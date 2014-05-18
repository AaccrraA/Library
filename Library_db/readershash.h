#ifndef READERSHASH_H
#define READERSHASH_H

#include <QtCore>
#include <reader.h>

const int TABLE_SIZE = 1024;

class ReadersHash {
private:
    QVector<Reader*>    map;
    static const qint32 HASH_SIZE = 1024;
    qint32              GenerateIndex(QString key);
    int                 numberOfReaders;

public:
    ReadersHash();
    void                Add(Reader* r);
    Reader*             SearchByCardNumber(QString cN);
    QVector<Reader*>    SearchByFIO(QString f);
    void                Delete(qint32 index);
    int                 GetSize();
    int                 GetNumberOfReaders();
    Reader*             At(qint32 index);

};

#endif // READERSHASHMAP_H
