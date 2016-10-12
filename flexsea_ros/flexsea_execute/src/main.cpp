#include "main.h"
#include "Driver_Node.h"

//  --------- MAIN -----------------------------------
int main(int argc, char **argv){

	// Init ROS
	ros::init(argc, argv, "driver");
	Driver_Node driver_node;
	ros::spin();
	
	return 0;
}
