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
    readershash.cpp \
    booktree.cpp

HEADERS  += mainwindow.h \
    reader.h \
    library.h \
    iobooksinfo.h \
    book.h \
    readershash.h \
    booktree.h

FORMS    += mainwindow.ui

OTHER_FILES +=
