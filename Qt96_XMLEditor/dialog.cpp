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
    QDomNodeList books = xmlRoot.elementsByTagName("Book");
    for (int i = 0; i < books.count(); i++) {
        QDomElement book = books.at(i).toElement();
        QStandardItem *bookItem = new QStandardItem(book.attribute("Name"));

        // read chapters of book
        QDomNodeList chapters = book.elementsByTagName("Chapter");
        for (int j = 0; j < chapters.count(); j++) {
            QDomElement chapter = chapters.at(j).toElement();
            QStandardItem *chapterItem = new QStandardItem(chapter.attribute("Name"));

            bookItem->appendRow(chapterItem);
        }

        root->appendRow(bookItem);
    }
}

void Dialog::writeFile()
{
    // write xml file

    QDomDocument document;

    // make a root node
    QDomElement xmlRoot = document.createElement("Books");
    document.appendChild(xmlRoot);

    QStandardItem *root = model->item(0, 0);
    for (int i = 0; i < root->rowCount(); i++) {
        QStandardItem *book = root->child(i, 0);

        QDomElement xmlBook = document.createElement("Book");
        xmlBook.setAttribute("Name", book->text());
        xmlBook.setAttribute("ID", i);
        xmlRoot.appendChild(xmlBook);

        for (int j = 0; j < book->rowCount(); j++) {
            QStandardItem *chapter = book->child(j, 0);
            QDomElement xmlChapter = document.createElement("Chapter");
            xmlChapter.setAttribute("Name", chapter->text());
            xmlChapter.setAttribute("ID", j);
            xmlBook.appendChild(xmlChapter);
        }
    }

    // save to disk (file is small so no need to buffer save)
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to write file.";
    }

    QTextStream stream(&file);
    stream << document.toString();
    file.close();

    qDebug() << "Finished writing file.";

}

void Dialog::on_pushButton_clicked()
{
    // save document
    writeFile();
}
