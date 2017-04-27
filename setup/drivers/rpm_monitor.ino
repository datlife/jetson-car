/*
   Wheel Encoder to monitor RPM using Photoelectronic Encoder
   Hardare:
   Teensy 3.2 
   Photoelectronic Encoder (two IR
*/


#define ENCODER_PIN     2      // The pin the encoder signal output is connected  
#define TIRE_DIAMETER   0.12    // in meter, to calcuate linear speed
#define PULSES_PER_TURN 20
#define KM_TO_MILE      0.62137

unsigned int rpm;           // revolutions per minutes
int          velocity;

// The number of pulses per revolution - depends on your index disc!!
volatile byte pulses_per_sec;      // number of pulses
unsigned long timeold;
void counter(){
  pulses_per_sec++;
}

void setup()
{
  Serial.begin(115200);
  //Use statusPin to flash along with interrupts
  pinMode(ENCODER_PIN, INPUT);

  //Interrupt 0 is digital pin 2, so that is where the IR detector is connected
  attachInterrupt(ENCODER_PIN, counter, RISING);

  // Initialize
  pulses_per_sec = 0;
  rpm = 0;
  timeold = 0;
}

void loop()
{
  if (millis() - timeold >= 1000) { /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
    //Don't process interrupts during calculations

    detachInterrupt(0);
    // How many revolutions happened in minutes based on 1s
    rpm = pulses_per_sec * (60 * 1000 / PULSES_PER_TURN ) / (millis() - timeold);
    // http://people.wku.edu/david.neal/117/Unit2/AngVel.pdf
    velocity = rpm * (2 * PI / 60) * TIRE_DIAMETER * KM_TO_MILE * 3600/1000 ; // to mph
     
    //Write it out to serial port
    Serial.print("RPM = ");
    Serial.print(rpm, DEC);
    Serial.print("  || Speed = ");
    Serial.print(velocity, DEC);
    Serial.println(" mph");
    pulses_per_sec = 0;
    timeold = millis();
    //Restart the interrupt processing
    attachInterrupt(0, counter, FALLING);
  }
}
