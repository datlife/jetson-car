# Image Size
HEIGHT = 46 # sky is removed .. in train.py
WIDTH = 160
CHANNELS = 3
# Cropping factor
CROP_TOP = 30
CROP_BOTTOM = 5
# output dimension from RNN
OUTPUT_DIM = 3  # Steer, throttle, velocity
# RNN SIZE
HIDDEN_UNITS = 64
STEER_CORRECTION = 0.2
# HYPER-PARAMETER
LOAD_WEIGHT = True
LEARN_RATE = 0.001
KEEP_PROP = 0.4
EPOCHS = 1
BATCH_SIZE = 4     # Be careful, stateful RNN requires to state batch size ahead
TIME_STEPS = 10    # For RNN
INIT = 'he_uniform'



