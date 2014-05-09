#ifndef READERSHASHMAP_H
#define READERSHASHMAP_H

#include <QtCore>
#include <reader.h>

class ReadersHashMap
{
private:
    const int TABLE_SIZE = 1024;
    QVector<Reader*> map;

    int     GenerateIndex(QString key);

public:
    ReadersHashMap();
    ReadersHashMap(const int size);
    Reader*             Add(Reader* r);
    Reader*             SearchByCardNumber(QString cN);
    QVector<Reader*>    SearchByFIO(QString f);
    void                Delete(Reader* const& r);
};

#endif // READERSHASHMAP_H
