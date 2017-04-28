#ifndef _ROS_py_trees_msgs_BehaviourTree_h
#define _ROS_py_trees_msgs_BehaviourTree_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "py_trees_msgs/Behaviour.h"

namespace py_trees_msgs
{

  class BehaviourTree : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t behaviours_length;
      typedef py_trees_msgs::Behaviour _behaviours_type;
      _behaviours_type st_behaviours;
      _behaviours_type * behaviours;

    BehaviourTree():
      header(),
      behaviours_length(0), behaviours(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->behaviours_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->behaviours_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->behaviours_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->behaviours_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->behaviours_length);
      for( uint32_t i = 0; i < behaviours_length; i++){
      offset += this->behaviours[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t behaviours_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      behaviours_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      behaviours_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      behaviours_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->behaviours_length);
      if(behaviours_lengthT > behaviours_length)
        this->behaviours = (py_trees_msgs::Behaviour*)realloc(this->behaviours, behaviours_lengthT * sizeof(py_trees_msgs::Behaviour));
      behaviours_length = behaviours_lengthT;
      for( uint32_t i = 0; i < behaviours_length; i++){
      offset += this->st_behaviours.deserialize(inbuffer + offset);
        memcpy( &(this->behaviours[i]), &(this->st_behaviours), sizeof(py_trees_msgs::Behaviour));
      }
     return offset;
    }

    const char * getType(){ return "py_trees_msgs/BehaviourTree"; };
    const char * getMD5(){ return "239023f5538cba34a10a3a5cd6610fa0"; };

  };

}
#endif