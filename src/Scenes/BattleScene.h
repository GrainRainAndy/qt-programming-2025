//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_BATTLESCENE_H
#define QT_PROGRAMMING_2024_BATTLESCENE_H

#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include "Scene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Character.h"

class BattleScene : public Scene {
Q_OBJECT

public:
    explicit BattleScene(MapType mapType, int player1CharacterId, int player2CharacterId, QObject *parent = nullptr);

    void processInput() override;

    void processMovement() override;

    void processPicking() override;

protected slots:

    void update() override;

protected:
    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

signals:
    void gameOver(int winner); // 1为玩家1胜，2为玩家2胜

private:
    QTimer* autoDamageTimer = nullptr;
    bool gameEnded = false; // 结束标志

    Mountable *findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold = std::numeric_limits<qreal>::max());

    static Mountable * pickupMountable(Character *character, Mountable *mountable);

    Map *map;
    Character *character1; // 玩家1角色
    Character *character2; // 玩家2角色
    int player1CharacterId;
    int player2CharacterId;
    Armor *spareArmor;
    MapType mapType;
};


#endif //QT_PROGRAMMING_2024_BATTLESCENE_H
