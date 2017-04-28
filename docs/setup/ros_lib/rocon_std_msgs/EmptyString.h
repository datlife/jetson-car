#ifndef _ROS_SERVICE_EmptyString_h
#define _ROS_SERVICE_EmptyString_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_std_msgs
{

static const char EMPTYSTRING[] = "rocon_std_msgs/EmptyString";

  class EmptyStringRequest : public ros::Msg
  {
    public:

    EmptyStringRequest()
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

    const char * getType(){ return EMPTYSTRING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class EmptyStringResponse : public ros::Msg
  {
    public:
      typedef const char* _data_type;
      _data_type data;

    EmptyStringResponse():
      data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_data = strlen(this->data);
      varToArr(outbuffer + offset, length_data);
      offset += 4;
      memcpy(outbuffer + offset, this->data, length_data);
      offset += length_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_data;
      arrToVar(length_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_data-1]=0;
      this->data = (char *)(inbuffer + offset-1);
      offset += length_data;
     return offset;
    }

    const char * getType(){ return EMPTYSTRING; };
    const char * getMD5(){ return "992ce8a1687cec8c8bd883ec73ca41d1"; };

  };

  class EmptyString {
    public:
    typedef EmptyStringRequest Request;
    typedef EmptyStringResponse Response;
  };

}
#endif
