#ifndef DRIVE_MOTOR__MOTOR_BASE_HPP_
#define DRIVE_MOTOR__MOTOR_BASE_HPP_

#include <string>
#include <sstream>
#include <memory>

// 前向声明 — 硬件抽象层 (替代 livelybot_serial::robot)
namespace drive_motor
{
class MotorHardware;
}

namespace drive_motor
{

// ═══════════════════════════════════════════════════════════════════
// MotorControlType — 与原始 C++ 完全一致的 12 种控制模式
// ═══════════════════════════════════════════════════════════════════
enum MotorControlType
{
    POS = 1,
    VEL = 2,
    TQE = 3,
    VOL = 4,
    CUR = 5,
    POS_VEL_MAX_TQE = 6,
    POS_VEL_TQE_RKP_RKD = 7,
    POS_VEL_RKP_RKD = 8,
    POS_VEL_TQE_KP_KD = 9,
    POS_VEL_KP_KD = 10,
    POS_VEL_ACC = 11,
    POS_VEL_TQE_KP_KD2 = 12,
};

// ═══════════════════════════════════════════════════════════════════
// MotorBackState — 硬件无关的电机反馈 (替代原始 motor_back_t)
// ═══════════════════════════════════════════════════════════════════
struct MotorBackState
{
    float position = 0.0f;
    float velocity = 0.0f;
    float torque   = 0.0f;
    float current  = 0.0f;     // 电机电流 (A)
    float voltage  = 0.0f;     // 母线电压 (V)
    int   fault    = 0;        // 故障码, >0 表示异常
};

// ═══════════════════════════════════════════════════════════════════
// MotorControlCmd — 控制指令包 (与原始完全一致)
// ═══════════════════════════════════════════════════════════════════
class MotorControlCmd
{
public:
    MotorControlCmd(
        float pos = 0.0f, float vel = 0.0f, float tqe = 0.0f,
        float kp = 0.0f, float ki = 0.0f, float kd = 0.0f,
        float acc = 0.0f, float vol = 0.0f, float cur = 0.0f,
        MotorControlType type = MotorControlType::POS_VEL_TQE_KP_KD2)
        : position(pos), velocity(vel), torque(tqe),
          kp(kp), ki(ki), kd(kd),
          acc(acc), voltage(vol), current(cur), type(type)
    {}

    float position  = 0.0f;
    float velocity  = 0.0f;
    float torque    = 0.0f;
    float kp        = 0.0f;
    float ki        = 0.0f;
    float kd        = 0.0f;
    float acc       = 0.0f;
    float voltage   = 0.0f;
    float current   = 0.0f;
    MotorControlType type = MotorControlType::POS_VEL_TQE_KP_KD2;

    std::string toString() const
    {
        std::ostringstream oss;
        oss << "MotorControlCmd(p=" << position << " v=" << velocity
            << " t=" << torque << " kp=" << kp << " kd=" << kd
            << " type=" << static_cast<int>(type) << ")";
        return oss.str();
    }
};

// ═══════════════════════════════════════════════════════════════════
// MotorBase — 电机控制抽象基类 (与原始完全一致)
// ═══════════════════════════════════════════════════════════════════
class MotorBase
{
public:
    virtual ~MotorBase() = default;

    // ── 属性 ──────────────────────────────────────────────────
    virtual std::string getName() const = 0;
    virtual int         getIndex() const = 0;

    // ── 状态 ──────────────────────────────────────────────────
    virtual MotorBackState getMotorBackState() const = 0;

    // ── 绝对控制 ──────────────────────────────────────────────
    virtual void setMotor(
        float position, float velocity, float torque,
        float kp, float ki, float kd,
        float acc, float voltage, float current,
        MotorControlType type = MotorControlType::POS_VEL_TQE_KP_KD2) = 0;

    virtual void setMotor(MotorControlCmd cmd) = 0;

    // ── 相对控制 (当前位置 + 偏移) ────────────────────────────
    virtual void setMotorRelative(
        float position, float velocity, float torque,
        float kp, float ki, float kd,
        float acc, float voltage, float current,
        MotorControlType type = MotorControlType::POS_VEL_TQE_KP_KD2) = 0;

    virtual void setMotorRelative(MotorControlCmd cmd) = 0;

    // ── 安全 ──────────────────────────────────────────────────
    virtual void protectMotor()    = 0;   // kp=0, kd=1 → 电机无力
    virtual void keepMotorLastCmd() = 0;  // 重发上一帧指令

    // ── 上次指令 ──────────────────────────────────────────────
    MotorControlCmd lastCmd_;
};

// ═══════════════════════════════════════════════════════════════════
// HtdwMotor — 具体电机实现 (替代原始 HtdwMotor, 使用 MotorHardware 而非 livelybot_serial)
// ═══════════════════════════════════════════════════════════════════
class HtdwMotor : public MotorBase
{
public:
    HtdwMotor() = delete;

    /**
     * @param hw      硬件抽象层 (CAN/RS485/串口)
     * @param index   电机全局编号 (对应 CAN ID 或 RS485 地址)
     * @param name    电机名称 (如 "r_ankle_roll_joint")
     * @param lowest  机械限位下限 (rad)
     * @param highest 机械限位上限 (rad)
     */
    HtdwMotor(std::shared_ptr<MotorHardware> hw,
              int index,
              const std::string & name,
              double lowest,
              double highest);

    // ── MotorBase 接口实现 ────────────────────────────────────
    inline std::string getName()  const override { return name_; }
    inline int         getIndex() const override { return index_; }

    MotorBackState getMotorBackState() const override;

    void setMotor(float position, float velocity, float torque,
                  float kp, float ki, float kd,
                  float acc, float voltage, float current,
                  MotorControlType type =
                      MotorControlType::POS_VEL_TQE_KP_KD2) override;

    void setMotor(MotorControlCmd cmd) override;

    void setMotorRelative(float position, float velocity, float torque,
                          float kp, float ki, float kd,
                          float acc, float voltage, float current,
                          MotorControlType type =
                              MotorControlType::POS_VEL_TQE_KP_KD2) override;

    void setMotorRelative(MotorControlCmd cmd) override;

    void protectMotor() override;
    void keepMotorLastCmd() override;

private:
    std::shared_ptr<MotorHardware> hw_;
    int         index_;
    std::string name_;
    double      lowest_;
    double      highest_;
};

}  // namespace drive_motor

#endif  // DRIVE_MOTOR__MOTOR_BASE_HPP_