#ifndef IOBOOKSINFO_H
#define IOBOOKSINFO_H

#include <QString>
using namespace std;

class IOBooksInfo
{
private:
    QString _libCardNumber;	/*строка формата «ANNNN-YY», где
                            A – права доступа читателя (А – только абонемент, Ч – только читальный зал, В – читальный зал и абонемент),
                            NNNN – порядковый номер регистрации (цифры),
                            YY – последние две цифры номера года регистрации;*/
    QString _code;           /*строка формата «NNN.MMM»,
                            где NNN – номер тематического раздела(цифры),
                            MMM – порядковый номер книги в разделе(цифры)*/
    QString _oDate;          // дата выдачи книги (dd.mm.yy)
    QString _iDate;          // дата приема книги (dd.mm.yy)
    IOBooksInfo* _next;
    IOBooksInfo* _prev;

public:
    IOBooksInfo();
    IOBooksInfo(QString libCardNumber,
                QString code,
                QString oDate,
                QString iDate,
                IOBooksInfo* next,
                IOBooksInfo* prev);
    void setLibCardNumber(QString libCardNumber);
    void setCode(QString code);
    void setODate(QString oDate);
    void setIDate(QString iDate);
    void setNext(IOBooksInfo* const& next);
    void setPrev(IOBooksInfo* const& next);
    QString     getLibCardNumber();
    QString     getCode();
    QString     getODate();
    QString     getIDate();
    IOBooksInfo* getNext();
    IOBooksInfo* getPrev();
};


#endif
