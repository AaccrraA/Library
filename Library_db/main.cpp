#include "mainwindow.h"
#include <QApplication>

qint32 main(qint32 argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    return a.exec();
}
