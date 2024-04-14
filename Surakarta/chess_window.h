#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include <QMainWindow>
#include "mypieces.h"
#include "surakarta/surakarta_common.h"

class chess_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit chess_window(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
    void setboard(std::shared_ptr<SurakartaBoard> board);

    std::vector<MyPieces*> pieces;

signals:
    void select(int pos);
    void moveend(int pos);
};

#endif // CHESS_WINDOW_H
