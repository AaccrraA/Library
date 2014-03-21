#ifndef IOBOOKSINFO_H
#define IOBOOKSINFO_H

#include <QString>
using namespace std;

class IOBooksInfo
{
private:
    QString libCardNumber;	/*строка формата «ANNNN-YY», где
                            A – права доступа читателя (А – только абонемент, Ч – только читальный зал, В – читальный зал и абонемент),
                            NNNN – порядковый номер регистрации (цифры),
                            YY – последние две цифры номера года регистрации;*/
    QString code;	/*строка формата «NNN.MMM»,
                    где NNN – номер тематического раздела(цифры),
                    MMM – порядковый номер книги в разделе(цифры)*/
    QString oDate; // дата выдачи книги (dd.mm.yy)
    QString iDate; // дата приема книги (dd.mm.yy)

public:
    IOBooksInfo(QString lCN, QString c, QString oD, QString iD);
};


#endif
