#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list << 1 << 5 << 15 << 23;

    // instead of using a for loop, use find
    QList<int>::const_iterator it = qFind(list.begin(),list.end(),15); // returns list.end if value not found

    if(it != list.end()) {
        qDebug() << "Found: " << *it;
    } else {
        qDebug() << "Not found";
    }

    return a.exec();
}
