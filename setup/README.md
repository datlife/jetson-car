# How to Set Up Jetson Car in 10 minutes

This README will walk through how to set up Jetson Car.

### Prerequisites:

1. Installed OS from JetPack 3.0

------------------------------------
### Install ROS Kinetic

* Execute [scrtips/ros_setup.sh](https://github.com/dat-ai/jetson-car/blob/master/setup/tx2_ros_install.sh) to install ROS Kinetic on Jetson automatically.
 
```
# Set up standard ROS workspace
cd jetson-car/src/
catkin_init_make
cd ..
catkin_make
```
### Install Realsense Camera Library
http://www.jetsonhacks.com/2017/03/26/intel-realsense-camera-installation-nvidia-jetson-tx2/

### Build Custom Kernel Modules on Jetson TX2

The purpose is to allow NVIDIA Jetson detect additional image formats from Stereo Camera Intel Realsense, by enabling **USB Video Class Module**.

Accoding to [jetsonhacks](http://www.jetsonhacks.com/2017/03/26/intel-realsense-camera-installation-nvidia-jetson-tx2/), we can understand kernel and kernel module in Linux as following:

> **The kernel** is the code that is the base of the operating system, the interface between hardware and the application code.

> **A kernel module** is code that can be accessed from the kernel on demand, without having to modify the kernel. These modules provide ancillary support for different types of devices and subsystems.


----

Follow wonderful instruction from JetsonHacks to create custom Kernel Modules for NVIDIA Jetson
```
http://www.jetsonhacks.com/2017/03/25/build-kernel-and-modules-nvidia-jetson-tx2/
```

**1. What the scripts do:**
* Download and extract Kernel Source
* Build Kernel Source
* Copy Kernel to /boot

**2. What do you need to to?**
* Create a custom kernel name (e.g `4.4.0-jetson-car-1.0`)
* Enable `USB CH341` chipset when configuring Kernel Module
