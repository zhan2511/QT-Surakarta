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
