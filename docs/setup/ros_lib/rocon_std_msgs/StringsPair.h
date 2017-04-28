#ifndef _ROS_rocon_std_msgs_StringsPair_h
#define _ROS_rocon_std_msgs_StringsPair_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/StringsPairRequest.h"
#include "rocon_std_msgs/StringsPairResponse.h"

namespace rocon_std_msgs
{

  class StringsPair : public ros::Msg
  {
    public:
      typedef rocon_std_msgs::StringsPairRequest _pair_request_type;
      _pair_request_type pair_request;
      typedef rocon_std_msgs::StringsPairResponse _pair_response_type;
      _pair_response_type pair_response;

    StringsPair():
      pair_request(),
      pair_response()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pair_request.serialize(outbuffer + offset);
      offset += this->pair_response.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pair_request.deserialize(inbuffer + offset);
      offset += this->pair_response.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/StringsPair"; };
    const char * getMD5(){ return "d41c9071bd514be249c417a13ec83e65"; };

  };

}
#endif