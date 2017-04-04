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


def callback(joy):
    global autonomous, activate_pilot

    # RIGHT TOP - BIG BUTTON
    if joy.buttons[7] == 1:
        if autonomous is False:
            autonomous = True
            activate_pilot = subprocess.Popen('roslaunch perception autopilot.launch', stdin=subprocess.PIPE, shell=True)
            print("\n\nStarting Autonomous Mode.")
        else:
            print("\nAutonomous has been activated already..\n")

    # RIGHT TOP - SMALL BUTTON
    if joy.buttons[5] == 1:
        if autonomous is True:
            autonomous = False
            terminate_process_and_children(activate_pilot)
            print("\n\nTurning off Autonomous...")
        else:
            print("\nAutopilot is not activated yet... Press RightTop button to activate.")

def terminate_process_and_children(p):
    ps_command = subprocess.Popen("ps -o pid --ppid %d --noheaders" % p.pid, shell=True, stdout=subprocess.PIPE)
    ps_output = ps_command.stdout.read()
    retcode = ps_command.wait()
    assert retcode == 0, "ps command returned %d" % retcode
    for pid_str in ps_output.split("\n")[:-1]:
            os.kill(int(pid_str), signal.SIGINT)
    p.terminate()

def start():
   rospy.init_node("autonomous_controller", anonymous=True)
   joy_listener = rospy.Subscriber("joy", Joy, callback)
   rospy.spin()

if __name__ == "__main__":
   autonomous = False
   start()

