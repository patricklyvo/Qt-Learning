#ifndef PERSON_H
#define PERSON_H

#include <QtCore>

class Person
{
public:
    Person();

    void setAge(int age);
    void setName(QString name);

    int getAge() const;
    QString getName() const;

private:
    int age;
    QString name;

};

#endif // PERSON_H
