#include <QCoreApplication>
#include <QDebug>
#include <QHash>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<int, QString> employees;

    employees.insert(1, "Bob");
    employees.insert(2, "Joe");
    employees.insert(3, "Sally");

    qDebug() << "3 = " << employees.value(3);

    foreach(int i, employees.keys()) {
        qDebug() << employees[i];
    }

    QHashIterator<int, QString> it(employees);
    while(it.hasNext()) {
        it.next();
        qDebug() << it.key() << " = " << it.value();
    }

    return a.exec();
}
