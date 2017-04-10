; Auto-generated. Do not edit!


(cl:in-package realsense_camera-srv)


;//! \htmlinclude SetPower-request.msg.html

(cl:defclass <SetPower-request> (roslisp-msg-protocol:ros-message)
  ((power_on
    :reader power_on
    :initarg :power_on
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SetPower-request (<SetPower-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetPower-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetPower-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<SetPower-request> is deprecated: use realsense_camera-srv:SetPower-request instead.")))

(cl:ensure-generic-function 'power_on-val :lambda-list '(m))
(cl:defmethod power_on-val ((m <SetPower-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader realsense_camera-srv:power_on-val is deprecated.  Use realsense_camera-srv:power_on instead.")
  (power_on m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetPower-request>) ostream)
  "Serializes a message object of type '<SetPower-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'power_on) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetPower-request>) istream)
  "Deserializes a message object of type '<SetPower-request>"
    (cl:setf (cl:slot-value msg 'power_on) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetPower-request>)))
  "Returns string type for a service object of type '<SetPower-request>"
  "realsense_camera/SetPowerRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetPower-request)))
  "Returns string type for a service object of type 'SetPower-request"
  "realsense_camera/SetPowerRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetPower-request>)))
  "Returns md5sum for a message object of type '<SetPower-request>"
  "a0a242e9c383e4ceb1b4d16e36607d54")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetPower-request)))
  "Returns md5sum for a message object of type 'SetPower-request"
  "a0a242e9c383e4ceb1b4d16e36607d54")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetPower-request>)))
  "Returns full string definition for message of type '<SetPower-request>"
  (cl:format cl:nil "bool power_on~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetPower-request)))
  "Returns full string definition for message of type 'SetPower-request"
  (cl:format cl:nil "bool power_on~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetPower-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetPower-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetPower-request
    (cl:cons ':power_on (power_on msg))
))
;//! \htmlinclude SetPower-response.msg.html

(cl:defclass <SetPower-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SetPower-response (<SetPower-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetPower-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetPower-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name realsense_camera-srv:<SetPower-response> is deprecated: use realsense_camera-srv:SetPower-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetPower-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader realsense_camera-srv:success-val is deprecated.  Use realsense_camera-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetPower-response>) ostream)
  "Serializes a message object of type '<SetPower-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetPower-response>) istream)
  "Deserializes a message object of type '<SetPower-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetPower-response>)))
  "Returns string type for a service object of type '<SetPower-response>"
  "realsense_camera/SetPowerResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetPower-response)))
  "Returns string type for a service object of type 'SetPower-response"
  "realsense_camera/SetPowerResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetPower-response>)))
  "Returns md5sum for a message object of type '<SetPower-response>"
  "a0a242e9c383e4ceb1b4d16e36607d54")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetPower-response)))
  "Returns md5sum for a message object of type 'SetPower-response"
  "a0a242e9c383e4ceb1b4d16e36607d54")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetPower-response>)))
  "Returns full string definition for message of type '<SetPower-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetPower-response)))
  "Returns full string definition for message of type 'SetPower-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetPower-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetPower-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetPower-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetPower)))
  'SetPower-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetPower)))
  'SetPower-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetPower)))
  "Returns string type for a service object of type '<SetPower>"
  "realsense_camera/SetPower")