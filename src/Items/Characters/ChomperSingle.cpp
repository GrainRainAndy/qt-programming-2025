// ChomperSingle.cpp
#include "ChomperSingle.h"
#include "Character.h"
#include "../Maps/Map.h"
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QGraphicsScene>
#include <QList>
#include <QRectF>
#include <QDebug>
#include <QRandomGenerator>

ChomperSingle::ChomperSingle(QGraphicsItem *parent)
    : Character(parent), currentFrame(0), frameRate(12), frameTimer(0), paused(false), state(State::Idle), direction(Direction::Right), hp(15), attacking(false) {
    setAttackRange();
    setIdleFrames(1, 25);
    setAttackFrames(25, 50);
    setFramePrefix("Chomper");
    idleFrames.clear();
    attackFrames.clear();
    for (int i = idleStart; i <= idleEnd; ++i) {
        QString path = QString(":/Items/Plants/Chomper/%1%2.png").arg(framePrefix).arg(i, 4, 10, QChar('0'));
        QPixmap pix(path);
        qDebug() << "Chomper idle frame" << i << ":" << path << ", loaded?" << !pix.isNull();
        if (!pix.isNull()) idleFrames.push_back(pix);
    }
    for (int i = attackStart; i <= attackEnd; ++i) {
        QString path = QString(":/Items/Plants/Chomper/%1%2.png").arg(framePrefix).arg(i, 4, 10, QChar('0'));
        QPixmap pix(path);
        qDebug() << "Chomper attack frame" << i << ":" << path << ", loaded?" << !pix.isNull();
        if (!pix.isNull()) attackFrames.push_back(pix);
    }
    if (pixmapItem) {
        QPixmap pix = idleFrames.empty() ? QPixmap() : idleFrames[0];
        pixmapItem->setOffset(-pix.width() / 2, -pix.height() / 2);
        pixmapItem->setPixmap(pix);
    }
}

void ChomperSingle::setPosition(const QPointF &pos) {
    setPos(pos);
}

void ChomperSingle::setDirection(Direction dir) {
    direction = dir;
    updatePixmap();
}

void ChomperSingle::setState(State s) {
    state = s;
    resetAnimation();
}

void ChomperSingle::setFrameRate(int fps) {
    frameRate = fps;
}

void ChomperSingle::setFramePrefix(const QString &prefix) {
    framePrefix = prefix;
}

void ChomperSingle::setIdleFrames(int start, int end) {
    idleStart = start;
    idleEnd = end;
}

void ChomperSingle::setAttackFrames(int start, int end) {
    attackStart = start;
    attackEnd = end;
}

void ChomperSingle::pauseAnimation(bool pause_) {
    paused = pause_;
}

void ChomperSingle::resetAnimation() {
    currentFrame = 0;
    frameTimer = 0;
    attacking = false;
    updatePixmap();
}

void ChomperSingle::setAttackRange() {
    attackRange = AttackRange::Melee;
}

void ChomperSingle::updateAnimation(qint64 deltaTime) {
    if (state == State::Jumping) {
        paused = true;
    } else {
        paused = false;
    }
    if (paused) return;
    frameTimer += deltaTime;
    int frameDuration = 1000 / frameRate;
    if (frameTimer >= frameDuration) {
        frameTimer -= frameDuration;
        if (attacking) {
            currentFrame++;
            if (currentFrame >= static_cast<int>(attackFrames.size())) {
                // 攻击动画播放完毕，判定伤害
                // 检查前方宽度范围内是否有其他Player
                if (scene()) {
                    QRectF area;
                    if (direction == Direction::Right) {
                        area = QRectF(pos().x(), pos().y() - 40, 80, 80);
                    } else {
                        area = QRectF(pos().x() - 80, pos().y() - 40, 80, 80);
                    }
                    QList<QGraphicsItem*> itemsInArea = scene()->items(area);
                    for (QGraphicsItem* item : itemsInArea) {
                        Character* target = dynamic_cast<Character*>(item);
                        if (target && target != this) {
                            target->takeDamage(2.0); // 豌豆伤害为1，Chomper为2倍
                        }
                    }
                }
                // 回到Idle
                state = State::Idle;
                attacking = false;
                currentFrame = 0;
            }
            updatePixmap();
        } else {
            currentFrame = (currentFrame + 1) % static_cast<int>(idleFrames.size());
            updatePixmap();
        }
    }
}

void ChomperSingle::updatePixmap() {
    if (attacking && !attackFrames.empty()) {
        QPixmap pix = attackFrames[std::min(currentFrame, static_cast<int>(attackFrames.size()) - 1)];
        if (direction == Direction::Left) {
            pix = pix.transformed(QTransform().scale(-1, 1));
        }
        if (pixmapItem) {
            pixmapItem->setPixmap(pix);
        }
    } else if (!idleFrames.empty()) {
        QPixmap pix = idleFrames[currentFrame];
        if (direction == Direction::Left) {
            pix = pix.transformed(QTransform().scale(-1, 1));
        }
        if (pixmapItem) {
            pixmapItem->setPixmap(pix);
        }
    }
}

void ChomperSingle::updateDirection() {
    if (getVelocity().x() < 0) {
        setDirection(Direction::Left);
    } else if (getVelocity().x() > 0) {
        setDirection(Direction::Right);
    }
}

QPointF ChomperSingle::getBottomPos() const {
    if (pixmapItem) {
        QRectF rect = pixmapItem->boundingRect();
        return pos() + QPointF(0, rect.height() / 2);
    }
    return pos();
}

void ChomperSingle::attack() {
    if (!attacking) {
        state = State::Attacking;
        attacking = true;
        currentFrame = 0;
        frameTimer = 0;
        updatePixmap();
    }
}

void ChomperSingle::takeDamage(double amount) {
    // 草地闪避判定
    if (scene()) {
        auto map = dynamic_cast<Map*>(scene()->parent());
        if (map) {
            TerrainType terrain = map->getTerrainType(getBottomPos());
            if (terrain == TerrainType::Grass && isCrouching()) {
                // 30%概率闪避
                if (QRandomGenerator::global()->bounded(100) < 30) {
                    return;
                }
            }
        }
    }
    hp -= static_cast<int>(amount);
    if (hp < 0) hp = 0;
}
