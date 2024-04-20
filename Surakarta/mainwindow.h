#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chess_window.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    chess_window * chessboard = nullptr;

    int roundtime=30;
    int gamehour=0;//设置移动总时间 h
    int gamemin=40;//设置移动总时间 min

public slots:
    void SetRoundTime(int sec);
    void SetGameHour(int h);
    void SetGameMin(int min);

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:

    // QWidget interface
protected:
    // void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
