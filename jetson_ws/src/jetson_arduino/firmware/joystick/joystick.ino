/*
  Arduino ROS node for Jetson Car
  MIT License
*/

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

///////////////////////////////DEFAULT PINS/////////////////////////////////////////
#define RC_ESC_PIN     7       // PWM PIN 7 for RC ESC Servo
#define RC_STEER_PIN   8       // PWM PIN 13 for RC Steer Servo
///////////////////////////////DEFAULT SERVO VALUES////////////////////////////////
//Constant ESC SERVO values
#define MAX_FORWARD    1600 //120     //MAX SPEED signal         (pulse = 2000ms)
#define NEUTRAL        1500 //95      //NEUTRAL signal           (pulse = 1500ms)
#define MAX_REVERSE    1400 //60      //MAX REVERSE SPEED signal (pulse = 1000ms)

//Constant STEERING SERVO values
#define MAX_LEFT       125
#define MIDDLE         95
#define MAX_RIGHT      60
//////////////////////////////GLOBAL VARIABLES/////////////////////////////////////
Servo STEER_SERVO;         // steering servo of my RC car [RedCat Volcano EPX]
Servo ESC;                 // Electric Speed Control for RC

// Set up ROS nodes
ros::NodeHandle nh_;
std_msgs::Int32 str_msg;
ros::Publisher chatter("arduino_publisher", &str_msg);

//////////////////////////FUNCTION PROTOTYPES///////////////////////////////////////
void drive_callback(const geometry_msgs::Twist& signal);
void control_steering(const geometry_msgs::Twist&);
void control_esc(const geometry_msgs::Twist& signal);
int convert_signal(double, double, double, double , double);

ros::Subscriber<geometry_msgs::Twist> driveSubscriber("/jetson_teleop/cmd_vel", &drive_callback) ;

void setup(){
    nh_.initNode();
    nh_.advertise(chatter);
    nh_.subscribe(driveSubscriber);

    // Connect ESC and Steering Servo to PIN 7 and 8 respectively
    ESC.attach(RC_ESC_PIN);
    STEER_SERVO.attach(RC_STEER_PIN);

    // Set everything to neutral
    ESC.writeMicroseconds(NEUTRAL);
    STEER_SERVO.write(MIDDLE);

    //Set up Serial library at 9600 bps (how many bytes can send in a second)
    Serial.begin(115200);
    Serial.println("Arduino starting");
    delay(30);
}

void loop(){
    nh_.spinOnce();
    delay(10);
}


void drive_callback(const geometry_msgs::Twist& signal){
    control_steering(signal);
    control_esc(signal);
}
void control_steering(const geometry_msgs::Twist& signal){
    int steer_angle = convert_signal(signal.angular.z, 0.0, 1.0, MAX_RIGHT, MAX_LEFT);

    if (steer_angle < MAX_RIGHT) steer_angle = MAX_RIGHT;
    if (steer_angle > MAX_LEFT)  steer_angle = MAX_LEFT;

    STEER_SERVO.write(steer_angle);
    Serial.println(STEER_SERVO.read());
    str_msg.data = STEER_SERVO.read();
    chatter.publish(&str_msg);
    

}

void control_esc(const geometry_msgs::Twist& signal) {
    int throttle = convert_signal(signal.linear.x, 0.5, 1.0, NEUTRAL, MAX_FORWARD);

    if (throttle < MAX_REVERSE) throttle = MAX_REVERSE;
    if (throttle > MAX_FORWARD)  throttle = MAX_FORWARD;

    ESC.writeMicroseconds(throttle);
    Serial.println(ESC.read());

}
int convert_signal(double toMap, double in_min, double in_max, double out_min, double out_max){
    return (toMap - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
