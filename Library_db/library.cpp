#include "library.h"
#include "reader.h"

Library::Library() {
    registrationNumber = 0;
    readersHash = new ReadersHash;
}

Reader* Library::AddReader(QString rOfA, QString fio, QString yOfB, QString adress, QString jOrSP) {
    Reader *newReader = new Reader(GenerateCardNumber(rOfA), fio, yOfB, adress, jOrSP, NULL, NULL);

    bool isReaderAdded = true;

    if (readersHash->SearchByCardNumber(newReader->getCardNumber()) == NULL) {
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

void Library::DeleteAllReaders() {
    for (int i = 0; i < readersHash->GetSize()-1; ++i) {
        this->readersHash->Delete(i);
    }
}

int Library::GetReadersHashSize() {
    int i = this->readersHash->GetSize();
    return i;
}

void Library::DeleteReader(qint32 index) {
    this->readersHash->Delete(index);
}

