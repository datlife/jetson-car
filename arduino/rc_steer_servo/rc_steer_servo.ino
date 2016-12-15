#include <Servo.h> 

#define RC_STEER_PIN   8       // PWM PIN 13 for RC Steer Servo

//Signals for STEERING Servo to turn
#define TURN_LEFT      60     // '<' on keyboard (ASCII Chart)
#define TURN_RIGHT     62      // '>' on keyboard (ASCII Chart)
#define NEUTRAL        61      // '=' on keyboard (ANSCII chart)

// Maximum Turn Degrees - 90 is in the middle
#define MAX_LEFT       125     //MAXIMUM left signal value for servo
#define MIDDLE         95      //NEUTRAL singal value for servo
#define MAX_RIGHT      60      //MAXIMUM right singal value for servo
#define STEER_RATE     1

Servo STEER_SERVO; // steering servo of my RC car [RedCat Volcano EPX]
int current_pos;   // current position of the wheel


void setup() 
{   
  current_pos = MIDDLE;
  STEER_SERVO.attach(RC_STEER_PIN);
  STEER_SERVO.write(MIDDLE);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Arduino code starting");
}


void loop() 
{ 
  if (Serial.available() > 0)
  {
    int control_signal = Serial.read();
    switch(control_signal)
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
        
        case NEUTRAL:{
            current_pos = MIDDLE;
            STEER_SERVO.write(current_pos);
        }
          break;
        
        default:
          break;
      }
      Serial.println(STEER_SERVO.read());    
    delay(5);                       // waits 15ms for the servo to reach the position 
  }
} 


