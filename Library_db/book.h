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
    QString getCode() const;
    QString getAuthors() const;
    QString getTitle() const;
    QString getPublisher() const;
    QString getYearOfPublication() const;
    QString getAllCopies() const;
    QString getCopiesInStock() const;
    quint8  getHeight() const;
    Book*   getLeft() const;
    Book*   getRight() const;
    bool IsEqualTo(const Book* right){
        return (this->getAuthors() == right->getAuthors() &&
                this->getTitle() == right->getTitle() &&
                this->getPublisher() == right->getPublisher() &&
                this->getYearOfPublication() == right->getYearOfPublication());
    }
};


#endif
