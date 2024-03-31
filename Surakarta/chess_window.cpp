#include "chess_window.h"
#include <QPainter>
#include <QtWidgets>

chess_window::chess_window(QWidget *parent): QMainWindow{parent}
{
    this->setFixedSize(1200,800);
    this->setWindowIcon(QPixmap(":/rsc/Icon.jpg"));
    this->setWindowTitle("Surakarta Game");
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
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6;++j)
        {
            rect_x = 190+70*i;
            rect_y = 190+70*j;
            painter.drawRect(rect_x,rect_y,70,70);
        }
    }

    //绘制圆弧线
    painter.drawArc(120,120,140,140,0,16*270);
    painter.drawArc(50,50,280,280,0,16*270);
    painter.drawArc(540,120,140,140,-16*90,16*270);
    painter.drawArc(470,50,280,280,-16*90,16*270);
    painter.drawArc(120,540,140,140,16*90,16*270);
    painter.drawArc(50,470,280,280,16*90,16*270);
    painter.drawArc(540,540,140,140,-16*180,16*270);
    painter.drawArc(470,470,280,280,-16*180,16*270);

}
