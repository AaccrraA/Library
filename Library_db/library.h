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
    ReadersHashMap      *readersHashMap;
    Book                *bookAVLTree;            // АВЛ-Дерево поиска с симметричным методом обхода
    IOBooksInfo         *ioBooksInfo;       // Линейный двунаправленный список

    int _getNumberOfReaders();
    int _getRegistraitonNumber();
    QString GenerateCardNumber(QString rOfA);
    int GenerateHashTableIndex(QString key);

public:
    Library();
    // Основные функции
    bool AddReader(QString rOfA, QString fio, QString yOfB, QString adress, QString jOrSP);
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
