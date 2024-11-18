#include "package_name/package_name.hpp"

namespace package_name
{

PackageName::PackageName(const rclcpp::NodeOptions& options)
: node_(std::make_shared<rclcpp::Node>("package_name", options))
{

  /* ------------------------------------------------------------------------ */
  // Create subs.
  /* ------------------------------------------------------------------------ */
  rclcpp::SubscriptionOptions sub_options;

  // Topic 1
  callback_gp_topic_name_ = node_->create_callback_group(
      rclcpp::CallbackGroupType::MutuallyExclusive
    );
  sub_options.callback_group = topic_name_callback_gp_;
  sub_topic_name_ = node_->create_subscription<vision_msgs::msg::Detection3DArray>(
      "topic/name",
      rclcpp::SensorDataQoS{},
      std::bind(&PackageName::callback_topic_name, this, std::placeholders::_1),
      sub_options
    );

  // Topic 2
  // ...

  // Topic 3
  // ...


  /* ------------------------------------------------------------------------ */
  // Create pubs.
  /* ------------------------------------------------------------------------ */

  // Topic 1
  pub_topic_name_=
    node_->create_publisher<vision_msgs::msg::Detection3DArray>(
        "topic/name", 10);

  // Topic 2
  // ...

  // Topic 3
  // ...
}

void PackageName::callback_topic_name(
    const vision_msgs::msg::Detection3DArray::SharedPtr msg) {
  return;
}

}  // namespace package_name

// Register as a component
#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(package_name::PackageName)
