/********************************************************************************
** Form generated from reading UI file 'StartMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_H
#define UI_STARTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QLabel *Bg_img;
    QLabel *ChooserBg;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *StartBotton;
    QPushButton *SettingButton;
    QPushButton *ExitButton;

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
        widget = new QWidget(StartMenu);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(236, 205, 281, 281));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(5, 0, 5, 0);
        StartBotton = new QPushButton(widget);
        StartBotton->setObjectName("StartBotton");
        StartBotton->setMinimumSize(QSize(270, 40));
        StartBotton->setMaximumSize(QSize(270, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Papyrus")});
        font.setPointSize(18);
        font.setBold(true);
        StartBotton->setFont(font);
        StartBotton->setAutoFillBackground(false);
        StartBotton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout->addWidget(StartBotton);

        SettingButton = new QPushButton(widget);
        SettingButton->setObjectName("SettingButton");
        SettingButton->setMinimumSize(QSize(270, 40));
        SettingButton->setMaximumSize(QSize(270, 40));
        SettingButton->setFont(font);
        SettingButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        SettingButton->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(SettingButton);

        ExitButton = new QPushButton(widget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setMinimumSize(QSize(270, 40));
        ExitButton->setMaximumSize(QSize(270, 40));
        ExitButton->setFont(font);
        ExitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout->addWidget(ExitButton);


        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QWidget *StartMenu)
    {
        StartMenu->setWindowTitle(QCoreApplication::translate("StartMenu", "Form", nullptr));
        Bg_img->setText(QString());
        ChooserBg->setText(QString());
        StartBotton->setText(QCoreApplication::translate("StartMenu", "Start", nullptr));
        SettingButton->setText(QCoreApplication::translate("StartMenu", "Settings", nullptr));
        ExitButton->setText(QCoreApplication::translate("StartMenu", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
