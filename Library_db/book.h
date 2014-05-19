#ifndef BOOK_H
#define BOOK_H

#include <QtCore>
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
    QString _yearOfPublication;
    QString _allCopies;         // Кол-во экземпляров всего
    QString _copiesInStock;     // Кол-во экземпляров в наличии
    quint8  _height;
    Book*   _left;
    Book*   _right;

public:
    Book();
    Book(QString    code,
         QString    authors,
         QString    title,
         QString    publisher,
         QString    yearOfPublication,
         QString    allCopies,
         QString    copiesInStock
         );
    void setCode(QString code);
    void setAuthors(QString authors);
    void setTitle(QString title);
    void setPublisher(QString publisher);
    void setYearOfPublication(QString yearOfPublication);
    void setAllCopies(QString allCopies);
    void setCopiesInStock(QString copiesInStock);
    void setHeight(quint8 height);
    void setLeft(Book *left);
    void setRight(Book* right);
    QString getCode();
    QString getAuthors();
    QString getTitle();
    QString getPublisher();
    QString getYearOfPublication();
    QString getAllCopies();
    QString getCopiesInStock();
    quint8  getHeight();
    Book*   getLeft();
    Book*   getRight();
};


#endif
