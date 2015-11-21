#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("LOCALHOST\\SQLEXPRESS");
    db.setDatabaseName("mydsn64");

    db.open();

    model = new QSqlTableModel(this);
    model->setTable("People");
    model->select();

    qDebug() << model->lastError().text();
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}
