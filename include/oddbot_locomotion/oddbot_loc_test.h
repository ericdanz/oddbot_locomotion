/*
 * \oddbot_loc_test.h
 *
 * \author Chris Dunkers, CMU - cmdunkers@cmu.edu
 * \date October 13, 2014
 */

#ifndef ODDBOT_LOC_TEST_H_
#define ODDBOT_LOC_TEST_H_

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"

class oddbot_loc_test{
	public:
		oddbot_loc_test();
		void send_od();
	private:
		
		nav_msgs::Odometry od_msg;
		ros::Publisher od_pub;
		ros::Subscriber vel_sub;
		void get_info(const geometry_msgs::Twist::ConstPtr& vel_msg);
		int subnet;
		
};

int main(int argc, char** argv);

#endif
