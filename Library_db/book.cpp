#include "Book.h"

#include <QString>

Book::Book(QString c, QString t, QString p, int yOfP, int aC, int cIS)
{
    code = c;
    title = t;
    publisher = p;
    yearOfPublication = yOfP;
    allCopies = aC;
    copiesInStock = cIS;
}
