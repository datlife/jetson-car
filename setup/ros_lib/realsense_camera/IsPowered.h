#ifndef _ROS_SERVICE_IsPowered_h
#define _ROS_SERVICE_IsPowered_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace realsense_camera
{

static const char ISPOWERED[] = "realsense_camera/IsPowered";

  class IsPoweredRequest : public ros::Msg
  {
    public:

    IsPoweredRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return ISPOWERED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class IsPoweredResponse : public ros::Msg
  {
    public:
      typedef bool _is_powered_type;
      _is_powered_type is_powered;

    IsPoweredResponse():
      is_powered(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_powered;
      u_is_powered.real = this->is_powered;
      *(outbuffer + offset + 0) = (u_is_powered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_powered);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_powered;
      u_is_powered.base = 0;
      u_is_powered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_powered = u_is_powered.real;
      offset += sizeof(this->is_powered);
     return offset;
    }

    const char * getType(){ return ISPOWERED; };
    const char * getMD5(){ return "7ee632447d6acea26ec2c412cc1e6ed5"; };

  };

  class IsPowered {
    public:
    typedef IsPoweredRequest Request;
    typedef IsPoweredResponse Response;
  };

}
#endif
