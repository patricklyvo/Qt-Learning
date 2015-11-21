#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{

}

void Person::listen(QString words) {
    qDebug() << this->getName() << "says someone told me..." << words;
}

void Person::gossip(QString words) {
    qDebug() << this->name << " says " << words;
    emit speak(words);
}

void Person::setName(QString name) {
    this->name = name;
}

QString Person::getName() {
    return this->name;
}
