#ifndef _ROS_py_trees_msgs_DockAction_h
#define _ROS_py_trees_msgs_DockAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "py_trees_msgs/DockActionGoal.h"
#include "py_trees_msgs/DockActionResult.h"
#include "py_trees_msgs/DockActionFeedback.h"

namespace py_trees_msgs
{

  class DockAction : public ros::Msg
  {
    public:
      typedef py_trees_msgs::DockActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef py_trees_msgs::DockActionResult _action_result_type;
      _action_result_type action_result;
      typedef py_trees_msgs::DockActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    DockAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "py_trees_msgs/DockAction"; };
    const char * getMD5(){ return "1487f2ccdee1636e3fa5ee088040ee3a"; };

  };

}
#endif