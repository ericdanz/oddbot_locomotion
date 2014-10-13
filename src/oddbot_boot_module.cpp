#include "oddbot_boot/oddbot_boot_module.h"

oddbot_boot_module::oddbot_boot_module(){
	//subscribe to oddbot_boot
	//publish to oddbot_boot_stop
  ros::NodeHandle nodeHandle;
  boot_pub = nodeHandle.advertise<oddbot_msgs::OddbotBoot>("boot", 1000);
  stop_sub = nodeHandle.subscribe("boot_stop", 1000, &oddbot_boot_module::get_info, this);
  subnet = get_subnet();
}
// Callback message
void oddbot_boot_module::get_info(const oddbot_msgs::OddbotBootStop::ConstPtr& stop_msg){
	
	//check my IP address	
	if (stop_msg->subnet == subnet) {
    //set stop running flag
    subnet_msg_stop = true;
  }
}

void oddbot_boot_module::send_info(){
  // Set the subnet
  module_info_msg.subnet = subnet;
	// Publish the subnet
  boot_pub.publish(module_info_msg);
}

bool oddbot_boot_module::get_subnet_msg_stop() {
  return subnet_msg_stop;
}

int oddbot_boot_module::get_subnet(){
  int fd;
  struct ifreq ifr;

  fd = socket(AF_INET, SOCK_DGRAM, 0);

  /* I want to get an IPv4 IP address */
  ifr.ifr_addr.sa_family = AF_INET;

  /* I want IP address attached to "subnet" */
  strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);

  ioctl(fd, SIOCGIFADDR, &ifr);

  close(fd);

  char *address = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
  std::stringstream s(address);
  int a, b, c, d;
  char ch;
  s >> a >> ch >> b >> ch >> c >> ch >> d;
  return c;
}

int main(int argc, char** argv){
	
	//stop when stop running flag is true
	ros::init(argc, argv, "oddbot_boot_module");

  oddbot_boot_module module = oddbot_boot_module();
  
  ROS_INFO("oddbot boot module node started!");  

  ros::Rate loop_rate(10);

  while (ros::ok() && !module.get_subnet_msg_stop())
  {
    module.send_info();
    ros::spinOnce();
    loop_rate.sleep();
  }
  ROS_INFO("you gon die now");
  return 0;
}
