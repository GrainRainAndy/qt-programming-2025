// Weapon.h
#ifndef WEAPON_H
#define WEAPON_H
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPointF>

class Weapon : public QGraphicsPixmapItem {
public:
    Weapon(double damage, int minInterval, int burstCount, const QString& imagePath);
    virtual ~Weapon() = default;
    virtual void attack(const QPointF& startPos, const QPointF& direction) = 0;
    double getDamage() const { return damage; }
    int getMinInterval() const { return minInterval; }
    int getBurstCount() const { return burstCount; }
protected:
    double damage;
    int minInterval; // ms
    int burstCount;
    QString imagePath;
};

#endif // WEAPON_H

