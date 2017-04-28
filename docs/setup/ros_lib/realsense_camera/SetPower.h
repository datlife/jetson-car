#ifndef _ROS_SERVICE_SetPower_h
#define _ROS_SERVICE_SetPower_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace realsense_camera
{

static const char SETPOWER[] = "realsense_camera/SetPower";

  class SetPowerRequest : public ros::Msg
  {
    public:
      typedef bool _power_on_type;
      _power_on_type power_on;

    SetPowerRequest():
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

    const char * getType(){ return SETPOWER; };
    const char * getMD5(){ return "0a07d78fa0214ec8d773e5045aa5087a"; };

  };

  class SetPowerResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetPowerResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return SETPOWER; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetPower {
    public:
    typedef SetPowerRequest Request;
    typedef SetPowerResponse Response;
  };

}
#endif
