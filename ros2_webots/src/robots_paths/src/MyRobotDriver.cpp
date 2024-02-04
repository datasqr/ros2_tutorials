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

#define PI 3.14159265358979323846 // Value of pi for angle calculation
// Angular velocity for turning, in radians per second
#define TURN_ANGULAR_VELOCITY (2.2 * ROBOT_SPEED / (2 * HALF_DISTANCE_BETWEEN_WHEELS))


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
        double time_step_seconds = wb_robot_get_basic_time_step() / 1000.0;
        switch (state) {
            case MOVING_FORWARD:
                if (distance_covered < LINE_LENGTH) {
                    setVelocity(ROBOT_SPEED, ROBOT_SPEED);
                    distance_covered += ROBOT_SPEED * time_step_seconds;
                } else {
                    state = TURNING;
                    total_turn_angle = 0.0; // Reset turn angle for the turn
                }
                break;
            case TURNING:
            if (total_turn_angle < M_PI) { // Complete a 180 degree turn
                double left_wheel_speed = -ROBOT_SPEED;
                double right_wheel_speed = ROBOT_SPEED;
                setVelocity(left_wheel_speed, right_wheel_speed);
                total_turn_angle += TURN_ANGULAR_VELOCITY * time_step_seconds;
            } else {
                state = MOVING_FORWARD;
                distance_covered = 0.0; // Reset distance for the next leg
            }
            break;
          }
}

void MyRobotDriver1::setVelocity(double left_speed, double right_speed) {
        wb_motor_set_velocity(left_motor, left_speed / WHEEL_RADIUS);
        wb_motor_set_velocity(right_motor, right_speed / WHEEL_RADIUS);
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