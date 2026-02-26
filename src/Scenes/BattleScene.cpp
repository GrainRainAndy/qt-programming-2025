//
// Created by gerw on 8/20/24.
//

#include <QDebug>
#include "BattleScene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Link.h"
#include "../Items/Armors/FlamebreakerArmor.h"
#include "../Items/Characters/PeaShooterSingle.h"
#include "../Items/Characters/SnowPeaSingle.h"
#include "../Items/Characters/ChomperSingle.h"
#include "../Items/Characters/CabbagepultSingle.h"
#include <QWidget>
#include <QApplication>
#include <QMainWindow>

BattleScene::BattleScene(MapType mapType, int player1CharacterId, int player2CharacterId, QObject *parent)
    : Scene(parent), mapType(mapType), player1CharacterId(player1CharacterId), player2CharacterId(player2CharacterId) {
    // This is useful if you want the scene to have the exact same dimensions as the view
    setSceneRect(0, 0, 800, 600);
    map = Map::createMap(mapType);
    // 根据角色Id实例化角色
    switch (player1CharacterId) {
        case 0:
            character1 = new PeaShooterSingle();
            break;
        case 1:
            character1 = new SnowPeaSingle();
            break;
        case 2:
            character1 = new CabbagepultSingle();
            break;
        case 3:
            character1 = new ChomperSingle();
            break;
        default:
            character1 = new PeaShooterSingle();
            break;
    }
    switch (player2CharacterId) {
        case 0:
            character2 = new PeaShooterSingle();
            break;
        case 1:
            character2 = new SnowPeaSingle();
            break;
        case 2:
            character2 = new CabbagepultSingle();
            break;
        case 3:
            character2 = new ChomperSingle();
            break;
        default:
            character2 = new PeaShooterSingle();
            break;
    }
    spareArmor = new FlamebreakerArmor();
    addItem(map);
    addItem(character1);
    addItem(character2);
    // addItem(spareArmor);
    map->scaleToFitScene(this);

    // 玩家1出生点：左1/4处
    QPointF spawn1(200, 0);
    // 玩家2出生点：右1/4处
    QPointF spawn2(600, 0);
    character1->setPos(spawn1);
    character2->setPos(spawn2);
    spareArmor->unmount();
    spareArmor->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorHeight());

    // 自动扣血定时器，每10秒触发一次
    autoDamageTimer = new QTimer(this);
    connect(autoDamageTimer, &QTimer::timeout, this, [this]() {
        if (character1) character1->takeDamage(1.0);
        if (character2) character2->takeDamage(1.0);
    });
    autoDamageTimer->start(10000); // 10秒
}

void BattleScene::processInput() {
    Scene::processInput();
    if (character1 != nullptr) {
        character1->processInput();
    }
    if (character2 != nullptr) {
        character2->processInput();
    }
}

void BattleScene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_A:
            if (character1 != nullptr) {
                character1->setLeftDown(true);
            }
            break;
        case Qt::Key_D:
            if (character1 != nullptr) {
                character1->setRightDown(true);
            }
            break;
        case Qt::Key_J:
            if (character1 != nullptr) {
                character1->setPickDown(true);
            }
            break;
        case Qt::Key_Space:
        case Qt::Key_W:
            if (character1 != nullptr && character1->isOnGround()) {
                character1->setVelocityY(-0.8); // 跳跃初速度，向上
                character1->setJumping(true);
                character1->setOnGround(false);
            }
            break;
        case Qt::Key_S:
            if (character1 != nullptr) {
                character1->setCrouching(true);
            }
            break;
        case Qt::Key_F:
            if (character1 != nullptr) {
                character1->attack();
            }
            break;
        // 玩家2的控制，使用方向键和小键盘
        case Qt::Key_Left:
            if (character2 != nullptr) {
                character2->setLeftDown(true);
            }
            break;
        case Qt::Key_Right:
            if (character2 != nullptr) {
                character2->setRightDown(true);
            }
            break;
        case Qt::Key_Enter: // 小键盘的Enter
        case Qt::Key_Return:
            if (character2 != nullptr) {
                character2->setPickDown(true);
            }
            break;
        case Qt::Key_0:
            if (character2 != nullptr) {
                character2->attack();
            }
            break;
        case Qt::Key_Up:
            if (character2 != nullptr && character2->isOnGround()) {
                character2->setVelocityY(-0.8); // 跳跃初速度，向上
                character2->setJumping(true);
                character2->setOnGround(false);
            }
            break;
        case Qt::Key_Down:
            if (character2 != nullptr) {
                character2->setCrouching(true);
            }
            break;
        default:
            Scene::keyPressEvent(event);
    }
}

