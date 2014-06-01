#include "Book.h"

#include <QString>

Book::Book(QString code,
           QString authors,
           QString title,
           QString publisher,
           QString yearOfPublication,
           QString allCopies,
           QString copiesInStock)
{
    _code = code;
    _authors = authors;
    _title = title;
    _publisher = publisher;
    _yearOfPublication = yearOfPublication;
    _allCopies = allCopies;
    _copiesInStock = copiesInStock;
    _left = NULL;
    _right = NULL;
}


void Book::setCode(QString code) {
    _code = code;
}

void Book::setAuthors(QString authors) {
    _authors = authors;
}

void Book::setTitle(QString title) {
    _title = title;
}

void Book::setPublisher(QString publisher) {
    _publisher = publisher;
}

void Book::setYearOfPublication(QString yearOfPublication) {
    _yearOfPublication = yearOfPublication;
}

void Book::setAllCopies(QString allCopies) {
    _allCopies = allCopies;
}

void Book::setCopiesInStock(QString copiesInStock) {
    _copiesInStock = copiesInStock;
}

void Book::setHeight(quint8 height) {
    _height = height;
}

void Book::setLeft(Book* left) {
    _left = left;
}

void Book::setRight(Book* right) {
    _right = right;
}

QString Book::getCode() const {
    return _code;
}

QString Book::getAuthors() const {
    return _authors;
}

QString Book::getTitle() const {
    return _title;
}

QString Book::getPublisher() const {
    return _publisher;
}

QString Book::getYearOfPublication() const {
    return _yearOfPublication;
}

QString Book::getAllCopies() const {
    return _allCopies;
}

QString Book::getCopiesInStock() const {
    return _copiesInStock;
}

quint8 Book::getHeight() const {
    return _height;
}

Book* Book::getLeft() const {
    return _left;
}

Book* Book::getRight() const {
    return _right;
}
