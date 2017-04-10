;; Auto-generated. Do not edit!


(when (boundp 'realsense_camera::IsPowered)
  (if (not (find-package "REALSENSE_CAMERA"))
    (make-package "REALSENSE_CAMERA"))
  (shadow 'IsPowered (find-package "REALSENSE_CAMERA")))
(unless (find-package "REALSENSE_CAMERA::ISPOWERED")
  (make-package "REALSENSE_CAMERA::ISPOWERED"))
(unless (find-package "REALSENSE_CAMERA::ISPOWEREDREQUEST")
  (make-package "REALSENSE_CAMERA::ISPOWEREDREQUEST"))
(unless (find-package "REALSENSE_CAMERA::ISPOWEREDRESPONSE")
  (make-package "REALSENSE_CAMERA::ISPOWEREDRESPONSE"))

(in-package "ROS")





(defclass realsense_camera::IsPoweredRequest
  :super ros::object
  :slots ())

(defmethod realsense_camera::IsPoweredRequest
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

(defclass realsense_camera::IsPoweredResponse
  :super ros::object
  :slots (_is_powered ))

(defmethod realsense_camera::IsPoweredResponse
  (:init
   (&key
    ((:is_powered __is_powered) nil)
    )
   (send-super :init)
   (setq _is_powered __is_powered)
   self)
  (:is_powered
   (&optional __is_powered)
   (if __is_powered (setq _is_powered __is_powered)) _is_powered)
  (:serialization-length
   ()
   (+
    ;; bool _is_powered
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _is_powered
       (if _is_powered (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _is_powered
     (setq _is_powered (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass realsense_camera::IsPowered
  :super ros::object
  :slots ())

(setf (get realsense_camera::IsPowered :md5sum-) "7ee632447d6acea26ec2c412cc1e6ed5")
(setf (get realsense_camera::IsPowered :datatype-) "realsense_camera/IsPowered")
(setf (get realsense_camera::IsPowered :request) realsense_camera::IsPoweredRequest)
(setf (get realsense_camera::IsPowered :response) realsense_camera::IsPoweredResponse)

(defmethod realsense_camera::IsPoweredRequest
  (:response () (instance realsense_camera::IsPoweredResponse :init)))

(setf (get realsense_camera::IsPoweredRequest :md5sum-) "7ee632447d6acea26ec2c412cc1e6ed5")
(setf (get realsense_camera::IsPoweredRequest :datatype-) "realsense_camera/IsPoweredRequest")
(setf (get realsense_camera::IsPoweredRequest :definition-)
      "---
bool is_powered

")

(setf (get realsense_camera::IsPoweredResponse :md5sum-) "7ee632447d6acea26ec2c412cc1e6ed5")
(setf (get realsense_camera::IsPoweredResponse :datatype-) "realsense_camera/IsPoweredResponse")
(setf (get realsense_camera::IsPoweredResponse :definition-)
      "---
bool is_powered

")



(provide :realsense_camera/IsPowered "7ee632447d6acea26ec2c412cc1e6ed5")


