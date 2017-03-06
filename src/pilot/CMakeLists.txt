cmake_minimum_required(VERSION 2.8.3)
project(pilot)

find_package(catkin REQUIRED COMPONENTS
  joy
  roscpp
  rospy
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pilot
#  CATKIN_DEPENDS joy roscpp rospy
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

#############
## Install ##
#############


#############
## Testing ##
#############

