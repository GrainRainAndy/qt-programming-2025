// Pea.h
#ifndef PEA_H
#define PEA_H
#include "Weapon.h"
#include "../Characters/Character.h"
#include <QTimer>
#include <QGraphicsScene>

class Pea : public Weapon {
public:
    Pea();
    void attack(const QPointF& startPos, const QPointF& direction) override;
    void advance(int phase) override;
    void setShooter(Character* shooter_);
private:
    QPointF velocity;
    QTimer* moveTimer;
    double speed = 5; // 匀速
    Character* shooter = nullptr;
};

#endif // PEA_H
