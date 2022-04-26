#include <rclcpp/rclcpp.hpp>

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("helloworld");
    rclcpp::WallRate loop(1);

    while(rclcpp::ok()) {
        RCLCPP_INFO(node->get_logger(), "Hello World!");
        loop.sleep();
    }
    rclcpp::shutdown();
    return 0;
}