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
    Book(QString    code,
         QString    authors,
         QString    title,
         QString    publisher,
         int        yearOfPublication,
         int        allCopies,
         int        copiesInStock,
         Book*      const& left,
         Book*      const& right
         );
    void setCode(QString code);
    void setAuthors(QString authors);
    void setTitle(QString title);
    void setPublisher(QString publisher);
    void setYearOfPublication(QString yearOfPublication);
    void setAllCopies(int allCopies);
    void setCopiesInStock(int copiesInStock);
    void setLeft(Book* const& left);
    void setRight(Book* const& right);
    QString getCode();
    QString getAuthors();
    QString getTitle();
    QString getPublisher();
    QString getYearOfPublication();
    int     getAllCopies();
    int     getCopiesInStock();
    Book*   getLeft();
    Book*   getRight();
};


#endif
