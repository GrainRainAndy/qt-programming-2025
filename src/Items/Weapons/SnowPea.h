// SnowPea.h
#ifndef SNOWPEA_H
#define SNOWPEA_H
#include "Weapon.h"
#include <QTimer>
#include <QGraphicsScene>
#include "../Characters/Character.h"

class SnowPea : public Weapon {
public:
    SnowPea();
    void attack(const QPointF& startPos, const QPointF& direction) override;
    void advance(int phase) override;
    void setShooter(Character* shooter_);
private:
    QPointF velocity;
    QTimer* moveTimer;
    double speed = 5;
    Character* shooter = nullptr;
};

#endif // SNOWPEA_H
