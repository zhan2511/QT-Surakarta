#ifndef MYPIECES_H
#define MYPIECES_H

#include <QPushButton>

class MyPieces : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPieces(QWidget *parent = nullptr);

signals:
};

#endif // MYPIECES_H
