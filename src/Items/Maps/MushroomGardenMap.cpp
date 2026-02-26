// MushroomGardenMap.cpp
#include "MushroomGardenMap.h"
#include "Map.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include "ui_Map_MushroomGarden.h"

namespace {
    const bool registered = [] {
        Map::registerMap(MapType::MushroomGarden, [](QGraphicsItem *parent) { return new MushroomGardenMap(parent); });
        return true;
    }();
}

MushroomGardenMap::~MushroomGardenMap() {
    for (auto item : children) {
        delete item;
    }
    children.clear();
}

MushroomGardenMap::MushroomGardenMap(QGraphicsItem *parent)
    : Map(parent, ":/Items/Maps/Battlefield/MushroomGarden.jpg") {
    // 台阶地形
    auto dirt1 = new QGraphicsPixmapItem(QPixmap(":/Items/Maps/Territory/LoadBar_dirt.png").scaled(800, 30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);
    dirt1->setPos(0, 370);
    children.push_back(dirt1);
    auto dirt2 = new QGraphicsPixmapItem(QPixmap(":/Items/Maps/Territory/LoadBar_dirt.png").scaled(200, 30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);
    dirt2->setPos(110, 290);
    children.push_back(dirt2);
    auto dirt3 = new QGraphicsPixmapItem(QPixmap(":/Items/Maps/Territory/LoadBar_dirt.png").scaled(200, 30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);
    dirt3->setPos(490, 290);
    children.push_back(dirt3);
    auto grass4 = new QGraphicsPixmapItem(QPixmap(":/Items/Maps/Territory/LoadBar_grass.png").scaled(200, 30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);
    grass4->setPos(300, 350);
    children.push_back(grass4);
    auto ice1 = new QGraphicsPixmapItem(QPixmap(":/Items/Maps/Territory/ice_cap.png").scaled(86, 30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);
    ice1->setPos(280, 210);
    children.push_back(ice1);
    auto ice2 = new QGraphicsPixmapItem(QPixmap(":/Items/Maps/Territory/ice_cap.png").scaled(86, 30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);
    ice2->setPos(430, 210);
    children.push_back(ice2);
    // 功能栏
    auto bar = new QGraphicsPixmapItem(QPixmap(":/Items/ui/dialog_frame.png"), this);
    bar->setPos(0, 400);
    bar->setScale(800.0 / bar->pixmap().width());
    children.push_back(bar);
    // 血量条
    auto hpbar1_bg = new QGraphicsPixmapItem(QPixmap(":/Items/ui/hpbar_bk.png"), this);
    hpbar1_bg->setPos(60, 450);
    hpbar1_bg->setScale(200.0 / hpbar1_bg->pixmap().width());
    children.push_back(hpbar1_bg);
    auto hpbar1_fr = new QGraphicsPixmapItem(QPixmap(":/Items/ui/hpbar_fr.png"), this);
    hpbar1_fr->setPos(60, 450);
    hpbar1_fr->setScale(200.0 / hpbar1_fr->pixmap().width());
    children.push_back(hpbar1_fr);
    this->hpbar1_fr = hpbar1_fr;
    this->hpbar1_pixmap = hpbar1_fr->pixmap();
    auto hpbar2_bg = new QGraphicsPixmapItem(QPixmap(":/Items/ui/hpbar_bk.png"), this);
    hpbar2_bg->setPos(510, 450);
    hpbar2_bg->setScale(200.0 / hpbar2_bg->pixmap().width());
    children.push_back(hpbar2_bg);
    auto hpbar2_fr = new QGraphicsPixmapItem(QPixmap(":/Items/ui/hpbar_fr.png"), this);
    hpbar2_fr->setPos(510, 450);
    hpbar2_fr->setScale(200.0 / hpbar2_fr->pixmap().width());
    children.push_back(hpbar2_fr);
    this->hpbar2_fr = hpbar2_fr;
    this->hpbar2_pixmap = hpbar2_fr->pixmap();
    // 玩家名标签
    auto label1 = new QGraphicsTextItem("Player1", this);
    label1->setFont(QFont("Papyrus", 20, QFont::Bold));
    label1->setDefaultTextColor(QColor("#5F6181"));
    label1->setPos(63, 505);
    children.push_back(label1);
    auto label2 = new QGraphicsTextItem("Player2", this);
    label2->setFont(QFont("Papyrus", 20, QFont::Bold));
    label2->setDefaultTextColor(QColor("#5F6181"));
    label2->setPos(510, 500);
    children.push_back(label2);
    // 地形区域数据（用于碰撞和判定）
    regions.push_back({QRectF(0, 370, 800, 30), TerrainType::Dirt});
    regions.push_back({QRectF(110, 290, 200, 30), TerrainType::Dirt});
    regions.push_back({QRectF(490, 290, 200, 30), TerrainType::Dirt});
    regions.push_back({QRectF(300, 350, 200, 30), TerrainType::Grass});
    regions.push_back({QRectF(280, 210, 86, 30), TerrainType::Ice});
    regions.push_back({QRectF(430, 210, 86, 30), TerrainType::Ice});
}

qreal MushroomGardenMap::getFloorHeight() {
    auto sceneRect = sceneBoundingRect();
    return (sceneRect.top() + sceneRect.bottom()) * 0.63;
}

QPointF MushroomGardenMap::getSpawnPos() {
    // 默认出生点在地图底部中央
    auto sceneRect = sceneBoundingRect();
    return QPointF(sceneRect.width() / 2, getFloorHeight());
}

TerrainType MushroomGardenMap::getTerrainType(const QPointF &pos) const {
    for (const auto &region : regions) {
        if (region.rect.contains(pos)) {
            return region.type;
        }
    }
    return TerrainType::None;
}

void MushroomGardenMap::updateHpBar(int player, int hp, int maxHp) {
    QGraphicsPixmapItem* bar = (player == 1) ? hpbar1_fr : hpbar2_fr;
    QPixmap basePixmap = (player == 1) ? hpbar1_pixmap : hpbar2_pixmap;
    if (!bar || basePixmap.isNull()) return;
    double ratio = (maxHp > 0) ? std::max(0.0, std::min(1.0, double(hp) / maxHp)) : 0.0;
    int cropWidth = int(basePixmap.width() * ratio);
    if (cropWidth <= 0) cropWidth = 1; // 至少显示1像素
    QPixmap cropped = basePixmap.copy(0, 0, cropWidth, basePixmap.height());
    bar->setPixmap(cropped);
    bar->setScale(200.0 / basePixmap.width()); // 保持缩放和位置
}
