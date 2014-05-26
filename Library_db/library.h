#ifndef LIBRARY_H
#define LIBRARY_H

#include <QtCore>
#include <QDebug>

#include "Reader.h"
#include "Book.h"
#include "IOBooksInfo.h"
#include "readershash.h"
#include "booktree.h"
#include "iobooksinfolinkedlist.h"

class Library
{
private:
    int GetNumberOfReaders();
    QString GenerateCardNumber(QString rOfA);
    int GenerateHashTableIndex(QString key);
    int registrationNumber;
    int GetReadersHashSize();
    QString GenerateCode(QString setionId, QString copiesInSection);


public:
    ReadersHash             *readersHash;
    BookTree                *bookAVLTree;            // АВЛ-Дерево поиска с симметричным методом обхода
    IOBooksInfoLinkedList   *ioBooksInfoList;       // Линейный двунаправленный список

    Library();
    // Основные функции
    Reader* AddReader(QString rOfA, QString fio, QString yOfB, QString adress, QString jOrSP);
    void    DeleteReader(qint32 index);
    void    DeleteAllReaders();
    Book*   AddBook(QString sectionId,
                    QString copiesInSection,
                    QString authors,
                    QString title,
                    QString publisher,
                    QString yearOfPublication,
                    QString allCopies,
                    QString copiesInStock);
    void    DeleteBook(QString code);
    void    DeleteAllBooks();
    void    GiveBook(IOBooksInfo* iobi);
    void    TakeBook(int index);
};

#endif
