;; Auto-generated. Do not edit!


(when (boundp 'realsense_camera::IMUInfo)
  (if (not (find-package "REALSENSE_CAMERA"))
    (make-package "REALSENSE_CAMERA"))
  (shadow 'IMUInfo (find-package "REALSENSE_CAMERA")))
(unless (find-package "REALSENSE_CAMERA::IMUINFO")
  (make-package "REALSENSE_CAMERA::IMUINFO"))

(in-package "ROS")
;;//! \htmlinclude IMUInfo.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass realsense_camera::IMUInfo
  :super ros::object
  :slots (_header _data _noise_variances _bias_variances ))

(defmethod realsense_camera::IMUInfo
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:data __data) (make-array 12 :initial-element 0.0 :element-type :float))
    ((:noise_variances __noise_variances) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:bias_variances __bias_variances) (make-array 3 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _data __data)
   (setq _noise_variances __noise_variances)
   (setq _bias_variances __bias_variances)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:noise_variances
   (&optional __noise_variances)
   (if __noise_variances (setq _noise_variances __noise_variances)) _noise_variances)
  (:bias_variances
   (&optional __bias_variances)
   (if __bias_variances (setq _bias_variances __bias_variances)) _bias_variances)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64[12] _data
    (* 8    12)
    ;; float64[3] _noise_variances
    (* 8    3)
    ;; float64[3] _bias_variances
    (* 8    3)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64[12] _data
     (dotimes (i 12)
       (sys::poke (elt _data i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[3] _noise_variances
     (dotimes (i 3)
       (sys::poke (elt _noise_variances i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[3] _bias_variances
     (dotimes (i 3)
       (sys::poke (elt _bias_variances i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64[12] _data
   (dotimes (i (length _data))
     (setf (elt _data i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[3] _noise_variances
   (dotimes (i (length _noise_variances))
     (setf (elt _noise_variances i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[3] _bias_variances
   (dotimes (i (length _bias_variances))
     (setf (elt _bias_variances i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;;
   self)
  )

(setf (get realsense_camera::IMUInfo :md5sum-) "b8a77fbb6e4146ae79c8a943413e4f62")
(setf (get realsense_camera::IMUInfo :datatype-) "realsense_camera/IMUInfo")
(setf (get realsense_camera::IMUInfo :definition-)
      "# header.frame_id is either set to \"imu_accel\" or \"imu_gyro\"
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



(provide :realsense_camera/IMUInfo "b8a77fbb6e4146ae79c8a943413e4f62")


