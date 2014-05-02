#ifndef BOOK_H
#define BOOK_H

#include <QString>
using namespace std;

class Book
{
private:
    QString _code;              /*строка формата «NNN.MMM»,
                                где NNN – номер тематического раздела(цифры),
                                MMM – порядковый номер книги в разделе(цифры)*/
    QString _authors;
    QString _title;
    QString _publisher;
    int     _yearOfPublication;
    int     _allCopies;         // Кол-во экземпляров всего
    int     _copiesInStock;     // Кол-во экземпляров в наличии
    Book*   _left;
    Book*   _right;
public:
    Book();
    Book(QString const& c, QString const& t, QString const& p, int yOfP, int aC, int cIS);

};


#endif
