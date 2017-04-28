#ifndef _ROS_rocon_service_pair_msgs_TestiesRequest_h
#define _ROS_rocon_service_pair_msgs_TestiesRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_service_pair_msgs
{

  class TestiesRequest : public ros::Msg
  {
    public:
      typedef const char* _data_type;
      _data_type data;

    TestiesRequest():
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

    const char * getType(){ return "rocon_service_pair_msgs/TestiesRequest"; };
    const char * getMD5(){ return "992ce8a1687cec8c8bd883ec73ca41d1"; };

  };

}
#endif