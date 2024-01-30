#ifndef WEBOTS_ROS2_PLUGIN_EXAMPLE_HPP
#define WEBOTS_ROS2_PLUGIN_EXAMPLE_HPP

#include "rclcpp/macros.hpp"
#include "webots_ros2_driver/PluginInterface.hpp"
#include "webots_ros2_driver/WebotsNode.hpp"

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

namespace my_robot_driver1 {
class MyRobotDriver1 : public webots_ros2_driver::PluginInterface {
public:
  
  void step() override;
  void init(webots_ros2_driver::WebotsNode *node,
            std::unordered_map<std::string, std::string> &parameters) override;

private:
  void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);

  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr
      cmd_vel_subscription_;
  geometry_msgs::msg::Twist cmd_vel_msg;

  WbDeviceTag right_motor;
  WbDeviceTag left_motor;

  // New
  double distance_covered = 0.0;
  bool moving_forward = true;
  std::chrono::steady_clock::time_point last_time;
  void moveStraight(double speed);

};

} // namespace my_robot_driver1

namespace my_robot_driver2 {
class MyRobotDriver2 : public webots_ros2_driver::PluginInterface {
public:
  
  void step() override;
  void init(webots_ros2_driver::WebotsNode *node,
            std::unordered_map<std::string, std::string> &parameters) override;

private:
  void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);

  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr
      cmd_vel_subscription_;
  geometry_msgs::msg::Twist cmd_vel_msg;

  WbDeviceTag right_motor;
  WbDeviceTag left_motor;
};
} // namespace my_robot_driver2

#endif