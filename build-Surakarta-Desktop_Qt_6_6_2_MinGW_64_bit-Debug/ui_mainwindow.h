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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *startpage0;
    QLabel *label;
    QPushButton *Start;
    QWidget *modepage1;
    QPushButton *Back;
    QGroupBox *modeBox;
    QVBoxLayout *verticalLayout;
    QPushButton *newgame;
    QPushButton *spectator;
    QPushButton *loadgame;

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
        startpage0 = new QWidget();
        startpage0->setObjectName("startpage0");
        label = new QLabel(startpage0);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 801, 551));
        label->setFrameShape(QFrame::Box);
        label->setPixmap(QPixmap(QString::fromUtf8("rsc/Background_Picture.png")));
        label->setScaledContents(true);
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
        verticalLayout = new QVBoxLayout(modeBox);
        verticalLayout->setObjectName("verticalLayout");
        newgame = new QPushButton(modeBox);
        newgame->setObjectName("newgame");

        verticalLayout->addWidget(newgame);

        spectator = new QPushButton(modeBox);
        spectator->setObjectName("spectator");

        verticalLayout->addWidget(spectator);

        loadgame = new QPushButton(modeBox);
        loadgame->setObjectName("loadgame");

        verticalLayout->addWidget(loadgame);

        stackedWidget->addWidget(modepage1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
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
