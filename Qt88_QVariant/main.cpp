#include <QCoreApplication>

#include <QVariant>
#include <QDebug>
#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariant v = 123.02;

    qDebug() << v.toInt();
    qDebug() << v.toDouble();

    if (v.canConvert<QString>())
    {
        qDebug() << v.toString();
    }

    myclass cClass;
    cClass.number = 321;

    QVariant z = QVariant::fromValue(cClass);
    myclass zClass = z.value<myclass>();

    qDebug() << zClass.number;

    return a.exec();
}
