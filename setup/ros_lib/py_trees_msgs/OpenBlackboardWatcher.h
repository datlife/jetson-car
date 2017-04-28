#ifndef _ROS_SERVICE_OpenBlackboardWatcher_h
#define _ROS_SERVICE_OpenBlackboardWatcher_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace py_trees_msgs
{

static const char OPENBLACKBOARDWATCHER[] = "py_trees_msgs/OpenBlackboardWatcher";

  class OpenBlackboardWatcherRequest : public ros::Msg
  {
    public:
      uint32_t variables_length;
      typedef char* _variables_type;
      _variables_type st_variables;
      _variables_type * variables;

    OpenBlackboardWatcherRequest():
      variables_length(0), variables(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->variables_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->variables_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->variables_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->variables_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variables_length);
      for( uint32_t i = 0; i < variables_length; i++){
      uint32_t length_variablesi = strlen(this->variables[i]);
      varToArr(outbuffer + offset, length_variablesi);
      offset += 4;
      memcpy(outbuffer + offset, this->variables[i], length_variablesi);
      offset += length_variablesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t variables_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      variables_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      variables_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      variables_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->variables_length);
      if(variables_lengthT > variables_length)
        this->variables = (char**)realloc(this->variables, variables_lengthT * sizeof(char*));
      variables_length = variables_lengthT;
      for( uint32_t i = 0; i < variables_length; i++){
      uint32_t length_st_variables;
      arrToVar(length_st_variables, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_variables; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_variables-1]=0;
      this->st_variables = (char *)(inbuffer + offset-1);
      offset += length_st_variables;
        memcpy( &(this->variables[i]), &(this->st_variables), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return OPENBLACKBOARDWATCHER; };
    const char * getMD5(){ return "8f184382c36d538fab610317191b119e"; };

  };

  class OpenBlackboardWatcherResponse : public ros::Msg
  {
    public:
      typedef const char* _topic_type;
      _topic_type topic;

    OpenBlackboardWatcherResponse():
      topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
     return offset;
    }

    const char * getType(){ return OPENBLACKBOARDWATCHER; };
    const char * getMD5(){ return "d8f94bae31b356b24d0427f80426d0c3"; };

  };

  class OpenBlackboardWatcher {
    public:
    typedef OpenBlackboardWatcherRequest Request;
    typedef OpenBlackboardWatcherResponse Response;
  };

}
#endif
