#ifndef _ROS_SERVICE_GetSerial_h
#define _ROS_SERVICE_GetSerial_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openni2_camera
{

static const char GETSERIAL[] = "openni2_camera/GetSerial";

  class GetSerialRequest : public ros::Msg
  {
    public:

    GetSerialRequest()
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

    const char * getType(){ return GETSERIAL; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetSerialResponse : public ros::Msg
  {
    public:
      typedef const char* _serial_type;
      _serial_type serial;

    GetSerialResponse():
      serial("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_serial = strlen(this->serial);
      varToArr(outbuffer + offset, length_serial);
      offset += 4;
      memcpy(outbuffer + offset, this->serial, length_serial);
      offset += length_serial;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_serial;
      arrToVar(length_serial, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serial; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serial-1]=0;
      this->serial = (char *)(inbuffer + offset-1);
      offset += length_serial;
     return offset;
    }

    const char * getType(){ return GETSERIAL; };
    const char * getMD5(){ return "fca40cf463282a80db4e2037c8a61741"; };

  };

  class GetSerial {
    public:
    typedef GetSerialRequest Request;
    typedef GetSerialResponse Response;
  };

}
#endif
