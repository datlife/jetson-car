import cv2
import os
import pandas as pd
import numpy as np
from image_processor import random_transform
from scipy.misc import imresize
# # git+https://github.com/uqfoundation/pathos.git@master
# http://stackoverflow.com/questions/1816958/cant-pickle-type-instancemethod-when-using-pythons-multiprocessing-pool-ma


class DataSet(object):
    ######################################
    # Process data from CSV(s) into
    # Training, Validation data set
    # =============================
    ######################################
    CSV_HEADER = ['RGB Image','Depth Image', 'Steering Angle', 'Throttle']

    def __init__(self, log_path, img_dir_path, sequence=10):
        self.df = pd.read_csv(log_path, names=self.CSV_HEADER, index_col=False)
        self.img_path = img_dir_path
        self.sequence_len = sequence
        self.X_train = []
        self.y_train = []

    def build_train_data(self):
        """
        :return:
        """
        print('Loading training data...')
        images = []
        measurements = []
        for i in range(1, len(self.df)): # 1 to except the title
            for image in ['RGB Image']:
                img_file = self.df.loc[i][image].rsplit('/')[-1]  # Extract image file only
		img = cv2.imread(os.path.join(self.img_path, img_file))
                img = imresize(img, 0.5)
                images.append(img)
                measurements.append((float(self.df.loc[i]['Steering Angle']),float(self.df.loc[i]['Throttle'])))

        self.y_train = measurements
        self.X_train = images
        #
        print("Data loaded.")
        self.X_train = np.asarray(self.X_train)
        print("Input shape: ", np.shape(self.X_train))
        print("Label shape: ", np.shape(self.y_train))
        return self.X_train, self.y_train

    def get_data(self):
        return self.X_train, self.y_train
