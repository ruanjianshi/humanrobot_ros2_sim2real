#!/usr/bin/env python3
"""
drive_motor.launch.py — 电机驱动启动文件

用法:
  # 单电机测试
  ros2 launch drive_motor drive_motor.launch.py

  # 指定配置
  ros2 launch drive_motor drive_motor.launch.py config_file:=pi_plus_lower_body.yaml
"""
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import (
    LaunchConfiguration,
    PathJoinSubstitution,
)
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # 配置文件名 (不带路径, 在 config/ 下)
    config_file = LaunchConfiguration('config_file', default='single_motor.yaml')

    declare_config = DeclareLaunchArgument(
        'config_file',
        default_value='single_motor.yaml',
        description='Motor config YAML file in config/ directory'
    )

    # 解析配置文件完整路径
    config_path = PathJoinSubstitution([
        FindPackageShare('drive_motor'),
        config_file,
    ])

    drive_motor_node = Node(
        package='drive_motor',
        executable='drive_motor_node',
        name='drive_motor_node',
        output='screen',
        parameters=[config_path],
    )

    return LaunchDescription([
        declare_config,
        drive_motor_node,
    ])