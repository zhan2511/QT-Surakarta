#include "myserverwindow.h"
#include "ui_myserverwindow.h"

MyServerWindow::MyServerWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyServerWindow)
{
    ui->setupUi(this);

    Server = new NetworkServer(this);

    setWindowTitle("Server");

    gamethread=new MyGameThread(this);

    QPixmap pix;

    //Listen 按键
    ui->Listen->setFixedSize(QSize(100,50));
    ui->Listen->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Listen.png");
    pix = pix.scaled(ui->Listen->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Listen->setIcon(pix);
    ui->Listen->setIconSize(QSize(100,50));
    connect(ui->Listen,&QPushButton::clicked,this,[=](){
        bool isListen = Server->listen(QHostAddress::LocalHost,9999);
        if(isListen == false ){
            ui->MessageText->append(ServerName + " : " + "Failed to listen.");
            qDebug()<<Server->errorString();
        }else{
            ui->MessageText->append(ServerName + " : " + "Server is listening...");
            qDebug()<<Server->serverAddress().toString();
            qDebug()<<QHostAddress(QHostAddress::LocalHost).toString();
            ui->HostIpText->setText(Server->serverAddress().toString());
            qDebug()<<"Listen";
        }
    });

    //ToPlayer1 按键
    ui->ToPlayer1->setEnabled(false);
    ui->ToPlayer1->setFixedSize(QSize(120,40));
    ui->ToPlayer1->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ToPlayer1.png");
    pix = pix.scaled(ui->ToPlayer1->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ToPlayer1->setIcon(pix);
    ui->ToPlayer1->setIconSize(QSize(120,40));
    connect(ui->ToPlayer1,&QPushButton::clicked,this,[=](){
            Server->send(Server->clients[0],NetworkData(OPCODE::CHAT_OP,"Server",ui->SendText->toPlainText(),""));
            ui->SendText->clear();
    });

    //ToPlayer2 按键
    ui->ToPlayer2->setEnabled(false);
    ui->ToPlayer2->setFixedSize(QSize(120,40));
    ui->ToPlayer2->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ToPlayer2.png");
    pix = pix.scaled(ui->ToPlayer2->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ToPlayer2->setIcon(pix);
    ui->ToPlayer2->setIconSize(QSize(120,40));
    connect(ui->ToPlayer2,&QPushButton::clicked,this,[=](){
            Server->send(Server->clients[1],NetworkData(OPCODE::CHAT_OP,"Server",ui->SendText->toPlainText(),""));
            ui->SendText->clear();
    });

    //ToAll 按键
    ui->ToAll->setEnabled(false);
    ui->ToAll->setFixedSize(QSize(120,40));
    ui->ToAll->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ToAll.png");
    pix = pix.scaled(ui->ToAll->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ToAll->setIcon(pix);
    ui->ToAll->setIconSize(QSize(120,50));
    connect(ui->ToAll,&QPushButton::clicked,this,[=](){
            Server->send(Server->clients[0],NetworkData(OPCODE::CHAT_OP,"Server",ui->SendText->toPlainText(),""));
            Server->send(Server->clients[1],NetworkData(OPCODE::CHAT_OP,"Server",ui->SendText->toPlainText(),""));
            ui->SendText->clear();
    });

    //
    ft.setPointSize(16);

    //
    ui->HostIpText->setFont(ft);
    ui->MessageText->setFont(ft);
    ui->SendText->setFont(ft);

    //
    connect(Server,SIGNAL(receive(QTcpSocket*, NetworkData)),this,SLOT(onreceive(QTcpSocket*, NetworkData)));


}

MyServerWindow::~MyServerWindow()
{
    delete ui;
}


void MyServerWindow::onreceive(QTcpSocket* client, NetworkData data)
{
    QTcpSocket* client1,*client2;
    if(client == Server->clients[0]){
        client1 = client;
        client2 = Server->clients[1];
    }else{
        client2 = client;
        client1 = Server->clients[0];
    }
    if(data.op==OPCODE::CHAT_OP){
        ui->MessageText->append(data.data1+" : "+data.data2);
        Server->send(client2,NetworkData(OPCODE::CHAT_OP,data.data1,data.data2,""));
    }else if(data.op==OPCODE::READY_OP){
        ui->MessageText->append(data.data1+" : "+data.data1+" is Ready!");
        Server->send(client2,NetworkData(OPCODE::CHAT_OP,data.data1,QString(data.data1+" is Ready!"),""));
        if(client == Server->clients[0]){
            isReadyP1 = 1;
            P1Name = data.data1;
        }else if(client == Server->clients[1]){
            isReadyP2 = 1;
            P2Name = data.data1;
        }
        if(isReadyP1&&isReadyP2){
            Gamestart();
        }
    }else if(data.op==OPCODE::MOVE_OP){
        if(client == Server->clients[0]){
            move = SurakartaMove(data.data1[0].unicode()-'A',data.data1[1].unicode()-1,
                                 data.data2[0].unicode()-'A',data.data2[1].unicode()-1,P1Color);
            Move(move);
        }
    }

}

void MyServerWindow::Gamestart()
{
    bool judgecolor = rand()%2;
    gamethread->GamePre();
    gamethread->start();
    if(judgecolor){
        P1Color = SurakartaPlayer::BLACK;
        P2Color = SurakartaPlayer::WHITE;
        Server->send(Server->clients[0],NetworkData(OPCODE::READY_OP,P2Name,"BLACK",QString::number(1)));
        Server->send(Server->clients[1],NetworkData(OPCODE::READY_OP,P1Name,"WHITE",QString::number(1)));
    }else{
        P1Color = SurakartaPlayer::WHITE;
        P2Color = SurakartaPlayer::BLACK;
        Server->send(Server->clients[0],NetworkData(OPCODE::READY_OP,P2Name,"WHITE",QString::number(1)));
        Server->send(Server->clients[1],NetworkData(OPCODE::READY_OP,P1Name,"BLACK",QString::number(1)));
    }

    connect(gamethread,&MyGameThread::BlackTurn,this,[=](){
        Turn = 0;
    });
    connect(gamethread,&MyGameThread::WhiteTurn,this,[=](){
        Turn = 1;
    });
    connect(gamethread,SIGNAL(Finished(SurakartaGame)),this,SLOT(Gameover(SurakartaGame)));
}

void MyServerWindow::Gameover(SurakartaGame game)
{
    Server->send(Server->clients[0],NetworkData(OPCODE::END_OP,"",
                                                 QString::number(static_cast<int>(game.game_info_->end_reason_)),
                                                 QString::number(static_cast<int>(game.game_info_->Winner()))));
    Server->send(Server->clients[1],NetworkData(OPCODE::END_OP,"",
                                                 QString::number(static_cast<int>(game.game_info_->end_reason_)),
                                                 QString::number(static_cast<int>(game.game_info_->Winner()))));
}


void MyServerWindow::Move(SurakartaMove move)
{
    if(Turn == 0 && move.player == SurakartaPlayer::BLACK){
        gamethread->blackmove_(move);
        Turn = -1;
        condition.wakeAll();
    }else if(Turn == 1 && move.player == SurakartaPlayer::WHITE){
        gamethread->whitemove_(move);
        Turn = -1;
        condition.wakeAll();
    }
}

