#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    statLabel = new QLabel(this);
    statProgress = new QProgressBar(this);

    ui->statusBar->addPermanentWidget(statLabel);
    ui->statusBar->addPermanentWidget(statProgress,1);
    statProgress->setTextVisible(false);
    statLabel->setText("Hello");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDo_Something_triggered()
{
    //ui->statusBar->showMessage("Hello",2000); // Stays for 2000 ms.
    ui->statusBar->showMessage("Hello");
    statProgress->setValue(45);
}
