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

class oddbot_boot_module{
	public:
		oddbot_boot_module();
	private:
		ros::Publisher boot_pub;
		ros::Subscriber stop_sub;
		void get_info(const oddbot_boot::OddbotBootStop::ConstPtr& stop_msg);
		void send_info()
}

int main(int argc, char** argv);

