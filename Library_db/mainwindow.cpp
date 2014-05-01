#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createreaderdialog.h"
#include "ui_createreaderdialog.h"
#include "ui_searchreaderdialog.h"

#include "library.h"

#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Зыкрытие доступа к работе с данными(библиотека не создана)
    ui->reader_menu->setEnabled(false);
    ui->book_menu->setEnabled(false);
    ui->ioinfo_menu->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_create_library_action_triggered()
{
    // Диалоговое окно с параметрами <- maybe
    library = new Library;

    // Открытие доступа к работе с данными
    ui->reader_menu->setEnabled(true);
    ui->book_menu->setEnabled(true);
    ui->ioinfo_menu->setEnabled(true);
}

void MainWindow::on_add_reader_action_triggered()
{
    CreateReaderDialog crd(this);
    crd.exec();
    library->AddReader(crd.getROfA(), crd.getFio(), crd.getYOfB(), crd.getAdress(), crd.getJOrSP());
}

void MainWindow::on_search_reader_action_triggered()
{
}
