#ifndef MYFRAMEWORK_H
#define MYFRAMEWORK_H

#include <QtCore>
#include <QtGui>

// --- READERS HASH MAP --- //


// --- DL LINEAR LIST ITEM --- //
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


#endif // MYFRAMEWORK_H
