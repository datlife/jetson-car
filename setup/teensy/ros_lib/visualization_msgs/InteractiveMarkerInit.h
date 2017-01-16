#ifndef _ROS_visualization_msgs_InteractiveMarkerInit_h
#define _ROS_visualization_msgs_InteractiveMarkerInit_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "visualization_msgs/InteractiveMarker.h"

namespace visualization_msgs
{

  class InteractiveMarkerInit : public ros::Msg
  {
    public:
      const char* server_id;
      uint64_t seq_num;
      uint8_t markers_length;
      visualization_msgs::InteractiveMarker st_markers;
      visualization_msgs::InteractiveMarker * markers;

    InteractiveMarkerInit():
      server_id(""),
      seq_num(0),
      markers_length(0), markers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_server_id = strlen(this->server_id);
      memcpy(outbuffer + offset, &length_server_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->server_id, length_server_id);
      offset += length_server_id;
      *(outbuffer + offset + 0) = (this->seq_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seq_num >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seq_num >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seq_num >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->seq_num >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->seq_num >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->seq_num >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->seq_num >> (8 * 7)) & 0xFF;
      offset += sizeof(this->seq_num);
      *(outbuffer + offset++) = markers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_server_id;
      memcpy(&length_server_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_server_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_server_id-1]=0;
      this->server_id = (char *)(inbuffer + offset-1);
      offset += length_server_id;
      this->seq_num =  ((uint64_t) (*(inbuffer + offset)));
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->seq_num);
      uint8_t markers_lengthT = *(inbuffer + offset++);
      if(markers_lengthT > markers_length)
        this->markers = (visualization_msgs::InteractiveMarker*)realloc(this->markers, markers_lengthT * sizeof(visualization_msgs::InteractiveMarker));
      offset += 3;
      markers_length = markers_lengthT;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(visualization_msgs::InteractiveMarker));
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/InteractiveMarkerInit"; };
    const char * getMD5(){ return "aa2f1dcea79533d1710675195653028d"; };

  };

}
#endif