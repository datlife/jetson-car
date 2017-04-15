#!/bin/bash
# Copy Driving Log to host computer for computing
scp -r driving_log.csv imgs depth_imgs datinfo@10.42.0.164:/home/datinfo/bag
