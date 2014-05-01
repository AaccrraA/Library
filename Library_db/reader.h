#ifndef READER_H
#define READER_H

#include <QString>
using namespace std;

class Reader
{
private:
    QString _cardNumber;		/*строка формата «ANNNN-YY», где
                            A – права доступа читателя (А – только абонемент, Ч – только читальный зал, В – читальный зал и абонемент),
                            NNNN – порядковый номер регистрации (цифры),
                            YY – последние две цифры номера года регистрации;*/
    QString _fio;
    int     _yearOfBirth;
    QString _adress;
    QString _jobOrStudyPlace;

public:
    Reader();
    Reader(QString const& cardNumber,
           QString const& fio,
           int const& yearOfBirth,
           QString const& adress,
           QString const& jobOrStudyPlace,
           Reader* const& previous);

    void setCardNumber      (QString const& cardNumber);
    void setFio             (QString const& fio);
    void setYearOfBirth     (int const& yearOfBirth);
    void setAdress          (QString const& adress);
    void setJobOrStudyPlace (QString const& jobOrStudyPlace);
    QString getCardNumber();
    QString getFio();
    int     getYearOfBirth();
    QString getAdress();
    QString getJobOrStudyPlace();
};


#endif
