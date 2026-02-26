// ChoosePlayers1Widget.cpp
#include "ChoosePlayers1Widget.h"
#include <QPushButton>

ChoosePlayers1Widget::ChoosePlayers1Widget(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    // 角色选择按钮连接
    connect(ui.ChooseButton_PeaShootSingle, &QPushButton::clicked, this, [this]{ onChoose(0); });
    connect(ui.ChooseButton_SnowPea, &QPushButton::clicked, this, [this]{ onChoose(1); });
    connect(ui.ChooseButton_Cabbagepult, &QPushButton::clicked, this, [this]{ onChoose(2); });
    connect(ui.ChooseButton_Chomper, &QPushButton::clicked, this, [this]{ onChoose(3); });
    // Back/Next按钮连接
    connect(ui.BackButton, &QPushButton::clicked, this, &ChoosePlayers1Widget::onBack);
    connect(ui.NextBotton, &QPushButton::clicked, this, &ChoosePlayers1Widget::onNext);
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
void ChoosePlayers1Widget::onChoose(int id) {
    selectedId = id;
    updateChosenUI();
}
void ChoosePlayers1Widget::updateChosenUI() {
    ui.PeaShooterSingle_Chosen->setVisible(selectedId == 0);
    ui.SnowPea_Chosen->setVisible(selectedId == 1);
    ui.Cabbagepult_Chosen->setVisible(selectedId == 2);
    ui.Chomper_Chosen->setVisible(selectedId == 3);
}
void ChoosePlayers1Widget::onBack() {
    emit backClicked();
}
void ChoosePlayers1Widget::onNext() {
    if (selectedId != -1) {
        PlayerInfo info;
        info.name = "Player1";
        info.characterId = selectedId;
        emit nextClicked(info); // 实际传递PreInfo.player1
    }
}
PlayerInfo ChoosePlayers1Widget::getPlayerInfo() const {
    PlayerInfo info;
    info.name = "Player1";
    info.characterId = selectedId;
    return info;
}
