// ChoosePlayers2Widget.h
#ifndef CHOOSEPLAYERS2WIDGET_H
#define CHOOSEPLAYERS2WIDGET_H
#include <QWidget>
#include "ui_ChoosePlayers2.h"
#include "../utils/PreInfo.h"
class ChoosePlayers2Widget : public QWidget {
    Q_OBJECT
public:
    explicit ChoosePlayers2Widget(QWidget *parent = nullptr);
    PlayerInfo getPlayerInfo() const;
signals:
    void backClicked();
    void nextClicked(const PlayerInfo &info); // 保持接口兼容，实际传递PreInfo.player2
private slots:
    void onChoose(int id);
    void onBack();
    void onNext();
private:
    Ui_Player2_Chooser ui;
    int selectedId = -1;
    void updateChosenUI();
};
#endif // CHOOSEPLAYERS2WIDGET_H
