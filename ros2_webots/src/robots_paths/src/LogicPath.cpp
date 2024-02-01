// #include <iostream>
// #include <vector>
// #include <stack>

// struct Cell {
//     int x;
//     int y;
// };

// bool isValid(const std::vector<std::vector<int>>& matrix, int x, int y, std::vector<std::vector<bool>>& visited) {
//     return (x >= 0) && (x < matrix.size()) && (y >= 0) && (y < matrix[0].size()) && 
//            (matrix[x][y] == 1) && (!visited[x][y]);
// }

// bool findPathDFS(const std::vector<std::vector<int>>& matrix, std::vector<Cell>& path, 
//                  std::vector<std::vector<bool>>& visited, int x, int y) {
//     if (x == matrix.size() - 1 && y == matrix[0].size() - 1) {
//         path.push_back({x, y});
//         return true;
//     }

//     if (isValid(matrix, x, y, visited)) {
//         path.push_back({x, y});
//         visited[x][y] = true;

//         if (findPathDFS(matrix, path, visited, x + 1, y)) { // Move Down
//             return true;
//         }
//         if (findPathDFS(matrix, path, visited, x, y + 1)) { // Move Right
//             return true;
//         }

//         // Backtrack
//         path.pop_back();
//     }

//     return false;
// }

// std::vector<Cell> findPath(const std::vector<std::vector<int>>& matrix) {
//     std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));
//     std::vector<Cell> path;

//     if (findPathDFS(matrix, path, visited, 0, 0)) {
//         return path;
//     } else {
//         return std::vector<Cell>(); // No path found
//     }
// }

// int main() {
//     std::vector<std::vector<int>> matrix = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1},
//         {0, 0, 0, 1}
//     };

//     std::vector<Cell> path = findPath(matrix);

//     for (const Cell& cell : path) {
//         std::cout << "(" << cell.x << ", " << cell.y << ") -> ";
//     }
//     std::cout << "End" << std::endl;

//     return 0;
// }


// ##########################

// To implement path navigation using a matrix of zeros and ones in a ROS2 environment with the MyRobotDriver2 class, you need to integrate the path-finding algorithm into the robot's control loop. The robot will use the computed path to navigate by turning and moving forward based on the current and next points in the path.

// First, you should compute the path using the matrix-based approach as previously described. Once you have the path, the MyRobotDriver2 class can be modified to follow this path.

// Here's an outline of how you can approach this:

//     Define the Path: Compute the path using the matrix approach and store it in a suitable data structure (like a std::vector of points).

//     Path Following Logic: Implement logic in the step function to follow the computed path. The robot should move from one point to the next.

//     Converting Path Points to Movements: For each pair of consecutive points, determine whether the robot needs to move straight, turn left, or turn right, and then move forward.

//     Robot Movement Commands: Update the velocities of the left and right motors based on the required movement (straight or turn).



// provide code to Define the Path: Compute the path using the matrix approach and store it in a suitable data structure (like a std::vector of points).

// #include <iostream>
// #include <vector>
// #include <stack>

// struct Point {
//     int x;
//     int y;
// };

// bool isValidMove(const std::vector<std::vector<int>>& grid, int x, int y, std::vector<std::vector<bool>>& visited) {
//     int numRows = grid.size();
//     int numCols = grid[0].size();
//     return x >= 0 && y >= 0 && x < numRows && y < numCols && grid[x][y] == 1 && !visited[x][y];
// }

// void findPathDFS(const std::vector<std::vector<int>>& grid, std::vector<Point>& path, std::vector<std::vector<bool>>& visited, int x, int y) {
//     if (x == grid.size() - 1 && y == grid[0].size() - 1) {  // Destination reached
//         path.push_back({x, y});
//         return;
//     }

//     if (!isValidMove(grid, x, y, visited))
//         return;

//     // Mark the cell as visited and add it to the path
//     visited[x][y] = true;
//     path.push_back({x, y});

