; Auto-generated. Do not edit!


(cl:in-package realsense_camera-srv)


;//! \htmlinclude ForcePower-request.msg.html

(cl:defclass <ForcePower-request> (roslisp-msg-protocol:ros-message)
  ((power_on
    :reader power_on
    :initarg :power_on
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ForcePower-request (<ForcePower-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ForcePower-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ForcePower-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<ForcePower-request> is deprecated: use realsense_camera-srv:ForcePower-request instead.")))

(cl:ensure-generic-function 'power_on-val :lambda-list '(m))
(cl:defmethod power_on-val ((m <ForcePower-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader realsense_camera-srv:power_on-val is deprecated.  Use realsense_camera-srv:power_on instead.")
  (power_on m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ForcePower-request>) ostream)
  "Serializes a message object of type '<ForcePower-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'power_on) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ForcePower-request>) istream)
  "Deserializes a message object of type '<ForcePower-request>"
    (cl:setf (cl:slot-value msg 'power_on) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ForcePower-request>)))
  "Returns string type for a service object of type '<ForcePower-request>"
  "realsense_camera/ForcePowerRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ForcePower-request)))
  "Returns string type for a service object of type 'ForcePower-request"
  "realsense_camera/ForcePowerRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ForcePower-request>)))
  "Returns md5sum for a message object of type '<ForcePower-request>"
  "0a07d78fa0214ec8d773e5045aa5087a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ForcePower-request)))
  "Returns md5sum for a message object of type 'ForcePower-request"
  "0a07d78fa0214ec8d773e5045aa5087a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ForcePower-request>)))
  "Returns full string definition for message of type '<ForcePower-request>"
  (cl:format cl:nil "bool power_on~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ForcePower-request)))
  "Returns full string definition for message of type 'ForcePower-request"
  (cl:format cl:nil "bool power_on~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ForcePower-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ForcePower-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ForcePower-request
    (cl:cons ':power_on (power_on msg))
))
;//! \htmlinclude ForcePower-response.msg.html

(cl:defclass <ForcePower-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ForcePower-response (<ForcePower-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ForcePower-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ForcePower-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<ForcePower-response> is deprecated: use realsense_camera-srv:ForcePower-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ForcePower-response>) ostream)
  "Serializes a message object of type '<ForcePower-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ForcePower-response>) istream)
  "Deserializes a message object of type '<ForcePower-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ForcePower-response>)))
  "Returns string type for a service object of type '<ForcePower-response>"
  "realsense_camera/ForcePowerResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ForcePower-response)))
  "Returns string type for a service object of type 'ForcePower-response"
  "realsense_camera/ForcePowerResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ForcePower-response>)))
  "Returns md5sum for a message object of type '<ForcePower-response>"
  "0a07d78fa0214ec8d773e5045aa5087a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ForcePower-response)))
  "Returns md5sum for a message object of type 'ForcePower-response"
  "0a07d78fa0214ec8d773e5045aa5087a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ForcePower-response>)))
  "Returns full string definition for message of type '<ForcePower-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ForcePower-response)))
  "Returns full string definition for message of type 'ForcePower-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ForcePower-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ForcePower-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ForcePower-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ForcePower)))
  'ForcePower-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ForcePower)))
  'ForcePower-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ForcePower)))
  "Returns string type for a service object of type '<ForcePower>"
  "realsense_camera/ForcePower")