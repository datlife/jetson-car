
#!/bin/bash
# Install Jetson Car Dependencies

# Driver for Teensy 3.2 to be detected on Jetson
sudo apt-get -y install gcc-avr arduino
sudo apt-get -y install ros-kinetic-rosserial-arduino ros-kinetic-rosserial ros-kinetic-angles

# Driver for Logitech Joystick
sudo apt-get -y install ros-kinetic-joy

# The current ROS version of librealsense
sudo apt-get -y install ros-kinetic-librealsense
sudo apt-get -y install ros-kinetic-cv-bridge ros-kinetic-cv-camera ros-kinetic-jsk-pcl-ros-utils ros-kinetic-roslint
# sudo apt-get install ros-indigo-usb-cam -y

# Remove headers /usr/src since they DO NOT match Jetson TX2.
cd /usr/src
sudo rm -rf linux-headers-4.4.0-72* uvcvideo-1.1.1-3-realsense/
