#include "mypieces.h"

MyPieces::MyPieces(QWidget *parent)
    : QPushButton{parent}
{
    this->setStyleSheet("QPushButton{Border:0px}");
}
