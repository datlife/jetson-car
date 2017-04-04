cmake_minimum_required(VERSION 2.8.3)
project(perception)

find_package(catkin REQUIRED COMPONENTS
  rc_car_msgs
  joy
  roscpp
)
################################################
## Declare ROS dynamic reconfigure parameters ##
################################################
catkin_package(CATKIN_DEPENDS rc_car_msgs joy roscpp)
###########
## Build ##
###########
include_directories(${catkin_INCLUDE_DIRS})
## Declare a C++ executable
add_executable(perception_node src/joystick_node.cpp)
add_dependencies(perception_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(perception_node ${catkin_LIBRARIES})

#############
## Install ##
#############

#############
## Testing ##
#############

