#include "mysettingsdialog.h"
#include "ui_mysettingsdialog.h"

MySettingsDialog::MySettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MySettingsDialog)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->EscSettings,&QPushButton::clicked,this,&QDialog::close);

    setModal(1);

    ui->RoundTimeSpin->setWrapping(true);
    ui->GameTimeH->setWrapping(true);
    ui->GameTimeMin->setWrapping(true);
}

MySettingsDialog::~MySettingsDialog()
{
    delete ui;
}
