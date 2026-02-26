//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_MYGAME_H
#define QT_PROGRAMMING_2024_MYGAME_H

#include <QGraphicsView>
#include <QMainWindow>
#include "Scenes/Scene.h"
#include "ui/StartMenu.h"
#include "ui/ChoosePlayers1Widget.h"
#include "ui/ChoosePlayers2Widget.h"
#include "utils/PreInfo.h"

class MyGame : public QMainWindow {
Q_OBJECT

public:
    explicit MyGame(QWidget *parent = nullptr);

private slots:
    void onStartGame();
    void onExitGame();
    void onPlayer1Back();
    void onPlayer1Next(const PlayerInfo &info);
    void onPlayer2Back();
    void onPlayer2Next(const PlayerInfo &info);
    void onMapBack();
    void onMapNext(int mapId);
    void onExitToMenu();

private:
    Scene *battleScene = nullptr;
    QGraphicsView *view = nullptr;
    StartMenu *startMenu = nullptr;
    ChoosePlayers1Widget *choosePlayers1Widget = nullptr;
    ChoosePlayers2Widget *choosePlayers2Widget = nullptr;
    QWidget *chooseMapWidget = nullptr;
    PreInfo preInfo;
};


#endif //QT_PROGRAMMING_2024_MYGAME_H
