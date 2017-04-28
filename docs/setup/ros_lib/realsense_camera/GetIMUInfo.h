#ifndef _ROS_SERVICE_GetIMUInfo_h
#define _ROS_SERVICE_GetIMUInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "realsense_camera/IMUInfo.h"

namespace realsense_camera
{

static const char GETIMUINFO[] = "realsense_camera/GetIMUInfo";

  class GetIMUInfoRequest : public ros::Msg
  {
    public:

    GetIMUInfoRequest()
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

    const char * getType(){ return GETIMUINFO; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetIMUInfoResponse : public ros::Msg
  {
    public:
      typedef realsense_camera::IMUInfo _accel_type;
      _accel_type accel;
      typedef realsense_camera::IMUInfo _gyro_type;
      _gyro_type gyro;

    GetIMUInfoResponse():
      accel(),
      gyro()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->accel.serialize(outbuffer + offset);
      offset += this->gyro.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->accel.deserialize(inbuffer + offset);
      offset += this->gyro.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETIMUINFO; };
    const char * getMD5(){ return "fcce7f85a63907f26a3912a7632e9630"; };

  };

  class GetIMUInfo {
    public:
    typedef GetIMUInfoRequest Request;
    typedef GetIMUInfoResponse Response;
  };

}
#endif
