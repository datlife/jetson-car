#!/bin/bash

# Start patch process
cd /usr/src/kernel/kernel-4.4
# Make sure that there's a config file
file=".config"
if [ -f "$file" ]
then
	echo "$file found. Patching UVC Video module"
else
	echo "$file not found."
	echo "Kernel source must be installed and configured correctly."
        echo "Exiting"
	exit 1
fi
sudo sed -i 's/.*CONFIG_USB_VIDEO_CLASS=.*/CONFIG_USB_VIDEO_CLASS=m/' .config
sudo patch -p1 -i $HOME/librealsense/scripts/realsense-camera-formats.patch


# cd /usr/src/
# sudo rm -rf linux-headers-4.4.0-75*
# sudo rm -rf uvcvideo-1.1.1-3-realsense/
