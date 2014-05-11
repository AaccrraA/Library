#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QMessageBox>
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


private slots:
    // --- Library
    void on_create_library_action_triggered();
    // --- Reader
    void on_add_reader_action_triggered();
    void on_search_reader_action_triggered();
    void on_add_reader_pushButton_clicked();
    void on_cr_ok_pushButton_clicked();

private:
    Ui::MainWindow      *ui;
    Library             *library;

    void SetupCreateReaderWidget();
};

#endif // MAINWINDOW_H
