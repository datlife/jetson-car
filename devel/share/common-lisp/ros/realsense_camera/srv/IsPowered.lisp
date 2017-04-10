; Auto-generated. Do not edit!


(cl:in-package realsense_camera-srv)


;//! \htmlinclude IsPowered-request.msg.html

(cl:defclass <IsPowered-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass IsPowered-request (<IsPowered-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IsPowered-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IsPowered-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<IsPowered-request> is deprecated: use realsense_camera-srv:IsPowered-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IsPowered-request>) ostream)
  "Serializes a message object of type '<IsPowered-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IsPowered-request>) istream)
  "Deserializes a message object of type '<IsPowered-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IsPowered-request>)))
  "Returns string type for a service object of type '<IsPowered-request>"
  "realsense_camera/IsPoweredRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IsPowered-request)))
  "Returns string type for a service object of type 'IsPowered-request"
  "realsense_camera/IsPoweredRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IsPowered-request>)))
  "Returns md5sum for a message object of type '<IsPowered-request>"
  "7ee632447d6acea26ec2c412cc1e6ed5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IsPowered-request)))
  "Returns md5sum for a message object of type 'IsPowered-request"
  "7ee632447d6acea26ec2c412cc1e6ed5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IsPowered-request>)))
  "Returns full string definition for message of type '<IsPowered-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IsPowered-request)))
  "Returns full string definition for message of type 'IsPowered-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IsPowered-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IsPowered-request>))
  "Converts a ROS message object to a list"
  (cl:list 'IsPowered-request
))
;//! \htmlinclude IsPowered-response.msg.html

(cl:defclass <IsPowered-response> (roslisp-msg-protocol:ros-message)
  ((is_powered
    :reader is_powered
    :initarg :is_powered
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass IsPowered-response (<IsPowered-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IsPowered-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IsPowered-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<IsPowered-response> is deprecated: use realsense_camera-srv:IsPowered-response instead.")))

(cl:ensure-generic-function 'is_powered-val :lambda-list '(m))
(cl:defmethod is_powered-val ((m <IsPowered-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader realsense_camera-srv:is_powered-val is deprecated.  Use realsense_camera-srv:is_powered instead.")
  (is_powered m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IsPowered-response>) ostream)
  "Serializes a message object of type '<IsPowered-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_powered) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IsPowered-response>) istream)
  "Deserializes a message object of type '<IsPowered-response>"
    (cl:setf (cl:slot-value msg 'is_powered) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IsPowered-response>)))
  "Returns string type for a service object of type '<IsPowered-response>"
  "realsense_camera/IsPoweredResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IsPowered-response)))
  "Returns string type for a service object of type 'IsPowered-response"
  "realsense_camera/IsPoweredResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IsPowered-response>)))
  "Returns md5sum for a message object of type '<IsPowered-response>"
  "7ee632447d6acea26ec2c412cc1e6ed5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IsPowered-response)))
  "Returns md5sum for a message object of type 'IsPowered-response"
  "7ee632447d6acea26ec2c412cc1e6ed5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IsPowered-response>)))
  "Returns full string definition for message of type '<IsPowered-response>"
  (cl:format cl:nil "bool is_powered~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IsPowered-response)))
  "Returns full string definition for message of type 'IsPowered-response"
  (cl:format cl:nil "bool is_powered~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IsPowered-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IsPowered-response>))
  "Converts a ROS message object to a list"
  (cl:list 'IsPowered-response
    (cl:cons ':is_powered (is_powered msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'IsPowered)))
  'IsPowered-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'IsPowered)))
  'IsPowered-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IsPowered)))
  "Returns string type for a service object of type '<IsPowered>"
  "realsense_camera/IsPowered")