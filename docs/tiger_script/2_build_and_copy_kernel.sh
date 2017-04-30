#!/bin/bash

##################################
##### BUILD KERNEL MODULES #######
##################################

# Fix makefile compiling issue during make modules
sudo ./scripts/fixMakeFiles.sh

# @TODO How to automatically select default option during building kernel process?
#  During building Joystick kernel module, it would ask us to enter Yes/No option

cd /usr/src/kernel/kernel-4.4
make prepare
make modules_prepare
make -j6
make modules
make modules_install

# Copy to current kernel directory
cd /usr/src/kernel/kernel-4.4
sudo cp arch/arm64/boot/zImage /boot/zImage
sudo cp arch/arm64/boot/Image /boot/Image

