#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("publicher");

    auto pub = node->create_publisher<std_msgs::msg::Int32>("number", 10);

    rclcpp::WallRate loop(1);
    std_msgs::msg::Int32 msg;

    while(rclcpp::ok()) {
        msg.data++;
        RCLCPP_INFO(node->get_logger(), "I publish : %d", msg.data);

        pub->publish(msg);
        loop.sleep();
    }
    rclcpp::shutdown();
    return 0;
}