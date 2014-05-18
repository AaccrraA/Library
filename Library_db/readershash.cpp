#include "ReadersHash.h"

ReadersHash::ReadersHash() {
    // *********
    numberOfReaders = 0;
    map.resize(HASH_SIZE);
    map.fill(NULL);
}

qint32 ReadersHash::GenerateIndex(QString key) {
    qint32 index = 0;
    for (qint32 i = 0; i < key.length()-1; i++) {
        //index += key.at(i).unicode();
        index = index + key.at(i).unicode() * (static_cast<int>(qPow(i, 3.0)));
    }
    index %= TABLE_SIZE;
    return index;
}

void ReadersHash::Add(Reader* r) {
    qint32 index = GenerateIndex(r->getCardNumber());
    r->setHashIndex(index);
    Reader* temp = map.at(index);

    if (temp == NULL) {
        map.replace(index, r);
    }
    else {
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        temp->setNext(r);
        r->setPrev(temp);
        r->setNext(NULL);
    }
    numberOfReaders++;
}

Reader* ReadersHash::SearchByCardNumber(QString cN) {
    int index = GenerateIndex(cN);

    Reader* temp = map.at(index);
    bool isFounded = false;
    while (temp != NULL) {
        if (temp->getCardNumber() == cN) {
            isFounded = true;
            break;
        }
        temp = temp->getNext();
    }
    return isFounded ? temp : NULL;
}

QVector<Reader*> ReadersHash::SearchByFIO(QString f) {
    QVector<Reader*> result;
    Reader* r;
    for (int i = 0; i < map.size()-1; ++i) {
        r = map.at(i);
        while (r != NULL) {
            if (r->getFio() == f) {
                result.append(r);
            }
            r = r->getNext();
        }
    }
    return result;
}

void ReadersHash::Delete(qint32 index) {
    delete map.at(index);
    map.replace(index, NULL);
    --numberOfReaders;
}

Reader* ReadersHash::At(qint32 index) {
    return map.at(index);
}

int ReadersHash::GetSize() {
    return map.size();
}

int ReadersHash::GetNumberOfReaders() {
    return numberOfReaders;
}
