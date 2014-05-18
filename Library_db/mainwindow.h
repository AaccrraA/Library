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
    // --------- Library
    void on_create_library_action_triggered();
    // --------- Reader
    void on_add_reader_action_triggered();
    void on_add_reader_pushButton_clicked();
    void on_cr_ok_pushButton_clicked();
    void on_cr_cancel_pushButton_clicked();
    void on_delete_reader_action_triggered();
    void on_delete_reader_pushButton_clicked();
    void on_delete_all_readers_pushButton_clicked();
    void on_delete_all_readers_action_triggered();

    void on_show_all_readers_pushButton_clicked();
    void on_search_reader_pushButton_clicked();



    void on_show_all_readers_action_triggered();

private:
    Ui::MainWindow      *ui;
    Library             *library;

    void UpdateReaderTableWidget();
    void CreateReader();
    void AddItemInReaderTableWidget(Reader* r, qint32 row);
    void DeleteReader();
    void DeleteAllReaders();
    void SearchReader();
    void ClearReaderTableWidget();
    void AddItemInSearchResultsTableWidget(Reader*, qint32 row);


};

#endif // MAINWINDOW_H
