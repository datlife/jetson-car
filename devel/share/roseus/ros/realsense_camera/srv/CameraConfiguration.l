;; Auto-generated. Do not edit!


(when (boundp 'realsense_camera::CameraConfiguration)
  (if (not (find-package "REALSENSE_CAMERA"))
    (make-package "REALSENSE_CAMERA"))
  (shadow 'CameraConfiguration (find-package "REALSENSE_CAMERA")))
(unless (find-package "REALSENSE_CAMERA::CAMERACONFIGURATION")
  (make-package "REALSENSE_CAMERA::CAMERACONFIGURATION"))
(unless (find-package "REALSENSE_CAMERA::CAMERACONFIGURATIONREQUEST")
  (make-package "REALSENSE_CAMERA::CAMERACONFIGURATIONREQUEST"))
(unless (find-package "REALSENSE_CAMERA::CAMERACONFIGURATIONRESPONSE")
  (make-package "REALSENSE_CAMERA::CAMERACONFIGURATIONRESPONSE"))

(in-package "ROS")





(defclass realsense_camera::CameraConfigurationRequest
  :super ros::object
  :slots ())

(defmethod realsense_camera::CameraConfigurationRequest
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

(defclass realsense_camera::CameraConfigurationResponse
  :super ros::object
  :slots (_configuration_str ))

(defmethod realsense_camera::CameraConfigurationResponse
  (:init
   (&key
    ((:configuration_str __configuration_str) "")
    )
   (send-super :init)
   (setq _configuration_str (string __configuration_str))
   self)
  (:configuration_str
   (&optional __configuration_str)
   (if __configuration_str (setq _configuration_str __configuration_str)) _configuration_str)
  (:serialization-length
   ()
   (+
    ;; string _configuration_str
    4 (length _configuration_str)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _configuration_str
       (write-long (length _configuration_str) s) (princ _configuration_str s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _configuration_str
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _configuration_str (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass realsense_camera::CameraConfiguration
  :super ros::object
  :slots ())

(setf (get realsense_camera::CameraConfiguration :md5sum-) "2c284890309b239ca006a289ca29b4d1")
(setf (get realsense_camera::CameraConfiguration :datatype-) "realsense_camera/CameraConfiguration")
(setf (get realsense_camera::CameraConfiguration :request) realsense_camera::CameraConfigurationRequest)
(setf (get realsense_camera::CameraConfiguration :response) realsense_camera::CameraConfigurationResponse)

(defmethod realsense_camera::CameraConfigurationRequest
  (:response () (instance realsense_camera::CameraConfigurationResponse :init)))

(setf (get realsense_camera::CameraConfigurationRequest :md5sum-) "2c284890309b239ca006a289ca29b4d1")
(setf (get realsense_camera::CameraConfigurationRequest :datatype-) "realsense_camera/CameraConfigurationRequest")
(setf (get realsense_camera::CameraConfigurationRequest :definition-)
      "---
string configuration_str

")

(setf (get realsense_camera::CameraConfigurationResponse :md5sum-) "2c284890309b239ca006a289ca29b4d1")
(setf (get realsense_camera::CameraConfigurationResponse :datatype-) "realsense_camera/CameraConfigurationResponse")
(setf (get realsense_camera::CameraConfigurationResponse :definition-)
      "---
string configuration_str

")



(provide :realsense_camera/CameraConfiguration "2c284890309b239ca006a289ca29b4d1")


