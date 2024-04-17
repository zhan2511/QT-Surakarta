#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include <QMainWindow>
#include "mypieces.h"
#include "surakarta/surakarta_game.h"
#include "surakarta/surakarta_common.h"
#include "surakarta/surakarta_agent/surakarta_agent_mine.h"
#include "surakarta/surakarta_agent/surakarta_agent_random.h"
#include <QWaitCondition>

// extern SurakartaGame game;


class chess_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit chess_window(QWidget *parent = nullptr);
    // ~chess_window();

    void paintEvent(QPaintEvent *);

    std::shared_ptr<SurakartaAgentBase> Blackagent=NULL;//设置ai
    std::shared_ptr<SurakartaAgentBase> Whiteagent=NULL;//设置ai
    // SurakartaPlayer BlackGamer=SurakartaPlayer::NONE;
    // SurakartaPlayer WhiteGamer=SurakartaPlayer::NONE;

    SurakartaGame gamecopy;//游戏线程的game的拷贝

    SurakartaMove Blackmove;//
    SurakartaMove Whitemove;//

    SurakartaMove Gamermove_;//用来判断玩家是否进行了有效移动：Gamermove_.player==UNKNOWN被认为是未进行有效移动

    std::vector<MyPieces*> pieces;//棋子的容器

    // QWaitCondition cdt;

    bool status=0;//用来判断棋子的点击是选取还是移动     1 to select    0 to moveend
    int frompos;//起始位置
    int topos;//最终位置

    QString BlackPawn=":/rsc/BlackPawn.png";//黑棋棋子
    QString WhitePawn=":/rsc/WhitePawn.png";//白棋棋子
    QString Blank="";//空棋子



signals:
    void select(int pos);//发送起始位置
    void moveend(int pos);//发送最终位置
    void blackmove(SurakartaMove Blackmove);//传给游戏线程的黑棋移动
    void whitemove(SurakartaMove Whitemove);//传给游戏线程的白棋移动
    void blackgamermove(SurakartaGame gamecopy);//玩家进行有效的黑棋移动
    void whitegamermove(SurakartaGame gamecopy);//玩家进行有效的白棋移动
    void gamerturn();//用来提示玩家回合（暂未使用）



public slots:
    void select_(int pos);//存入起始位置frompos
    void moveend_(int pos);//存入最终位置topos
    void winner_(SurakartaGame game);//输出winner
    void setboard(SurakartaGame game);//更新棋盘
    void decideblackmove(SurakartaGame game);//判断玩家orAgent进行移动，传递黑棋移动
    void decidewhitemove(SurakartaGame game);//判断玩家orAgent进行移动，传递白棋移动


};

#endif // CHESS_WINDOW_H
