
(cl:in-package :asdf)

(defsystem "realsense_camera-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :realsense_camera-msg
)
  :components ((:file "_package")
    (:file "CameraConfiguration" :depends-on ("_package_CameraConfiguration"))
    (:file "_package_CameraConfiguration" :depends-on ("_package"))
    (:file "ForcePower" :depends-on ("_package_ForcePower"))
    (:file "_package_ForcePower" :depends-on ("_package"))
    (:file "GetIMUInfo" :depends-on ("_package_GetIMUInfo"))
    (:file "_package_GetIMUInfo" :depends-on ("_package"))
    (:file "IsPowered" :depends-on ("_package_IsPowered"))
    (:file "_package_IsPowered" :depends-on ("_package"))
    (:file "SetPower" :depends-on ("_package_SetPower"))
    (:file "_package_SetPower" :depends-on ("_package"))
  ))