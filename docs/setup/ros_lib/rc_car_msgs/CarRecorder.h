#ifndef _ROS_rc_car_msgs_CarRecorder_h
#define _ROS_rc_car_msgs_CarRecorder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rc_car_msgs
{

  class CarRecorder : public ros::Msg
  {
    public:
      typedef const char* _img_path_type;
      _img_path_type img_path;
      typedef float _steer_type;
      _steer_type steer;
      typedef float _throttle_type;
      _throttle_type throttle;
      typedef float _speed_type;
      _speed_type speed;

    CarRecorder():
      img_path(""),
      steer(0),
      throttle(0),
      speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_img_path = strlen(this->img_path);
      varToArr(outbuffer + offset, length_img_path);
      offset += 4;
      memcpy(outbuffer + offset, this->img_path, length_img_path);
      offset += length_img_path;
      union {
        float real;
        uint32_t base;
      } u_steer;
      u_steer.real = this->steer;
      *(outbuffer + offset + 0) = (u_steer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer);
      union {
        float real;
        uint32_t base;
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_img_path;
      arrToVar(length_img_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_img_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_img_path-1]=0;
      this->img_path = (char *)(inbuffer + offset-1);
      offset += length_img_path;
      union {
        float real;
        uint32_t base;
      } u_steer;
      u_steer.base = 0;
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer = u_steer.real;
      offset += sizeof(this->steer);
      union {
        float real;
        uint32_t base;
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
     return offset;
    }

    const char * getType(){ return "rc_car_msgs/CarRecorder"; };
    const char * getMD5(){ return "2206cee5c7121162c945e51ad73cfaaa"; };

  };

}
#endif