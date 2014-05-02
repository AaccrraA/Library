#include "Book.h"

#include <QString>

Book::Book(const QString &c, const QString &t, const QString &p, int yOfP, int aC, int cIS)
{
    code = c;
    title = t;
    publisher = p;
    yearOfPublication = yOfP;
    allCopies = aC;
    copiesInStock = cIS;
}
