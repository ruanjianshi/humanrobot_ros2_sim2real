/**
 * can_bridge.cpp — CANFD 电机通信实现
 *
 * RDK X5 通过 USB-CANFD 适配器与电机通信。
 * 每个电机有独立的 CAN ID。
 *
 * 当前为桩实现 (无真实 CAN 设备)：
 *   - 所有状态读写走内存模拟
 *   - open()/close() 只打日志
 *   - sendAll() 更新模拟电机状态
 *
 * 接入真实 CAN 硬件时，替换此文件中的 socket CAN 操作即可。
 */
#include "drive_motor/can_bridge.hpp"
#include <rclcpp/rclcpp.hpp>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

// ── Linux SocketCAN header (真实设备时取消注释) ───────────────────
// #include <unistd.h>
// #include <fcntl.h>
// #include <sys/socket.h>
// #include <sys/ioctl.h>
// #include <net/if.h>
// #include <linux/can.h>
// #include <linux/can/raw.h>

namespace drive_motor
{

// ═══════════════════════════════════════════════════════════════════
// 构造函数
// ═══════════════════════════════════════════════════════════════════
CanBridge::CanBridge(const std::string & device,
                     const std::vector<int> & can_ids,
                     int baudrate)
    : device_(device)
    , can_ids_(can_ids)
    , baudrate_(baudrate)
    , motor_count_(static_cast<int>(can_ids.size()))
{
    motor_states_.resize(motor_count_);
    motor_cmds_.resize(motor_count_);
}

CanBridge::~CanBridge()
{
    close();
}

// ═══════════════════════════════════════════════════════════════════
// open — 初始化 CAN 设备
// ═══════════════════════════════════════════════════════════════════
bool CanBridge::open()
{
    // ── 桩实现: 直接返回成功 ──────────────────────────────────
    RCLCPP_INFO(rclcpp::get_logger("CanBridge"),
                "CAN bridge opened (mock) device=%s, motors=%d",
                device_.c_str(), motor_count_);
    return true;

    // ── 真实 SocketCAN 实现 (取消注释) ─────────────────────────
    /*
    socket_fd_ = ::socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (socket_fd_ < 0) {
        RCLCPP_ERROR(rclcpp::get_logger("CanBridge"),
                     "Failed to create CAN socket: %s", strerror(errno));
        return false;
    }

    // 绑定到接口 (e.g. "can0")
    struct ifreq ifr;
    strncpy(ifr.ifr_name, device_.c_str(), IFNAMSIZ - 1);
    if (ioctl(socket_fd_, SIOCGIFINDEX, &ifr) < 0) {
        RCLCPP_ERROR(rclcpp::get_logger("CanBridge"),
                     "Failed to get interface index: %s", strerror(errno));
        ::close(socket_fd_);
        socket_fd_ = -1;
        return false;
    }

    struct sockaddr_can addr;
    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (::bind(socket_fd_, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        RCLCPP_ERROR(rclcpp::get_logger("CanBridge"),
                     "Failed to bind CAN socket: %s", strerror(errno));
        ::close(socket_fd_);
        socket_fd_ = -1;
        return false;
    }

    RCLCPP_INFO(rclcpp::get_logger("CanBridge"),
                "CAN socket bound to %s, fd=%d", device_.c_str(), socket_fd_);
    return true;
    */
}

// ═══════════════════════════════════════════════════════════════════
// close
// ═══════════════════════════════════════════════════════════════════
void CanBridge::close()
{
    // if (socket_fd_ >= 0) { ::close(socket_fd_); socket_fd_ = -1; }
    RCLCPP_INFO(rclcpp::get_logger("CanBridge"), "CAN bridge closed");
}

// ═══════════════════════════════════════════════════════════════════
// 状态读取 — 从 motor_states_[] 直接返回
// ═══════════════════════════════════════════════════════════════════
float CanBridge::getPosition(int i) const { return motor_states_[i].position; }
float CanBridge::getVelocity(int i) const { return motor_states_[i].velocity; }
float CanBridge::getTorque  (int i) const { return motor_states_[i].torque; }
float CanBridge::getCurrent (int i) const { return motor_states_[i].current; }
float CanBridge::getVoltage (int i) const { return motor_states_[i].voltage; }
int   CanBridge::getFault   (int i) const { return motor_states_[i].fault; }

// ═══════════════════════════════════════════════════════════════════
// 命令写入 — 存入 motor_cmds_[]
// ═══════════════════════════════════════════════════════════════════
void CanBridge::cmdPosition(int i, float p)
    { motor_cmds_[i] = {p, 0, 0, 0, 0, true}; }
void CanBridge::cmdVelocity(int i, float v)
    { motor_cmds_[i] = {0, v, 0, 0, 0, true}; }
void CanBridge::cmdTorque(int i, float t)
    { motor_cmds_[i] = {0, 0, t, 0, 0, true}; }
void CanBridge::cmdVoltage(int, float) {}
void CanBridge::cmdCurrent(int, float) {}

void CanBridge::cmdPosVelMaxTqe(int i, float p, float v, float t)
    { motor_cmds_[i] = {p, v, t, 0, 0, true}; }
void CanBridge::cmdPosVelTqeKpKd(int i, float p, float v, float t, float kp, float kd)
    { motor_cmds_[i] = {p, v, t, kp, kd, true}; }
void CanBridge::cmdPosVelKpKd(int i, float p, float v, float kp, float kd)
    { motor_cmds_[i] = {p, v, 0, kp, kd, true}; }
void CanBridge::cmdPosVelAcc(int i, float p, float v, float)
    { motor_cmds_[i] = {p, v, 0, 0, 0, true}; }
void CanBridge::cmdPosVelTqeKpKd2(int i, float p, float v, float t, float kp, float kd)
    { motor_cmds_[i] = {p, v, t, kp, kd, true}; }

// ═══════════════════════════════════════════════════════════════════
// sendAll — 批量发送 + 模拟电机响应
// ═══════════════════════════════════════════════════════════════════
void CanBridge::sendAll()
{
    // ── 桩实现: 模拟电机低通响应 ──────────────────────────────
    constexpr float dt = 0.002f;   // 500Hz

    for (int i = 0; i < motor_count_; ++i)
    {
        if (!motor_cmds_[i].fresh)
            continue;   // 本帧无新命令, 跳过

        float target = motor_cmds_[i].position;
        float kp = motor_cmds_[i].kp;
        float kd = motor_cmds_[i].kd;
        if (kd < 0.1f) kd = 1.0f;

        float & pos = motor_states_[i].position;
        float & vel = motor_states_[i].velocity;

        if (kp > 0.0f)
        {
            // 一阶低通: pos += alpha * (target - pos)
            float alpha = std::clamp(kp / kd * dt, 0.0f, 0.5f);
            pos += alpha * (target - pos);
            vel = (pos - motor_states_[i].velocity + vel) * 0.5f;   // 平滑速度
        }
        else
        {
            pos = target;
            vel = 0.0f;
        }

        motor_states_[i].torque = kp * (target - pos) - kd * vel;

        motor_cmds_[i].fresh = false;
    }

    // ── 真实实现: 构造 CAN 帧发送, 读取 CAN 帧更新状态 ────────
    /*
    for (int i = 0; i < motor_count_; ++i) {
        if (!motor_cmds_[i].fresh) continue;

        struct can_frame frame;
        frame.can_id = can_ids_[i];
        frame.can_dlc = 8;
        // 按电机协议打包: 位置 (int16) + 速度 (int16) + kp (int16) + kd (int16)
        int16_t pos_int = static_cast<int16_t>(motor_cmds_[i].position * 1000);  // rad → mrad
        int16_t vel_int = static_cast<int16_t>(motor_cmds_[i].velocity * 100);
        int16_t kp_int  = static_cast<int16_t>(motor_cmds_[i].kp * 10);
        int16_t kd_int  = static_cast<int16_t>(motor_cmds_[i].kd * 10);

        memcpy(&frame.data[0], &pos_int, 2);
        memcpy(&frame.data[2], &vel_int, 2);
        memcpy(&frame.data[4], &kp_int,  2);
        memcpy(&frame.data[6], &kd_int,  2);

        if (::write(socket_fd_, &frame, sizeof(frame)) < 0)
            RCLCPP_WARN_THROTTLE(...);

        motor_cmds_[i].fresh = false;
    }
    */
}

}  // namespace drive_motor