/**
 * motor_hw.cpp — MotorHardware 的"无硬件"桩实现
 *
 * 当没有真实 CAN 设备时，提供一组内存模拟的电机状态。
 * 用于开发阶段在没有实体电机的情况下测试话题通信。
 */
#include "drive_motor/motor_hw.hpp"
#include <algorithm>
#include <memory>

namespace drive_motor
{

// ═══════════════════════════════════════════════════════════════════
// MockMotorHardware — 内存模拟实现 (无真实CAN设备时使用)
// ═══════════════════════════════════════════════════════════════════
class MockMotorHardware : public MotorHardware
{
public:
    explicit MockMotorHardware(int count)
        : positions_(count, 0.0f)
        , velocities_(count, 0.0f)
        , efforts_(count, 0.0f)
        , currents_(count, 0.0f)
        , voltages_(count, 24.0f)    // 默认 24V 母线电压
        , faults_(count, 0)
        , cmd_positions_(count, 0.0f)
        , cmd_velocities_(count, 0.0f)
        , cmd_efforts_(count, 0.0f)
        , cmd_kps_(count, 0.0f)
        , cmd_kds_(count, 0.0f)
        , motor_count_(count)
    {}

    // ── 状态读取 ─────────────────────────────────────────────
    float getPosition(int i) const override { return positions_[i]; }
    float getVelocity(int i) const override { return velocities_[i]; }
    float getTorque  (int i) const override { return efforts_[i]; }
    float getCurrent (int i) const override { return currents_[i]; }
    float getVoltage (int i) const override { return voltages_[i]; }
    int   getFault   (int i) const override { return faults_[i]; }

    // ── 命令写入 ─────────────────────────────────────────────
    void cmdPosition     (int i, float p) override { cmd_positions_[i] = p; }
    void cmdVelocity     (int i, float v) override { cmd_velocities_[i] = v; }
    void cmdTorque       (int i, float t) override { cmd_efforts_[i] = t; }
    void cmdVoltage      (int, float)     override {}
    void cmdCurrent      (int, float)     override {}
    void cmdPosVelMaxTqe (int i, float p, float v, float t) override
        { cmd_positions_[i] = p; cmd_velocities_[i] = v; cmd_efforts_[i] = t; }
    void cmdPosVelTqeKpKd(int i, float p, float v, float t, float kp, float kd) override
        { cmd_positions_[i] = p; cmd_velocities_[i] = v; cmd_efforts_[i] = t;
          cmd_kps_[i] = kp; cmd_kds_[i] = kd; }
    void cmdPosVelKpKd   (int i, float p, float v, float kp, float kd) override
        { cmd_positions_[i] = p; cmd_velocities_[i] = v;
          cmd_kps_[i] = kp; cmd_kds_[i] = kd; }
    void cmdPosVelAcc    (int i, float p, float v, float) override
        { cmd_positions_[i] = p; cmd_velocities_[i] = v; }
    void cmdPosVelTqeKpKd2(int i, float p, float v, float t, float kp, float kd) override
        { cmd_positions_[i] = p; cmd_velocities_[i] = v; cmd_efforts_[i] = t;
          cmd_kps_[i] = kp; cmd_kds_[i] = kd; }

    // ── 批量发送 + 模拟电机响应 ──────────────────────────────
    void sendAll() override
    {
        // 模拟电机: 位置 = 上一帧位置 + 低通响应
        for (int i = 0; i < motor_count_; ++i)
        {
            float target = cmd_positions_[i];
            float kp = cmd_kps_[i] > 0.1f ? cmd_kps_[i] : 0.0f;
            float kd = cmd_kds_[i] > 0.1f ? cmd_kds_[i] : 1.0f;
            float dt  = 0.002f;  // 500Hz

            // 一阶低通模拟: position += (target - position) * kp/kd * dt
            if (kp > 0)
            {
                float alpha = std::clamp(kp / kd * dt, 0.0f, 0.5f);
                positions_[i] += alpha * (target - positions_[i]);
            }
            else
            {
                positions_[i] = target;  // kp=0 → 直接到位
            }

            velocities_[i] = 0.0f;
            efforts_[i] = kp * (target - positions_[i]);
        }
    }

    bool open()  override { return true; }
    void close() override {}
    int  motorCount() const override { return motor_count_; }

private:
    std::vector<float> positions_;
    std::vector<float> velocities_;
    std::vector<float> efforts_;
    std::vector<float> currents_;
    std::vector<float> voltages_;
    std::vector<int>   faults_;

    std::vector<float> cmd_positions_;
    std::vector<float> cmd_velocities_;
    std::vector<float> cmd_efforts_;
    std::vector<float> cmd_kps_;
    std::vector<float> cmd_kds_;

    int motor_count_;
};

// ── 工厂函数 ──────────────────────────────────────────────────────
std::shared_ptr<MotorHardware> createMockHardware(int motorCount)
{
    return std::make_shared<MockMotorHardware>(motorCount);
}

}  // namespace drive_motor