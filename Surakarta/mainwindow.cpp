#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(820,570);

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


void MainWindow::paintEvent(QPaintEvent *event)// 画个首页背景
{
    QPainter painter(this);
    QPixmap bground;
    bground.load(":/rsc/Background_Picture.png");
    bground=bground.scaled(bground.width()*0.8,bground.height()*0.7);//缩放
    painter.drawPixmap(0,0,this->width(),this->height()*0.9,bground);
}
