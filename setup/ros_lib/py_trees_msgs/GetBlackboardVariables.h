#ifndef _ROS_SERVICE_GetBlackboardVariables_h
#define _ROS_SERVICE_GetBlackboardVariables_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace py_trees_msgs
{

static const char GETBLACKBOARDVARIABLES[] = "py_trees_msgs/GetBlackboardVariables";

  class GetBlackboardVariablesRequest : public ros::Msg
  {
    public:

    GetBlackboardVariablesRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETBLACKBOARDVARIABLES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetBlackboardVariablesResponse : public ros::Msg
  {
    public:
      uint32_t variables_length;
      typedef char* _variables_type;
      _variables_type st_variables;
      _variables_type * variables;

    GetBlackboardVariablesResponse():
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

    const char * getType(){ return GETBLACKBOARDVARIABLES; };
    const char * getMD5(){ return "8f184382c36d538fab610317191b119e"; };

  };

  class GetBlackboardVariables {
    public:
    typedef GetBlackboardVariablesRequest Request;
    typedef GetBlackboardVariablesResponse Response;
  };

}
#endif
