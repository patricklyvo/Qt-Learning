#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    for(int i = 0; i < 9; i++) {
        ui->listWidget->addItem(QString::number(i) + " item");
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QListWidgetItem *itm = ui->listWidget->currentItem();
    itm->setText("This is selected item.");
    itm->setTextColor(Qt::red);
    itm->setBackground(Qt::black);
}
