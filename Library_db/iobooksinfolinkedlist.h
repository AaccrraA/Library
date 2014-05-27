#ifndef IOBOOKSINFOLINKEDLIST_H
#define IOBOOKSINFOLINKEDLIST_H

#include <QtCore>
#include "iobooksinfo.h"

class IOBooksInfoLinkedList
{
private:
    IOBooksInfo* first;
public:
    IOBooksInfoLinkedList();
    void Add(IOBooksInfo* iobi);
    void setFirst(IOBooksInfo* iobi);
    IOBooksInfo* getFirst();
    void Delete(qint32 index);
};

#endif // IOBOOKSINFOLINKEDLIST_H
