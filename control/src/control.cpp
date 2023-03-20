#include "CJoystick.h"
#include "CJoystick.cpp"
#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
/*Tipo de mensaje personalizado para el steering y la velocidad
en el AutoMiNy*/
#include <autominy_msgs/NormalizedSteeringCommand.h>
#include <autominy_msgs/NormalizedSpeedCommand.h>

using namespace std;
bool tri,cir,x,cua;
float axis_1, axis_2, axis_3, axis_4;

int main (int argc, char **argv){
    ros::init(argc,argv,"control");
    ros::NodeHandle nh;

    ros::Publisher speed_pub = nh.advertise<autominy_msgs::NormalizedSpeedCommand>("/control/command/normalized_wanted_speed",1000);
    ros::Publisher steering_pub = nh.advertise<autominy_msgs::NormalizedSteeringCommand>("/control/command/normalized_wanted_steering",1000);

    autominy_msgs::NormalizedSpeedCommand msg_speed;  /*range 0-1000*/
    autominy_msgs::NormalizedSteeringCommand msg_steering; /*range -0.*/
    ros::Rate rate(20);
	
    CJoystick *H = new CJoystick();
	ros::Subscriber Joystick = nh.subscribe("joy",1000, &CJoystick::chatterCallback,H);

    ROS_INFO("Inicio del programa");

	while(ros::ok()){
		tri=H->a;
		cir=H->b;
		cua=H->y;
		x=H->x;
		axis_1=H->stickL0;
		axis_2=H->stickL1;
		axis_3=H->stickR2;
		axis_4=H->stickR5;
		//cout<<"| "<<tri<<" |"<<cir<<" "<<cua<<" |"<<x<<" |"<<axis_1<<" |"<<axis_2<<" |"<<axis_3<<" |"<<axis_4<<" |"<<endl;
		ROS_INFO("axis_1: %f | axis_2: %f | axis_3: %f | axis_4: %f",axis_1,axis_2,axis_3,axis_4);
		
		msg_speed.value = (axis_4/2);
		msg_steering.value = (axis_1);
		speed_pub.publish(msg_speed);
        steering_pub.publish(msg_steering);

		ros::spinOnce();
		rate.sleep();
	}

    delete H;
    return 0;
}
