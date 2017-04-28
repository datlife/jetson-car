#ifndef _ROS_rocon_std_msgs_ConnectionsDiff_h
#define _ROS_rocon_std_msgs_ConnectionsDiff_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/Connection.h"

namespace rocon_std_msgs
{

  class ConnectionsDiff : public ros::Msg
  {
    public:
      uint32_t added_length;
      typedef rocon_std_msgs::Connection _added_type;
      _added_type st_added;
      _added_type * added;
      uint32_t lost_length;
      typedef rocon_std_msgs::Connection _lost_type;
      _lost_type st_lost;
      _lost_type * lost;

    ConnectionsDiff():
      added_length(0), added(NULL),
      lost_length(0), lost(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->added_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->added_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->added_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->added_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->added_length);
      for( uint32_t i = 0; i < added_length; i++){
      offset += this->added[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->lost_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lost_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lost_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lost_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lost_length);
      for( uint32_t i = 0; i < lost_length; i++){
      offset += this->lost[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t added_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      added_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      added_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      added_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->added_length);
      if(added_lengthT > added_length)
        this->added = (rocon_std_msgs::Connection*)realloc(this->added, added_lengthT * sizeof(rocon_std_msgs::Connection));
      added_length = added_lengthT;
      for( uint32_t i = 0; i < added_length; i++){
      offset += this->st_added.deserialize(inbuffer + offset);
        memcpy( &(this->added[i]), &(this->st_added), sizeof(rocon_std_msgs::Connection));
      }
      uint32_t lost_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lost_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lost_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lost_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lost_length);
      if(lost_lengthT > lost_length)
        this->lost = (rocon_std_msgs::Connection*)realloc(this->lost, lost_lengthT * sizeof(rocon_std_msgs::Connection));
      lost_length = lost_lengthT;
      for( uint32_t i = 0; i < lost_length; i++){
      offset += this->st_lost.deserialize(inbuffer + offset);
        memcpy( &(this->lost[i]), &(this->st_lost), sizeof(rocon_std_msgs::Connection));
      }
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/ConnectionsDiff"; };
    const char * getMD5(){ return "19f9e3bef1153b4bc619ec3d21b94718"; };

  };

}
#endif