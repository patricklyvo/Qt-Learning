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

    QMutableListIterator<int> it(list);
    while(it.hasNext()) {
        int i = it.next();
        if(i == 5) {
            it.remove();
        }
    }

    it.toFront();

    while(it.hasNext()) {
        qDebug() << it.next();
    }

    return a.exec();
}
