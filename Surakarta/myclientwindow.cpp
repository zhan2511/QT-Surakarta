#include "myclientwindow.h"
#include "ui_myclientwindow.h"
#include <QPainter>
#include <QGraphicsOpacityEffect>
#include "network/networkdata.h"

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
    this->Gamermove_.player=SurakartaPlayer::UNKNOWN;


    //Send 按键
    ui->Send->setEnabled(false);
    ui->Send->setFixedSize(QSize(150,50));
    ui->Send->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Send.png");
    pix = pix.scaled(ui->Send->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Send->setIcon(pix);
    ui->Send->setIconSize(QSize(150,50));
    connect(ui->Send,&QPushButton::clicked,this,[=](){
        Chat(ui->SendText->toPlainText());
        qDebug()<<"Send Message";
        ui->SendText->clear();
    });

    //ConnectToHost 按键
    ui->ConnectToHost->setFixedSize(QSize(190,60));
    ui->ConnectToHost->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ConnectToHost.png");
    pix = pix.scaled(ui->ConnectToHost->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ConnectToHost->setIcon(pix);
    ui->ConnectToHost->setIconSize(QSize(190,60));
    connect(ui->ConnectToHost,&QPushButton::clicked,this,[=](){
        ip = ui->HostIPText->toPlainText();
        qDebug()<<QHostAddress(ip).toString();
        qDebug()<<ip;
        Socket->hello(QHostAddress(ip).toString(),9999);
        qDebug()<<"ConnectToHost";
    });


    //Ready 按键
    ui->Ready->setEnabled(false);
    ui->Ready->setFixedSize(QSize(120,60));
    ui->Ready->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Ready.png");
    pix = pix.scaled(ui->Ready->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->Ready->setIcon(pix);
    ui->Ready->setIconSize(QSize(120,60));
    connect(ui->Ready,&QPushButton::clicked,this,[=](){
        Socket->send(NetworkData(OPCODE::READY_OP,Name,"",QString::number(1)));
        qDebug()<<"Ready";
        ui->Ready->setEnabled(false);
    });

    //ESC 按键
    ui->ESC->setFixedSize(QSize(40,40));
    ui->ESC->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/ESC.png");
    pix = pix.scaled(ui->ESC->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    ui->ESC->setIcon(pix);
    ui->ESC->setIconSize(QSize(40,40));
    connect(ui->ESC,&QPushButton::clicked,this,[=](){
        Socket->bye();
        // emit NetDialogShow();
        this->close();
    });


    //设置字体大小
    ft.setPointSize(16);


    //
    ui->HostIPText->setFont(ft);
    ui->MessageText->setFont(ft);
    ui->NameText->setFont(ft);

    //
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
                // qDebug()<<"select";
            }
            else{
                emit moveend(i);
                // qDebug()<<"moveend";
            }
        });
    }

    gamecopy.StartGame();
    OriginalBoard(gamecopy);

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

void MyClientWindow::OriginalBoard(SurakartaGame game)
{
    game.StartGame();
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
    if(pieces[pos]->color!=Me)
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

        Gamermove_.player=SurakartaPlayer::UNKNOWN;
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
    Gamermove_.player=pieces[frompos]->color;
    SendMove(frompos,topos);
};


void MyClientWindow::SendMove(int frompos, int topos)
{
    ;
    Socket->send(NetworkData(OPCODE::MOVE_OP,
                             QString(QChar(frompos%6+'A'))+QString::number(frompos/6+1),
                             QString(QChar(topos%6+'A'))+QString::number(topos/6+1),""));
}

void MyClientWindow::Chat(QString message)
{
    Socket->send(NetworkData(OPCODE::CHAT_OP,Name,message,""));
}
