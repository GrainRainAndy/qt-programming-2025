// Cabbage.h
#ifndef CABBAGE_H
#define CABBAGE_H
#include "Weapon.h"
#include "../Characters/Character.h"
#include <QTimer>
#include <QGraphicsScene>

class Cabbage : public Weapon {
public:
    Cabbage();
    void attack(const QPointF& startPos, const QPointF& direction) override;
    void advance(int phase) override;
    void setShooter(Character* shooter_);
private:
    QPointF velocity;
    double speed = 5;
    double gravity = 0.15;
    double vy = -5;
    Character* shooter = nullptr;
};

#endif // CABBAGE_H

