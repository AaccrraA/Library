#include "mylibrary.h"

// DL Linear List Item
DLLinearListItem::DLLinearListItem() {
    this->date = NULL;
    this->next = NULL;
    this->prev = NULL;
}

DLLLinearListItem::DLLinearListItem(T* d, T* p, T* n) {
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
