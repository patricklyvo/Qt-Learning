#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    loadSettings();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::saveSettings()
{
    // save
    QSettings setting("MyCompany", "myapp");
    setting.beginGroup("MainWindow");
    // save window size
    setting.setValue("position", this->geometry());
    setting.endGroup();

    qDebug() << "Saved.";
}

void Dialog::loadSettings()
{
    // load
    QSettings setting("MyCompany", "myapp");
    setting.beginGroup("MainWindow");
    // load window size
    QRect rect = setting.value("position").toRect(); // should include default position
    setGeometry(rect);
    setting.endGroup();

    qDebug() << "Loaded.";
}

void Dialog::on_pushButton_clicked()
{
    // save
    saveSettings();
}

void Dialog::on_pushButton_2_clicked()
{
    // load
    loadSettings();
}
