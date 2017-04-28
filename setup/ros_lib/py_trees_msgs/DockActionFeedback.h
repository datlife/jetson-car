#ifndef _ROS_py_trees_msgs_DockActionFeedback_h
#define _ROS_py_trees_msgs_DockActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "py_trees_msgs/DockFeedback.h"

namespace py_trees_msgs
{

  class DockActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef py_trees_msgs::DockFeedback _feedback_type;
      _feedback_type feedback;

    DockActionFeedback():
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

    const char * getType(){ return "py_trees_msgs/DockActionFeedback"; };
    const char * getMD5(){ return "2ff213e56f8a13eff9119a87d46f6e06"; };

  };

}
#endif