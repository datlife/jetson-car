;; Auto-generated. Do not edit!


(when (boundp 'rc_car_msgs::CarRecorder)
  (if (not (find-package "RC_CAR_MSGS"))
    (make-package "RC_CAR_MSGS"))
  (shadow 'CarRecorder (find-package "RC_CAR_MSGS")))
(unless (find-package "RC_CAR_MSGS::CARRECORDER")
  (make-package "RC_CAR_MSGS::CARRECORDER"))

(in-package "ROS")
;;//! \htmlinclude CarRecorder.msg.html


(defclass rc_car_msgs::CarRecorder
  :super ros::object
  :slots (_img_path _steer _throttle _velocity ))

(defmethod rc_car_msgs::CarRecorder
  (:init
   (&key
    ((:img_path __img_path) "")
    ((:steer __steer) 0.0)
    ((:throttle __throttle) 0.0)
    ((:velocity __velocity) 0.0)
    )
   (send-super :init)
   (setq _img_path (string __img_path))
   (setq _steer (float __steer))
   (setq _throttle (float __throttle))
   (setq _velocity (float __velocity))
   self)
  (:img_path
   (&optional __img_path)
   (if __img_path (setq _img_path __img_path)) _img_path)
  (:steer
   (&optional __steer)
   (if __steer (setq _steer __steer)) _steer)
  (:throttle
   (&optional __throttle)
   (if __throttle (setq _throttle __throttle)) _throttle)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:serialization-length
   ()
   (+
    ;; string _img_path
    4 (length _img_path)
    ;; float32 _steer
    4
    ;; float32 _throttle
    4
    ;; float32 _velocity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _img_path
       (write-long (length _img_path) s) (princ _img_path s)
     ;; float32 _steer
       (sys::poke _steer (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _throttle
       (sys::poke _throttle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _img_path
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _img_path (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32 _steer
     (setq _steer (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _throttle
     (setq _throttle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _velocity
     (setq _velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get rc_car_msgs::CarRecorder :md5sum-) "7ff232c3ef1ac97d91355af7dc5015af")
(setf (get rc_car_msgs::CarRecorder :datatype-) "rc_car_msgs/CarRecorder")
(setf (get rc_car_msgs::CarRecorder :definition-)
      "string   img_path
float32  steer
float32  throttle
float32  velocity

")



(provide :rc_car_msgs/CarRecorder "7ff232c3ef1ac97d91355af7dc5015af")