void BattleScene::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_K:
            if (character1 != nullptr) {
                character1->setHp(0);
            }
            break;
        case Qt::Key_A:
            if (character1 != nullptr) {
                character1->setLeftDown(false);
            }
            break;
        case Qt::Key_D:
            if (character1 != nullptr) {
                character1->setRightDown(false);
            }
            break;
        case Qt::Key_J:
            if (character1 != nullptr) {
                character1->setPickDown(false);
            }
            break;
        case Qt::Key_Space:
        case Qt::Key_W:
            if (character1 != nullptr) {
                character1->setJumpDown(false);
            }
            break;
        case Qt::Key_S:
            if (character1 != nullptr) {
                character1->setCrouching(false);
            }
            break;
        // 玩家2的控制释放
        case Qt::Key_Left:
            if (character2 != nullptr) {
                character2->setLeftDown(false);
            }
            break;
        case Qt::Key_Right:
            if (character2 != nullptr) {
                character2->setRightDown(false);
            }
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
            if (character2 != nullptr) {
                character2->setPickDown(false);
            }
            break;
        case Qt::Key_Plus:
        case Qt::Key_Equal:
            if (character2 != nullptr) {
                character2->setJumpDown(false);
            }
            break;
        case Qt::Key_Down:
            if (character2 != nullptr) {
                character2->setCrouching(false);
            }
            break;
        default:
            Scene::keyReleaseEvent(event);
    }
}

void BattleScene::update() {
    Scene::update();
    // 实时更新血条，血量上限为10
    if (map) {
        int hp1 = character1 ? character1->getHp() : 0;
        int hp2 = character2 ? character2->getHp() : 0;
        map->updateHpBar(1, hp1, 10);
        map->updateHpBar(2, hp2, 10);
        // 结束判定
        if ((hp1 <= 0 || hp2 <= 0) && !gameEnded) {
            gameEnded = true;
            emit gameOver(hp1 > 0 ? 1 : 2); // 1为玩家1胜，2为玩家2胜
        }
    }
}

void BattleScene::processMovement() {
    Scene::processMovement();
    if (character1 != nullptr) {
        // 判断是否在冰场
        TerrainType terrain1 = map->getTerrainType(character1->getBottomPos());
        double speedFactor1 = (terrain1 == TerrainType::Ice) ? 1.5 : 1.0;
        // 水平移动
        character1->setPos(character1->pos() + character1->getVelocity() * (double) deltaTime * speedFactor1);
        // 跳跃与重力
        double gravity = 0.0025 * deltaTime; // 重力加速度
        double vy = character1->getVelocityY();
        vy += gravity;
        QPointF pos = character1->pos();
        pos.setY(pos.y() + vy * (double) deltaTime);
        character1->setPos(pos); // 先更新位置
        // 台阶碰撞检测
        bool landed = false;
        QPointF bottomPos = character1->getBottomPos();
        for (const auto& region : map->getTerrainRegions()) {
            QRectF rect = region.rect;
            if (region.type == TerrainType::Grass) {
                // 草地不参与碰撞，但可用于后续功能
                if (bottomPos.y() >= rect.top() && bottomPos.y() <= rect.bottom() &&
                    bottomPos.x() >= rect.left() && bottomPos.x() <= rect.right()) {
                    // 可在此处设置角色的草地状态（如character->setOnGrass(true);）
                    // 当前仅做判定，不影响落地
                }
                continue;
            }
            if (bottomPos.y() >= rect.top() && bottomPos.y() <= rect.bottom() &&
                bottomPos.x() >= rect.left() && bottomPos.x() <= rect.right()) {
                pos.setY(rect.top() - (bottomPos.y() - pos.y())); // 角色底部对齐台阶顶部
                vy = 0;
                landed = true;
                break;
            }
        }
        character1->setPos(pos);
        character1->setVelocityY(vy);
        character1->setOnGround(landed);
        if (landed) character1->setJumping(false);
        // 新增：动画更新
        character1->updateAnimation(deltaTime);
    }
    if (character2 != nullptr) {
        TerrainType terrain2 = map->getTerrainType(character2->getBottomPos());
        double speedFactor2 = (terrain2 == TerrainType::Ice) ? 1.5 : 1.0;
        character2->setPos(character2->pos() + character2->getVelocity() * (double) deltaTime * speedFactor2);
        double gravity = 0.0025 * deltaTime; // 重力加速度
        double vy = character2->getVelocityY();
        vy += gravity;
        QPointF pos = character2->pos();
        pos.setY(pos.y() + vy * (double) deltaTime);
        character2->setPos(pos); // 先更新位置
        // 台阶碰撞检测
        bool landed = false;
        QPointF bottomPos = character2->getBottomPos();
        for (const auto& region : map->getTerrainRegions()) {
            QRectF rect = region.rect;
            if (region.type == TerrainType::Grass) {
                // 草地不参与碰撞，但可用于后续功能
                if (bottomPos.y() >= rect.top() && bottomPos.y() <= rect.bottom() &&
                    bottomPos.x() >= rect.left() && bottomPos.x() <= rect.right()) {
                    // 可在此处设置角色的草地状态（如character->setOnGrass(true);）
                    // 当前仅做判定，不影响落地
                }
                continue;
            }
            if (bottomPos.y() >= rect.top() && bottomPos.y() <= rect.bottom() &&
                bottomPos.x() >= rect.left() && bottomPos.x() <= rect.right()) {
                pos.setY(rect.top() - (bottomPos.y() - pos.y())); // 角色底部对齐台阶顶部
                vy = 0;
                landed = true;
                break;
            }
        }
        character2->setPos(pos);
        character2->setVelocityY(vy);
        character2->setOnGround(landed);
        if (landed) character2->setJumping(false);
        // 新增：动画更新
        character2->updateAnimation(deltaTime);
    }
}

