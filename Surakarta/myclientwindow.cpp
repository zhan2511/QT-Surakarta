#include "myclientwindow.h"
#include "ui_myclientwindow.h"
#include <QPainter>
#include <QGraphicsOpacityEffect>
#include "network/networkdata.h"
#include "surakarta/surakarta_agent/surakarta_agent_mine.h"
#include "surakarta/surakarta_agent/surakarta_agent_random.h"

MyClientWindow::MyClientWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyClientWindow)
{
    ui->setupUi(this);

    setWindowTitle("Client");

    QTcpSocket *Tcpsocket = new QTcpSocket(this);
    Socket = new NetworkSocket(Tcpsocket,this);


    this->setFixedSize(1200,800);
    this->setWindowIcon(QPixmap(":/rsc/Icon.jpg"));
    this->setWindowTitle("Surakarta Game");
    // this->Gamermove_.player=SurakartaPlayer::UNKNOWN;


    //Send 按键
    ui->Send->setEnabled(false);
    ui->Send->setFixedSize(ui->Send->size());
    ui->Send->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Send.png");
    pix = pix.scaled(ui->Send->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Send->setIcon(pix);
    ui->Send->setIconSize(ui->Send->size());
    connect(ui->Send,&QPushButton::clicked,this,[=](){
        Chat(ui->SendText->toPlainText());
        qDebug()<<"Send Message";
        ui->SendText->clear();
    });

    //ConnectToHost 按键
    ui->ConnectToHost->setFixedSize(ui->ConnectToHost->size());
    ui->ConnectToHost->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ConnectToHost.png");
    pix = pix.scaled(ui->ConnectToHost->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ConnectToHost->setIcon(pix);
    ui->ConnectToHost->setIconSize(ui->ConnectToHost->size());
    connect(ui->ConnectToHost,&QPushButton::clicked,this,[=](){
        ip = ui->HostIPText->toPlainText();
        port = ui->PortText->toPlainText();
        qDebug()<<QHostAddress(ip).toString();
        qDebug()<<ip;
        Socket->hello(QHostAddress(ip).toString(),port.toInt());
        qDebug()<<"ConnectToHost";
    });


    //Ready 按键
    ui->Ready->setEnabled(false);
    ui->Ready->setFixedSize(ui->Ready->size());
    ui->Ready->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Ready.png");
    pix = pix.scaled(ui->Ready->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Ready->setIcon(pix);
    ui->Ready->setIconSize(ui->Ready->size());
    connect(ui->Ready,&QPushButton::clicked,this,[=](){
        Socket->send(NetworkData(OPCODE::READY_OP,Name,"",QString::number(1)));
        qDebug()<<"Ready";
    });

    //ESC 按键
    ui->ESC->setFixedSize(ui->ESC->size());
    ui->ESC->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ESC.png");
    pix = pix.scaled(ui->ESC->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ESC->setIcon(pix);
    ui->ESC->setIconSize(ui->ESC->size());
    connect(ui->ESC,&QPushButton::clicked,this,[=](){
        Socket->send(NetworkData(OPCODE::LEAVE_OP,"","",""));
        Socket->bye();
        // emit NetDialogShow();
        this->close();
    });

    //Resign 按键
    ui->Resign->setFixedSize(ui->Resign->size());
    ui->Resign->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Resign.png");
    pix = pix.scaled(ui->Resign->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Resign->setIcon(pix);
    ui->Resign->setIconSize(ui->Resign->size());
    connect(ui->Resign,&QPushButton::clicked,this,[=](){
        Socket->send(NetworkData(OPCODE::RESIGN_OP,"","",""));
    });

    //Agent 按键  与  IsAgent label
    pix.load(":/rsc/Untick.png");
    pix = pix.scaled(ui->IsAgent->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->IsAgent->setPixmap(pix);
    ui->Agent->setFixedSize(ui->Agent->size());
    ui->Agent->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Agent.png");
    pix = pix.scaled(ui->Agent->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Agent->setIcon(pix);
    ui->Agent->setIconSize(ui->Agent->size());
    connect(ui->Agent,&QPushButton::clicked,this,[=](){
        isAgent = !isAgent;
        if(isAgent){
            pix.load(":/rsc/Tick.png");
            pix = pix.scaled(ui->IsAgent->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
            ui->IsAgent->setPixmap(pix);
        }else {
            pix.load(":/rsc/Untick.png");
            pix = pix.scaled(ui->IsAgent->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
            ui->IsAgent->setPixmap(pix);
        }
    });


    //设置字体大小
    ft.setPointSize(16);


    //
    ui->HostIPText->setFont(ft);
    ui->MessageText->setFont(ft);
    ui->NameText->setFont(ft);
    ui->CurrentplayerText->setFont(ft);
    ui->MeText->setFont(ft);
    ui->SendText->setFont(ft);
    ui->PortText->setFont(ft);

    //
    ui->HostIPText->setText(ip);
    ui->PortText->setText(port);
    ui->NameText->setText(Name);
    connect(ui->NameText,&QTextEdit::textChanged,this,[=](){
        Name = ui->NameText->toPlainText();
    });


    //连接成功
    connect(Tcpsocket,&QTcpSocket::connected,this,[=](){


        ui->ConnectToHost->setEnabled(false);
        ui->Ready->setEnabled(true);
        ui->Send->setEnabled(true);

        ui->HostIPText->setReadOnly(true);
        ui->NameText->setReadOnly(true);

        ui->MessageText->append("Server : You are Connected.");

        gamecopy.StartGame();

        SetBoard(gamecopy);

        connect(this,&MyClientWindow::select,&MyClientWindow::select_);
        connect(this,&MyClientWindow::moveend,&MyClientWindow::moveend_);

        connect(Socket,SIGNAL(receive(NetworkData)),this,SLOT(onreceive(NetworkData)));

    });

    //连接断开
    connect(Tcpsocket,&QTcpSocket::disconnected,this,[=](){

        ui->ConnectToHost->setEnabled(true);
        ui->Ready->setEnabled(false);
        ui->Send->setEnabled(false);

        ui->HostIPText->setReadOnly(false);
        ui->NameText->setReadOnly(false);
    });



    //创建棋子piece并存入棋盘pieces
    for(int i=0;i<36;++i)
    {
        MyPieces *piece =new MyPieces(this);
        piece->setFixedSize(80,80);
        piece->move(160+i/6*80,160+i%6*80);
        pieces.push_back(piece);
        //连接：棋子点击后利用status判断是选取（SIGNAL select）还是移动（SIGNAL moveend）
        connect(piece,&QPushButton::clicked,[=](){
            qDebug() <<"clicked   "<<i/6<<"   "<<i%6;
            if(!status){
                emit select(i);
                qDebug()<<"select";
            }
            else{
                emit moveend(i);
                qDebug()<<"moveend";
            }
        });
    }





}

MyClientWindow::~MyClientWindow()
{
    delete ui;
}


void MyClientWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);// 抗锯齿

    // 绘制棋盘
    painter.setPen(Qt::black);
    painter.drawRect(20, 20, 760, 760); // 棋盘外边框

    //绘制棋盘格
    int rect_x, rect_y;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5;++j)
        {
            rect_x = 200+80*i;
            rect_y = 200+80*j;
            painter.drawRect(rect_x,rect_y,80,80);
        }
    }

    //绘制圆弧线
    painter.drawArc(120,120,160,160,0,16*270);
    painter.drawArc(40,40,320,320,0,16*270);
    painter.drawArc(520,120,160,160,-16*90,16*270);
    painter.drawArc(440,40,320,320,-16*90,16*270);
    painter.drawArc(120,520,160,160,16*90,16*270);
    painter.drawArc(40,440,320,320,16*90,16*270);
    painter.drawArc(520,520,160,160,-16*180,16*270);
    painter.drawArc(440,440,320,320,-16*180,16*270);

}

void MyClientWindow::SetBoard(SurakartaGame game)
{
    // if(game.GetGameInfo()->current_player_==SurakartaPlayer::BLACK)
    //     Current_Player->setText("Current Player : BLACK");
    // else
    //     Current_Player->setText("Current Player : WHITE");

    // Round->setText("Round   "+QString::number(game.GetGameInfo()->num_round_));

    for(int i=0;i<36;i++)
    {
        pieces[i]->moveable=1;
        if((*game.GetBoard())[i/6][i%6]->GetColor()==PieceColor::BLACK)
        {
            pieces[i]->color=PieceColor::BLACK;
            pix.load(BlackPawn);
            pix = pix.scaled(pieces[i]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
            // pix=pix.scaled(80,80);
            pieces[i]->setIcon(pix);
            // pieces[i]->setIcon(QIcon(BlackPawn));
            pieces[i]->setIconSize(QSize(80,80));
            // QPainter painter(pieces[i]);
            // painter.setRenderHint(QPainter::Antialiasing);
            // qDebug()<<i/6<<" "<<i%6<<" B";
        }
        else if((*game.GetBoard())[i/6][i%6]->GetColor()==PieceColor::WHITE)
        {
            pieces[i]->color=PieceColor::WHITE;
            pix.load(WhitePawn);
            pix = pix.scaled(pieces[i]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
            // pix=pix.scaled(80,80);
            pieces[i]->setIcon(pix);
            pieces[i]->setIconSize(QSize(80,80));
            // qDebug()<<i/6<<" "<<i%6<<" W";
        }
        else if((*game.GetBoard())[i/6][i%6]->GetColor()==PieceColor::NONE)
        {
            pieces[i]->color=PieceColor::NONE;
            pix.load(Blank);
            pix = pix.scaled(pieces[i]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
            // pix=pix.scaled(80,80);
            pieces[i]->setIcon(pix);
            pieces[i]->setIconSize(QSize(80,80));
            // qDebug()<<i/6<<" "<<i%6<<" N";
        }
    }
}


void MyClientWindow::select_(int pos)
{
    if(pieces[pos]->color!=Me || CurrentPlayer!=Me)
        return;

    frompos=pos;
    status=1;

    //设置透明度
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(pieces[pos]);
    opacityEffect->setOpacity(0.7);
    pieces[pos]->setGraphicsEffect(opacityEffect);

    // QPixmap pix;
    // pix.load("");
    // pieces[pos]->setIcon(pix);
    // QGraphicsEffect * ge;
    // pieces[pos]->setGraphicsEffect(ge);
    qDebug()<<"select"<<"   "<<pos;
};


void MyClientWindow::moveend_(int pos)
{
    // QGraphicsEffect * ge;
    // pieces[frompos]->setGraphicsEffect(ge);

    //如果点击相同棋子，则取消选中
    if(pos==frompos){
        frompos=0;
        status=0;
        qDebug()<<"cancel";

        //设置透明度
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(pieces[pos]);
        opacityEffect->setOpacity(1);
        pieces[pos]->setGraphicsEffect(opacityEffect);

        // Gamermove_.player=SurakartaPlayer::UNKNOWN;
        return;
    }

    //设置透明度
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(pieces[frompos]);
    opacityEffect->setOpacity(1);
    pieces[frompos]->setGraphicsEffect(opacityEffect);


    //设置最终位置
    topos=pos;
    status=0;
    qDebug()<<"moveend"<<"   "<<pos;
    // Gamermove_.player=pieces[frompos]->color;
    SendMove(frompos,topos);
};


void MyClientWindow::SendMove(int frompos, int topos)
{
    SurakartaMove move = SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,Me);
    gamecopy.Move(move);
    SetBoard(gamecopy);
    Socket->send(NetworkData(OPCODE::MOVE_OP,
                             QString(QChar(frompos/6+'A'))+QString::number(frompos%6+1),
                             QString(QChar(topos/6+'A'))+QString::number(topos%6+1),""));
    qDebug()<<"SendMove  "<<QString(QChar(frompos/6+'A'))+QString::number(frompos%6+1)
             <<QString(QChar(topos/6+'A'))+QString::number(topos%6+1);
    ui->MessageText->append("Server : You move!");
    CurrentPlayer = Opponent;
    if(CurrentPlayer == SurakartaPlayer::BLACK){
        ui->CurrentplayerText->setText("BLACK");
    }else if(CurrentPlayer == SurakartaPlayer::WHITE){
        ui->CurrentplayerText->setText("WHITE");
    }
}

void MyClientWindow::SendMove(SurakartaMove move)
{
    gamecopy.Move(move);
    SetBoard(gamecopy);
    frompos=move.from.x*6+move.from.y;
    topos=move.to.x*6+move.to.y;
    Socket->send(NetworkData(OPCODE::MOVE_OP,
                             QString(QChar(frompos/6+'A'))+QString::number(frompos%6+1),
                             QString(QChar(topos/6+'A'))+QString::number(topos%6+1),""));
    qDebug()<<"SendMove  "<<QString(QChar(frompos/6+'A'))+QString::number(frompos%6+1)
             <<QString(QChar(topos/6+'A'))+QString::number(topos%6+1);
    qDebug()<<"SendMove  "<<frompos/6+'A';
    qDebug()<<"SendMove  "<<frompos/6;
    qDebug()<<"SendMove  "<<QChar(topos/6+'A');
    ui->MessageText->append("Server : You move!");
    CurrentPlayer = Opponent;
    if(CurrentPlayer == SurakartaPlayer::BLACK){
        ui->CurrentplayerText->setText("BLACK");
    }else if(CurrentPlayer == SurakartaPlayer::WHITE){
        ui->CurrentplayerText->setText("WHITE");
    }
}

void MyClientWindow::Chat(QString message)
{
    Socket->send(NetworkData(OPCODE::CHAT_OP,Name,message,""));
}


void MyClientWindow::onreceive(NetworkData data)
{
    if(data.op == OPCODE::READY_OP){
        ui->Ready->setEnabled(false);
        if(data.data2 == "BLACK"){
            ui->MessageText->append("Server : You are Black.");
            ui->MessageText->append("Server : It's your turn.");
            Me = SurakartaPlayer::BLACK;
            ui->MeText->setText("BALCK");
            Opponent = SurakartaPlayer::WHITE;
            CurrentPlayer = SurakartaPlayer::BLACK;
            ui->CurrentplayerText->setText("BLACK");
        }else if(data.data2 == "WHITE"){
            ui->MessageText->append("Server : You are White.");
            Me = SurakartaPlayer::WHITE;
            ui->MeText->setText("WHITE");
            Opponent = SurakartaPlayer::BLACK;
            CurrentPlayer = SurakartaPlayer::BLACK;
            ui->CurrentplayerText->setText("BLACK");
        }
        ui->MessageText->append(QString("Server")+" : "+"Game Start!");
        if(isAgent&&CurrentPlayer==Me){
            QTimer::singleShot(200,this,[=](){
                AgentMove(gamecopy);
            });
        }
    }else if(data.op == OPCODE::CHAT_OP){
        ui->MessageText->append(data.data1+" : "+data.data2);
    }else if(data.op == OPCODE::MOVE_OP){
        ui->MessageText->append(data.data1+" : "+"Move!");
        SurakartaMove move = SurakartaMove(data.data1[0].unicode()-'A',data.data1[1].unicode()-'1',
                                           data.data2[0].unicode()-'A',data.data2[1].unicode()-'1',Opponent);
        gamecopy.Move(move);
        SetBoard(gamecopy);
        ui->MessageText->append("Server : It's your turn.");
        CurrentPlayer = Me;
        if(CurrentPlayer == SurakartaPlayer::BLACK){
            ui->CurrentplayerText->setText("BLACK");
        }else if(CurrentPlayer == SurakartaPlayer::WHITE){
            ui->CurrentplayerText->setText("WHITE");
        }
        if(isAgent&&CurrentPlayer==Me){
            QTimer::singleShot(200,this,[=](){
                AgentMove(gamecopy);
            });
        }
    }else if(data.op == OPCODE::END_OP){
        ui->MessageText->append("Server : Game Over!");
        // std::cout<<static_cast<SurakartaEndReason>(data.data2.toInt());
        if(static_cast<SurakartaPlayer>(data.data3.toInt())==Me){
            ui->MessageText->append("Server : You are victorious!");
        }else if(static_cast<SurakartaPlayer>(data.data3.toInt())==Opponent){
            ui->MessageText->append("Server : You have lost!");
        }else if(static_cast<SurakartaPlayer>(data.data3.toInt())==SurakartaPlayer::NONE){
            ui->MessageText->append("Server : Fight to a standstill.");
        }
        CurrentPlayer = SurakartaPlayer::NONE;
        // Socket->bye();
        disconnect(Socket,SIGNAL(receive(NetworkData)),this,SLOT(onreceive(NetworkData)));
    }
}

void MyClientWindow::AgentMove(SurakartaGame gamecopy)
{
    // QTimer::singleShot(1000,this,[=](){
        Agent=std::make_shared<SurakartaAgentMine>(gamecopy.GetBoard(), gamecopy.GetGameInfo(), gamecopy.GetRuleManager());
        SurakartaMove move = Agent->CalculateMove();
        SendMove(move);
    // });
}
