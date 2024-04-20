#ifndef MYSETTINGSDIALOG_H
#define MYSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class MySettingsDialog;
}

class MySettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MySettingsDialog(QWidget *parent = nullptr);
    ~MySettingsDialog();

public:
    Ui::MySettingsDialog *ui;
};

#endif // MYSETTINGSDIALOG_H
