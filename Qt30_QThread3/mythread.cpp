#include "mythread.h"
#include <QtCore>
#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run() {
    qDebug() << this->name << ": Running...";

    for (int i = 0; i < 1000; i++) {
        QMutex mutex; // mutex to prevent multiple threads from modifying/reading bool stop
        mutex.lock();
        if(this->stop) {
            break;
        }
        mutex.unlock();

        this->sleep(1); // slows thread down
        qDebug() << this->name << i;
    }
}
