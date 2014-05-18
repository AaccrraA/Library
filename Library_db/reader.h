#ifndef READER_H
#define READER_H

#include <QString>

class Reader
{
private:
    QString _cardNumber;	/*строка формата «ANNNN-YY», где
                            A – права доступа читателя (А – только абонемент, Ч – только читальный зал, В – читальный зал и абонемент),
                            NNNN – порядковый номер регистрации (цифры),
                            YY – последние две цифры номера года регистрации;*/
    QString _fio;
    QString _yearOfBirth;
    QString _adress;
    QString _jobOrStudyPlace;
    qint32  _hashIndex;
    Reader* _next;
    Reader* _prev;

public:
    Reader();
    Reader(QString cardNumber,
           QString fio,
           QString yearOfBirth,
           QString adress,
           QString jobOrStudyPlace,
           Reader* next,
           Reader* prev
           );
    void    setCardNumber (QString cardNumber);
    void    setFio (QString fio);
    void    setYearOfBirth (QString yearOfBirth);
    void    setAdress (QString adress);
    void    setJobOrStudyPlace (QString  jobOrStudyPlace);
    void    setHashIndex(qint32 hashIndex);
    void    setNext(Reader* n);
    void    setPrev(Reader* p);
    QString getCardNumber();
    QString getFio();
    QString getYearOfBirth();
    QString getAdress();
    QString getJobOrStudyPlace();
    qint32  getHashIndex();
    Reader* getNext();
    Reader* getPrev();
};

#endif
