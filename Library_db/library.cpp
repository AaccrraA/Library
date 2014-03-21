#include "library.h"
#include "reader.h"

#include <QString>
#include <QDateTime>
#include <QDebug>
#include <QChar>
#include <qmath.h>

Library::Library()
{
    readers.resize(HTSize);
}

void Library::AddReader(QString rOfA, QString f, int yOfB, QString a, QString jOrSP)
{
    QString cN = getCardNumber(rOfA);
    int ind = getHashIndex(cN);
    // ----------------- Нужна проверка на существующего читателя
    if (readers[ind] == NULL)
    {
        readers[ind] = new Reader(cN, f, yOfB, a, jOrSP);
    }
    else {
        while (readers[ind]->getNext() != NULL)
            readers[ind] = readers[ind]->getNext();
        readers[ind]->setNext(new Reader(cN, f, yOfB, a, jOrSP));
    }
}

int Library::getNumberOfReaders()
{
    int numOfR = 0;
    for (int i = 0; i < readers.size(); i++)
        if (readers[i] != NULL)
            numOfR++;
    return numOfR;
}

int Library::getRegistraitonNumber()
{
    int regNum = 0;
    for (int i = 0; i < readers.size(); i++)
        if (readers[i] != NULL)
        {
            regNum = i+1;
            break;
        }

    return regNum;
}

QString Library::getCardNumber(QString rOfA)
{
    /*строка формата «ANNNN-YY», где
                                A – права доступа читателя (А – только абонемент, Ч – только читальный зал, В – читальный зал и абонемент),
                                NNNN – порядковый номер регистрации (цифры),
                                YY – последние две цифры номера года регистрации;*/
    QString cN;
    cN += rOfA;
    QString regNumStr = QString::number(getRegistraitonNumber());
    for(int i = 0; i < 4-regNumStr.length(); i++)
        cN += "0";
    cN += regNumStr;
    QDateTime date = QDateTime::currentDateTime();
    QString dateStr = date.toString();
    dateStr.remove(0, dateStr.length()-2);
    cN += "-" + dateStr;
    return cN;
}

int Library::getHashIndex(QString key)
{
    int index = 0;
    for(int i = 1; i < key.length()+1; i++)
    {
        index = index + key[i-1].unicode() * (static_cast<int>(qPow(i, 3.0)));
    }
    index %= HTSize;
    return index;
}
