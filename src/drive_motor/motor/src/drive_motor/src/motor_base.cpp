/**
 * motor_base.cpp — HtdwMotor 实现
 *
 * 完全保留原始 ROS1 htdw_motor.cpp 的控制逻辑：
 *   - 12 种 MotorControlType 的 switch-case 分发
 *   - 机械限位钳位 (POS_VEL_MAX_TQE 模式放宽到 ±6.0)
 *   - lastCmd_ 记录 + protectMotor (kp=0,kd=1)
 *
 * 唯一变化: rbPtr_->Motors[index]->xxx() 替换为 hw_->cmdXxx(index, ...)
 */
#include "drive_motor/motor_base.hpp"
#include "drive_motor/motor_hw.hpp"
#include <rclcpp/rclcpp.hpp>

namespace drive_motor
{

// ═══════════════════════════════════════════════════════════════════
// 构造函数
// ═══════════════════════════════════════════════════════════════════
HtdwMotor::HtdwMotor(std::shared_ptr<MotorHardware> hw,
                     int index,
                     const std::string & name,
                     double lowest,
                     double highest)
    : hw_(std::move(hw))
    , index_(index)
    , name_(name)
    , lowest_(lowest)
    , highest_(highest)
{}

// ═══════════════════════════════════════════════════════════════════
// getMotorBackState — 从 MotorHardware 读取反馈
// ═══════════════════════════════════════════════════════════════════
MotorBackState HtdwMotor::getMotorBackState() const
{
    MotorBackState state;
    state.position = hw_->getPosition(index_);
    state.velocity = hw_->getVelocity(index_);
    state.torque   = hw_->getTorque(index_);
    state.current  = hw_->getCurrent(index_);
    state.voltage  = hw_->getVoltage(index_);
    state.fault    = hw_->getFault(index_);

    if (state.fault > 0)
    {
        RCLCPP_WARN_THROTTLE(
            rclcpp::get_logger("HtdwMotor"),
            *rclcpp::Clock::make_shared(), 2000,
            "[%d] %s fault code: %d",
            index_, name_.c_str(), state.fault);
    }
    return state;
}

// ═══════════════════════════════════════════════════════════════════
// setMotor(float...) — 绝对控制 (与原始完全一致)
// ═══════════════════════════════════════════════════════════════════
void HtdwMotor::setMotor(float position, float velocity, float torque,
                         float kp, float ki, float kd,
                         float acc, float voltage, float current,
                         MotorControlType type)
{
    // 限位保护 — POS_VEL_MAX_TQE 模式放宽限位
    auto highest = (type == POS_VEL_MAX_TQE) ? 6.0 : highest_;
    auto lowest  = (type == POS_VEL_MAX_TQE) ? -6.0 : lowest_;

    if (position > highest) position = highest;
    if (position < lowest)  position = lowest;

    lastCmd_ = MotorControlCmd(position, velocity, torque,
                               kp, ki, kd,
                               acc, voltage, current, type);

    // ── 12 种控制模式分发 (与原始完全一致) ────────────────────
    switch (type)
    {
        case POS:                hw_->cmdPosition(index_, position); break;
        case VEL:                hw_->cmdVelocity(index_, velocity); break;
        case TQE:                hw_->cmdTorque(index_, torque); break;
        case VOL:                hw_->cmdVoltage(index_, voltage); break;
        case CUR:                hw_->cmdCurrent(index_, current); break;
        case POS_VEL_MAX_TQE:    hw_->cmdPosVelMaxTqe(index_, position, velocity, torque); break;
        case POS_VEL_TQE_RKP_RKD:
        case POS_VEL_TQE_KP_KD:  hw_->cmdPosVelTqeKpKd(index_, position, velocity, torque, kp, kd); break;
        case POS_VEL_RKP_RKD:
        case POS_VEL_KP_KD:      hw_->cmdPosVelKpKd(index_, position, velocity, kp, kd); break;
        case POS_VEL_ACC:        hw_->cmdPosVelAcc(index_, position, velocity, acc); break;
        case POS_VEL_TQE_KP_KD2: hw_->cmdPosVelTqeKpKd2(index_, position, velocity, torque, kp, kd); break;
    }
}

// ═══════════════════════════════════════════════════════════════════
// setMotor(MotorControlCmd) — 结构体版本
// ═══════════════════════════════════════════════════════════════════
void HtdwMotor::setMotor(MotorControlCmd cmd)
{
    auto highest = (cmd.type == POS_VEL_MAX_TQE) ? 6.0 : highest_;
    auto lowest  = (cmd.type == POS_VEL_MAX_TQE) ? -6.0 : lowest_;

    if (cmd.position > highest) cmd.position = highest;
    if (cmd.position < lowest)  cmd.position = lowest;

    setMotor(cmd.position, cmd.velocity, cmd.torque,
             cmd.kp, cmd.ki, cmd.kd,
             cmd.acc, cmd.voltage, cmd.current, cmd.type);
}

// ═══════════════════════════════════════════════════════════════════
// setMotorRelative — 相对控制 (当前位置 + 偏移)
// ═══════════════════════════════════════════════════════════════════
void HtdwMotor::setMotorRelative(float relativePosition, float velocity, float torque,
                                 float kp, float ki, float kd,
                                 float acc, float voltage, float current,
                                 MotorControlType type)
{
    float currentPosition = getMotorBackState().position;
    float position = currentPosition + relativePosition;
    setMotor(position, velocity, torque, kp, ki, kd, acc, voltage, current, type);
}

void HtdwMotor::setMotorRelative(MotorControlCmd cmd)
{
    float currentPosition = getMotorBackState().position;
    cmd.position += currentPosition;
    setMotor(cmd);
}

// ═══════════════════════════════════════════════════════════════════
// protectMotor — 安全保护: kp=0, kd=1 → 电机无力可推动
// ═══════════════════════════════════════════════════════════════════
void HtdwMotor::protectMotor()
{
    float kp = 0.0f, kd = 1.0f;
    setMotor(0, 0, 0, kp, 0, kd, 0, 0, 0);
    lastCmd_ = MotorControlCmd(0, 0, 0, kp, 0, kd, 0, 0, 0);
}

// ═══════════════════════════════════════════════════════════════════
// keepMotorLastCmd — 重发上一帧指令
// ═══════════════════════════════════════════════════════════════════
void HtdwMotor::keepMotorLastCmd()
{
    setMotor(lastCmd_.position, lastCmd_.velocity, lastCmd_.torque,
             lastCmd_.kp, lastCmd_.ki, lastCmd_.kd,
             lastCmd_.acc, lastCmd_.voltage, lastCmd_.current, lastCmd_.type);
}

}  // namespace drive_motor