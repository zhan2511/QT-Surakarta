#include "chess_window.h"
#include <QPainter>
#include <QtWidgets>
#include "mypieces.h"
#include <QDebug>
#include <QTimer>
#include "mygamethread.h"
#include "mypausedialog.h"
#include "surakarta/surakarta_game.h"
#include "surakarta/surakarta_common.h"
// #include "surakarta/surakarta_agent/surakarta_agent_mine.h"
// #include "surakarta/surakarta_agent/surakarta_agent_random.h"


// SurakartaGame game;


chess_window::chess_window(int mode,int roundtimelimit,int gamehour,int gamemin,QWidget *parent):
    QMainWindow{parent},mode {mode},roundtimelimit{roundtimelimit},gamehour{gamehour},gamemin{gamemin}
{
    this->setFixedSize(1200,800);
    this->setWindowIcon(QPixmap(":/rsc/Icon.jpg"));
    this->setWindowTitle("Surakarta Game");
    this->Gamermove_.player=SurakartaPlayer::UNKNOWN;


    //创建游戏线程
    MyGameThread* gamethread=new MyGameThread(this);

    //连接：游戏线程准备好了后主线程设置棋盘setboard
    connect(gamethread,SIGNAL(GameReady(SurakartaGame)),this,SLOT(setboard(SurakartaGame)));

    //游戏时间
    BTime=QTime(gamehour,gamemin);
    WTime=QTime(gamehour,gamemin);

    //设置模式（agent）
    if(mode==1){
        Blackagent=std::make_shared<SurakartaAgentMine>(gamecopy.GetBoard(), gamecopy.GetGameInfo(), gamecopy.GetRuleManager());
    }
    else if(mode==2){
        Blackagent=std::make_shared<SurakartaAgentMine>(gamecopy.GetBoard(), gamecopy.GetGameInfo(), gamecopy.GetRuleManager());
        Whiteagent=std::make_shared<SurakartaAgentMine>(gamecopy.GetBoard(), gamecopy.GetGameInfo(), gamecopy.GetRuleManager());
    }

    //计时器
    QTimer *timer=new QTimer(this);
    connect(gamethread,&MyGameThread::BlackTurn,this,[=](){
        qDebug()<<"timer start";
        timer->start(1000);
    });
    connect(this,&chess_window::blackgamermove,this,[=](){
        qDebug()<<"timer stop";
        timer->stop();
        timeS=0;
        Time->setText("RoundTime   "+QString::number(roundtimelimit));
    });
    connect(gamethread,&MyGameThread::WhiteTurn,this,[=](){
        qDebug()<<"timer start";
        timer->start(1000);
    });
    connect(this,&chess_window::whitegamermove,this,[=](){
        qDebug()<<"timer stop";
        timer->stop();
        timeS=0;
        Time->setText("RoundTime   "+QString::number(roundtimelimit));
    });
    connect(gamethread,&MyGameThread::Finished,this,[=](){timer->stop();});
    connect(timer,&QTimer::timeout,[=](){
        // qDebug()<<timeS;
        Time->setText("RoundTime   "+QString::number(roundtimelimit-(++timeS)));
        if(gamecopy.GetGameInfo()->current_player_==SurakartaPlayer::BLACK){
            BTime=BTime.addMSecs(-1000);
            BlackTime->setText("BlackTime   "+BTime.toString("h:mm:ss"));
        }
        else if(gamecopy.GetGameInfo()->current_player_==SurakartaPlayer::WHITE){
            WTime=WTime.addMSecs(-1000);
            WhiteTime->setText("WhiteTime   "+WTime.toString("h:mm:ss"));
        }
        if(timeS==roundtimelimit||(QTime(0,0,0).secsTo(BTime)==0)||(QTime(0,0,0).secsTo(WTime)==0)){
            timer->stop();
            qDebug()<<"Time Out";
            emit timeover(gamecopy.GetGameInfo()->current_player_);
        }
    });

    //暂停键与暂停窗口（模态对话框）
    PauseDialog=new MyPauseDialog(this);
    PauseDialog->setAttribute(Qt::WA_DeleteOnClose);
    PauseDialog->setModal(1);
    QPushButton *Pause=new QPushButton(this);
    Pause->move(1100,60);
    Pause->setFixedSize(QSize(60,60));
    Pause->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Pause.png");
    pix = pix.scaled(Pause->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    Pause->setIcon(pix);
    Pause->setIconSize(QSize(60,60));
    connect(Pause,&QPushButton::clicked,this,[=](){
        timer->stop();
        PauseDialog->show();
    });

    //暂停窗口的按键
    connect(PauseDialog->Back,&QPushButton::clicked,this,[=](){
        timer->start(1000);
        PauseDialog->hide();
    });
    connect(PauseDialog->Quit,&QPushButton::clicked,this,[=](){
        gamethread->quit();
        gamethread->wait(25);
        gamethread->terminate();

        // if(gamethread->isRunning()){
        //     disconnect(gamethread,SIGNAL(OneMove(SurakartaGame)),this,SLOT(setboard(SurakartaGame)));
        //     disconnect(gamethread,SIGNAL(Finished(SurakartaGame)),this,SLOT(winner_(SurakartaGame)));
        //     gamethread->m_stop=1;
        //     condition.wakeAll();
        //     gamethread->quit();
        //     gamethread->wait(25);
        //     qDebug()<<"game exit";
        // }
        emit mainshow();
        this->close();
    });
    connect(PauseDialog->Restart,&QPushButton::clicked,this,[=/*,&gamethread*/](){
        PauseDialog->hide();

        qDebug()<<"    ====";


        // gamethread->quit();
        // gamethread->wait(25);
        // qDebug()<<"game exit";
        // gamethread->terminate();

        if(gamethread->isRunning()){
        disconnect(gamethread,SIGNAL(OneMove(SurakartaGame)),this,SLOT(setboard(SurakartaGame)));
        disconnect(gamethread,SIGNAL(Finished(SurakartaGame)),this,SLOT(winner_(SurakartaGame)));
        gamethread->m_stop=1;
        condition.wakeAll();
        gamethread->quit();
        qDebug()<<"game exit";
        gamethread->wait(25);
        }



        QTimer::singleShot(100,this,[=/*,&gamethread*/](){
            // gamethread=new MyGameThread(this);
            BTime=QTime(gamehour,gamemin);
            WTime=QTime(gamehour,gamemin);
            timeS=0;
            connect(gamethread,SIGNAL(OneMove(SurakartaGame)),this,SLOT(setboard(SurakartaGame)));
            connect(gamethread,SIGNAL(Finished(SurakartaGame)),this,SLOT(winner_(SurakartaGame)));
            gamethread->m_stop=0;
            gamethread->GamePre();
            gamethread->start();
        });
    });


    //设置字体大小
    ft.setPointSize(18);

    // 显示游戏信息的标签
    Round=new QLabel(this);
    Round->setFixedSize(280,100);
    Round->move(850,100);
    Round->setFont(ft);
    Round->setText("Round   0");

    Current_Player=new QLabel(this);
    Current_Player->setFixedSize(280,100);
    Current_Player->move(850,200);
    Current_Player->setFont(ft);
    Current_Player->setText("Current Player : ");

    Time=new QLabel(this);
    Time->setFixedSize(280,100);
    Time->move(850,300);
    Time->setFont(ft);
    Time->setText("RoundTime   "+QString::number(roundtimelimit));

    BlackTime=new QLabel(this);
    BlackTime->setFixedSize(280,100);
    BlackTime->move(850,400);
    BlackTime->setFont(ft);
    BlackTime->setText("BlackTime   "+BTime.toString("h:mm:ss"));

    WhiteTime=new QLabel(this);
    WhiteTime->setFixedSize(280,100);
    WhiteTime->move(850,500);
    WhiteTime->setFont(ft);
    WhiteTime->setText("WhiteTime   "+WTime.toString("h:mm:ss"));

    Winner=new QLabel(this);
    Winner->setFixedSize(280,150);
    Winner->move(850,600);
    Winner->setFont(ft);






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
                // status=1;
                // qDebug()<<"select";
            }
            else{
                emit moveend(i);
                // status=0;
                // qDebug()<<"moveend";
            }
        });
    }

    //游戏线程：准备
    (*gamethread).GamePre();

    //连接：
    connect(this,SIGNAL(select(int)),SLOT(select_(int)));
    connect(this,SIGNAL(moveend(int)),SLOT(moveend_(int)));

    //连接：玩家有效移动后告诉主线程
    connect(this,SIGNAL(blackgamermove(SurakartaGame)),SLOT(decideblackmove(SurakartaGame)));
    connect(this,SIGNAL(whitegamermove(SurakartaGame)),SLOT(decidewhitemove(SurakartaGame)));

    //to debug
    connect(gamethread,&MyGameThread::started,this,[=](){qDebug()<<"connect";});
    // connect(&gamethread,SIGNAL(gamethread.Finished()),this,SLOT(winner_()));
    // connect(&gamethread,&MyGameThread::Finished,this,&chess_window::winner_);

    //连接：游戏线程中轮到黑（白）的回合，发信号告诉主线程
    connect(gamethread,SIGNAL(BlackTurn(SurakartaGame)),this,SLOT(decideblackmove(SurakartaGame)));
    connect(gamethread,SIGNAL(WhiteTurn(SurakartaGame)),this,SLOT(decidewhitemove(SurakartaGame)));

    //连接：主线程把玩家orAgent的移动move传给游戏线程
    connect(this,SIGNAL(blackmove(SurakartaMove)),gamethread,SLOT(blackmove_(SurakartaMove)));
    connect(this,SIGNAL(whitemove(SurakartaMove)),gamethread,SLOT(whitemove_(SurakartaMove)));

    //连接：一次移动后交给主线程更新棋盘
    connect(gamethread,SIGNAL(OneMove(SurakartaGame)),this,SLOT(setboard(SurakartaGame)));

    //连接：游戏结束后输出winner
    connect(gamethread,SIGNAL(Finished(SurakartaGame)),this,SLOT(winner_(SurakartaGame)));
    connect(this,SIGNAL(timeover(SurakartaPlayer)),SLOT(winner_(SurakartaPlayer)));

    //连接：超时终止游戏线程
    connect(this,&chess_window::timeover,[=](){
        gamethread->quit();
        // gamethread->exit(0);
        // auto ret=gamethread->isRunning();
        // qDebug()<<ret;
        gamethread->wait(25);
        // gamethread->terminate();//###########  ****，害死我了，****
        // disconnect(gamethread,SIGNAL(OneMove(SurakartaGame)),this,SLOT(setboard(SurakartaGame)));
        // disconnect(gamethread,SIGNAL(Finished(SurakartaGame)),this,SLOT(winner_(SurakartaGame)));
        // gamethread->m_stop=1;
        // condition.wakeAll();
        // gamethread->quit();
        // gamethread->wait(25);
        qDebug()<<"game exit";
    });

    //连接：退出线程后删除线程
    // connect(gamethread,&QThread::finished,gamethread,&QThread::deleteLater);//###########  ****，害死我了，****

    //开始线程
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
    if(game.GetGameInfo()->current_player_==SurakartaPlayer::BLACK)
        Current_Player->setText("Current Player : BLACK");
    else
        Current_Player->setText("Current Player : WHITE");

    Round->setText("Round   "+QString::number(game.GetGameInfo()->num_round_));

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

