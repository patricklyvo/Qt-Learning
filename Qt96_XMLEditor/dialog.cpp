#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // create the model
    filename = "C:/Temp/MyXML.xml";
    model = new QStandardItemModel(0, 1, this);

    readFile();

    ui->treeView->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::readFile()
{
    QStandardItem *root = new QStandardItem("Books");
    model->appendRow(root);

    QDomDocument document;

    // load xml file
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        document.setContent(&file);
        file.close();
    }

    // get the xml root element
    QDomElement xmlRoot = document.firstChildElement();

    // read the books
    QDomNodeList books = xmlRoot.elementsByTagName("Books");
    for (int i = 0; i < books.count(); i++) {
        QDomElement book = books.at(i).toElement();
        QStandardItem *bookItem = new QStandardItem(book.attribute("Name"));

        // read chapters of book
        QDomNodeList chapters = book.elementsByTagName("Chapter");
        for (int j = 0; j < chapters.count(); j++) {
            QDomElement chapter = books.at(j).toElement();
            QStandardItem *chapterItem = new QStandardItem(chapter.attribute("Name"));

            bookItem->appendRow(chapterItem);
        }

        root->appendRow(bookItem);
    }
}

void Dialog::writeFile()
{

}

void Dialog::on_pushButton_clicked()
{
    // save document
}