void BattleScene::processPicking() {
    Scene::processPicking();
    // 角色1拾取武器
    if (character1 && character1->isCrouching()) {
        Weapon* nearestWeapon = nullptr;
        qreal minDistance = 50.0; // 拾取距离阈值
        for (QGraphicsItem* item : items()) {
            Weapon* weapon = dynamic_cast<Weapon*>(item);
            if (weapon && weapon->isVisible() && weapon != character1->getWeapon()) {
                qreal dist = QLineF(character1->pos(), weapon->pos()).length();
                if (dist < minDistance) {
                    minDistance = dist;
                    nearestWeapon = weapon;
                }
            }
        }
        if (nearestWeapon) {
            character1->pickupWeapon(nearestWeapon);
        }
    }
    // 角色2拾取武器
    if (character2 && character2->isCrouching()) {
        Weapon* nearestWeapon = nullptr;
        qreal minDistance = 50.0;
        for (QGraphicsItem* item : items()) {
            Weapon* weapon = dynamic_cast<Weapon*>(item);
            if (weapon && weapon->isVisible() && weapon != character2->getWeapon()) {
                qreal dist = QLineF(character2->pos(), weapon->pos()).length();
                if (dist < minDistance) {
                    minDistance = dist;
                    nearestWeapon = weapon;
                }
            }
        }
        if (nearestWeapon) {
            character2->pickupWeapon(nearestWeapon);
        }
    }
    if (character1->isPicking()) {
        auto mountable = findNearestUnmountedMountable(character1->pos(), 100.);
        if (mountable != nullptr) {
            spareArmor = dynamic_cast<Armor *>(pickupMountable(character1, mountable));
        }
    }
    if (character2->isPicking()) {
        auto mountable = findNearestUnmountedMountable(character2->pos(), 100.);
        if (mountable != nullptr) {
            spareArmor = dynamic_cast<Armor *>(pickupMountable(character2, mountable));
        }
    }
}

Mountable *BattleScene::findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold) {
    Mountable *nearest = nullptr;
    qreal minDistance = distance_threshold;

    for (QGraphicsItem *item: items()) {
        if (auto mountable = dynamic_cast<Mountable *>(item)) {
            if (!mountable->isMounted()) {
                qreal distance = QLineF(pos, item->pos()).length();
                if (distance < minDistance) {
                    minDistance = distance;
                    nearest = mountable;
                }
            }
        }
    }

    return nearest;
}

Mountable *BattleScene::pickupMountable(Character *character, Mountable *mountable) {
    // Limitation: currently only supports armor
    if (auto armor = dynamic_cast<Armor *>(mountable)) {
        return character->pickupArmor(armor);
    }
    return nullptr;
}

