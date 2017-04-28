#!/usr/bin/env python
''' Recorder Object '''
import rospy
import roslib

# Utils
import cv2
import csv
import threading
import numpy as np
import os.path

# Convert Image msg into an image
from cv_bridge import CvBridge, CvBridgeError

from rc_car_msgs.msg import CarInfo
from sensor_msgs.msg import Image
from rc_car_msgs.msg import CarRecorder

DEFAULT_LOCATION = "/home/nvidia/bag/"
RGB_IMG_PATH = "/home/nvidia/bag/imgs/"
DEPTH_IMG_PATH = "/home/nvidia/bag/depth_imgs/"
DRIVING_LOG_PATH="/home/nvidia/bag/driving_log.csv"

def camera_callback(camera):
    '''Convert sensor_msg::Image to an image'''
    global lock, image, steering, throttle, cv_bridge
    if lock.acquire(True):
	image = cv_bridge.imgmsg_to_cv2(camera)
        lock.release()

def car_info_callback(carinfo):
    global steering,throttle, speed
    steering = carinfo.steer
    throttle = carinfo.throttle	
    speed    = carinfo.speed

def depth_cam_callback(depth_cam):
    global lock, depth_img, steering, throttle, cv_bridge
    if lock.acquire(True):
        depth_img = cv_bridge.imgmsg_to_cv2(depth_cam)
	lock.release()
 
# Shared variables
steering = 0.0
throttle = 0.0
speed = 0.0
image = None
depth_img = None
seq = 1

# Set up ROS
rospy.init_node("recorder_device", anonymous=True)
record_pub   = rospy.Publisher("/recorder", CarRecorder, queue_size=1)
joy_listener = rospy.Subscriber("/car_info", CarInfo, car_info_callback)
cam_listener = rospy.Subscriber("/camera/rgb/image_rect_color_drop", Image, camera_callback)
epth_cam_listener = rospy.Subscriber("camera/depth/image_rect_raw_drop", Image, depth_cam_callback)

# Open driving_log file
if os.path.isfile(DRIVING_LOG_PATH) is True:
	f = open(DRIVING_LOG_PATH,'ab')
	driving_log = csv.DictWriter(f, fieldnames=["RGB Image","Depth Image", "Steering Angle", "Throttle"])
else:
	f = open(DRIVING_LOG_PATH,'wb')
	driving_log = csv.DictWriter(f, fieldnames=["RGB Image","Depth Image", "Steering Angle", "Throttle"])
	driving_log.writeheader()

# Lock to acquire camera iamge
lock = threading.RLock()


# Set up CV Bridge to transform ROS Image to OpenCV Image
cv_bridge = CvBridge()

# Keep publishing info until rospy is shut down
print("\n\nStart publishing data via /recorder [steering, throttle] and images is saved at /home/nvidia/bag/imgs.\n Press 'X' to stop the recording process.\n")


while not rospy.is_shutdown():
    if image is None:
      	continue
    # Convert image to RGB color space
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    # Create image filename for current frame
    timestamp = rospy.get_rostime()
    # RGB image
    fname = str(timestamp)+"_"+str(seq) +"_"+str(round(steering, 6)) + "_"+ str(round(throttle,6)) 
    fname = RGB_IMG_PATH+fname+".jpg"
    # Depth Image
    depth_fname = str(timestamp)+"_"+str(seq) +"_"+str(round(steering, 6)) + "_"+ str(round(throttle,6))
    depth_fname = DEPTH_IMG_PATH+depth_fname+".jpg"
    # Write images into disk
    cv2.imwrite(fname, image)
    cv2.imwrite(depth_fname, depth_img)
    
    # new csv line
    driving_log.writerow({'RGB Image': fname, 'Depth Image': depth_fname, 'Steering Angle': steering,'Throttle': throttle,'Speed': speed})
    # publish data to /car_recorder
    msg = CarRecorder()
    msg.steer = steering
    msg.throttle = throttle
    msg.speed = speed
    msg.img_path = fname
    record_pub.publish(msg)
    seq +=1
    # Set rate at 30 Hz
    rospy.sleep(0.034)

