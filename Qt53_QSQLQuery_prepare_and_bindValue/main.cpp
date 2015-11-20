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

        QString sQuery = "INSERT INTO [dbo].[People]([FirstName],[LastName]) VALUES(:first,:last)";

        QSqlQuery qry(db);

        qry.prepare(sQuery);

        qry.bindValue(":first","Bill");
        qry.bindValue(":last","Gates");

        if(qry.exec()) {
            qDebug() << "Record inserted.";
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
