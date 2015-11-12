#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir mDir("C:/Users/Patrick/Desktop/");
    //QDir mDir;

    // Lists files or directories of mDir.
    foreach(QFileInfo mItm, mDir.entryInfoList())
    {
        //qDebug() << mItm.absoluteFilePath();
        if(mItm.isDir())
        {
            qDebug() << "Dir:" << mItm.absoluteFilePath();
        }
        else if (mItm.isFile())
        {
            qDebug() << "File:" << mItm.absoluteFilePath();
        }
    }

    /* Checks to see if mPath exists and creates it if it doesn't.
    QString mPath = "C:/Users/Patrick/Desktop/Test";
    if(!mDir.exists(mPath))
    {
        mDir.mkpath(mPath);
        qDebug() << "Created path" << mPath;
    }
    else
    {
        qDebug() << "Path" << mPath << "already exists!";
    }
    */

    /* Lists all drives.
    foreach(QFileInfo mItm, mDir.drives())
    {
        qDebug() << mItm.absoluteFilePath();
    }
    */

    return a.exec();
}
