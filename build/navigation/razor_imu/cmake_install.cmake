# Install script for directory: /home/nvidia/jetson-car/src/navigation/razor_imu

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/nvidia/jetson-car/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/razor_imu_9dof" TYPE FILE FILES "/home/nvidia/jetson-car/devel/include/razor_imu_9dof/imuConfig.h")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/razor_imu_9dof" TYPE FILE FILES "/home/nvidia/jetson-car/devel/lib/python2.7/dist-packages/razor_imu_9dof/__init__.py")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/nvidia/jetson-car/devel/lib/python2.7/dist-packages/razor_imu_9dof/cfg")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/razor_imu_9dof" TYPE DIRECTORY FILES "/home/nvidia/jetson-car/devel/lib/python2.7/dist-packages/razor_imu_9dof/cfg")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/nvidia/jetson-car/build/navigation/razor_imu/catkin_generated/installspace/razor_imu_9dof.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof/cmake" TYPE FILE FILES
    "/home/nvidia/jetson-car/build/navigation/razor_imu/catkin_generated/installspace/razor_imu_9dofConfig.cmake"
    "/home/nvidia/jetson-car/build/navigation/razor_imu/catkin_generated/installspace/razor_imu_9dofConfig-version.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof" TYPE FILE FILES "/home/nvidia/jetson-car/src/navigation/razor_imu/package.xml")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof" TYPE DIRECTORY FILES "/home/nvidia/jetson-car/src/navigation/razor_imu/launch")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof" TYPE DIRECTORY FILES "/home/nvidia/jetson-car/src/navigation/razor_imu/config")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof" TYPE DIRECTORY FILES "/home/nvidia/jetson-car/src/navigation/razor_imu/cfg")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof" TYPE DIRECTORY FILES "/home/nvidia/jetson-car/src/navigation/razor_imu/src")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof" TYPE DIRECTORY FILES "/home/nvidia/jetson-car/src/navigation/razor_imu/magnetometer_calibration")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof/nodes" TYPE PROGRAM FILES "/home/nvidia/jetson-car/build/navigation/razor_imu/catkin_generated/installspace/imu_node.py")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/razor_imu_9dof/nodes" TYPE PROGRAM FILES "/home/nvidia/jetson-car/build/navigation/razor_imu/catkin_generated/installspace/display_3D_visualization.py")
endif()

