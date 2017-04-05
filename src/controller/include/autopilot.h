//
// Created by nvidia on 4/4/17.
//

#ifndef CAR_AUTOPILOT_H
#define CAR_AUTOPILOT_H

class Pilot{
    public:
        // Default Constructor
        Pilot();
    private:
        enum {OFF, ON};
        ros::NodeHandle node_handle_;
        ros::Publisher  car_pub_;
        ros::Subscriber joy_sub_;
        ros::Subscriber vision_sub;

        void 		    joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
        void 		    visionCallback(const sensor_msgs::Image::ConstPtr& image);
};
#endif //CAR_AUTOPILOT_H