void chess_window::select_(int pos)
{
    if(pieces[pos]->color!=gamecopy.GetGameInfo()->current_player_)
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


void chess_window::moveend_(int pos)
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

    //玩家进行有效移动后再次呼出槽函数传递有效移动给游戏线程
    if(Gamermove_.player==SurakartaPlayer::BLACK){
        emit blackgamermove(gamecopy);
    }
    else{
        emit whitegamermove(gamecopy);
    }
    // if(game.GetGameInfo()->current_player_==SurakartaPlayer::BLACK){
    //     Blackmove=SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,game.game_info_->current_player_);
    // }
    // else{
    //     Whitemove=SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,game.game_info_->current_player_);
    // }
};


void chess_window::winner_(SurakartaGame game){

    for(int i=0;i<36;i++){
        pieces[i]->moveable=0;
    }

    if(game.GetGameInfo()->winner_==SurakartaPlayer::BLACK)
        Winner->setText("WINNER : BLACK");
    else if(game.GetGameInfo()->winner_==SurakartaPlayer::WHITE)
        Winner->setText("WINNER : WHITE");
    else if(game.GetGameInfo()->winner_==SurakartaPlayer::NONE)
        Winner->setText("TIE");

    auto winner=game.GetGameInfo()->winner_;
    if(winner==SurakartaPlayer::BLACK){
        qDebug()<<"Black win";
    }
    else if(winner==SurakartaPlayer::WHITE){
        qDebug()<<"White win";
    }
    else{
        qDebug()<<"Tie";
    }
}

