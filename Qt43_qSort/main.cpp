#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;

    list << 2 << 3 << 1 << 0;

    qDebug() << "Before using qSort:";
    foreach(int i, list) {
        qDebug() << i;
    }

    qSort(list);
    //qSort(list.begin() + 1, list.end() - 1); // to sort in between a range

    qDebug() << "After using qSort:";
    foreach(int j, list) {
        qDebug() << j;
    }


    return a.exec();
}
