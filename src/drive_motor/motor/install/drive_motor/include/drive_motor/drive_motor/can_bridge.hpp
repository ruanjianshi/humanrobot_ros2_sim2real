#ifndef DRIVE_MOTOR__CAN_BRIDGE_HPP_
#define DRIVE_MOTOR__CAN_BRIDGE_HPP_

#include "drive_motor/motor_hw.hpp"
#include <memory>
#include <string>
#include <vector>

namespace drive_motor
{

// ═══════════════════════════════════════════════════════════════════
// CanBridge — CANFD 电机硬件实现 (RDK X5)
//
// 通过 USB-CANFD 适配器与电机通信。
// 每个电机有独立的 CAN ID。
//
// 当前为单电机测试版：motorCount() == 1
// ═══════════════════════════════════════════════════════════════════
class CanBridge : public MotorHardware
{
public:
    /**
     * @param device   CAN 设备路径, e.g. "/dev/ttyACM0" 或 "can0"
     * @param can_ids  每个电机的 CAN ID 列表
     * @param baudrate 波特率 (1000000 = 1Mbps)
     */
    CanBridge(const std::string & device,
              const std::vector<int> & can_ids,
              int baudrate = 1000000);

    ~CanBridge() override;

    // ── MotorHardware 接口 ────────────────────────────────────
    float getPosition(int index) const override;
    float getVelocity(int index) const override;
    float getTorque  (int index) const override;
    float getCurrent (int index) const override;
    float getVoltage (int index) const override;
    int   getFault   (int index) const override;

    void cmdPosition     (int index, float pos) override;
    void cmdVelocity     (int index, float vel) override;
    void cmdTorque       (int index, float tqe) override;
    void cmdVoltage      (int index, float vol) override;
    void cmdCurrent      (int index, float cur) override;
    void cmdPosVelMaxTqe (int index, float pos, float vel, float tqe) override;
    void cmdPosVelTqeKpKd(int index, float pos, float vel, float tqe,
                          float kp, float kd) override;
    void cmdPosVelKpKd   (int index, float pos, float vel,
                          float kp, float kd) override;
    void cmdPosVelAcc    (int index, float pos, float vel, float acc) override;
    void cmdPosVelTqeKpKd2(int index, float pos, float vel, float tqe,
                           float kp, float kd) override;

    void sendAll() override;
    bool open()  override;
    void close() override;
    int  motorCount() const override { return motor_count_; }

private:
    struct MotorState
    {
        float position = 0.0f;
        float velocity = 0.0f;
        float torque   = 0.0f;
        float current  = 0.0f;
        float voltage  = 0.0f;
        int   fault    = 0;
    };

    struct MotorCmd
    {
        float position = 0.0f;
        float velocity = 0.0f;
        float torque   = 0.0f;
        float kp       = 0.0f;
        float kd       = 0.0f;
        bool  fresh    = false;   // 本帧是否写入过新命令
    };

    std::string    device_;
    std::vector<int> can_ids_;
    int            baudrate_;
    int            socket_fd_ = -1;

    std::vector<MotorState> motor_states_;
    std::vector<MotorCmd>   motor_cmds_;
    int motor_count_ = 0;
};

}  // namespace drive_motor

#endif  // DRIVE_MOTOR__CAN_BRIDGE_HPP_