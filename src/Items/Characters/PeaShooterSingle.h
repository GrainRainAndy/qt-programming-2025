// PeaShooterSingle.h
#ifndef PEASHOOTERSINGLE_H
#define PEASHOOTERSINGLE_H
#include "../Item.h"
#include "Character.h"
#include <QPixmap>
#include <QTimer>
#include <vector>
#include <QString>

class PeaShooterSingle : public Character {
public:
    enum class Direction {
        Left,
        Right
    };
    explicit PeaShooterSingle(QGraphicsItem *parent = nullptr);
    void setPosition(const QPointF &pos);
    void setDirection(Direction dir);
    void setState(State state);
    void updateAnimation(qint64 deltaTime);
    void setFrameRate(int fps); // 支持自定义动画帧率
    void setFramePrefix(const QString &prefix); // 支持自定义动画资源前缀
    void setIdleFrames(int start, int end);
    void pauseAnimation(bool pause);
    void resetAnimation();
    void setAttackRange();
    QPointF getBottomPos() const override;
    void updateDirection() override;
    void attack(); // 新增攻击接口
    void takeDamage(double amount) override; // 新增受击接口
    // ...可扩展其它接口
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
    QString framePrefix = "PeaShooterSingle_";
    AttackRange attackRange = AttackRange::Ranged;
};
#endif // PEASHOOTERSINGLE_H
