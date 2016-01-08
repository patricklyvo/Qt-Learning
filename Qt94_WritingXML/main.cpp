#include <QCoreApplication>
#include <QtCore>
#include <QtXml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Write XML
    QDomDocument document;

    // Make the root element
    QDomElement root  = document.createElement("Books");

    // Add to the document
    document.appendChild(root);

    // Add some elements
    for (int i = 0; i < 10; i++) {
        QDomElement book = document.createElement("Book");
        book.setAttribute("Name", " My Book " + QString::number(i));
        book.setAttribute("ID", QString::number(i));
        root.appendChild(book);

        for (int j = 0; j < 10; j++) {
            QDomElement chapter = document.createElement("Chapter");
            chapter.setAttribute("Name", " My Chapter " + QString::number(j));
            chapter.setAttribute("ID", QString::number(j));
            book.appendChild(chapter);
        }
    }

    // Write to file
    QFile file("C:/Temp/MyXML.xml");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing.";
        return -1;
    } else {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Finished writing file.";
    }

    return a.exec();
}
