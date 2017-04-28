#ifndef _ROS_py_trees_msgs_RotateFeedback_h
#define _ROS_py_trees_msgs_RotateFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace py_trees_msgs
{

  class RotateFeedback : public ros::Msg
  {
    public:
      typedef float _percentage_completed_type;
      _percentage_completed_type percentage_completed;
      typedef float _angle_rotated_type;
      _angle_rotated_type angle_rotated;

    RotateFeedback():
      percentage_completed(0),
      angle_rotated(0)
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
      union {
        float real;
        uint32_t base;
      } u_angle_rotated;
      u_angle_rotated.real = this->angle_rotated;
      *(outbuffer + offset + 0) = (u_angle_rotated.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_rotated.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_rotated.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_rotated.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_rotated);
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
      union {
        float real;
        uint32_t base;
      } u_angle_rotated;
      u_angle_rotated.base = 0;
      u_angle_rotated.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_rotated.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_rotated.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_rotated.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_rotated = u_angle_rotated.real;
      offset += sizeof(this->angle_rotated);
     return offset;
    }

    const char * getType(){ return "py_trees_msgs/RotateFeedback"; };
    const char * getMD5(){ return "f1088922e17b4a9f4319356ac8d99645"; };

  };

}
#endif