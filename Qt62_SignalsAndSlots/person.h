#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QDebug>

class Person : public QObject
{
    Q_OBJECT // macro
public:
    explicit Person(QObject *parent = 0);

    void gossip(QString words);

    void setName(QString name);

    QString getName();

private:
    QString name;

signals:
    void speak(QString words); // don't need to implement signal

public slots:
    void listen(QString words); // need to implement slot, slot consumes signal
};

#endif // PERSON_H
