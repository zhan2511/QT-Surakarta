#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(820,570);
    this->setWindowIcon(QPixmap(":/rsc/Icon.jpg"));
    this->setWindowTitle("Surakarta");

    ui->stackedWidget->setCurrentIndex(0);//设置首页
    connect(ui->Start,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });//Start-切页1
    connect(ui->Back,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });//Back-切页0
    connect(ui->loadgame,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });//LOADGAME-切页2

    //跳转到棋盘
    chessboard = new chess_window;
    connect(ui->newgame,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(500,this,[=](){
            this->hide();
            chessboard->show();
        });
    });


    //插入首页背景
    QPixmap pix;
    bool ret01= pix.load(":/rsc/Background.png");
    if(!ret01){qDebug()<<"pix wrong";}
    ui->startpage0->GetPaintInfo_pix(pix);
    ui->startpage0->GetPaintInfo_scale(pix.width()*1.1,pix.height());
    ui->startpage0->GetPaintInfo_size(800,550);
    ui->startpage0->GetPaintInfo_pos(0,-10);
    ui->startpage0->update();

    // QPixmap pix_Title;
    // bool ret02= pix_Title.load(":/rsc/Surakarta.png");
    // if(!ret02){qDebug()<<"pix wrong";}
    // ui->startpage0->GetPaintInfo_pix(pix_Title);
    // ui->startpage0->GetPaintInfo_scale(pix_Title.width(),pix_Title.height());
    // ui->startpage0->GetPaintInfo_size(500,100);
    // ui->startpage0->GetPaintInfo_pos(200,0);
    // ui->startpage0->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}

