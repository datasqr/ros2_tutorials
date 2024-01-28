#include "multiple_robots/ObstacleAvoider1.hpp"

#define MAX_RANGE 0.15

ObstacleAvoider1::ObstacleAvoider1() : Node("obstacle_avoider1") {
  publisher_ = create_publisher<geometry_msgs::msg::Twist>("/cmd_vel1", 1);

  left_sensor_sub_ = create_subscription<sensor_msgs::msg::Range>(
      "/left_sensor1", 1,
      std::bind(&ObstacleAvoider1::leftSensorCallback, this,
                std::placeholders::_1));

  right_sensor_sub_ = create_subscription<sensor_msgs::msg::Range>(
      "/right_sensor1", 1,
      std::bind(&ObstacleAvoider1::rightSensorCallback, this,
                std::placeholders::_1));
}

void ObstacleAvoider1::leftSensorCallback(
    const sensor_msgs::msg::Range::SharedPtr msg) {
  left_sensor_value = msg->range;
}

void ObstacleAvoider1::rightSensorCallback(
    const sensor_msgs::msg::Range::SharedPtr msg) {
  right_sensor_value = msg->range;

  auto command_message = std::make_unique<geometry_msgs::msg::Twist>();

  command_message->linear.x = 0.1;

  if (left_sensor_value < 0.9 * MAX_RANGE ||
      right_sensor_value < 0.9 * MAX_RANGE) {
    command_message->angular.z = -2.0;
  }

  publisher_->publish(std::move(command_message));
}

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto avoider = std::make_shared<ObstacleAvoider1>();
  rclcpp::spin(avoider);
  rclcpp::shutdown();
  return 0;
}