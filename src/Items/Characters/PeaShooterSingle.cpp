// PeaShooterSingle.cpp
#include "PeaShooterSingle.h"
#include "Character.h"
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QGraphicsScene>
#include "../Weapons/Pea.h"
#include <QRandomGenerator>
#include "../Maps/Map.h"

PeaShooterSingle::PeaShooterSingle(QGraphicsItem *parent)
    : Character(parent), currentFrame(0), frameRate(12), frameTimer(0), paused(false), state(State::Idle), direction(Direction::Right) {
    setAttackRange();
    setIdleFrames(80, 104);
    setFramePrefix("PeaShooterSingle");
    // 默认加载Idle帧
    idleFrames.clear();
    for (int i = idleStart; i <= idleEnd; ++i) {
        QString path = QString(":/Items/Plants/PeaShooterSingle/%1%2.png").arg(framePrefix).arg(i, 4, 10, QChar('0'));
        QPixmap pix(path);
        if (!pix.isNull()) idleFrames.push_back(pix);
    }
    // 设置锚点为图片中心，保证碰撞检测准确
    if (pixmapItem) {
        QPixmap pix = idleFrames.empty() ? QPixmap() : idleFrames[0];
        pixmapItem->setOffset(-pix.width() / 2, -pix.height() / 2);
    }
    updatePixmap();
    // 默认武器：Pea
    setWeapon(new Pea());
}

void PeaShooterSingle::setPosition(const QPointF &pos) {
    setPos(pos);
}

void PeaShooterSingle::setDirection(Direction dir) {
    direction = dir;
    updatePixmap();
}

void PeaShooterSingle::setState(State s) {
    state = s;
    resetAnimation();
}

void PeaShooterSingle::setFrameRate(int fps) {
    frameRate = fps;
}

void PeaShooterSingle::setFramePrefix(const QString &prefix) {
    framePrefix = prefix;
}

void PeaShooterSingle::setIdleFrames(int start, int end) {
    idleStart = start;
    idleEnd = end;
}

void PeaShooterSingle::pauseAnimation(bool pause_) {
    paused = pause_;
}

void PeaShooterSingle::resetAnimation() {
    currentFrame = 0;
    frameTimer = 0;
    updatePixmap();
}

void PeaShooterSingle::setAttackRange() {
    attackRange = AttackRange::Ranged;
}

void PeaShooterSingle::updateAnimation(qint64 deltaTime) {
    // Jump 状态下暂停动画
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

void PeaShooterSingle::updatePixmap() {
    if (idleFrames.empty()) return;
    QPixmap pix = idleFrames[currentFrame];
    if (direction == Direction::Left) {
        pix = pix.transformed(QTransform().scale(-1, 1));
    }
    if (pixmapItem) {
        pixmapItem->setPixmap(pix);
    }
}

void PeaShooterSingle::updateDirection() {
    // 根据速度自动调整朝向
    if (getVelocity().x() < 0) {
        setDirection(Direction::Left);
    } else if (getVelocity().x() > 0) {
        setDirection(Direction::Right);
    }
    // 速度为0时不变
}

QPointF PeaShooterSingle::getBottomPos() const {
    // 角色底部点，假设pixmapItem锚点为图片中心
    if (pixmapItem) {
        QRectF rect = pixmapItem->boundingRect();
        // offset为中心，底部点为pos() + (0, rect.height()/2)
        return pos() + QPointF(0, rect.height() / 2);
    }
    return pos();
}

void PeaShooterSingle::attack() {
    Weapon* weapon = getWeapon();
    if (weapon) {
        QPointF dir = (direction == Direction::Left) ? QPointF(-1, 0) : QPointF(1, 0);
        Pea* pea = new Pea();
        pea->attack(pos() + QPointF(0, -30), dir);
        pea->setShooter(this); // 记录发射者
        if (scene()) scene()->addItem(pea);
    }
}

void PeaShooterSingle::takeDamage(double amount) {
    // 草地闪避判定
    if (scene()) {
        auto map = dynamic_cast<Map*>(scene()->parent());
        if (map) {
            TerrainType terrain = map->getTerrainType(getBottomPos());
            if (terrain == TerrainType::Grass && isCrouching()) {
                if (QRandomGenerator::global()->bounded(100) < 30) {
                    qDebug() << "PeaShooter dodged the attack!";
                    return;
                }
            }
        }
    }
    Character::takeDamage(amount); // 调用基类扣血逻辑
    // 可扩展：受击动画、死亡处理等
}
