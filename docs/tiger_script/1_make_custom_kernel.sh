#!/bin/bash
#
# This script will automatically download kernel source, enable and install neccessary kernel modules for Tiger Car
#
# Written by: Dat Nguyen
# Last Update: 04/30/2017
#

sudo apt-add-repository universe
sudo apt-get update

###########################################################
##### DOWNLOAD AND ENABLE NECCESSARY KERNEL MODULES #######
###########################################################

# Download kernel source 27.1.0
cd /usr/src
wget http://developer.download.nvidia.com/embedded/L4T/r27_Release_v1.0/BSP/r27.1.0_sources.tbz2
tar -xvf r27.1.0_sources.tbz2 kernel_src.tbz2
tar -xvf kernel_src.tbz2
cd kernel/kernel-4.4

# Build config file, where we will enable necessary kernel modules 
zcat /proc/config.gz > .config

# Create a custom kernel name
sudo sed -i 's/.*CONFIG_LOCALVERSION="".*/CONFIG_LOCALVERSION="-tiger-car-1.0"/' /usr/src/kernel/kernel-4.4/.config

# 1. Enable USB_ACM to detect Teensy, IMU sensor
sudo sed -i 's/.*CONFIG_USB_ACM.*/CONFIG_USB_ACM=y/' /usr/src/kernel/kernel-4.4/.config

# 2. Enable USB_CH341 for Intel Realsense
sudo sed -i 's/.*CONFIG_USB_SERIAL_CH341.*/CONFIG_USB_SERIAL_CH341=y/' /usr/src/kernel/kernel-4.4/.config

# 3. Enable Joy Stick support
# sudo sed -i 's/.*CONFIG_INPUT_JOYDEV.*/CONFIG_INPUT_JOYDEV=y/' /usr/src/kernel/kernel-4.4/.config
sudo sed -i 's/.*CONFIG_INPUT_JOYSTICK.*/CONFIG_INPUT_JOYSTICK=y/' /usr/src/kernel/kernel-4.4/.config


