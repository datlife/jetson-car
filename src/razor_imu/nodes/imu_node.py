#!/usr/bin/env python

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
from diagnostic_msgs.msg import DiagnosticArray, DiagnosticStatus, KeyValue

PAUSE_LOGGING       =  b' '    #  Space - Pause SD/UART logging
DISABLE_TIME        =  b't'    #  Enable/disable time log (milliseconds)
DISABLE_COMPASS     =  b'm'    #  Enable/Disable Compass
ENABLE_QUAT         =  b'q'
ENABLE_EULER        =  b'e'

# ENABLE_CALIB_MODE   =  b'x'   #  Enable Calibration mode **NOT WORKING YET**

degrees2rad         =  math.pi/180.0
imu_yaw_calibration = 0.
accel_factor        = 9.806 / 256.0    # sensor reports accel as 256.0 = 1G (9.8m/s^2). Convert to m/s^2.

# Covariance estimation:
ORIENT_COVARIANCE = [
0.0025 , 0 , 0,
0, 0.0025, 0,
0, 0, 0.0025
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
diag_pub = rospy.Publisher('diagnostics', DiagnosticArray, queue_size=1)
diag_pub_time = rospy.get_time();

# ################### SERIAL PORT SET UP ######################
default_port='/dev/ttyUSB0'
port = rospy.get_param('~port', default_port)
# Check your COM port and baud rate
rospy.loginfo("Opening %s...", port)
try:
    ser = serial.Serial(port=port, baudrate=57600, timeout=1)
except serial.serialutil.SerialException:
    rospy.logerr("IMU not found at port "+port + ". Did you specify the correct port in the launch file?")
    #exit
    sys.exit(0)

# ################### INIT & CALIBRATION ######################
imuMsg = Imu()

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

'''
NOT WORKING YET!
# Start Calibration
rospy.loginfo("Writing calibration values to razor IMU board... Please wait 8 seconds")
ser.write(ENABLE_CALIB_MODE)
ser.write(PAUSE_LOGGING)  # Enable Logging
ser.flushInput()
calib_data = ser.readlines()
calib_data_print = "Printing set calibration values:\r\n"
for line in calib_data:
    calib_data_print += line
rospy.loginfo(calib_data_print)
'''

roll=0
pitch=0
yaw=0
seq=0
rospy.loginfo("Giving the razor IMU board 3 seconds to boot...")
rospy.sleep(3) # Sleep for 5 seconds to wait for the board to boot

### configure board ###


# Orientation covariance estimation:
imuMsg.orientation_covariance = ORIENT_COVARIANCE
imuMsg.angular_velocity_covariance = ANGL_VEL_COVARIANCE
imuMsg.linear_acceleration_covariance = LIN_ACCEL_COVARIANCE

ser.write(PAUSE_LOGGING)
ser.write(DISABLE_TIME)
ser.write(DISABLE_COMPASS)
ser.write(ENABLE_EULER)
ser.write(ENABLE_QUAT)
while not rospy.is_shutdown():
    line = ser.readline()
    # IMU data: <timeMS>, <accelX>, <accelY>, <accelZ>, <gyroX>, <gyroY>, <gyroZ>, <magX>, <magY>, <magZ>

    #f.write(line)                     # Write to the output log file
    words = string.split(line,",")    # Fields split
    if len(words) > 2:

        # This means y and z are correct for ROS, but x needs reversing
        imuMsg.linear_acceleration.x = -float(words[0]) * accel_factor
        imuMsg.linear_acceleration.y = float(words[1]) * accel_factor
        imuMsg.linear_acceleration.z = float(words[2]) * accel_factor

        imuMsg.angular_velocity.x = float(words[3])
        imuMsg.angular_velocity.y = -float(words[4])        # in ROS y axis points left (see REP 103)
        imuMsg.angular_velocity.z = -float(words[5])        #in ROS z axis points up (see REP 103)


        yaw_deg = -float(words[6])                          # in ROS z axis points up (see REP 103)
        yaw_deg = yaw_deg + imu_yaw_calibration
        if yaw_deg > 180.0:
            yaw_deg = yaw_deg - 360.0
        if yaw_deg < -180.0:
            yaw_deg = yaw_deg + 360.0
        yaw = yaw_deg*degrees2rad
        pitch = -float(words[7])*degrees2rad                 # in ROS y axis points left (see REP 103)
        roll = float(words[8])*degrees2rad

    q = quaternion_from_euler(roll,pitch,yaw)
    imuMsg.orientation.x = q[0]
    imuMsg.orientation.y = q[1]
    imuMsg.orientation.z = q[2]
    imuMsg.orientation.w = q[3]
    imuMsg.header.stamp= rospy.Time.now()
    imuMsg.header.frame_id = 'base_imu_link'
    imuMsg.header.seq = seq
    seq = seq + 1
    pub.publish(imuMsg)

    if (diag_pub_time < rospy.get_time()) :
        diag_pub_time += 1
        diag_arr = DiagnosticArray()
        diag_arr.header.stamp = rospy.get_rostime()
        diag_arr.header.frame_id = '1'
        diag_msg = DiagnosticStatus()
        diag_msg.name = 'Razor_Imu'
        diag_msg.level = DiagnosticStatus.OK
        diag_msg.message = 'Received AHRS measurement'
        diag_msg.values.append(KeyValue('roll (deg)', str(roll*(180.0/math.pi))))
        diag_msg.values.append(KeyValue('pitch (deg)', str(pitch*(180.0/math.pi))))
        diag_msg.values.append(KeyValue('yaw (deg)', str(yaw*(180.0/math.pi))))
        diag_msg.values.append(KeyValue('sequence number', str(seq)))
        diag_arr.status.append(diag_msg)
        diag_pub.publish(diag_arr)
        
ser.close()
