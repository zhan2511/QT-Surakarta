#include "mynetwidget.h"
#include "ui_mynetwidget.h"
#include <QPushButton>


MyNetWidget::MyNetWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyNetWidget)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    QPixmap pix;

    //Back 按键
    ui->Back->setFixedSize(QSize(300,120));
    ui->Back->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Back.png");
    pix = pix.scaled(ui->Back->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Back->setIcon(pix);
    ui->Back->setIconSize(QSize(300,120));
    connect(ui->Back,&QPushButton::clicked,this,[=](){
        emit mainshow();
        this->close();
    });

    //Server 按键
    // ui->Server->move();
    ui->Server->setFixedSize(QSize(300,120));
    ui->Server->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Server.png");
    pix = pix.scaled(ui->Server->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Server->setIcon(pix);
    ui->Server->setIconSize(QSize(300,120));
    connect(ui->Server,&QPushButton::clicked,this,[=](){
        ServerWd = new MyServerWindow;
        ServerWd->setAttribute(Qt::WA_DeleteOnClose);
        ServerWd->show();
        qDebug()<<"Server clicked";
    });

    //Client 按键
    // ui->Client->move();
    ui->Client->setFixedSize(QSize(300,120));
    ui->Client->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Client.png");
    pix = pix.scaled(ui->Client->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Client->setIcon(pix);
    ui->Client->setIconSize(QSize(300,120));
    connect(ui->Client,&QPushButton::clicked,this,[=](){
        ClientWd = new MyClientWindow;
        ClientWd->setAttribute(Qt::WA_DeleteOnClose);
        ClientWd->show();
        qDebug()<<"Client clicked";
    });
}

MyNetWidget::~MyNetWidget()
{
    delete ui;
}
