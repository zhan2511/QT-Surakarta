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
        QThread::msleep(500);
        if (!turn) {
            emit BlackTurn(game);
            qDebug()<<"blackturn";

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
            emit WhiteTurn(game);
            qDebug()<<"whiteturn";

            mutex.lock();
            qDebug()<<"waiting";
            condition.wait(&mutex);
            qDebug()<<"ok";
            game.Move(Whitemove);
            mutex.unlock();
            qDebug()<<"white move";
            turn = !turn;
        }
        emit OneMove(game);
        QThread::msleep(1000);
    }
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
