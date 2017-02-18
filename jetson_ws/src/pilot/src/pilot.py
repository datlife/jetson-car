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
# ROS libraries
import roslib
import rospy

# ROS mesages
import sensor_msgs.msg import Joy
import rc_car_msgs.msg import CarInfo

def load_model(args):
     
    # LOAD Pre-trained model
    with open(args.model, 'r') as json_file:
	json_model = json_file.read()
	model = model_from_json(json_model)
    print('Pilot model is loaded...')
    model.compile("adam","mse")

    pre_trained_weights = args.model.replace('json', 'h5')
    model.load_weights(pre_trained_weights)
    return model

def drive(model):
     # get a frame from usb_cam
     image = np.asarray(image)
     image = imresize(image, 0.5)
     start = time.clock()
     prediction = model.predict(image[None, :, :, :], batch_size=1)
     steering_angle = prediction[0][0]
     throttle = prediction[0][1]
     # throttle = 0.3
      end = time.clock()

     # TODO:
     # POST STEER ANGLE PROCESSING - PID Controller
     print("Steer: {:5.4f} Throttle {:5.4f} in {:5.4f}ms".format(steering_angle, throttle, (end-start)))
     send_control(steering_angle, throttle)

def send_control(steering, throttle):
'''
Publish a rc_car_msgs
'''
     
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Remote Driving')
    parser.add_argument('model', type=str,help='Path to model json file. Model should be on the same path.')
    args = parser.parse_args()
    pilot_model = load_model(args)

