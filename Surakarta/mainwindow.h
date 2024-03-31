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

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:

    // QWidget interface
protected:
    // void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
