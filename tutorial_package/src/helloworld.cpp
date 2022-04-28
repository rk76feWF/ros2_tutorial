#include <rclcpp/rclcpp.hpp>

int main(int argc, char ** argv)
{
    // プロセスの初期化
    rclcpp::init(argc, argv);
    // ノードの初期化
    auto node = rclcpp::Node::make_shared("helloworld");
    // ループ間隔を1Hzに設定
    rclcpp::WallRate loop(1);
    // CTRL+Cで中断されるまで無限ループ
    while(rclcpp::ok()) {
        RCLCPP_INFO(node->get_logger(), "Hello World!");
        loop.sleep();
    }
    // プロセスの終了
    rclcpp::shutdown();
    return 0;
}