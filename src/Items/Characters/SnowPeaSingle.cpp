// SnowPeaSingle.cpp
#include "SnowPeaSingle.h"
#include "Character.h"
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QGraphicsScene>
#include "../Weapons/SnowPea.h"
#include <QRandomGenerator>
#include "../Maps/Map.h"

SnowPeaSingle::SnowPeaSingle(QGraphicsItem *parent)
    : Character(parent), currentFrame(0), frameRate(12), frameTimer(0), paused(false), state(State::Idle), direction(Direction::Right) {
    setAttackRange();
    setIdleFrames(80, 104);
    setFramePrefix("SnowPea");
    idleFrames.clear();
    for (int i = idleStart; i <= idleEnd; ++i) {
        QString path = QString(":/Items/Plants/SnowPea/%1%2.png").arg(framePrefix).arg(i, 4, 10, QChar('0'));
        QPixmap pix(path);
        if (!pix.isNull()) idleFrames.push_back(pix);
    }
    if (pixmapItem) {
        QPixmap pix = idleFrames.empty() ? QPixmap() : idleFrames[0];
        pixmapItem->setOffset(-pix.width() / 2, -pix.height() / 2);
    }
    updatePixmap();
    setWeapon(new SnowPea());
}

void SnowPeaSingle::setPosition(const QPointF &pos) {
    setPos(pos);
}

void SnowPeaSingle::setDirection(Direction dir) {
    direction = dir;
    updatePixmap();
}

void SnowPeaSingle::setState(State s) {
    state = s;
    resetAnimation();
}

void SnowPeaSingle::setFrameRate(int fps) {
    frameRate = fps;
}

void SnowPeaSingle::setFramePrefix(const QString &prefix) {
    framePrefix = prefix;
}

void SnowPeaSingle::setIdleFrames(int start, int end) {
    idleStart = start;
    idleEnd = end;
}

void SnowPeaSingle::pauseAnimation(bool pause_) {
    paused = pause_;
}

void SnowPeaSingle::resetAnimation() {
    currentFrame = 0;
    frameTimer = 0;
    updatePixmap();
}

void SnowPeaSingle::setAttackRange() {
    attackRange = AttackRange::Ranged;
}

void SnowPeaSingle::updateAnimation(qint64 deltaTime) {
    if (state == State::Jumping) {
        paused = true;
    } else {
        paused = false;
    }
    if (paused || idleFrames.empty()) return;
    frameTimer += deltaTime;
    int frameDuration = 1000 / frameRate;
    if (frameTimer >= frameDuration) {
        frameTimer -= frameDuration;
        currentFrame = (currentFrame + 1) % static_cast<int>(idleFrames.size());
        updatePixmap();
    }
}

void SnowPeaSingle::updatePixmap() {
    if (idleFrames.empty()) return;
    QPixmap pix = idleFrames[currentFrame];
    if (direction == Direction::Left) {
        pix = pix.transformed(QTransform().scale(-1, 1));
    }
    if (pixmapItem) {
        pixmapItem->setPixmap(pix);
    }
}

void SnowPeaSingle::updateDirection() {
    if (getVelocity().x() < 0) {
        setDirection(Direction::Left);
    } else if (getVelocity().x() > 0) {
        setDirection(Direction::Right);
    }
}

QPointF SnowPeaSingle::getBottomPos() const {
    if (pixmapItem) {
        QRectF rect = pixmapItem->boundingRect();
        return pos() + QPointF(0, rect.height() / 2);
    }
    return pos();
}

void SnowPeaSingle::attack() {
    Weapon* weapon = getWeapon();
    if (weapon) {
        QPointF dir = (direction == Direction::Left) ? QPointF(-1, 0) : QPointF(1, 0);
        SnowPea* snowPea = new SnowPea();
        snowPea->attack(pos() + QPointF(0, -30), dir);
        snowPea->setShooter(this); // 记录发射者
        if (scene()) scene()->addItem(snowPea);
    }
}

void SnowPeaSingle::takeDamage(double amount) {
    // 草地闪避判定
    if (scene()) {
        auto map = dynamic_cast<Map*>(scene()->parent());
        if (map) {
            TerrainType terrain = map->getTerrainType(getBottomPos());
            if (terrain == TerrainType::Grass && isCrouching()) {
                if (QRandomGenerator::global()->bounded(100) < 30) {
                    qDebug() << "SnowPea dodged the attack!";
                    return;
                }
            }
        }
    }
    Character::takeDamage(amount);
}
