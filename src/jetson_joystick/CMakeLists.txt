cmake_minimum_required(VERSION 2.8.3)
project(jetson_joystick)

find_package(catkin REQUIRED COMPONENTS
  rc_car_msgs
  joy
  roscpp
)


################################################
## Declare ROS dynamic reconfigure parameters ##
################################################


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES jetson_joystick
   CATKIN_DEPENDS rc_car_msgs joy roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)
## Declare a C++ executable
add_executable(jetson_joystick_node src/jetson_joystick_node.cpp)
add_dependencies(jetson_joystick_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(jetson_joystick_node ${catkin_LIBRARIES})


#############
## Install ##
#############


#############
## Testing ##
#############

