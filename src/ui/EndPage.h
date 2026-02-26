#include <QWidget>
#include "ui_EndPage.h"

class EndPage : public QWidget {
public:
    explicit EndPage(int winner, QWidget *parent = nullptr)
        : QWidget(parent) {
        ui.setupUi(this);
        if (winner == 1) {
            ui.label->setText(tr("Player 1 Wins!"));
        } else if (winner == 2) {
            ui.label->setText(tr("Player 2 Wins!"));
        } else {
            ui.label->setText(tr("Draw!"));
        }
    }
private:
    Ui::StartMenu ui;
};

