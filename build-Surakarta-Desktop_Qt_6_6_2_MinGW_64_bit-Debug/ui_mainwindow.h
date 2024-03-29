/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mywidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    MyWidget *startpage0;
    QPushButton *Start;
    QWidget *modepage1;
    QPushButton *Back;
    QGroupBox *modeBox;
    QVBoxLayout *vboxLayout;
    QPushButton *newgame;
    QPushButton *spectator;
    QPushButton *loadgame;
    QWidget *page3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(840, 590);
        MainWindow->setMinimumSize(QSize(9, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(820, 570));
        centralwidget->setMaximumSize(QSize(820, 570));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 800, 550));
        stackedWidget->setMinimumSize(QSize(800, 550));
        stackedWidget->setMaximumSize(QSize(800, 550));
        startpage0 = new MyWidget();
        startpage0->setObjectName("startpage0");
        Start = new QPushButton(startpage0);
        Start->setObjectName("Start");
        Start->setGeometry(QRect(450, 270, 301, 201));
        stackedWidget->addWidget(startpage0);
        modepage1 = new QWidget();
        modepage1->setObjectName("modepage1");
        Back = new QPushButton(modepage1);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(20, 20, 101, 51));
        modeBox = new QGroupBox(modepage1);
        modeBox->setObjectName("modeBox");
        modeBox->setGeometry(QRect(200, 170, 461, 351));
        vboxLayout = new QVBoxLayout(modeBox);
        vboxLayout->setSpacing(0);
        vboxLayout->setObjectName("vboxLayout");
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        newgame = new QPushButton(modeBox);
        newgame->setObjectName("newgame");

        vboxLayout->addWidget(newgame);

        spectator = new QPushButton(modeBox);
        spectator->setObjectName("spectator");

        vboxLayout->addWidget(spectator);

        loadgame = new QPushButton(modeBox);
        loadgame->setObjectName("loadgame");

        vboxLayout->addWidget(loadgame);

        stackedWidget->addWidget(modepage1);
        page3 = new QWidget();
        page3->setObjectName("page3");
        stackedWidget->addWidget(page3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        modeBox->setTitle(QString());
        newgame->setText(QCoreApplication::translate("MainWindow", "NEW GAME", nullptr));
        spectator->setText(QCoreApplication::translate("MainWindow", "SPECTATOR", nullptr));
        loadgame->setText(QCoreApplication::translate("MainWindow", "LOAD GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
