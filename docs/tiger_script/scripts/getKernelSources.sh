#!/bin/bash
apt-add-repository universe
apt-get update
apt-get install qt5-default pkg-config -y
cd /usr/src
wget http://developer.download.nvidia.com/embedded/L4T/r27_Release_v1.0/BSP/r27.1.0_sources.tbz2
tar -xvf r27.1.0_sources.tbz2 kernel_src.tbz2
tar -xvf kernel_src.tbz2
cd kernel/kernel-4.4
zcat /proc/config.gz > .config
# make xconfig

