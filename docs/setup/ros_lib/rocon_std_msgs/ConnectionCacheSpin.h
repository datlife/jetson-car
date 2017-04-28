#ifndef _ROS_rocon_std_msgs_ConnectionCacheSpin_h
#define _ROS_rocon_std_msgs_ConnectionCacheSpin_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_std_msgs
{

  class ConnectionCacheSpin : public ros::Msg
  {
    public:
      typedef float _spin_freq_type;
      _spin_freq_type spin_freq;
      typedef float _spin_timer_type;
      _spin_timer_type spin_timer;

    ConnectionCacheSpin():
      spin_freq(0),
      spin_timer(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_spin_freq;
      u_spin_freq.real = this->spin_freq;
      *(outbuffer + offset + 0) = (u_spin_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_spin_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_spin_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_spin_freq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->spin_freq);
      union {
        float real;
        uint32_t base;
      } u_spin_timer;
      u_spin_timer.real = this->spin_timer;
      *(outbuffer + offset + 0) = (u_spin_timer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_spin_timer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_spin_timer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_spin_timer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->spin_timer);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_spin_freq;
      u_spin_freq.base = 0;
      u_spin_freq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_spin_freq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_spin_freq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_spin_freq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->spin_freq = u_spin_freq.real;
      offset += sizeof(this->spin_freq);
      union {
        float real;
        uint32_t base;
      } u_spin_timer;
      u_spin_timer.base = 0;
      u_spin_timer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_spin_timer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_spin_timer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_spin_timer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->spin_timer = u_spin_timer.real;
      offset += sizeof(this->spin_timer);
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/ConnectionCacheSpin"; };
    const char * getMD5(){ return "b6c0b0ddb1d2a2de9918dc5f6d87680a"; };

  };

}
#endif