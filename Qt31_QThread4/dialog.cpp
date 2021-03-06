#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    mThread = new MyThread(this);
    connect(mThread,SIGNAL(numberChanged(int)),this,SLOT(onNumberChanged(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onNumberChanged(int number) {
    ui->label->setText(QString::number(number));
}

void Dialog::on_pushButton_clicked()
{
    // started button
    mThread->start();
}

void Dialog::on_pushButton_2_clicked()
{
    // stopped button
    mThread->stop = true;
}
