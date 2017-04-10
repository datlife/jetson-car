;; Auto-generated. Do not edit!


(when (boundp 'realsense_camera::ForcePower)
  (if (not (find-package "REALSENSE_CAMERA"))
    (make-package "REALSENSE_CAMERA"))
  (shadow 'ForcePower (find-package "REALSENSE_CAMERA")))
(unless (find-package "REALSENSE_CAMERA::FORCEPOWER")
  (make-package "REALSENSE_CAMERA::FORCEPOWER"))
(unless (find-package "REALSENSE_CAMERA::FORCEPOWERREQUEST")
  (make-package "REALSENSE_CAMERA::FORCEPOWERREQUEST"))
(unless (find-package "REALSENSE_CAMERA::FORCEPOWERRESPONSE")
  (make-package "REALSENSE_CAMERA::FORCEPOWERRESPONSE"))

(in-package "ROS")





(defclass realsense_camera::ForcePowerRequest
  :super ros::object
  :slots (_power_on ))

(defmethod realsense_camera::ForcePowerRequest
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

(defclass realsense_camera::ForcePowerResponse
  :super ros::object
  :slots ())

(defmethod realsense_camera::ForcePowerResponse
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

(defclass realsense_camera::ForcePower
  :super ros::object
  :slots ())

(setf (get realsense_camera::ForcePower :md5sum-) "0a07d78fa0214ec8d773e5045aa5087a")
(setf (get realsense_camera::ForcePower :datatype-) "realsense_camera/ForcePower")
(setf (get realsense_camera::ForcePower :request) realsense_camera::ForcePowerRequest)
(setf (get realsense_camera::ForcePower :response) realsense_camera::ForcePowerResponse)

(defmethod realsense_camera::ForcePowerRequest
  (:response () (instance realsense_camera::ForcePowerResponse :init)))

(setf (get realsense_camera::ForcePowerRequest :md5sum-) "0a07d78fa0214ec8d773e5045aa5087a")
(setf (get realsense_camera::ForcePowerRequest :datatype-) "realsense_camera/ForcePowerRequest")
(setf (get realsense_camera::ForcePowerRequest :definition-)
      "bool power_on
---

")

(setf (get realsense_camera::ForcePowerResponse :md5sum-) "0a07d78fa0214ec8d773e5045aa5087a")
(setf (get realsense_camera::ForcePowerResponse :datatype-) "realsense_camera/ForcePowerResponse")
(setf (get realsense_camera::ForcePowerResponse :definition-)
      "bool power_on
---

")



(provide :realsense_camera/ForcePower "0a07d78fa0214ec8d773e5045aa5087a")


