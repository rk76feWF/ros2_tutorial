#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

int main(int argc, char **argv)
{
    // プロセスの初期化
    rclcpp::init(argc, argv);
    // ノードの初期化
    auto node = rclcpp::Node::make_shared("publicher");
    // パブリッシャーの初期化
    auto pub = node->create_publisher<std_msgs::msg::Int32>("number", 10);
    // ループ周期の設定
    rclcpp::WallRate loop(1);
    // パブリッシュするメッセージの宣言
    std_msgs::msg::Int32 msg;
    // CTRL+Cで中断されるまで無限ループ
    while(rclcpp::ok()) {
        msg.data++;
        RCLCPP_INFO(node->get_logger(), "I publish : %d", msg.data);
        // メッセージのパブリッシュ
        pub->publish(msg);
        loop.sleep();
    }
    // プロセスの終了
    rclcpp::shutdown();
    return 0;
}