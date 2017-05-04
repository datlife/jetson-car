#!/bin/bash

sudo echo "source jetson-car/devel/setup.bash" >> ~/.bashrc

# To communicate to HOST, should be update when using wireless
sudo echo "export ROS_IP=192.168.1.79" >> ~/.bashrc

# Add HOST IP (your laptop/pc)
sudo echo "192.168.1.78 dat" | sudo tee --append /etc/hosts

