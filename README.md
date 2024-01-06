

#ros2_tutorials

ROS2 Tutorials: https://docs.ros.org/en/iron/Tutorials.html

## Hardware and OS
* Lenovo
* 32GB RAM
* Proc: Intel® Core™ i7-6600U CPU @ 2.60GHz × 4
* Ubuntu 22.04.3 LTS (Jammy Jellyfish - https://docs.ros.org/en/iron/Installation.html)

## commands

source /opt/ros/iron/setup.bash

cd ~/ros2_ws/src

ros2 pkg create --build-type ament_cmake --license Apache-2.0 <package_name>

ros2 pkg create --build-type ament_cmake --license Apache-2.0 --node-name my_node my_package --license Apache-2.0

cd ~/ros2_ws

colcon build --packages-select my_package

source install/local_setup.bash

ros2 run my_package my_node

## Important
When running tutorial https://docs.ros.org/en/iron/Tutorials/Intermediate/URDF/Using-URDF-with-Robot-State-Publisher.html in python rember to dwongrade setuptools to 58.2.0

pip3 install setuptools==58.2.0
