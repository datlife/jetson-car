#ifndef _ROS_SERVICE_CloseBlackboardWatcher_h
#define _ROS_SERVICE_CloseBlackboardWatcher_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace py_trees_msgs
{

static const char CLOSEBLACKBOARDWATCHER[] = "py_trees_msgs/CloseBlackboardWatcher";

  class CloseBlackboardWatcherRequest : public ros::Msg
  {
    public:
      typedef const char* _topic_name_type;
      _topic_name_type topic_name;

    CloseBlackboardWatcherRequest():
      topic_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic_name = strlen(this->topic_name);
      varToArr(outbuffer + offset, length_topic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_topic_name);
      offset += length_topic_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic_name;
      arrToVar(length_topic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic_name-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
      offset += length_topic_name;
     return offset;
    }

    const char * getType(){ return CLOSEBLACKBOARDWATCHER; };
    const char * getMD5(){ return "b38cc2f19f45368c2db7867751ce95a9"; };

  };

  class CloseBlackboardWatcherResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    CloseBlackboardWatcherResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return CLOSEBLACKBOARDWATCHER; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class CloseBlackboardWatcher {
    public:
    typedef CloseBlackboardWatcherRequest Request;
    typedef CloseBlackboardWatcherResponse Response;
  };

}
#endif
