How to Set Up Jetson Car
========================

This README will walk through how to set up Jetson Car.


Hardware / Bill Of Materials
----------------------------
* Note: I am working on Bill of Materials. Stay tuned!


| **Item**                                         | **Unit** | **Estimated Price** | **Notes**                                                     |
|--------------------------------------------------|----------|---------------------|---------------------------------------------------------------|
| RedCat Volcano EPX Brushed                       | 1        | $139.99             |                                                               |
| NVIDIA Jetson TX2                                | 1        | $599.99             | If you are a student, you can apply for 50% student discount. |
| Teensy 3.2                                       | 1        | $29.95              |                                                               |
| Intel RealSense R200                             | 1        | $109.00             |                                                               |
| Logitech C920 USB Webcam                         | 1        | $61.50              | H264 encoded MJPEG                                            |
| Sparkfun Razor IMU 9DoF                          | 1        | $49.95              |                                                               |
| Anker 4-Port USB 3.0 Ultra Slim                  | 1        | $9.99               |                                                               |
| RAVPower 23000mAh Power Bank                     | 1        | $60                 | Used on Amazon                                                |
| ABS Plastic 12'' x 12'' x 0.125''                | 2        | $9.85               |                                                               |
| M3 Male Female Standoff Screw Nut Assortment Kit | 2        | $9.79               |                                                               |
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
