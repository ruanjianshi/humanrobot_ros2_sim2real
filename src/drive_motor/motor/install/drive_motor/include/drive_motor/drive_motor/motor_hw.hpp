#ifndef DRIVE_MOTOR__MOTOR_HW_HPP_
#define DRIVE_MOTOR__MOTOR_HW_HPP_

#include <cstdint>
#include <vector>
#include <string>

namespace drive_motor
{

// ═══════════════════════════════════════════════════════════════════
// MotorHardware — 硬件抽象层基类
//
// 替代 ROS1 的 livelybot_serial::robot。
// 不同通信协议 (CANFD / RS485 / 串口) 各自实现子类。
// ═══════════════════════════════════════════════════════════════════
class MotorHardware
{
public:
    virtual ~MotorHardware() = default;

    // ── 单电机状态读取 ──────────────────────────────────────
    virtual float getPosition(int index) const = 0;
    virtual float getVelocity(int index) const = 0;
    virtual float getTorque  (int index) const = 0;
    virtual float getCurrent (int index) const = 0;
    virtual float getVoltage (int index) const = 0;
    virtual int   getFault   (int index) const = 0;

    // ── 单电机命令 (对应 MotorControlType 12 种模式) ────────
    virtual void cmdPosition     (int index, float pos) = 0;
    virtual void cmdVelocity     (int index, float vel) = 0;
    virtual void cmdTorque       (int index, float tqe) = 0;
    virtual void cmdVoltage      (int index, float vol) = 0;
    virtual void cmdCurrent      (int index, float cur) = 0;
    virtual void cmdPosVelMaxTqe (int index, float pos, float vel, float tqe) = 0;
    virtual void cmdPosVelTqeKpKd(int index, float pos, float vel, float tqe,
                                  float kp, float kd) = 0;
    virtual void cmdPosVelKpKd   (int index, float pos, float vel,
                                  float kp, float kd) = 0;
    virtual void cmdPosVelAcc    (int index, float pos, float vel, float acc) = 0;
    virtual void cmdPosVelTqeKpKd2(int index, float pos, float vel, float tqe,
                                   float kp, float kd) = 0;

    // ── 批量发送 ────────────────────────────────────────────
    virtual void sendAll() = 0;

    // ── 初始化/关闭 ─────────────────────────────────────────
    virtual bool open()  = 0;
    virtual void close() = 0;

    // ── 电机数量 ────────────────────────────────────────────
    virtual int motorCount() const = 0;
};

}  // namespace drive_motor

#endif  // DRIVE_MOTOR__MOTOR_HW_HPP_