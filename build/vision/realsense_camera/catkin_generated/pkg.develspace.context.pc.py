# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "/home/nvidia/jetson-car/devel/include;/home/nvidia/jetson-car/src/vision/realsense_camera/include".split(';') if "/home/nvidia/jetson-car/devel/include;/home/nvidia/jetson-car/src/vision/realsense_camera/include" != "" else []
PROJECT_CATKIN_DEPENDS = "std_msgs;message_runtime;sensor_msgs;librealsense".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lrealsense_camera_nodelet".split(';') if "-lrealsense_camera_nodelet" != "" else []
PROJECT_NAME = "realsense_camera"
PROJECT_SPACE_DIR = "/home/nvidia/jetson-car/devel"
PROJECT_VERSION = "1.8.0"
