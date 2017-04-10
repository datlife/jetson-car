; Auto-generated. Do not edit!


(cl:in-package rc_car_msgs-msg)


;//! \htmlinclude CarRecorder.msg.html

(cl:defclass <CarRecorder> (roslisp-msg-protocol:ros-message)
  ((img_path
    :reader img_path
    :initarg :img_path
    :type cl:string
    :initform "")
   (steer
    :reader steer
    :initarg :steer
    :type cl:float
    :initform 0.0)
   (throttle
    :reader throttle
    :initarg :throttle
    :type cl:float
    :initform 0.0)
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0))
)

(cl:defclass CarRecorder (<CarRecorder>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CarRecorder>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CarRecorder)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rc_car_msgs-msg:<CarRecorder> is deprecated: use rc_car_msgs-msg:CarRecorder instead.")))

(cl:ensure-generic-function 'img_path-val :lambda-list '(m))
(cl:defmethod img_path-val ((m <CarRecorder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rc_car_msgs-msg:img_path-val is deprecated.  Use rc_car_msgs-msg:img_path instead.")
  (img_path m))

(cl:ensure-generic-function 'steer-val :lambda-list '(m))
(cl:defmethod steer-val ((m <CarRecorder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rc_car_msgs-msg:steer-val is deprecated.  Use rc_car_msgs-msg:steer instead.")
  (steer m))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <CarRecorder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rc_car_msgs-msg:throttle-val is deprecated.  Use rc_car_msgs-msg:throttle instead.")
  (throttle m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <CarRecorder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rc_car_msgs-msg:velocity-val is deprecated.  Use rc_car_msgs-msg:velocity instead.")
  (velocity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CarRecorder>) ostream)
  "Serializes a message object of type '<CarRecorder>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'img_path))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'img_path))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'steer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'throttle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CarRecorder>) istream)
  "Deserializes a message object of type '<CarRecorder>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'img_path) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'img_path) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'steer) (roslisp-utils:decode-single-float-bits bits)))
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
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CarRecorder>)))
  "Returns string type for a message object of type '<CarRecorder>"
  "rc_car_msgs/CarRecorder")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CarRecorder)))
  "Returns string type for a message object of type 'CarRecorder"
  "rc_car_msgs/CarRecorder")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CarRecorder>)))
  "Returns md5sum for a message object of type '<CarRecorder>"
  "7ff232c3ef1ac97d91355af7dc5015af")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CarRecorder)))
  "Returns md5sum for a message object of type 'CarRecorder"
  "7ff232c3ef1ac97d91355af7dc5015af")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CarRecorder>)))
  "Returns full string definition for message of type '<CarRecorder>"
  (cl:format cl:nil "string   img_path~%float32  steer~%float32  throttle~%float32  velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CarRecorder)))
  "Returns full string definition for message of type 'CarRecorder"
  (cl:format cl:nil "string   img_path~%float32  steer~%float32  throttle~%float32  velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CarRecorder>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'img_path))
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CarRecorder>))
  "Converts a ROS message object to a list"
  (cl:list 'CarRecorder
    (cl:cons ':img_path (img_path msg))
    (cl:cons ':steer (steer msg))
    (cl:cons ':throttle (throttle msg))
    (cl:cons ':velocity (velocity msg))
))
