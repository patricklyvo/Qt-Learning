#include <QCoreApplication>
#include <QtXml>
#include <QDebug>
#include <QtCore>

// reading XML with Document Object Model (DOM)

void listElements(QDomElement root, QString tagName, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagName);

    qDebug() << "Total items = " << items.count();

    for (int i = 0; i < items.count(); i++) {
        QDomNode itemNode = items.at(i);

        // convert to element
        if (itemNode.isElement()) {
            QDomElement itemElement = itemNode.toElement();
            qDebug() << itemElement.attribute(attribute);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument document;

    // load file
    QFile file("C:/Temp/MyXML.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file.";

        return -1;
    } else {
        if (!document.setContent(&file)) {
            qDebug() << "Failed to load document.";

            return -1;
        }
        file.close();
    }

    // get the root element
    QDomElement root = document.firstChildElement();

    // list the books
    listElements(root, "Book", "Name");

    qDebug() << "\r\nMore Advanced\r\n";

    // get the chapters
    QDomNodeList books = root.elementsByTagName("Book");
    for (int i = 0; i < books.count(); i++) {
        QDomNode bookNode = books.at(i);

        //convert to an element
        if (bookNode.isElement()) {
            QDomElement book = bookNode.toElement();
            qDebug() << "Chapters in " << book.attribute("Name");
            listElements(book, "Chapter", "Name");
        }
    }

    qDebug() << "Finished.";

    return a.exec();
}
