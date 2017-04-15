from keras.models import Model
from keras.layers import Input, Lambda, Dropout, merge
from keras.layers import Activation, BatchNormalization, Flatten, Dense
from keras.layers import Convolution2D, MaxPooling2D, ZeroPadding2D, AveragePooling2D
from keras.regularizers import l2
from keras.layers.convolutional import Convolution2D, Cropping2D

from keras.layers import Input, Convolution2D, Dense, Dropout, Flatten, MaxPooling2D, merge, Lambda
from keras.layers.convolutional import Cropping2D
from keras.layers import TimeDistributed, GRU, Embedding
from keras.models import Model
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
        self.RNN  = self.build_rnn()

    def train_rnn(self, batch_generator=None, epochs=2, augmentation_scale=3):
        if batch_generator is None:
            print("Cannot open batch generator. Please try again.")
        elif self.RNN is None:
            print("RNN is not built yet.")
        else:
            print('Train...')
            for epoch in range(epochs):
                mean_tr_acc = []
                mean_tr_loss = []
                batch_len = 0
                limit = batch_generator.get_seq_size()
                print("Epoch {}: ".format(epoch + 1))
                while batch_generator.cursor < limit:
                    # Data Augmentation per patch
                    batch_x, batch_y = batch_generator.next(augmentation_scale)
                    batch_len += len(batch_x)
                    steps = len(batch_x)
                    # Iterate through batch. (BATCH, TIME STEPS, HEIGHT, WIDTH, CHANNELS)
                    # Each iteration is like a mini-batch
                    for i in range(0, steps, BATCH_SIZE):
                        x = batch_x[i:i + BATCH_SIZE]
                        y = batch_y[i:i + BATCH_SIZE]
                        # Train on batch, gradient  will flow back through batch
                        loss, acc = self.RNN.train_on_batch(x, y)
                        mean_tr_acc.append(acc)
                        mean_tr_loss.append(loss)
                        # Reset the state because my RNN is stateful
                        self.RNN.reset_states()
                    if batch_generator.cursor % 500 == 0:
                        print("Current batch: {}/{}, loss: {:7.4f} acc: {:5.2f}".format(batch_generator.cursor, limit,
                                                                                        np.mean(mean_tr_acc),
                                                                                        np.mean(mean_tr_loss)))
                print('Accuracy: {}, Loss: {}'.format(np.mean(mean_tr_acc), np.mean(mean_tr_loss)))
                print('Batches ', batch_len)
                print('_____________________________________________________________')
                batch_generator.reset_cursor()

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
            x = BatchNormalization(axis=1, name=bn_name + 'a')(input_tensor)
            x = Activation('relu', name=relu_name + 'a')(x)
            x = Dropout(KEEP_PROP)(x)
        else:
            x = input_tensor

        x = Convolution2D(nb_bottleneck_filters, 1, 1,
                          init=init, W_regularizer=l2(reg), border_mode='valid',
                          bias=False, name=conv_name + 'a')(x)
        # batch-norm-relu-conv, from nb_bottleneck_filters to nb_bottleneck_filters via FxF conv
        x = BatchNormalization(axis=1, name=bn_name + 'b')(x)
        x = Activation('relu', name=relu_name + 'b')(x)
        x = Convolution2D(nb_bottleneck_filters, filter_sz, filter_sz, border_mode='same',
                          init=init, W_regularizer=l2(reg), bias=False, name=conv_name + 'b')(x)

        # batch-norm-relu-conv, from nb_in_filters to nb_bottleneck_filters via 1x1 conv
        x = BatchNormalization(axis=1, name=bn_name + 'c')(x)
        x = Activation('relu', name=relu_name + 'c')(x)
        x = Dropout(KEEP_PROP)(x)

        x = Convolution2D(nb_in_filters, 1, 1,
                          init=init, W_regularizer=l2(reg),
                          name=conv_name + 'c'
                          )(x)
        # merge
        if use_shortcuts:
             x = merge([x, input_tensor], mode='sum', name=merge_name)
	 #   x = Add((x, input_tensor))
        return x

    def build(self, nb_classes=10, input_shape=(HEIGHT, WIDTH, CHANNELS),
              layer1_params=(5, 32, 2), res_layer_params=(3, 16, 3),
              init='glorot_normal', reg=0.01, use_shortcuts=True):
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
        x = Convolution2D(nb_L1_filters, sz_L1_filters, sz_L1_filters, border_mode='same',
                          subsample=(stride_L1, stride_L1), init=init, W_regularizer=l2(reg),
                          bias=False, name='conv0')(x)
        x = BatchNormalization(axis=1, name='bn0')(x)
        x = Activation('relu', name='relu0')(x)
        x = Dropout(KEEP_PROP)(x)
        # Bottle Neck Layers
        for stage in range(1, nb_res_stages + 1):
            x = self._bottleneck_layer(x, (nb_L1_filters, nb_res_filters), sz_res_filters, stage, init=init, reg=reg)

        x = BatchNormalization(axis=1, name='bnF')(x)
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

        # Load weight manually
        return model

    def build_rnn(self):

        frame_sequence = Input(batch_shape=(BATCH_SIZE, TIME_STEPS, HEIGHT, WIDTH, CHANNELS))
        # # RNN MODEL, STACKED ON TOP OF THE CNN
        # # ###################################################################################
        # Note: Time-Distributed Model, BatchNormalization is required to use `mode=2`
        net = TimeDistributed(self.vision_model, name='CNN_Time_Distributed')(frame_sequence)
        net = GRU(HIDDEN_UNITS, return_sequences=True, stateful=True, name='GRU2_1')(net)
        net = GRU(HIDDEN_UNITS, return_sequences=False, stateful=True, name='GRU2_2')(net)
        net = Dense(256, name='RNN_fc1', activation='relu')(net)
        net = Dense(OUTPUT_DIM, name='RNN_output')(net)
        model = Model(input=frame_sequence, output=net)

        return model

def mse_steer_angle(y_true, y_pred):
    return mean_squared_error(y_true[0], y_pred[0])


