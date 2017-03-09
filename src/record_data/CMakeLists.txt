cmake_minimum_required(VERSION 2.8.3)
project(record_data)

find_package(catkin REQUIRED COMPONENTS
  rospy
  usb_cam
  rc_car_msgs
  std_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES record_data
   CATKIN_DEPENDS rospy rc_car_msgs std_msgs usb_cam
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

catkin_install_python(PROGRAMS 
        recorder.py
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)



## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_record_data.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
