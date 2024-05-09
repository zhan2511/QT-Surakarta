/********************************************************************************
** Form generated from reading UI file 'mysettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSETTINGSDIALOG_H
#define UI_MYSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySettingsDialog
{
public:
    QLabel *SettingsTitle;
    QGroupBox *RoundTimeBox;
    QSpinBox *RoundTimeSpin;
    QGroupBox *GameTimeBox;
    QSpinBox *GameTimeH;
    QSpinBox *GameTimeMin;
    QLabel *HLabel;
    QLabel *label_3;
    QPushButton *EscSettings;

    void setupUi(QWidget *MySettingsDialog)
    {
        if (MySettingsDialog->objectName().isEmpty())
            MySettingsDialog->setObjectName("MySettingsDialog");
        MySettingsDialog->resize(520, 380);
        MySettingsDialog->setMinimumSize(QSize(520, 380));
        MySettingsDialog->setMaximumSize(QSize(520, 380));
        SettingsTitle = new QLabel(MySettingsDialog);
        SettingsTitle->setObjectName("SettingsTitle");
        SettingsTitle->setGeometry(QRect(170, 0, 180, 60));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        SettingsTitle->setFont(font);
        RoundTimeBox = new QGroupBox(MySettingsDialog);
        RoundTimeBox->setObjectName("RoundTimeBox");
        RoundTimeBox->setGeometry(QRect(50, 60, 200, 30));
        QFont font1;
        font1.setPointSize(14);
        RoundTimeBox->setFont(font1);
        RoundTimeSpin = new QSpinBox(RoundTimeBox);
        RoundTimeSpin->setObjectName("RoundTimeSpin");
        RoundTimeSpin->setGeometry(QRect(120, 0, 80, 30));
        QFont font2;
        font2.setPointSize(11);
        RoundTimeSpin->setFont(font2);
        RoundTimeSpin->setMinimum(10);
        RoundTimeSpin->setMaximum(90);
        RoundTimeSpin->setSingleStep(5);
        RoundTimeSpin->setValue(30);
        GameTimeBox = new QGroupBox(MySettingsDialog);
        GameTimeBox->setObjectName("GameTimeBox");
        GameTimeBox->setGeometry(QRect(50, 110, 400, 30));
        GameTimeBox->setMinimumSize(QSize(90, 20));
        GameTimeBox->setFont(font1);
        GameTimeH = new QSpinBox(GameTimeBox);
        GameTimeH->setObjectName("GameTimeH");
        GameTimeH->setGeometry(QRect(120, 0, 80, 30));
        GameTimeH->setFont(font2);
        GameTimeH->setMaximum(3);
        GameTimeMin = new QSpinBox(GameTimeBox);
        GameTimeMin->setObjectName("GameTimeMin");
        GameTimeMin->setGeometry(QRect(230, 0, 80, 30));
        GameTimeMin->setFont(font2);
        GameTimeMin->setMinimum(0);
        GameTimeMin->setMaximum(59);
        GameTimeMin->setValue(40);
        HLabel = new QLabel(GameTimeBox);
        HLabel->setObjectName("HLabel");
        HLabel->setGeometry(QRect(205, 4, 21, 21));
        label_3 = new QLabel(GameTimeBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(316, 5, 54, 16));
        EscSettings = new QPushButton(MySettingsDialog);
        EscSettings->setObjectName("EscSettings");
        EscSettings->setGeometry(QRect(460, 20, 31, 31));

        retranslateUi(MySettingsDialog);

        QMetaObject::connectSlotsByName(MySettingsDialog);
    } // setupUi

    void retranslateUi(QWidget *MySettingsDialog)
    {
        MySettingsDialog->setWindowTitle(QCoreApplication::translate("MySettingsDialog", "Form", nullptr));
        SettingsTitle->setText(QCoreApplication::translate("MySettingsDialog", "        SETTINGS", nullptr));
        RoundTimeBox->setTitle(QCoreApplication::translate("MySettingsDialog", "RoundTime", nullptr));
        GameTimeBox->setTitle(QCoreApplication::translate("MySettingsDialog", "GameTime", nullptr));
        HLabel->setText(QCoreApplication::translate("MySettingsDialog", "h", nullptr));
        label_3->setText(QCoreApplication::translate("MySettingsDialog", "min", nullptr));
        EscSettings->setText(QCoreApplication::translate("MySettingsDialog", "ESC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MySettingsDialog: public Ui_MySettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSETTINGSDIALOG_H
