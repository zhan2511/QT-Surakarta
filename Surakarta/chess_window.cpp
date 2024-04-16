#include "chess_window.h"
#include <QPainter>
#include <QtWidgets>
#include "mypieces.h"
#include <QDebug>
#include "mygamethread.h"
#include "surakarta/surakarta_game.h"
#include "surakarta/surakarta_common.h"
// #include "surakarta/surakarta_agent/surakarta_agent_mine.h"
// #include "surakarta/surakarta_agent/surakarta_agent_random.h"


// SurakartaGame game;


chess_window::chess_window(QWidget *parent): QMainWindow{parent}
{
    this->setFixedSize(1200,800);
    this->setWindowIcon(QPixmap(":/rsc/Icon.jpg"));
    this->setWindowTitle("Surakarta Game");
    this->Gamermove_.player=SurakartaPlayer::UNKNOWN;

    MyGameThread* gamethread=new MyGameThread(this);

    connect(gamethread,SIGNAL(GameReady(SurakartaGame)),this,SLOT(setboard(SurakartaGame)));

    for(int i=0;i<36;++i)
    {
        MyPieces *piece =new MyPieces(this);
        piece->setFixedSize(80,80);
        piece->move(160+i/6*80,160+i%6*80);
        pieces.push_back(piece);
        connect(piece,&QPushButton::clicked,[=](){
            qDebug() <<"clicked   "<<i/6<<"   "<<i%6;
            if(!status)
            {
                emit select(i);
                // status=1;
                // qDebug()<<"select";
            }
            else
            {
                emit moveend(i);
                // status=0;
                // qDebug()<<"moveend";
            }
        });
    }

    (*gamethread).GamePre();



    connect(this,SIGNAL(select(int)),SLOT(select_(int)));
    connect(this,SIGNAL(moveend(int)),SLOT(moveend_(int)));

    connect(gamethread,&MyGameThread::started,this,[=](){qDebug()<<"connect";});
    // connect(&gamethread,SIGNAL(gamethread.Finished()),this,SLOT(winner_()));
    // connect(&gamethread,&MyGameThread::Finished,this,&chess_window::winner_);

    connect(gamethread,SIGNAL(BlackTurn(SurakartaGame)),this,SLOT(decideblackmove(SurakartaGame)));
    connect(gamethread,SIGNAL(WhiteTurn(SurakartaGame)),this,SLOT(decidewhitemove(SurakartaGame)));
    connect(this,SIGNAL(blackmove(SurakartaMove)),gamethread,SLOT(blackmove_(SurakartaMove)));
    connect(this,SIGNAL(whitemove(SurakartaMove)),gamethread,SLOT(whitemove_(SurakartaMove)));
    connect(gamethread,SIGNAL(OneMove(SurakartaGame)),this,SLOT(setboard(SurakartaGame)));
    connect(gamethread,SIGNAL(Finished(SurakartaGame)),this,SLOT(winner_(SurakartaGame)));
    connect(gamethread,&QThread::finished,gamethread,&QThread::deleteLater);
    qDebug()<<"ready to start";
    (*gamethread).start();
    // gamethread.run();
    qDebug()<<"startover";



}


// chess_window::~chess_window()
// {
//     qDebug()<<"chess over";
// }


void chess_window::paintEvent(QPaintEvent *)
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



void chess_window::setboard(SurakartaGame game)
{
    QPixmap pix;

    for(int i=0;i<36;i++)
    {
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
            qDebug()<<i/6<<" "<<i%6<<" B";
        }
        else if((*game.GetBoard())[i/6][i%6]->GetColor()==PieceColor::WHITE)
        {
            pieces[i]->color=PieceColor::WHITE;
            pix.load(WhitePawn);
            pix = pix.scaled(pieces[i]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
            // pix=pix.scaled(80,80);
            pieces[i]->setIcon(pix);
            pieces[i]->setIconSize(QSize(80,80));
            qDebug()<<i/6<<" "<<i%6<<" W";
        }
        else if((*game.GetBoard())[i/6][i%6]->GetColor()==PieceColor::NONE)
        {
            pieces[i]->color=PieceColor::NONE;
            pix.load(Blank);
            pix = pix.scaled(pieces[i]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
            // pix=pix.scaled(80,80);
            pieces[i]->setIcon(pix);
            pieces[i]->setIconSize(QSize(80,80));
            qDebug()<<i/6<<" "<<i%6<<" N";
        }
    }
}

void chess_window::select_(int pos)
{
    frompos=pos;
    status=1;
    // QPixmap pix;
    // pix.load("");
    // pieces[pos]->setIcon(pix);
    // QGraphicsEffect * ge;
    // pieces[pos]->setGraphicsEffect(ge);
    qDebug()<<"select"<<"   "<<pos;
};


void chess_window::moveend_(int pos)
{
    // QGraphicsEffect * ge;
    // pieces[frompos]->setGraphicsEffect(ge);
    if(pos==frompos){
        frompos=0;
        status=0;
        qDebug()<<"cancel";
        Gamermove_.player=SurakartaPlayer::UNKNOWN;
        return;
    }
    topos=pos;
    status=0;
    qDebug()<<"moveend"<<"   "<<pos;
    Gamermove_.player=pieces[frompos]->color;

    // if(game.GetGameInfo()->current_player_==SurakartaPlayer::BLACK){
    //     Blackmove=SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,game.game_info_->current_player_);
    // }
    // else{
    //     Whitemove=SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,game.game_info_->current_player_);
    // }
};

void chess_window::winner_(SurakartaGame game){
    auto winner=game.GetGameInfo()->winner_;
    if(winner==SurakartaPlayer::BLACK){
        qDebug()<<"Black win";
    }
    else{
        qDebug()<<"White win";
    }
}


void chess_window::decideblackmove(SurakartaGame game)
{
    Blackagent=std::make_shared<SurakartaAgentMine>(game.GetBoard(), game.GetGameInfo(), game.GetRuleManager());
    qDebug()<<"black connect";
    if(Blackagent!=NULL){
        Blackmove=Blackagent->CalculateMove();
        qDebug()<<"Blackagent CalculateMove";
    }
    else {
        while(Gamermove_.player==SurakartaPlayer::UNKNOWN){
        }
        Blackmove=SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,SurakartaPlayer::BLACK);
    }
    emit blackmove(Blackmove);
    qDebug()<<"emit blackmove";
    Gamermove_.player=SurakartaPlayer::UNKNOWN;
    condition.wakeAll();
}

void chess_window::decidewhitemove(SurakartaGame game)
{
    Whiteagent=std::make_shared<SurakartaAgentRandom>(game.GetBoard(), game.GetGameInfo(), game.GetRuleManager());
    qDebug()<<"white connect";
    if(Whiteagent!=NULL){
        Whitemove=Whiteagent->CalculateMove();
        qDebug()<<"Whiteagent CalculateMove";
    }
    else {
        while(Gamermove_.player==SurakartaPlayer::UNKNOWN){
        }
        Whitemove=SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,SurakartaPlayer::WHITE);
    }
    emit whitemove(Whitemove);
    qDebug()<<"emit blackmove";
    Gamermove_.player=SurakartaPlayer::UNKNOWN;
    condition.wakeAll();
}