//     // Explore the neighboring cells
//     findPathDFS(grid, path, visited, x + 1, y); // Down
//     findPathDFS(grid, path, visited, x, y + 1); // Right
//     findPathDFS(grid, path, visited, x - 1, y); // Up
//     findPathDFS(grid, path, visited, x, y - 1); // Left

//     // If no path is found, backtrack
//     if (path.back().x != grid.size() - 1 || path.back().y != grid[0].size() - 1) {
//         path.pop_back();
//     }
// }

// std::vector<Point> findPath(const std::vector<std::vector<int>>& grid) {
//     std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
//     std::vector<Point> path;
//     findPathDFS(grid, path, visited, 0, 0); // Start from (0,0)
//     return path;
// }

// int main() {
//     std::vector<std::vector<int>> matrix = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1},
//         {0, 0, 0, 1}
//     };

//     std::vector<Point> path = findPath(matrix);
//     for (const auto& p : path) {
//         std::cout << "(" << p.x << ", " << p.y << ") -> ";
//     }
//     std::cout << "End\n";

//     return 0;
// }


// provide code for Path Following Logic: Implement logic in the step function to follow the computed path. The robot should move from one point to the next.

// struct Point {
//     int x, y;
// };

// // ... (other includes and class member definitions)

// void MyRobotDriver2::step() {
//     if (!path.empty() && current_path_index < path.size()) {
//         followPath();
//     } else {
//         // Stop the robot or handle the end of the path
//         stopRobot();
//     }
// }

// void MyRobotDriver2::followPath() {
//     Point current_target = path[current_path_index];
//     Point next_target = (current_path_index + 1 < path.size()) ? path[current_path_index + 1] : current_target;

//     // Assuming the robot needs to align itself with the next target
//     // Calculate the required turn
//     double required_turn = calculateTurnAngle(current_target, next_target);

//     // Move or turn the robot based on the current alignment
//     if (std::abs(required_turn) > TURN_THRESHOLD) {
//         turnRobot(required_turn);
//     } else if (isAlignedWithTarget(current_target)) {
//         moveRobotForward();
//         current_path_index++;
//     }
// }

// #include <cmath> 
// double MyRobotDriver2::calculateTurnAngle(const Point& current, const Point& next) {
//     // Determine the direction vector from current to next
//     int dx = next.x - current.x;
//     int dy = next.y - current.y;

//     // Calculate the angle in radians from current to next
//     // atan2 returns the angle in radians between the positive x-axis and the point (dx, dy)
//     double angleRadians = std::atan2(dy, dx);

//     // Optional: Convert angle to the robot's orientation system if needed
//     // For example, if your robot's forward direction is 0 radians and it measures angles in clockwise direction

//     // Normalize the angle to your robot's orientation system
//     // Assuming the robot's forward (0 degrees) direction is up (North) and positive angles are clockwise
//     double robotOrientationAngle = angleRadians;

//     // Adjust angle based on the robot's current orientation if necessary
//     // For example, if the robot is currently facing East (90 degrees or π/2 radians) and needs to turn to South (180 degrees or π radians)
//     // The turn angle would be π/2 radians (90 degrees)

//     // Return the calculated turn angle
//     return robotOrientationAngle;
// }

// #include <cmath> // For atan2 function and M_PI constant

// // Assuming the robot's orientation is stored in a variable `robot_orientation`
// // which represents the robot's current facing direction in radians
// // 0 radians could represent facing "up" (north) on the grid, with positive angles in the clockwise direction

// class MyRobotDriver2 {
// public:
//     // Other member functions and variables

// private:
//     double robot_orientation = 0.0; // Robot's facing direction in radians, 0 = up (north)

//     // Function to update robot's orientation based on turning movement
//     void updateOrientation(double turn_angle_radians);
//     // Additional class members...
// };

// void MyRobotDriver2::updateOrientation(double turn_angle_radians) {
//     robot_orientation += turn_angle_radians;

