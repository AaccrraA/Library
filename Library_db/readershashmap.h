#ifndef READERSHASHMAP_H
#define READERSHASHMAP_H

#include <QtCore>
#include <reader.h>

const int TABLE_SIZE = 1024;

class ReadersHashMap {
private:
    QVector<Reader*> map;
    static const int HASHMAP_SIZE = 1024;
    int              GenerateIndex(QString key);
    int              numberOfReaders;

public:
    ReadersHashMap();
    void                Add(Reader* r);
    Reader*             SearchByCardNumber(QString cN);
    QVector<Reader*>    SearchByFIO(QString f);
    void                Delete(Reader* const& r);
    int                 GetSize();
    int                 GetNumberOfReaders();
};

#endif // READERSHASHMAP_H
