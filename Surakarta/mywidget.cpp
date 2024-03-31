#include "mywidget.h"
#include <Qpainter>
#include <QPixmap>
#include <QtWidgets>

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{}


void MyWidget::paintEvent(QPaintEvent *event)// 画个背景
{
    QPainter painter(this);
    pix=pix.scaled(scaleX,scaleY);
    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    painter.drawPixmap(posX,posY,width,height,pix);
}

//输入 pixmap 并初始化各参数
void MyWidget::GetPaintInfo_pix(QPixmap pix)
{
    this->pix=pix;
    this->scaleX=pix.width();
    this->scaleY=pix.height();
    this->width=pix.width();
    this->height=pix.height();
}
void MyWidget::GetPaintInfo_scale(int scaleX,int scaleY)
{
    this->scaleX=scaleX;
    this->scaleY=scaleY;
}
void MyWidget::GetPaintInfo_size(int width,int height)
{
    this->width=width;
    this->height=height;
}
void MyWidget::GetPaintInfo_pos(int posX,int posY)
    {
    this->posX=posX;
    this->posY=posY;
}

