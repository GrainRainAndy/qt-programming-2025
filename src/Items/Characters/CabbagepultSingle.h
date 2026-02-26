// CabbagepultSingle.h
#ifndef CABBAGEPULTSINGLE_H
#define CABBAGEPULTSINGLE_H
#include "Character.h"
#include <QPixmap>
#include <vector>
#include <QString>

class CabbagepultSingle : public Character {
public:
    enum class Direction {
        Left,
        Right
    };
    explicit CabbagepultSingle(QGraphicsItem *parent = nullptr);
    void setPosition(const QPointF &pos);
    void setDirection(Direction dir);
    void setState(State state);
    void updateAnimation(qint64 deltaTime) override;
    void setFrameRate(int fps);
    void setFramePrefix(const QString &prefix);
    void setIdleFrames(int start, int end);
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
    int currentFrame = 0;
    int idleStart = 6, idleEnd = 36;
    int frameRate = 12;
    qint64 frameTimer = 0;
    bool paused = false;
    State state = State::Idle;
    Direction direction = Direction::Right;
    QString framePrefix = "Cabbagepult";
    AttackRange attackRange = AttackRange::Ranged;
    int hp = 15;
};
#endif // CABBAGEPULTSINGLE_H

