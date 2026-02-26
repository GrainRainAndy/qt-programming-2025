// StartMenu.h
// 用于替换MainMenu，实现主菜单功能，基于Qt Designer生成的UI

#ifndef QT_PROGRAMMING_2024_STARTMENU_H
#define QT_PROGRAMMING_2024_STARTMENU_H

#include <QWidget>
#include "ui_StartMenu.h"

class StartMenu : public QWidget {
    Q_OBJECT
public:
    explicit StartMenu(QWidget *parent = nullptr);

signals:
    void startGameClicked();
    void optionsClicked();
    void exitClicked();

private:
    Ui_StartMenu ui;
};

#endif //QT_PROGRAMMING_2024_STARTMENU_H

