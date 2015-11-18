#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList list;

    QString line = "Toyota,Honda,Mazda,Ford";

    list = line.split(","); // splits up by ',' and adds to list

    list.append("Subaru");

    list.replaceInStrings("Honda","Acura"); // replace honda with acura in the list

    qDebug() << "Contents of list: ";
    foreach(QString brand, list) {
        qDebug() << brand;
    }

    QString after = list.join(",");
    qDebug() << "Contents of list with ',' join: \n" << after;

    return a.exec();
}
