/********************************************************************************
** Form generated from reading UI file 'Map_MushroomGarden.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_MUSHROOMGARDEN_H
#define UI_MAP_MUSHROOMGARDEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Map_MushroomGarden
{
public:
    QLabel *Bg_Map;
    QLabel *Bg_Bar;
    QWidget *HPBar_Player1;
    QLabel *HPBar_Background_1;
    QLabel *HPBar_Front_1;
    QWidget *HPBar_Player2;
    QLabel *HPBar_Background_2;
    QLabel *HPBar_Front_2;
    QLabel *dirt_1;
    QLabel *dirt_2;
    QLabel *dirt_3;
    QLabel *grass_4;
    QLabel *ice_1;
    QLabel *ice_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Map_MushroomGarden)
    {
        if (Map_MushroomGarden->objectName().isEmpty())
            Map_MushroomGarden->setObjectName("Map_MushroomGarden");
        Map_MushroomGarden->resize(800, 600);
        Bg_Map = new QLabel(Map_MushroomGarden);
        Bg_Map->setObjectName("Bg_Map");
        Bg_Map->setGeometry(QRect(0, 0, 800, 600));
        Bg_Map->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Battlefield/MushroomGarden.jpg")));
        Bg_Map->setTextInteractionFlags(Qt::NoTextInteraction);
        Bg_Bar = new QLabel(Map_MushroomGarden);
        Bg_Bar->setObjectName("Bg_Bar");
        Bg_Bar->setGeometry(QRect(0, 400, 800, 200));
        Bg_Bar->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/dialog_frame.png")));
        Bg_Bar->setScaledContents(true);
        Bg_Bar->setAlignment(Qt::AlignCenter);
        HPBar_Player1 = new QWidget(Map_MushroomGarden);
        HPBar_Player1->setObjectName("HPBar_Player1");
        HPBar_Player1->setGeometry(QRect(50, 440, 220, 60));
        HPBar_Background_1 = new QLabel(HPBar_Player1);
        HPBar_Background_1->setObjectName("HPBar_Background_1");
        HPBar_Background_1->setGeometry(QRect(10, 10, 200, 40));
        HPBar_Background_1->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/hpbar_bk.png")));
        HPBar_Background_1->setScaledContents(true);
        HPBar_Background_1->setTextInteractionFlags(Qt::NoTextInteraction);
        HPBar_Front_1 = new QLabel(HPBar_Player1);
        HPBar_Front_1->setObjectName("HPBar_Front_1");
        HPBar_Front_1->setGeometry(QRect(10, 10, 200, 40));
        HPBar_Front_1->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/hpbar_fr.png")));
        HPBar_Front_1->setScaledContents(true);
        HPBar_Front_1->setTextInteractionFlags(Qt::NoTextInteraction);
        HPBar_Player2 = new QWidget(Map_MushroomGarden);
        HPBar_Player2->setObjectName("HPBar_Player2");
        HPBar_Player2->setGeometry(QRect(500, 440, 220, 60));
        HPBar_Background_2 = new QLabel(HPBar_Player2);
        HPBar_Background_2->setObjectName("HPBar_Background_2");
        HPBar_Background_2->setGeometry(QRect(10, 10, 200, 40));
        HPBar_Background_2->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/hpbar_bk.png")));
        HPBar_Background_2->setScaledContents(true);
        HPBar_Background_2->setTextInteractionFlags(Qt::NoTextInteraction);
        HPBar_Front_2 = new QLabel(HPBar_Player2);
        HPBar_Front_2->setObjectName("HPBar_Front_2");
        HPBar_Front_2->setGeometry(QRect(10, 10, 200, 40));
        HPBar_Front_2->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/hpbar_fr.png")));
        HPBar_Front_2->setScaledContents(true);
        HPBar_Front_2->setTextInteractionFlags(Qt::NoTextInteraction);
        dirt_1 = new QLabel(Map_MushroomGarden);
        dirt_1->setObjectName("dirt_1");
        dirt_1->setGeometry(QRect(0, 370, 800, 30));
        dirt_1->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Territory/LoadBar_dirt.png")));
        dirt_1->setScaledContents(true);
        dirt_1->setTextInteractionFlags(Qt::NoTextInteraction);
        dirt_2 = new QLabel(Map_MushroomGarden);
        dirt_2->setObjectName("dirt_2");
        dirt_2->setGeometry(QRect(110, 290, 200, 30));
        dirt_2->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Territory/LoadBar_dirt.png")));
        dirt_2->setScaledContents(true);
        dirt_2->setTextInteractionFlags(Qt::NoTextInteraction);
        dirt_3 = new QLabel(Map_MushroomGarden);
        dirt_3->setObjectName("dirt_3");
        dirt_3->setGeometry(QRect(490, 290, 200, 30));
        dirt_3->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Territory/LoadBar_dirt.png")));
        dirt_3->setScaledContents(true);
        dirt_3->setTextInteractionFlags(Qt::NoTextInteraction);
        grass_4 = new QLabel(Map_MushroomGarden);
        grass_4->setObjectName("grass_4");
        grass_4->setGeometry(QRect(300, 350, 200, 30));
        grass_4->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Territory/LoadBar_grass.png")));
        grass_4->setScaledContents(true);
        grass_4->setTextInteractionFlags(Qt::NoTextInteraction);
        ice_1 = new QLabel(Map_MushroomGarden);
        ice_1->setObjectName("ice_1");
        ice_1->setGeometry(QRect(280, 210, 86, 30));
        ice_1->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Territory/ice_cap.png")));
        ice_1->setScaledContents(true);
        ice_1->setTextInteractionFlags(Qt::NoTextInteraction);
        ice_2 = new QLabel(Map_MushroomGarden);
        ice_2->setObjectName("ice_2");
        ice_2->setGeometry(QRect(430, 210, 86, 30));
        ice_2->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Territory/ice_cap.png")));
        ice_2->setScaledContents(true);
        ice_2->setTextInteractionFlags(Qt::NoTextInteraction);
        label = new QLabel(Map_MushroomGarden);
        label->setObjectName("label");
        label->setGeometry(QRect(63, 505, 191, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Papyrus")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #5F6181"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(Map_MushroomGarden);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(510, 500, 191, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: #5F6181"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(Map_MushroomGarden);

        QMetaObject::connectSlotsByName(Map_MushroomGarden);
    } // setupUi

    void retranslateUi(QWidget *Map_MushroomGarden)
    {
        Map_MushroomGarden->setWindowTitle(QCoreApplication::translate("Map_MushroomGarden", "Form", nullptr));
        Bg_Map->setText(QString());
        Bg_Bar->setText(QString());
        HPBar_Background_1->setText(QString());
        HPBar_Front_1->setText(QString());
        HPBar_Background_2->setText(QString());
        HPBar_Front_2->setText(QString());
        dirt_1->setText(QString());
        dirt_2->setText(QString());
        dirt_3->setText(QString());
        grass_4->setText(QString());
        ice_1->setText(QString());
        ice_2->setText(QString());
        label->setText(QCoreApplication::translate("Map_MushroomGarden", "Player1", nullptr));
        label_2->setText(QCoreApplication::translate("Map_MushroomGarden", "Player2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Map_MushroomGarden: public Ui_Map_MushroomGarden {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_MUSHROOMGARDEN_H
