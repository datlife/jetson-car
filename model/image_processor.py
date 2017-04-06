import cv2
import numpy as np


def random_transform(img):
    # There are total of 6 transformation
    # I will create an boolean array of 6 elements [ 0 or 1]
    a = np.random.randint(0, 2, [1, 5]).astype('bool')[0]
    flip_angle = 1
    if a[1] == 1:
        img = rotate(img)
    # if a[2] == 1:
    #     img = flip(img)
    #     flip_angle = -1  # to swap the steering angle
    if a[3] == 1:
        img = blur(img)
    if a[4] == 1:
        img = gamma(img)
    return img, flip_angle


def rotate(img):
    row, col, channel = img.shape
    angle = np.random.uniform(-15, 15)
    rotation_point = (row / 2, col / 2)
    rotation_matrix = cv2.getRotationMatrix2D(rotation_point, angle, 1)
    rotated_img = cv2.warpAffine(img, rotation_matrix, (col, row))
    return rotated_img


def gamma(img):
    gamma = np.random.uniform(0.5, 1.2)
    invGamma = 1.0 / gamma
    table = np.array([((i / 255.0) ** invGamma) * 255 for i in np.arange(0, 256)]).astype("uint8")
    new_img = cv2.LUT(img, table)
    return new_img


def blur(img):
    r_int = np.random.randint(0, 2)
    odd_size = 2 * r_int + 1
    return cv2.GaussianBlur(img, (odd_size, odd_size), 0)


def flip(img):
    return cv2.flip(img, 1)



