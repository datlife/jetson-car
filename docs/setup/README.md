How to Set Up Jetson Car
========================

This README will walk through how to set up Jetson Car.



Hardware / Bill Of Materials
----------------------------


#### Base 

| **Item**                                         | **Unit** | **Price** | **Notes**                                                     |
|--------------------------------------------------|----------|---------------------|---------------------------------------------------------------|
| RedCat Volcano EPX Brushed                       | 1        | $139.99             |                                           |
| NVIDIA Jetson TX2                                | 1        | $599.99             | If you are a student, you can apply for EDU discount. |
| Teensy 3.2                                       | 1        | $29.95              |                                      |
| Logitech GamePad F710 Wireless Controller        | 1        | $30.99               |                                      |
| RAVPower 23000mAh Power Bank                     | 1        | $60                 | Used on Amazon                                   |

#### Sensors

| **Item**                                         | **Unit** | **Price** | **Notes**                                                     |
|--------------------------------------------------|----------|---------------------|---------------------------------------------------------------|
| Intel RealSense R200                             | 1        | $109.00             |                                                               |
| Logitech C920 USB Webcam                         | 1        | $61.50              | H264 encoded MJPEG                                            |
| Sparkfun Razor IMU 9DoF M0                         | 1        | $49.95              |                                                               |
| UBLOX GPS NEO-6m                  | 1        | $19.99               |                                                               |            
#### Accessories

| **Item**                                         | **Unit** | **Price** | **Notes**                                                     |
|--------------------------------------------------|----------|---------------------|---------------------------------------------------------------|
| ABS Plastic 12'' x 12'' x 0.125''                | 2        | $9.85               | To cut the base                                                              |
| M3 Male Female Standoff Screw Nut Assortment Kit | 2        | $9.79               |                            



Software
--------

| Software                | Version              |
|-------------------------|----------------------|
| Stock OS for Jetson TX2 | JetPack 3.0 (27.0.1) |
| ROS Kinetic for ARM     | kinetic-ros-bare     |
| Keras                   | 2.0.2                |
| TensorFlow              | 1.0.1                |





Installation Steps
------------------

#### 1. Build Custom Kernel Modules
----------------------------------

The purpose is to allow NVIDIA Jetson detect additional image formats from Stereo Camera Intel Realsense, Teensy and IMU driver correctly.


> **The kernel** is the code that is the base of the operating system, the interface between hardware and the application code.

> **A kernel module** is code that can be accessed from the kernel on demand, without having to modify the kernel. These modules provide ancillary support for different types of devices and subsystems.
- [jetsonhacks](http://www.jetsonhacks.com/2017/03/26/intel-realsense-camera-installation-nvidia-jetson-tx2/),
----

Follow instruction from JetsonHacks to create custom Kernel Modules for NVIDIA Jetson
http://www.jetsonhacks.com/2017/03/25/build-kernel-and-modules-nvidia-jetson-tx2/



**1.a. What the scripts do:**
* Download and extract Kernel Source
* Build Kernel Source
* Copy Kernel to /boot


**1.b. What do you need to to?**
* Create a custom kernel name (e.g `4.4.0-jetson-car-1.0`) in
* Press `Ctrl F` to enable the following two Modules.
* Enable `USB CH341` chipset
* Enable `USB CDC ACM SUPPORT` to allow detect Teensy and IMU Driver
* Enable `JOYDEV` AND `CONFIG_INPUT_JOYSTICK` to allow Joystick deteceted

#### 2. Install ROS Kinetic

* Execute [`scripts/1_installRos.sh`](https://github.com/dat-ai/jetson-car/blob/master/setup/scripts/1_installRos.sh) and [`scripts/2_installDependencies.sh`](https://github.com/dat-ai/jetson-car/blob/master/setup/scripts/2_installDependencies.sh) to run automatically.
```
# Make sure you are in `setup` directorty
cd ./setup

sudo ./scripts/1_installRos.sh
sudo ./scripts/2_installDependencies.sh
```

#### 3. Install Realsense Library
--------------------------------
http://www.jetsonhacks.com/2017/03/26/intel-realsense-camera-installation-nvidia-jetson-tx2/


* Install librealsense
* Update kernel module to detect realsense format
* Build new Kernel Module with patched from Intelcd 

####  4. Install Intel Realsense ROS Package
http://www.jetsonhacks.com/2017/03/29/intel-realsense-package-for-ros-on-nvidia-jetson-tx2/

####  5. Build catkinw_ws workspace
-------------------------------

```
cd jetson-car/src/
catkin_init_make
cd ..
catkin_make
```
