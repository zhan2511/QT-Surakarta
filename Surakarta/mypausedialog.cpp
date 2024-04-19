#include "mypausedialog.h"
#include <QPixmap>

MyPauseDialog::MyPauseDialog(QWidget *parent)
    : QDialog{parent}
{
    setFixedSize(QSize(400,600));

    QPixmap pix;

    Back=new QPushButton(this);
    Back->setFixedSize(QSize(300,120));
    Back->move(50,30);
    Back->setStyleSheet("QPushButton{Border:0px}");
    pix.load(":/rsc/Back.png");
    pix = pix.scaled(Back->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    Back->setIcon(pix);
    Back->setIconSize(QSize(300,120));

    SaveGame=new QPushButton(this);
    SaveGame->setFixedSize(QSize(300,120));
    SaveGame->move(50,160);
    pix.load(":/rsc/SaveGame.png");
    pix = pix.scaled(SaveGame->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    SaveGame->setStyleSheet("QPushButton{Border:0px}");
    SaveGame->setIcon(pix);
    SaveGame->setIconSize(QSize(300,120));


    Restart=new QPushButton(this);
    Restart->setFixedSize(QSize(300,120));
    Restart->move(50,290);
    pix.load(":/rsc/Restart.png");
    pix = pix.scaled(Restart->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    Restart->setStyleSheet("QPushButton{Border:0px}");
    Restart->setIcon(pix);
    Restart->setIconSize(QSize(300,120));


    Quit=new QPushButton(this);
    Quit->setFixedSize(QSize(300,120));
    Quit->move(50,410);
    pix.load(":/rsc/Quit.png");
    pix = pix.scaled(Quit->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation) ;
    Quit->setStyleSheet("QPushButton{Border:0px}");
    Quit->setIcon(pix);
    Quit->setIconSize(QSize(300,120));






}
