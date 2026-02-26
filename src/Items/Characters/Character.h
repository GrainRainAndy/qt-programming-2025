//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_CHARACTER_H
#define QT_PROGRAMMING_2024_CHARACTER_H

#include <QGraphicsEllipseItem>
#include <QGraphicsPixmapItem>
#include "../HeadEquipments/HeadEquipment.h"
#include "../Armors/Armor.h"
#include "../LegEquipments/LegEquipment.h"
#include "../Weapons/Weapon.h"

class Character : public Item {
public:
    explicit Character(QGraphicsItem *parent);

    [[nodiscard]] bool isLeftDown() const;
    void setLeftDown(bool leftDown);
    [[nodiscard]] bool isRightDown() const;
    void setRightDown(bool rightDown);
    [[nodiscard]] bool isPickDown() const;
    void setPickDown(bool pickDown);
    [[nodiscard]] bool isJumpDown() const;
    void setJumpDown(bool jumpDown);
    [[nodiscard]] bool isOnGround() const;
    void setOnGround(bool onGround);
    [[nodiscard]] bool isJumping() const;
    void setJumping(bool jumping);
    [[nodiscard]] double getVelocityY() const;
    void setVelocityY(double vy);
    [[nodiscard]] const QPointF &getVelocity() const;
    [[nodiscard]] bool isPicking() const;
    void setVelocity(const QPointF &velocity);
    void processInput();
    Armor* pickupArmor(Armor* newArmor);
    // 拾取武器，替换当前武器，原武器掉落到场景
    Weapon* pickupWeapon(Weapon* newWeapon);
    [[nodiscard]] bool isCrouching() const;
    void setCrouching(bool crouching);
    enum class AttackRange {
        Melee,
        Ranged
    };
    void setAttackRange(AttackRange range);
    AttackRange getAttackRange() const;
    virtual QPointF getBottomPos() const;
    virtual void updateDirection();
    virtual void updateAnimation(qint64 deltaTime) {} // 新增：通用动画更新接口，基类为空实现
    // 武器相关
    virtual void takeDamage(double amount); // 受伤逻辑
    void applySlow(double duration, double slowFactor); // 异常状态：减速
    void updateStatus(qint64 deltaTime); // 状态更新（如减速恢复）
    void setWeapon(class Weapon* weapon); // 设置武器
    class Weapon* getWeapon() const;
    virtual void attack() {} // 新增通用攻击接口，基类为空实现
    // 受击与血量相关
    int getHp() const;
    void setHp(int hp);

protected:
    HeadEquipment *headEquipment{};
    LegEquipment *legEquipment{};
    Armor *armor{};
    QPointF velocity{};
    QGraphicsPixmapItem *pixmapItem{}; // 新增成员用于显示角色图片
    // 新增：动画/状态支持
    enum class State {
        Idle,
        Running,
        Jumping,
        Falling,
        Crouching,
        Attacking,
        Picking
    };
    State currentState{State::Idle}; // 新增：当前角色动画状态
    // 由子类实现具体枚举类型
private:
    bool leftDown{}, rightDown{}, pickDown{};
    bool lastPickDown{};
    bool picking{};
    // 跳跃与重力相关
    bool jumpDown{};
    bool onGround{};
    bool jumping{};
    double velocityY{};
    bool crouching{};
    AttackRange attackRange{AttackRange::Melee};
    class Weapon* weapon = nullptr; // 当前持有武器
    // 异常状态
    bool slowed = false;
    double slowFactor = 1.0;
    qint64 slowTimer = 0;
    int hp = 10; // 初始血量
};


#endif //QT_PROGRAMMING_2024_CHARACTER_H
