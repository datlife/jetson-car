# This script describes how to build the model architecture for this project.
# This script is re-used some codes from object DatNet in DatNet.py
# Import necessary Keras methods to use in this file
from keras.models import Model
from keras.layers import Convolution2D, Dense, Dropout, BatchNormalization, AveragePooling2D
from keras.layers import Input, Flatten, merge, Lambda, Activation
from keras.optimizers import Adam
from keras.objectives import mean_squared_error
from keras.regularizers import l2


# Data processors
import numpy as np
import cv2

from FLAGS import *


def build_model(input_shape, layer1_params=(5, 32, 2), res_layers_params=(3, 16, 3),
                init='he_uniform', reg=0.01):
    '''
    Return a ResNet Pre-Activation Model. An Implementation of He et al in this paper:
    https://arxiv.org/pdf/1603.05027.pdf
    '''
    #  Filter Config.
    # ##################################################################################
    sz_L1_filters, nb_L1_filters, stride_L1 = layer1_params
    sz_res_filters, nb_res_filters, nb_res_stages = res_layers_params
    sz_pool_fin = (input_shape[0]) / stride_L1

    #  INPUT LAYERS
    # ###################################################################################
    frame = Input(shape=(HEIGHT, WIDTH, CHANNELS), name='cifar')
    # speed = Input(batch_shape=(BATCH_SIZE, TIME_STEPS, 1), name='curr_speed')
    # brake = Input(batch_shape=(BATCH_SIZE, TIME_STEPS, 1), name='curr_brake')
    # throttle = Input(batch_shape=(BATCH_SIZE, TIME_STEPS, 1), name='curr_throttle')

    # VISION MODEL - USING CNN
    # ####################################################################################
    x = Lambda(lambda image: image/255.0 - 0.5, input_shape=(HEIGHT, WIDTH, CHANNELS))(frame)
    # x = Cropping2D(cropping=((30, 5), (1, 1)))(x)
    x = Convolution2D(nb_L1_filters, sz_L1_filters, sz_L1_filters, border_mode='same', subsample=(stride_L1, stride_L1),
                      init=init, W_regularizer=l2(reg), bias=False, name='conv0')(x)
    x = BatchNormalization(axis=1, name='bn0', mode=2)(x)
    x = Activation('relu', name='relu0')(x)
    x = Dropout(KEEP_PROP)(x)

    # Bottle Neck Layers
    for stage in range(1, nb_res_stages + 1):
        x = _bottleneck_layer(x, (nb_L1_filters, nb_res_filters), sz_res_filters, stage, init=init, reg=reg)

    x = BatchNormalization(axis=1, name='bnF', mode=2)(x)
    x = Activation('relu', name='reluF')(x)
    x = Dropout(KEEP_PROP)(x)
    x = AveragePooling2D((sz_pool_fin, sz_pool_fin), name='avg_pool')(x)
    x = Flatten(name='flat')(x)

    x = Dense(1024, name='fc1', activation='relu')(x)
    x = Dropout(0.5)(x)
    x = Dense(512, name='fc2', activation='relu')(x)
    x = Dropout(0.5)(x)
    x = Dense(256, name='fc3', activation='relu')(x)
    x = Dropout(0.5)(x)
    x = Dense(OUTPUT_DIM, name='output_1')(x)

    model = Model(input=frame, output=x)
    model.summary()
    return model


def _bottleneck_layer(input_tensor, nb_filters, filter_sz, stage,
                      init='glorot_normal', reg=0.0, use_shortcuts=True):
    '''
    :param input_tensor:
    :param nb_filters:   number of filters in Conv2D
    :param filter_sz:    filter size for Conv2D
    :param stage:        current position of the block (used a loop when get called)
    :param init:         initialization type
    :param reg:          regularization type
    :param use_shortcuts:
    :return:
    '''
    nb_in_filters, nb_bottleneck_filters = nb_filters

    bn_name = 'bn' + str(stage)
    conv_name = 'conv' + str(stage)
    relu_name = 'relu' + str(stage)
    merge_name = '+' + str(stage)

    # batch-norm-relu-conv, from nb_in_filters to nb_bottleneck_filters via 1x1 conv
    if stage > 1:  # first activation is just after conv1
        x = BatchNormalization(axis=1, name=bn_name + 'a', mode=2)(input_tensor)
        x = Activation('relu', name=relu_name + 'a')(x)
        x = Dropout(KEEP_PROP)(x)
    else:
        x = input_tensor

    x = Convolution2D(nb_bottleneck_filters, 1, 1,
                      init=init, W_regularizer=l2(reg), border_mode='valid',
                      bias=False, name=conv_name + 'a')(x)

    # batch-norm-relu-conv, from nb_bottleneck_filters to nb_bottleneck_filters via FxF conv
    x = BatchNormalization(axis=1, name=bn_name + 'b', mode=2)(x)
    x = Activation('relu', name=relu_name + 'b')(x)
    x = Convolution2D(nb_bottleneck_filters, filter_sz, filter_sz, border_mode='same',
                      init=init, W_regularizer=l2(reg), bias=False, name=conv_name + 'b')(x)

    # batch-norm-relu-conv, from nb_in_filters to nb_bottleneck_filters via 1x1 conv
    x = BatchNormalization(axis=1, name=bn_name + 'c', mode=2)(x)
    x = Activation('relu', name=relu_name + 'c')(x)
    x = Dropout(KEEP_PROP)(x)

    x = Convolution2D(nb_in_filters, 1, 1,
                      init=init, W_regularizer=l2(reg),
                      name=conv_name + 'c')(x)
    # merge
    if use_shortcuts:
        x = merge([x, input_tensor], mode='sum', name=merge_name)

    return x

def main(pre_trained_weight_path=None, input_shape=None):
    # Build new model
    # Determine the shape of input
    if input_shape is not None:
        shape = input_shape
    else:
        shape = (HEIGHT, WIDTH, CHANNELS)

    # Build model
    model = build_model(input_shape=shape, res_layers_params=(3, 32, 4))

    # Determine if pre-trained model is specified
    if pre_trained_weight_path is not None:
        model.load_weights(pre_trained_weight_path, by_name=True)
        print("Pre-trained model is successfully loaded...")

    # Save model architecture into a json file
    json_str = model.to_json()
    with open('cnn.json', 'w') as outfile:
        outfile.write(json_str)
        print('Model saved')

if __name__ == "__main__":

    main(pre_trained_weight_path='./cnn.h5')
