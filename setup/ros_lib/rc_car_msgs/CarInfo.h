#ifndef _ROS_rc_car_msgs_CarInfo_h
#define _ROS_rc_car_msgs_CarInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rc_car_msgs
{

  class CarInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _throttle_type;
      _throttle_type throttle;
      typedef float _steer_type;
      _steer_type steer;

    CarInfo():
      header(),
      throttle(0),
      steer(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
     return offset;
    }

    const char * getType(){ return "rc_car_msgs/CarInfo"; };
    const char * getMD5(){ return "fde3dbdce53ea8efc0e0dd6ef6da3ed4"; };

  };

}
#endif