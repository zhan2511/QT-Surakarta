#ifndef MYNETWIDGET_H
#define MYNETWIDGET_H

#include <QWidget>
#include "myclientwindow.h"
#include "myserverwindow.h"

namespace Ui {
class MyNetWidget;
}

class MyNetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyNetWidget(QWidget *parent = nullptr);
    ~MyNetWidget();

    MyClientWindow* ClientWd;
    MyServerWindow* ServerWd;

signals:
    void mainshow();

private:
    Ui::MyNetWidget *ui;
};

#endif // MYNETWIDGET_H
