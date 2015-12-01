#include <QCoreApplication>
#include <QtCore>
#include <QDebug>

void write()
{
    QFile file("C:/Users/Patrick/Desktop/myfile.txt");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream ts(&file);

        ts << "Hello\r\n";
        ts << "World!\r\n";

        ts.flush();
        file.close();
        qDebug() << "File written.";
    }
}

void read()
{
    QFile file("C:/Users/Patrick/Desktop/myfile.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream ts(&file);

        QString line;
        do
        {
            line = ts.readLine();
            qDebug() << line;
        } while (!line.isNull());

        file.close();
        qDebug() << "File read.";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    write();
    read();

    return a.exec();
}
