from setuptools import setup, find_packages
from glob import glob
import os

package_name = 'sim2real'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        (
            'share/ament_index/resource_index/packages',
            ['resource/' + package_name]
        ),
        (
            'share/' + package_name,
            ['package.xml']
        ),
        (
            os.path.join('share', package_name, 'config'),
            glob('config/*.yaml')
        ),
        (
            os.path.join('share', package_name, 'policy'),
            glob('policy/*.onnx')
        ),
        (
            os.path.join('share', package_name, 'launch'),
            glob('launch/*.py')
        ),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sunrise',
    maintainer_email='sunrise@example.com',
    description='Sim2Real inference package for ROS2 deployment',
    license='MIT',
    entry_points={
        'console_scripts': [
            'test_onnx = sim2real.test_onnx:main',
        ],
    },
)
