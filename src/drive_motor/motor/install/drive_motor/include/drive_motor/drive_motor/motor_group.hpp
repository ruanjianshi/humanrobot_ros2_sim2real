#ifndef DRIVE_MOTOR__MOTOR_GROUP_HPP_
#define DRIVE_MOTOR__MOTOR_GROUP_HPP_

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <type_traits>

#include "drive_motor/motor_base.hpp"

namespace drive_motor
{

// ═══════════════════════════════════════════════════════════════════
// MotorGroup — 电机组批次管理 (与原始 ROS1 的 hightorque::MotorGroup 完全一致)
//
// 管理一组 MotorBase 派生电机对象。
// 支持: 批量读状态、批量写命令、按 index 排序、按名称查电机。
// ═══════════════════════════════════════════════════════════════════
class MotorGroup
{
public:
    // ── 构造函数1: 直接传入 MotorBase 指针 ──────────────────
    MotorGroup(int size, std::vector<std::shared_ptr<MotorBase>> motors)
        : size_(size), motors_(std::move(motors))
    {
        motorsMap_.reserve(motors_.size());
        for (const auto & motor : motors_)
        {
            index_.push_back(motor->getIndex());
            motorsMap_.emplace(motor->getName(), motor);
        }
    }

    // ── 构造函数2: 模板 — 支持 HtdwMotor 等派生类自动向上转型 ─
    template <typename Derived,
              typename = std::enable_if_t<std::is_base_of_v<MotorBase, Derived>>>
    MotorGroup(int size, const std::vector<std::shared_ptr<Derived>> & derivedMotors)
        : size_(size)
    {
        motors_.reserve(derivedMotors.size());
        motorsMap_.reserve(derivedMotors.size());
        for (const auto & motor : derivedMotors)
        {
            index_.push_back(motor->getIndex());
            motors_.push_back(motor);
            motorsMap_.emplace(motor->getName(), motor);
        }
    }

    virtual ~MotorGroup() { motorsMap_.clear(); motors_.clear(); }

    // ── 查询 ─────────────────────────────────────────────────
    inline int size() const { return size_; }
    inline const std::vector<int> & getIndex() const { return index_; }
    virtual std::shared_ptr<MotorBase> getMotor(const std::string & name) const;

    // ── 状态读取 ─────────────────────────────────────────────
    std::vector<MotorBackState> getMotorsBackState() const;
    std::string getMotorStateString() const;

    // ── 批量绝对控制 ─────────────────────────────────────────
    void setMotors(const std::vector<float> & target_q,
                   const std::vector<float> & target_dq,
                   const std::vector<float> & target_tau,
                   const std::vector<float> & target_kp,
                   const std::vector<float> & target_kd,
                   MotorControlType type = MotorControlType::POS_VEL_TQE_KP_KD2) const;

    void setMotors(const std::vector<MotorControlCmd> & cmds) const;

    // ── 批量相对控制 ─────────────────────────────────────────
    void setMotorsRelative(const std::vector<float> & target_q,
                           const std::vector<float> & target_dq,
                           const std::vector<float> & target_tau,
                           const std::vector<float> & target_kp,
                           const std::vector<float> & target_kd,
                           MotorControlType type = MotorControlType::POS_VEL_TQE_KP_KD2) const;

    void setMotorsRelative(const std::vector<MotorControlCmd> & cmds) const;

    // ── 按 index 升序绝对控制 (示教模式用) ───────────────────
    void setMotorsByIndexUp(const std::vector<float> & target_q,
                            const std::vector<float> & target_dq,
                            const std::vector<float> & target_tau,
                            const std::vector<float> & target_kp,
                            const std::vector<float> & target_kd,
                            MotorControlType type = MotorControlType::POS_VEL_TQE_KP_KD2) const;

    void setMotorsByIndexUp(const std::vector<MotorControlCmd> & cmds) const;

    // ── 安全 ─────────────────────────────────────────────────
    void protectMotor() const;

    virtual void keepMotorsLastCmd() const
    {
        for (const auto & motor : motors_)
            motor->keepMotorLastCmd();
    }

    virtual std::vector<std::shared_ptr<MotorBase>> getMotors() const
    {
        return motors_;
    }

private:
    std::vector<std::shared_ptr<MotorBase>> motors_;
    std::unordered_map<std::string, std::shared_ptr<MotorBase>> motorsMap_;
    int size_;
    std::vector<int> index_;
};

}  // namespace drive_motor

#endif  // DRIVE_MOTOR__MOTOR_GROUP_HPP_