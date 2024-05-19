#ifndef MYSERVERWINDOW_H
#define MYSERVERWINDOW_H

#include <QWidget>
#include "network/networkserver.h"
#include "surakarta/surakarta_game.h"
#include "mygamethread.h"


namespace Ui {
class MyServerWindow;
}

class MyServerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MyServerWindow(QWidget *parent = nullptr);
    ~MyServerWindow();

    NetworkServer *Server;
    QString ServerName = "Server";

    bool isReadyP1 = 0;
    bool isReadyP2 = 0;

    SurakartaMove move;

    SurakartaPlayer P1Color = SurakartaPlayer::NONE;
    SurakartaPlayer P2Color = SurakartaPlayer::NONE;
    QString P1Name = "";
    QString P2Name = "";
    int Turn = -1;// 决定白棋or黑棋的回合

    MyGameThread* gamethread;

    QFont ft;

public slots:
    void onreceive(QTcpSocket* client, NetworkData data);
    void Gamestart();
    void Gameover(SurakartaGame game);
    void Move(SurakartaMove move);

signals:

private:
    Ui::MyServerWindow *ui;
};

#endif // MYSERVERWINDOW_H
