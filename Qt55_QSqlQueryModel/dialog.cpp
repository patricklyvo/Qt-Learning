#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("LOCALHOST\\SQLEXPRESS");
    db.setDatabaseName("mydsn64");

    db.open();

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT [ID],[FirstName],[LastName] FROM [test].[dbo].[People]");

    ui->tableView->setModel(model);
}

Dialog::~Dialog()
{
    db.close();
    delete ui;
}
