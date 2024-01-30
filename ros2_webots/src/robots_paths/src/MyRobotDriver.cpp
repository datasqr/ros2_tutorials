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

#define ROBOT_SPEED 0.2 // meters per second
#define LINE_LENGTH 1.0 // meters

namespace my_robot_driver1 {

// Robot 1
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

  // New
  last_time = std::chrono::steady_clock::now();

}

void MyRobotDriver1::cmdVelCallback(
    const geometry_msgs::msg::Twist::SharedPtr msg) {
  cmd_vel_msg.linear = msg->linear;
  cmd_vel_msg.angular = msg->angular;
}

void MyRobotDriver1::step() {
  
  auto current_time = std::chrono::steady_clock::now();
  auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count() / 1000.0;
  last_time = current_time;

  // Calculate distance covered
  distance_covered += ROBOT_SPEED * elapsed_time;

  // Check if the robot needs to change direction
  if (distance_covered >= LINE_LENGTH) {
      moving_forward = !moving_forward;
      distance_covered = 0.0;
  }

  // Move the robot
  moveStraight(moving_forward ? ROBOT_SPEED : -ROBOT_SPEED);

}

void MyRobotDriver1::moveStraight(double speed) {
    double motor_speed = speed / WHEEL_RADIUS;
    wb_motor_set_velocity(left_motor, motor_speed);
    wb_motor_set_velocity(right_motor, motor_speed);
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

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(my_robot_driver1::MyRobotDriver1, webots_ros2_driver::PluginInterface)
PLUGINLIB_EXPORT_CLASS(my_robot_driver2::MyRobotDriver2, webots_ros2_driver::PluginInterface)