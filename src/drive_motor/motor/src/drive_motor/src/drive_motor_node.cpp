/**
 * drive_motor_node.cpp — ROS2 电机驱动主节点
 *
 * 架构:
 *   ┌────────────────────────────────────────────────────┐
 *   │  main_loop() @ 500Hz (rclcpp::WallTimer)           │
 *   │                                                     │
 *   │  1. 读取电机编码器 (hw_->getPosition/Velocity/...)  │
 *   │  2. 发布 /motor_state (MotorState)                  │
 *   │  3. 检查 motor_cmd_sub_ 是否有新指令                 │
 *   │     - 有新指令 → 写入电机 (motor_group_->setMotors) │
 *   │     - 无新指令 → keepMotorLastCmd()                 │
 *   │  4. hw_->sendAll() 批量发送到 CAN/RS485 硬件        │
 *   └────────────────────────────────────────────────────┘
 *
 * 订阅: /motor_cmd  (MotorCmd)    — sim2real 下发的控制指令
 * 发布: /motor_state (MotorState)  — 电机当前位置/速度/力矩
 */
#include <rclcpp/rclcpp.hpp>
#include <motor_interfaces/msg/motor_state.hpp>
#include <motor_interfaces/msg/motor_cmd.hpp>

#include "drive_motor/motor_base.hpp"
#include "drive_motor/motor_group.hpp"
#include "drive_motor/motor_hw.hpp"
#include "drive_motor/can_bridge.hpp"

#include <memory>
#include <vector>
#include <string>
#include <atomic>
#include <mutex>

using namespace std::chrono_literals;

namespace drive_motor
{

class DriveMotorNode : public rclcpp::Node
{
public:
    DriveMotorNode()
        : Node("drive_motor_node")
    {
        // ── 参数声明 ────────────────────────────────────────
        this->declare_parameter("motor_count", 1);
        this->declare_parameter("can_device", "/dev/ttyACM0");
        this->declare_parameter("can_baudrate", 1000000);
        this->declare_parameter("joint_names",
            std::vector<std::string>{"motor_0"});
        this->declare_parameter("joint_lower_limits",
            std::vector<double>{-6.0});
        this->declare_parameter("joint_upper_limits",
            std::vector<double>{6.0});
        this->declare_parameter("kp_default", 55.0);
        this->declare_parameter("kd_default", 0.8);
        this->declare_parameter("loop_rate", 500);

        // ── 读取参数 ────────────────────────────────────────
        int motor_count = this->get_parameter("motor_count").as_int();
        std::string can_dev = this->get_parameter("can_device").as_string();
        int can_br = this->get_parameter("can_baudrate").as_int();
        auto joint_names = this->get_parameter("joint_names")
                               .as_string_array();
        auto lower_limits = this->get_parameter("joint_lower_limits")
                                .as_double_array();
        auto upper_limits = this->get_parameter("joint_upper_limits")
                                .as_double_array();
        double kp_def = this->get_parameter("kp_default").as_double();
        double kd_def = this->get_parameter("kd_default").as_double();
        int rate_hz = this->get_parameter("loop_rate").as_int();

        // 确保 vector 大小匹配
        joint_names.resize(motor_count, "motor");
        lower_limits.resize(motor_count, -6.0);
        upper_limits.resize(motor_count, 6.0);

        // ── 创建硬件层 ──────────────────────────────────────
        std::vector<int> can_ids(motor_count);
        for (int i = 0; i < motor_count; ++i)
            can_ids[i] = i + 1;   // CAN ID: 1, 2, 3, ...

        can_bridge_ = std::make_shared<CanBridge>(can_dev, can_ids, can_br);
        can_bridge_->open();

        // ── 创建 HtdwMotor 对象 (每个电机一个) ──────────────
        std::vector<std::shared_ptr<MotorBase>> motors;
        motors.reserve(motor_count);
        for (int i = 0; i < motor_count; ++i)
        {
            auto motor = std::make_shared<HtdwMotor>(
                can_bridge_,
                i,                        // index (对应 CAN ID = i+1)
                joint_names[i],           // name
                lower_limits[i],          // lowest
                upper_limits[i]           // highest
            );
            motors.push_back(motor);

            RCLCPP_INFO(this->get_logger(),
                "Created motor[%d]: %s  limit=[%.2f, %.2f]",
                i, joint_names[i].c_str(),
                lower_limits[i], upper_limits[i]);
        }

        // ── 创建 MotorGroup ─────────────────────────────────
        motor_group_ = std::make_shared<MotorGroup>(motor_count, motors);

        // ── 初始化电机状态存储 ──────────────────────────────
        motor_state_pos_.resize(motor_count, 0.0f);
        motor_state_vel_.resize(motor_count, 0.0f);
        motor_state_tau_.resize(motor_count, 0.0f);

        motor_cmd_pos_.resize(motor_count, 0.0f);
        motor_cmd_vel_.resize(motor_count, 0.0f);
        motor_cmd_tau_.resize(motor_count, 0.0f);
        motor_cmd_kp_.resize(motor_count, kp_def);
        motor_cmd_kd_.resize(motor_count, kd_def);
        has_new_cmd_ = false;

        // ── ROS2 发布 /motor_state ──────────────────────────
        motor_state_pub_ = this->create_publisher<
            motor_interfaces::msg::MotorState>("/motor_state", 10);

        // ── ROS2 订阅 /motor_cmd ────────────────────────────
        motor_cmd_sub_ = this->create_subscription<
            motor_interfaces::msg::MotorCmd>(
            "/motor_cmd", 10,
            std::bind(&DriveMotorNode::motorCmdCallback,
                      this, std::placeholders::_1));

        // ── 500Hz 定时器 ────────────────────────────────────
        auto period = std::chrono::microseconds(1000000 / rate_hz);
        loop_timer_ = this->create_wall_timer(
            period, std::bind(&DriveMotorNode::mainLoop, this));

        RCLCPP_INFO(this->get_logger(),
            "drive_motor_node started: %d motors @ %d Hz, device=%s",
            motor_count, rate_hz, can_dev.c_str());
    }

