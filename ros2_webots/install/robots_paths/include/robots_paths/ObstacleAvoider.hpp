#include <memory>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/range.hpp"
#include <string>
#include <chrono>

using namespace std::chrono_literals;

class ObstacleAvoider1 : public rclcpp::Node {
public:
  explicit ObstacleAvoider1(const std::string& cmd_vel_topic, 
                           const std::string& left_sensor_topic, 
                           const std::string& right_sensor_topic);

private:
  void leftSensorCallback(const sensor_msgs::msg::Range::SharedPtr msg);
  void rightSensorCallback(const sensor_msgs::msg::Range::SharedPtr msg);

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr left_sensor_sub_;
  rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr right_sensor_sub_;

  double left_sensor_value{0.0};
  double right_sensor_value{0.0};

  enum class State {
        MOVING_FORWARD,
        STOPPING,
        TURNING_AROUND,
        MOVING_BACK
    };

  State state_;
  const char* stateToString(State);

  double distance_traveled_;
  double velocity_; // Velocity in meters per second
  double wheelbase_width_;
  bool turning_around;
  bool obstacle_detected = false;
  bool isMoving;


  rclcpp::TimerBase::SharedPtr timer_distance_;
  rclcpp::TimerBase::SharedPtr timer_robot_turn_;
  rclcpp::Time start_time_;
  rclcpp::Time start_time_distance_;
  rclcpp::Time turn_start_time_;
  rclcpp::Duration turn_duration = rclcpp::Duration(2, 0);

  void updateRobotBehavior();
  void updateDistance();
  void turn180();
  void finishTurning();

};

class ObstacleAvoider2 : public rclcpp::Node {
public:
  explicit ObstacleAvoider2(const std::string& cmd_vel_topic, 
                           const std::string& left_sensor_topic, 
                           const std::string& right_sensor_topic);

private:
  void leftSensorCallback(const sensor_msgs::msg::Range::SharedPtr msg);
  void rightSensorCallback(const sensor_msgs::msg::Range::SharedPtr msg);

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr left_sensor_sub_;
  rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr right_sensor_sub_;

  double left_sensor_value{0.0};
  double right_sensor_value{0.0};
};