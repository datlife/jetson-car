#ifndef _ROS_rocon_service_pair_msgs_TestiesPairRequest_h
#define _ROS_rocon_service_pair_msgs_TestiesPairRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "rocon_service_pair_msgs/TestiesRequest.h"

namespace rocon_service_pair_msgs
{

  class TestiesPairRequest : public ros::Msg
  {
    public:
      typedef uuid_msgs::UniqueID _id_type;
      _id_type id;
      typedef rocon_service_pair_msgs::TestiesRequest _request_type;
      _request_type request;

    TestiesPairRequest():
      id(),
      request()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
      offset += this->request.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->request.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rocon_service_pair_msgs/TestiesPairRequest"; };
    const char * getMD5(){ return "71ec95e384ce52aa32491f3b69a62027"; };

  };

}
#endif