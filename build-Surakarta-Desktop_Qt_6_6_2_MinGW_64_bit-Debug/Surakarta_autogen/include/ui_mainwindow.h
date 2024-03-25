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
    QWidget *startpage1;
    QLabel *label;
    QPushButton *Start;
    QWidget *modepage2;
    QPushButton *Back;
    QGroupBox *Mode;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(820, 570);
        MainWindow->setMinimumSize(QSize(820, 570));
        MainWindow->setMaximumSize(QSize(820, 570));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 800, 550));
        stackedWidget->setMinimumSize(QSize(800, 550));
        stackedWidget->setMaximumSize(QSize(800, 550));
        startpage1 = new QWidget();
        startpage1->setObjectName("startpage1");
        label = new QLabel(startpage1);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 361, 511));
        Start = new QPushButton(startpage1);
        Start->setObjectName("Start");
        Start->setGeometry(QRect(470, 240, 251, 151));
        stackedWidget->addWidget(startpage1);
        modepage2 = new QWidget();
        modepage2->setObjectName("modepage2");
        Back = new QPushButton(modepage2);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(20, 20, 111, 51));
        Mode = new QGroupBox(modepage2);
        Mode->setObjectName("Mode");
        Mode->setGeometry(QRect(200, 130, 411, 361));
        verticalLayout = new QVBoxLayout(Mode);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(Mode);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Mode);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Mode);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        stackedWidget->addWidget(modepage2);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Mode->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
