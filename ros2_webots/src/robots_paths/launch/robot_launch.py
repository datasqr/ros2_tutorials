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
    robot_description_path3 = os.path.join(package_dir, 'resource', 'my_robot3.urdf')
    robot_description_path4 = os.path.join(package_dir, 'resource', 'my_robot4.urdf')
    robot_description_path5 = os.path.join(package_dir, 'resource', 'my_robot5.urdf')
    robot_description_path6 = os.path.join(package_dir, 'resource', 'my_robot6.urdf')
    robot_description_path7 = os.path.join(package_dir, 'resource', 'my_robot7.urdf')

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

    my_robot_driver3 = WebotsController(
        robot_name='my_robot3',
        parameters=[
            {'robot_description': robot_description_path3}
        ],
        respawn=True
    )

    my_robot_driver4 = WebotsController(
        robot_name='my_robot4',
        parameters=[
            {'robot_description': robot_description_path4}
        ],
        respawn=True
    )

    my_robot_driver5 = WebotsController(
        robot_name='my_robot5',
        parameters=[
            {'robot_description': robot_description_path5}
        ],
        respawn=True
    )

    my_robot_driver6 = WebotsController(
        robot_name='my_robot6',
        parameters=[
            {'robot_description': robot_description_path6}
        ],
        respawn=True
    )

    my_robot_driver7 = WebotsController(
        robot_name='my_robot7',
        parameters=[
            {'robot_description': robot_description_path7}
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

    obstacle_avoider3 = Node(
        package='robots_paths',
        executable='obstacle_avoider3',
    )

    obstacle_avoider4 = Node(
        package='robots_paths',
        executable='obstacle_avoider4',
    )

    obstacle_avoider5 = Node(
        package='robots_paths',
        executable='obstacle_avoider5',
    )

    obstacle_avoider6 = Node(
        package='robots_paths',
        executable='obstacle_avoider6',
    )

    obstacle_avoider7 = Node(
        package='robots_paths',
        executable='obstacle_avoider7',
    )

    return LaunchDescription([
        webots,
        my_robot_driver1,
        my_robot_driver2,
        my_robot_driver3,
        my_robot_driver4,
        my_robot_driver5,
        my_robot_driver6,
        my_robot_driver7,
        obstacle_avoider1,
        obstacle_avoider2,
        obstacle_avoider3,
        obstacle_avoider4,
        obstacle_avoider5,
        obstacle_avoider6,
        obstacle_avoider7,
        launch.actions.RegisterEventHandler(
            event_handler=launch.event_handlers.OnProcessExit(
                target_action=webots,
                on_exit=[launch.actions.EmitEvent(event=launch.events.Shutdown())],
            )
        )
    ])