//
// Created by nvidia on 4/4/17.
//
#include <autopilot.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/Image.h>
#include <rc_car_msgs/CarController.h>

Pilot::Pilot(){

}

void Pilot::joyCallback(const sensor_msgs::Joy::ConstPtr& joy){

}

void Pilot::visionCallback(const sensor_msgs::Image::ConstPtr& image){

}
