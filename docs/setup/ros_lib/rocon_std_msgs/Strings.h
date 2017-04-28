#ifndef _ROS_rocon_std_msgs_Strings_h
#define _ROS_rocon_std_msgs_Strings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_std_msgs
{

  class Strings : public ros::Msg
  {
    public:
      enum { ROCON_VERSION = acdc };
      enum { URI_WILDCARD = * };
      enum { HW_PC = pc };
      enum { HW_TURTLEBOT2 = turtlebot2 };
      enum { HW_PR2 = pr2 };
      enum { HW_WAITERBOT = waiterbot };
      enum { HW_ROBOT_OTHER = robot_other };
      enum { HW_GALAXY = galaxy };
      enum { HW_MEGA = mega };
      enum { HW_NOTE3 = note3 };
      enum { HW_PHONE_OTHER = phone_other };
      enum { HW_XOOM = xoom };
      enum { HW_NOTE10 = note10 };
      enum { HW_TABLET_OTHER = tablet_other };
      enum { APPLICATION_FRAMEWORK_OTHER = application_framework_other };
      enum { APPLICATION_FRAMEWORK_OPROS = opros };
      enum { APPLICATION_FRAMEWORK_GROOVY = groovy };
      enum { APPLICATION_FRAMEWORK_HYDRO = hydro };
      enum { APPLICATION_FRAMEWORK_INDIGO = indigo };
      enum { APPLICATION_FRAMEWORK_ROS_OTHER = ros_other };
      enum { OS_OSX = osx };
      enum { OS_FREEBSD = freebsd };
      enum { OS_WINXP = winxp };
      enum { OS_WINDOWS7 = windows7 };
      enum { OS_ARCH = arch };
      enum { OS_DEBIAN = debian };
      enum { OS_FEDORA = fedora };
      enum { OS_GENTOO = gentoo };
      enum { OS_PRECISE = precise };
      enum { OS_QUANTAL = quantal };
      enum { OS_RARING = raring };
      enum { OS_SAUCY = saucy };
      enum { OS_HONEYCOMB = honeycomb };
      enum { OS_ICE_CREAM_SANDWICH = ice_cream_sandwich };
      enum { OS_JELLYBEAN = jellybean };
      enum { OS_KITKAT = kitkat };
      enum { OS_CHROME = chrome };
      enum { OS_FIREFOX = firefox };
      enum { OS_INTERNET_EXPLORER = internet_explorer };
      enum { OS_SAFARI = safari };
      enum { OS_OPERA = opera };
      enum { TAG_SERVICE = concert_service };
      enum { TAG_RAPP = rocon_app };
      enum { TAG_GAZEBO_ROBOT_TYPE = concert_gazebo };
      enum { TAG_SOFTWARE = software_farm };

    Strings()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/Strings"; };
    const char * getMD5(){ return "58fa1e54e6c0338b3faebae82a13e892"; };

  };

}
#endif