#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <mypushbutton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(820,570);
    this->setWindowIcon(QPixmap(":/rsc/Icon.jpg"));
    this->setWindowTitle("Surakarta_Home");

    ui->stackedWidget->setCurrentIndex(0);//设置首页
    // connect(ui->Start,&QPushButton::clicked,this,[=](){
    // });//Start-切页1
    // connect(ui->Back,&QPushButton::clicked,this,[=](){
    //     ui->stackedWidget->setCurrentIndex(0);
    // });//Back-切页0
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


    //startpage0 插入背景
    QPixmap pix;
    bool ret= pix.load(":/rsc/Background_Picture.png");
    if(!ret){qDebug()<<"pix wrong";}
    ui->startpage0->GetPaintInfo_pix(pix);
    ui->startpage0->GetPaintInfo_scale(pix.width()*1.5,pix.height());
    ui->startpage0->GetPaintInfo_size(800,550);
    ui->startpage0->GetPaintInfo_pos(-10,-20);
    ui->startpage0->update();

    //Start 设置图标和弹跳效果
    ui->Start->height=200;
    ui->Start->width=300;
    ui->Start->pixheight=190;
    ui->Start->pixwidth=290;
    ui->Start->SetCustomisedIcon("");
    ui->Start->setFixedSize(ui->Start->width,ui->Start->height);
    connect(ui->Start,&QPushButton::clicked,this,[=](){
        ui->Start->BounceDown();
        QTimer::singleShot(100,this,[=](){
            ui->Start->BounceUp();
        });
        QTimer::singleShot(100,this,[=](){
            ui->stackedWidget->setCurrentIndex(1);
        });
    });

    //Back 设置图标和弹跳效果
    ui->Back->move(20,20);
    ui->Back->height=50;
    ui->Back->width=100;
    ui->Back->pixheight=90;
    ui->Back->pixwidth=40;
    ui->Back->SetCustomisedIcon("");
    ui->Back->setFixedSize(ui->Back->width,ui->Back->height);
    connect(ui->Back,&QPushButton::clicked,this,[=](){
        ui->Back->BounceDown();
        QTimer::singleShot(100,this,[=](){
            ui->Back->BounceUp();
        });
        QTimer::singleShot(100,this,[=](){
            ui->stackedWidget->setCurrentIndex(0);
        });
    });

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

