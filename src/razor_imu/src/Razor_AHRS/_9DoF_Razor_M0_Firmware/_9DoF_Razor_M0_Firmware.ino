/******************************************************************************
SparkFun 9DoF Razor M0 Example Firmware
Jim Lindblom @ SparkFun Electronics
Original creation date: November 22, 2016
https://github.com/sparkfun/9DOF_Razor_IMU/Firmware

This example firmware for the SparkFun 9DoF Razor IMU M0 
demonstrates how to grab accelerometer, gyroscope, magnetometer,
and quaternion values from the MPU-9250's digital motion processor
(DMP). It prints those values to a serial port and, if a card is
present, an SD card.

Values printed can be configured using the serial port. Settings
can be modified using the included "config.h" file.

Resources:
SparkFun MPU9250-DMP Arduino Library:
  https://github.com/sparkfun/SparkFun_MPU-9250-DMP_Arduino_Library
FlashStorage Arduino Library
  https://github.com/cmaglie/FlashStorage

Development environment specifics:
  Firmware developed using Arduino IDE 1.6.12

Hardware:
  SparkFun 9DoF Razor IMU M0 (SEN-14001)
  https://www.sparkfun.com/products/14001
******************************************************************************/
// MPU-9250 Digital Motion Processing (DMP) Library
#include <SparkFunMPU9250-DMP.h>

// SD Library manages file and hardware control 
#include <SD.h>

// config.h manages default logging parameters and can be used to adjust specific parameters of the IMU
#include "config.h"

MPU9250_DMP imu; // Create an instance of the MPU9250_DMP class

/////////////////////////////
// Logging Control Globals //
/////////////////////////////
// Defaults all set in config.h
bool enableSDLogging = ENABLE_SD_LOGGING;
bool enableSerialLogging = ENABLE_UART_LOGGING;
bool enableTimeLog = ENABLE_TIME_LOG;
bool enableCalculatedValues = ENABLE_CALCULATED_LOG;
bool enableAccel = ENABLE_ACCEL_LOG;
bool enableGyro = ENABLE_GYRO_LOG;
bool enableCompass = ENABLE_MAG_LOG;
bool enableQuat = ENABLE_QUAT_LOG;
bool enableEuler = ENABLE_EULER_LOG;
bool enableHeading = ENABLE_HEADING_LOG;
unsigned short accelFSR = IMU_ACCEL_FSR;
unsigned short gyroFSR = IMU_GYRO_FSR;
unsigned short fifoRate = DMP_SAMPLE_RATE;

/////////////////////
// SD Card Globals //
/////////////////////
bool sdCardPresent = false; // Keeps track of if SD card is plugged in
String logFileName; // Active logging file
String logFileBuffer; // Buffer for logged data. Max is set in config

///////////////////////
// LED Blink Control //
///////////////////////
uint32_t lastBlink = 0;
void blinkLED()
{
  static bool ledState = false;
  digitalWrite(HW_LED_PIN, ledState);
  ledState = !ledState;
}

void setup()
{
  // LED defaults to off:
  initHardware();                     // Initialize LED, interrupt input, and serial port.
  if ( !initIMU() ) {                 // Initialize the MPU-9250. Should return true on success:
    LOG_PORT.println("Error connecting to MPU-9250");
    while (1) ;                       // LED will remain off in this state.
  }
  if ( initSD() ){                    // Check for the presence of an SD card, and initialize it:
    sdCardPresent = true;
    logFileName = nextLogFile();      // Get the next, available log file name
  }
  Serial1.begin(115200);
}

void loop()
{
  if ( LOG_PORT.available() )                         // The loop constantly checks for new serial input:
    parseSerialInput(LOG_PORT.read());                // If new input is available on serial port, parse it

  if ( !imu.fifoAvailable() )                         // If no new IMU data is available
    return;                                           // return to the top of the loop

  if ( imu.dmpUpdateFifo() != INV_SUCCESS )           // Read from the digital motion processor's FIFO
    return;                                           // If that fails, return to top

  if ( (enableCompass || enableHeading) &&
       (imu.updateCompass() != INV_SUCCESS) )         // If enabled, read from the compass.
    return;                                           // If compass read fails, return to top

  if ( enableSerialLogging || enableSDLogging)        // If logging (to either UART and SD card) is enabled
    logIMUData(); // Log new data

}


void initHardware(void) {
  pinMode(HW_LED_PIN, OUTPUT);                // Set up LED pin (active-high, default to off)
  digitalWrite(HW_LED_PIN, LOW);
  pinMode(MPU9250_INT_PIN, INPUT_PULLUP);    // Set up MPU-9250 interrupt input (active-low)
  LOG_PORT.begin(SERIAL_BAUD_RATE);          // Set up serial log port
}

