; Auto-generated. Do not edit!


(cl:in-package rc_car_msgs-msg)


;//! \htmlinclude CarController.msg.html

(cl:defclass <CarController> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (throttle
    :reader throttle
    :initarg :throttle
    :type cl:float
    :initform 0.0)
   (steer
    :reader steer
    :initarg :steer
    :type cl:float
    :initform 0.0))
)

(cl:defclass CarController (<CarController>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CarController>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CarController)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rc_car_msgs-msg:<CarController> is deprecated: use rc_car_msgs-msg:CarController instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <CarController>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rc_car_msgs-msg:header-val is deprecated.  Use rc_car_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <CarController>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rc_car_msgs-msg:throttle-val is deprecated.  Use rc_car_msgs-msg:throttle instead.")
  (throttle m))

(cl:ensure-generic-function 'steer-val :lambda-list '(m))
(cl:defmethod steer-val ((m <CarController>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rc_car_msgs-msg:steer-val is deprecated.  Use rc_car_msgs-msg:steer instead.")
  (steer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CarController>) ostream)
  "Serializes a message object of type '<CarController>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'throttle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'steer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CarController>) istream)
  "Deserializes a message object of type '<CarController>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'throttle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'steer) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CarController>)))
  "Returns string type for a message object of type '<CarController>"
  "rc_car_msgs/CarController")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CarController)))
  "Returns string type for a message object of type 'CarController"
  "rc_car_msgs/CarController")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CarController>)))
  "Returns md5sum for a message object of type '<CarController>"
  "fde3dbdce53ea8efc0e0dd6ef6da3ed4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CarController)))
  "Returns md5sum for a message object of type 'CarController"
  "fde3dbdce53ea8efc0e0dd6ef6da3ed4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CarController>)))
  "Returns full string definition for message of type '<CarController>"
  (cl:format cl:nil "Header  header~%float32 throttle~%float32 steer~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CarController)))
  "Returns full string definition for message of type 'CarController"
  (cl:format cl:nil "Header  header~%float32 throttle~%float32 steer~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CarController>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CarController>))
  "Converts a ROS message object to a list"
  (cl:list 'CarController
    (cl:cons ':header (header msg))
    (cl:cons ':throttle (throttle msg))
    (cl:cons ':steer (steer msg))
))
