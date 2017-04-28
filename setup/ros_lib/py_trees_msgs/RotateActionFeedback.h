#ifndef _ROS_py_trees_msgs_RotateActionFeedback_h
#define _ROS_py_trees_msgs_RotateActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "py_trees_msgs/RotateFeedback.h"

namespace py_trees_msgs
{

  class RotateActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef py_trees_msgs::RotateFeedback _feedback_type;
      _feedback_type feedback;

    RotateActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "py_trees_msgs/RotateActionFeedback"; };
    const char * getMD5(){ return "344ed0daa120e01d5801edcb980cf618"; };

  };

}
#endif