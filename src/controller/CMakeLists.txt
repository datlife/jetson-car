cmake_minimum_required(VERSION 2.8.3)
project(controller)

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
add_executable(controller_node src/joystick_node.cpp)
add_dependencies(controller_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(controller_node ${catkin_LIBRARIES})

#############
## Install ##
#############

#############
## Testing ##
#############

