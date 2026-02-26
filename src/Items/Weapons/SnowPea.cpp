// SnowPea.cpp
#include "SnowPea.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QRectF>
#include <QList>
#include "../Characters/Character.h"

SnowPea::SnowPea()
    : Weapon(1.0, 300, 1, ":/Items/Weapons/ProjectileSnowPea.png"), velocity(0, 0), moveTimer(nullptr) {
    setPixmap(QPixmap(imagePath));
    setVisible(false);
}

void SnowPea::attack(const QPointF& startPos, const QPointF& direction) {
    setPos(startPos);
    setVisible(true);
    velocity = direction * speed;
    if (scene() && !scene()->items().contains(this)) {
        scene()->addItem(this);
    }
}

void SnowPea::setShooter(Character* shooter_) {
    shooter = shooter_;
}

void SnowPea::advance(int phase) {
    if (!isVisible()) return;
    if (phase == 1) {
        setPos(pos() + velocity);
        if (!scene()) return;
        QRectF bounds = scene()->sceneRect();
        if (!bounds.contains(pos())) {
            setVisible(false);
            if (scene()) scene()->removeItem(this);
            return;
        }
        QList<QGraphicsItem*> colliding = collidingItems();
        for (QGraphicsItem* item : colliding) {
            Character* target = dynamic_cast<Character*>(item);
            if (target && target != shooter) {
                target->takeDamage(damage);
                target->applySlow(2000, 0.5); // 2秒减速，倍率0.5
                setVisible(false);
                if (scene()) scene()->removeItem(this);
                break;
            }
        }
    }
}
