#!/bin/bash

sudo echo "source export jetson-car/devel/setup.bash" >> ~/.bashrc

# To communicate to HOST, should be update when using wireless
export ROS_IP=192.168.1.79

# Add HOST IP (your laptop/pc)
sudo echo "192.168.1.76 dat" >> /etc/hosts

