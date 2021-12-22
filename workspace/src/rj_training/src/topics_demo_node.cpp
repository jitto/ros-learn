#include<rclcpp/rclcpp.hpp>
#include<rclcpp_components/register_node_macro.hpp>
#include<std_msgs/msg/string.hpp>

namespace rj_training {
    class TopicsDemoNode : public rclcpp::Node {
    public:
        explicit TopicsDemoNode(const rclcpp::NodeOptions& options) : rclcpp::Node("topics_demo_node", options) {
            publisher_ = create_publisher<std_msgs::msg::String>("/greeting", rclcpp::SystemDefaultsQoS());
            subscription_ = create_subscription<std_msgs::msg::String>("/name", rclcpp::SystemDefaultsQoS(), std::bind(&TopicsDemoNode::Callback, this, std::placeholders::_1));
            RCLCPP_INFO(get_logger(), "Subscriber ready!");
        }
    private:
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

        void Callback(const std_msgs::msg::String::SharedPtr msg) {
            std_msgs::msg::String greeting_msg;
            greeting_msg.data = "Hello, " + msg->data + "!";
            publisher_->publish(greeting_msg);
            // RCLCPP_INFO(get_logger(), "Published!");
        }
    };
}

RCLCPP_COMPONENTS_REGISTER_NODE(rj_training::TopicsDemoNode)