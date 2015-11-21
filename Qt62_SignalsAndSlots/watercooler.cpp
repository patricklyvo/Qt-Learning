#include "watercooler.h"
#include <person.h>

WaterCooler::WaterCooler(QObject *parent) : QObject(parent)
{
    Person sally;
    Person joe;
    Person jill;

    sally.setName("Sally");
    joe.setName("Joe");
    jill.setName("Jill");

    connect(&sally,SIGNAL(speak(QString)),&joe,SLOT(listen(QString))); // Sally speaks, Joe listens
    connect(&sally,SIGNAL(speak(QString)),&jill,SLOT(listen(QString))); // Sally speaks, Jill listens

    sally.gossip("I heard Will wears a wig.");
}

