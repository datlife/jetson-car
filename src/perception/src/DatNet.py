# TF 0.8 requires to Modify KERAS tensorflow_backend

from keras.layers import Activation, BatchNormalization
from keras.layers import AveragePooling2D

from keras.layers import Input, Convolution2D, Dense, Dropout, Flatten, merge, Lambda
from keras.layers.convolutional import Cropping2D
from keras.layers import TimeDistributed, GRU, Embedding
from keras.models import Model
from keras.regularizers import l2
from keras.objectives import mean_squared_error
from FLAGS import *
import numpy as np


class DatNet(object):

    def __init__(self, input_shape=(HEIGHT, WIDTH, CHANNELS), nb_classes=10,
                 layer1_params=(5, 32, 2),
                 res_layer_params=(3, 16, 3),
                 init='glorot_normal', reg=0.0, use_shortcuts=True):

        self.vision_model = self.build(input_shape=input_shape, nb_classes=nb_classes,
                                        layer1_params=layer1_params, res_layer_params=res_layer_params,
                                        init=init, reg=reg, use_shortcuts=use_shortcuts)

    def _bottleneck_layer(self, input_tensor, nb_filters, filter_sz, stage,
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
        else:
            x = input_tensor

        x = Convolution2D(nb_bottleneck_filters, 1, 1, init=init, W_regularizer=l2(reg),
                          bias=False, name=conv_name + 'a')(x)
        # batch-norm-relu-conv, from nb_bottleneck_filters to nb_bottleneck_filters via FxF conv
        x = BatchNormalization(axis=1, name=bn_name + 'b', mode=2)(x)
        x = Activation('relu', name=relu_name + 'b')(x)
        x = Convolution2D(nb_bottleneck_filters, filter_sz, filter_sz, border_mode='same',
                          init=init, W_regularizer=l2(reg), bias=False, name=conv_name + 'b')(x)

        # batch-norm-relu-conv, from nb_in_filters to nb_bottleneck_filters via 1x1 conv
        x = BatchNormalization(axis=1, name=bn_name + 'c', mode=2)(x)
        x = Activation('relu', name=relu_name + 'c')(x)
        x = Convolution2D(nb_in_filters, 1, 1, border_mode='same',  # Used to be 1x1 here, but it is slow
                          init=init, W_regularizer=l2(reg),
                          name=conv_name + 'c'
                          )(x)
        # merge
        if use_shortcuts:
            x = merge([x, input_tensor], mode='sum', name=merge_name)

        return x

    def build(self, nb_classes=10, input_shape=(HEIGHT, WIDTH, CHANNELS),
              layer1_params=(5, 32, 2), res_layer_params=(3, 16, 3),
              init='glorot_normal', reg=0.0, use_shortcuts=True):
        '''
        Return a new Residual Network using full pre-activation based on the work in
        "Identity Mappings in Deep Residual Networks"  by He et al
        http://arxiv.org/abs/1603.05027

        Parameters
        ----------
        input_shape     : tuple of (C, H, W)
        nb_classes      :  number of scores to produce from final affine layer (input to softmax)
        layer1_params   : tuple of (filter size, num filters, stride for conv)
        res_layer_params: tuple of (filter size, num res layer filters, num res stages)
        init            : type of weight initialization to use
        reg             : L2 weight regularization (or weight decay)
        use_shortcuts   : to evaluate difference between residual and non-residual network
        '''

        #  Filter Config.
        # ##################################################################################
        sz_L1_filters, nb_L1_filters, stride_L1 = layer1_params
        sz_res_filters, nb_res_filters, nb_res_stages = res_layer_params
        sz_pool_fin = (input_shape[0] - 30 - 5) / stride_L1

        #  INPUT LAYERS
        # ###################################################################################
        frame = Input(shape=(HEIGHT, WIDTH, CHANNELS), name='cifar')
        # speed = Input(batch_shape=(BATCH_SIZE, TIME_STEPS, 1), name='curr_speed')
        # brake = Input(batch_shape=(BATCH_SIZE, TIME_STEPS, 1), name='curr_brake')
        # throttle = Input(batch_shape=(BATCH_SIZE, TIME_STEPS, 1), name='curr_throttle')

        # VISION MODEL - USING CNN
        # ####################################################################################
        x = Lambda(lambda image: image/255.0 - 0.5, input_shape=(HEIGHT, WIDTH, CHANNELS))(frame)
        x = Convolution2D(nb_L1_filters, sz_L1_filters, sz_L1_filters, border_mode='same',
                          subsample=(stride_L1, stride_L1), init=init, W_regularizer=l2(reg),
                          bias=False, name='conv0')(x)
        x = BatchNormalization(axis=1, name='bn0', mode=2)(x)
        x = Activation('relu', name='relu0')(x)

        # Bottle Neck Layers
        for stage in range(1, nb_res_stages + 1):
            x = self._bottleneck_layer(x, (nb_L1_filters, nb_res_filters), sz_res_filters, stage,
                                       init=init, reg=reg, use_shortcuts=use_shortcuts)
        x = BatchNormalization(axis=1, name='bnF', mode=2)(x)
        x = Activation('relu', name='reluF')(x)
        x = AveragePooling2D((sz_pool_fin, sz_pool_fin), name='avg_pool')(x)
        x = Flatten(name='flat')(x)

        x = Dense(1024, name='fc1', activation='relu')(x)
        x = Dropout(0.5)(x)
        x = Dense(512, name='fc2', activation='relu')(x)
        x = Dropout(0.5)(x)
        x = Dense(256, name='fc3', activation='relu')(x)
        x = Dropout(0.5)(x)
        x = Dense(OUTPUT_DIM, name='output_2')(x)
        model = Model(input=frame, output=x)

        # Load weight manually
        return model

def mse_steer_angle(y_true, y_pred):
    return mean_squared_error(y_true[0], y_pred[0])