//     // Normalize the orientation to be within [0, 2*PI)
//     while (robot_orientation < 0) {
//         robot_orientation += 2 * M_PI;
//     }
//     while (robot_orientation >= 2 * M_PI) {
//         robot_orientation -= 2 * M_PI;
//     }
// }


// bool MyRobotDriver2::isAlignedWithTarget(const Point& target) {
//     // Assuming `current_position` and `robot_orientation` are accessible
//     Point current_position; // You need to have the robot's current position
//     double robot_orientation; // And its current orientation in radians

//     // Calculate the desired orientation to face the target
//     int dx = target.x - current_position.x;
//     int dy = target.y - current_position.y;
//     double desired_orientation = std::atan2(dy, dx);

//     // Calculate the difference between the current and desired orientations
//     double orientation_difference = std::abs(desired_orientation - robot_orientation);

//     // Normalize the difference to the range [0, 2*PI]
//     orientation_difference = std::fmod(orientation_difference, 2 * M_PI);
//     if (orientation_difference > M_PI) {
//         orientation_difference = 2 * M_PI - orientation_difference;
//     }

//     // Define an alignment threshold (in radians)
//     // This is the maximum allowed difference in orientation to consider the robot aligned with the target
//     const double alignment_threshold = M_PI / 18; // 10 degrees in radians

//     // Check if the robot is aligned within the threshold
//     return orientation_difference <= alignment_threshold;
// }

// void MyRobotDriver2::turnRobot(double angle) {
//     // Constants
//     const double wheelbase = 0.2; // Distance between wheels, adjust based on your robot
//     const double wheelDiameter = 0.05; // Diameter of the wheels, adjust based on your robot
//     const double wheelCircumference = M_PI * wheelDiameter;

//     // Calculate the distance each wheel needs to travel
//     double wheelDistance = (angle * wheelbase) / 2.0;

//     // Calculate the rotation in terms of wheel turns, considering the circumference
//     double wheelTurns = wheelDistance / wheelCircumference;

//     // Calculate the required motor rotations in radians
//     double motorRotation = wheelTurns * 2.0 * M_PI;

//     // Assuming motors need to be set in radians and wb_motor_set_velocity function is used
//     // For a turn, one wheel moves forward and the other moves backward
//     wb_motor_set_position(left_motor, INFINITY); // Allow continuous rotation
//     wb_motor_set_position(right_motor, INFINITY); // Allow continuous rotation

//     double leftMotorSpeed = (angle > 0) ? motorRotation : -motorRotation; // Positive angle, right turn
//     double rightMotorSpeed = -leftMotorSpeed; // Opposite direction for turning

//     // Set the speed. Adjust the multiplier as necessary to match your robot's speed characteristics
//     wb_motor_set_velocity(left_motor, leftMotorSpeed);
//     wb_motor_set_velocity(right_motor, rightMotorSpeed);

//     // Assuming you have a way to wait until the turn is completed
//     // This might involve a delay based on the speed of the robot and the angle to turn
//     // Or, more sophisticated, using odometry to check when the turn has been completed
// }

// void MyRobotDriver2::moveRobotForward() {
//     // Implement logic to move the robot forward
//     // Set motor speeds for forward movement
// }

// void MyRobotDriver2::stopRobot() {
//     // Implement logic to stop the robot
//     // Set motor speeds to zero
// }

// void MyRobotDriver1::moveStraight(double speed) {
//     double motor_speed = speed / WHEEL_RADIUS;
//     wb_motor_set_velocity(left_motor, motor_speed);
//     wb_motor_set_velocity(right_motor, motor_speed);
// }

// void MyRobotDriver1::turn180(double speed) {
//     double motor_speed = speed * HALF_DISTANCE_BETWEEN_WHEELS / WHEEL_RADIUS;
//     wb_motor_set_velocity(left_motor, -motor_speed);
//     wb_motor_set_velocity(right_motor, motor_speed);
// }