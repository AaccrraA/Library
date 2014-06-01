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

    if (readersHash->SearchByCardNumber(newReader->getCardNumber()).size() == 0) {
        // --- Добавляем читателя
        readersHash->Add(newReader);
        ++registrationNumber;
    }
    else {
        // Такой читатель уже существует
        delete newReader;
        newReader = NULL;
    }

    return newReader;
}

QString Library::GenerateCardNumber(QString rOfA) {
    QString cN;
    cN += rOfA;
    QString regNumStr = QString::number((this->registrationNumber));
    for(qint32 i = 0; i < 4-regNumStr.length(); i++) {
        cN += "0";
    }
    cN += regNumStr;
    QDate date = QDate::currentDate();
    QString dateStr = date.toString();
    dateStr.remove(0, dateStr.length()-2);
    cN += "-" + dateStr;
    return cN;
}

qint32 Library::GetReadersHashSize() {
    qint32 i = this->readersHash->GetSize();
    return i;
}

QString Library::GenerateCode(QString sectionId, QString copiesInSection) {
    QString code = "";
    for(qint32 i = 0; i < 3-sectionId.length(); i++) {
        code += "0";
    }
    code += sectionId;
    code += ".";
    for(qint32 i = 0; i < 3-copiesInSection.length(); i++) {
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
