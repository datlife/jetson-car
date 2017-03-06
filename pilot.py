'''
This script activate pilot mode to take control over Jetson Car.

However, one can use joystick to stop by pressing X button
'''

# Keras Model
import keras
import tensorflow as tf
from keras.models import model_from_json
from keras import backend as K

# Utils
import argparse
import time
import cv2
import time
import json

# Utils
import numpy as np
import cv2
import threading

# ROS libraries
import roslib
import rospy

# ROS mesages
from sensor_msgs.msg import Joy, Image  # we could combine Image into CarInfo
from rc_car_msgs.msg import CarInfo

class Pilot:
    # Activate autonomous mode in Jetson Car
    def __init__(self, get_model_call_back, model_callback, args=None):
        self.steering = 0.0
        self.throttle = 0.0
        self.image = None
        self.model = None
        self.get_model = get_model_call_back
        self.predict = model_callback

        # Load Keras Model
        # Publish topic - CarInfo
        rospy.init_node("pilot_steering_model", anonymous=True)
        self.control_signal = rospy.Publisher('/car_info', CarInfo, queue_size=1)
        self.camera = rospy.Subscriber('/usb_cam/image_raw', Image, self.callback, queue_size = 1)
        self.joy = rospy.Subscriber('/joy', Joy)

        # Lock which waiting for keras model to make prediction
        self.lock = threading.RLock()
        rospy.Timer(rospy.Duration(0.02), self.send_control)

    def callback(self, camera):
        d = map(ord, camera.data)
        img = np.ndarray(shape=(camera.height, camera.width, 3),
                         dtype=np.uint8,
                         buffer=np.array(d))[:, :, ::-1]
        if self.lock.acquire(True):
            self.image = img
            # print("Predicting... \n")
            # To avoid create loop
            # tf.reset_default_graph()
            if self.model is None:
                self.model = self.get_model()
            # Predict steering & throttle using image
            self.steering, self.throttle = self.predict(self.model, self.image)
            self.lock.release()

    def send_control(self, event):
        if self.image is None:
            return
            # Publish a rc_car_msgs
        msg = CarInfo()
        msg.header.stamp = rospy.Time.now()
        msg.steer = self.steering
        msg.throttle = self.throttle
        self.control_signal.publish(msg)

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
            model.compile("adam", "mse")

            pre_trained_weights = args.model.replace('json', 'h5')
            model.load_weights(pre_trained_weights)
            return model



def drive(model, image):
    '''
    Make prediction  on steering angle given an image
    :param model:
    :param image:
    :return:
    '''
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
    return steering_angle, throttle


def load_model(args):
    # LOAD Pre-trained model
    with open(args.model, 'r') as json_file:
        json_model = json_file.read()
        model = model_from_json(json_model)
    print('Pilot model is loaded...')
    model.compile("adam", "mse")

    pre_trained_weights = args.model.replace('json', 'h5')
    model.load_weights(pre_trained_weights)
    return model

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Remote Driving')
    parser.add_argument('model', type=str, help='Path to model json file. Model should be on the same path.')
    args = parser.parse_args()

    print("Activating AutoPilot mode..\n")
    pilot = Pilot(lambda: load_model(args), drive)
    rospy.spin() 



