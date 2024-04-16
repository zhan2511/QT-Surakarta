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


    void GamePre();

    virtual void run() override;

public slots:
    void blackmove_(SurakartaMove Blackmove);
    void whitemove_(SurakartaMove Whitemove);


signals:
    void GameReady(SurakartaGame game);
    void BlackTurn(SurakartaGame game);
    void WhiteTurn(SurakartaGame game);
    void OneMove(SurakartaGame game);
    void Finished(SurakartaGame game);
    // QThread interface
protected:
};

#endif // MYGAMETHREAD_H
