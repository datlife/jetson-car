Jetson Autonomous RC Car
========================
Autonomous RC Car using ROS and Keras/TensorFlow. Inspired by JetsonHacks

![alt tag](https://github.com/dat-ai/jetson-car/raw/master/docs/img/jetson-car.jpg)

### Goals:
----------
* Get hands-on experience on autonomous vehicle development.
* Understand Deep Learning concepts.
* For Fun ( I probably end up taking the car to some autonomous racing competition. We'll see).

### Dependencies:
-----------------
#### Hardwares:
1. RC Car - RedCat Volcano EPX (stock - no mod) + Extra battery
2. NVIDIA Jetson TK1
3. Teensy 3.2
3. Intel RealSense R200
4. Intel Network 7260
5. Ultrasonic Sensor

#### Softwares:

1. Stock OS for Jetson TK1 (JetPack 21.5)
2. Grinch Kernel 21.4
3. ROS Indingo for ARM
4. Keras using TensorFlow as backend


### Installation Guide:
----------------------
 
#### Software Setup

JetsonHacks provides many helpful scripts to automate the process. I will avoid to reproduce his wonderful works.

 1. Install [JetPack 21.5](https://developer.nvidia.com/embedded/jetpack) (Ubuntu + CUDA 6.5 + cuDNN v2 + OpenCV4Tegra)
 2. Install [postFlash](https://github.com/jetsonhacks/postFlash) (Enabled USB 3.0, some helpful tools for development) 
 3. Install [grinch Kernel](http://www.jetsonhacks.com/2015/05/26/install-grinch-kernel-for-l4t-21-3-on-nvidia-jetson-tk1) (allow to have more driver options)
 4. Install [ROS Indigo & Teensy Driver for Jetson TK1](https://raw.githubusercontent.com/dat-ai/jetson-car/master/setup/tk1_ros_setup.sh) - Run this script on TK1
 5. 
 
#### Hardware Setup



### Author(s):
--------------
* [**Dat Nguyen**](https://github.com/dat-ai)
* I am very happy if anyone would like to work with me on this project. please shoot me an email at tdat.nguyen93@gmail.com

### Acknowledgements:
---------------------
* [JetsonHacks](http://www.jetsonhacks.com/) website provides helpful tips and tricks to work with Jetson TK1. JetsonHacks nicely simplifies the installation process with many ready-to-use scripts
* [DuckieTown](http://duckietown.mit.edu), an MIT Course,  is a great place to learn about developing autonomous vehicles.
* UPenn F1/10 Tutorials give a nice introduction to ROS, Hardware installation, and System Architecture for RC Car.

### TODO:
* Create an interface to switch between autonomous/maunual mode. (could it be semi-autonomous? like level 2/3)
* Apply the advantage of Intel Realsense (IR camera) to better reconigze objects.

