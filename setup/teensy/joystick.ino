/*
  Arduino ROS node for Jetson Car
  This code is run on Teensy 3.2, not Arduino
  MIT License
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
//#define USB_USBCON
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <rc_car_msgs/CarInfo.h>
//====================================DEFAULT PINS============================================
#define RC_ESC_PIN     4       // PWM PIN 7 for RC ESC Servo
#define RC_STEER_PIN   5       // PWM PIN 13 for RC Steer Servo

//===================================DEFAULT SERVO VALUES=====================================
//Constant ESC SERVO values
#define MAX_FORWARD    1700 //120     //MAX SPEED signal         (pulse = 2000ms)
#define NEUTRAL        1500 //95      //NEUTRAL signal           (pulse = 1500ms)
#define MAX_REVERSE    1300 //60      //MAX REVERSE SPEED signal (pulse = 1000ms)

//Constant STEERING SERVO values
#define MAX_LEFT       140
#define MIDDLE         95
#define MAX_RIGHT      50
//=================================GLOBAL VARIABLES============================================
Servo STEER_SERVO;         // steering servo of my RC car [RedCat Volcano EPX]
Servo ESC;                 // Electric Speed Control for RC

// Set up ROS nodes
ros::NodeHandle nh_;
//std_msgs::Int32 str_msg;
//ros::Publisher chatter("arduino_publisher", &str_msg);

//================================FUNCTION PROTOTYPES==========================================
void drive_callback(const rc_car_msgs::CarInfo& signal);
void control_steering(const rc_car_msgs::CarInfo&);
void control_esc(const rc_car_msgs::CarInfo& signal);
int convert_signal(double, double, double, double , double);

ros::Subscriber<rc_car_msgs::CarInfo> driveSubscriber("/car_info", &drive_callback) ;

void setup(){
    // Connect ESC and Steering Servo to PIN 7 and 8 respectively
    ESC.attach(RC_ESC_PIN);
    STEER_SERVO.attach(RC_STEER_PIN);

    // Set everything to neutral
    ESC.writeMicroseconds(NEUTRAL);
    STEER_SERVO.write(MIDDLE);
    pinMode(13, OUTPUT);

    //Set up Serial library / baundrate (how many bytes can send in a second)
    Serial.begin(115200);
    Serial.println("Arduino starting");
    delay(30);
    nh_.initNode();
    //nh_.advertise(chatter);
    nh_.subscribe(driveSubscriber);
    delay(1000);
}

void loop(){
    nh_.spinOnce();
    delay(1);
}


void drive_callback(const rc_car_msgs::CarInfo& signal){
    control_steering(signal);
    control_esc(signal);
}
void control_steering(const rc_car_msgs::CarInfo& signal){
    int steer_angle = convert_signal(signal.steer, -1.0, 1.0, MAX_RIGHT, MAX_LEFT);

    if (steer_angle < MAX_RIGHT) steer_angle = MAX_RIGHT;
    if (steer_angle > MAX_LEFT)  steer_angle = MAX_LEFT;
    
    STEER_SERVO.write(steer_angle);
    //str_msg.data = steer_angle;
    //chatter.publish(&str_msg);
}

void control_esc(const rc_car_msgs::CarInfo& signal) {
    int throttle = convert_signal(signal.throttle, 0.0, 1.0, NEUTRAL, MAX_FORWARD);
    if (throttle < MAX_REVERSE) throttle = MAX_REVERSE;
    if (throttle > MAX_FORWARD)  throttle = MAX_FORWARD;
    ESC.writeMicroseconds(throttle);

}
int convert_signal(double toMap, double in_min, double in_max, double out_min, double out_max){
    return (toMap - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
