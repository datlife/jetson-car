#ifndef _ROS_rocon_std_msgs_Connection_h
#define _ROS_rocon_std_msgs_Connection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_std_msgs
{

  class Connection : public ros::Msg
  {
    public:
      typedef const char* _type_type;
      _type_type type;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _node_type;
      _node_type node;
      typedef const char* _type_msg_type;
      _type_msg_type type_msg;
      typedef const char* _type_info_type;
      _type_info_type type_info;
      typedef const char* _xmlrpc_uri_type;
      _xmlrpc_uri_type xmlrpc_uri;
      enum { PUBLISHER =  publisher };
      enum { SUBSCRIBER =  subscriber };
      enum { SERVICE =  service };
      enum { ACTION_CLIENT =  action_client };
      enum { ACTION_SERVER =  action_server };
      enum { INVALID =  invalid };

    Connection():
      type(""),
      name(""),
      node(""),
      type_msg(""),
      type_info(""),
      xmlrpc_uri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_node = strlen(this->node);
      varToArr(outbuffer + offset, length_node);
      offset += 4;
      memcpy(outbuffer + offset, this->node, length_node);
      offset += length_node;
      uint32_t length_type_msg = strlen(this->type_msg);
      varToArr(outbuffer + offset, length_type_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->type_msg, length_type_msg);
      offset += length_type_msg;
      uint32_t length_type_info = strlen(this->type_info);
      varToArr(outbuffer + offset, length_type_info);
      offset += 4;
      memcpy(outbuffer + offset, this->type_info, length_type_info);
      offset += length_type_info;
      uint32_t length_xmlrpc_uri = strlen(this->xmlrpc_uri);
      varToArr(outbuffer + offset, length_xmlrpc_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->xmlrpc_uri, length_xmlrpc_uri);
      offset += length_xmlrpc_uri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_node;
      arrToVar(length_node, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node-1]=0;
      this->node = (char *)(inbuffer + offset-1);
      offset += length_node;
      uint32_t length_type_msg;
      arrToVar(length_type_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type_msg-1]=0;
      this->type_msg = (char *)(inbuffer + offset-1);
      offset += length_type_msg;
      uint32_t length_type_info;
      arrToVar(length_type_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type_info-1]=0;
      this->type_info = (char *)(inbuffer + offset-1);
      offset += length_type_info;
      uint32_t length_xmlrpc_uri;
      arrToVar(length_xmlrpc_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_xmlrpc_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_xmlrpc_uri-1]=0;
      this->xmlrpc_uri = (char *)(inbuffer + offset-1);
      offset += length_xmlrpc_uri;
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/Connection"; };
    const char * getMD5(){ return "0dee991006513320090e2ee648136101"; };

  };

}
#endif