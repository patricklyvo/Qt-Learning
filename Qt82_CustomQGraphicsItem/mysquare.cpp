#include "mysquare.h"

MySquare::MySquare()
{
    pressed = false;
    setFlag(ItemIsMovable);
}

QRectF MySquare::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void MySquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    if(pressed)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::green);
    }

    painter->fillRect(rec, brush);
    painter->drawEllipse(rec);
    painter->drawRect(rec);
}

void MySquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MySquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

