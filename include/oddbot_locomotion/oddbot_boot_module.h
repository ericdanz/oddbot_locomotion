/*
 * \oddbot_boot_module.h
 *
 * \author Chris Dunkers, CMU - cmdunkers@cmu.edu
 * \date October 13, 2014
 */

#ifndef ODDBOT_BOOT_MODULE_H_
#define ODDBOT_BOOT_MODULE_H_

#include "ros/ros.h"
#include "oddbot_msgs/OddbotBoot.h"
#include "oddbot_msgs/OddbotBootStop.h"
//#include "oddbot_boot/get_subnet.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h> /* for strncpy */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

class oddbot_boot_module{
	public:
		oddbot_boot_module();
		bool get_subnet_msg_stop();
		void send_info();
	private:
		bool subnet_msg_stop;
		oddbot_msgs::OddbotBoot module_info_msg;
		ros::Publisher boot_pub;
		ros::Subscriber stop_sub;
		void get_info(const oddbot_msgs::OddbotBootStop::ConstPtr& stop_msg);
		int subnet;
		int get_subnet();
};

int main(int argc, char** argv);

#endif
