#include "Reader.h"

#include <QString>

Reader::Reader()
{

}

Reader::Reader(QString cN, QString f, int yOfB, QString a, QString jOrSP)
{
    cardNumber = cN;
    fio = f;
    yearOfBirth = yOfB;
    adress = a;
    jobOrStudyPlace = jOrSP;
    next = NULL;
}

Reader* Reader::getNext()
{
    return next;
}

void Reader::setNext(Reader* n)
{
    next = n;
}
