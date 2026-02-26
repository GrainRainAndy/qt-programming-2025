//
// Created by gerw on 8/21/24.
//

#ifndef QT_PROGRAMMING_2024_MAP_H
#define QT_PROGRAMMING_2024_MAP_H

#include <QGraphicsScene>
#include <QPointF>
#include <functional>
#include <unordered_map>
#include "../Item.h"

enum class MapType {
    MushroomGarden,
    Roof,
    Aquarium,
    MoreMaps
};

enum class TerrainType {
    Dirt,
    Grass,
    Ice,
    None
};

struct TerrainRegion {
    QRectF rect;
    TerrainType type;
};

class Map : public Item {
public:
    explicit Map(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");

    void scaleToFitScene(QGraphicsScene *scene);

    virtual qreal getFloorHeight(); // Need to rewrite to support multiple platforms

    virtual QPointF getSpawnPos();

    virtual TerrainType getTerrainType(const QPointF &pos) const { return TerrainType::None; }
    virtual std::vector<TerrainRegion> getTerrainRegions() const { return {}; }

    // 新增：血量条更新接口，虚函数，默认空实现
    virtual void updateHpBar(int player, int hp, int maxHp) {}

    static Map *createMap(MapType type, QGraphicsItem *parent = nullptr);
    static void registerMap(MapType type, std::function<Map*(QGraphicsItem*)> creator);
private:
    static std::unordered_map<MapType, std::function<Map*(QGraphicsItem*)>> &factory();
};


#endif //QT_PROGRAMMING_2024_MAP_H
