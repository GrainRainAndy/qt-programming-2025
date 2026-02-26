//
// Created by gerw on 8/20/24.
//

#include <QTransform>
#include <QGraphicsScene>
#include "../Weapons/Weapon.h"
#include "Character.h"

Character::Character(QGraphicsItem *parent) : Item(parent, "") {
    pixmapItem = new QGraphicsPixmapItem(this); // 初始化角色图片显示项
//    ellipseItem = new QGraphicsEllipseItem(-5, -5, 10, 10, this);
//    // Optionally, set some properties of the ellipse
//    ellipseItem->setBrush(Qt::green);          // Fill color
//    ellipseItem->setZValue(1);
}

bool Character::isLeftDown() const {
    return leftDown;
}

void Character::setLeftDown(bool leftDown) {
    Character::leftDown = leftDown;
}

bool Character::isRightDown() const {
    return rightDown;
}

void Character::setRightDown(bool rightDown) {
    Character::rightDown = rightDown;
}

bool Character::isPickDown() const {
    return pickDown;
}

void Character::setPickDown(bool pickDown) {
    Character::pickDown = pickDown;
}

const QPointF &Character::getVelocity() const {
    return velocity;
}

void Character::setVelocity(const QPointF &velocity) {
    Character::velocity = velocity;
}

void Character::processInput() {
    auto velocity = QPointF(0, 0);
    const auto moveSpeed = 0.3;
    if (!isCrouching()) { // 下蹲时不能移动
        if (isLeftDown()) {
            velocity.setX(velocity.x() - moveSpeed);
        }
        if (isRightDown()) {
            velocity.setX(velocity.x() + moveSpeed);
        }
    }
    setVelocity(velocity);
    updateDirection(); // 每次输入处理后自动调整朝向
    if (!lastPickDown && pickDown) { // first time pickDown
        picking = true;
    } else {
        picking = false;
    }
    lastPickDown = pickDown;
}

void Character::updateDirection() {
    // 基类默认不做任何处理，子类可重写
}

bool Character::isPicking() const {
    return picking;
}

Armor *Character::pickupArmor(Armor *newArmor) {
    auto oldArmor = armor;
    if (oldArmor != nullptr) {
        oldArmor->unmount();
        oldArmor->setPos(newArmor->pos());
        oldArmor->setParentItem(parentItem());
    }
    newArmor->setParentItem(this);
    newArmor->mountToParent();
    armor = newArmor;
    return oldArmor;
}

bool Character::isJumpDown() const {
    return jumpDown;
}

void Character::setJumpDown(bool jumpDown_) {
    jumpDown = jumpDown_;
}

bool Character::isOnGround() const {
    return onGround;
}

void Character::setOnGround(bool onGround_) {
    onGround = onGround_;
}

bool Character::isJumping() const {
    return jumping;
}

void Character::setJumping(bool jumping_) {
    jumping = jumping_;
}

double Character::getVelocityY() const {
    return velocityY;
}

void Character::setVelocityY(double vy) {
    velocityY = vy;
}

bool Character::isCrouching() const {
    return crouching;
}

void Character::setCrouching(bool crouching_) {
    crouching = crouching_;
}

Character::AttackRange Character::getAttackRange() const { return attackRange; }
void Character::setAttackRange(AttackRange range) { attackRange = range; }

QPointF Character::getBottomPos() const {
    return pos();
}

int Character::getHp() const {
    return hp;
}

void Character::setHp(int hp_) {
    hp = hp_;
}

void Character::takeDamage(double amount) {
    hp -= static_cast<int>(amount);
    if (hp < 0) hp = 0;
    // 可扩展：播放受伤动画、死亡处理等
}

void Character::applySlow(double duration, double factor) {
    slowed = true;
    slowFactor = factor;
    slowTimer = duration;
}

void Character::updateStatus(qint64 deltaTime) {
    if (slowed) {
        if (slowTimer > 0) {
            slowTimer -= deltaTime;
            if (slowTimer <= 0) {
                slowed = false;
                slowFactor = 1.0;
                slowTimer = 0;
            }
        }
    }
}

void Character::setWeapon(Weapon* weapon_) {
    weapon = weapon_;
}

Weapon* Character::getWeapon() const {
    return weapon;
}

Weapon* Character::pickupWeapon(Weapon* newWeapon) {
    Weapon* oldWeapon = weapon;
    if (oldWeapon) {
        // 原武器掉落到角色当前位置
        oldWeapon->setPos(this->pos());
        oldWeapon->setVisible(true);
        oldWeapon->setParentItem(nullptr);
        if (scene() && !scene()->items().contains(oldWeapon)) {
            scene()->addItem(oldWeapon);
        }
    }
    // 新武器被角色持有，隐藏在场景
    setWeapon(newWeapon);
    if (newWeapon) {
        newWeapon->setVisible(false);
        newWeapon->setParentItem(this);
        if (scene() && scene()->items().contains(newWeapon)) {
            scene()->removeItem(newWeapon);
        }
    }
    return oldWeapon;
}
