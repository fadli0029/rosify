#pragma once

// Typical includes.
#include <iostream>

// STL data containers, add more.
#include <vector>
#include <algorithm>

// ROS2 includes, add more.
#include "rclcpp/rclcpp.hpp"

// ROS2 messages, add more.
#include "std_msgs/msg/string.hpp"
#include "vision_msgs/msg/detection3_d_array.hpp"

namespace package_name
{


class PackageName
{
  public:
    PackageName(const rclcpp::NodeOptions& options);

    rclcpp::node_interfaces::NodeBaseInterface::SharedPtr
    get_node_base_interface()
    {
      return node_->get_node_base_interface();
    }

    // Callbacks
    void callback_topic_name(const vision_msgs::msg::Detection3DArray::SharedPtr msg);

    // Other methods
    // ...

  private:

    // Publishers
    rclcpp::Publisher<vision_msgs::msg::Detection3DArray>::SharedPtr pub_topic_name_;

    // Subscribers
    rclcpp::Subscription<vision_msgs::msg::Detection3DArray>::SharedPtr sub_topic_name_;

    // Callback groups
    rclcpp::CallbackGroup::SharedPtr callback_gp_topic_name_;

    // Others
    rclcpp::Node::SharedPtr node_;

};

} // namespace package_name