void chess_window::winner_(SurakartaPlayer time_out){

    for(int i=0;i<36;i++){
        pieces[i]->moveable=0;
    }

    if(time_out==SurakartaPlayer::WHITE){
        qDebug()<<"Black win";
        Winner->setText("WINNER : BLACK");
    }
    else if(time_out==SurakartaPlayer::BLACK){
        qDebug()<<"White win";
        Winner->setText("WINNER : WHITE");
    }
}


void chess_window::decideblackmove(SurakartaGame game)
{
    gamecopy=game;
    qDebug()<<"black connect";

    //判断是否建立了Agent，是则让Agent做出移动
    if(Blackagent!=NULL){
        // QTimer::singleShot(1000,this,[=](){
        Blackagent=std::make_shared<SurakartaAgentMine>(game.GetBoard(), game.GetGameInfo(), game.GetRuleManager());
            Blackmove=Blackagent->CalculateMove();
            qDebug()<<"Blackagent CalculateMove";
        // });
    }
    //判断玩家是否进行了有效移动并提示
    else if(Gamermove_.player==SurakartaPlayer::UNKNOWN){
        emit blackgamerturn();

        // status=1;
        return;
    }
    //玩家误用棋子
    else if(Gamermove_.player==SurakartaPlayer::WHITE){
        return;
    }
    //存入玩家的有效移动
    else/* if(Gamermove_.player==SurakartaPlayer::BLACK)*/{
        Blackmove=SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,SurakartaPlayer::BLACK);
        Gamermove_.player=SurakartaPlayer::UNKNOWN;
    }
    //发送给游戏线程并唤醒
    emit blackmove(Blackmove);
    qDebug()<<"emit blackmove";
    Gamermove_.player=SurakartaPlayer::UNKNOWN;
    condition.wakeAll();
}

void chess_window::decidewhitemove(SurakartaGame game)
{
    gamecopy=game;
    qDebug()<<"white connect";
    if(Whiteagent!=NULL){
        // QTimer::singleShot(1000,this,[=](){
        Whiteagent=std::make_shared<SurakartaAgentMine>(game.GetBoard(), game.GetGameInfo(), game.GetRuleManager());
            Whitemove=Whiteagent->CalculateMove();
            qDebug()<<"Whiteagent CalculateMove";
        // });
    }
    else if(Gamermove_.player==SurakartaPlayer::UNKNOWN){
        emit whitegamerturn();
        return;
    }
    else if(Gamermove_.player==SurakartaPlayer::BLACK){
        return;
    }
    else{
        Whitemove=SurakartaMove(frompos/6,frompos%6,topos/6,topos%6,SurakartaPlayer::WHITE);
        Gamermove_.player=SurakartaPlayer::UNKNOWN;
    }
    emit whitemove(Whitemove);
    qDebug()<<"emit whitemove";
    Gamermove_.player=SurakartaPlayer::UNKNOWN;
    condition.wakeAll();
}






