// Pea.cpp
#include "Pea.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QRectF>
#include <QList>
#include "../Characters/Character.h"

Pea::Pea()
    : Weapon(1.0, 300, 1, ":/Items/Weapons/ProjectilePea.png"), velocity(0, 0), moveTimer(nullptr) {
    setPixmap(QPixmap(imagePath));
    setVisible(false); // 默认不显示，attack时才显示
}

void Pea::attack(const QPointF& startPos, const QPointF& direction) {
    setPos(startPos);
    setVisible(true);
    // direction为单位向量，乘以speed得到速度
    velocity = direction * speed;
    if (scene() && !scene()->items().contains(this)) {
        scene()->addItem(this);
    }
}

void Pea::setShooter(Character* shooter_) {
    shooter = shooter_;
}

void Pea::advance(int phase) {
    if (!isVisible()) return;
    if (phase == 1) {
        setPos(pos() + velocity);
        // 边界检测
        if (!scene()) return;
        QRectF bounds = scene()->sceneRect();
        if (!bounds.contains(pos())) {
            setVisible(false);
            if (scene()) scene()->removeItem(this);
            return;
        }
        // 碰撞检测：与角色（敌人）碰撞
        QList<QGraphicsItem*> colliding = collidingItems();
        for (QGraphicsItem* item : colliding) {
            // 只检测Character类型，且不是自己发射方
            Character* target = dynamic_cast<Character*>(item);
            if (target && target != shooter) {
                // 造成伤害（假设Character有takeDamage方法）
                target->takeDamage(damage);
                setVisible(false);
                if (scene()) scene()->removeItem(this);
                break;
            }
        }
    }
}
