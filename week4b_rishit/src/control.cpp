
#include <chrono>
#include <memory>

#include <thread>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses a fancy C++11 lambda
* function to shorten the callback syntax, at the expense of making the
* code somewhat more difficult to understand at first glance. */

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("input_publisher")
  {
    publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/rover/control_input", 10);
    double pi=3.14159265358979323846;
        auto message = std_msgs::msg::Float64MultiArray();
        message.data ={0,0,0,0,1,1,1,1};
        RCLCPP_INFO(this->get_logger(), "Publishing: [%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf]'",
            message.data[0],message.data[1],message.data[2],message.data[3],message.data[4],message.data[5],
            message.data[6],message.data[7]);
        this->publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(),"Waiting for 2 seconds for rover to move");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        //Rotating wheels
        //
         message.data ={-pi/2,-pi/2,-pi/2,-pi/2,0,0,0,0};
         RCLCPP_INFO(this->get_logger(), "Publishing: [%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf]'",
             message.data[0],message.data[1],message.data[2],message.data[3],message.data[4],message.data[5],
             message.data[6],message.data[7]);
         this->publisher_->publish(message);
         RCLCPP_INFO(this->get_logger(),"Waiting for 2 seconds for wheel to rotate");
         std::this_thread::sleep_for(std::chrono::seconds(2));

         //Moving Rover
         message.data ={0,0,0,0,1,1,1,1};
         RCLCPP_INFO(this->get_logger(), "Publishing: [%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf]'",
             message.data[0],message.data[1],message.data[2],message.data[3],message.data[4],message.data[5],
             message.data[6],message.data[7]);
         this->publisher_->publish(message);
         RCLCPP_INFO(this->get_logger(),"Waiting for 2 seconds for rover to move");
         std::this_thread::sleep_for(std::chrono::seconds(2));

         //rotating wheels
         message.data ={-pi/4,pi/4,pi/4,-pi/4,0,0,0,0};
         RCLCPP_INFO(this->get_logger(), "Publishing: [%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf]'",
             message.data[0],message.data[1],message.data[2],message.data[3],message.data[4],message.data[5],
             message.data[6],message.data[7]);
         this->publisher_->publish(message);
         RCLCPP_INFO(this->get_logger(),"Waiting for 2 seconds for wheel to rotate");
         std::this_thread::sleep_for(std::chrono::seconds(2));

         //rotating rover
         message.data ={0,0,0,0,-1,1,-1,1};
         RCLCPP_INFO(this->get_logger(), "Publishing: [%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf]'",
             message.data[0],message.data[1],message.data[2],message.data[3],message.data[4],message.data[5],
             message.data[6],message.data[7]);
         this->publisher_->publish(message);
         RCLCPP_INFO(this->get_logger(),"Waiting for 1 seconds for rover to rotate");
         std::this_thread::sleep_for(std::chrono::seconds(1));

         // rotating wheels to 45 degree
         //rotating wheels
         message.data ={pi/4,pi/4,pi/4,pi/4,0,0,0,0};
         RCLCPP_INFO(this->get_logger(), "Publishing: [%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf]'",
             message.data[0],message.data[1],message.data[2],message.data[3],message.data[4],message.data[5],
             message.data[6],message.data[7]);
         this->publisher_->publish(message);
         RCLCPP_INFO(this->get_logger(),"Waiting for 2 seconds for wheel to rotate");
         std::this_thread::sleep_for(std::chrono::seconds(2));

         //moving rover
         message.data ={0,0,0,0,1,1,1,1};
         RCLCPP_INFO(this->get_logger(), "Publishing: [%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf]'",
             message.data[0],message.data[1],message.data[2],message.data[3],message.data[4],message.data[5],
             message.data[6],message.data[7]);
         this->publisher_->publish(message);
  }

private:
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
