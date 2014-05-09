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
    int     _yearOfBirth;
    QString _adress;
    QString _jobOrStudyPlace;
    Reader* _next;
    Reader* _prev;

public:
    Reader();
    Reader(QString const&   cardNumber,
           QString const&   fio,
           int              yearOfBirth,
           QString const&   adress,
           QString const&   jobOrStudyPlace,
           Reader* const&   next,
           Reader* const&   prev
           );
    void    setCardNumber (QString const& cardNumber);
    void    setFio (QString const& fio);
    void    setYearOfBirth (int yearOfBirth);
    void    setAdress (QString const& adress);
    void    setJobOrStudyPlace (QString const& jobOrStudyPlace);
    void    setNext(Reader* const& n);
    void    setPrev(Reader* const& p);
    QString getCardNumber();
    QString getFio();
    int     getYearOfBirth();
    QString getAdress();
    QString getJobOrStudyPlace();
    Reader* getNext();
    Reader* getPrev();
};

#endif
