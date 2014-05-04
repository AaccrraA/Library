#include "Book.h"

#include <QString>

Book::Book(QString    code,
           QString    authors,
           QString    title,
           QString    publisher,
           int        yearOfPublication,
           int        allCopies,
           int        copiesInStock,
           Book*      const& left,
           Book*      const& right)
{
    _code = code;
    _authors = authors;
    _title = title;
    _publisher = publisher;
    _yearOfPublication = yearOfPublication;
    _allCopies = allCopies;
    _copiesInStock = copiesInStock;
    _left = left;
    _right = right;
}

/*
void Book::setCode(QString code);
void Book::setAuthors(QString authors);
void Book::setTitle(QString title);
void Book::setPublisher(QString publisher);
void Book::setYearOfPublication(QString yearOfPublication);
void Book::setAllCopies(int allCopies);
void Book::setCopiesInStock(int copiesInStock);
void Book::setLeft(Book* const& left);
void Book::setRight(Book* const& right);
QString Book::getCode();
QString Book::getAuthors();
QString Book::getTitle();
QString Book::getPublisher();
QString Book::getYearOfPublication();
int Book::getAllCopies();
int Book::getCopiesInStock();
Book* Book::getLeft();
Book* Book::getRight();*/
