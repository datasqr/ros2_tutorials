#include "robots_paths/MyRobotDriver.hpp"

#include "rclcpp/rclcpp.hpp"
#include <cstdio>
#include <functional>
#include <webots/motor.h>
#include <webots/robot.h>

#include <chrono>
#include <cmath>

#define HALF_DISTANCE_BETWEEN_WHEELS 0.045
#define WHEEL_RADIUS 0.025

#define ROBOT_SPEED 0.1 // meters per second
#define LINE_LENGTH 1.0 // meters

namespace my_robot_driver1 {

void MyRobotDriver1::init(
    webots_ros2_driver::WebotsNode *node,
    std::unordered_map<std::string, std::string> &parameters) {

  right_motor = wb_robot_get_device("right wheel motor");
  left_motor = wb_robot_get_device("left wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);

  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(right_motor, 0.0);

  cmd_vel_subscription_ = node->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel1", rclcpp::SensorDataQoS().reliable(),
      std::bind(&MyRobotDriver1::cmdVelCallback, this, std::placeholders::_1));

}

void MyRobotDriver1::cmdVelCallback(
  const geometry_msgs::msg::Twist::SharedPtr msg) {
  cmd_vel_msg.linear = msg->linear;
  cmd_vel_msg.angular = msg->angular;
}

void MyRobotDriver1::step() {

    auto forward_speed = cmd_vel_msg.linear.x;
    auto angular_speed = cmd_vel_msg.angular.z;

    auto command_motor_left =
        (forward_speed - angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;
    auto command_motor_right =
        (forward_speed + angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;

    wb_motor_set_velocity(left_motor, command_motor_left);
    wb_motor_set_velocity(right_motor, command_motor_right);
}


}; // namespace my_robot_driver1

// Robot 2
namespace my_robot_driver2 {

void MyRobotDriver2::init(
    webots_ros2_driver::WebotsNode *node,
    std::unordered_map<std::string, std::string> &parameters) {

  right_motor = wb_robot_get_device("right wheel motor");
  left_motor = wb_robot_get_device("left wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);

  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(right_motor, 0.0);

  cmd_vel_subscription_ = node->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel2", rclcpp::SensorDataQoS().reliable(),
      std::bind(&MyRobotDriver2::cmdVelCallback, this, std::placeholders::_1));
}

void MyRobotDriver2::cmdVelCallback(
    const geometry_msgs::msg::Twist::SharedPtr msg) {
  cmd_vel_msg.linear = msg->linear;
  cmd_vel_msg.angular = msg->angular;
}

void MyRobotDriver2::step() {
  auto forward_speed = cmd_vel_msg.linear.x;
  auto angular_speed = cmd_vel_msg.angular.z;

  auto command_motor_left =
      (forward_speed - angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
      WHEEL_RADIUS;
  auto command_motor_right =
      (forward_speed + angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
      WHEEL_RADIUS;

  wb_motor_set_velocity(left_motor, command_motor_left);
  wb_motor_set_velocity(right_motor, command_motor_right);
}

}; // namespace my_robot_driver2

namespace my_robot_driver3 {

void MyRobotDriver3::init(
    webots_ros2_driver::WebotsNode *node,
    std::unordered_map<std::string, std::string> &parameters) {

  right_motor = wb_robot_get_device("right wheel motor");
  left_motor = wb_robot_get_device("left wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);

  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(right_motor, 0.0);

  cmd_vel_subscription_ = node->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel3", rclcpp::SensorDataQoS().reliable(),
      std::bind(&MyRobotDriver3::cmdVelCallback, this, std::placeholders::_1));

}

void MyRobotDriver3::cmdVelCallback(
  const geometry_msgs::msg::Twist::SharedPtr msg) {
  cmd_vel_msg.linear = msg->linear;
  cmd_vel_msg.angular = msg->angular;
}

void MyRobotDriver3::step() {

    auto forward_speed = cmd_vel_msg.linear.x;
    auto angular_speed = cmd_vel_msg.angular.z;

    auto command_motor_left =
        (forward_speed - angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;
    auto command_motor_right =
        (forward_speed + angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;

    wb_motor_set_velocity(left_motor, command_motor_left);
    wb_motor_set_velocity(right_motor, command_motor_right);
}


}; // namespace my_robot_driver3

namespace my_robot_driver4 {

void MyRobotDriver4::init(
    webots_ros2_driver::WebotsNode *node,
    std::unordered_map<std::string, std::string> &parameters) {

  right_motor = wb_robot_get_device("right wheel motor");
  left_motor = wb_robot_get_device("left wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);

  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(right_motor, 0.0);

  cmd_vel_subscription_ = node->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel4", rclcpp::SensorDataQoS().reliable(),
      std::bind(&MyRobotDriver4::cmdVelCallback, this, std::placeholders::_1));

}

void MyRobotDriver4::cmdVelCallback(
  const geometry_msgs::msg::Twist::SharedPtr msg) {
  cmd_vel_msg.linear = msg->linear;
  cmd_vel_msg.angular = msg->angular;
}

void MyRobotDriver4::step() {

    auto forward_speed = cmd_vel_msg.linear.x;
    auto angular_speed = cmd_vel_msg.angular.z;

    auto command_motor_left =
        (forward_speed - angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;
    auto command_motor_right =
        (forward_speed + angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;

    wb_motor_set_velocity(left_motor, command_motor_left);
    wb_motor_set_velocity(right_motor, command_motor_right);
}


}; // namespace my_robot_driver4

namespace my_robot_driver5 {

void MyRobotDriver5::init(
    webots_ros2_driver::WebotsNode *node,
    std::unordered_map<std::string, std::string> &parameters) {

  right_motor = wb_robot_get_device("right wheel motor");
  left_motor = wb_robot_get_device("left wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);

  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(right_motor, 0.0);

  cmd_vel_subscription_ = node->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel5", rclcpp::SensorDataQoS().reliable(),
      std::bind(&MyRobotDriver5::cmdVelCallback, this, std::placeholders::_1));

}

void MyRobotDriver5::cmdVelCallback(
  const geometry_msgs::msg::Twist::SharedPtr msg) {
  cmd_vel_msg.linear = msg->linear;
  cmd_vel_msg.angular = msg->angular;
}

void MyRobotDriver5::step() {

    auto forward_speed = cmd_vel_msg.linear.x;
    auto angular_speed = cmd_vel_msg.angular.z;

    auto command_motor_left =
        (forward_speed - angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;
    auto command_motor_right =
        (forward_speed + angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;

    wb_motor_set_velocity(left_motor, command_motor_left);
    wb_motor_set_velocity(right_motor, command_motor_right);
}


}; // namespace my_robot_driver5

namespace my_robot_driver6 {

void MyRobotDriver6::init(
    webots_ros2_driver::WebotsNode *node,
    std::unordered_map<std::string, std::string> &parameters) {

  right_motor = wb_robot_get_device("right wheel motor");
  left_motor = wb_robot_get_device("left wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);

  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(right_motor, 0.0);

  cmd_vel_subscription_ = node->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel6", rclcpp::SensorDataQoS().reliable(),
      std::bind(&MyRobotDriver6::cmdVelCallback, this, std::placeholders::_1));

}

void MyRobotDriver6::cmdVelCallback(
  const geometry_msgs::msg::Twist::SharedPtr msg) {
  cmd_vel_msg.linear = msg->linear;
  cmd_vel_msg.angular = msg->angular;
}

void MyRobotDriver6::step() {

    auto forward_speed = cmd_vel_msg.linear.x;
    auto angular_speed = cmd_vel_msg.angular.z;

    auto command_motor_left =
        (forward_speed - angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;
    auto command_motor_right =
        (forward_speed + angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;

    wb_motor_set_velocity(left_motor, command_motor_left);
    wb_motor_set_velocity(right_motor, command_motor_right);
}


}; // namespace my_robot_driver6

namespace my_robot_driver7 {

void MyRobotDriver7::init(
    webots_ros2_driver::WebotsNode *node,
    std::unordered_map<std::string, std::string> &parameters) {

  right_motor = wb_robot_get_device("right wheel motor");
  left_motor = wb_robot_get_device("left wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);

  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(right_motor, 0.0);

  cmd_vel_subscription_ = node->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel7", rclcpp::SensorDataQoS().reliable(),
      std::bind(&MyRobotDriver7::cmdVelCallback, this, std::placeholders::_1));

}

void MyRobotDriver7::cmdVelCallback(
  const geometry_msgs::msg::Twist::SharedPtr msg) {
  cmd_vel_msg.linear = msg->linear;
  cmd_vel_msg.angular = msg->angular;
}

void MyRobotDriver7::step() {

    auto forward_speed = cmd_vel_msg.linear.x;
    auto angular_speed = cmd_vel_msg.angular.z;

    auto command_motor_left =
        (forward_speed - angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;
    auto command_motor_right =
        (forward_speed + angular_speed * HALF_DISTANCE_BETWEEN_WHEELS) /
        WHEEL_RADIUS;

    wb_motor_set_velocity(left_motor, command_motor_left);
    wb_motor_set_velocity(right_motor, command_motor_right);
}


}; // namespace my_robot_driver7


#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(my_robot_driver1::MyRobotDriver1, webots_ros2_driver::PluginInterface)
PLUGINLIB_EXPORT_CLASS(my_robot_driver2::MyRobotDriver2, webots_ros2_driver::PluginInterface)
PLUGINLIB_EXPORT_CLASS(my_robot_driver3::MyRobotDriver3, webots_ros2_driver::PluginInterface)
PLUGINLIB_EXPORT_CLASS(my_robot_driver4::MyRobotDriver4, webots_ros2_driver::PluginInterface)
PLUGINLIB_EXPORT_CLASS(my_robot_driver5::MyRobotDriver5, webots_ros2_driver::PluginInterface)
PLUGINLIB_EXPORT_CLASS(my_robot_driver6::MyRobotDriver6, webots_ros2_driver::PluginInterface)
PLUGINLIB_EXPORT_CLASS(my_robot_driver7::MyRobotDriver7, webots_ros2_driver::PluginInterface)