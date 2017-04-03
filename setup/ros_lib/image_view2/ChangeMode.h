#ifndef _ROS_SERVICE_ChangeMode_h
#define _ROS_SERVICE_ChangeMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace image_view2
{

static const char CHANGEMODE[] = "image_view2/ChangeMode";

  class ChangeModeRequest : public ros::Msg
  {
    public:
      typedef const char* _mode_type;
      _mode_type mode;

    ChangeModeRequest():
      mode("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_mode = strlen(this->mode);
      varToArr(outbuffer + offset, length_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->mode, length_mode);
      offset += length_mode;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_mode;
      arrToVar(length_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mode-1]=0;
      this->mode = (char *)(inbuffer + offset-1);
      offset += length_mode;
     return offset;
    }

    const char * getType(){ return CHANGEMODE; };
    const char * getMD5(){ return "e84dc3ad5dc323bb64f0aca01c2d1eef"; };

  };

  class ChangeModeResponse : public ros::Msg
  {
    public:

    ChangeModeResponse()
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

    const char * getType(){ return CHANGEMODE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ChangeMode {
    public:
    typedef ChangeModeRequest Request;
    typedef ChangeModeResponse Response;
  };

}
#endif
