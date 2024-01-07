cmake_minimum_required(VERSION 3.8)
project(package_name)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -g)
endif()

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(vision_msgs REQUIRED)

include_directories(
  include
)

add_library(
  package_name SHARED
  src/package_name.cpp
)
target_compile_definitions(package_name
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(
  package_name
  rclcpp
  rclcpp_components
  std_msgs
  vision_msgs
)
rclcpp_components_register_nodes(package_name "package_name::PackageName")
set(node_plugins "${node_plugins}package_name::PackageName;$<TARGET_FILE:package_name>\n")

add_executable(package_name_node src/package_name_node.cpp)
target_link_libraries(package_name_node package_name)
ament_target_dependencies(package_name_node "rclcpp")

install(TARGETS
  package_name_node
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  package_name
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
