#include <QtCore>
#include "booktree.h"

BookTree::BookTree() {
    root = NULL;
}

qint32 BookTree::Height(Book* b) {
    return b ? b->getHeight() : 0;
}

qint32 BookTree::BalanceFactor(Book *b) {
    return Height(b->getRight())-Height(b->getLeft());
}

void BookTree::FixHeight(Book *b) {
    qint32 hl = Height(b->getLeft());
    qint32 hr = Height(b->getRight());
    b->setHeight((hl > hr ? hl : hr) + 1);
}

Book* BookTree::RotateRight(Book *b) {
    Book* q = b->getLeft();
    b->setLeft(q->getRight());
    q->setRight(b);
    FixHeight(b);
    FixHeight(q);
    return q;
}

Book* BookTree::RotateLeft(Book *b) {
    Book* q = b->getRight();
    b->setRight(q->getLeft());
    q->setLeft(b);
    FixHeight(b);
    FixHeight(q);
    return q;
}

Book* BookTree::Balance(Book *b) {
    FixHeight(b);
    if ( BalanceFactor(b)== 2 ) {
        if( BalanceFactor(b->getRight()) < 0 )
            b->setRight(RotateRight(b->getRight()));
        return RotateLeft(b);
    }
    if( BalanceFactor(b)== -2 ) {
        if( BalanceFactor(b->getLeft()) > 0 )
            b->setLeft(RotateLeft(b->getLeft()));
        return RotateRight(b);
    }
    return b; // балансировка не нужна
}

Book* BookTree::Add(Book *p, Book* b) {
    if( !p ) {
        p = b;
        FixHeight(p);
        return p;
    }
    else if( QString::localeAwareCompare(b->getCode(), p->getCode()) < 0 )
        p->setLeft(Add(p->getLeft(), b));
    else
        p->setRight(Add(p->getRight(), b));
    return Balance(p);
}

Book* BookTree::Delete(Book *p, Book *b) {
    if ( !p ) return 0;
    if( QString::localeAwareCompare(b->getCode(), p->getCode()) < 0 )
        p->setLeft(Delete(p->getLeft(), b));
    else if( QString::localeAwareCompare(b->getCode(), p->getCode()) > 0 )
        p->setRight(Delete(p->getRight(), b));
    else {  //  b->getCode() == p->getCode()
        Book* q = p->getLeft();
        Book* r = p->getRight();
        delete p;
        if( !r ) return q;
        Book* min = FindMin(r);
        min->setRight(DeleteMin(r));
        min->setLeft(q);
        return Balance(min);
    }
    return Balance(p);
}

Book* BookTree::FindMin(Book* b) {
    return b->getLeft() ? FindMin(b->getLeft()) : b;
}

Book* BookTree::DeleteMin(Book* b) {
    if ( b->getLeft() == 0)
        return b->getRight();
    b->setLeft(DeleteMin(b->getLeft()));
    return Balance(b);
}

Book* BookTree::SearchByCode(QString code) {
    Book* tmp = root;
    if(tmp) {
        while ( tmp != NULL) {
            if( QString::localeAwareCompare(code, tmp->getCode()) < 0 )
                tmp = tmp->getLeft();
            else if( QString::localeAwareCompare(code, tmp->getCode()) > 0 )
                tmp = tmp->getRight();
            else {
                break;
            }
        }
    }
    return tmp;
}

QVector<Book*> BookTree::SearchByAuthorsOrTitle(QString authors) {
    QVector<Book*> treeVec, results;
    Visit(root, treeVec);
    foreach (Book* b, treeVec) {
        if (BoyerMooreHorspoolSearch(b->getAuthors(), authors) || BoyerMooreHorspoolSearch(b->getTitle(), authors))
            results.append(b);
    }
    return results;
}

int BookTree::BoyerMooreHorspoolSearch(QString haystack, QString needle ) {
    /*int needleLen = needle.length();
    int haystackLen = haystack.length();
    if (needleLen < haystackLen) {
        QHash<QChar, int> offsetTable;

        for (int i = 0; i < 256; ++i) {
            //QChar c((short) i);
            offsetTable.insert(i, needleLen);
        }
        for (int i = 0; i < needleLen; ++i) {
            QChar c = needle.at(i);
            offsetTable.insert(c, haystackLen - i - 1);
        }
        int i = needleLen - 1;
        int j = i;
        int k = i;
        while (j >= 0 && i <= haystackLen - 1) {
                j = needleLen - 1;
                k = i;
                while (j >= 0 && haystack.at(k) == haystack.at(j)) {
                    k--;
                    j--;
                }
                i += offsetTable.take(needle.at(i));
            }
            if (k >= haystackLen - needleLen) {
                return -1;
            } else {
                return k + 1;
            }
    }
    else {
        return -1;
    }*/
}

QVector<Book*> BookTree::GetVectorOfBooks() {
    QVector<Book*> results;
    Visit(root, results);
    return results;
}

void BookTree::Visit(Book* p, QVector<Book*>& r) {
    if ( p ) {
        Visit(p->getLeft(), r);
        Visit(p->getRight(), r);
        r.append(p);
    }
}

void BookTree::DeleteAll(Book *p) {
    if ( p ) {
        DeleteAll(p->getLeft());
        DeleteAll(p->getRight());
        delete p;
    }
}


























