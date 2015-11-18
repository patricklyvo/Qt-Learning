#include <QCoreApplication>
#include <QDebug>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<int, QString> employees;

    employees.insert(1, "Bob");
    employees.insert(2, "Joe");
    employees.insert(3, "Sally");
    employees.insertMulti(1, "Mary");

    foreach(int i, employees.keys()) {
        qDebug() << employees[i];
    }

    QMapIterator<int, QString> it(employees);
    while(it.hasNext()) {
        it.next();
        qDebug() << it.key() << " = " << it.value();
    }

    return a.exec();
}
