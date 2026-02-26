// SnowPeaSingle.h
#ifndef SNOWPEASINGLE_H
#define SNOWPEASINGLE_H
#include "../Item.h"
#include "Character.h"
#include <QPixmap>
#include <QTimer>
#include <vector>
#include <QString>

class SnowPeaSingle : public Character {
public:
    enum class Direction {
        Left,
        Right
    };
    explicit SnowPeaSingle(QGraphicsItem *parent = nullptr);
    void setPosition(const QPointF &pos);
    void setDirection(Direction dir);
    void setState(State state);
    void updateAnimation(qint64 deltaTime);
    void setFrameRate(int fps);
    void setFramePrefix(const QString &prefix);
    void setIdleFrames(int start, int end);
    void pauseAnimation(bool pause);
    void resetAnimation();
    void setAttackRange();
    QPointF getBottomPos() const override;
    void updateDirection() override;
    void attack();
    void takeDamage(double amount) override;
protected:
    void updatePixmap();
private:
    std::vector<QPixmap> idleFrames;
    int currentFrame = 0;
    int idleStart = 80, idleEnd = 104;
    int frameRate = 12;
    qint64 frameTimer = 0;
    bool paused = false;
    State state = State::Idle;
    Direction direction = Direction::Right;
    QString framePrefix = "SnowPea_";
    AttackRange attackRange = AttackRange::Ranged;
};
#endif // SNOWPEASINGLE_H