bool initIMU(void)
{
  // imu.begin() should return 0 on success. Will initialize I2C bus, and reset MPU-9250 to defaults.
  if (imu.begin() != INV_SUCCESS)
    return false;

  // Set up MPU-9250 interrupt:
  imu.enableInterrupt(); // Enable interrupt output
  imu.setIntLevel(1);    // Set interrupt to active-low
  imu.setIntLatched(1);  // Latch interrupt output

  // Configure sensors:
  imu.setAccelFSR(accelFSR);     // Set accel full-scale range: options are 2, 4, 8, or 16 g
  imu.setGyroFSR(gyroFSR);       // Set gyro full-scale range: options are 250, 500, 1000, or 2000:
  imu.setLPF(IMU_AG_LPF);        // Set gyro/accel LPF: options are 5, 10, 20, 42, 98, 188 Hz
  imu.setSampleRate(IMU_AG_SAMPLE_RATE);    // Set gyro/accel sample rate: must be between 4-1000Hz (will be overridden by the DMP sample rate))
  imu.setCompassSampleRate(IMU_COMPASS_SAMPLE_RATE);   // Set compass sample rate: between 4-100Hz

  unsigned short dmpFeatureMask = 0;                   // Configure digital motion processor. Use the FIFO to get data from the DMP.
  if (ENABLE_GYRO_CALIBRATION) {
    dmpFeatureMask |= DMP_FEATURE_SEND_CAL_GYRO;       // Gyro calibration re-calibrates the gyro after a set amount of no motion detected
  }

  dmpFeatureMask |= DMP_FEATURE_SEND_RAW_ACCEL;       // Add accel and quaternion's to the DMP
  dmpFeatureMask |= DMP_FEATURE_6X_LP_QUAT;
  imu.dmpBegin(dmpFeatureMask, fifoRate);             // Initialize the DMP, and set the FIFO's update rate:

  return true; // Return success
}

bool initSD(void)
{
  // SD.begin should return true if a valid SD card is present
  if ( !SD.begin(SD_CHIP_SELECT_PIN) ) {
    return false;
  }

  return true;
}

void logIMUData(void)
{
  String imuLog = ""; // Create a fresh line to log

  if (enableTimeLog) {
    imuLog += String(imu.time) + ", "; // Add time to log string
  }

  if (enableCalculatedValues){        // If estimated Calculation mode is enabled
    if (enableAccel){
      imuLog += String(imu.calcAccel(imu.ax)) + ", ";
      imuLog += String(imu.calcAccel(imu.ay)) + ", ";
      imuLog += String(imu.calcAccel(imu.az)) + ", ";
    }
    if(enableGyro){
      imuLog += String(imu.calcGyro(imu.gx)) + ", ";
      imuLog += String(imu.calcGyro(imu.gy)) + ", ";
      imuLog += String(imu.calcGyro(imu.gz)) + ", ";
    }
    if (enableCompass){
      imuLog += String(imu.calcMag(imu.mx)) + ", ";
      imuLog += String(imu.calcMag(imu.my)) + ", ";
      imuLog += String(imu.calcMag(imu.mz)) + ", ";
    }
    if (enableQuat){
      imuLog += String(imu.calcQuat(imu.qw), 4) + ", ";
      imuLog += String(imu.calcQuat(imu.qx), 4) + ", ";
      imuLog += String(imu.calcQuat(imu.qy), 4) + ", ";
      imuLog += String(imu.calcQuat(imu.qz), 4) + ", ";
    }
  }
  else{
    if (enableAccel){
      imuLog += String(imu.ax) + ", ";
      imuLog += String(imu.ay) + ", ";
      imuLog += String(imu.az) + ", ";
    }
    if (enableGyro){
      imuLog += String(imu.gx) + ", ";
      imuLog += String(imu.gy) + ", ";
      imuLog += String(imu.gz) + ", ";
    }
    if (enableCompass){
      imuLog += String(imu.mx) + ", ";
      imuLog += String(imu.my) + ", ";
      imuLog += String(imu.mz) + ", ";
    }
    if (enableQuat){
      imuLog += String(imu.qw) + ", ";
      imuLog += String(imu.qx) + ", ";
      imuLog += String(imu.qy) + ", ";
      imuLog += String(imu.qz) + ", ";
    }
  }
  if (enableEuler) // If Euler-angle logging is enabled
  {
    imu.computeEulerAngles();
    imuLog += String(imu.pitch, 2) + ", ";
    imuLog += String(imu.roll, 2) + ", ";
    imuLog += String(imu.yaw, 2) + ", ";
  }
  if (enableHeading) // If heading logging is enabled
  {
    imuLog += String(imu.computeCompassHeading(), 2) + ", ";
  }

  imuLog.remove(imuLog.length() - 2, 2);    // Remove last comma/space:
  imuLog += "\r\n"; // Add a new line


  if (enableSerialLogging)  // If serial port logging is enabled
    LOG_PORT.print(imuLog); // Print log line to serial port

  // If SD card logging is enabled & a card is plugged in
  if ( sdCardPresent && enableSDLogging)
  {
    // If adding this log line will put us over the buffer length:
    if (imuLog.length() + logFileBuffer.length() >=
        SD_LOG_WRITE_BUFFER_SIZE)
    {
      sdLogString(logFileBuffer); // Log SD buffer
      logFileBuffer = ""; // Clear SD log buffer
      blinkLED(); // Blink LED every time a new buffer is logged to SD
    }
    // Add new line to SD log buffer
    logFileBuffer += imuLog;
  }
  else
  {
    // Blink LED once every second (if only logging to serial port)
    if ( millis() > lastBlink + UART_BLINK_RATE )
    {
      blinkLED();
      lastBlink = millis();
    }
  }
}

