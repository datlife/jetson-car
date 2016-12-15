#include <Servo.h> 

#define RC_ESC_PIN   7       // PWM PIN 7 for RC ESC Servo

//Signals to notice the Servo to turn
#define ACCELERATE     43      // '+' on keyboard (ASCII Chart)
#define BRAKE          47      // '/' on keyboard (ANSCII CHART)
#define REVERSE        45      // '-'(minus sign) on keyboard (ANSCII chart)


#define MAX_FORWARD    120     //MAX SPEED value for servo to turn to          (pulse = 2000ms)
#define NEUTRAL        95      //NEUTRAL singal value for servo                (pulse = 1500ms)
#define MAX_REVERSE    60      //MAX REVERSE SPEED value for servo to turn to  (pulse = 1000ms)
#define ACC_RATE       5  

Servo ESC;                   // Electric Speed Control for RC
int   current_speed;         // current speed value


void setup() 
{   
  current_speed = NEUTRAL;
  ESC.attach(RC_ESC_PIN);
  ESC.write(NEUTRAL);
  Serial.begin(9600);           // set up Serial library at 9600 bps
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
        // input is +
        case ACCELERATE:{
          if ((current_speed + ACC_RATE)< MAX_FORWARD){
            current_speed += ACC_RATE;
            ESC.write(current_speed);
          }
        }   
          break;
        // input is /
        case BRAKE:{
            current_speed = NEUTRAL;
            ESC.write(current_speed);
        }
          break;         
        //input is -
        case REVERSE:{
            if ((current_speed - ACC_RATE) > MAX_REVERSE){
              current_speed -= ACC_RATE;
              ESC.write(current_speed);
            }
        }
          break;
          
        
        default:
          break;
      }
      Serial.println(ESC.read());    
    delay(5);                       // waits 15ms for the servo to reach the position 
  }
} 


