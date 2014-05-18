#ifndef LIBRARY_H
#define LIBRARY_H

#include <QtCore>
#include <QDebug>

#include "Reader.h"
#include "Book.h"
#include "IOBooksInfo.h"
#include "readershash.h"

class Library
{
private:
    int GetNumberOfReaders();
    QString GenerateCardNumber(QString rOfA);
    int GenerateHashTableIndex(QString key);
    int registrationNumber;

public:
    ReadersHash         *readersHash;
    Book                *bookAVLTree;            // АВЛ-Дерево поиска с симметричным методом обхода
    IOBooksInfo         *ioBooksInfo;       // Линейный двунаправленный список

    Library();
    // Основные функции
    Reader *AddReader(QString rOfA, QString fio, QString yOfB, QString adress, QString jOrSP);
    void DeleteReader(qint32 index);
    void DeleteAllReaders();
//    void SearchReaderByNumber(string cardNumber);
//    void SearchReaderByName(string name);
//    void AddBook();
//    void DeleteBook();
//    void DeleteAllBooks();
//    void SearchBookByCode(string code);
//    void SearchBookByAuthorsOrTitle(string authorsOrTitle);
//    void RegOutBook();
//    void RegInBook();

    int GetReadersHashSize();
};

#endif
