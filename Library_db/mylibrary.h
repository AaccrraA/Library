#ifndef MYLIBRARY_H
#define MYLIBRARY_H

// DL Linear List Item
template <typename T> class DLLinearListItem
{
private:
    T* date;
    T* next;
    T* prev;
    int index;

public:
    DLLinearListItem();
    DLLinearListItem(T* d, T* p, T* n);
    void    setDate(T* d);
    void    setNext(T* n);
    void    setPrev(T* p);
    T*    getDate();
    T*    getNext();
    T*    getPrev();
};

// Hash Map
template
#endif // MYLIBRARY_H