    ~DriveMotorNode() override
    {
        if (can_bridge_)
            can_bridge_->close();
    }

private:
    // ══════════════════════════════════════════════════════════
    // motorCmdCallback — 接收 sim2real 下发的 /motor_cmd
    // ══════════════════════════════════════════════════════════
    void motorCmdCallback(
        const motor_interfaces::msg::MotorCmd::ConstSharedPtr msg)
    {
        std::lock_guard<std::mutex> lock(cmd_mutex_);

        int n = std::min({
            static_cast<int>(msg->target_q.size()),
            static_cast<int>(msg->target_dq.size()),
            static_cast<int>(msg->target_tau.size()),
            static_cast<int>(msg->target_kp.size()),
            static_cast<int>(msg->target_kd.size()),
            static_cast<int>(motor_cmd_pos_.size())
        });

        for (int i = 0; i < n; ++i)
        {
            motor_cmd_pos_[i] = msg->target_q[i];
            motor_cmd_vel_[i] = msg->target_dq[i];
            motor_cmd_tau_[i] = msg->target_tau[i];
            motor_cmd_kp_[i]  = msg->target_kp[i];
            motor_cmd_kd_[i]  = msg->target_kd[i];
        }

        has_new_cmd_ = true;
    }

    // ══════════════════════════════════════════════════════════
    // mainLoop — 500Hz 驱动循环
    // ══════════════════════════════════════════════════════════
    void mainLoop()
    {
        // ── 1. 读取所有电机编码器 ───────────────────────────
        auto states = motor_group_->getMotorsBackState();
        int n = static_cast<int>(states.size());

        for (int i = 0; i < n; ++i)
        {
            motor_state_pos_[i] = states[i].position;
            motor_state_vel_[i] = states[i].velocity;
            motor_state_tau_[i] = states[i].torque;
        }

        // ── 2. 发布 /motor_state ────────────────────────────
        {
            auto msg = motor_interfaces::msg::MotorState();
            msg.position.resize(n);
            msg.velocity.resize(n);
            msg.torque.resize(n);

            for (int i = 0; i < n; ++i)
            {
                msg.position[i] = motor_state_pos_[i];
                msg.velocity[i] = motor_state_vel_[i];
                msg.torque[i]   = motor_state_tau_[i];
            }

            motor_state_pub_->publish(msg);
        }

        // ── 3. 处理 /motor_cmd 指令 ─────────────────────────
        {
            std::lock_guard<std::mutex> lock(cmd_mutex_);

            if (has_new_cmd_)
            {
                // 有新指令 → 写入所有电机
                motor_group_->setMotors(
                    motor_cmd_pos_, motor_cmd_vel_, motor_cmd_tau_,
                    motor_cmd_kp_,  motor_cmd_kd_,
                    MotorControlType::POS_VEL_TQE_KP_KD2);

                has_new_cmd_ = false;
            }
            else
            {
                // 无新指令 → 保持上一帧指令
                motor_group_->keepMotorsLastCmd();
            }
        }

        // ── 4. 批量发送到硬件 ───────────────────────────────
        can_bridge_->sendAll();
    }

    // ── 硬件层 ──────────────────────────────────────────────
    std::shared_ptr<CanBridge>   can_bridge_;

    // ── 电机对象 ────────────────────────────────────────────
    std::shared_ptr<MotorGroup>  motor_group_;

    // ── 状态存储 (发布) ─────────────────────────────────────
    std::vector<float> motor_state_pos_;
    std::vector<float> motor_state_vel_;
    std::vector<float> motor_state_tau_;

    // ── 命令存储 (订阅) ─────────────────────────────────────
    std::vector<float> motor_cmd_pos_;
    std::vector<float> motor_cmd_vel_;
    std::vector<float> motor_cmd_tau_;
    std::vector<float> motor_cmd_kp_;
    std::vector<float> motor_cmd_kd_;
    bool               has_new_cmd_ = false;
    std::mutex         cmd_mutex_;

    // ── ROS2 接口 ───────────────────────────────────────────
    rclcpp::Publisher<motor_interfaces::msg::MotorState>::SharedPtr
        motor_state_pub_;
    rclcpp::Subscription<motor_interfaces::msg::MotorCmd>::SharedPtr
        motor_cmd_sub_;
    rclcpp::TimerBase::SharedPtr loop_timer_;
};

}  // namespace drive_motor

// ═════════════════════════════════════════════════════════════════
// main
// ═════════════════════════════════════════════════════════════════
int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<drive_motor::DriveMotorNode>());
    rclcpp::shutdown();
    return 0;
}