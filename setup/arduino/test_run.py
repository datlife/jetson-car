'''
Control Servos using Arduino through Serial Port

Requirements:
1. PySerial Installed
2. Arduino Driver has been installed on the computer
3. Arduino is connected to computer via micro-USB

Troubleshooting:
'''

import serial
import time
import serial.tools.list_ports
import warnings

# Signals for STEERING Servo to turn
TURN_LEFT = b'<'         # '<' on keyboard (ASCII Chart)
TURN_RIGHT = b'>'        # '>' on keyboard (ASCII Chart)
STRAIGHT = b'='          # '=' on keyboard (ASCII chart)


# Signals for ESC SERVO to speed up
ACCELERATE = b'+'      # '+' on keyboard (ASCII Chart)
BRAKE = b'/'           # '/' on keyboard (ASCII CHART)
REVERSE = b'-'         # '-'(minus sign) on keyboard (ASCII chart)
NEUTRAL = b','

def initialize():
    """
    Look for 'Arduino' in all serial ports
    :return: Serial Object
    """
    print("Connecting to Arduino....")
    """
     arduino_ports = [
        p.device
        for p in serial.tools.list_ports.comports()
        if 'Arduino' in p.description
        ]

    if not arduino_ports:
        raise IOError("No Arduino found")
        return None

    if len(arduino_ports) > 1:
        warnings.warn('Multiple Arduino found - using the first')
    """
    # ard = serial.Serial(arduino_ports[0])
    ard = serial.Serial('/dev/ttyACM1',9600)
    time.sleep(1)
    print("Initialized successfully: ", ard.name)

    return ard


def validate_steering_servo(ard, wait=0.01):
    """
    Let the Steering Servo moving back and forth 4 times
    :param ard: Arduino Serial Object
    :return:
    """
    if ard is not None:
        for i in range(3):
            # Move to the left
            for n in range(30):
                ard.write(TURN_LEFT)
                time.sleep(wait)

            ard.write(STRAIGHT)
            time.sleep(0.5)

            #  Move to the right
            for n in range(35):
                ard.write(TURN_RIGHT)
                time.sleep(wait)

            # Move back to the Neutral
            # print(i, 'Straight')
            ard.write(STRAIGHT)
            time.sleep(0.5)


def validate_esc_servo(ard):
    """
    Let the ESC (Electric Speed Control) Servo turn medium speed, brake, and medium reverse
    :param ard:
    :return:
    """
    if ard is not None:
        for i in range(1):
            # Speed up
            print("Speeding up...")
            for n in range(40):
                ard.write(ACCELERATE)
                time.sleep(0.03)
                print(ard.readline())

            print("Braking...")
            ard.write(BRAKE)
            time.sleep(3)
	    # Back to Neutral  before reversing
	    ard.write(NEUTRAL)
	    time.sleep(0.5)
            # Move to the right
            print("Backing up...")
            for n in range(40):
                ard.write(REVERSE)
                time.sleep(0.03)
                print(ard.readline())

            # Move back to the Neutral
            # print(i, 'Straight')
            ard.write(NEUTRAL)
            time.sleep(0.5)


if __name__ == "__main__":

    # initialize the servo
    arduino = initialize()
    time.sleep(1)
    # warm it up
    validate_steering_servo(arduino)
    time.sleep(1)
    validate_esc_servo(arduino)
    time.sleep(0.5)
    validate_steering_servo(arduino,0.005)

    print("\n\nClosing Serial Port...")
    arduino.close()


