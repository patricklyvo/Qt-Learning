#include <QCoreApplication>
#include <QDebug>
#include <QStringList>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList list;
    list << "Acura" << "Lexus" << "Mercedes";

    QVector<QString> vect(3);

    //qCopy(list.begin(),list.end(),vect.begin()); // copies start - end of list to vect
    qCopy(list.begin() + 1,list.end(),vect.begin()); // will leave a blank because only copying 2 items into vect which is size 3

    foreach(QString brand, vect) {
        qDebug() << brand;
    }

    return a.exec();
}
