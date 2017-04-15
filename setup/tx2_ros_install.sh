#!/bin/bash
# Install Robot Operating System (ROS) on NVIDIA Jetson
# Setup Locale
sudo update-locale LANG=C LANGUAGE=C LC_ALL=C LC_MESSAGES=POSIX

# Setup sources.lst
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

# Setup keys
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116

# Installation
sudo apt-get update
sudo apt-get  -y install ros-kinetic-ros-base

# Initialize rosdep
sudo apt-get  -y install python-rosdep

# There were some issues with Jeton TX2 Certificates, this is a workaround to run rosdep init
sudo c_rehash /etc/ssl/certs
sudo rosdep init

# To find available packages, use:
rosdep update

# Environment Setup
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc

# Install rosinstall
sudo apt-get -y install python-rosinstall
