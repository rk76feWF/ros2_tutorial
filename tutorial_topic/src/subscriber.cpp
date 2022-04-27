#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

rclcpp::Node::SharedPtr g_node = nullptr;

void onNumberSubscribed(const std_msgs::msg::Int32::SharedPtr msg)
{
    RCLCPP_INFO(g_node->get_logger(), "I heard : %d", msg->data);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    g_node = rclcpp::Node::make_shared("subscriber");

    auto sub = g_node->create_subscription<std_msgs::msg::Int32>("number", 10, onNumberSubscribed);

    rclcpp::spin(g_node);
    g_node = nullptr;
    rclcpp::shutdown();
    return 0;
}