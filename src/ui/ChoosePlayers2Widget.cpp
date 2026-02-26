// ChoosePlayers2Widget.cpp
#include "ChoosePlayers2Widget.h"
#include <QPushButton>

ChoosePlayers2Widget::ChoosePlayers2Widget(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    connect(ui.ChooseButton_PeaShootSingle, &QPushButton::clicked, this, [this]{ onChoose(0); });
    connect(ui.ChooseButton_SnowPea, &QPushButton::clicked, this, [this]{ onChoose(1); });
    connect(ui.ChooseButton_Cabbagepult, &QPushButton::clicked, this, [this]{ onChoose(2); });
    connect(ui.ChooseButton_Chomper, &QPushButton::clicked, this, [this]{ onChoose(3); });
    connect(ui.BackButton, &QPushButton::clicked, this, &ChoosePlayers2Widget::onBack);
    connect(ui.NextBotton, &QPushButton::clicked, this, &ChoosePlayers2Widget::onNext);
    // 初始隐藏所有选中高亮
    ui.PeaShooterSingle_Chosen->setVisible(false);
    ui.SnowPea_Chosen->setVisible(false);
    ui.Cabbagepult_Chosen->setVisible(false);
    ui.Chomper_Chosen->setVisible(false);
    // 让高亮层和角色图像层不阻挡鼠标事件
    ui.PeaShooterSingle_Chosen->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Img_PeaShooterSingle->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.SnowPea_Chosen->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Img_SnowPea->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Cabbagepult_Chosen->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Img_Cabbagepult->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Chomper_Chosen->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Img_Chomper->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}
void ChoosePlayers2Widget::onChoose(int id) {
    selectedId = id;
    updateChosenUI();
}
void ChoosePlayers2Widget::updateChosenUI() {
    ui.PeaShooterSingle_Chosen->setVisible(selectedId == 0);
    ui.SnowPea_Chosen->setVisible(selectedId == 1);
    ui.Cabbagepult_Chosen->setVisible(selectedId == 2);
    ui.Chomper_Chosen->setVisible(selectedId == 3);
}
void ChoosePlayers2Widget::onBack() {
    emit backClicked();
}
void ChoosePlayers2Widget::onNext() {
    if (selectedId != -1) {
        PlayerInfo info;
        info.name = "Player2";
        info.characterId = selectedId;
        emit nextClicked(info); // 实际传递PreInfo.player2
    }
}
PlayerInfo ChoosePlayers2Widget::getPlayerInfo() const {
    PlayerInfo info;
    info.name = "Player2";
    info.characterId = selectedId;
    return info;
}
