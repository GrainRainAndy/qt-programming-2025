// ChooseMapWidget.h
#ifndef CHOOSEMAPWIDGET_H
#define CHOOSEMAPWIDGET_H
#include <QWidget>
#include "../utils/PreInfo.h"
#include "ui_ChooseMap.h"
class ChooseMapWidget : public QWidget {
    Q_OBJECT
public:
    explicit ChooseMapWidget(QWidget *parent = nullptr);
    void setPreInfo(const PreInfo &info);
signals:
    void backClicked();
    void nextClicked(int mapId);
private slots:
    void onChoose(int id);
    void onBack();
    void onNext();
private:
    Ui_Form ui;
    int selectedId = -1;
    PreInfo preInfo;
    void updateChosenUI();
};
#endif // CHOOSEMAPWIDGET_H

