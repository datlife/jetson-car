#!/bin/bash

sudo apt-get install ros-kinetic-librealsense -y
sudo -u $USER rosdep update
cd /usr/src/

sudo rm -rf linux-headers-4.4.0-75*
sudo rm -rf uvcvideo-1.1.1-3-realsense/
