#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "library.h"

MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent),
                                            ui(new Ui::MainWindow) {
    library = NULL;
    ui->setupUi(this);

    bookSections.insert("Художественная литература", 0);
    bookSections.insert("Литература для детей", 0);
    bookSections.insert("Учебная литература для школы", 0);
    bookSections.insert("Иностранные языки", 0);
    bookSections.insert("Краеведение", 0);
    bookSections.insert("Искусство", 0);
    bookSections.insert("Бизнес, экономика и право", 0);
    bookSections.insert("Компьютерная литература", 0);
    bookSections.insert("Психология и эзотерика", 0);
    bookSections.insert("Медицина, здоровье, дети", 0);
    bookSections.insert("Домашний круг", 0);
    bookSections.insert("Научная литература", 0);
    bookSections.insert("История и политика", 0);
    bookSections.insert("Путешествия, автомобили, спорт", 0);
    QHashIterator<QString, qint32> i(bookSections);
    while (i.hasNext()) {
        i.next();
        ui->cb_section_comboBox->addItem(i.key());
    }

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

    // --- Enabling(Disenabling) editing tables
    //ui->reader_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->book_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->iobooksinfo_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ClearTableWidget(QTableWidget* tw) {
    while (tw->rowCount() > 0) {
        tw->removeRow(0);
    }
}

// ---------------
// --- LIBRARY ---
// ---------------
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



