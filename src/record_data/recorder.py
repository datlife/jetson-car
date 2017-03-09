#!/usr/bin/env python
''' Recorder Object '''
import rospy
import roslib

# Utils
import cv2
import threading
import numpy as np

from sensor_msgs.msg import Joy
from sensor_msgs.msg import Image
from rc_car_msgs.msg import CarRecorder

DEFAULT_LOCATION = "/home/ubuntu/bag/"

def camera_callback(camera):
    '''Convert sensor_msg::Image to an image'''
    global lock, image
    if lock.acquire(True):
        image = camera
        lock.release()

def joy_callback( joy):
    global steering,throttle
    steering = joy.axes[0]
    throttle = joy.axes[3]	

# Shared variables
steering = 0.0
throttle = 0.0
image = None

# Set up ROS
rospy.init_node("recorder_device", anonymous=True)
record_pub   = rospy.Publisher("/recorder", CarRecorder, queue_size=1)
joy_listener = rospy.Subscriber("/joy", Joy, joy_callback)
cam_listener = rospy.Subscriber("/usb_cam/image_raw", Image, camera_callback)

# Lock to acquire camera iamge
lock = threading.RLock()

# Keep publishing info until rospy is shut down
print("\n\nPublishing data via /recorder [image, steering, throttle]..\n Press 'X' to stop the recording process.\n")

while not rospy.is_shutdown():
    if image is None:
          continue
    # publish data  
    msg = CarRecorder()
    msg.steer = steering
    msg.throttle = throttle
    msg.image  = image
    record_pub.publish(msg)
    # Set rate at 50 Hz
    rospy.sleep(0.02)

