/**
 * motor_group.cpp — MotorGroup 实现
 *
 * 与原始 ROS1 motor_group.cpp 完全一致。
 * 唯一变化: motor_back_t → MotorBackState
 */
#include "drive_motor/motor_group.hpp"

namespace drive_motor
{

// ═══════════════════════════════════════════════════════════════════
// getMotorsBackState — 批量读所有电机反馈
// ═══════════════════════════════════════════════════════════════════
std::vector<MotorBackState> MotorGroup::getMotorsBackState() const
{
    std::vector<MotorBackState> states;
    states.reserve(size_);
    for (const auto & motor : motors_)
        states.push_back(motor->getMotorBackState());
    return states;
}

// ═══════════════════════════════════════════════════════════════════
// getMotorStateString — 调试用状态字符串
// ═══════════════════════════════════════════════════════════════════
std::string MotorGroup::getMotorStateString() const
{
    std::stringstream ss;
    ss << "MotorGroup (size=" << size_ << "):\n";
    for (int i = 0; i < size_; ++i)
    {
        const auto & motor = motors_[i];
        auto s = motor->getMotorBackState();
        ss << "  [" << i << "] " << motor->getName()
           << " (idx=" << motor->getIndex() << "): "
           << "pos=" << s.position << " vel=" << s.velocity
           << " tqe=" << s.torque << "\n";
    }
    return ss.str();
}

// ═══════════════════════════════════════════════════════════════════
// setMotors — 批量绝对控制 (向量参数版)
// ═══════════════════════════════════════════════════════════════════
void MotorGroup::setMotors(
    const std::vector<float> & target_q,
    const std::vector<float> & target_dq,
    const std::vector<float> & target_tau,
    const std::vector<float> & target_kp,
    const std::vector<float> & target_kd,
    MotorControlType type) const
{
    for (int i = 0; i < size_; ++i)
    {
        motors_[i]->setMotor(
            target_q[i], target_dq[i], target_tau[i],
            target_kp[i], 0, target_kd[i],
            0, 0, 0, type);
    }
}

// ═══════════════════════════════════════════════════════════════════
// setMotors — 批量绝对控制 (结构体版)
// ═══════════════════════════════════════════════════════════════════
void MotorGroup::setMotors(const std::vector<MotorControlCmd> & cmds) const
{
    for (int i = 0; i < size_; ++i)
        motors_[i]->setMotor(cmds[i]);
}

// ═══════════════════════════════════════════════════════════════════
// setMotorsRelative — 批量相对控制
// ═══════════════════════════════════════════════════════════════════
void MotorGroup::setMotorsRelative(
    const std::vector<float> & target_q,
    const std::vector<float> & target_dq,
    const std::vector<float> & target_tau,
    const std::vector<float> & target_kp,
    const std::vector<float> & target_kd,
    MotorControlType type) const
{
    for (int i = 0; i < size_; ++i)
    {
        motors_[i]->setMotorRelative(
            target_q[i], target_dq[i], target_tau[i],
            target_kp[i], 0, target_kd[i],
            0, 0, 0, type);
    }
}

void MotorGroup::setMotorsRelative(const std::vector<MotorControlCmd> & cmds) const
{
    for (int i = 0; i < size_; ++i)
        motors_[i]->setMotorRelative(cmds[i]);
}

// ═══════════════════════════════════════════════════════════════════
// setMotorsByIndexUp — 按 index 升序发送 (示教模式用)
// ═══════════════════════════════════════════════════════════════════
void MotorGroup::setMotorsByIndexUp(
    const std::vector<float> & target_q,
    const std::vector<float> & target_dq,
    const std::vector<float> & target_tau,
    const std::vector<float> & target_kp,
    const std::vector<float> & target_kd,
    MotorControlType type) const
{
    auto sorted = motors_;
    std::sort(sorted.begin(), sorted.end(),
              [](const auto & a, const auto & b) { return a->getIndex() < b->getIndex(); });

    for (size_t i = 0; i < sorted.size(); ++i)
    {
        sorted[i]->setMotor(
            target_q[i], target_dq[i], target_tau[i],
            target_kp[i], 0, target_kd[i],
            0, 0, 0, type);
    }
}

void MotorGroup::setMotorsByIndexUp(const std::vector<MotorControlCmd> & cmds) const
{
    auto sorted = motors_;
    std::sort(sorted.begin(), sorted.end(),
              [](const auto & a, const auto & b) { return a->getIndex() < b->getIndex(); });

    for (size_t i = 0; i < sorted.size(); ++i)
        sorted[i]->setMotor(cmds[i]);
}

// ═══════════════════════════════════════════════════════════════════
// protectMotor — 批量保护
// ═══════════════════════════════════════════════════════════════════
void MotorGroup::protectMotor() const
{
    for (const auto & motor : motors_)
        motor->protectMotor();
}

// ═══════════════════════════════════════════════════════════════════
// getMotor — 按名称查找单个电机 (O(1))
// ═══════════════════════════════════════════════════════════════════
std::shared_ptr<MotorBase> MotorGroup::getMotor(const std::string & name) const
{
    auto it = motorsMap_.find(name);
    if (it == motorsMap_.end())
    {
        std::cerr << "[MotorGroup] motor not found: " << name << std::endl;
        return nullptr;
    }
    return it->second;
}

}  // namespace drive_motor