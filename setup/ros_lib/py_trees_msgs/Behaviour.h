#ifndef _ROS_py_trees_msgs_Behaviour_h
#define _ROS_py_trees_msgs_Behaviour_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"

namespace py_trees_msgs
{

  class Behaviour : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _class_name_type;
      _class_name_type class_name;
      typedef uuid_msgs::UniqueID _own_id_type;
      _own_id_type own_id;
      typedef uuid_msgs::UniqueID _parent_id_type;
      _parent_id_type parent_id;
      typedef uuid_msgs::UniqueID _tip_id_type;
      _tip_id_type tip_id;
      uint32_t child_ids_length;
      typedef uuid_msgs::UniqueID _child_ids_type;
      _child_ids_type st_child_ids;
      _child_ids_type * child_ids;
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _blackbox_level_type;
      _blackbox_level_type blackbox_level;
      typedef uint8_t _status_type;
      _status_type status;
      typedef const char* _message_type;
      _message_type message;
      typedef bool _is_active_type;
      _is_active_type is_active;
      enum { INVALID =  1 };
      enum { RUNNING =  2 };
      enum { SUCCESS =  3 };
      enum { FAILURE =  4 };
      enum { UNKNOWN_TYPE =  0 };
      enum { BEHAVIOUR =  1 };
      enum { SEQUENCE =  2 };
      enum { SELECTOR =  3 };
      enum { PARALLEL =  4 };
      enum { CHOOSER =  5 };
      enum { BLACKBOX_LEVEL_DETAIL =  1 };
      enum { BLACKBOX_LEVEL_COMPONENT =  2 };
      enum { BLACKBOX_LEVEL_BIG_PICTURE =  3 };
      enum { BLACKBOX_LEVEL_NOT_A_BLACKBOX =  4 };

    Behaviour():
      name(""),
      class_name(""),
      own_id(),
      parent_id(),
      tip_id(),
      child_ids_length(0), child_ids(NULL),
      type(0),
      blackbox_level(0),
      status(0),
      message(""),
      is_active(0)
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
      uint32_t length_class_name = strlen(this->class_name);
      varToArr(outbuffer + offset, length_class_name);
      offset += 4;
      memcpy(outbuffer + offset, this->class_name, length_class_name);
      offset += length_class_name;
      offset += this->own_id.serialize(outbuffer + offset);
      offset += this->parent_id.serialize(outbuffer + offset);
      offset += this->tip_id.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->child_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->child_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->child_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->child_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->child_ids_length);
      for( uint32_t i = 0; i < child_ids_length; i++){
      offset += this->child_ids[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->blackbox_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blackbox_level);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_is_active;
      u_is_active.real = this->is_active;
      *(outbuffer + offset + 0) = (u_is_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_active);
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
      uint32_t length_class_name;
      arrToVar(length_class_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_class_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_class_name-1]=0;
      this->class_name = (char *)(inbuffer + offset-1);
      offset += length_class_name;
      offset += this->own_id.deserialize(inbuffer + offset);
      offset += this->parent_id.deserialize(inbuffer + offset);
      offset += this->tip_id.deserialize(inbuffer + offset);
      uint32_t child_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      child_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      child_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      child_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->child_ids_length);
      if(child_ids_lengthT > child_ids_length)
        this->child_ids = (uuid_msgs::UniqueID*)realloc(this->child_ids, child_ids_lengthT * sizeof(uuid_msgs::UniqueID));
      child_ids_length = child_ids_lengthT;
      for( uint32_t i = 0; i < child_ids_length; i++){
      offset += this->st_child_ids.deserialize(inbuffer + offset);
        memcpy( &(this->child_ids[i]), &(this->st_child_ids), sizeof(uuid_msgs::UniqueID));
      }
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->blackbox_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->blackbox_level);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_is_active;
      u_is_active.base = 0;
      u_is_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_active = u_is_active.real;
      offset += sizeof(this->is_active);
     return offset;
    }

    const char * getType(){ return "py_trees_msgs/Behaviour"; };
    const char * getMD5(){ return "88ddda148fc81f5dc402f56e3e333222"; };

  };

}
#endif