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
    ui->Listen->setFixedSize(ui->Listen->size());
    ui->Listen->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Listen.png");
    pix = pix.scaled(ui->Listen->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Listen->setIcon(pix);
    ui->Listen->setIconSize(ui->Listen->size());
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
    ui->ToPlayer1->setFixedSize(ui->ToPlayer1->size());
    ui->ToPlayer1->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ToPlayer1.png");
    pix = pix.scaled(ui->ToPlayer1->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ToPlayer1->setIcon(pix);
    ui->ToPlayer1->setIconSize(ui->ToPlayer1->size());
    connect(ui->ToPlayer1,&QPushButton::clicked,this,[=](){
            Server->send(Server->clients[0],NetworkData(OPCODE::CHAT_OP,"Server",ui->SendText->toPlainText(),""));
            ui->SendText->clear();
    });

    //ToPlayer2 按键
    ui->ToPlayer2->setEnabled(false);
    ui->ToPlayer2->setFixedSize(ui->ToPlayer2->size());
    ui->ToPlayer2->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ToPlayer2.png");
    pix = pix.scaled(ui->ToPlayer2->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ToPlayer2->setIcon(pix);
    ui->ToPlayer2->setIconSize(ui->ToPlayer2->size());
    connect(ui->ToPlayer2,&QPushButton::clicked,this,[=](){
            Server->send(Server->clients[1],NetworkData(OPCODE::CHAT_OP,"Server",ui->SendText->toPlainText(),""));
            ui->SendText->clear();
    });

    //ToAll 按键
    ui->ToAll->setEnabled(false);
    ui->ToAll->setFixedSize(ui->ToAll->size());
    ui->ToAll->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ToAll.png");
    pix = pix.scaled(ui->ToAll->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ToAll->setIcon(pix);
    ui->ToAll->setIconSize(ui->ToAll->size());
    connect(ui->ToAll,&QPushButton::clicked,this,[=](){
            Server->send(Server->clients[0],NetworkData(OPCODE::CHAT_OP,"Server",ui->SendText->toPlainText(),""));
            Server->send(Server->clients[1],NetworkData(OPCODE::CHAT_OP,"Server",ui->SendText->toPlainText(),""));
            ui->SendText->clear();
    });

    //ESC 按键
    ui->ESC->setFixedSize(ui->ESC->size());
    ui->ESC->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ESC.png");
    pix = pix.scaled(ui->ESC->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ESC->setIcon(pix);
    ui->ESC->setIconSize(ui->ESC->size());
    connect(ui->ESC,&QPushButton::clicked,this,[=](){
        while (!Server->clients.isEmpty()) {
            Server->clients[0]->disconnectFromHost();
            Server->clients.erase(Server->clients.begin());
        }
        gamethread->quit();
        gamethread->wait(25);
        gamethread->terminate();
        this->close();
    });

    //
    ft.setPointSize(16);

    //
    ui->HostIpText->setFont(ft);
    ui->MessageText->setFont(ft);
    ui->SendText->setFont(ft);

    //
    connect(Server,SIGNAL(receive(QTcpSocket*, NetworkData)),this,SLOT(onreceive(QTcpSocket*, NetworkData)));

    //
    connect(Server,&QTcpServer::newConnection,this,[=](){
        ui->MessageText->append("Server : Someone is connected!") ;
    });

}

MyServerWindow::~MyServerWindow()
{
    delete ui;
}


void MyServerWindow::onreceive(QTcpSocket* client1, NetworkData data)
{
    if(Server->clients.size()<2){
        return;
    }
    QTcpSocket*client2;
    if(client1== Server->clients[0]){
        client2 = Server->clients[1];
    }else{
        client2 = Server->clients[0];
    }
    if(data.op==OPCODE::CHAT_OP){
        ui->MessageText->append(data.data1+" : "+data.data2);
        Server->send(client2,NetworkData(OPCODE::CHAT_OP,data.data1,data.data2,""));
    }else if(data.op==OPCODE::READY_OP){
        ui->MessageText->append(data.data1+" : "+data.data1+" is Ready!");
        Server->send(client2,NetworkData(OPCODE::CHAT_OP,data.data1,QString(data.data1+" is Ready!"),""));
        if(client1 == Server->clients[0]){
            isReadyP1 = 1;
            P1Name = data.data1;
        }else if(client1 == Server->clients[1]){
            isReadyP2 = 1;
            P2Name = data.data1;
        }
        if(isReadyP1&&isReadyP2){
            Gamestart();
        }
    }else if(data.op==OPCODE::MOVE_OP){
        if(client1 == Server->clients[0]){
            move = SurakartaMove(data.data1[0].unicode()-'A',data.data1[1].unicode()-'1',
                                 data.data2[0].unicode()-'A',data.data2[1].unicode()-'1',P1Color);
            qDebug()<<"Move "<<data.data1[1].unicode()-'1'
                     <<data.data1[0].unicode()-'A'
                     <<data.data2[1].unicode()-'1'
                     <<data.data2[0].unicode()-'A';
            Move(move);
            QTimer::singleShot(500,this,[=](){
                Server->send(Server->clients[1],data);
            });
        }else if(client1 == Server->clients[1]){
            move = SurakartaMove(data.data1[0].unicode()-'A',data.data1[1].unicode()-'1',
                                 data.data2[0].unicode()-'A',data.data2[1].unicode()-'1',P2Color);
            qDebug()<<"Move "<<data.data1[1].unicode()-'1'
                     <<data.data1[0].unicode()-'A'
                     <<data.data2[1].unicode()-'1'
                     <<data.data2[0].unicode()-'A';
            Move(move);
            QTimer::singleShot(500,this,[=](){
                Server->send(Server->clients[0],data);
            });
        }
    }else if(data.op==OPCODE::RESIGN_OP){
        SurakartaGame game;
        if(client1 == Server->clients[0]){
            game.game_info_->end_reason_ = SurakartaEndReason::NONE;
            game.game_info_->winner_ = P2Color;
        }else if(client1 == Server->clients[1]){
            game.game_info_->end_reason_ = SurakartaEndReason::NONE;
            game.game_info_->winner_ = P1Color;
        }
        Gameover(game);
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
        qDebug()<<"BlackTurn,Turn=0";
    });
    connect(gamethread,&MyGameThread::WhiteTurn,this,[=](){
        Turn = 1;
        qDebug()<<"BlackTurn,Turn=1";
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
    while (!Server->clients.isEmpty()) {
        Server->clients[0]->disconnectFromHost();
        Server->clients.erase(Server->clients.begin());
    }
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

