#include <QCoreApplication>
#include "mythread.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mThread;

    mThread.start();
    mThread.wait(); // waits for mThread to complete before running any other code
    qDebug() << "Done!";

    return a.exec();
}
