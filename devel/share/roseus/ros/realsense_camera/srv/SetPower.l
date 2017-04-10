;; Auto-generated. Do not edit!


(when (boundp 'realsense_camera::SetPower)
  (if (not (find-package "REALSENSE_CAMERA"))
    (make-package "REALSENSE_CAMERA"))
  (shadow 'SetPower (find-package "REALSENSE_CAMERA")))
(unless (find-package "REALSENSE_CAMERA::SETPOWER")
  (make-package "REALSENSE_CAMERA::SETPOWER"))
(unless (find-package "REALSENSE_CAMERA::SETPOWERREQUEST")
  (make-package "REALSENSE_CAMERA::SETPOWERREQUEST"))
(unless (find-package "REALSENSE_CAMERA::SETPOWERRESPONSE")
  (make-package "REALSENSE_CAMERA::SETPOWERRESPONSE"))

(in-package "ROS")





(defclass realsense_camera::SetPowerRequest
  :super ros::object
  :slots (_power_on ))

(defmethod realsense_camera::SetPowerRequest
  (:init
   (&key
    ((:power_on __power_on) nil)
    )
   (send-super :init)
   (setq _power_on __power_on)
   self)
  (:power_on
   (&optional __power_on)
   (if __power_on (setq _power_on __power_on)) _power_on)
  (:serialization-length
   ()
   (+
    ;; bool _power_on
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _power_on
       (if _power_on (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _power_on
     (setq _power_on (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass realsense_camera::SetPowerResponse
  :super ros::object
  :slots (_success ))

(defmethod realsense_camera::SetPowerResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass realsense_camera::SetPower
  :super ros::object
  :slots ())

(setf (get realsense_camera::SetPower :md5sum-) "a0a242e9c383e4ceb1b4d16e36607d54")
(setf (get realsense_camera::SetPower :datatype-) "realsense_camera/SetPower")
(setf (get realsense_camera::SetPower :request) realsense_camera::SetPowerRequest)
(setf (get realsense_camera::SetPower :response) realsense_camera::SetPowerResponse)

(defmethod realsense_camera::SetPowerRequest
  (:response () (instance realsense_camera::SetPowerResponse :init)))

(setf (get realsense_camera::SetPowerRequest :md5sum-) "a0a242e9c383e4ceb1b4d16e36607d54")
(setf (get realsense_camera::SetPowerRequest :datatype-) "realsense_camera/SetPowerRequest")
(setf (get realsense_camera::SetPowerRequest :definition-)
      "bool power_on
---
bool success

")

(setf (get realsense_camera::SetPowerResponse :md5sum-) "a0a242e9c383e4ceb1b4d16e36607d54")
(setf (get realsense_camera::SetPowerResponse :datatype-) "realsense_camera/SetPowerResponse")
(setf (get realsense_camera::SetPowerResponse :definition-)
      "bool power_on
---
bool success

")



(provide :realsense_camera/SetPower "a0a242e9c383e4ceb1b4d16e36607d54")


