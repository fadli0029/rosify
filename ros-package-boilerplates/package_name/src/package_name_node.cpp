#include "package_name/package_name.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  rclcpp::executors::MultiThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto package_name = std::make_shared<package_name::PackageName>(options);
  exec.add_node(package_name->get_node_base_interface());

  exec.spin();

  rclcpp::shutdown();

  return 0;
}

