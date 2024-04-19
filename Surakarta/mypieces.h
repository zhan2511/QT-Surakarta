#ifndef MYPIECES_H
#define MYPIECES_H

#include <QPushButton>
#include "surakarta/surakarta_game.h"


class MyPieces : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPieces(QWidget *parent = nullptr);
    PieceColor color;
    bool moveable=1;//判断是否可以移动   0 假    1 真

signals:

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
};

#endif // MYPIECES_H
