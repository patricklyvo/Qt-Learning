#include <QCoreApplication>
#include <QtCore>
#include <QFile>
#include <QString>
#include <QMap>
#include <QDebug>

void save()
{
    int myNum = 22;
    QMap<qint64, QString> map;
    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    // save to disk
    QFile file("C:/Users/Patrick/Desktop/myfile.txt");

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Could not open file.";
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_5);

    out << myNum << map;

    file.flush();
    file.close();
}

void load()
{
    int myNum;
    QMap<qint64, QString> map;

    // load from disk
    QFile file("C:/Users/Patrick/Desktop/myfile.txt");

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open file.";
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_5);

    in >> myNum >> map;

    file.close();

    qDebug() << "myNum = " << myNum;

    foreach (QString item, map.values())
    {
        qDebug() << item;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //save();
    load();

    return a.exec();
}
