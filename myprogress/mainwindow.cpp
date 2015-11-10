#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int))); // connect SIGNAL/SLOT for slider and progress bar

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar_2,SLOT(setValue(int))); // connect SIGNAL/SLOT for slider and progress bar_2

    disconnect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int))); // disconnect SIGNAL/SLOT for slider and progress bar
}

MainWindow::~MainWindow()
{
    delete ui;
}
