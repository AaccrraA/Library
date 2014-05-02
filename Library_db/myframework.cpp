#include "myframework.h"

// --- DL LINEAR LIST ITEM --- //
DLLinearListItem::DLLinearListItem() {
    this->date = NULL;
    this->next = NULL;
    this->prev = NULL;
}

DLLinearListItem::DLLinearListItem(T* d, T* p, T* n) {
    this->date = d;
    this->next = p;
    this->prev = n;
}

void DLLinearListItem::setDate(T* d) {
    this->date = d;
}

void DLLinearListItem::setNext(T* n) {
    this->next = n;
}

void DLLinearListItem::setPrev(T* p) {
    this->prev = p;
}

T* DLLinearListItem::getDate() {
    return this->date;
}

T* DLLinearListItem::getNext() {
    return this->next;
}

T* DLLinearListItem::getPrev() {
    return this->prev;
}

// --- READERS HASH MAP --- //
ReadersHashMap::ReadersHashMap() {
    map.resize(TABLE_SIZE);
}

int ReadersHashMap::GenerateIndex(QString key) {
    int index = 0;
    for (int i = 0; i < key.length()-1; i++) {
        index += key.at(i).unicode();
    }
    index %= TABLE_SIZE;
    return index;
}

Reader* ReadersHashMap::Add(Reader* r) {
    int index = GenerateIndex(r->getCardNumber());
    Reader* temp = map.at(index);

    if (temp == NULL) {
        map.replace(index, r);
    }
    else {
        while (temp->getNext() != NULL) {
            if (temp->getCardNumber() != r->getCardNumber()) {
                temp = temp->getNext();
            }
            else {
                return NULL;
            }
        }
        temp->setNext(r);
        r->setPrev(temp);
        r->setNext(NULL);
    }
    return r;
}

Reader* ReadersHashMap::SearchByCardNumber(string cN) {
    int index = GenerateIndex(cN);
    Reader* temp = map.at(index);
    while (temp != NULL) {
        if (temp->getCardNumber() == cN) {
            break;
        }
    }
    return temp;
}

QVector<Reader*> ReadersHashMap::SearchByFIO(string f) {
    QVector<Reader*> result;
    foreach (Reader* r, map) {
        while (r != NULL) {
            if (r->getFio() == f) {
                result.append(r);
                r = r->getNext();
            }
        }
    }
    return result;
}

void ReadersHashMap::Delete(Reader* const& r) {
    if (r->getPrev() != NULL) {
        r->getPrev()->setNext(r->getNext());
        map.replace(GenerateIndex(r->getCardNumber()), r->getNext());
    }
    if (r->getNext() != NULL) {
        r->getNext()->setPrev(r->getPrev());
    }
    delete r;
}



















