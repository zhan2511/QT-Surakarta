#include "mygamethread.h"
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>


// MyGameThread::MyGameThread(QObject *parent)
//     : QThread{parent}
// {}

QWaitCondition condition;
QMutex mutex;
// SurakartaGame game;


MyGameThread::MyGameThread(QObject *parent)
    : QThread{parent}
{}


void MyGameThread::run()
{ 
    bool turn ;/*= rand() % 2 == 0;*/
    while (!game.IsEnd()) {
        // QThread::msleep(500);
        if (!turn) {

            //提示主线程黑棋回合
            emit BlackTurn(game);
            qDebug()<<"blackturn";

            //加锁并等待唤醒
            mutex.lock();
            qDebug()<<"waiting";
            condition.wait(&mutex);
            qDebug()<<"ok";
            game.Move(Blackmove);
            mutex.unlock();
            qDebug()<<"black move";
            turn = !turn;
        }
        else {

            //提示主线程白棋回合
            emit WhiteTurn(game);
            qDebug()<<"whiteturn";

            //加锁并等待唤醒
            mutex.lock();
            qDebug()<<"waiting";
            condition.wait(&mutex);
            qDebug()<<"ok";
            game.Move(Whitemove);
            mutex.unlock();
            qDebug()<<"white move";
            turn = !turn;
        }

        //提示主线程完成一次移动
        emit OneMove(game);
        QThread::msleep(500);
    }
    qDebug()<<"game over";

    //提示主线程完成一次游戏
    emit Finished(game);
}


void MyGameThread::GamePre()
{
    game.StartGame();
    emit GameReady(game);
}


void MyGameThread::blackmove_(SurakartaMove Blackmove)
{
    this->Blackmove=Blackmove;
}
void MyGameThread::whitemove_(SurakartaMove Whitemove)
{
    this->Whitemove=Whitemove;
}
