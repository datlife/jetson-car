; Auto-generated. Do not edit!


(cl:in-package realsense_camera-srv)


;//! \htmlinclude CameraConfiguration-request.msg.html

(cl:defclass <CameraConfiguration-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass CameraConfiguration-request (<CameraConfiguration-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CameraConfiguration-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CameraConfiguration-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<CameraConfiguration-request> is deprecated: use realsense_camera-srv:CameraConfiguration-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CameraConfiguration-request>) ostream)
  "Serializes a message object of type '<CameraConfiguration-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CameraConfiguration-request>) istream)
  "Deserializes a message object of type '<CameraConfiguration-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CameraConfiguration-request>)))
  "Returns string type for a service object of type '<CameraConfiguration-request>"
  "realsense_camera/CameraConfigurationRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CameraConfiguration-request)))
  "Returns string type for a service object of type 'CameraConfiguration-request"
  "realsense_camera/CameraConfigurationRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CameraConfiguration-request>)))
  "Returns md5sum for a message object of type '<CameraConfiguration-request>"
  "2c284890309b239ca006a289ca29b4d1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CameraConfiguration-request)))
  "Returns md5sum for a message object of type 'CameraConfiguration-request"
  "2c284890309b239ca006a289ca29b4d1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CameraConfiguration-request>)))
  "Returns full string definition for message of type '<CameraConfiguration-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CameraConfiguration-request)))
  "Returns full string definition for message of type 'CameraConfiguration-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CameraConfiguration-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CameraConfiguration-request>))
  "Converts a ROS message object to a list"
  (cl:list 'CameraConfiguration-request
))
;//! \htmlinclude CameraConfiguration-response.msg.html

(cl:defclass <CameraConfiguration-response> (roslisp-msg-protocol:ros-message)
  ((configuration_str
    :reader configuration_str
    :initarg :configuration_str
    :type cl:string
    :initform ""))
)

(cl:defclass CameraConfiguration-response (<CameraConfiguration-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CameraConfiguration-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CameraConfiguration-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<CameraConfiguration-response> is deprecated: use realsense_camera-srv:CameraConfiguration-response instead.")))

(cl:ensure-generic-function 'configuration_str-val :lambda-list '(m))
(cl:defmethod configuration_str-val ((m <CameraConfiguration-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader realsense_camera-srv:configuration_str-val is deprecated.  Use realsense_camera-srv:configuration_str instead.")
  (configuration_str m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CameraConfiguration-response>) ostream)
  "Serializes a message object of type '<CameraConfiguration-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'configuration_str))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'configuration_str))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CameraConfiguration-response>) istream)
  "Deserializes a message object of type '<CameraConfiguration-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'configuration_str) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'configuration_str) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CameraConfiguration-response>)))
  "Returns string type for a service object of type '<CameraConfiguration-response>"
  "realsense_camera/CameraConfigurationResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CameraConfiguration-response)))
  "Returns string type for a service object of type 'CameraConfiguration-response"
  "realsense_camera/CameraConfigurationResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CameraConfiguration-response>)))
  "Returns md5sum for a message object of type '<CameraConfiguration-response>"
  "2c284890309b239ca006a289ca29b4d1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CameraConfiguration-response)))
  "Returns md5sum for a message object of type 'CameraConfiguration-response"
  "2c284890309b239ca006a289ca29b4d1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CameraConfiguration-response>)))
  "Returns full string definition for message of type '<CameraConfiguration-response>"
  (cl:format cl:nil "string configuration_str~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CameraConfiguration-response)))
  "Returns full string definition for message of type 'CameraConfiguration-response"
  (cl:format cl:nil "string configuration_str~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CameraConfiguration-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'configuration_str))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CameraConfiguration-response>))
  "Converts a ROS message object to a list"
  (cl:list 'CameraConfiguration-response
    (cl:cons ':configuration_str (configuration_str msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'CameraConfiguration)))
  'CameraConfiguration-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'CameraConfiguration)))
  'CameraConfiguration-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CameraConfiguration)))
  "Returns string type for a service object of type '<CameraConfiguration>"
  "realsense_camera/CameraConfiguration")