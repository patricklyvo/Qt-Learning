#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("LOCALHOST\\SQLEXPRESS");
    db.setDatabaseName("mydsn64");

    if(db.open()) {
        qDebug() << "Opened!";
        db.close();
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }

    return a.exec();
}
