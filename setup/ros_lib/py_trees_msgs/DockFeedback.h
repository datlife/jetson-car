#ifndef _ROS_py_trees_msgs_DockFeedback_h
#define _ROS_py_trees_msgs_DockFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace py_trees_msgs
{

  class DockFeedback : public ros::Msg
  {
    public:
      typedef float _percentage_completed_type;
      _percentage_completed_type percentage_completed;

    DockFeedback():
      percentage_completed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_percentage_completed;
      u_percentage_completed.real = this->percentage_completed;
      *(outbuffer + offset + 0) = (u_percentage_completed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percentage_completed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percentage_completed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percentage_completed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percentage_completed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_percentage_completed;
      u_percentage_completed.base = 0;
      u_percentage_completed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percentage_completed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percentage_completed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percentage_completed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percentage_completed = u_percentage_completed.real;
      offset += sizeof(this->percentage_completed);
     return offset;
    }

    const char * getType(){ return "py_trees_msgs/DockFeedback"; };
    const char * getMD5(){ return "26e2c7154b190781742892deccb6c8f0"; };

  };

}
#endif