#include "robots_paths/ObstacleAvoider.hpp"

// ObstacleAvoider2

ObstacleAvoider2::ObstacleAvoider2(const std::string& cmd_vel_topic, 
                                  const std::string& left_sensor_topic, 
                                  const std::string& right_sensor_topic) : Node("obstacle_avoider2") {

  publisher_ = create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic, 1);

  left_sensor_sub_ = create_subscription<sensor_msgs::msg::Range>(
      left_sensor_topic, 1,
      std::bind(&ObstacleAvoider2::leftSensorCallback, this,
                std::placeholders::_1));

  right_sensor_sub_ = create_subscription<sensor_msgs::msg::Range>(
      right_sensor_topic, 1,
      std::bind(&ObstacleAvoider2::rightSensorCallback, this,
                std::placeholders::_1));
}

void ObstacleAvoider2::leftSensorCallback(
    const sensor_msgs::msg::Range::SharedPtr msg) {
  left_sensor_value = msg->range;

  auto command_message = std::make_unique<geometry_msgs::msg::Twist>();

  command_message->linear.x = 0.1;

  if (left_sensor_value < 0.9 * MAX_RANGE) {
    command_message->angular.z = -2.0;
  }

  publisher_->publish(std::move(command_message));
}

void ObstacleAvoider2::rightSensorCallback(
    const sensor_msgs::msg::Range::SharedPtr msg) {
  right_sensor_value = msg->range;

  auto command_message = std::make_unique<geometry_msgs::msg::Twist>();

  command_message->linear.x = 0.1;

  if (right_sensor_value < 0.9 * MAX_RANGE) {
    command_message->angular.z = 2.0;
  }

  publisher_->publish(std::move(command_message));
}

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  
  auto avoider = std::make_shared<ObstacleAvoider2>("/cmd_vel2", "/my_robot2/left_sensor", "/my_robot2/right_sensor");

  rclcpp::spin(avoider);

  rclcpp::shutdown();
  return 0;
}