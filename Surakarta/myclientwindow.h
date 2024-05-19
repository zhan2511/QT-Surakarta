#ifndef MYCLIENTWINDOW_H
#define MYCLIENTWINDOW_H

#include <QWidget>
#include <QLabel>
#include "mypieces.h"
#include "network/networksocket.h"
#include <QTcpSocket>



namespace Ui {
class MyClientWindow;
}

class MyClientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MyClientWindow(QWidget *parent = nullptr);
    ~MyClientWindow();

    NetworkSocket *Socket;

    void paintEvent(QPaintEvent *);

    std::vector<MyPieces*> pieces;//棋子的容器

    SurakartaGame gamecopy;//游戏线程的game的拷贝

    QString BlackPawn=":/rsc/BlackPawn.png";//黑棋棋子
    QString WhitePawn=":/rsc/WhitePawn.png";//白棋棋子
    QString Blank="";//空棋子

    QString Name = "New Player";
    QString ip = "";

    SurakartaPlayer Me;
    SurakartaMove Gamermove_;//用来判断玩家是否进行了有效移动：Gamermove_.player==UNKNOWN被认为是未进行有效移动

    QLabel *HostIp;
    QLabel *Current_Player;//
    QLabel *Round;//
    QLabel *Status;

    QFont ft;//字体
    QPixmap pix;

    void OriginalBoard(SurakartaGame game);//设置棋盘

    bool status=0;//用来判断棋子的点击是选取还是移动     1 to select    0 to moveend
    int frompos;//起始位置
    int topos;//最终位置
    void SendMove(int frompos,int topos);

    void Chat(QString message);

signals:
    void select(int pos);//发送起始位置
    void moveend(int pos);//发送最终位置
    // void NetDialogShow();

public slots:
    void select_(int pos);//存入起始位置frompos
    void moveend_(int pos);//存入最终位置topos


private:
    Ui::MyClientWindow *ui;
};

#endif // MYCLIENTWINDOW_H
