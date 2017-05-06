#!/bin/bash
#
# This script is used to enable the user "ubuntu" to access GPIO through
# /sys/class/gpio interface. It only needs to be executed once. Make sure
# you have "fix_udev_gpio.sh" and "99-com.rules" in the same directory
# when you run this script.

sudo groupadd gpio
sudo usermod -a -G gpio ubuntu
sudo cp fix_udev_gpio.sh /usr/local/bin/
sudo chmod a+x /usr/local/bin/fix_udev_gpio.sh

sudo chown -R root.gpio /sys/class/gpio
sudo chmod 0220 /sys/class/gpio/export
sudo chmod 0220 /sys/class/gpio/unexport

sudo cp 99-com.rules /etc/udev/rules.d/
