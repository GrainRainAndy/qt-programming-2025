/********************************************************************************
** Form generated from reading UI file 'EndPage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDPAGE_H
#define UI_ENDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QLabel *Bg_img;
    QLabel *ChooserBg;
    QLabel *label;
    QPushButton *BackButton_3;
    QPushButton *NextBotton_3;

    void setupUi(QWidget *StartMenu)
    {
        if (StartMenu->objectName().isEmpty())
            StartMenu->setObjectName("StartMenu");
        StartMenu->resize(800, 600);
        Bg_img = new QLabel(StartMenu);
        Bg_img->setObjectName("Bg_img");
        Bg_img->setGeometry(QRect(0, 0, 800, 600));
        Bg_img->setPixmap(QPixmap(QString::fromUtf8(":/Items/titlescreen_new.jpg")));
        Bg_img->setAlignment(Qt::AlignCenter);
        ChooserBg = new QLabel(StartMenu);
        ChooserBg->setObjectName("ChooserBg");
        ChooserBg->setGeometry(QRect(194, 175, 360, 325));
        ChooserBg->setPixmap(QPixmap(QString::fromUtf8(":/Items/SeedChooser_Background.png")));
        ChooserBg->setScaledContents(true);
        label = new QLabel(StartMenu);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 230, 281, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Papyrus")});
        font.setPointSize(36);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: none;\n"
"border-image: url(:/Items/ui/SeedChooser_Button.png) 0 0 0 0 stretch stretch;"));
        label->setAlignment(Qt::AlignCenter);
        BackButton_3 = new QPushButton(StartMenu);
        BackButton_3->setObjectName("BackButton_3");
        BackButton_3->setGeometry(QRect(247, 380, 100, 40));
        BackButton_3->setMinimumSize(QSize(100, 40));
        BackButton_3->setMaximumSize(QSize(100, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Papyrus")});
        font1.setPointSize(18);
        font1.setBold(true);
        BackButton_3->setFont(font1);
        BackButton_3->setAutoFillBackground(false);
        BackButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        NextBotton_3 = new QPushButton(StartMenu);
        NextBotton_3->setObjectName("NextBotton_3");
        NextBotton_3->setGeometry(QRect(400, 380, 100, 40));
        NextBotton_3->setMinimumSize(QSize(100, 40));
        NextBotton_3->setMaximumSize(QSize(100, 40));
        NextBotton_3->setFont(font1);
        NextBotton_3->setAutoFillBackground(false);
        NextBotton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QWidget *StartMenu)
    {
        StartMenu->setWindowTitle(QCoreApplication::translate("StartMenu", "Form", nullptr));
        Bg_img->setText(QString());
        ChooserBg->setText(QString());
        label->setText(QCoreApplication::translate("StartMenu", "Game Over", nullptr));
        BackButton_3->setText(QCoreApplication::translate("StartMenu", "Back", nullptr));
        NextBotton_3->setText(QCoreApplication::translate("StartMenu", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDPAGE_H
