#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
// グローバル変数の宣言
rclcpp::Node::SharedPtr g_node = nullptr;

// Int32型をサブスクライブするコールバック関数
void onNumberSubscribed(const std_msgs::msg::Int32::SharedPtr msg)
{
    RCLCPP_INFO(g_node->get_logger(), "I heard : %d", msg->data);
}

int main(int argc, char **argv)
{
    // プロセスの初期化
    rclcpp::init(argc, argv);
    // ノードの初期化
    g_node = rclcpp::Node::make_shared("subscriber");
    // サブスクライバの初期化
    auto sub = g_node->create_subscription<std_msgs::msg::Int32>("number", 10, onNumberSubscribed);
    // コールバック関数の発生を待機
    rclcpp::spin(g_node);
    // プロセスの終了
    g_node = nullptr;
    rclcpp::shutdown();
    return 0;
}