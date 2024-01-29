#include "robots_world/ObstacleAvoider.hpp"

#define MAX_RANGE 0.15

// ObstacleAvoider1

ObstacleAvoider1::ObstacleAvoider1(const std::string& cmd_vel_topic, 
                                 const std::string& left_sensor_topic, 
                                 const std::string& right_sensor_topic) : Node("obstacle_avoider1") {

  publisher_ = create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic, 1);

  left_sensor_sub_ = create_subscription<sensor_msgs::msg::Range>(
      left_sensor_topic, 1,
      std::bind(&ObstacleAvoider1::leftSensorCallback, this,
                std::placeholders::_1));

  right_sensor_sub_ = create_subscription<sensor_msgs::msg::Range>(
      right_sensor_topic, 1,
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
  // auto avoider = std::make_shared<ObstacleAvoider>();
  // rclcpp::spin(avoider);
  auto avoider = std::make_shared<ObstacleAvoider1>("/cmd_vel1", "/my_robot1/left_sensor", "/my_robot1/right_sensor");

  rclcpp::spin(avoider);

  rclcpp::shutdown();
  return 0;
}