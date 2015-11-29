#ifndef OVERLOADS
#define OVERLOADS

#include "person.h"
#include <QtCore>

QDataStream &operator <<(QDataStream &out, const Person &person);
QDataStream &operator >>(QDataStream &in, Person &person);

QDataStream &operator <<(QDataStream &out, const Person &person)
{
    // write a person class to the stream
    out << person.getAge() << person.getName();

    return out;
}

QDataStream &operator >>(QDataStream &in, Person &person)
{
    // read in a person class
    person = Person();
    int tempAge;
    QString tempName;
    in >> tempAge >> tempName;
    person.setAge(tempAge);
    person.setName(tempName);

    return in;
}

#endif // OVERLOADS

