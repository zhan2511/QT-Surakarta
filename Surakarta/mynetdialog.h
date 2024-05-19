#ifndef MYNETDIALOG_H
#define MYNETDIALOG_H

#include <QDialog>
#include "myclientwindow.h"
#include "myserverwindow.h"

namespace Ui {
class MyNetDialog;
}


class MyNetDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MyNetDialog(QWidget *parent = nullptr);
    ~MyNetDialog();

    MyClientWindow* ClientWd;
    MyServerWindow* ServerWd;

public:
    Ui::MyNetDialog *ui;

signals:
    void mainshow();
};

#endif // MYNETDIALOG_H
