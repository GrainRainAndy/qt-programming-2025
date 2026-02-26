// ChoosePlayers1Widget.h
#ifndef CHOOSEPLAYERS1WIDGET_H
#define CHOOSEPLAYERS1WIDGET_H
#include <QWidget>
#include "ui_ChoosePlayers1.h"
#include "../utils/PreInfo.h"
class ChoosePlayers1Widget : public QWidget {
    Q_OBJECT
public:
    explicit ChoosePlayers1Widget(QWidget *parent = nullptr);
    PlayerInfo getPlayerInfo() const;
signals:
    void backClicked();
    void nextClicked(const PlayerInfo &info); // 保持接口兼容，实际传递PreInfo.player1
private slots:
    void onChoose(int id);
    void onBack();
    void onNext();
private:
    Ui_Player1_Chooser ui;
    int selectedId = -1;
    void updateChosenUI();
};
#endif // CHOOSEPLAYERS1WIDGET_H
