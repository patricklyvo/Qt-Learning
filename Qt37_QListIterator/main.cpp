#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;

    for(int i = 0; i < 10; i++) {
        list.append(i);
    }

    qDebug() << "Forwards!";

    QListIterator<int> it(list);

    while (it.hasNext()) {
        qDebug() << it.next();
    }

    qDebug() << "Now backwards!";

    QListIterator<int> it2(list);
    it2.toBack();

    while (it2.hasPrevious()) {
        qDebug() << it2.previous();
        if(it2.hasPrevious()) { // peek before iterating
            qDebug() << "previous... " << it2.peekPrevious();
        }
    }

    return a.exec();
}
