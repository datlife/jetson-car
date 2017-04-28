#ifndef _ROS_rocon_service_pair_msgs_TestiesPair_h
#define _ROS_rocon_service_pair_msgs_TestiesPair_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_service_pair_msgs/TestiesPairRequest.h"
#include "rocon_service_pair_msgs/TestiesPairResponse.h"

namespace rocon_service_pair_msgs
{

  class TestiesPair : public ros::Msg
  {
    public:
      typedef rocon_service_pair_msgs::TestiesPairRequest _pair_request_type;
      _pair_request_type pair_request;
      typedef rocon_service_pair_msgs::TestiesPairResponse _pair_response_type;
      _pair_response_type pair_response;

    TestiesPair():
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

    const char * getType(){ return "rocon_service_pair_msgs/TestiesPair"; };
    const char * getMD5(){ return "7b5cb9b4ccdb74840ce04ea92d2a141d"; };

  };

}
#endif