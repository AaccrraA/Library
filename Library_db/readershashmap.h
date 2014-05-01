#ifndef READERSHASHMAP_H
#define READERSHASHMAP_H

#include <QtCore>
#include <reader.h>

const int TABLE_SIZE = 256;

class ReadersHashMap
{
private:
    QVector<Reader*> map;

    int     GenerateIndex(QString key);

public:
    ReadersHashMap();
    void    Add(Reader* r);


};

#endif // READERSHASHMAP_H
