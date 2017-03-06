'''
Create Pilot Model

reference: https://gist.github.com/spicavigo/3afde12b5b48b0de8e7294f1d58934c6
'''
# Keras Model
import keras
import json
from keras.models import model_from_json
import tensorflow as tf
from keras import backend as K
import rospy
import roslib
# Utils
import argparse
import sys, os, time
import numpy as np
import cv2
import time

from pilot import Pilot

def load_model(args):
    # LOAD Pre-trained model
    K.clear_session()
    with tf.Graph().as_default():
        session = tf.Session('')
        K.set_session(session)
        with open(args.model, 'r') as json_file:
            json_model = json_file.read()
            model = model_from_json(json_model)
        print('Pilot model is loaded...')
        model.compile("adam","mse")

        pre_trained_weights = args.model.replace('json', 'h5')
        model.load_weights(pre_trained_weights)
        return model

def drive(model, image):

	if image is None:
	    return

	start = time.clock()  # Measure how fast model makes one prediction (speed = stop - start)
	# Resize to fit the model
	image = cv2.resize(image, (160, 80), interpolation=cv2.INTER_AREA)
	# Crop the sky
	image = image[29:75, :]
	prediction = model.predict(image[None, :, :, :], batch_size=1)
	steering_angle = prediction[0][0]
	# throttle = prediction[0][1]
	throttle = 0.001
	end = time.clock()
	print "Steer: {:5.4f} Throttle {:5.4f} in {:5.4f}ms".format(steering_angle, throttle, (end - start))

	# TODO:
	# POST STEER ANGLE PROCESSING - PID Controller
	return steering, throttle

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Remote Driving')
    parser.add_argument('model', type=str,help='Path to model json file. Model should be on the same path.')
    args = parser.parse_args()

    print("Activating AutoPilot mode..\n")
    pilot = Pilot(lambda: load_model(args), drive)
    rospy.spin() 


