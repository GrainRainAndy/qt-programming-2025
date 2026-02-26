//
// Created by gerw on 8/20/24.
//
#include "MyGame.h"
#include "Scenes/BattleScene.h"
#include "ui/StartMenu.h"
#include "ui/ChoosePlayers1Widget.h"
#include "ui/ChoosePlayers2Widget.h"
#include "utils/PreInfo.h"
#include "ui/ChooseMapWidget.h"
#include <QCloseEvent>

MyGame::MyGame(QWidget *parent) : QMainWindow(parent) {
    startMenu = new StartMenu(this);
    setCentralWidget(startMenu);
    setFixedSize(800, 600);
    connect(startMenu, &StartMenu::startGameClicked, this, &MyGame::onStartGame);
    connect(startMenu, &StartMenu::exitClicked, this, &MyGame::onExitGame);
}

void MyGame::onStartGame() {
    if (choosePlayers1Widget) {
        delete choosePlayers1Widget;
        choosePlayers1Widget = nullptr;
    }
    if (!choosePlayers1Widget) {
        choosePlayers1Widget = new ChoosePlayers1Widget(this);
        connect(choosePlayers1Widget, &ChoosePlayers1Widget::backClicked, this, &MyGame::onPlayer1Back);
        connect(choosePlayers1Widget, &ChoosePlayers1Widget::nextClicked, this, &MyGame::onPlayer1Next);
    }
    setCentralWidget(choosePlayers1Widget);
    setFixedSize(800, 600);
    if (startMenu) {
        delete startMenu;
        startMenu = nullptr;
    }
}

void MyGame::onPlayer1Back() {
    if (startMenu) {
        delete startMenu;
        startMenu = nullptr;
    }
    startMenu = new StartMenu(this);
    connect(startMenu, &StartMenu::startGameClicked, this, &MyGame::onStartGame);
    connect(startMenu, &StartMenu::exitClicked, this, &MyGame::onExitGame);
    setCentralWidget(startMenu);
    setFixedSize(800, 600);
    if (choosePlayers1Widget) {
        delete choosePlayers1Widget;
        choosePlayers1Widget = nullptr;
    }
}

void MyGame::onPlayer1Next(const PlayerInfo &info) {
    preInfo.player1 = info;
    if (choosePlayers2Widget) {
        delete choosePlayers2Widget;
        choosePlayers2Widget = nullptr;
    }
    choosePlayers2Widget = new ChoosePlayers2Widget(this);
    connect(choosePlayers2Widget, &ChoosePlayers2Widget::backClicked, this, &MyGame::onPlayer2Back);
    connect(choosePlayers2Widget, &ChoosePlayers2Widget::nextClicked, this, &MyGame::onPlayer2Next);
    setCentralWidget(choosePlayers2Widget);
    setFixedSize(800, 600);
    if (choosePlayers1Widget) {
        delete choosePlayers1Widget;
        choosePlayers1Widget = nullptr;
    }
}

void MyGame::onPlayer2Back() {
    if (choosePlayers1Widget) {
        delete choosePlayers1Widget;
        choosePlayers1Widget = nullptr;
    }
    choosePlayers1Widget = new ChoosePlayers1Widget(this);
    connect(choosePlayers1Widget, &ChoosePlayers1Widget::backClicked, this, &MyGame::onPlayer1Back);
    connect(choosePlayers1Widget, &ChoosePlayers1Widget::nextClicked, this, &MyGame::onPlayer1Next);
    setCentralWidget(choosePlayers1Widget);
    setFixedSize(800, 600);
    if (choosePlayers2Widget) {
        delete choosePlayers2Widget;
        choosePlayers2Widget = nullptr;
    }
}

void MyGame::onPlayer2Next(const PlayerInfo &info) {
    preInfo.player2 = info;
    if (chooseMapWidget) {
        delete chooseMapWidget;
        chooseMapWidget = nullptr;
    }
    ChooseMapWidget *mapWidget = new ChooseMapWidget(this);
    chooseMapWidget = mapWidget;
    mapWidget->setPreInfo(preInfo);
    connect(mapWidget, &ChooseMapWidget::backClicked, this, &MyGame::onMapBack);
    connect(mapWidget, &ChooseMapWidget::nextClicked, this, &MyGame::onMapNext);
    setCentralWidget(mapWidget);
    setFixedSize(800, 600);
    if (choosePlayers2Widget) {
        delete choosePlayers2Widget;
        choosePlayers2Widget = nullptr;
    }
}

void MyGame::onMapBack() {
    if (choosePlayers2Widget) {
        delete choosePlayers2Widget;
        choosePlayers2Widget = nullptr;
    }
    choosePlayers2Widget = new ChoosePlayers2Widget(this);
    connect(choosePlayers2Widget, &ChoosePlayers2Widget::backClicked, this, &MyGame::onPlayer2Back);
    connect(choosePlayers2Widget, &ChoosePlayers2Widget::nextClicked, this, &MyGame::onPlayer2Next);
    setCentralWidget(choosePlayers2Widget);
    setFixedSize(800, 600);
    if (chooseMapWidget) {
        delete chooseMapWidget;
        chooseMapWidget = nullptr;
    }
}

void MyGame::onMapNext(int mapId) {
    preInfo.mapId = mapId;
    MapType mapType = MapType::MushroomGarden;
    switch (mapId) {
        case 0: mapType = MapType::Roof; break;
        case 1: mapType = MapType::MushroomGarden; break;
        case 2: mapType = MapType::Aquarium; break;
        case 3: mapType = MapType::MoreMaps; break;
        default: mapType = MapType::MushroomGarden; break;
    }
    if (battleScene) {
        delete battleScene;
        battleScene = nullptr;
    }
    battleScene = new BattleScene(mapType, preInfo.player1.characterId, preInfo.player2.characterId);
    if (!view) {
        view = new QGraphicsView(this);
        view->setScene(battleScene);
        view->setFixedSize((int) battleScene->width(), (int) battleScene->height());
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    } else {
        view->setScene(battleScene);
        view->setFixedSize((int) battleScene->width(), (int) battleScene->height());
    }
    setCentralWidget(view);
    setFixedSize(view->sizeHint());
    if (chooseMapWidget) {
        delete chooseMapWidget;
        chooseMapWidget = nullptr;
    }
    battleScene->startLoop();
}

void MyGame::onExitToMenu() {
    if (startMenu) {
        delete startMenu;
        startMenu = nullptr;
    }
    startMenu = new StartMenu(this);
    connect(startMenu, &StartMenu::startGameClicked, this, &MyGame::onStartGame);
    connect(startMenu, &StartMenu::exitClicked, this, &MyGame::onExitGame);
    setCentralWidget(startMenu);
    setFixedSize(800, 600);
}

void MyGame::onExitGame() {
    close();
}
