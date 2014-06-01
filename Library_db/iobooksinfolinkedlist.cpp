#include "iobooksinfolinkedlist.h"

IOBooksInfoLinkedList::IOBooksInfoLinkedList() {
    first = NULL;
}

void IOBooksInfoLinkedList::Add(IOBooksInfo *iobi) {
    if (!first) {
        first = iobi;
    }
    else {
        IOBooksInfo* temp = first;
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        temp->setNext(iobi);
        iobi->setPrev(temp);
    }
}

void IOBooksInfoLinkedList::setFirst(IOBooksInfo* iobi) {
    first = iobi;
}

IOBooksInfo* IOBooksInfoLinkedList::getFirst() {
    return first;
}

void IOBooksInfoLinkedList::Delete(qint32 index) {
    IOBooksInfo* temp = first;
    while (index != 0 && temp != NULL) {
        temp = temp->getNext();
        --index;
    }
    IOBooksInfo* ptemp = temp->getPrev();
    IOBooksInfo* ntemp = temp->getNext();
    delete temp;
    if (ptemp)
        ptemp->setNext(ntemp);
    else
        first = ntemp;
    if (ntemp)
        ntemp->setPrev(ptemp);
}

IOBooksInfo* IOBooksInfoLinkedList::AtIndex(qint32 index) {
    IOBooksInfo* r = this->getFirst();
    while (index != 0 || r != NULL) {
        r = r->getNext();
        index--;
    }
    return r;
}

