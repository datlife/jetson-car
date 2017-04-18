How to Set Up Jetson Car
========================

This README will walk through how to set up Jetson Car.


Hardware / Bill Of Materials
----------------------------
* Note: I am working on Bill of Materials. Stay tuned!

1. An RC Car - [RedCat Volcano EPX](https://www.amazon.com/Redcat-Racing-Electric-Volcano-Included/dp/B00HVBVNVG/ref=sr_1_2?ie=UTF8&qid=1487805887&sr=8-2&keywords=RedCat+Volcano+EPX) (stock - no mod) + [Extra battery](https://www.amazon.com/Redcat-Racing-HX-3800MH-B-Battery-7-2V-Connector/dp/B00D2539IU/ref=sr_1_1?ie=UTF8&qid=1487805956&sr=8-1&keywords=Redcat-Racing+HX-3800MH)
2. NVIDIA Jetson TX2
3. Teensy 3.2
4. Intel RealSense R200
5. USB Webcam Logitech C920
6. Razor IMU 9DoF
7. Anker 4-port USB 3.0 Hub
8. RAVPower 23000mAh Power Bank

Software
--------

1. Stock OS for Jetson TX2 (JetPack 3.0)
3. ROS Kinetic for ARM (barebone version)
4. Keras using TensorFlow as backend
5. TensorFlow 1.0.1


Installation Steps
------------------

* Execute [`scripts/1_installRos.sh`](https://github.com/dat-ai/jetson-car/blob/master/setup/scripts/1_installRos.sh) and [`scripts/2_installDependencies.sh`](https://github.com/dat-ai/jetson-car/blob/master/setup/scripts/2_installDependencies.sh) to run automatically.
```
# Optional: make sure you are in `setup` directorty
cd ./setup

sudo ./scripts/1_installRos.sh
sudo ./scripts/2_installDependencies.sh
```
------------------------------------
### Install Realsense Camera Library
http://www.jetsonhacks.com/2017/03/26/intel-realsense-camera-installation-nvidia-jetson-tx2/


----------------------------------------------
### Build Custom Kernel Modules on Jetson TX2

The purpose is to allow NVIDIA Jetson detect additional image formats from Stereo Camera Intel Realsense

One can understand kernel and kernel module in Linux as following:

> **The kernel** is the code that is the base of the operating system, the interface between hardware and the application code.
> **A kernel module** is code that can be accessed from the kernel on demand, without having to modify the kernel. These modules provide ancillary support for different types of devices and subsystems.
- [jetsonhacks](http://www.jetsonhacks.com/2017/03/26/intel-realsense-camera-installation-nvidia-jetson-tx2/),
----

Follow instruction from JetsonHacks to create custom Kernel Modules for NVIDIA Jetson
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

-------------------------------
###  Build catkinw_ws workspace
cd jetson-car/src/
catkin_init_make
cd ..
catkin_make
