#-------------------------------------------------
#
# Project created by QtCreator 2014-03-20T13:59:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library_db
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    reader.cpp \
    library.cpp \
    iobooksinfo.cpp \
    book.cpp \
    createreaderdialog.cpp \
    searchreaderdialog.cpp

HEADERS  += mainwindow.h \
    reader.h \
    library.h \
    iobooksinfo.h \
    book.h \
    createreaderdialog.h \
    searchreaderdialog.h

FORMS    += mainwindow.ui \
    createreaderdialog.ui \
    searchreaderdialog.ui

OTHER_FILES +=
