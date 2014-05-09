#include "library.h"
#include "reader.h"

Library::Library()
{
    readersHashMap_ = new ReadersHashMap(MY_HASHMAP_SIZE);
}
/*
void Library::AddReader(QString rOfA, QString f, int yOfB, QString a, QString jOrSP)
{
    QString cN = _gainCardNumber(rOfA);
    int ind = _gainHashTableIndex(cN);
    // --------- Нужна проверка на существующего читателя
    if (_readers[ind] == NULL)
    {
        _readers[ind] = new Reader(cN, f, yOfB, a, jOrSP, NULL, NULL);
    }
    else {
        while (_readers[ind]->getNext() != NULL)
            _readers[ind] = _readers[ind]->getNext();
        _readers[ind]->setNext(new Reader(cN, f, yOfB, a, jOrSP, _readers[ind], NULL));
    }
}

void Library::AddReader(Reader *reader) {
    // --- Search for copy --- //

}

int Library::_getNumberOfReaders()
{
    int numOfR = 0;
    for (int i = 0; i < _readers.size(); i++)
        if (_readers[i] != NULL)
            numOfR++;
    return numOfR;
}

int Library::_getRegistraitonNumber()
{
    int regNum = 0;
    for (int i = 0; i < _readers.size(); i++)
        if (_readers[i] != NULL)
        {
            regNum++;
        }

    return regNum;
}

QString Library::_gainCardNumber(QString rOfA)
{
    QString cN;
    cN += rOfA;
    QString regNumStr = QString::number(_getRegistraitonNumber());
    for(int i = 0; i < 4-regNumStr.length(); i++)
        cN += "0";
    cN += regNumStr;
    QDate date = QDate::currentDate();
    QString dateStr = date.toString();
    dateStr.remove(0, dateStr.length()-2);
    cN += "-" + dateStr;
    return cN;
}

int Library::_gainHashTableIndex(QString key)
{
    int index = 0;
    for(int i = 1; i < key.length()+1; i++)
    {
        index = index + key[i-1].unicode() * (static_cast<int>(qPow(i, 3.0)));
    }
    index %= 256;
    return index;
}
*/
