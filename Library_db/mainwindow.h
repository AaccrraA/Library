#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QStackedWidget>
#include <QMainWindow>
#include "library.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AddReaderToLibrary();

private slots:
    // --- Menu Library --- //
    void on_create_library_action_triggered();
    // --- Menu Reader --- //
    void on_add_reader_action_triggered();
    void on_search_reader_action_triggered();

    void on_add_reader_pushButton_clicked();

    void on_ok_pushButton_clicked();

private:
    Ui::MainWindow      *ui;
    Library             *library;

    Reader* CreateReader();

};

#endif // MAINWINDOW_H
