#include "CJoystick.h"

CJoystick::CJoystick(){
  a=b=y=x=false,
  stickL0=stickL1=stickR2=stickR5=0;}

CJoystick::~CJoystick(){}

void CJoystick::chatterCallback(const sensor_msgs::Joy& msg){
  //Assign Buttons
  a = msg.buttons[0]; //button a Takeoff
  b = msg.buttons[1]; //button b control
  y = msg.buttons[3]; //button y Landing
  x = msg.buttons[2]; //button x desactiva control
  RB= msg.buttons[5]; //button x desactiva control
  b5 = msg.buttons[4];
  b6 = msg.buttons[5];
  b7 = msg.buttons[6];
  b8 = msg.buttons[7];
  //Assign sticks
  //this-> JYaw = floor(msg.axes[0]*10)/10;
  this-> stickL0 = msg.axes[0]; //Left/Right Axis stick left
  this-> stickL1 = msg.axes[1]; //Up/Down Axis stick left
  this-> stickR2 = msg.axes[2]; //Left/Right Axis stick right
  this-> stickR5 = msg.axes[5];//Up/Down Axis stick right
}

void CJoystick::publishMessage(ros::Publisher *const H){
	std_msgs::Empty msg;
	H->publish(msg);
  	//geometry_msgs::Twist msg;
	//H->publish(msg);
}


