//
// Created by gerw on 8/21/24.
//

#include "Map.h"
#include <stdexcept>

Map::Map(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {}

void Map::scaleToFitScene(QGraphicsScene *scene) {
    // Calculate scale factors to scale the item to fit the entire scene
    QRectF sceneRect = scene->sceneRect();
    QRectF itemRect = boundingRect();

    qreal scaleX = sceneRect.width() / itemRect.width();
    qreal scaleY = sceneRect.height() / itemRect.height();

    // Choose the smaller scale factor to maintain aspect ratio
    qreal scaleFactor = qMin(scaleX, scaleY);

    // Apply the scale to the item
    setTransform(QTransform::fromScale(scaleFactor, scaleFactor), true);

    // Center the item in the scene (optional)
    setPos((sceneRect.width() - boundingRect().width() * scaleFactor) / 2,
           (sceneRect.height() - boundingRect().height() * scaleFactor) / 2);

}

QPointF Map::getSpawnPos() {
    auto boundingRect = sceneBoundingRect();
    auto midX = (boundingRect.left() + boundingRect.right()) * 0.5;
    return {midX, getFloorHeight()};
}

qreal Map::getFloorHeight() {
    auto sceneRect = sceneBoundingRect();
    return sceneRect.top() + (sceneRect.top() - sceneRect.bottom()) * 0.5;
}

Map *Map::createMap(MapType type, QGraphicsItem *parent) {
    auto it = factory().find(type);
    if (it != factory().end()) {
        return it->second(parent);
    }
    throw std::runtime_error("MapType not registered");
}

void Map::registerMap(MapType type, std::function<Map*(QGraphicsItem*)> creator) {
    factory()[type] = creator;
}

std::unordered_map<MapType, std::function<Map*(QGraphicsItem*)>> &Map::factory() {
    static std::unordered_map<MapType, std::function<Map*(QGraphicsItem*)>> instance;
    return instance;
}
