#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createreaderwidget.h"
#include "ui_createreaderwidget.h"

#include "library.h"

MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent),
                                            ui(new Ui::MainWindow) {
    libraryWidget_ = new LibraryWidget(this);
    createReaderWidget_ = new CreateReaderWidget(this);

    stackedWidget->addWidget(libraryWidget_);
    stackedWidget->addWidget(createReaderWidget_);

    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete _library;
    delete ui;
}

Library* MainWindow::CreateLibrary() {
    // Сохранить если существует уже библиотека
    _library = new Library;

    // --- Enabling access --- //
    ui->reader_menu->setEnabled(true);
    ui->book_menu->setEnabled(true);
    ui->iobooksinfo_menu->setEnabled(true);
    ui->library_tabWidget->setEnabled(true);
    ui->save_library_action->setEnabled(true);
    ui->save_as_library_action->setEnabled(true);

    return _library;
}

void MainWindow::on_create_library_action_triggered() {
    CreateLibrary();
}

void MainWindow::on_add_reader_action_triggered() {
}

void MainWindow::on_search_reader_action_triggered()
{
}