// Log a string to the SD card
bool sdLogString(String toLog)
{
  File logFile = SD.open(logFileName, FILE_WRITE);             // Open the current file name:
  if (logFile.size() > (SD_MAX_FILE_SIZE - toLog.length()))    // If the file will get too big with this new string, create a new one, and open it.
  {
    logFileName = nextLogFile();
    logFile = SD.open(logFileName, FILE_WRITE);
  }
  if (logFile)     // If the log file opened properly, add the string to it.
  {
    logFile.print(toLog);
    logFile.close();
    return true; // Return success
  }
  return false; // Return fail
}

// Find the next available log file. Or return a null string
// if we've reached the maximum file limit.
String nextLogFile(void)
{
  String filename;
  int logIndex = 0;

  for (int i = 0; i < LOG_FILE_INDEX_MAX; i++)
  {
    // Construct a file with PREFIX[Index].SUFFIX
    filename = String(LOG_FILE_PREFIX);
    filename += String(logIndex);
    filename += ".";
    filename += String(LOG_FILE_SUFFIX);
    // If the file name doesn't exist, return it
    if (!SD.exists(filename))
    {
      return filename;
    }
    // Otherwise increment the index, and try again
    logIndex++;
  }
  return "";
}

// Parse serial input, take action if it's a valid character
void parseSerialInput(char c)
{
  unsigned short temp;
  switch (c)
  {
  case PAUSE_LOGGING: // Pause logging on SPACE
    enableSerialLogging = !enableSerialLogging;
    break;

  case ENABLE_TIME: // Enable time (milliseconds) logging
    enableTimeLog = !enableTimeLog;
    break;

  case ENABLE_ACCEL: // Enable/disable accelerometer logging
    enableAccel = !enableAccel;
    break;

  case ENABLE_GYRO: // Enable/disable gyroscope logging
    enableGyro = !enableGyro;
    break;

  case ENABLE_COMPASS: // Enable/disable magnetometer logging
    enableCompass = !enableCompass;
    break;

  case ENABLE_CALC: // Enable/disable calculated value logging
    enableCalculatedValues = !enableCalculatedValues;
    break;

  case ENABLE_QUAT: // Enable/disable quaternion logging
    enableQuat = !enableQuat;
    break;

  case ENABLE_EULER: // Enable/disable Euler angle (roll, pitch, yaw)
    enableEuler = !enableEuler;
    break;

  case ENABLE_HEADING: // Enable/disable heading output
    enableHeading = !enableHeading;
    break;

  case SET_LOG_RATE: // Increment the log rate from 1-100Hz (10Hz increments)
    temp = imu.dmpGetFifoRate(); // Get current FIFO rate
    if (temp == 1) // If it's 1Hz, set it to 10Hz
      temp = 10;
    else
      temp += 10; // Otherwise increment by 10
    if (temp > 100)  // If it's greater than 100Hz, reset to 1
      temp = 1;
    imu.dmpSetFifoRate(temp); // Send the new rate
    temp = imu.dmpGetFifoRate(); // Read the updated rate
    LOG_PORT.println("IMU rate set to " + String(temp) + " Hz");
    break;

  case SET_ACCEL_FSR: // Increment accelerometer full-scale range
    temp = imu.getAccelFSR();      // Get current FSR
    if (temp == 2) temp = 4;       // If it's 2, go to 4
    else if (temp == 4) temp = 8;  // If it's 4, go to 8
    else if (temp == 8) temp = 16; // If it's 8, go to 16
    else temp = 2;                 // Otherwise, default to 2
    imu.setAccelFSR(temp); // Set the new FSR
    temp = imu.getAccelFSR(); // Read it to make sure
    LOG_PORT.println("Accel FSR set to +/-" + String(temp) + " g");
    break;

  case SET_GYRO_FSR:// Increment gyroscope full-scale range
    temp = imu.getGyroFSR();           // Get the current FSR
    if (temp == 250) temp = 500;       // If it's 250, set to 500
    else if (temp == 500) temp = 1000; // If it's 500, set to 1000
    else if (temp == 1000) temp = 2000;// If it's 1000, set to 2000
    else temp = 250;                   // Otherwise, default to 250
    imu.setGyroFSR(temp); // Set the new FSR
    temp = imu.getGyroFSR(); // Read it to make sure
    LOG_PORT.println("Gyro FSR set to +/-" + String(temp) + " dps");
    break;
/*    
  case ENABLE_CALIB_MODE:
    imu.dmpEnableFeatures(DMP_FEATURE_SEND_CAL_GYRO);
    break;
*/
  case ENABLE_SD_LOGGING: // Enable/disable SD card logging
    enableSDLogging = !enableSDLogging;
    break;

  default: // If an invalid character, do nothing
    break;

  }
}
