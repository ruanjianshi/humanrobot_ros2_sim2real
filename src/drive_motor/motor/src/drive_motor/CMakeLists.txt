cmake_minimum_required(VERSION 3.8)
project(drive_motor)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(motor_interfaces REQUIRED)

# ── Library: drive_motor_core (motor_base + motor_group + motor_hw + can_bridge) ──
add_library(drive_motor_core SHARED
  src/motor_base.cpp
  src/motor_group.cpp
  src/motor_hw.cpp
  src/can_bridge.cpp
)

target_include_directories(drive_motor_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

ament_target_dependencies(drive_motor_core PUBLIC
  rclcpp
)

# ── Executable: drive_motor_node ────────────────────────────────────
add_executable(drive_motor_node
  src/drive_motor_node.cpp
)

target_link_libraries(drive_motor_node PRIVATE
  drive_motor_core
)

ament_target_dependencies(drive_motor_node PUBLIC
  rclcpp
  motor_interfaces
)

# ── Install ─────────────────────────────────────────────────────────
install(TARGETS
  drive_motor_core
  drive_motor_node
  EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

install(DIRECTORY launch/ config/
  DESTINATION share/${PROJECT_NAME}
)

ament_export_targets(${PROJECT_NAME}Targets HAS_LIBRARY_TARGET)
ament_export_dependencies(rclcpp motor_interfaces)
ament_package()