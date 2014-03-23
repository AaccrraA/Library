#ifndef READER_H
#define READER_H

#include <QString>
using namespace std;

class Reader
{
private:
    QString cardNumber;		/*строка формата «ANNNN-YY», где
                            A – права доступа читателя (А – только абонемент, Ч – только читальный зал, В – читальный зал и абонемент),
                            NNNN – порядковый номер регистрации (цифры),
                            YY – последние две цифры номера года регистрации;*/
    QString fio;
    int yearOfBirth;
    QString adress;
    QString jobOrStudyPlace;
    Reader* next;
    Reader* previous;

public:
    Reader();
    Reader(QString cN, QString f, int yOfB, QString a, QString jOrSP);
    Reader* getNext();
    Reader* getPrevious();
    void setNext(Reader* n);
    void setPrevious(Reader* p);
};


#endif
