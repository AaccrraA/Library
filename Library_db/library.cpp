#include "library.h"
#include "reader.h"

Library::Library() {
    registrationNumber = 0;
    readersHash = new ReadersHash;
    bookAVLTree = new BookTree;
    ioBooksInfoList = new IOBooksInfoLinkedList;
}

Reader* Library::AddReader(QString rOfA, QString fio, QString yOfB, QString adress, QString jOrSP) {
    Reader *newReader = new Reader(GenerateCardNumber(rOfA), fio, yOfB, adress, jOrSP, NULL, NULL);

    bool isReaderAdded = true;

    if (readersHash->SearchByCardNumber(newReader->getCardNumber()).size() == 0) {
        // --- Добавляем читателя
        readersHash->Add(newReader);
        ++registrationNumber;
    }
    else {
        // Такой читатель уже существует
        isReaderAdded = false;
        delete newReader;
        newReader = NULL;
    }

    return newReader;
}

QString Library::GenerateCardNumber(QString rOfA) {
    QString cN;
    cN += rOfA;
    QString regNumStr = QString::number((this->registrationNumber));
    for(int i = 0; i < 4-regNumStr.length(); i++) {
        cN += "0";
    }
    cN += regNumStr;
    QDate date = QDate::currentDate();
    QString dateStr = date.toString();
    dateStr.remove(0, dateStr.length()-2);
    cN += "-" + dateStr;
    return cN;
}

int Library::GetReadersHashSize() {
    int i = this->readersHash->GetSize();
    return i;
}

Book* Library::AddBook(QString sectionId,
                    QString copiesInSection,
                    QString authors,
                    QString title,
                    QString publisher,
                    QString yearOfPublication,
                    QString allCopies,
                    QString copiesInStock) {
    Book* newBook = new Book(GenerateCode(sectionId, copiesInSection), authors, title, publisher, yearOfPublication, allCopies, copiesInStock);
    bool isBookAdded = true;
    if (bookAVLTree->SearchByCode(newBook->getCode()) == NULL) {
        // --- Добавляем читателя
        bookAVLTree->root = bookAVLTree->Add(bookAVLTree->root, newBook);
    }
    else {
        // --- Такой читатель уже существует
        isBookAdded = false;
        delete newBook;
        newBook = NULL;
    }
    return newBook;
}

QString Library::GenerateCode(QString sectionId, QString copiesInSection) {
    QString code = "";
    for(int i = 0; i < 3-sectionId.length(); i++) {
        code += "0";
    }
    code += sectionId;
    code += ".";
    for(int i = 0; i < 3-copiesInSection.length(); i++) {
        code += "0";
    }
    code += copiesInSection;
    return code;
}

void Library::DeleteBook(QString code) {
    bookAVLTree->root = bookAVLTree->Delete(bookAVLTree->root, bookAVLTree->SearchByCode(code));
}
void Library::DeleteAllBooks() {
    bookAVLTree->DeleteAll(bookAVLTree->root);
    bookAVLTree->root = NULL;
}

void Library::GiveBook(IOBooksInfo* iobi) {
    ioBooksInfoList->Add(iobi);
}

void Library::TakeBook(int index) {
    ioBooksInfoList->Delete(index);
}
