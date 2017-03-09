#!/usr/bin/env python
'''
This script is used to start/stop record rosbag using Joy ROS message
'''
import rospy
import roslib
import subprocess
import os 
import signal
from sensor_msgs.msg import Joy

DEFAULT_LOCATION = "/home/ubuntu/bag/"

def callback(joy):
    global recording, start_rosbag
    if joy.buttons[1] == 1:
        if recording is False:
	    recording = True
	    start_rosbag = subprocess.Popen('roslaunch record_data recorder.launch', stdin=subprocess.PIPE, shell=True)
   	    print("\n\nRosbag Recorder started...")
        else:
	    print("\nRecorder has been activated already..\n")

    if joy.buttons[0] == 1:
	if recording is True:
	    recording = False
	    terminate_process_and_children(start_rosbag)
	    print("\n\nRosbag Recorder stopped...")
        else:
	    print("\nRecorder is not activated yet...Press A to start record")

def terminate_process_and_children(p):
    ps_command = subprocess.Popen("ps -o pid --ppid %d --noheaders" % p.pid, shell=True, stdout=subprocess.PIPE)
    ps_output = ps_command.stdout.read()
    retcode = ps_command.wait()
    assert retcode == 0, "ps command returned %d" % retcode
    for pid_str in ps_output.split("\n")[:-1]:
            os.kill(int(pid_str), signal.SIGINT)
    p.terminate()

def start():
   rospy.init_node("recorder_controller", anonymous=True)
   joy_listener = rospy.Subscriber("joy", Joy, callback)
   rospy.spin()

if __name__ == "__main__":
   recording = False
   start()

