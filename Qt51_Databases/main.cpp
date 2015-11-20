#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
    QString serverName = "LOCALHOST\\SQLEXPRESS";
    QString dbName = "test";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); // universal driver

    db.setConnectOptions();

    //QString dsn = QString("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2,UID=sa;PWD=;").arg(serverName).arg(dbName);
    QString dsn = QString("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2,Trusted_Connection=Yes;").arg(serverName).arg(dbName);

    db.setDatabaseName(dsn);

    if(db.open()) {
        qDebug() << "Opened!";
        db.close();
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }
    */

    QString serverName = "LOCALHOST\\SQLEXPRESS";
    QString dbName = "test";
    QString connectionName = "MyDatabase";

    QString connectionTemplate = "DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;";

    QString connectionString = connectionTemplate.arg(serverName).arg(dbName);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", connectionName);

    db.setDatabaseName(connectionString);
    db.setUserName("sa");
    db.setPassword("test");

    if(db.open()) {
        qDebug() << "Opened!";
        db.close();
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }

    return a.exec();
}
