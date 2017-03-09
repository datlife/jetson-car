#!/usr/bin/env python
'''
Create Pilot Model
'''
# Keras Model
import json
from keras.models import model_from_json
import rospy
# Utils
import argparse
import time
import cv2
import time

from Pilot import Pilot


def drive(model, image):
    '''
    Make prediction  on steering angle given an image
    :param model:
    :param image:
    :return:
    '''
    if image is None:
        return
    # Resize to fit the model
    image = cv2.resize(image, (160, 80), interpolation=cv2.INTER_AREA)
    # Crop the sky
    image = image[29:75, :]
    start = time.clock()  # Measure how fast model makes one prediction (speed = stop - start)
    prediction = model.predict(image[None, :, :, :], batch_size=1)
    steering_angle = prediction[0][0]
    # throttle = prediction[0][1]
    throttle = 0.001
    end = time.clock()
    print "Steer: {:5.4f} Throttle {:5.4f} in {:5.4f}ms".format(steering_angle, throttle, (end - start))

    # TODO:
    # POST STEER ANGLE PROCESSING - PID Controller
    return steering_angle, throttle


def load_model(args):
    # LOAD Pre-trained model
#    path = args.model
    path = args
    with open(path, 'r') as json_file:
        json_model = json_file.read()
        model = model_from_json(json_model)
    print('Pilot model is loaded...')
    model.compile("adam", "mse")

    pre_trained_weights = path.replace('json', 'h5')
    model.load_weights(pre_trained_weights)
    return model

if __name__ == "__main__":
#   parser = argparse.ArgumentParser(description='Remote Driving')
#   parser.add_argument('model', type=str, help='Path to model json file. Model should be on the same path.')
#   args = parser.parse_args()
    args = '/home/ubuntu/jetson-car/src/pilot/src/cnn.json'
    print("Activating AutoPilot mode..\n")
    pilot = Pilot(lambda: load_model(args), drive)
    rospy.spin() 


