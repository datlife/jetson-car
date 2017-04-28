#ifndef _ROS_rocon_std_msgs_ConnectionsList_h
#define _ROS_rocon_std_msgs_ConnectionsList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/Connection.h"

namespace rocon_std_msgs
{

  class ConnectionsList : public ros::Msg
  {
    public:
      uint32_t connections_length;
      typedef rocon_std_msgs::Connection _connections_type;
      _connections_type st_connections;
      _connections_type * connections;

    ConnectionsList():
      connections_length(0), connections(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->connections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->connections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->connections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->connections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->connections_length);
      for( uint32_t i = 0; i < connections_length; i++){
      offset += this->connections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t connections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      connections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      connections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      connections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->connections_length);
      if(connections_lengthT > connections_length)
        this->connections = (rocon_std_msgs::Connection*)realloc(this->connections, connections_lengthT * sizeof(rocon_std_msgs::Connection));
      connections_length = connections_lengthT;
      for( uint32_t i = 0; i < connections_length; i++){
      offset += this->st_connections.deserialize(inbuffer + offset);
        memcpy( &(this->connections[i]), &(this->st_connections), sizeof(rocon_std_msgs::Connection));
      }
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/ConnectionsList"; };
    const char * getMD5(){ return "672d6ad69b684884f8fb6f4acedbd39f"; };

  };

}
#endif