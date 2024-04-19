#ifndef MYPAUSEDIALOG_H
#define MYPAUSEDIALOG_H

#include <QDialog>
#include <QPushButton>

class MyPauseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MyPauseDialog(QWidget *parent = nullptr);

    QPushButton *SaveGame;
    QPushButton *Quit;
    QPushButton *Back;
    QPushButton *Restart;


signals:
};

#endif // MYPAUSEDIALOG_H
