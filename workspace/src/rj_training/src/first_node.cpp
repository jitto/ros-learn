#include<rclcpp/rclcpp.hpp>
#include<rclcpp_components/register_node_macro.hpp>
#include<std_msgs/msg/string.hpp>

namespace rj_training {
    class FirstNode : public rclcpp::Node {
    public:
        explicit FirstNode(const rclcpp::NodeOptions& options) : rclcpp::Node("first_node", options) {
            declare_parameter<std::string>("message_data", "Hello !");
            timer_ = create_wall_timer(std::chrono::seconds(1), std::bind(&FirstNode::TimerCallback, this));
            RCLCPP_INFO(get_logger(), "First node is ready");
        }
    private:
        rclcpp::TimerBase::SharedPtr timer_;
        void TimerCallback() {
            RCLCPP_INFO(get_logger(), get_parameter("message_data").as_string());
        }
    };
}

RCLCPP_COMPONENTS_REGISTER_NODE(rj_training::FirstNode)