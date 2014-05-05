#include "Reader.h"

#include <QString>

Reader::Reader()
{
}

Reader::Reader(QString const& cardNumber, QString const& fio, int yearOfBirth, QString const& adress, QString const& jobOrStudyPlace, Reader * const &next, Reader * const &prev)
{
    setCardNumber(cardNumber);
    setFio(fio);
    setYearOfBirth(yearOfBirth);
    setAdress(adress);
    setJobOrStudyPlace(jobOrStudyPlace);
    setNext(next);
    setPrev(prev);
}

void Reader::setCardNumber (QString const& cardNumber) {
    _cardNumber = cardNumber;
}

void Reader::setFio (QString const& fio) {
    _fio = fio;
}

void Reader::setYearOfBirth (int yearOfBirth) {
    _yearOfBirth = yearOfBirth;
}

void Reader::setAdress (QString const& adress) {
    _adress = adress;
}

void Reader::setJobOrStudyPlace (QString const& jobOrStudyPlace) {
    _jobOrStudyPlace = jobOrStudyPlace;
}

void Reader::setNext(Reader* const& n) {
    _next = n;
}

void Reader::setPrev(Reader* const& p) {
    _prev = p;
}

QString Reader::getCardNumber() {
    return _cardNumber;
}

QString Reader::getFio() {
    return _fio;
}

int     Reader::getYearOfBirth() {
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
