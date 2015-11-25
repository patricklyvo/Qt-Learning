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

    // make our polygon
    QPolygon poly;
    poly << QPoint(10, 10);
    poly << QPoint(10, 100);
    poly << QPoint(100, 10);
    poly << QPoint(100, 100);

    // make a pen
    QPen linePen;
    linePen.setWidth(8);
    linePen.setColor(Qt::red);
    //linePen.setJoinStyle(Qt::RoundJoin);
    linePen.setJoinStyle(Qt::MiterJoin);
    linePen.setStyle(Qt::DotLine);
    painter.setPen(linePen);

    // make a brush
    QBrush fillBrush;
    fillBrush.setColor(Qt::green);
    fillBrush.setStyle(Qt::SolidPattern);

    // fill the polygon
    QPainterPath path;
    path.addPolygon(poly);
    painter.fillPath(path, fillBrush);

    // draw polygon
    painter.drawPolygon(poly);

}
