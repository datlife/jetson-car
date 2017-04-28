#ifndef _ROS_rocon_std_msgs_StringArray_h
#define _ROS_rocon_std_msgs_StringArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_std_msgs
{

  class StringArray : public ros::Msg
  {
    public:
      uint32_t strings_length;
      typedef char* _strings_type;
      _strings_type st_strings;
      _strings_type * strings;

    StringArray():
      strings_length(0), strings(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->strings_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->strings_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->strings_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->strings_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strings_length);
      for( uint32_t i = 0; i < strings_length; i++){
      uint32_t length_stringsi = strlen(this->strings[i]);
      varToArr(outbuffer + offset, length_stringsi);
      offset += 4;
      memcpy(outbuffer + offset, this->strings[i], length_stringsi);
      offset += length_stringsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t strings_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      strings_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      strings_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      strings_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->strings_length);
      if(strings_lengthT > strings_length)
        this->strings = (char**)realloc(this->strings, strings_lengthT * sizeof(char*));
      strings_length = strings_lengthT;
      for( uint32_t i = 0; i < strings_length; i++){
      uint32_t length_st_strings;
      arrToVar(length_st_strings, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_strings; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_strings-1]=0;
      this->st_strings = (char *)(inbuffer + offset-1);
      offset += length_st_strings;
        memcpy( &(this->strings[i]), &(this->st_strings), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/StringArray"; };
    const char * getMD5(){ return "51789d20146e565223d0963361aecda1"; };

  };

}
#endif