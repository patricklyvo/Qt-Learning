#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void Read(QString filename) {
    QFile mFile(filename);

    // If file could not be opened.
    if(!mFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Could not open file for reading.";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;

    mFile.close();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Read(":/MyFiles/Qt13_ResourceFiles.pro");

    return a.exec();
}
