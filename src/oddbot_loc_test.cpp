#include "oddbot_locomotion/oddbot_loc_test.h"

oddbot_loc_test::oddbot_loc_test(){
	//subscribe to oddbot_boot
	//publish to oddbot_boot_stop
  ros::NodeHandle nodeHandle;
  od_pub = nodeHandle.advertise<nav_msgs::Odometry>("odom", 1000);
  vel_sub = nodeHandle.subscribe("cmd_vel", 1000, &oddbot_loc_test::get_info, this);
  subnet = get_subnet();
}
// Callback message
void oddbot_loc_test::get_info(const geometry_msgs::Twist::ConstPtr& vel_msg){
	
	ROS_INFO("Getting this forward vel: %d",vel_msg.linear.x);
  }
}

void oddbot_loc_test::send_od(){
  // Set the odom message
  od_msg.twist.twist.linear.x= 2;
	// Publish the odom message
  od_pub.publish(od_msg);
}


int main(int argc, char** argv){
	
	//stop when stop running flag is true
	ros::init(argc, argv, "oddbot_loc_test");

  oddbot_loc_test lt = oddbot_loc_test();
  
  ROS_INFO("oddbot boot module node started!");  

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    module.send_od();
    ros::spinOnce();
    loop_rate.sleep();
  }
  
  return 0;
}
