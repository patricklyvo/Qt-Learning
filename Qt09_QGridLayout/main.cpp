#include <QApplication>
#include <QtGui>
#include <QWidget>
#include <QTCore>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("My App");

    QGridLayout *layout = new QGridLayout;

    QLabel *label1 = new QLabel("Name: ");
    QLineEdit *txtName = new QLineEdit;

    QLabel *label2 = new QLabel("Name: ");
    QLineEdit *txtName2 = new QLineEdit;

    layout->addWidget(label1,0,0); // On row: 0, col: 0.
    layout->addWidget(txtName,0,1);

    layout->addWidget(label2,1,0);
    layout->addWidget(txtName2,1,1);

    QPushButton *button = new QPushButton("OK");

    layout->addWidget(button,2,0,1,2); // On row: 2, col: 1. Spans 1 row, 1 col.

    window->setLayout(layout);

    window->show();
    return app.exec();
}
