#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "library.h"

MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent),
                                            ui(new Ui::MainWindow) {
    library = NULL;
    ui->setupUi(this);

    // --- Unenabling access
    ui->reader_menu->setEnabled(false);
    ui->book_menu->setEnabled(false);
    ui->iobooksinfo_menu->setEnabled(false);
    ui->stackedWidget->setEnabled(false);
    ui->save_library_action->setEnabled(false);
    ui->save_as_library_action->setEnabled(false);

    // --- Setting up main widget
    ui->stackedWidget->setCurrentWidget(ui->library_page);
    ui->library_tabWidget->setCurrentWidget(ui->reader_tab);

    // --- Setting up tables
    QStringList readerLabels, bookLabels, iobooksinfoLabels;
    readerLabels << tr("Index") << tr("№ ЧБ") << tr("ФИО") << tr("Год рождения") << tr("Адрес") << tr("Место работы/учебы");
    bookLabels << tr("Шифр") << tr("Автор(ы)") << tr("Название") << tr("Издатель") << tr("Год издания") << tr("Тираж(шт.)") << tr("На складе(шт.)");
    iobooksinfoLabels << tr("№ ЧБ") << tr("Шифр") << tr("Дата выдачи") << tr("Дата приема");

    ui->reader_tableWidget->setColumnCount(readerLabels.length());
    ui->book_tableWidget->setColumnCount(bookLabels.length());
    ui->iobooksinfo_tableWidget->setColumnCount(iobooksinfoLabels.length());

    ui->reader_tableWidget->setRowCount(0);
    ui->book_tableWidget->setRowCount(0);
    ui->iobooksinfo_tableWidget->setRowCount(0);

    ui->reader_tableWidget->setHorizontalHeaderLabels(readerLabels);
    ui->book_tableWidget->setHorizontalHeaderLabels(bookLabels);
    ui->iobooksinfo_tableWidget->setHorizontalHeaderLabels(iobooksinfoLabels);

    ui->reader_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->book_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->iobooksinfo_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_create_library_action_triggered() {
    if (library == NULL) {
        // --- Creating New Library
        library = new Library;

        // --- Enabling access
        ui->reader_menu->setEnabled(true);
        ui->book_menu->setEnabled(true);
        ui->iobooksinfo_menu->setEnabled(true);
        ui->stackedWidget->setEnabled(true);
        ui->save_library_action->setEnabled(true);
        ui->save_as_library_action->setEnabled(true);
    }
    else {
        // --- Saving Current Library
    }
}

// --- READER
void MainWindow::UpdateReaderTableWidget() {
    ClearReaderTableWidget();
    for (int i = 0; i < library->readersHash->GetSize(); ++i) {
        if (library->readersHash->At(i) != NULL) {
            int row = ui->reader_tableWidget->rowCount();
            ui->reader_tableWidget->insertRow(row);
            AddItemInReaderTableWidget(library->readersHash->At(i), row);
        }
    }
}

void MainWindow::ClearReaderTableWidget() {
    while (ui->reader_tableWidget->rowCount() > 0) {
        ui->reader_tableWidget->removeRow(0);
    }
}

// ------ Create Reader
void MainWindow::on_add_reader_action_triggered() { CreateReader(); }

void MainWindow::on_add_reader_pushButton_clicked() { CreateReader(); }

void MainWindow::CreateReader() {
    // --- Setting up Create Reader Page
    ui->cr_right_of_acces_comboBox->setCurrentIndex(0);
    ui->cr_fio_lineEdit->setText("");
    ui->cr_year_of_birth_lineEdit->setText("");
    ui->cr_adress_lineEdit->setText("");
    ui->cr_job_or_study_place_lineEdit->setText("");
    // --- Show Create Reader Page
    ui->stackedWidget->setCurrentWidget(ui->create_reader_page);
}

void MainWindow::on_cr_ok_pushButton_clicked() {
    bool isCorrectForm = true;

    QString rOfA_str = QString::number(ui->cr_right_of_acces_comboBox->currentIndex());
    QString fio_str = ui->cr_fio_lineEdit->text();
    QString yOfB_str = ui->cr_year_of_birth_lineEdit->text();
    QString adress_str = ui->cr_adress_lineEdit->text();
    QString jOrSP_str = ui->cr_job_or_study_place_lineEdit->text();

    QRegExp fio_rexp("");
    QRegExp yOfB_rexp("");
    QRegExp adress_rexp("");
    QRegExp jOrSP_rexp("");

    if (fio_rexp.indexIn(fio_str) < 0) {
        // Не павильная фамилия
        isCorrectForm = false;
    }

    if (yOfB_rexp.indexIn(yOfB_str) < 0) {
        // Не правильный год рождения
        isCorrectForm = false;
    }

    if (adress_rexp.indexIn(adress_str) < 0) {
        // Не правильный адрес
        isCorrectForm = false;
    }

    if (jOrSP_rexp.indexIn(jOrSP_str) < 0) {
        // Не правильная работа
        isCorrectForm = false;
    }

    if (isCorrectForm) {
        Reader* r = library->AddReader(rOfA_str, fio_str, yOfB_str, adress_str, jOrSP_str);
        if (r != NULL) {
            UpdateReaderTableWidget();
            //QMessageBox::information(this, tr("Читатель добавлен"), tr("Новый читатель успешно добавлен в библиотеку."), QMessageBox::Ok);
            ui->stackedWidget->setCurrentWidget(ui->library_page);
        }
        else {
            // Вывести ошибку о попытке добавления существующего читателя
            QMessageBox::critical(this, tr("Ошибка"), tr("Такой читатель уже зарегистрирован."), QMessageBox::Ok);
        }
    }
    else {
        // Вывести ошибку о заполнении полей
        QMessageBox::critical(this, tr("Ошибка"), tr("Следующие поля заполнены неверно"), QMessageBox::Ok);
    }
}

void MainWindow::on_cr_cancel_pushButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->library_page);
}

