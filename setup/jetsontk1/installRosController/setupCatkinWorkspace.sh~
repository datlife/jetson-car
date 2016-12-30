#!/bin/sh
# Create a Catkin Workspace and setup ROS environment variables
# Usage setupCatkinWorkspace.sh dirName
DEFAULTDIR=~/catkin_ws
CLDIR="$1"
if [ ! -z "$CLDIR" ]; then 
 DEFAULTDIR=~/"$CLDIR"
fi
if [ -e "$DEFAULTDIR" ] ; then
  echo "$DEFAULTDIR already exists; no action taken" 
  exit 1
else 
  echo "Creating Catkin Workspace: $DEFAULTDIR"
fi
echo "$DEFAULTDIR"/src
mkdir -p "$DEFAULTDIR"/src
cd "$DEFAULTDIR"/src
catkin_init_workspace
cd "$DEFAULTDIR"
catkin_make


#setup ROS environment variables
grep -q -F ' ROS_MASTER_URI' ~/.bashrc ||  echo 'export ROS_MASTER_URI=http://localhost:11311' | tee -a ~/.bashrc
grep -q -F ' ROS_IP' ~/.bashrc ||  echo "export ROS_IP=$(hostname -I)" | tee -a ~/.bashrc
echo "export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH" >> ~/.bashrc


