#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include <QMainWindow>

class chess_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit chess_window(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

signals:
};

#endif // CHESS_WINDOW_H
