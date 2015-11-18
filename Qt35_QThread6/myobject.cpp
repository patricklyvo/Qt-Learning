#include "myobject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::doSetup(QThread &cThread) {
    connect(&cThread,SIGNAL(started()),this,SLOT(doWork()));
}

void MyObject::doWork() {
    for(int i = 0; i < 100; i++) {
        qDebug() << i;
    }
}
