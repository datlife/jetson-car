#!/bin/bash
#
# This script changes the group ("gpio") and permissions of most files in
# /sys/class/gpio directory, so that gpio could be accessed by non-root
# users in the "gpio" group.

chown -R root.gpio /sys/class/gpio
chmod 0220 /sys/class/gpio/export
chmod 0220 /sys/class/gpio/unexport

chown root.gpio /sys/class/gpio/*/direction
chown root.gpio /sys/class/gpio/*/edge
chown root.gpio /sys/class/gpio/*/value
chown root.gpio /sys/class/gpio/*/active_low
chmod 0664 /sys/class/gpio/*/direction
chmod 0664 /sys/class/gpio/*/edge
chmod 0664 /sys/class/gpio/*/value
chmod 0664 /sys/class/gpio/*/active_low
