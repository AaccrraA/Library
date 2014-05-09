#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QStackedWidget>
#include <QMainWindow>
#include "library.h"
#include "librarywidget.h"
#include "createreaderwidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // --- Menu Library --- //
    void on_create_library_action_triggered();
    // --- Menu Reader --- //
    void on_add_reader_action_triggered();
    void on_search_reader_action_triggered();

private:
    QStackedWidget      *stackedWidget;
    Ui::MainWindow      *ui;
    Library             *_library;

    LibraryWidget       *libraryWidget_;
    CreateReaderWidget  *createReaderWidget_;

    Library* CreateLibrary();
    Library* OpenLibrary();

};

#endif // MAINWINDOW_H
