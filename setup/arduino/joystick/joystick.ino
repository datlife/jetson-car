/*********************************************
Arduino Firmware for Jetson Car
**********************************************
Author : Dat Nguyen
GitHub : https://github.com/dat-ai/jetson-car
Update : Jan 13, 2016

Hardware:
-  RedRacing Volcano EPX
-  Arduino Board

Software:
-  Ubuntu 14.04 + ROS
-  jetson_joystick is running
***********************************************/

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include <WProgram.h>
#endif
#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

//=================================== DEFAULT PINS ==================================
#define RC_ESC_PIN     7       // PWM PIN 7 for RC ESC Servo
#define RC_STEER_PIN   8       // PWM PIN 13 for RC Steer Servo

//================================ DEFAULT SERVO VALUES =============================

#define MAX_FORWARD    1600 //120     //MAX SPEED signal         (pulse = 2000ms)
#define NEUTRAL        1500 //95      //NEUTRAL signal           (pulse = 1500ms)
#define MAX_REVERSE    1400 //60      //MAX REVERSE SPEED signal (pulse = 1000ms)

#define MAX_LEFT       125
#define MIDDLE         95
#define MAX_RIGHT      60

//================================ GLOBAL VARIABLES ==================================

Servo STEER_SERVO;         // Steering servo
Servo ESC;                 // Electric Speed Control Servo

//=============================== FUNCTION PROTOTYPES ================================

void drive_callback     (const geometry_msgs::Twist&);
void control_steering   (const geometry_msgs::Twist&);
void control_esc        (const geometry_msgs::Twist& );
int  convert_signal     (double, double, double, double , double);

//============================== ROS NODE SETUP ======================================
ros::NodeHandle                         nh_;
std_msgs::Int32                         str_msg;
ros::Publisher                          chatter("arduino_publisher", &str_msg);
ros::Subscriber<geometry_msgs::Twist>   driveSubscriber("/cmd_vel",
                                                        &drive_callback) ;

void setup(){
    nh_.initNode();
    nh_.advertise(chatter);
    nh_.subscribe(driveSubscriber);

    // Connect ESC and Steering Servo
    ESC.attach(RC_ESC_PIN);
    STEER_SERVO.attach(RC_STEER_PIN);

    // Set everything to neutral
    ESC.writeMicroseconds(NEUTRAL);
    STEER_SERVO.write(MIDDLE);

    //Set up Serial library at 115200 bps (how many bytes can send in a second)
    Serial.begin(9600);
    Serial.println("Arduino starting");
    delay(30);
}

void loop(){
    nh_.spinOnce();
    delay(10);
}

/*********************************************************
                  drive_callback()
**********************************************************
wrapper of steering and esc controller
    input : geometer_msgs::Twist message from ROS
    output : control ESC and Steering
**********************************************************/

void drive_callback(const geometry_msgs::Twist& signal){
    control_steering(signal);
    control_esc(signal);
}

/*********************************************************
                  control_steering()
**********************************************************
Update steering angle of Steering Servo
    input :
            geometer_msgs::Twist message from ROS
    output :
            - Update steering angle
            - Publish current angle to chatter
**********************************************************/
void control_steering(const geometry_msgs::Twist& signal){
    int steer_angle = convert_signal(signal.angular.z, -1.0, 1.0,MAX_RIGHT, MAX_LEFT);
    
    if (steer_angle > MAX_LEFT) steer_angle = MAX_LEFT;
    if (steer_angle < MAX_RIGHT)   steer_angle = MAX_RIGHT;
    STEER_SERVO.write(steer_angle);

    str_msg.data = STEER_SERVO.read();
    chatter.publish(&str_msg);
      Serial.println(STEER_SERVO.read());
}

/*********************************************************
                  control_esc()
**********************************************************
Update throttle level of ESC Motor
    input :
            geometer_msgs::Twist message from ROS
    output :
            - Update throttle level
            - Publish current throttle level to chatter
**********************************************************/
void control_esc(const geometry_msgs::Twist& signal) {
    int throttle = convert_signal(signal.linear.x,
                                  -1.0, 1.0,
                                  MAX_REVERSE, MAX_FORWARD);
    if (throttle > MAX_FORWARD) throttle = MAX_FORWARD;
    if (throttle < MAX_REVERSE) throttle = MAX_REVERSE;
    ESC.writeMicroseconds(throttle);
    Serial.println(ESC.read());
}
/*********************************************************
                  convert_signal()
**********************************************************
Scale joystick signal to actual value for motor to understand
    input :
            toMap:           Signal from Twist message
            in_min, in_max:  Min/Max value of Twist message
            out_min,out_max: Min/Max value of Motor
    output :
            Actual signal value for motor
**********************************************************/
int convert_signal(double toMap,
                   double in_min, double in_max,
                   double out_min, double out_max){
    return (toMap - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
