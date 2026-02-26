// Weapon.cpp
#include "Weapon.h"
#include <QPixmap>

Weapon::Weapon(double damage_, int minInterval_, int burstCount_, const QString& imagePath_)
    : QGraphicsPixmapItem(QPixmap(imagePath_)), damage(damage_), minInterval(minInterval_), burstCount(burstCount_), imagePath(imagePath_) {
    setVisible(false); // 默认不显示，attack时显示
}

