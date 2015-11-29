#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200, -200, 300, 300);

    QPen myPen = QPen(Qt::red);

    QLineF topLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF leftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF rightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF bottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(topLine, myPen);
    scene->addLine(leftLine, myPen);
    scene->addLine(rightLine, myPen);
    scene->addLine(bottomLine, myPen);

    int itemCount = 25;
    for (int i = 0; i < itemCount; i++)
    {
        MyItem *item = new MyItem();
        scene->addItem(item);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(100);
}

Dialog::~Dialog()
{
    delete ui;
}
