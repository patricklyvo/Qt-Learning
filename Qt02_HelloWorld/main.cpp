#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); // Creates instance of QCore Application

    QString helloString = "Hello World!";

    qDebug() << helloString;

    return a.exec();
}
