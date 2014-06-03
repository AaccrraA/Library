#include "iobooksinfolinkedlist.h"
#include "iobooksinfo.h"

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
        first = InsertionSort(first);
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
    first = InsertionSort(first);
}

IOBooksInfo* IOBooksInfoLinkedList::AtIndex(qint32 index) {
    IOBooksInfo* r = this->getFirst();
    while (index != 0 && r != NULL) {
        r = r->getNext();
        index--;
    }
    return r;
}

IOBooksInfo *IOBooksInfoLinkedList::InsertionSort(IOBooksInfo* f) {
    IOBooksInfo* tmp = f;
    while (tmp != NULL) {
        IOBooksInfo* tmp2 = tmp;
        while (tmp2->getPrev() != NULL && QString::localeAwareCompare(tmp2->getCardNumber(), tmp2->getPrev()->getCardNumber()) < 0) {
            SwapNeighbours(tmp2->getPrev(), tmp2);
        }
        tmp = tmp->getNext();
    }
    while(f->getPrev() != NULL) {
        f = f->getPrev();
    }
    return f;
}

bool IOBooksInfoLinkedList::SwapNeighbours(IOBooksInfo* l, IOBooksInfo* r) {
    bool isSwaped = true;

    if (l->getPrev() == r && l->getNext() == r) {
        IOBooksInfo* tmp = l;
        l = r;
        r = tmp;
    }

    if (l->getPrev())
        l->getPrev()->setNext(r);
    if (r->getNext())
        r->getNext()->setPrev(l);
    l->setNext(r->getNext());
    r->setNext(l);
    r->setPrev(l->getPrev());
    l->setPrev(r);

    return isSwaped;
}































