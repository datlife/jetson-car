# Image Size
HEIGHT = 46
WIDTH = 160
CHANNELS = 3
# output dimension from RNN
OUTPUT_DIM = 3

# RNN SIZE
HIDDEN_UNITS = 32
STEER_CORRECTION = 0.2

# HYPER-PARAMETER
LEARN_RATE = 0.0001
KEEP_PROP = 0.3
EPOCHS = 5
BATCH_SIZE = 2    # Be careful, stateful RNN requires to state batch size ahead
TIME_STEPS = 10  # For RNN
INIT = 'he_uniform'

# INPUT
DRIVING_LOG = './data/driving_log.csv'
IMG_DIR = './data/IMG'

# CROP FACTOR - remove top and bottom of images
TOP = 70
BOTTOM = 20
