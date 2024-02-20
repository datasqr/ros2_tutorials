#include "robots_paths/ObstacleAvoider.hpp"

// ObstacleAvoider6 stops for 2 sec when apporach obstacle

ObstacleAvoider6::ObstacleAvoider6(const std::string& cmd_vel_topic,
                                  const std::string& left_sensor_topic,
                                  const std::string& right_sensor_topic) : Node("obstacle_avoider6"),
                                  left_sensor_value(0.0), right_sensor_value(0.0), 
                                  turn_start_time_(0), start_time_distance_(0),
                                  distance_traveled_(0.0), state_(State::MOVING_FORWARD){

  publisher_ = create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic, 1);

  left_sensor_sub_ = create_subscription<sensor_msgs::msg::Range>(
      left_sensor_topic, 1,
      std::bind(&ObstacleAvoider6::leftSensorCallback, this,
                std::placeholders::_1));

  right_sensor_sub_ = create_subscription<sensor_msgs::msg::Range>(
      right_sensor_topic, 1,
      std::bind(&ObstacleAvoider6::rightSensorCallback, this,
                std::placeholders::_1));

  timer_robot_turn_ = this->create_wall_timer(100ms, std::bind(&ObstacleAvoider6::turn180, this));

  timer_distance_ = this->create_wall_timer(100ms, std::bind(&ObstacleAvoider6::updateDistance, this));

  start_time_ = this->now();

}

const char* ObstacleAvoider6::stateToString(State state) {
    switch (state) {
        case State::MOVING_FORWARD: return "MOVING_FORWARD";
        case State::STOPPING: return "STOPPING";
        case State::TURNING_AROUND: return "TURNING_AROUND";
        case State::MOVING_BACK: return "MOVING_BACK";
        default: return "UNKNOWN_STATE";
    }
}

void ObstacleAvoider6::leftSensorCallback(
    const sensor_msgs::msg::Range::SharedPtr msg) {
  left_sensor_value = msg->range;
  updateRobotBehavior();
}

void ObstacleAvoider6::rightSensorCallback(
    const sensor_msgs::msg::Range::SharedPtr msg) {
  right_sensor_value = msg->range;
  updateRobotBehavior();
}

void ObstacleAvoider6::updateDistance() {

  // auto command_message = std::make_unique<geometry_msgs::msg::Twist>();
  if (state_ == State::MOVING_FORWARD) {

    RCLCPP_INFO(this->get_logger(), "Robot1 state (distance): %s", stateToString(state_));

    double time_interval = 0.1; // 100ms in seconds
    distance_traveled_ += ROBOT_SPEED * time_interval;
    RCLCPP_INFO(this->get_logger(), "Robot1 distance: %f", distance_traveled_);

    if (distance_traveled_ >= TRAVEL_DISTANCE){
      RCLCPP_INFO(this->get_logger(), "Robot1 distance traveled: %f", TRAVEL_DISTANCE);
      state_ = State::TURNING_AROUND;
      turn_start_time_ = this->now();
      RCLCPP_INFO(this->get_logger(), "Robot1 state (distance): %s", stateToString(state_));
    }

  }

}

void ObstacleAvoider6::turn180() {

    auto command_message = std::make_unique<geometry_msgs::msg::Twist>();

    if (state_ == State::TURNING_AROUND) {

      RCLCPP_INFO(this->get_logger(), "Robot1 state (turn180): %s", stateToString(state_));
      RCLCPP_INFO(this->get_logger(), "Robot starts to turn");
      
      rclcpp::Time now = this->now();
      rclcpp::Duration duration_since_start_turning = now - turn_start_time_;

      
      // Convert TURN_SPEED to linear velocity of the wheel's edge
      double v_linear = TURN_SPEED * WHEEL_RADIUS;
      // Calculate robot's angular velocity around its center
      double omega_robot = (v_linear) / WHEELBASE_WIDTH;

      // Calculate time to turn 180 degrees
      double turn_duration = (M_PI / omega_robot);
      //double turn_duration = (WHEEL_RADIUS*M_PI)/TURN_SPEED;


      RCLCPP_INFO(this->get_logger(), "duration_since_start_turning: %f", duration_since_start_turning.seconds());

      if (duration_since_start_turning.seconds() < turn_duration) {
        RCLCPP_INFO(this->get_logger(), "Robot is turning 180 degrees.");

        command_message->linear.x = 0.0; // Stop linear movement
        command_message->angular.z = TURN_SPEED; // Angular velocity for the turn
      } else {
        // Stop the turn after reaching the desired duration
        command_message->linear.x = ROBOT_SPEED;
        command_message->angular.z = 0.0; // Stop turning
        state_ = State::MOVING_FORWARD; // Update state as needed
        RCLCPP_INFO(this->get_logger(), "Completed 180 degrees turn.");
        distance_traveled_ = 0.0;
        RCLCPP_INFO(this->get_logger(), "Robot1 state (turn180): %s", stateToString(state_));
      }

    }

    publisher_->publish(std::move(command_message));

}

void ObstacleAvoider6::updateRobotBehavior() {

    auto command_message = std::make_unique<geometry_msgs::msg::Twist>();

    if(state_ != State::TURNING_AROUND){

      command_message->linear.x = ROBOT_SPEED; // run
      // left_sensor_value < MAX_RANGE || 
      if (right_sensor_value < MAX_RANGE) {
        // Obstacle detected, stop and wait
        RCLCPP_INFO(this->get_logger(), "Robot1 - Obstacle detected, stop and wait");
        command_message->linear.x = 0.0; // Stop
        state_=State::STOPPING;
        
        RCLCPP_INFO(this->get_logger(), "Robot1 state (sensors): %s", stateToString(state_));
      } else {
        // No obstacle, move forward
        command_message->linear.x = ROBOT_SPEED;
        obstacle_detected = false;
        state_=State::MOVING_FORWARD;

        RCLCPP_INFO(this->get_logger(), "Robot1 state (sensors): %s", stateToString(state_));
      }
      
    }

    publisher_->publish(std::move(command_message)); // Publish stop command
    
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);

  auto avoider = std::make_shared<ObstacleAvoider6>("/cmd_vel6", "/my_robot6/left_sensor", "/my_robot6/right_sensor");

  rclcpp::spin(avoider);

  rclcpp::shutdown();
  return 0;
}