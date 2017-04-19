#!/bin/bash
# Install Jetson Car Dependencies

# Driver for Teensy 3.2 (Arduino-ish) 
sudo apt-get -y install gcc-avr arduino
sudo apt-get -y install ros-kinetic-rosserial-arduino ros-kinetic-rosserial ros-kinetic-angles

# Driver for Logitech Joystick
sudo apt-get -y install ros-kinetic-joy

# Driver for USB Camera node
sudo apt-get -y install ros-kinetic-cv-bridge ros-kinetic-cv-camera ros-kinetic-jsk-pcl-ros-utils ros-kinetic-roslint
sudo apt-get -y install v4l-utils 

# The current ROS version of librealsense
# NOT WORKING yet
# sudo apt-get -y install ros-kinetic-librealsense
# Remove headers /usr/src since they DO NOT match Jetson TX2.
# cd /usr/src
# sudo rm -rf linux-headers-4.4.0-72* uvcvideo-1.1.1-3-realsense/

