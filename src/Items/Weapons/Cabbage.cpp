// Cabbage.cpp
#include "Cabbage.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QRectF>
#include <QList>
#include "../Characters/Character.h"

Cabbage::Cabbage()
    : Weapon(3.0, 300, 1, ":/Items/Weapons/ProjectileCabbage.png"), velocity(0, 0), vy(0.0) {
    setPixmap(QPixmap(imagePath));
    setVisible(false);
}

void Cabbage::attack(const QPointF& startPos, const QPointF& direction) {
    setPos(startPos);
    setVisible(true);
    velocity = direction * speed;
    vy = -5.;
    if (scene() && !scene()->items().contains(this)) {
        scene()->addItem(this);
    }
}

void Cabbage::setShooter(Character* shooter_) {
    shooter = shooter_;
}

void Cabbage::advance(int phase) {
    if (!isVisible()) return;
    if (phase == 1) {
        vy += gravity;
        setPos(pos() + QPointF(velocity.x(), vy));
        if (!scene()) return;
        QRectF bounds = scene()->sceneRect();
        if (!bounds.contains(pos())) {
            setVisible(false);
            if (scene()) scene()->removeItem(this);
            return;
        }
        QRectF cabbageRect = boundingRect().translated(pos());
        QList<QGraphicsItem*> itemsInArea = scene()->items(cabbageRect);
        for (QGraphicsItem* item : itemsInArea) {
            Character* target = dynamic_cast<Character*>(item);
            if (target && target != shooter) {
                target->takeDamage(damage);
                setVisible(false);
                if (scene()) scene()->removeItem(this);
                return;
            }
        }
        if (pos().y() >= bounds.bottom() - 5) {
            setVisible(false);
            if (scene()) scene()->removeItem(this);
        }
    }
}
