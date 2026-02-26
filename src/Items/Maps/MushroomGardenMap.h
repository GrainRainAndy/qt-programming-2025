// MushroomGardenMap.h
#ifndef MUSHROOMGARDENMAP_H
#define MUSHROOMGARDENMAP_H
#include "Map.h"
#include <vector>

class MushroomGardenMap : public Map {
public:
    explicit MushroomGardenMap(QGraphicsItem *parent = nullptr);
    ~MushroomGardenMap();
    qreal getFloorHeight() override;
    QPointF getSpawnPos() override;
    TerrainType getTerrainType(const QPointF &pos) const override;
    std::vector<TerrainRegion> getTerrainRegions() const override { return regions; }
    // 新增：血量条更新接口
    void updateHpBar(int player, int hp, int maxHp);
private:
    std::vector<QGraphicsItem*> children;
    std::vector<TerrainRegion> regions;
    QGraphicsPixmapItem* hpbar1_fr = nullptr;
    QGraphicsPixmapItem* hpbar2_fr = nullptr;
    QPixmap hpbar1_pixmap;
    QPixmap hpbar2_pixmap;
};

#endif // MUSHROOMGARDENMAP_H
