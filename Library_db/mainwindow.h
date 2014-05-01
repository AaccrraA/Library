#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    // Меню Библиотека
    void on_create_library_action_triggered();
    // Меню читатель
    void on_add_reader_action_triggered();
    void on_search_reader_action_triggered();

private:
    Ui::MainWindow  *ui;
    Library         *library;

};

#endif // MAINWINDOW_H
