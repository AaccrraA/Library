#ifndef READERSHASH_H
#define READERSHASH_H

#include <QtCore>
#include <reader.h>

const qint32 TABLE_SIZE = 1024;

class ReadersHash {
private:
    QVector<Reader*>    map;
    static const qint32 HASH_SIZE = 1024;
    qint32              GenerateIndex(QString key);
    qint32              numberOfReaders;

public:
    ReadersHash();
    void                Add(Reader* r);
    QVector<Reader*>    SearchByCardNumber(QString cN);
    QVector<Reader*>    SearchByFIO(QString f);
    void                Delete(qint32 index);
    qint32              GetSize();
    qint32              GetNumberOfReaders();
    Reader*             At(qint32 index);
};

#endif // READERSHASHMAP_H
