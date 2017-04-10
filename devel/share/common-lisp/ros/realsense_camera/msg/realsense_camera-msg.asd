
(cl:in-package :asdf)

(defsystem "realsense_camera-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "IMUInfo" :depends-on ("_package_IMUInfo"))
    (:file "_package_IMUInfo" :depends-on ("_package"))
  ))