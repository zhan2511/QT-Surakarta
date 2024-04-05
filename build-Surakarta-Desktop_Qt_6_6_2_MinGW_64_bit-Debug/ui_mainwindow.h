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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <mypushbutton.h>
#include <mywidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    MyWidget *startpage0;
    MyPushbutton *Start;
    QWidget *modepage1;
    MyPushbutton *Back;
    QGroupBox *modeBox;
    QGridLayout *gridLayout;
    MyPushbutton *AIVSGamer;
    MyPushbutton *AIVSAI;
    MyPushbutton *loadgame;
    QWidget *page3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(820, 570);
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
        Start = new MyPushbutton(startpage0);
        Start->setObjectName("Start");
        Start->setGeometry(QRect(500, 200, 261, 251));
        stackedWidget->addWidget(startpage0);
        modepage1 = new QWidget();
        modepage1->setObjectName("modepage1");
        Back = new MyPushbutton(modepage1);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(20, 20, 101, 51));
        modeBox = new QGroupBox(modepage1);
        modeBox->setObjectName("modeBox");
        modeBox->setGeometry(QRect(175, 140, 450, 350));
        modeBox->setMinimumSize(QSize(450, 350));
        modeBox->setMaximumSize(QSize(450, 350));
        modeBox->setStyleSheet(QString::fromUtf8("QGroupBox{Border:0px}"));
        gridLayout = new QGridLayout(modeBox);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        AIVSGamer = new MyPushbutton(modeBox);
        AIVSGamer->setObjectName("AIVSGamer");

        gridLayout->addWidget(AIVSGamer, 0, 0, 1, 1);

        AIVSAI = new MyPushbutton(modeBox);
        AIVSAI->setObjectName("AIVSAI");

        gridLayout->addWidget(AIVSAI, 1, 0, 1, 1);

        loadgame = new MyPushbutton(modeBox);
        loadgame->setObjectName("loadgame");

        gridLayout->addWidget(loadgame, 2, 0, 1, 1);

        stackedWidget->addWidget(modepage1);
        page3 = new QWidget();
        page3->setObjectName("page3");
        stackedWidget->addWidget(page3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        Back->setText(QString());
        modeBox->setTitle(QString());
        AIVSGamer->setText(QString());
        AIVSAI->setText(QString());
        loadgame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
