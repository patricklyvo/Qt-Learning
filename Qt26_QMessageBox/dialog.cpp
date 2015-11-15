#include "dialog.h"
#include "ui_dialog.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    // Information
    QMessageBox::information(this,"Title","Text here.");
}

void Dialog::on_pushButton_2_clicked()
{
    // Question
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this,"Title","Are you a car enthusiast?",QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        QMessageBox::information(this,"Title","You LOVE cars!");
    }
}

void Dialog::on_pushButton_3_clicked()
{
    // Warning
    QMessageBox::warning(this,"Title","Text here.");
}

void Dialog::on_pushButton_4_clicked()
{
    // Custom
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"My Title","MyText here",QMessageBox::YesToAll | QMessageBox::Yes | QMessageBox::No | QMessageBox::NoToAll);
}
