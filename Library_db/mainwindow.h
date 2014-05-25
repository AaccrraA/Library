#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QTableWidget>
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
    // --- LIBRARY
    void on_create_library_action_triggered();
    // --- READER
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
    // --- BOOK
    void on_add_book_action_triggered();
    void on_add_book_pushButton_clicked();
    void on_cb_ok_pushButton_clicked();
    void on_cb_cancel_pushButton_clicked();
    void on_delete_book_pushButton_clicked();
    void on_delete_book_action_triggered();
    void on_delete_all_books_pushButton_clicked();
    void on_delete_all_books_action_triggered();

    void on_cb_section_comboBox_currentIndexChanged(const QString &arg1);

    void on_show_all_books_pushButton_clicked();

    void on_show_all_books_action_triggered();

    void on_search_book_pushButton_clicked();

    void on_give_iobooksinfo_pushButton_clicked();

    void on_give_book_action_triggered();

    void on_gb_give_book_pushButton_clicked();

private:
    Ui::MainWindow          *ui;
    Library                 *library;
    QHash<QString, qint32>  bookSections;

    void ClearTableWidget(QTableWidget* tw);
    // --- READER
    void UpdateReaderTableWidget();
    void CreateReader();
    void AddReaderInTableWidget(Reader* r, QTableWidget* tw, int row);
    void DeleteReader();
    void DeleteAllReaders();
    void SearchReader();
    void AddItemInSearchResultsTableWidget(Reader*, qint32 row);
    // --- BOOK
    void CreateBook();
    void UpdateBookTableWidget();
    void AddBookInTableWidget(Book* b, QTableWidget* tw, int row);
    void DeleteBook();
    void DeleteAllBooks();
    // --- IOBOOKSINFO
    void GiveBook();

};

#endif // MAINWINDOW_H
