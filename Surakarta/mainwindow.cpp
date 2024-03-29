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


    //插入首页背景
    QPixmap pix;
    bool ret= pix.load(":/rsc/Background_Picture.png");
    if(!ret){qDebug()<<"pix wrong";}
    ui->startpage0->GetPaintInfo_pix(pix);
    ui->startpage0->GetPaintInfo_scale(pix.width()*1.1,pix.height());
    ui->startpage0->GetPaintInfo_size(800,550);
    ui->startpage0->GetPaintInfo_pos(0,-10);
    ui->startpage0->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}

