#ifndef _ROS_SERVICE_ForcePower_h
#define _ROS_SERVICE_ForcePower_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace realsense_camera
{

static const char FORCEPOWER[] = "realsense_camera/ForcePower";

  class ForcePowerRequest : public ros::Msg
  {
    public:
      typedef bool _power_on_type;
      _power_on_type power_on;

    ForcePowerRequest():
      power_on(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_power_on;
      u_power_on.real = this->power_on;
      *(outbuffer + offset + 0) = (u_power_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_on);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_power_on;
      u_power_on.base = 0;
      u_power_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->power_on = u_power_on.real;
      offset += sizeof(this->power_on);
     return offset;
    }

    const char * getType(){ return FORCEPOWER; };
    const char * getMD5(){ return "0a07d78fa0214ec8d773e5045aa5087a"; };

  };

  class ForcePowerResponse : public ros::Msg
  {
    public:

    ForcePowerResponse()
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

    const char * getType(){ return FORCEPOWER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ForcePower {
    public:
    typedef ForcePowerRequest Request;
    typedef ForcePowerResponse Response;
  };

}
#endif
