#!/bin/bash
#
# This script is used to do simple tests of GPIO.
# Reference: https://developer.ridgerun.com/wiki/index.php/How_to_use_GPIO_signals

show_usage()
{
    printf "\nUsage: gpio.sh <gpio pin number> [in|out [<value>]]\n"
}

if [ $# -eq 0 -o $# -gt 3 ]; then
    show_usage
    printf "\nERROR: incorrect number of parameters\n"
    exit 255
fi

if [ ! -d /sys/class/gpio/gpio$1 ]; then
    echo $1 > /sys/class/gpio/export
    # sleep 1 second here to make sure udev rule takes effect
    sleep 1
fi

if [ $# -eq 1 ]; then
   cat /sys/class/gpio/gpio$1/value
   exit 0
fi

if [ "$2" != "in" -a "$2" != "out" ] ; then
    show_usage
    printf "\nERROR: second parameter must be 'in' or 'out'\n"
    exit 255
fi

echo $2 > /sys/class/gpio/gpio$1/direction

if [ $# -eq 2 ]; then
   cat /sys/class/gpio/gpio$1/value
   exit 0
fi

VAL=$3
if [ $VAL -ne 0 ]; then
    VAL=1
fi

echo $VAL > /sys/class/gpio/gpio$1/value
