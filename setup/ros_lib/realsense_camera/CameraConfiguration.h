#ifndef _ROS_SERVICE_CameraConfiguration_h
#define _ROS_SERVICE_CameraConfiguration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace realsense_camera
{

static const char CAMERACONFIGURATION[] = "realsense_camera/CameraConfiguration";

  class CameraConfigurationRequest : public ros::Msg
  {
    public:

    CameraConfigurationRequest()
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

    const char * getType(){ return CAMERACONFIGURATION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class CameraConfigurationResponse : public ros::Msg
  {
    public:
      typedef const char* _configuration_str_type;
      _configuration_str_type configuration_str;

    CameraConfigurationResponse():
      configuration_str("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_configuration_str = strlen(this->configuration_str);
      varToArr(outbuffer + offset, length_configuration_str);
      offset += 4;
      memcpy(outbuffer + offset, this->configuration_str, length_configuration_str);
      offset += length_configuration_str;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_configuration_str;
      arrToVar(length_configuration_str, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_configuration_str; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_configuration_str-1]=0;
      this->configuration_str = (char *)(inbuffer + offset-1);
      offset += length_configuration_str;
     return offset;
    }

    const char * getType(){ return CAMERACONFIGURATION; };
    const char * getMD5(){ return "2c284890309b239ca006a289ca29b4d1"; };

  };

  class CameraConfiguration {
    public:
    typedef CameraConfigurationRequest Request;
    typedef CameraConfigurationResponse Response;
  };

}
#endif
