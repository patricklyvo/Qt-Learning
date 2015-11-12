#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void Write(QString filename) {
    QFile mFile(filename);

    // If file could not be opened.
    if(!mFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Could not open file for writing.";
        return;
    }

    QTextStream out(&mFile);
    out << "A single sentence written to the file.";

    mFile.flush(); // Make sure everything is written to disk.
    mFile.close();
}

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


    QString mFile = "C:/Users/Patrick/Desktop/Qt/myfile.txt";
    Write(mFile);
    Read(mFile);

    return a.exec();
}
