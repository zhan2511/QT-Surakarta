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

signals:
};

#endif // MYPIECES_H
