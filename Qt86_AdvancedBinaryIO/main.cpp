#include <QCoreApplication>

#include <QtCore>
#include <QDebug>
#include "person.h"
#include "overloads.h"

void save()
{
    Person person1;
    person1.setAge(30);
    person1.setName("Bob");

    Person person2;
    person2.setAge(19);
    person2.setName("Sally");

    QFile file("C:/Users/Patrick/Desktop/people.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Could not open file.";
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_5);

    out << person1;
    out << person2;

    file.flush();
    file.close();
}

void load()
{
    Person person1;
    Person person2;

    QFile file("C:/Users/Patrick/Desktop/people.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open file.";
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_5);

    in >> person1;
    in >> person2;

    file.close();

    qDebug() << person1.getName() << " is " << person1.getAge();
    qDebug() << person2.getName() << " is " << person2.getAge();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //save();
    load();

    return a.exec();
}
