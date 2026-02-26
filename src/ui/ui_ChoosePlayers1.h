/********************************************************************************
** Form generated from reading UI file 'ChoosePlayers1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEPLAYERS1_H
#define UI_CHOOSEPLAYERS1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player1_Chooser
{
public:
    QLabel *Bg;
    QLabel *ChooserBg;
    QLabel *Title;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QStackedWidget *Stacked_SnowPea;
    QWidget *page_3;
    QPushButton *ChooseButton_SnowPea;
    QLabel *Img_SnowPea;
    QLabel *SnowPea_Chosen;
    QWidget *page_4;
    QPushButton *BackButton;
    QStackedWidget *Stacked_PeaShooterSingle;
    QWidget *page;
    QPushButton *ChooseButton_PeaShootSingle;
    QLabel *Img_PeaShooterSingle;
    QLabel *PeaShooterSingle_Chosen;
    QWidget *page_2;
    QPushButton *NextBotton;
    QStackedWidget *Stacked_Cabbagepult;
    QWidget *page_5;
    QPushButton *ChooseButton_Cabbagepult;
    QLabel *Img_Cabbagepult;
    QLabel *Cabbagepult_Chosen;
    QWidget *page_6;
    QStackedWidget *Stacked_Chomper;
    QWidget *page_7;
    QPushButton *ChooseButton_Chomper;
    QLabel *Img_Chomper;
    QLabel *Chomper_Chosen;
    QWidget *page_8;

    void setupUi(QWidget *Player1_Chooser)
    {
        if (Player1_Chooser->objectName().isEmpty())
            Player1_Chooser->setObjectName("Player1_Chooser");
        Player1_Chooser->resize(800, 600);
        Bg = new QLabel(Player1_Chooser);
        Bg->setObjectName("Bg");
        Bg->setGeometry(QRect(0, 0, 800, 600));
        Bg->setPixmap(QPixmap(QString::fromUtf8(":/Items/titlescreen_new.jpg")));
        ChooserBg = new QLabel(Player1_Chooser);
        ChooserBg->setObjectName("ChooserBg");
        ChooserBg->setGeometry(QRect(194, 175, 360, 325));
        ChooserBg->setPixmap(QPixmap(QString::fromUtf8(":/Items/SeedChooser_Background.png")));
        ChooserBg->setScaledContents(true);
        Title = new QLabel(Player1_Chooser);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(200, 130, 351, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Papyrus")});
        font.setPointSize(20);
        font.setBold(true);
        Title->setFont(font);
        Title->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(Player1_Chooser);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(200, 210, 351, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Stacked_SnowPea = new QStackedWidget(gridLayoutWidget);
        Stacked_SnowPea->setObjectName("Stacked_SnowPea");
        Stacked_SnowPea->setMinimumSize(QSize(100, 100));
        Stacked_SnowPea->setMaximumSize(QSize(100, 100));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        ChooseButton_SnowPea = new QPushButton(page_3);
        ChooseButton_SnowPea->setObjectName("ChooseButton_SnowPea");
        ChooseButton_SnowPea->setGeometry(QRect(0, 0, 100, 100));
        ChooseButton_SnowPea->setMinimumSize(QSize(100, 100));
        ChooseButton_SnowPea->setMaximumSize(QSize(100, 100));
        ChooseButton_SnowPea->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/ShovelBank.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Img_SnowPea = new QLabel(page_3);
        Img_SnowPea->setObjectName("Img_SnowPea");
        Img_SnowPea->setGeometry(QRect(10, 3, 81, 81));
        Img_SnowPea->setMinimumSize(QSize(81, 81));
        Img_SnowPea->setMaximumSize(QSize(81, 81));
        Img_SnowPea->setPixmap(QPixmap(QString::fromUtf8(":/Items/Plants/SnowPea.png")));
        Img_SnowPea->setAlignment(Qt::AlignCenter);
        SnowPea_Chosen = new QLabel(page_3);
        SnowPea_Chosen->setObjectName("SnowPea_Chosen");
        SnowPea_Chosen->setGeometry(QRect(0, 0, 100, 100));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Papyrus")});
        font1.setPointSize(14);
        SnowPea_Chosen->setFont(font1);
        SnowPea_Chosen->setAutoFillBackground(false);
        SnowPea_Chosen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/SeedChooser_Button.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button2.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button_Disabled.png) 0 0 0 0 stretch stretch;\n"
"}"));
        SnowPea_Chosen->setTextFormat(Qt::PlainText);
        SnowPea_Chosen->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/SeedChooser_Button_Glow.png")));
        SnowPea_Chosen->setScaledContents(true);
        SnowPea_Chosen->setAlignment(Qt::AlignCenter);
        SnowPea_Chosen->setWordWrap(false);
        Stacked_SnowPea->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        Stacked_SnowPea->addWidget(page_4);

        gridLayout->addWidget(Stacked_SnowPea, 2, 1, 1, 1);

        BackButton = new QPushButton(gridLayoutWidget);
        BackButton->setObjectName("BackButton");
        BackButton->setMinimumSize(QSize(100, 40));
        BackButton->setMaximumSize(QSize(100, 40));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Papyrus")});
        font2.setPointSize(18);
        font2.setBold(true);
        BackButton->setFont(font2);
        BackButton->setAutoFillBackground(false);
        BackButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/SeedChooser_Button.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button2.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button_Disabled.png) 0 0 0 0 stretch stretch;\n"
"}"));

        gridLayout->addWidget(BackButton, 4, 0, 1, 1);

        Stacked_PeaShooterSingle = new QStackedWidget(gridLayoutWidget);
        Stacked_PeaShooterSingle->setObjectName("Stacked_PeaShooterSingle");
        Stacked_PeaShooterSingle->setMinimumSize(QSize(100, 100));
        Stacked_PeaShooterSingle->setMaximumSize(QSize(100, 100));
        page = new QWidget();
        page->setObjectName("page");
        ChooseButton_PeaShootSingle = new QPushButton(page);
        ChooseButton_PeaShootSingle->setObjectName("ChooseButton_PeaShootSingle");
        ChooseButton_PeaShootSingle->setGeometry(QRect(0, 0, 100, 100));
        ChooseButton_PeaShootSingle->setMinimumSize(QSize(100, 100));
        ChooseButton_PeaShootSingle->setMaximumSize(QSize(100, 100));
        ChooseButton_PeaShootSingle->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/ShovelBank.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Img_PeaShooterSingle = new QLabel(page);
        Img_PeaShooterSingle->setObjectName("Img_PeaShooterSingle");
        Img_PeaShooterSingle->setGeometry(QRect(10, 3, 81, 81));
        Img_PeaShooterSingle->setMinimumSize(QSize(81, 81));
        Img_PeaShooterSingle->setMaximumSize(QSize(81, 81));
        Img_PeaShooterSingle->setPixmap(QPixmap(QString::fromUtf8(":/Items/Plants/PeaShooterSingle.png")));
        Img_PeaShooterSingle->setAlignment(Qt::AlignCenter);
        PeaShooterSingle_Chosen = new QLabel(page);
        PeaShooterSingle_Chosen->setObjectName("PeaShooterSingle_Chosen");
        PeaShooterSingle_Chosen->setGeometry(QRect(0, 0, 100, 100));
        PeaShooterSingle_Chosen->setFont(font1);
        PeaShooterSingle_Chosen->setAutoFillBackground(false);
        PeaShooterSingle_Chosen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/SeedChooser_Button.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button2.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button_Disabled.png) 0 0 0 0 stretch stretch;\n"
"}"));
        PeaShooterSingle_Chosen->setTextFormat(Qt::PlainText);
        PeaShooterSingle_Chosen->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/SeedChooser_Button_Glow.png")));
        PeaShooterSingle_Chosen->setScaledContents(true);
        PeaShooterSingle_Chosen->setAlignment(Qt::AlignCenter);
        PeaShooterSingle_Chosen->setWordWrap(false);
        Stacked_PeaShooterSingle->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        Stacked_PeaShooterSingle->addWidget(page_2);

        gridLayout->addWidget(Stacked_PeaShooterSingle, 2, 0, 1, 1);

        NextBotton = new QPushButton(gridLayoutWidget);
        NextBotton->setObjectName("NextBotton");
        NextBotton->setMinimumSize(QSize(100, 40));
        NextBotton->setMaximumSize(QSize(100, 40));
        NextBotton->setFont(font2);
        NextBotton->setAutoFillBackground(false);
        NextBotton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/SeedChooser_Button.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button2.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button_Disabled.png) 0 0 0 0 stretch stretch;\n"
"}"));

        gridLayout->addWidget(NextBotton, 4, 1, 1, 1);

        Stacked_Cabbagepult = new QStackedWidget(gridLayoutWidget);
        Stacked_Cabbagepult->setObjectName("Stacked_Cabbagepult");
        Stacked_Cabbagepult->setMinimumSize(QSize(100, 100));
        Stacked_Cabbagepult->setMaximumSize(QSize(100, 100));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        ChooseButton_Cabbagepult = new QPushButton(page_5);
        ChooseButton_Cabbagepult->setObjectName("ChooseButton_Cabbagepult");
        ChooseButton_Cabbagepult->setGeometry(QRect(0, 0, 100, 100));
        ChooseButton_Cabbagepult->setMinimumSize(QSize(100, 100));
        ChooseButton_Cabbagepult->setMaximumSize(QSize(100, 100));
        ChooseButton_Cabbagepult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/ShovelBank.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Img_Cabbagepult = new QLabel(page_5);
        Img_Cabbagepult->setObjectName("Img_Cabbagepult");
        Img_Cabbagepult->setGeometry(QRect(0, 0, 100, 100));
        Img_Cabbagepult->setMinimumSize(QSize(81, 81));
        Img_Cabbagepult->setMaximumSize(QSize(146, 146));
        Img_Cabbagepult->setPixmap(QPixmap(QString::fromUtf8(":/Items/Plants/Cabbagepult.png")));
        Img_Cabbagepult->setScaledContents(true);
        Img_Cabbagepult->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        Cabbagepult_Chosen = new QLabel(page_5);
        Cabbagepult_Chosen->setObjectName("Cabbagepult_Chosen");
        Cabbagepult_Chosen->setGeometry(QRect(0, 0, 100, 100));
        Cabbagepult_Chosen->setFont(font1);
        Cabbagepult_Chosen->setAutoFillBackground(false);
        Cabbagepult_Chosen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/SeedChooser_Button.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button2.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button_Disabled.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Cabbagepult_Chosen->setTextFormat(Qt::PlainText);
        Cabbagepult_Chosen->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/SeedChooser_Button_Glow.png")));
        Cabbagepult_Chosen->setScaledContents(true);
        Cabbagepult_Chosen->setAlignment(Qt::AlignCenter);
        Cabbagepult_Chosen->setWordWrap(false);
        Stacked_Cabbagepult->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        Stacked_Cabbagepult->addWidget(page_6);

        gridLayout->addWidget(Stacked_Cabbagepult, 3, 0, 1, 1);

        Stacked_Chomper = new QStackedWidget(gridLayoutWidget);
        Stacked_Chomper->setObjectName("Stacked_Chomper");
        Stacked_Chomper->setMinimumSize(QSize(100, 100));
        Stacked_Chomper->setMaximumSize(QSize(100, 100));
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        ChooseButton_Chomper = new QPushButton(page_7);
        ChooseButton_Chomper->setObjectName("ChooseButton_Chomper");
        ChooseButton_Chomper->setGeometry(QRect(0, 0, 100, 100));
        ChooseButton_Chomper->setMinimumSize(QSize(100, 100));
        ChooseButton_Chomper->setMaximumSize(QSize(100, 100));
        ChooseButton_Chomper->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/ShovelBank.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Img_Chomper = new QLabel(page_7);
        Img_Chomper->setObjectName("Img_Chomper");
        Img_Chomper->setGeometry(QRect(10, 3, 81, 81));
        Img_Chomper->setMinimumSize(QSize(81, 81));
        Img_Chomper->setMaximumSize(QSize(81, 81));
        Img_Chomper->setPixmap(QPixmap(QString::fromUtf8(":/Items/Plants/Chomper.png")));
        Img_Chomper->setScaledContents(true);
        Img_Chomper->setAlignment(Qt::AlignCenter);
        Chomper_Chosen = new QLabel(page_7);
        Chomper_Chosen->setObjectName("Chomper_Chosen");
        Chomper_Chosen->setGeometry(QRect(0, 0, 100, 100));
        Chomper_Chosen->setFont(font1);
        Chomper_Chosen->setAutoFillBackground(false);
        Chomper_Chosen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/SeedChooser_Button.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button2.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-image: url(:/Items/ui/SeedChooser_Button_Disabled.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Chomper_Chosen->setTextFormat(Qt::PlainText);
        Chomper_Chosen->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/SeedChooser_Button_Glow.png")));
        Chomper_Chosen->setScaledContents(true);
        Chomper_Chosen->setAlignment(Qt::AlignCenter);
        Chomper_Chosen->setWordWrap(false);
        Stacked_Chomper->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        Stacked_Chomper->addWidget(page_8);

        gridLayout->addWidget(Stacked_Chomper, 3, 1, 1, 1);


        retranslateUi(Player1_Chooser);

        QMetaObject::connectSlotsByName(Player1_Chooser);
    } // setupUi

    void retranslateUi(QWidget *Player1_Chooser)
    {
        Player1_Chooser->setWindowTitle(QCoreApplication::translate("Player1_Chooser", "Form", nullptr));
        Bg->setText(QString());
        ChooserBg->setText(QString());
        Title->setText(QCoreApplication::translate("Player1_Chooser", "Choose Initiate Player1", nullptr));
        ChooseButton_SnowPea->setText(QString());
        Img_SnowPea->setText(QString());
        SnowPea_Chosen->setText(QString());
        BackButton->setText(QCoreApplication::translate("Player1_Chooser", "Back", nullptr));
        ChooseButton_PeaShootSingle->setText(QString());
        Img_PeaShooterSingle->setText(QString());
        PeaShooterSingle_Chosen->setText(QString());
        NextBotton->setText(QCoreApplication::translate("Player1_Chooser", "Next", nullptr));
        ChooseButton_Cabbagepult->setText(QString());
        Img_Cabbagepult->setText(QString());
        Cabbagepult_Chosen->setText(QString());
        ChooseButton_Chomper->setText(QString());
        Img_Chomper->setText(QString());
        Chomper_Chosen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Player1_Chooser: public Ui_Player1_Chooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEPLAYERS1_H
