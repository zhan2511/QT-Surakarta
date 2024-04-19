#include "mypieces.h"

MyPieces::MyPieces(QWidget *parent)
    : QPushButton{parent}
{
    this->setStyleSheet("QPushButton{Border:0px}");
}


void MyPieces::mousePressEvent(QMouseEvent *event)
{
    if(moveable==0){
        return;
    }
    else
        return QPushButton::mousePressEvent(event);
}
