#include "person.h"

Person::Person()
{

}

void Person::setAge(int age)
{
    this->age = age;
}

int Person::getAge() const
{
    return this->age;
}

void Person::setName(QString name)
{
    this->name = name;
}

QString Person::getName() const
{
    return this->name;
}

