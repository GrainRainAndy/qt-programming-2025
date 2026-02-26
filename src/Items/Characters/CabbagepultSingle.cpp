// CabbagepultSingle.cpp
#include "CabbagepultSingle.h"
#include "Character.h"
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QGraphicsScene>
#include "../Weapons/Cabbage.h"

CabbagepultSingle::CabbagepultSingle(QGraphicsItem *parent)
    : Character(parent), currentFrame(0), frameRate(12), frameTimer(0), paused(false), state(State::Idle), direction(Direction::Right), hp(15) {
    setAttackRange();
    setIdleFrames(6, 36);
    setFramePrefix("Cabbagepult");
    idleFrames.clear();
    for (int i = idleStart; i <= idleEnd; ++i) {
        QString path = QString(":/Items/Plants/Cabbagepult/%1%2.png").arg(framePrefix).arg(i, 4, 10, QChar('0'));
        QPixmap pix(path);
        if (!pix.isNull()) idleFrames.push_back(pix);
    }
    if (pixmapItem) {
        QPixmap pix = idleFrames.empty() ? QPixmap() : idleFrames[0];
        pixmapItem->setOffset(-pix.width() / 2, -pix.height() / 2);
        pixmapItem->setPixmap(pix);
    }
    setWeapon(new Cabbage());
}

void CabbagepultSingle::setPosition(const QPointF &pos) {
    setPos(pos);
}

void CabbagepultSingle::setDirection(Direction dir) {
    direction = dir;
    updatePixmap();
}

void CabbagepultSingle::setState(State s) {
    state = s;
    resetAnimation();
}

void CabbagepultSingle::setFrameRate(int fps) {
    frameRate = fps;
}

void CabbagepultSingle::setFramePrefix(const QString &prefix) {
    framePrefix = prefix;
}

void CabbagepultSingle::setIdleFrames(int start, int end) {
    idleStart = start;
    idleEnd = end;
}

void CabbagepultSingle::pauseAnimation(bool pause_) {
    paused = pause_;
}

void CabbagepultSingle::resetAnimation() {
    currentFrame = 0;
    frameTimer = 0;
    updatePixmap();
}

void CabbagepultSingle::setAttackRange() {
    attackRange = AttackRange::Ranged;
}

void CabbagepultSingle::updateAnimation(qint64 deltaTime) {
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

void CabbagepultSingle::updatePixmap() {
    if (idleFrames.empty()) return;
    QPixmap pix = idleFrames[currentFrame];
    if (direction == Direction::Left) {
        pix = pix.transformed(QTransform().scale(-1, 1));
    }
    if (pixmapItem) {
        pixmapItem->setPixmap(pix);
    }
}

void CabbagepultSingle::updateDirection() {
    if (getVelocity().x() < 0) {
        setDirection(Direction::Left);
    } else if (getVelocity().x() > 0) {
        setDirection(Direction::Right);
    }
}

QPointF CabbagepultSingle::getBottomPos() const {
    if (pixmapItem) {
        QRectF rect = pixmapItem->boundingRect();
        return pos() + QPointF(0, rect.height() / 2);
    }
    return pos();
}

void CabbagepultSingle::attack() {
    Weapon* weapon = getWeapon();
    if (weapon) {
        QPointF dir = (direction == Direction::Left) ? QPointF(-1, 0) : QPointF(1, 0);
        Cabbage* cabbage = new Cabbage();
        cabbage->attack(pos() + QPointF(0, -50), dir);
        if (scene()) scene()->addItem(cabbage);
    }
}

void CabbagepultSingle::takeDamage(double amount) {
    hp -= static_cast<int>(amount);
    if (hp < 0) hp = 0;
}

