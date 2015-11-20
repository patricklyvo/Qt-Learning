#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

        QSqlQuery qry(db);

        if(qry.exec("SELECT * FROM [test].[dbo].[People]")) {
            while(qry.next()) {
                qDebug() << qry.value(1).toString();
            }
        } else {
            qDebug() << "Error: " << db.lastError().text();
        }

        qDebug() << "Closing...";
        db.close();
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }

    return a.exec();
}
