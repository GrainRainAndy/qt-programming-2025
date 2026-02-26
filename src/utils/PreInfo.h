// PreInfo.h
// 存储玩家和地图信息
#ifndef PREINFO_H
#define PREINFO_H
#include <QString>
struct PlayerInfo {
    QString name;
    int characterId; // 0: PeaShooter, 1: SnowPea, 2: Cabbagepult, 3: Chomper
};
struct PreInfo {
    PlayerInfo player1;
    PlayerInfo player2;
    int mapId; // 0: Roof, 1: MushroomGarden, 2: Aquarium, 3: MoreMaps
};
#endif // PREINFO_H

