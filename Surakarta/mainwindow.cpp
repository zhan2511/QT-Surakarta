#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <mypushbutton.h>
#include "mysettingsdialog.h"
#include "ui_mysettingsdialog.h"
#include "mynetdialog.h"
#include "ui_mynetdialog.h"
#include <QDialog>



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
    // connect(ui->loadgame,&QPushButton::clicked,this,[=](){
    //     ui->stackedWidget->setCurrentIndex(2);
    // });//LOADGAME-切页2





    //Gammers 设置图标和弹跳效果 跳转到棋盘
    ui->Gamers->height=80;
    ui->Gamers->width=250;
    ui->Gamers->pixheight=80;
    ui->Gamers->pixwidth=250;
    ui->Gamers->SetCustomisedIcon(":/rsc/Gamers.png");
    ui->Gamers->setFixedSize(ui->Gamers->width,ui->Gamers->height);
    connect(ui->Gamers,&QPushButton::clicked,this,[=](){
        ui->Gamers->BounceDown();
        QTimer::singleShot(100,this,[=](){
            ui->Gamers->BounceUp();
        });
        QTimer::singleShot(100,this,[=](){
            this->hide();
            chessboard = new chess_window(0,roundtime,gamehour,gamemin,this);
            connect(chessboard,&chess_window::mainshow,this,[=](){
                this->show();
                ui->stackedWidget->setCurrentIndex(1);
            });
            chessboard->setAttribute(Qt::WA_DeleteOnClose);
            // chessboard->roundtimelimit=roundtime;
            // chessboard->gamehour=gamehour;
            // chessboard->gamemin=gamemin;
            chessboard->show();
        });
    });


    //AIVSGammer 设置图标和弹跳效果 跳转到棋盘
    ui->AIVSGamer->height=80;
    ui->AIVSGamer->width=250;
    ui->AIVSGamer->pixheight=80;
    ui->AIVSGamer->pixwidth=250;
    ui->AIVSGamer->SetCustomisedIcon(":/rsc/AIVSGamer.png");
    ui->AIVSGamer->setFixedSize(ui->AIVSGamer->width,ui->AIVSGamer->height);
    connect(ui->AIVSGamer,&QPushButton::clicked,this,[=](){
        ui->AIVSGamer->BounceDown();
        QTimer::singleShot(100,this,[=](){
            ui->AIVSGamer->BounceUp();
        });
        QTimer::singleShot(100,this,[=](){
            this->hide();
            chessboard = new chess_window(1,roundtime,gamehour,gamemin,this);
            connect(chessboard,&chess_window::mainshow,this,[=](){
                this->show();
                ui->stackedWidget->setCurrentIndex(1);
            });
            chessboard->setAttribute(Qt::WA_DeleteOnClose);
            // chessboard->roundtimelimit=roundtime;
            // chessboard->gamehour=gamehour;
            // chessboard->gamemin=gamemin;
            chessboard->show();
        });
    });


    //AIVSAI 设置图标和弹跳效果
    ui->AIVSAI->height=80;
    ui->AIVSAI->width=250;
    ui->AIVSAI->pixheight=80;
    ui->AIVSAI->pixwidth=250;
    ui->AIVSAI->SetCustomisedIcon(":/rsc/AIVSAI.png");
    ui->AIVSAI->setFixedSize(ui->AIVSAI->width,ui->AIVSAI->height);
    connect(ui->AIVSAI,&QPushButton::clicked,this,[=](){
        ui->AIVSAI->BounceDown();
        QTimer::singleShot(100,this,[=](){
            ui->AIVSAI->BounceUp();
        });
        QTimer::singleShot(100,this,[=](){
            this->hide();
            chessboard = new chess_window(2,roundtime,gamehour,gamemin,this);
            connect(chessboard,&chess_window::mainshow,this,[=](){
                this->show();
                ui->stackedWidget->setCurrentIndex(1);
            });
            chessboard->setAttribute(Qt::WA_DeleteOnClose);
            // chessboard->roundtimelimit=roundtime;
            // chessboard->gamehour=gamehour;
            // chessboard->gamemin=gamemin;
            chessboard->show();
        });
    });


    //OnlineGame 设置图标和弹跳效果
    ui->OnlineGame->height=80;
    ui->OnlineGame->width=250;
    ui->OnlineGame->pixheight=80;
    ui->OnlineGame->pixwidth=250;
    ui->OnlineGame->SetCustomisedIcon(":/rsc/OnlineGame.png");
    ui->OnlineGame->setFixedSize(ui->OnlineGame->width,ui->OnlineGame->height);
    connect(ui->OnlineGame,&QPushButton::clicked,this,[=](){
        ui->OnlineGame->BounceDown();
        QTimer::singleShot(100,this,[=](){
            ui->OnlineGame->BounceUp();
        });
        QTimer::singleShot(100,this,[=](){
            MyNetDialog *NetDialog = new MyNetDialog(this);
            this->hide();
            connect(NetDialog,&MyNetDialog::mainshow,this,[=](){
                this->show();
                ui->stackedWidget->setCurrentIndex(1);
            });
            NetDialog->show();
        });
    });

    //Setting界面

    //Settings按键
    ui->Settings->height=70;
    ui->Settings->width=70;
    ui->Settings->pixheight=70;
    ui->Settings->pixwidth=70;
    ui->Settings->SetCustomisedIcon(":/rsc/Settings.png");
    ui->Settings->setFixedSize(ui->Settings->width,ui->Settings->height);
    connect(ui->Settings,&QPushButton::clicked,this,[=](){
        ui->Settings->BounceDown();
        QTimer::singleShot(100,this,[=](){
            ui->Settings->BounceUp();
        });
        QTimer::singleShot(100,this,[=](){
            MySettingsDialog *SettingsDialog=new MySettingsDialog(this);
            // Ui_MySettingsDialog *SettingsUi;
            // SettingsUi=SettingsDialog->ui;
            connect(SettingsDialog->ui->RoundTimeSpin,SIGNAL(valueChanged(int)),this,SLOT(SetRoundTime(int)));
            connect(SettingsDialog->ui->GameTimeH,SIGNAL(valueChanged(int)),this,SLOT(SetGameHour(int)));
            connect(SettingsDialog->ui->GameTimeMin,SIGNAL(valueChanged(int)),this,SLOT(SetGameMin(int)));
            // roundtime=SettingsDialog->ui->RoundTimeSpin->value();
            // roundtime=SettingsDialog->ui->GameTimeH->value();
            // roundtime=SettingsDialog->ui->GameTimeMin->value();
            SettingsDialog->ui->RoundTimeSpin->setValue(roundtime);
            SettingsDialog->ui->GameTimeH->setValue(gamehour);
            SettingsDialog->ui->GameTimeMin->setValue(gamemin);
            SettingsDialog->show();
        });
    });


    //startpage0 插入背景
    QPixmap pix;
    bool ret= pix.load(":/rsc/Background.png");
    if(!ret){qDebug()<<"pix wrong";}
    ui->startpage0->GetPaintInfo_pix(pix);
    ui->startpage0->GetPaintInfo_scale(pix.width()*0.8,pix.height()*1.7);
    ui->startpage0->GetPaintInfo_size(810,570);
    ui->startpage0->GetPaintInfo_pos(-10,-20);
    ui->startpage0->update();


    //Start 设置图标和弹跳效果
    ui->Start->move(500,200);
    ui->Start->height=250;
    ui->Start->width=250;
    ui->Start->pixheight=250;
    ui->Start->pixwidth=250;
    ui->Start->SetCustomisedIcon(":/rsc/Start.png");
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
    ui->Back->move(20,0);
    ui->Back->height=80;
    ui->Back->width=140;
    ui->Back->pixheight=80;
    ui->Back->pixwidth=140;
    ui->Back->SetCustomisedIcon(":/rsc/Back.png");
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

    //ESC
    ui->ESC->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ESC.png");
    pix = pix.scaled(ui->ESC->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ESC->setIcon(pix);
    ui->ESC->setIconSize(ui->ESC->size());
    connect(ui->ESC,&QPushButton::clicked,this,&QMainWindow::close);


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


void MainWindow::SetRoundTime(int sec){
    qDebug()<<"set RoundTime  "<<sec;
    roundtime=sec;
}
void MainWindow::SetGameHour(int h){
    qDebug()<<"set GameHour  "<<h;
    gamehour=h;
}
void MainWindow::SetGameMin(int min){
    qDebug()<<"set GameMin  "<<min;
    gamemin=min;
}

