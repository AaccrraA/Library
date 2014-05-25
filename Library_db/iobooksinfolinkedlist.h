#ifndef IOBOOKSINFOLINKEDLIST_H
#define IOBOOKSINFOLINKEDLIST_H

#include "iobooksinfo.h" b

class IOBooksInfoLinkedList
{
private:
    IOBooksInfo* first;
public:
    IOBooksInfoLinkedList();
    void Add(IOBooksInfo* iobi);
};

#endif // IOBOOKSINFOLINKEDLIST_H
