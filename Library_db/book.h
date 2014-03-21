#ifndef BOOK_H
#define BOOK_H

#include <QString>
using namespace std;

class Book
{
private:
    QString code;	/*строка формата «NNN.MMM»,
                    где NNN – номер тематического раздела(цифры),
                    MMM – порядковый номер книги в разделе(цифры)*/
    QString authors;
    QString title;
    QString publisher;
    int yearOfPublication;
    int allCopies; // Кол-во экземпляров всего
    int copiesInStock; // Кол-во экземпляров в наличии
public:
    Book();
    Book(QString c, QString t, QString p, int yOfP, int aC, int cIS);
};


#endif
