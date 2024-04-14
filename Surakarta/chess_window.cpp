#include "chess_window.h"
#include <QPainter>
#include <QtWidgets>
#include "mypieces.h"
#include <QDebug>
#include "surakarta/surakarta_game.h"


chess_window::chess_window(QWidget *parent): QMainWindow{parent}
{
    this->setFixedSize(1200,800);
    this->setWindowIcon(QPixmap(":/rsc/Icon.jpg"));
    this->setWindowTitle("Surakarta Game");

    SurakartaGame game;
    game.GetRuleManager();
    game.StartGame();

    bool status=0;
    for(int i=0;i<36;++i)
    {
        MyPieces *piece =new MyPieces(this);
        piece->setFixedSize(80,80);
        piece->move(160+i/6*80,160+i%6*80);
        pieces.push_back(piece);
        connect(piece,&QPushButton::clicked,[=,&status](){
            qDebug() <<"clicked   "<<i/6<<"   "<<i%6;
            if(!status)
            {
                emit select(i);
                status=1;
                qDebug()<<"select";
            }
            else
            {
                emit moveend(i);
                status=0;
            }
        });
    }

    this->setboard(game.board_);

}

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



void chess_window::setboard(std::shared_ptr<SurakartaBoard> board)
{
    QString BlackPawn=":/rsc/BlackPawn.png";
    QString WhitePawn=":/rsc/WhitePawn.png";
    QString Blank="";
    QPixmap pix;

    for(int i=0;i<36;i++)
    {
        if((*board)[i/6][i%6]->GetColor()==PieceColor::BLACK)
        {
            pix.load(BlackPawn);
            pix.scaled(80,80);
            pieces[i]->setIcon(pix);
            this->setIconSize(pix.size());
            qDebug()<<i/6<<" "<<i%6<<" B";
        }
        else if((*board)[i/6][i%6]->GetColor()==PieceColor::WHITE)
        {
            pix.load(WhitePawn);
            pieces[i]->setIcon(pix);
            this->setIconSize(QSize(80,80));
            qDebug()<<i/6<<" "<<i%6<<" W";
        }
        else if((*board)[i/6][i%6]->GetColor()==PieceColor::NONE)
        {
            pix.load(Blank);
            pieces[i]->setIcon(pix);
            this->setIconSize(QSize(80,80));
            qDebug()<<i/6<<" "<<i%6<<" N";
        }
    }
}
