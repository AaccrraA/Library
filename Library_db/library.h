#ifndef LIBRARY_H
#define LIBRARY_H

#include <QtCore>
#include <QDebug>

#include "Reader.h"
#include "Book.h"
#include "IOBooksInfo.h"
#include "readershashmap.h"

class Library
{
private:
    const int MY_HASHMAP_SIZE = 256;
    ReadersHashMap      *readersHashMap_;
    Book                *bookAVLTree_;            // АВЛ-Дерево поиска с симметричным методом обхода
    IOBooksInfo         *ioBooksInfo_;       // Линейный двунаправленный список


    // Служебные функции
    int _getNumberOfReaders();
    int _getRegistraitonNumber();
    QString _gainCardNumber(QString rOfA);
    int _gainHashTableIndex(QString key);

public:
    Library();
    // Основные функции
    void AddReader(QString rOfA, QString f, int yOfB, QString a, QString jOrSP);
    void AddReader(Reader* reader);
//    bool DeleteReader();
//    void ShowAllReaders();
//    void DeleteAllReaders();
//    void SearchReaderByNumber(string cardNumber);
//    void SearchReaderByName(string name);
//    void AddBook();
//    void DeleteBook();
//    void DeleteAllBooks();
//    void SearchBookByCode(string code);
//    void SearchBookByAuthorsOrTitle(string authorsOrTitle);
//    void RegOutBook();
//    void RegInBook();

};

#endif
