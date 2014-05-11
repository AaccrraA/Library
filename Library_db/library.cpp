#include "library.h"
#include "reader.h"

Library::Library() {
    readersHashMap = new ReadersHashMap;
}

bool Library::AddReader(QString rOfA, QString fio, QString yOfB, QString adress, QString jOrSP) {
    Reader *newReader = new Reader(GenerateCardNumber(rOfA), fio, yOfB, adress, jOrSP, NULL, NULL);

    bool isReaderAdded = true;

    if (readersHashMap->SearchByCardNumber(newReader->getCardNumber()) == NULL &&
        readersHashMap->SearchByFIO(newReader->getFio()).size() == 0) {
        // --- Добавляем читателя
        readersHashMap->Add(newReader);
    }
    else {
        // Такой читатель уже существует
        isReaderAdded = false;
        delete newReader;
    }

    return isReaderAdded;
}

QString Library::GenerateCardNumber(QString rOfA) {
    QString cN;
    cN += rOfA;
    QString regNumStr = QString::number((this->readersHashMap->GetNumberOfReaders())+1);
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


