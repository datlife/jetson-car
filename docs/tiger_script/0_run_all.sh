#!/bin/bash

# Combines scripts below in one file

sudo ./1_make_custom_kernel.sh
sudo ./3_install_ros.sh
sudo ./4_install_realsense.sh
sudo ./5_install_ros_realsense.sh


sudo ./2_build_and_copy_kernel.sh

# Disable USB autosuspend
sudo sed -i '$s/$/ usbcore.autosuspend=-1/'  /boot/extlinux/extlinux.conf
# /bin/ required for echo to work correctly in /bin/sh file
/bin/echo -e "\e[1;32mPlease reboot for changes to take effect.\e[0m"

