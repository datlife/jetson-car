'''
Data Generator for /carRecorder message
'''

import cv2
import pickle
import argparse
import numpy as np
import pandas as pd

FILENAME = 'data.p'

df = pd.read_csv('data.csv')
steering_angles = df['steer'].as_matrix()
throttles = df['throttle'].as_matrix()
images    = df['data']
width, height = df['width'].loc[0], df['height'].loc[0]

features = []
labels = (steering_angles, throttles)
for image in images:
    # The image data from ROS bag is formatted in String ('[1, 2, 3.., n]')
    # So I cropped the '[' and ']'
    img_str = image[1:-2]
    # to use fromstring and convert into np.array
    np_img = np.fromstring(img_str, dtype=np.uint8, sep=',')
    # Reshape to original image
    img = np.reshape(np_img, newshape=(height, width, -1))
    features.append(img)


pickle.dump({'features': features, 'labels': labels}, open(FILENAME, 'wb'), protocol=2)
