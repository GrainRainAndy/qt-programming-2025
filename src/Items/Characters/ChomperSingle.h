// ChomperSingle.h
#ifndef CHOMPERSINGLE_H
#define CHOMPERSINGLE_H
#include "Character.h"
#include <QPixmap>
#include <vector>
#include <QString>

class ChomperSingle : public Character {
public:
    enum class Direction {
        Left,
        Right
    };
    explicit ChomperSingle(QGraphicsItem *parent = nullptr);
    void setPosition(const QPointF &pos);
    void setDirection(Direction dir);
    void setState(State state);
    void updateAnimation(qint64 deltaTime) override;
    void setFrameRate(int fps);
    void setFramePrefix(const QString &prefix);
    void setIdleFrames(int start, int end);
    void setAttackFrames(int start, int end);
    void pauseAnimation(bool pause);
    void resetAnimation();
    void setAttackRange();
    QPointF getBottomPos() const override;
    void updateDirection() override;
    void attack() override;
    void takeDamage(double amount) override;
protected:
    void updatePixmap();
private:
    std::vector<QPixmap> idleFrames;
    std::vector<QPixmap> attackFrames;
    int currentFrame = 0;
    int idleStart = 1, idleEnd = 25;
    int attackStart = 25, attackEnd = 50;
    int frameRate = 12;
    qint64 frameTimer = 0;
    bool paused = false;
    State state = State::Idle;
    Direction direction = Direction::Right;
    QString framePrefix = "Chomper";
    AttackRange attackRange = AttackRange::Melee;
    int hp = 15;
    bool attacking = false;
};
#endif // CHOMPERSINGLE_H

