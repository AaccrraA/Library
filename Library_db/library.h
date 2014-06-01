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
    qint32 GetNumberOfReaders();
    QString GenerateCardNumber(QString rOfA);
    qint32 GenerateHashTableIndex(QString key);
    qint32 registrationNumber;
    qint32 GetReadersHashSize();

public:
    ReadersHash             *readersHash;
    BookTree                *bookAVLTree;            // АВЛ-Дерево поиска с симметричным методом обхода
    IOBooksInfoLinkedList   *ioBooksInfoList;       // Линейный двунаправленный список

    Library();
    Reader* AddReader(QString rOfA, QString fio, QString yOfB, QString adress, QString jOrSP);
    QString GenerateCode(QString setionId, QString copiesInSection);
    void    DeleteReader(qint32 index);
    void    DeleteAllReaders();
    void    DeleteBook(QString code);
    void    DeleteAllBooks();
};

#endif
