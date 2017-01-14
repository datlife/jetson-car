# Fix error with TF and Keras
import tensorflow as tf
tf.python.control_flow_ops = tf

# PARAMETERS
FRAME_SIZE  = (32, 32, 3)
DROP_OUT    = 0.6
POOL_SIZE   = (2, 2)
KERNEL_SIZE = (3, 3)

# BUILD AUTO-PILOT MODEL
input_frame = Input(shape=FRAME_SIZE, name="curr_frame")
input_angle = Input(shape=(1,), name="steering_angle")
input_throttle = Input(shape=(1,), name="throttle")
