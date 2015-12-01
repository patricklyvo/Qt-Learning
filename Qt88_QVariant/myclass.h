#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtCore>

class myclass
{
public:
    myclass();
    int number;
};

Q_DECLARE_METATYPE(myclass);

#endif // MYCLASS_H
