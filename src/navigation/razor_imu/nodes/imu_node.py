#!/usr/bin/env python

'''
This node is used to publish the /imu node in ROS

Hardware: 
Sparksfun 9DoF IMU M0 (2017 - latest version)

Author: Tang Tiong Yew

Modified by: Dat Nguyen
'''

# Copyright (c) 2012, Tang Tiong Yew
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#    * Neither the name of the Willow Garage, Inc. nor the names of its
#      contributors may be used to endorse or promote products derived from
#       this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

import rospy
import serial
import string
import math
import sys

#from time import time
from sensor_msgs.msg import Imu
from tf.transformations import quaternion_from_euler
from dynamic_reconfigure.server import Server
from razor_imu_9dof.cfg import imuConfig

PAUSE_LOGGING       =  b' '    #  Space - Pause SD/UART logging
DISABLE_TIME        =  b't'    #  Disable time log (milliseconds)
DISABLE_COMPASS     =  b'm'    #  Disable Compass
ENABLE_QUAT         =  b'Q'
ENABLE_EULER        =  b'E'

# Covariance estimation:
ORIENT_COVARIANCE = [
0.005 , 0 , 0,
0, 0.005, 0,
0, 0, 0.005
]

ANGL_VEL_COVARIANCE = [
0.02, 0 , 0,
0 , 0.02, 0,
0 , 0 , 0.02
]

LIN_ACCEL_COVARIANCE = [
0.04 , 0 , 0,
0 , 0.04, 0,
0 , 0 , 0.04
]


imu_yaw_calibration = 0.
# Callback for dynamic reconfigure requests
def reconfig_callback(config, level):
    global imu_yaw_calibration
    rospy.loginfo("""Reconfigure request for yaw_calibration: %d""" %(config['yaw_calibration']))
    imu_yaw_calibration = config['yaw_calibration']
    rospy.loginfo("Set imu_yaw_calibration to %d" % (imu_yaw_calibration))
    return config


# ####################### ROS SET UP #########################
rospy.init_node("razor_node")
srv = Server(imuConfig, reconfig_callback)     # define dynamic_reconfigure callback
pub = rospy.Publisher('imu', Imu, queue_size=1) #We only care about the most recent measurement, i.e. queue_size=1

# ################### SERIAL PORT SET UP ######################
default_port='/dev/ttyACM1'
# Check your COM port and baud rate
rospy.loginfo("Opening %s...", default_port)
try:
    ser = serial.Serial(port=default_port, baudrate=115200, timeout=1)
except serial.serialutil.SerialException:
    rospy.logerr("IMU not found at port "+port + ". Did you specify the correct port in the launch file?")
    #exit
    sys.exit(0)

# ################### INIT & CALIBRATION ######################

#accelerometer
accel_x_min = rospy.get_param('~accel_x_min', -250.0)
accel_x_max = rospy.get_param('~accel_x_max', 250.0)
accel_y_min = rospy.get_param('~accel_y_min', -250.0)
accel_y_max = rospy.get_param('~accel_y_max', 250.0)
accel_z_min = rospy.get_param('~accel_z_min', -250.0)
accel_z_max = rospy.get_param('~accel_z_max', 250.0)
# gyroscope
gyro_average_offset_x = rospy.get_param('~gyro_average_offset_x', 0.0)
gyro_average_offset_y = rospy.get_param('~gyro_average_offset_y', 0.0)
gyro_average_offset_z = rospy.get_param('~gyro_average_offset_z', 0.0)
# magnetometer
magn_x_min = rospy.get_param('~magn_x_min', -600.0)
magn_x_max = rospy.get_param('~magn_x_max', 600.0)
magn_y_min = rospy.get_param('~magn_y_min', -600.0)
magn_y_max = rospy.get_param('~magn_y_max', 600.0)
magn_z_min = rospy.get_param('~magn_z_min', -600.0)
magn_z_max = rospy.get_param('~magn_z_max', 600.0)

calibration_magn_use_extended = rospy.get_param('~calibration_magn_use_extended', False)
magn_ellipsoid_center = rospy.get_param('~magn_ellipsoid_center', [0, 0, 0])
magn_ellipsoid_transform = rospy.get_param('~magn_ellipsoid_transform', [[0, 0, 0], [0, 0, 0], [0, 0, 0]])
imu_yaw_calibration = rospy.get_param('~imu_yaw_calibration', 0.0)

#@TODO : Calibration

roll=0
pitch=0
yaw=0
seq=0
degrees2rad = math.pi/180.0

rospy.loginfo("Giving the razor IMU board 3 seconds to boot...")
rospy.sleep(3) # Sleep for 5 seconds to wait for the board to boot

#################################
### IMU Board Configuration #####
#################################
ser.write(DISABLE_TIME)
ser.write(DISABLE_COMPASS)
ser.write(ENABLE_EULER)
ser.write(ENABLE_QUAT)

imuMsg = Imu()
# Orientation covariance estimation
imuMsg.orientation_covariance = ORIENT_COVARIANCE
imuMsg.angular_velocity_covariance = ANGL_VEL_COVARIANCE
imuMsg.linear_acceleration_covariance = LIN_ACCEL_COVARIANCE

# @TODO : bug when disable and enable TIME

sample = ser.readline()
print("IMU Format:<accelX>, <accelY>, <accelZ>, <gyroX>, <gyroY>, <gyroZ>, <quatW>, <quatX>, <quatY>, <quatZ>, <pitch>, <roll>, <yaw>")
print("Sample Data: " +  sample)

while not rospy.is_shutdown():
    line = ser.readline()
    measurement = string.split(line,",")    # Fields split
    if len(measurement) > 2:
#@TODO: CORRECT IMU MEASUREMENT 
# Unceted/Kalman filter? robot_localization package

        # Followed REP-103 ROS
        # http://www.ros.org/reps/rep-0103.html

	# Linear Acceleration
        imuMsg.linear_acceleration.x = float(measurement[0])   
        imuMsg.linear_acceleration.y = float(measurement[1])
        imuMsg.linear_acceleration.z = -float(measurement[2])   # Gravity force should pull down

        # Angular Velocity
        imuMsg.angular_velocity.x = float(measurement[3])
        imuMsg.angular_velocity.y = float(measurement[4])        
        imuMsg.angular_velocity.z = float(measurement[5])  

        # Euler angle
        pitch = float(measurement[9])*degrees2rad
        roll  = float(measurement[10])*degrees2rad
        yaw   = float(measurement[11])*degrees2rad
  
        # Quaterion
        imuMsg.orientation.w = float(measurement[6])
        imuMsg.orientation.x = float(measurement[7])
        imuMsg.orientation.y = float(measurement[8])
        imuMsg.orientation.z = float(measurement[9])

# 	q = quaternion_from_euler(yaw, pitch, roll, 'rzyx')	
#        imuMsg.orientation.w = q[0]
#        imuMsg.orientation.x = q[1]
#        imuMsg.orientation.y = q[2]
#        imuMsg.orientation.z = q[3]
        imuMsg.header.stamp= rospy.Time.now()
        imuMsg.header.frame_id = 'base_imu_link'
        imuMsg.header.seq = seq
        seq = seq + 1
        pub.publish(imuMsg)

ser.close()
