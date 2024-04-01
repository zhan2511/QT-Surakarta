#include "mypushbutton.h"
#include <QPropertyAnimation>

MyPushbutton::MyPushbutton(QWidget *parent)
    : QPushButton{parent}
{}

void MyPushbutton::SetCustomisedIcon(QString NormalImage)
{
    this->NormalImage=NormalImage;
    QPixmap pix;
    pix.load(NormalImage);
    this->setFixedSize(this->width,this->height);
    this->setStyleSheet("QPushButton{Border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(this->pixwidth,this->pixheight));
}



void MyPushbutton::BounceDown()
{
    QPropertyAnimation * AniDown =new QPropertyAnimation(this,"geometry");
    AniDown->setDuration(100);
    AniDown->setStartValue(QRect(this->x(),this->y(),this->widthMM(),this->heightMM()));
    AniDown->setEndValue(QRect(this->x(),this->y()+5,this->widthMM(),this->heightMM()));
    AniDown->setEasingCurve(QEasingCurve::OutBounce);
    AniDown->start();

}
void MyPushbutton::BounceUp()
{
    QPropertyAnimation * AniUp =new QPropertyAnimation(this,"geometry");
    AniUp->setDuration(100);
    AniUp->setStartValue(QRect(this->x(),this->y(),this->widthMM(),this->heightMM()));
    AniUp->setEndValue(QRect(this->x(),this->y()-5,this->widthMM(),this->heightMM()));
    AniUp->setEasingCurve(QEasingCurve::OutBounce);
    AniUp->start();
}



// void MyPushbutton::PressEfect(QString PressImage)
// {
//     this->PressImage=PressImage;
// }
