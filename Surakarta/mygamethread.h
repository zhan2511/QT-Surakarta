#ifndef MYGAMETHREAD_H
#define MYGAMETHREAD_H

#include <QThread>
#include "surakarta/surakarta_game.h"
#include <QWaitCondition>
#include <QMutex>


extern QWaitCondition condition;
extern QMutex mutex;
// extern SurakartaGame game;


class MyGameThread : public QThread
{
    Q_OBJECT
public:
    // explicit MyGameThread(QObject *parent = nullptr);
    MyGameThread(QObject *parent = nullptr);

    SurakartaMove Blackmove;
    SurakartaMove Whitemove;
    SurakartaGame game;

    void GamePre();//game的准备

    bool m_stop=0;

    virtual void run() override;

public slots:
    void blackmove_(SurakartaMove Blackmove);//接收主线程的黑棋移动
    void whitemove_(SurakartaMove Whitemove);//接收主线程的白棋移动


signals:
    void GameReady(SurakartaGame game);//提示主线程准备完成
    void BlackTurn(SurakartaGame game);//提示主线程黑棋回合
    void WhiteTurn(SurakartaGame game);//提示主线程白棋回合
    void OneMove(SurakartaGame game);//提示主线程完成一次移动
    void Finished(SurakartaGame game);//提示主线程完成一次游戏
    // QThread interface
protected:
};

#endif // MYGAMETHREAD_H
