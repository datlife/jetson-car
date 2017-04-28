/*
  Arduino ROS node for Jetson Car
  This code is run on Teensy 3.2, not Arduino
  MIT License

Hardwares:
   Teensy 3.2
   Photoelectronic Encoder 
   ESC Controller
   Servo COntroller
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#define USB_USBCON

#include <rc_car_msgs/CarController.h>
#include <rc_car_msgs/CarInfo.h>

//====================================DEFAULT PINS============================================
#define RC_ESC_PIN     4       // PWM PIN 7 for RC ESC Servo
#define RC_STEER_PIN   5       // PWM PIN 13 for RC Steer Servo
#define ENCODER_PIN     2      // The pin the encoder signal output is connected  

//===================================DEFAULT SERVO VALUES=====================================
//Constant ESC SERVO values
#define MAX_FORWARD    1900 //120     //MAX SPEED signal         (pulse = 2000ms)
#define NEUTRAL        1500 //95      //NEUTRAL signal           (pulse = 1500ms)
#define MAX_REVERSE    1100 //60      //MAX REVERSE SPEED signal (pulse = 1000ms)

//Constant STEERING SERVO values
#define MAX_LEFT       140
#define MIDDLE         95
#define MAX_RIGHT      50

//=================================DEFAULT RPM MONITOR VALUES ===============================
#define TIRE_DIAMETER   0.12    // in meter, to calcuate linear speed
#define PULSES_PER_TURN 20
#define KM_TO_MILE      0.62137
#define UPDATE_RATE     100
//=================================GLOBAL VARIABLES============================================
Servo STEER_SERVO;         // steering servo of my RC car [RedCat Volcano EPX]
Servo ESC;                 // Electric Speed Control for RC

volatile byte pulses_per_sec;      // number of pulses
unsigned int  rpm;                 // revolutions per minutes
unsigned int  velocity;            // velocity
unsigned long timeold;
float         steer_temp = 0.0;
float         throttle_temp =0.0;
IntervalTimer publish_timer;

//================================FUNCTION PROTOTYPES==========================================
void drive_callback(const rc_car_msgs::CarController& signal);
void init_rpm_monitor();
void control_steering(const rc_car_msgs::CarController&);
void control_esc(const rc_car_msgs::CarController& signal);
void calculate_rpm();
int  convert_signal(double, double, double, double , double);
void counter() {pulses_per_sec++;}
void publish_car_info();
// Set up ROS nodes
ros::NodeHandle nh_;

ros::Subscriber<rc_car_msgs::CarController> driveSubscriber("/car_controller", &drive_callback) ;
rc_car_msgs::CarInfo carinfo;
ros::Publisher car_pub("car_info", &carinfo);

void setup(){
    // Connect ESC and Steering Servo and RPM Monitor to correct PIN
    ESC.attach(RC_ESC_PIN);
    STEER_SERVO.attach(RC_STEER_PIN);

    // ============== INITIALZING STATES ==================
    ESC.writeMicroseconds(NEUTRAL);
    STEER_SERVO.write(MIDDLE);
    init_rpm_monitor();
    pinMode(13, OUTPUT);

    // =============== Set up Serial ======================
    Serial.begin(115200);
    Serial.println("Arduino starting");
    delay(30);
    nh_.initNode();
    nh_.subscribe(driveSubscriber);
    nh_.advertise(car_pub);
    delay(500);
    publish_timer.begin(publish_car_info, 30000);
}

void loop(){
    calculate_rpm();
    nh_.spinOnce();
    delay(1);
}
void init_rpm_monitor(){
    pinMode(ENCODER_PIN, INPUT);
    //Interrupt 0 is digital pin 2, so that is where the IR detector is connected
    attachInterrupt(ENCODER_PIN, counter, RISING);
    // Initialize
    pulses_per_sec = 0;
    rpm = 0;
    timeold = 0; 
}

void drive_callback(const rc_car_msgs::CarController& signal){
    control_steering(signal);
    control_esc(signal);
    steer_temp = signal.steer;
    throttle_temp = signal.throttle;
 }

void publish_car_info(){
      carinfo.steer = steer_temp;
      carinfo.throttle = throttle_temp;
      carinfo.speed = velocity;
      carinfo.rpm   = rpm;
      car_pub.publish(&carinfo);
}
void control_steering(const rc_car_msgs::CarController& signal){
    int steer_angle = convert_signal(signal.steer, -1.0, 1.0, MAX_RIGHT, MAX_LEFT);
    if (steer_angle < MAX_RIGHT) steer_angle = MAX_RIGHT;
    if (steer_angle > MAX_LEFT)  steer_angle = MAX_LEFT;
    STEER_SERVO.write(steer_angle);
}

void control_esc(const rc_car_msgs::CarController& signal) {
    int throttle = convert_signal(signal.throttle, 0.0, 1.0, NEUTRAL, MAX_FORWARD);
    if (throttle < MAX_REVERSE) throttle = MAX_REVERSE;
    if (throttle > MAX_FORWARD)  throttle = MAX_FORWARD;
    ESC.writeMicroseconds(throttle);

}
int convert_signal(double toMap, double in_min, double in_max, double out_min, double out_max){
    return (toMap - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void calculate_rpm(){
  if (millis() - timeold >= 1000) { /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
    
    //Don't process interrupts during calculations
    detachInterrupt(0);
    
    // How many revolutions happened in minutes based on 1s
    rpm = pulses_per_sec * (60 * 1000 / PULSES_PER_TURN ) / (millis() - timeold);
    
    // http://people.wku.edu/david.neal/117/Unit2/AngVel.pdf
    // Angular to Linear Velocity : v = radius * w
    velocity = rpm * (PI / 60) *(TIRE_DIAMETER) * KM_TO_MILE * 3.6 ; // to mph

    // Reset
    pulses_per_sec = 0;
    timeold = millis();
    
    //Restart the interrupt processing
    attachInterrupt(ENCODER_PIN, counter, RISING);
  }

}
