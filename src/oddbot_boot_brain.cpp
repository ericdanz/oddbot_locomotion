# include "oddbot_boot/oddbot_boot_brain.h"

oddbot_boot_brain::oddbot_boot_brain(){
  //the main node handle
  ros::NodeHandle nh;

  //grab the parameters
  //ros::NodeHandle private_node_handle_("~");
  //private_node_handle_.param<double>("param", variable, value);
  
  //initialize the publishers and subscribers
  stop_pub = nh.advertise<oddbot_msgs::OddbotBootStop>("oddbot/boot_stop", 1000);
  boot_sub = nh.subscribe("oddbot/boot", 1000, &oddbot_boot_brain::get_info, this);
}

void oddbot_boot_brain::get_info(const oddbot_boot::OddbotBoot::ConstPtr& boot_msg){
	
	oddbot_msgs::OddbotBootStop obs_msg;
	obs_msg.name = boot_msg.name
	stop_pub.publish(obs_msg);
	
}

int main(int argc, char** argv){
  
  ros::init(argc, argv, "oddbot_boot_brain");

  oddbot_boot_brain obb = oddbot_boot_brain();
  
  ROS_INFO("oddbot boot brain node started!");	

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}