// --------------
// --- READER ---
// --------------
void MainWindow::UpdateReaderTableWidget() {
    ClearTableWidget(ui->reader_tableWidget);
    for (int i = 0; i < library->readersHash->GetSize(); ++i) {
        if (library->readersHash->At(i) != NULL) {
            int row = ui->reader_tableWidget->rowCount();
            ui->reader_tableWidget->insertRow(row);
            AddItemInReaderTableWidget(library->readersHash->At(i), row);
        }
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

void MainWindow::AddItemInReaderTableWidget(Reader* r, int row) {
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
    if (library->readersHash->GetSize() > 0) {
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
        QMessageBox::critical(this, tr("Нет читателей"), tr("Отстствуют записи для удаления"), QMessageBox::Ok);
    }
}

// ------ Show all Readers
void MainWindow::on_show_all_readers_action_triggered() { UpdateReaderTableWidget(); }

void MainWindow::on_show_all_readers_pushButton_clicked() { UpdateReaderTableWidget(); }

// ------ Search Reader

void MainWindow::on_search_reader_pushButton_clicked() {
    int row;
    if (ui->search_reader_lineEdit->text() != "") {
        if (ui->search_reader_by_FIO_radioButton->isChecked()) {
            QVector<Reader*> results;
            results = library->readersHash->SearchByFIO(ui->search_reader_lineEdit->text());
            if (results.size() != 0) {
                ClearTableWidget(ui->reader_tableWidget);
                foreach (Reader* r, results) {
                    row = ui->reader_tableWidget->rowCount();
                    ui->reader_tableWidget->insertRow(row);
                    AddItemInReaderTableWidget(r, row);
                }
            }
            else {
                QMessageBox::information(this, tr("Совпадения отсутствуют"), tr("Читателей с таким имненем не зарегистрировано."), QMessageBox::Ok);
            }
        } else if (ui->search_reader_by_card_number_radioButton->isChecked()) {
            Reader *r = library->readersHash->SearchByCardNumber(ui->search_reader_lineEdit->text());
            if (r != NULL) {
                ClearTableWidget(ui->reader_tableWidget);
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

// ------------
// --- BOOK ---
// ------------
void MainWindow::UpdateBookTableWidget() {
    ClearTableWidget(ui->book_tableWidget);
    QVector<Book*> vector = library->bookAVLTree->GetVectorOfBooks();
    foreach (Book* b, vector) {
        int row = ui->book_tableWidget->rowCount();
        ui->book_tableWidget->insertRow(row);
        AddItemInBookTableWidget(b, row);
    }
}

// ------ Create Book
void MainWindow::AddItemInBookTableWidget(Book* b, int row) {
    ui->book_tableWidget->setItem(row, 0, new QTableWidgetItem(b->getCode()));
    ui->book_tableWidget->setItem(row, 1, new QTableWidgetItem(b->getAuthors()));
    ui->book_tableWidget->setItem(row, 2, new QTableWidgetItem(b->getTitle()));
    ui->book_tableWidget->setItem(row, 3, new QTableWidgetItem(b->getPublisher()));
    ui->book_tableWidget->setItem(row, 4, new QTableWidgetItem(b->getYearOfPublication()));
    ui->book_tableWidget->setItem(row, 5, new QTableWidgetItem(b->getAllCopies()));
    ui->book_tableWidget->setItem(row, 6, new QTableWidgetItem(b->getCopiesInStock()));
}

void MainWindow::on_add_book_pushButton_clicked() { CreateBook(); }

void MainWindow::on_add_book_action_triggered() { CreateBook(); }

void MainWindow::CreateBook() {
    ui->cb_section_count_label->setText(QString::number(bookSections.value(ui->cb_section_comboBox->currentText())));
    // --- Setting up Create Book Page
    ui->cb_section_comboBox->setCurrentIndex(0);
    ui->cb_authors_lineEdit->setText("");
    ui->cb_title_lineEdit->setText("");
    ui->cb_publisher_lineEdit->setText("");
    ui->cb_year_of_publication_lineEdit->setText("");
    ui->cb_all_copies_lineEdit->setText("");
    ui->cb_copies_in_stock_lineEdit->setText("");
    // --- Show Create Reader Page
    ui->stackedWidget->setCurrentWidget(ui->create_book_page);
}

void MainWindow::on_cb_ok_pushButton_clicked() {
    bool isCorrectForm = true;

    QString sectionId_str = QString::number(ui->cb_section_comboBox->currentIndex());
    QString copies_in_section_str = QString::number(bookSections.value(ui->cb_section_comboBox->currentText()));
    QString authors_str = ui->cb_authors_lineEdit->text();
    QString title_str = ui->cb_title_lineEdit->text();
    QString publisher_str = ui->cb_publisher_lineEdit->text();
    QString yOfP_str = ui->cb_year_of_publication_lineEdit->text();
    QString all_copies_str = ui->cb_all_copies_lineEdit->text();
    QString copies_in_stock_str = ui->cb_copies_in_stock_lineEdit->text();

    QRegExp authors_rexp("");
    QRegExp title_rexp("");
    QRegExp publisher_rexp("");
    QRegExp yOfP_rexp("");
    QRegExp all_copies_rexp("");
    QRegExp copies_in_stock_rexp("");

    QString errorMsg = tr("Ошибка в поле ");
    if (authors_rexp.indexIn(authors_str) < 0) {
        // Не павильная фамилия
        isCorrectForm = false;
        errorMsg += ui->cb_authors_label->text();
        QMessageBox::critical(this, errorMsg, tr("Следующие поля заполнены неверно:"), QMessageBox::Ok);
    }
    else if (title_rexp.indexIn(title_str) < 0) {
        // Не правильный год рождения
        isCorrectForm = false;
        errorMsg += ui->cb_title_label->text();
        QMessageBox::critical(this, errorMsg, tr("Следующие поля заполнены неверно:"), QMessageBox::Ok);
    }
    else if (publisher_rexp.indexIn(publisher_str) < 0) {
        // Не правильный адрес
        isCorrectForm = false;
        errorMsg += ui->cb_publisher_label->text();
        QMessageBox::critical(this, errorMsg, tr("Следующие поля заполнены неверно:"), QMessageBox::Ok);
    }
    else if (yOfP_rexp.indexIn(yOfP_str) < 0) {
        // Не правильная работа
        isCorrectForm = false;
        errorMsg += ui->cb_year_of_publishing_label->text();
        QMessageBox::critical(this, errorMsg, tr("Следующие поля заполнены неверно:"), QMessageBox::Ok);
    }
    else if (all_copies_rexp.indexIn(all_copies_str) < 0) {
        // Не правильный адрес
        isCorrectForm = false;
        errorMsg += ui->cb_all_copies_label->text();
        QMessageBox::critical(this, errorMsg, tr("Следующие поля заполнены неверно:"), QMessageBox::Ok);
    }
    else if (copies_in_stock_rexp.indexIn(copies_in_stock_str) < 0) {
        // Не правильная работа
        isCorrectForm = false;
        errorMsg += ui->cb_copies_in_stock_label->text();
        QMessageBox::critical(this, errorMsg, tr("Следующие поля заполнены неверно:"), QMessageBox::Ok);
    }
    else if (isCorrectForm) {
        Book* r = library->AddBook(sectionId_str, copies_in_section_str, authors_str, title_str, publisher_str, yOfP_str, all_copies_str, copies_in_stock_str);
        if (r != NULL) {
            UpdateBookTableWidget();
            QString str = ui->cb_section_comboBox->currentText();
            //bookSections.insert(bookSections.find(ui->cb_section_comboBox->currentText()), ui->cb_section_comboBox->currentText(), bookSections.value(ui->cb_section_comboBox->currentText())+1)
            bookSections.insert(str, bookSections.value(ui->cb_section_comboBox->currentText())+1);
            ui->stackedWidget->setCurrentWidget(ui->library_page);
            ui->library_tabWidget->setCurrentWidget(ui->book_tab);
        }
        else {
            QMessageBox::critical(this, tr("Ошибка"), tr("Книга с таки шифром уже содержится."), QMessageBox::Ok);
        }
    }
}

void MainWindow::on_cb_cancel_pushButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->library_page);
    ui->library_tabWidget->setCurrentWidget(ui->book_tab);
}

// ------ Delete Book
void MainWindow::on_delete_book_pushButton_clicked() { DeleteBook(); }

void MainWindow::on_delete_book_action_triggered() { DeleteBook(); }

void MainWindow::DeleteBook() {
    QList<QTableWidgetItem*> selectionRangeList = ui->book_tableWidget->selectedItems();
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
                    QTableWidgetItem *item = ui->book_tableWidget->item(rowIndex, 0);
                    library->DeleteBook(item->text());
                }
                break;
            case QMessageBox::Cancel:
                break;
        }
        UpdateBookTableWidget();
    } else {
        QMessageBox::critical(this, tr("Нет выбранных строк"), tr("Для удаления, выберите строки или ячейки строк."), QMessageBox::Ok);
    }
}

// ------ Delete All Books
void MainWindow::on_delete_all_books_pushButton_clicked() { DeleteAllBooks(); }

void MainWindow::on_delete_all_books_action_triggered() { DeleteAllBooks(); }

void MainWindow::DeleteAllBooks() {
    if (library->bookAVLTree->root != NULL) {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Стереть все записи?"));
        msgBox.setInformativeText(tr("Вы уверены, что хотите стереть все записи таблицы \"Читатели\"?"));
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Ok:
                library->DeleteAllBooks();
                break;
            case QMessageBox::Cancel:
                break;
        }
        UpdateBookTableWidget();
    } else {
        QMessageBox::critical(this, tr("Нет читателей"), tr("Отстствуют записи для удаления"), QMessageBox::Ok);
    }
}













void MainWindow::on_cb_section_comboBox_currentIndexChanged(const QString &arg1) {
    ui->cb_section_count_label->setText(QString::number(bookSections.value(ui->cb_section_comboBox->currentText())));
}
