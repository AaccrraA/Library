#include "Reader.h"

#include <QString>

Reader::Reader() : Reader("", "", "", "", "", NULL, NULL) {
}

Reader::Reader(QString cardNumber, QString fio, QString yearOfBirth, QString adress, QString jobOrStudyPlace, Reader *next, Reader *prev)
{
    setCardNumber(cardNumber);
    setFio(fio);
    setYearOfBirth(yearOfBirth);
    setAdress(adress);
    setJobOrStudyPlace(jobOrStudyPlace);
    setNext(next);
    setPrev(prev);
}

void Reader::setCardNumber (QString cardNumber) {
    _cardNumber = cardNumber;
}

void Reader::setFio (QString fio) {
    _fio = fio;
}

void Reader::setYearOfBirth (QString yearOfBirth) {
    _yearOfBirth = yearOfBirth;
}

void Reader::setAdress (QString adress) {
    _adress = adress;
}

void Reader::setJobOrStudyPlace (QString jobOrStudyPlace) {
    _jobOrStudyPlace = jobOrStudyPlace;
}

void Reader::setNext(Reader* n) {
    _next = n;
}

void Reader::setPrev(Reader* p) {
    _prev = p;
}

QString Reader::getCardNumber() {
    return _cardNumber;
}

QString Reader::getFio() {
    return _fio;
}

QString Reader::getYearOfBirth() {
    return _yearOfBirth;
}

QString Reader::getAdress() {
    return _adress;
}

QString Reader::getJobOrStudyPlace() {
    return _jobOrStudyPlace;
}

Reader* Reader::getNext() {
    return _next;
}

Reader* Reader::getPrev() {
    return _prev;
}
