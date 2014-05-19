#ifndef BOOKTREE_H
#define BOOKTREE_H

#include <book.h>
#include "book.h"

class BookTree
{
private:
    qint32  Height(Book* b);
    qint32  BalanceFactor(Book* b);
    void    FixHeight(Book* b);
    Book*   RotateRight(Book* b);
    Book*   RotateLeft(Book* b);
    Book*   Balance(Book* b);
public:
    BookTree();
    Book* root;
    Book*   Add(Book* p, Book* b);
    Book*   Delete(Book* p, Book* b);
    Book*   FindMin(Book* b);
    Book*   DeleteMin(Book* b);
    void    Visit(Book* p, QVector<Book *> &r);
    void    DeleteAll(Book* p);
    Book*   SearchByCode(QString code);
    QVector<Book*> SearchBookByAuthorsOrTitle(QString authors);
    QVector<Book*> GetVectorOfBooks();

};

#endif // BOOKTREE_H
