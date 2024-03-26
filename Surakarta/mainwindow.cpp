#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);//设置首页

    connect(ui->Start,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });//Start-切页1

    connect(ui->Back,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });//Back-切页0

}

MainWindow::~MainWindow()
{
    delete ui;
}
