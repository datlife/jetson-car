; Auto-generated. Do not edit!


(cl:in-package realsense_camera-srv)


;//! \htmlinclude GetIMUInfo-request.msg.html

(cl:defclass <GetIMUInfo-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass GetIMUInfo-request (<GetIMUInfo-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetIMUInfo-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetIMUInfo-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<GetIMUInfo-request> is deprecated: use realsense_camera-srv:GetIMUInfo-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetIMUInfo-request>) ostream)
  "Serializes a message object of type '<GetIMUInfo-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetIMUInfo-request>) istream)
  "Deserializes a message object of type '<GetIMUInfo-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetIMUInfo-request>)))
  "Returns string type for a service object of type '<GetIMUInfo-request>"
  "realsense_camera/GetIMUInfoRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetIMUInfo-request)))
  "Returns string type for a service object of type 'GetIMUInfo-request"
  "realsense_camera/GetIMUInfoRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetIMUInfo-request>)))
  "Returns md5sum for a message object of type '<GetIMUInfo-request>"
  "fcce7f85a63907f26a3912a7632e9630")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetIMUInfo-request)))
  "Returns md5sum for a message object of type 'GetIMUInfo-request"
  "fcce7f85a63907f26a3912a7632e9630")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetIMUInfo-request>)))
  "Returns full string definition for message of type '<GetIMUInfo-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetIMUInfo-request)))
  "Returns full string definition for message of type 'GetIMUInfo-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetIMUInfo-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetIMUInfo-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetIMUInfo-request
))
;//! \htmlinclude GetIMUInfo-response.msg.html

(cl:defclass <GetIMUInfo-response> (roslisp-msg-protocol:ros-message)
  ((accel
    :reader accel
    :initarg :accel
    :type realsense_camera-msg:IMUInfo
    :initform (cl:make-instance 'realsense_camera-msg:IMUInfo))
   (gyro
    :reader gyro
    :initarg :gyro
    :type realsense_camera-msg:IMUInfo
    :initform (cl:make-instance 'realsense_camera-msg:IMUInfo)))
)

(cl:defclass GetIMUInfo-response (<GetIMUInfo-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetIMUInfo-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetIMUInfo-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<GetIMUInfo-response> is deprecated: use realsense_camera-srv:GetIMUInfo-response instead.")))

(cl:ensure-generic-function 'accel-val :lambda-list '(m))
(cl:defmethod accel-val ((m <GetIMUInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader realsense_camera-srv:accel-val is deprecated.  Use realsense_camera-srv:accel instead.")
  (accel m))

(cl:ensure-generic-function 'gyro-val :lambda-list '(m))
(cl:defmethod gyro-val ((m <GetIMUInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader realsense_camera-srv:gyro-val is deprecated.  Use realsense_camera-srv:gyro instead.")
  (gyro m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetIMUInfo-response>) ostream)
  "Serializes a message object of type '<GetIMUInfo-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'accel) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'gyro) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetIMUInfo-response>) istream)
  "Deserializes a message object of type '<GetIMUInfo-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'accel) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'gyro) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetIMUInfo-response>)))
  "Returns string type for a service object of type '<GetIMUInfo-response>"
  "realsense_camera/GetIMUInfoResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetIMUInfo-response)))
  "Returns string type for a service object of type 'GetIMUInfo-response"
  "realsense_camera/GetIMUInfoResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetIMUInfo-response>)))
  "Returns md5sum for a message object of type '<GetIMUInfo-response>"
  "fcce7f85a63907f26a3912a7632e9630")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetIMUInfo-response)))
  "Returns md5sum for a message object of type 'GetIMUInfo-response"
  "fcce7f85a63907f26a3912a7632e9630")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetIMUInfo-response>)))
  "Returns full string definition for message of type '<GetIMUInfo-response>"
  (cl:format cl:nil "IMUInfo accel~%IMUInfo gyro~%~%~%================================================================================~%MSG: realsense_camera/IMUInfo~%# header.frame_id is either set to \"imu_accel\" or \"imu_gyro\"~%# to distinguish between \"accel\" and \"gyro\" info.~%std_msgs/Header header~%float64[12] data~%float64[3] noise_variances~%float64[3] bias_variances~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetIMUInfo-response)))
  "Returns full string definition for message of type 'GetIMUInfo-response"
  (cl:format cl:nil "IMUInfo accel~%IMUInfo gyro~%~%~%================================================================================~%MSG: realsense_camera/IMUInfo~%# header.frame_id is either set to \"imu_accel\" or \"imu_gyro\"~%# to distinguish between \"accel\" and \"gyro\" info.~%std_msgs/Header header~%float64[12] data~%float64[3] noise_variances~%float64[3] bias_variances~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetIMUInfo-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'accel))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'gyro))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetIMUInfo-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetIMUInfo-response
    (cl:cons ':accel (accel msg))
    (cl:cons ':gyro (gyro msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetIMUInfo)))
  'GetIMUInfo-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetIMUInfo)))
  'GetIMUInfo-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetIMUInfo)))
  "Returns string type for a service object of type '<GetIMUInfo>"
  "realsense_camera/GetIMUInfo")