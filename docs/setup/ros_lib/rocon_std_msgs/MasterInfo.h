#ifndef _ROS_rocon_std_msgs_MasterInfo_h
#define _ROS_rocon_std_msgs_MasterInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/Icon.h"

namespace rocon_std_msgs
{

  class MasterInfo : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _rocon_uri_type;
      _rocon_uri_type rocon_uri;
      typedef const char* _description_type;
      _description_type description;
      typedef rocon_std_msgs::Icon _icon_type;
      _icon_type icon;
      typedef const char* _version_type;
      _version_type version;

    MasterInfo():
      name(""),
      rocon_uri(""),
      description(""),
      icon(),
      version("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_rocon_uri = strlen(this->rocon_uri);
      varToArr(outbuffer + offset, length_rocon_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->rocon_uri, length_rocon_uri);
      offset += length_rocon_uri;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      offset += this->icon.serialize(outbuffer + offset);
      uint32_t length_version = strlen(this->version);
      varToArr(outbuffer + offset, length_version);
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_rocon_uri;
      arrToVar(length_rocon_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rocon_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rocon_uri-1]=0;
      this->rocon_uri = (char *)(inbuffer + offset-1);
      offset += length_rocon_uri;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      offset += this->icon.deserialize(inbuffer + offset);
      uint32_t length_version;
      arrToVar(length_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/MasterInfo"; };
    const char * getMD5(){ return "e85613ae2e3faade6b77d94b4e0bf4bf"; };

  };

}
#endif