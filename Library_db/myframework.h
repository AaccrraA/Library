#ifndef MYFRAMEWORK_H
#define MYFRAMEWORK_H

#include <QtCore>
#include <QtGui>

#include "library.h"

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

// --- READERS HASH MAP --- //
class ReadersHashMap
{
private:
    const int TABLE_SIZE = 1024;
    QVector<Reader*> map;

    int     GenerateIndex(QString key);

public:
    ReadersHashMap();
    Reader*             Add(Reader* r);
    Reader*             SearchByCardNumber(string cN);
    QVector<Reader*>    SearchByFIO(string f);
    void                Delete(Reader* const& r);
};
#endif // MYFRAMEWORK_H
