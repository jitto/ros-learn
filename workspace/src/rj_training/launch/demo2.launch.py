import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(name="background_r", default_value="255"),
        Node(package="turtlesim", executable="turtlesim_node", 
        # parameters=[{
        #     "background_r": LaunchConfiguration("background_r"),
        #     "background_g": 255,
        #     "background_b": 0
        # }]
            parameters=[os.path.join(get_package_share_directory("rj_training"), "config", "turtlesim_params.yaml")]
        ),
        Node(package="turtlesim", executable="draw_square")
    ])