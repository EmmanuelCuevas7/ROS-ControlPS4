#ifndef CJoystick_H
#define CJoystick_H

#include "ros/ros.h"
#include <sensor_msgs/Joy.h>
#include <std_msgs/Empty.h>

using std::string;

class CJoystick{
	public:
		CJoystick();  	/*Contrusctor*/
		~CJoystick();  	/*Destructor*/
		void chatterCallback(const sensor_msgs::Joy& msg); //suscribe to function of the joystick
		void publishMessage(ros::Publisher *const); //publish information to other topic
		//-------------------Botones-----------------------------//
		bool a,b,y,x;
		bool RB,b5,b6,b7,b8;
		float stickL0;
		float stickL1;
		float stickR2;
		float stickR5;
};
#endif

