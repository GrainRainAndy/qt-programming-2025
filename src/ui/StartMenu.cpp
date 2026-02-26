// StartMenu.cpp
// StartMenu实现，连接UI与信号

#include "StartMenu.h"

StartMenu::StartMenu(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    connect(ui.StartBotton, &QPushButton::clicked, this, &StartMenu::startGameClicked);
    connect(ui.SettingButton, &QPushButton::clicked, this, &StartMenu::optionsClicked);
    connect(ui.ExitButton, &QPushButton::clicked, this, &StartMenu::exitClicked);
}

