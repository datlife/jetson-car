#include <Servo.h> 

//------------------------------CONSANT VARIABLES---------------------------------------------------

#define RC_ESC_PIN   7       // PWM PIN 7 for RC ESC Servo
#define RC_STEER_PIN   8       // PWM PIN 13 for RC Steer Servo

//Signals for ESC SERVO to speed up
#define ACCELERATE     43      // '+' on keyboard (ASCII Chart)
#define BRAKE          47      // '/' on keyboard (ASCII CHART)
#define REVERSE        45      // '-'(minus sign) on keyboard (ASCII chart)
#define NEUTRAL_POS    44      //  ',' (comma sign) (ASCII chart)

//Signals for STEERING Servo to turn
#define TURN_LEFT      60     // '<' on keyboard (ASCII Chart)
#define TURN_RIGHT     62      // '>' on keyboard (ASCII Chart)
#define STRAIGHT       61      // '=' on keyboard (ANSCII chart)

// Maximum variables of ESC SERVO
#define MAX_FORWARD    2000 //120     //MAX SPEED value for servo to turn to          (pulse = 2000ms)
#define NEUTRAL        1500 //95      //NEUTRAL singal value for servo                (pulse = 1500ms)
#define MAX_REVERSE    1000 //60      //MAX REVERSE SPEED value for servo to turn to  (pulse = 1000ms)
#define ACC_RATE       10              //ACCELERATE RATE

// Maximum Turn Degrees - 90 is in the middle
#define MAX_LEFT       125     //MAXIMUM left signal value for servo
#define MIDDLE         95      //NEUTRAL singal value for servo
#define MAX_RIGHT      60      //MAXIMUM right singal value for servo
#define STEER_RATE     8

Servo STEER_SERVO;           // steering servo of my RC car [RedCat Volcano EPX]
Servo ESC;                   // Electric Speed Control for RC
int   current_speed;         // current speed value
int   current_pos;   // current position of the wheel
//-----------------------------------------------------------------------------------------------------




void setup() 
{   
  current_speed = NEUTRAL;
  current_pos = MIDDLE;
  
  ESC.attach(RC_ESC_PIN);
  ESC.write(NEUTRAL);
  STEER_SERVO.attach(RC_STEER_PIN);
  STEER_SERVO.write(MIDDLE);  
  
  // set up Serial library at 9600 bps
  Serial.begin(9600);           
  Serial.println("Arduino starting");
}


void loop() 
{ 
  if (Serial.available() > 0)
  {
    //Read current input
    int signal = Serial.read();
    
    switch(signal)
    {      
        case ACCELERATE:{
              if ((current_speed + ACC_RATE)< MAX_FORWARD){
                current_speed += ACC_RATE;
                //ESC.write(current_speed);
                ESC.writeMicroseconds(current_speed);
              }
            }   
              break; 
              
        case BRAKE:{
                current_speed = NEUTRAL-100;
                //ESC.write(current_speed);
                ESC.writeMicroseconds(current_speed);
        }
          break;
                    
        case NEUTRAL_POS:{
                ESC.writeMicroseconds(NEUTRAL);
        }
         break;
         
        case REVERSE:{
                if ((current_speed - ACC_RATE) > MAX_REVERSE){
                  current_speed -= ACC_RATE;
                  //ESC.write(current_speed);
                  ESC.writeMicroseconds(current_speed);
                }
        }
          break;          
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
      if ((signal == BRAKE) || (signal == REVERSE) || (signal == ACCELERATE)){
              Serial.println(ESC.read());    
      }
      else
              Serial.println(STEER_SERVO.read());    
              
    delay(10);                       // waits 5ms for the servo to reach the position 
  }
} 



