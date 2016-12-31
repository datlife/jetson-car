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

////////////////////////////////ESC SERVO////////////////////////////////////////////
#define ACCELERATE     43      // '+' on keyboard (ASCII Chart)
#define BRAKE          47      // '/' on keyboard (ASCII CHART)
#define REVERSE        45      // '-'(minus sign) on keyboard (ASCII chart)

//Constant ESC SERVO values
#define MAX_FORWARD    1600 //120     //MAX SPEED signal         (pulse = 2000ms)
#define NEUTRAL        1500 //95      //NEUTRAL signal           (pulse = 1500ms)
#define MAX_REVERSE    1400 //60      //MAX REVERSE SPEED signal (pulse = 1000ms)

///////////////////////////////STEERING SERVO/////////////////////////////////////////
#define TURN_LEFT      60     // '<' on keyboard (ASCII Chart)
#define TURN_RIGHT     62      // '>' on keyboard (ASCII Chart)
#define STRAIGHT       61      // '=' on keyboard (ASCII chart)

//Constant STEERING SERVO values
#define MAX_LEFT       125     //MAXIMUM left signal
#define MIDDLE         95      //NEUTRAL signal
#define MAX_RIGHT      60      //MAXIMUM right signal

/////////////////////////////UPDATE RATE//////////////////////////////////////////////
#define ACC_RATE       10             //ACCELERATE RATE ---------- COULD BE  ROS PARAM
#define STEER_RATE     5

//////////////////////////////GLOBAL VARIABLES/////////////////////////////////////////
Servo STEER_SERVO;           // steering servo of my RC car [RedCat Volcano EPX]
Servo ESC;                   // Electric Speed Control for RC
int   current_speed;         // current speed value
int   current_pos;   // current position of the wheel

void controlESC(int incoming_signal);
void controlSteering(int incoming_signal);

void setup() 
{   
  current_speed = NEUTRAL;
  current_pos = MIDDLE;
  // Connect ESC and Steering Servo to PIN 7 and 8 respectively
  ESC.attach(RC_ESC_PIN);
  STEER_SERVO.attach(RC_STEER_PIN);
  
  // Set everything to neutral
  ESC.write(NEUTRAL);
  STEER_SERVO.write(MIDDLE);  
  
  //Set up Serial library at 9600 bps (how many bytes can send in a second)
  Serial.begin(9600);           
  Serial.println("Arduino starting");
}

void loop() 
{ 
  if (Serial.available() > 0)
  {
    int signal = Serial.read();
    if ((signal == BRAKE) || (signal == REVERSE) || (signal == ACCELERATE))
        controlESC(signal);
        
    else if ((signal == TURN_LEFT) || (signal == TURN_RIGHT) || (signal == STRAIGHT))
       controllSteering(signal); 
              
    delay(10);                       // waits 10ms for the servo to reach the position 
  }
} 

void controlESC(int signal)
{ 
      switch(signal)
      {      
          case ACCELERATE:
          {
              if ((current_speed + ACC_RATE)< MAX_FORWARD){
                current_speed += ACC_RATE;
                ESC.writeMicroseconds(current_speed);
              }
           }   
           break; 
                
          case BRAKE:
          {
              // Set emergency brake
              current_speed = NEUTRAL-100;
              ESC.writeMicroseconds(current_speed);
              // Then put into Neutral
              delay(20);
              ESC.writeMicroseconds(NEUTRAL);
          }
            break;
           
          case REVERSE:
          {
              if ((current_speed - ACC_RATE) > MAX_REVERSE){
                current_speed -= ACC_RATE;
                //ESC.write(current_speed);
                ESC.writeMicroseconds(current_speed);
              }
          }
          break;  
          
          default:
            break;
      }
      
      Serial.println(ESC.read());        
}
void controllSteering(int signal)
{  
      switch(signal)
      {      
          case TURN_LEFT:{
                if ((current_pos + STEER_RATE)< MAX_LEFT){
                  current_pos += STEER_RATE;
                  STEER_SERVO.write(current_pos);
                }
          }
          break;
          
          case TURN_RIGHT:{
                 if ((current_pos-STEER_RATE) > MAX_RIGHT){
                  current_pos -= STEER_RATE;
                  STEER_SERVO.write(current_pos);
                }
          }
          break;  
          
          case STRAIGHT:{
                current_pos = MIDDLE;
                STEER_SERVO.write(current_pos);
          }
          
          default:
            break;
     }
     Serial.println(STEER_SERVO.read());    
}

