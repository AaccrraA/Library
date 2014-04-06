#ifndef LIBRARY_H
#define LIBRARY_H

#include <QVector>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QChar>
#include <qmath.h>

#include "Reader.h"
#include "Book.h"
#include "IOBooksInfo.h"

using namespace std;

class Library
{
private:
    QVector<Reader*> _readers;   // Хеш-таблица с открытым хешированием
    const int _hashTableSize = 256;
    //Book* bookST;	// АВЛ-Дерево поиска с симметричным методом обхода
    //IOBooksInfo *ioBooksInfo;	// Линейный двунаправленный список

    // Служебные функции
    int _getNumberOfReaders();
    int _getRegistraitonNumber();
    QString _gainCardNumber(QString rOfA);
    int _gainHashTableIndex(QString key);

public:
    Library();
    // Основные функции
    void AddReader(QString rOfA, QString f, int yOfB, QString a, QString jOrSP);

    //    bool DeleteReader();
//    void DrawAllReaders();
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
