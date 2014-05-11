#include "readershashmap.h"

ReadersHashMap::ReadersHashMap() {
    // *********
    numberOfReaders = 0;
    map.resize(HASHMAP_SIZE);
}

int ReadersHashMap::GenerateIndex(QString key) {
    int index = 0;
    for (int i = 0; i < key.length()-1; i++) {
        //index += key.at(i).unicode();
        index = index + key.at(i).unicode() * (static_cast<int>(qPow(i, 3.0)));
    }
    index %= TABLE_SIZE;
    return index;
}

void ReadersHashMap::Add(Reader* r) {
    int index = GenerateIndex(r->getCardNumber());
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
}

Reader* ReadersHashMap::SearchByCardNumber(QString cN) {
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

QVector<Reader*> ReadersHashMap::SearchByFIO(QString f) {
    QVector<Reader*> result;
    foreach (Reader* r, map) {
        while (r != NULL) {
            if (r->getFio() == f) {
                result.append(r);
                r = r->getNext();
            }
        }
    }
    return result;
}

void ReadersHashMap::Delete(Reader* const& r) {
    if (r->getPrev() != NULL) {
        r->getPrev()->setNext(r->getNext());
        map.replace(GenerateIndex(r->getCardNumber()), r->getNext());
    }
    if (r->getNext() != NULL) {
        r->getNext()->setPrev(r->getPrev());
    }
    // *************
    numberOfReaders--;
    delete r;
}

int ReadersHashMap::GetSize() {
    return map.size();
}

int ReadersHashMap::GetNumberOfReaders() {
    return numberOfReaders;
}
