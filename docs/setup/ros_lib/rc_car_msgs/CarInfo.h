#ifndef _ROS_rc_car_msgs_CarInfo_h
#define _ROS_rc_car_msgs_CarInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rc_car_msgs
{

  class CarInfo : public ros::Msg
  {
    public:
      typedef float _throttle_type;
      _throttle_type throttle;
      typedef float _steer_type;
      _steer_type steer;
      typedef uint8_t _rpm_type;
      _rpm_type rpm;
      typedef uint8_t _speed_type;
      _speed_type speed;

    CarInfo():
      throttle(0),
      steer(0),
      rpm(0),
      speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      } u_steer;
      u_steer.real = this->steer;
      *(outbuffer + offset + 0) = (u_steer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer);
      *(outbuffer + offset + 0) = (this->rpm >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rpm);
      *(outbuffer + offset + 0) = (this->speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      } u_steer;
      u_steer.base = 0;
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer = u_steer.real;
      offset += sizeof(this->steer);
      this->rpm =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rpm);
      this->speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->speed);
     return offset;
    }

    const char * getType(){ return "rc_car_msgs/CarInfo"; };
    const char * getMD5(){ return "760226ed85e7b7598cf8f93d6db1cd49"; };

  };

}
#endif