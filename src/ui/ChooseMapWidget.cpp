// ChooseMapWidget.cpp
#include "ChooseMapWidget.h"
#include <QPushButton>

ChooseMapWidget::ChooseMapWidget(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    // 地图选择按钮连接
    connect(ui.ChooseButton_Roof, &QPushButton::clicked, this, [this]{ onChoose(0); });
    connect(ui.ChooseButton_MushroomGarden, &QPushButton::clicked, this, [this]{ onChoose(1); });
    connect(ui.ChooseButton_Aquarium, &QPushButton::clicked, this, [this]{ onChoose(2); });
    connect(ui.ChooseButton_MoreMaps, &QPushButton::clicked, this, [this]{ onChoose(3); });
    // Back/Next按钮连接
    connect(ui.BackButton_3, &QPushButton::clicked, this, &ChooseMapWidget::onBack);
    connect(ui.NextBotton_3, &QPushButton::clicked, this, &ChooseMapWidget::onNext);
    // 初始隐藏所有选中高亮
    ui.Roof_Chosen->setVisible(false);
    ui.MushroomGarden_Chosen->setVisible(false);
    ui.Aquarium_Chosen->setVisible(false);
    // 让高亮层和地图图像层不阻挡鼠标事件
    ui.Roof_Chosen->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Img_Roof->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.MushroomGarden_Chosen->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Img_MarshroomGarden->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Aquarium_Chosen->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui.Img_Aquarium->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

void ChooseMapWidget::setPreInfo(const PreInfo &info) {
    preInfo = info;
}

void ChooseMapWidget::onChoose(int id) {
    selectedId = id;
    updateChosenUI();
}

void ChooseMapWidget::updateChosenUI() {
    ui.Roof_Chosen->setVisible(selectedId == 0);
    ui.MushroomGarden_Chosen->setVisible(selectedId == 1);
    ui.Aquarium_Chosen->setVisible(selectedId == 2);
    // MoreMaps没有高亮
}

void ChooseMapWidget::onBack() {
    emit backClicked();
}

void ChooseMapWidget::onNext() {
    if (selectedId != -1) {
        emit nextClicked(selectedId);
    }
}

