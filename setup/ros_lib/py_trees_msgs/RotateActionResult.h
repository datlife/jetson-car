#ifndef _ROS_py_trees_msgs_RotateActionResult_h
#define _ROS_py_trees_msgs_RotateActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "py_trees_msgs/RotateResult.h"

namespace py_trees_msgs
{

  class RotateActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef py_trees_msgs::RotateResult _result_type;
      _result_type result;

    RotateActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "py_trees_msgs/RotateActionResult"; };
    const char * getMD5(){ return "4eda63f75c02197dafd2a62a0d413ab0"; };

  };

}
#endif