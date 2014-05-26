#include "iobooksinfo.h"

#include <QString>

IOBooksInfo::IOBooksInfo() {
    setCardNumber("");
    setCode("");
    setODate("");
    setIDate("");
    setNext(NULL);
    setPrev(NULL);
}

IOBooksInfo::IOBooksInfo(QString cardNumber,
                         QString code,
                         QString oDate,
                         QString iDate,
                         IOBooksInfo* next,
                         IOBooksInfo* prev) {
    _cardNumber = cardNumber;
    _code = code;
    _oDate = oDate;
    _iDate = iDate;
    _next = next;
    _prev = prev;
}

void IOBooksInfo::setCardNumber(QString cardNumber) {
    _cardNumber = cardNumber;
}

void IOBooksInfo::setCode(QString code) {
    _code = code;
}

void IOBooksInfo::setODate(QString oDate) {
    _oDate = oDate;
}

void IOBooksInfo::setIDate(QString iDate) {
    _iDate = iDate;
}

void IOBooksInfo::setNext(IOBooksInfo* next) {
    _next = next;
}

void IOBooksInfo::setPrev(IOBooksInfo* prev) {
    _prev = prev;
}

QString IOBooksInfo::getCardNumber() {
    return _cardNumber;
}

QString IOBooksInfo::IOBooksInfo::getCode() {
    return _code;
}

QString IOBooksInfo::getODate() {
    return _oDate;
}

QString IOBooksInfo::getIDate() {
    return _iDate;
}

IOBooksInfo* IOBooksInfo::getNext() {
    return _next;
}

IOBooksInfo* IOBooksInfo::getPrev() {
    return _prev;
}
