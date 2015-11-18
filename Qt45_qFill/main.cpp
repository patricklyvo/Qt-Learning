#include <QCoreApplication>
#include <QDebug>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<QString> vect(5);

    // empty vector before qFill
    qDebug() << "Before qFill:";
    foreach(QString itm, vect) {
        qDebug() << itm;
    }

    //qFill(vect,"Hello World!");
    qFill(vect.begin()+1,vect.end()-2,"PLACEHOLDER"); // range to fill in

    // vector after qFill
    qDebug() << "After qFill:";
    foreach(QString itm, vect) {
        qDebug() << itm;
    }

    return a.exec();
}
