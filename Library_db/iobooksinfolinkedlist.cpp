#include "iobooksinfolinkedlist.h"

IOBooksInfoLinkedList::IOBooksInfoLinkedList() {
}

void IOBooksInfoLinkedList::Add(IOBooksInfo *iobi) {
    IOBooksInfo* temp = first;
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
    }
    temp->setNext(iobi);
    iobi->setPrev(temp);
}
