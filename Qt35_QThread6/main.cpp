#include <QCoreApplication>
#include "myobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // signals and slots are not meant to be run with QThread
    QThread cThread;
    MyObject cObject;

    cObject.doSetup(cThread);
    cObject.moveToThread(&cThread);

    cThread.start();

    return a.exec();
}
