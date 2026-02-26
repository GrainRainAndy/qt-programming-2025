/********************************************************************************
** Form generated from reading UI file 'ChooseMap.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEMAP_H
#define UI_CHOOSEMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *Title;
    QLabel *Bg;
    QLabel *ChooserBg;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QStackedWidget *Stacked_Roof;
    QWidget *page_17;
    QPushButton *ChooseButton_Roof;
    QLabel *Img_Roof;
    QLabel *Roof_Chosen;
    QWidget *page_18;
    QPushButton *BackButton_3;
    QStackedWidget *Stacked_MushroomGarden;
    QWidget *page_19;
    QPushButton *ChooseButton_MushroomGarden;
    QLabel *Img_MarshroomGarden;
    QLabel *MushroomGarden_Chosen;
    QWidget *page_20;
    QPushButton *NextBotton_3;
    QStackedWidget *Stacked_Aquarium;
    QWidget *page_21;
    QPushButton *ChooseButton_Aquarium;
    QLabel *Img_Aquarium;
    QLabel *Aquarium_Chosen;
    QWidget *page_22;
    QStackedWidget *Stacked_MoreMaps;
    QWidget *page_23;
    QPushButton *ChooseButton_MoreMaps;
    QWidget *page_24;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(800, 600);
        Title = new QLabel(Form);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(200, 130, 351, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Papyrus")});
        font.setPointSize(20);
        font.setBold(true);
        Title->setFont(font);
        Title->setAlignment(Qt::AlignCenter);
        Bg = new QLabel(Form);
        Bg->setObjectName("Bg");
        Bg->setGeometry(QRect(0, 0, 800, 600));
        Bg->setPixmap(QPixmap(QString::fromUtf8(":/Items/titlescreen_new.jpg")));
        ChooserBg = new QLabel(Form);
        ChooserBg->setObjectName("ChooserBg");
        ChooserBg->setGeometry(QRect(194, 175, 360, 325));
        ChooserBg->setPixmap(QPixmap(QString::fromUtf8(":/Items/SeedChooser_Background.png")));
        ChooserBg->setScaledContents(true);
        gridLayoutWidget = new QWidget(Form);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(200, 210, 351, 281));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        Stacked_Roof = new QStackedWidget(gridLayoutWidget);
        Stacked_Roof->setObjectName("Stacked_Roof");
        Stacked_Roof->setMinimumSize(QSize(100, 100));
        Stacked_Roof->setMaximumSize(QSize(100, 100));
        page_17 = new QWidget();
        page_17->setObjectName("page_17");
        ChooseButton_Roof = new QPushButton(page_17);
        ChooseButton_Roof->setObjectName("ChooseButton_Roof");
        ChooseButton_Roof->setGeometry(QRect(0, 0, 100, 100));
        ChooseButton_Roof->setMinimumSize(QSize(100, 100));
        ChooseButton_Roof->setMaximumSize(QSize(100, 100));
        ChooseButton_Roof->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/ShovelBank.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Img_Roof = new QLabel(page_17);
        Img_Roof->setObjectName("Img_Roof");
        Img_Roof->setGeometry(QRect(10, 10, 80, 80));
        Img_Roof->setMinimumSize(QSize(80, 80));
        Img_Roof->setMaximumSize(QSize(81, 81));
        Img_Roof->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Battlefield/roof.jpg")));
        Img_Roof->setScaledContents(true);
        Img_Roof->setAlignment(Qt::AlignCenter);
        Img_Roof->setTextInteractionFlags(Qt::NoTextInteraction);
        Roof_Chosen = new QLabel(page_17);
        Roof_Chosen->setObjectName("Roof_Chosen");
        Roof_Chosen->setGeometry(QRect(0, 0, 100, 100));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Papyrus")});
        font1.setPointSize(14);
        Roof_Chosen->setFont(font1);
        Roof_Chosen->setAutoFillBackground(false);
        Roof_Chosen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Roof_Chosen->setTextFormat(Qt::PlainText);
        Roof_Chosen->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/SeedChooser_Button_Glow.png")));
        Roof_Chosen->setScaledContents(true);
        Roof_Chosen->setAlignment(Qt::AlignCenter);
        Roof_Chosen->setWordWrap(false);
        Roof_Chosen->setTextInteractionFlags(Qt::NoTextInteraction);
        Stacked_Roof->addWidget(page_17);
        page_18 = new QWidget();
        page_18->setObjectName("page_18");
        Stacked_Roof->addWidget(page_18);

        gridLayout_3->addWidget(Stacked_Roof, 2, 1, 1, 1);

        BackButton_3 = new QPushButton(gridLayoutWidget);
        BackButton_3->setObjectName("BackButton_3");
        BackButton_3->setMinimumSize(QSize(100, 40));
        BackButton_3->setMaximumSize(QSize(100, 40));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Papyrus")});
        font2.setPointSize(18);
        font2.setBold(true);
        BackButton_3->setFont(font2);
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

        gridLayout_3->addWidget(BackButton_3, 4, 0, 1, 1);

        Stacked_MushroomGarden = new QStackedWidget(gridLayoutWidget);
        Stacked_MushroomGarden->setObjectName("Stacked_MushroomGarden");
        Stacked_MushroomGarden->setMinimumSize(QSize(100, 100));
        Stacked_MushroomGarden->setMaximumSize(QSize(100, 100));
        page_19 = new QWidget();
        page_19->setObjectName("page_19");
        ChooseButton_MushroomGarden = new QPushButton(page_19);
        ChooseButton_MushroomGarden->setObjectName("ChooseButton_MushroomGarden");
        ChooseButton_MushroomGarden->setGeometry(QRect(0, 0, 100, 100));
        ChooseButton_MushroomGarden->setMinimumSize(QSize(100, 100));
        ChooseButton_MushroomGarden->setMaximumSize(QSize(100, 100));
        ChooseButton_MushroomGarden->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/ShovelBank.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Img_MarshroomGarden = new QLabel(page_19);
        Img_MarshroomGarden->setObjectName("Img_MarshroomGarden");
        Img_MarshroomGarden->setGeometry(QRect(10, 10, 80, 80));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Img_MarshroomGarden->sizePolicy().hasHeightForWidth());
        Img_MarshroomGarden->setSizePolicy(sizePolicy);
        Img_MarshroomGarden->setMinimumSize(QSize(80, 80));
        Img_MarshroomGarden->setMaximumSize(QSize(80, 80));
        Img_MarshroomGarden->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Battlefield/MushroomGarden.jpg")));
        Img_MarshroomGarden->setScaledContents(true);
        Img_MarshroomGarden->setAlignment(Qt::AlignCenter);
        Img_MarshroomGarden->setTextInteractionFlags(Qt::NoTextInteraction);
        MushroomGarden_Chosen = new QLabel(page_19);
        MushroomGarden_Chosen->setObjectName("MushroomGarden_Chosen");
        MushroomGarden_Chosen->setGeometry(QRect(0, 0, 100, 100));
        MushroomGarden_Chosen->setFont(font1);
        MushroomGarden_Chosen->setAutoFillBackground(false);
        MushroomGarden_Chosen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        MushroomGarden_Chosen->setTextFormat(Qt::PlainText);
        MushroomGarden_Chosen->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/SeedChooser_Button_Glow.png")));
        MushroomGarden_Chosen->setScaledContents(true);
        MushroomGarden_Chosen->setAlignment(Qt::AlignCenter);
        MushroomGarden_Chosen->setWordWrap(false);
        MushroomGarden_Chosen->setTextInteractionFlags(Qt::NoTextInteraction);
        Stacked_MushroomGarden->addWidget(page_19);
        page_20 = new QWidget();
        page_20->setObjectName("page_20");
        Stacked_MushroomGarden->addWidget(page_20);

        gridLayout_3->addWidget(Stacked_MushroomGarden, 2, 0, 1, 1);

        NextBotton_3 = new QPushButton(gridLayoutWidget);
        NextBotton_3->setObjectName("NextBotton_3");
        NextBotton_3->setMinimumSize(QSize(100, 40));
        NextBotton_3->setMaximumSize(QSize(100, 40));
        NextBotton_3->setFont(font2);
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

        gridLayout_3->addWidget(NextBotton_3, 4, 1, 1, 1);

        Stacked_Aquarium = new QStackedWidget(gridLayoutWidget);
        Stacked_Aquarium->setObjectName("Stacked_Aquarium");
        Stacked_Aquarium->setMinimumSize(QSize(100, 100));
        Stacked_Aquarium->setMaximumSize(QSize(100, 100));
        page_21 = new QWidget();
        page_21->setObjectName("page_21");
        ChooseButton_Aquarium = new QPushButton(page_21);
        ChooseButton_Aquarium->setObjectName("ChooseButton_Aquarium");
        ChooseButton_Aquarium->setGeometry(QRect(0, 0, 100, 100));
        ChooseButton_Aquarium->setMinimumSize(QSize(100, 100));
        ChooseButton_Aquarium->setMaximumSize(QSize(100, 100));
        ChooseButton_Aquarium->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/ShovelBank.png) 0 0 0 0 stretch stretch;\n"
"}"));
        Img_Aquarium = new QLabel(page_21);
        Img_Aquarium->setObjectName("Img_Aquarium");
        Img_Aquarium->setGeometry(QRect(10, 10, 80, 80));
        Img_Aquarium->setMinimumSize(QSize(80, 80));
        Img_Aquarium->setMaximumSize(QSize(146, 146));
        Img_Aquarium->setPixmap(QPixmap(QString::fromUtf8(":/Items/Maps/Battlefield/aquarium.jpg")));
        Img_Aquarium->setScaledContents(true);
        Img_Aquarium->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        Img_Aquarium->setTextInteractionFlags(Qt::NoTextInteraction);
        Aquarium_Chosen = new QLabel(page_21);
        Aquarium_Chosen->setObjectName("Aquarium_Chosen");
        Aquarium_Chosen->setGeometry(QRect(0, 0, 100, 100));
        Aquarium_Chosen->setMinimumSize(QSize(0, 0));
        Aquarium_Chosen->setFont(font1);
        Aquarium_Chosen->setAutoFillBackground(false);
        Aquarium_Chosen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Aquarium_Chosen->setTextFormat(Qt::PlainText);
        Aquarium_Chosen->setPixmap(QPixmap(QString::fromUtf8(":/Items/ui/SeedChooser_Button_Glow.png")));
        Aquarium_Chosen->setScaledContents(true);
        Aquarium_Chosen->setAlignment(Qt::AlignCenter);
        Aquarium_Chosen->setWordWrap(false);
        Stacked_Aquarium->addWidget(page_21);
        page_22 = new QWidget();
        page_22->setObjectName("page_22");
        Stacked_Aquarium->addWidget(page_22);

        gridLayout_3->addWidget(Stacked_Aquarium, 3, 0, 1, 1);

        Stacked_MoreMaps = new QStackedWidget(gridLayoutWidget);
        Stacked_MoreMaps->setObjectName("Stacked_MoreMaps");
        Stacked_MoreMaps->setMinimumSize(QSize(100, 100));
        Stacked_MoreMaps->setMaximumSize(QSize(100, 100));
        page_23 = new QWidget();
        page_23->setObjectName("page_23");
        ChooseButton_MoreMaps = new QPushButton(page_23);
        ChooseButton_MoreMaps->setObjectName("ChooseButton_MoreMaps");
        ChooseButton_MoreMaps->setGeometry(QRect(0, 0, 100, 100));
        ChooseButton_MoreMaps->setMinimumSize(QSize(100, 100));
        ChooseButton_MoreMaps->setMaximumSize(QSize(100, 100));
        ChooseButton_MoreMaps->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-image: url(:/Items/ui/ShovelBank.png) 0 0 0 0 stretch stretch;\n"
"}"));
        ChooseButton_MoreMaps->setFlat(false);
        Stacked_MoreMaps->addWidget(page_23);
        page_24 = new QWidget();
        page_24->setObjectName("page_24");
        Stacked_MoreMaps->addWidget(page_24);

        gridLayout_3->addWidget(Stacked_MoreMaps, 3, 1, 1, 1);

        Bg->raise();
        ChooserBg->raise();
        Title->raise();
        gridLayoutWidget->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        Title->setText(QCoreApplication::translate("Form", "Choose Map", nullptr));
        Bg->setText(QString());
        ChooserBg->setText(QString());
        ChooseButton_Roof->setText(QString());
        Img_Roof->setText(QString());
        Roof_Chosen->setText(QString());
        BackButton_3->setText(QCoreApplication::translate("Form", "Back", nullptr));
        ChooseButton_MushroomGarden->setText(QString());
        Img_MarshroomGarden->setText(QString());
        MushroomGarden_Chosen->setText(QString());
        NextBotton_3->setText(QCoreApplication::translate("Form", "Next", nullptr));
        ChooseButton_Aquarium->setText(QString());
        Img_Aquarium->setText(QString());
        Aquarium_Chosen->setText(QString());
        ChooseButton_MoreMaps->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEMAP_H
