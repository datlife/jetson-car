'''
This script activate pilot mode to take control over Jetson Car.

However, one can use joystick to stop by pressing X button
'''

# Keras Model
import keras
from keras import backend as K

# Utils
import numpy as np
import cv2
import threading

# ROS libraries
import roslib
import rospy

# ROS mesages
from sensor_msgs.msg import Joy, Image # we could combine Image into CarInfo
from rc_car_msgs.msg import CarInfo

class Pilot:
    # Activate autonomous mode in Jetson Car
    def __init__(self, get_model_callback, model_callback):
        
	rospy.init_node("pilot_steering_model", anonymous=True)
        
	# Load Keras Model
        self.model = get_model_callback()
	self.get_model = get_model_callback
	self.predict = model_callback

	# Initialize
	self.image = None
        self.steering = 0.0
	self.throttle = 0.0

        # Publish topic - CarInfo
        self.control_signal = rospy.Publisher('/car_info', CarInfo, queue_size=1)
        # Subscribe to USB Camera
        self.camera = rospy.Subscriber('/usb_cam/image_raw', Image, self.callback, queue_size = 1)
        # Subscribe to Joystick Command
	# self.joy = rospy.Subscriber('/joy', Joy)

	# Lock which waiting for keras model to make prediction
	self.lock = threading.RLock()
	rospy.Timer(rospy.Duration(0.02), self.send_control)
    	
    def callback(self, webcam):
        d = map(ord, webcam.data)
        img = np.ndarray(shape=(webcam.height, webcam.width, 3),
                         dtype=np.uint8,
                         buffer=np.array(d))[:,:,::-1]
	# what is image size ?
	if self.lock.acquire(True):
	   self.image = img
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

