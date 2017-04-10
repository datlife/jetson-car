;; Auto-generated. Do not edit!


(when (boundp 'realsense_camera::GetIMUInfo)
  (if (not (find-package "REALSENSE_CAMERA"))
    (make-package "REALSENSE_CAMERA"))
  (shadow 'GetIMUInfo (find-package "REALSENSE_CAMERA")))
(unless (find-package "REALSENSE_CAMERA::GETIMUINFO")
  (make-package "REALSENSE_CAMERA::GETIMUINFO"))
(unless (find-package "REALSENSE_CAMERA::GETIMUINFOREQUEST")
  (make-package "REALSENSE_CAMERA::GETIMUINFOREQUEST"))
(unless (find-package "REALSENSE_CAMERA::GETIMUINFORESPONSE")
  (make-package "REALSENSE_CAMERA::GETIMUINFORESPONSE"))

(in-package "ROS")





(defclass realsense_camera::GetIMUInfoRequest
  :super ros::object
  :slots ())

(defmethod realsense_camera::GetIMUInfoRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass realsense_camera::GetIMUInfoResponse
  :super ros::object
  :slots (_accel _gyro ))

(defmethod realsense_camera::GetIMUInfoResponse
  (:init
   (&key
    ((:accel __accel) (instance realsense_camera::IMUInfo :init))
    ((:gyro __gyro) (instance realsense_camera::IMUInfo :init))
    )
   (send-super :init)
   (setq _accel __accel)
   (setq _gyro __gyro)
   self)
  (:accel
   (&rest __accel)
   (if (keywordp (car __accel))
       (send* _accel __accel)
     (progn
       (if __accel (setq _accel (car __accel)))
       _accel)))
  (:gyro
   (&rest __gyro)
   (if (keywordp (car __gyro))
       (send* _gyro __gyro)
     (progn
       (if __gyro (setq _gyro (car __gyro)))
       _gyro)))
  (:serialization-length
   ()
   (+
    ;; realsense_camera/IMUInfo _accel
    (send _accel :serialization-length)
    ;; realsense_camera/IMUInfo _gyro
    (send _gyro :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; realsense_camera/IMUInfo _accel
       (send _accel :serialize s)
     ;; realsense_camera/IMUInfo _gyro
       (send _gyro :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; realsense_camera/IMUInfo _accel
     (send _accel :deserialize buf ptr-) (incf ptr- (send _accel :serialization-length))
   ;; realsense_camera/IMUInfo _gyro
     (send _gyro :deserialize buf ptr-) (incf ptr- (send _gyro :serialization-length))
   ;;
   self)
  )

(defclass realsense_camera::GetIMUInfo
  :super ros::object
  :slots ())

(setf (get realsense_camera::GetIMUInfo :md5sum-) "fcce7f85a63907f26a3912a7632e9630")
(setf (get realsense_camera::GetIMUInfo :datatype-) "realsense_camera/GetIMUInfo")
(setf (get realsense_camera::GetIMUInfo :request) realsense_camera::GetIMUInfoRequest)
(setf (get realsense_camera::GetIMUInfo :response) realsense_camera::GetIMUInfoResponse)

(defmethod realsense_camera::GetIMUInfoRequest
  (:response () (instance realsense_camera::GetIMUInfoResponse :init)))

(setf (get realsense_camera::GetIMUInfoRequest :md5sum-) "fcce7f85a63907f26a3912a7632e9630")
(setf (get realsense_camera::GetIMUInfoRequest :datatype-) "realsense_camera/GetIMUInfoRequest")
(setf (get realsense_camera::GetIMUInfoRequest :definition-)
      "---
IMUInfo accel
IMUInfo gyro


================================================================================
MSG: realsense_camera/IMUInfo
# header.frame_id is either set to \"imu_accel\" or \"imu_gyro\"
# to distinguish between \"accel\" and \"gyro\" info.
std_msgs/Header header
float64[12] data
float64[3] noise_variances
float64[3] bias_variances
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
")

(setf (get realsense_camera::GetIMUInfoResponse :md5sum-) "fcce7f85a63907f26a3912a7632e9630")
(setf (get realsense_camera::GetIMUInfoResponse :datatype-) "realsense_camera/GetIMUInfoResponse")
(setf (get realsense_camera::GetIMUInfoResponse :definition-)
      "---
IMUInfo accel
IMUInfo gyro


================================================================================
MSG: realsense_camera/IMUInfo
# header.frame_id is either set to \"imu_accel\" or \"imu_gyro\"
# to distinguish between \"accel\" and \"gyro\" info.
std_msgs/Header header
float64[12] data
float64[3] noise_variances
float64[3] bias_variances
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
")



(provide :realsense_camera/GetIMUInfo "fcce7f85a63907f26a3912a7632e9630")


