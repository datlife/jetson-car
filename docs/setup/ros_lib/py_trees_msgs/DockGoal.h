#ifndef _ROS_py_trees_msgs_DockGoal_h
#define _ROS_py_trees_msgs_DockGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace py_trees_msgs
{

  class DockGoal : public ros::Msg
  {
    public:
      typedef bool _dock_type;
      _dock_type dock;

    DockGoal():
      dock(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_dock;
      u_dock.real = this->dock;
      *(outbuffer + offset + 0) = (u_dock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dock);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_dock;
      u_dock.base = 0;
      u_dock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dock = u_dock.real;
      offset += sizeof(this->dock);
     return offset;
    }

    const char * getType(){ return "py_trees_msgs/DockGoal"; };
    const char * getMD5(){ return "035360b0bb03f7f742a0b2d734a3a660"; };

  };

}
#endif