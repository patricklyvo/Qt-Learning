#include "dialog.h"
#include "ui_dialog.h"

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

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen1(Qt::black);
    pen1.setWidth(6);

    QPen pen2(Qt::red);
    pen2.setWidth(6);

    QPen pen3(Qt::green);
    pen3.setWidth(6);

    QPen pen4(Qt::blue);
    pen4.setWidth(6);

    QRect rec(100, 100, 100, 100);

    painter.setPen(pen1);
    painter.drawRect(rec);

    painter.translate(150, -60); // translate before rotating canvas to stack rectangles
    painter.rotate(45); // rotate canvas by 45 degrees
    painter.setPen(pen2);
    painter.drawRect(rec);

    painter.setPen(pen3);
    painter.scale(0.5, 0.5); // scale size of rectangle
    painter.drawRect(rec);

    painter.resetTransform(); // resets all transformations
    painter.shear(0.2, 0.2); // stretches object
    painter.setPen(pen4);
    painter.drawRect(rec);
}
