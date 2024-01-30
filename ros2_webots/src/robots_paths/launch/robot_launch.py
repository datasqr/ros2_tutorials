import os
import launch
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from webots_ros2_driver.webots_launcher import WebotsLauncher
from webots_ros2_driver.webots_controller import WebotsController

from launch_ros.actions import Node


def generate_launch_description():
    package_dir = get_package_share_directory('robots_paths')
    robot_description_path1 = os.path.join(package_dir, 'resource', 'my_robot1.urdf')
    robot_description_path2 = os.path.join(package_dir, 'resource', 'my_robot2.urdf')

    webots = WebotsLauncher(
        world=os.path.join(package_dir, 'worlds', 'my_world.wbt')
    )

    my_robot_driver1 = WebotsController(
        robot_name='my_robot1',
        parameters=[
            {'robot_description': robot_description_path1},
        ],
        respawn=True
    )

    my_robot_driver2 = WebotsController(
        robot_name='my_robot2',
        parameters=[
            {'robot_description': robot_description_path2}
        ],
        respawn=True
    )

    obstacle_avoider1 = Node(
        package='robots_paths',
        executable='obstacle_avoider1',
    )

    obstacle_avoider2 = Node(
        package='robots_paths',
        executable='obstacle_avoider2',
    )

    return LaunchDescription([
        webots,
        my_robot_driver1,
        my_robot_driver2,
        obstacle_avoider1,
        obstacle_avoider2,
        launch.actions.RegisterEventHandler(
            event_handler=launch.event_handlers.OnProcessExit(
                target_action=webots,
                on_exit=[launch.actions.EmitEvent(event=launch.events.Shutdown())],
            )
        )
    ])