void MainWindow::AddItemInReaderTableWidget(Reader* r, qint32 row) {
    ui->reader_tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(r->getHashIndex())));
    ui->reader_tableWidget->setItem(row, 1, new QTableWidgetItem(r->getCardNumber()));
    ui->reader_tableWidget->setItem(row, 2, new QTableWidgetItem(r->getFio()));
    ui->reader_tableWidget->setItem(row, 3, new QTableWidgetItem(r->getYearOfBirth()));
    ui->reader_tableWidget->setItem(row, 4, new QTableWidgetItem(r->getAdress()));
    ui->reader_tableWidget->setItem(row, 5, new QTableWidgetItem(r->getJobOrStudyPlace()));
}

// ------ Delete Reader
void MainWindow::on_delete_reader_action_triggered() { DeleteReader(); }

void MainWindow::on_delete_reader_pushButton_clicked() { DeleteReader(); }

void MainWindow::DeleteReader() {
    QList<QTableWidgetItem*> selectionRangeList = this->ui->reader_tableWidget->selectedItems();
    int rowIndex;
    QListIterator<QTableWidgetItem*> selectionRangeListIter(selectionRangeList);

    if (selectionRangeList.size() > 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Удалить строки"));
        msgBox.setInformativeText(tr("Вы уверены, что хотите удалить выбранные строки?"));
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Ok:
                while(selectionRangeListIter.hasNext()){
                    rowIndex = ((int)((QTableWidgetItem*)selectionRangeListIter.next())->row());
                    QTableWidgetItem *item = ui->reader_tableWidget->item(rowIndex, 0);
                    library->DeleteReader(item->text().toInt(0, 10));
                    //this->ui->reader_tableWidget->removeRow(rowIndex);
                }
                break;
            case QMessageBox::Cancel:
                break;
        }
        UpdateReaderTableWidget();
    } else {
        QMessageBox::critical(this, tr("Нет выбранных строк"), tr("Для удаления, выберите строки или ячейки строк."), QMessageBox::Ok);
    }
}

// ------ Delete all Readers
void MainWindow::on_delete_all_readers_action_triggered() { DeleteAllReaders(); }

void MainWindow::on_delete_all_readers_pushButton_clicked() { DeleteAllReaders(); }

void MainWindow::DeleteAllReaders() {
    if (library->readersHash->GetNumberOfReaders() > 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Стереть все записи?"));
        msgBox.setInformativeText(tr("Вы уверены, что хотите стереть все записи таблицы \"Читатели\"?"));
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Ok:
                library->DeleteAllReaders();
                break;
            case QMessageBox::Cancel:
                break;
        }
        UpdateReaderTableWidget();
    } else {
        QMessageBox::critical(this, tr("Нет выбранных строк"), tr("Для удаления, выберите строки или ячейки строк."), QMessageBox::Ok);
    }
}

// ------ Show all Readers
void MainWindow::on_show_all_readers_action_triggered() { UpdateReaderTableWidget(); }

void MainWindow::on_show_all_readers_pushButton_clicked() { UpdateReaderTableWidget(); }

// ------ Search Reader

void MainWindow::on_search_reader_pushButton_clicked() {
    int row;
    if (ui->search_lineEdit->text() != "") {
        if (ui->search_by_FIO_radioButton->isChecked()) {
            QVector<Reader*> results;
            results = library->readersHash->SearchByFIO(ui->search_lineEdit->text());
            if (results.size() != 0) {
                ClearReaderTableWidget();
                foreach (Reader* r, results) {
                    row = ui->reader_tableWidget->rowCount();
                    ui->reader_tableWidget->insertRow(row);
                    AddItemInReaderTableWidget(r, row);
                }
            }
            else {
                QMessageBox::information(this, tr("Совпадения отсутствуют"), tr("Читателей с таким имненем не зарегистрировано."), QMessageBox::Ok);
            }
        } else if (ui->search_by_card_number_radioButton->isChecked()) {
            Reader *r = library->readersHash->SearchByCardNumber(ui->search_lineEdit->text());
            if (r != NULL) {
                ClearReaderTableWidget();
                row = ui->reader_tableWidget->rowCount();
                ui->reader_tableWidget->insertRow(row);
                AddItemInReaderTableWidget(r, row);
            }
            else {
                QMessageBox::information(this, tr("Совпадения отсутствуют"), tr("Читателей с таким номером читательского билета не зарегистрировано."), QMessageBox::Ok);
            }
        }
        else {
            QMessageBox::critical(this, tr("Отсутствуют параметры поиска"), tr("Выберите один из вариантов поиска: поиск по ФИО или поиск по № читательского билета."), QMessageBox::Ok);
        }
    } else {
        QMessageBox::critical(this, tr("Строка поиска пуста"), tr("Заполните строку поиска."), QMessageBox::Ok);
    }
}


