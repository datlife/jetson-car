'''
This script activate pilot mode to take control over Jetson Car.

However, one can use joystick to stop by pressing X button
'''

# Keras Model
import keras
import json
from keras.models import model_from_json

# Utils
import argparse
import sys, os, time
import numpy as np
import cv2

# ROS libraries
import roslib
import rospy

# ROS mesages
from sensor_msgs.msg import Joy, Image
from rc_car_msgs.msg import CarInfo

class Pilot:
    # Activate autonomous mode in Jetson Car
    def __init__(self, args):
        # Initialize Publisher and Subscriber

        # Publish topic - CarInfo
        self.control_signal = rospy.Publisher('/car_info', CarInfo)

        # Subscribe to USB Camera
        self.camera = rospy.Subscriber('/usb_cam/image_raw', Image, self.callback, queue_size = 1)

        # Subscribe to Joystick Command

        # Load Keras Model
        self.model = self.load_model(args)

    def callback(self, data):

        # Convert image to cv2
        np_arr = np.fromstring(data.data, np.uint8)
        image = cv2.imdecode(np_arr, cv2.CV_LOAD_IMAGE_COLOR)

        start = time.clock()
        prediction = self.model.predict(image[None, :, :, :], batch_size=1)
        steering_angle = prediction[0][0]
        throttle = prediction[0][1]
        # throttle = 0.3

        end = time.clock()
        print "Steer: {:5.4f} Throttle {:5.4f} in {:5.4f}ms".format(steering_angle, throttle, (end - start)))

        self.send_control(steering_angle, throttle)
        # TODO:
        # POST STEER ANGLE PROCESSING - PID Controller

    def load_model(self, args):
        # LOAD Pre-trained model
        with open(args.model, 'r') as json_file:
        json_model = json_file.read()
        model = model_from_json(json_model)
        print('Pilot model is loaded...')
        model.compile("adam","mse")

        pre_trained_weights = args.model.replace('json', 'h5')
        model.load_weights(pre_trained_weights)
        return model

    def send_control(self, steering, throttle):
        # Publish a rc_car_msgs
        msg = CarInfo()
        msg.header.stamp = rospy.Time.now()
        msg.steer = steering
        msg.throttle = throttle
        self.control_signal.publish(msg)

def  main (args):

    pilot = Pilot(args=args)
    rospy.init("pilot_drive", anonymous=True)
    rospy.spin()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Remote Driving')
    parser.add_argument('model', type=str,help='Path to model json file. Model should be on the same path.')
    args = parser.parse_args()

