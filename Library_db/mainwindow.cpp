#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "library.h"
#include "aboutdilog.h"

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
    ui->reader_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->book_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->iobooksinfo_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
    qint32 row;
    for (qint32 i = 0; i < library->readersHash->GetSize(); ++i) {
        if (library->readersHash->At(i) != NULL) {
            row = ui->reader_tableWidget->rowCount();
            ui->reader_tableWidget->insertRow(row);
            AddReaderInTableWidget(library->readersHash->At(i),ui->reader_tableWidget, row);
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
    QString rOfA_str = QString::number(ui->cr_right_of_acces_comboBox->currentIndex());
    QString fio_str = ui->cr_fio_lineEdit->text();
    QString yOfB_str = ui->cr_year_of_birth_lineEdit->text();
    QString adress_str = ui->cr_adress_lineEdit->text();
    QString jOrSP_str = ui->cr_job_or_study_place_lineEdit->text();

    QRegExp fio_rexp("[A-Z, a-z, А-Я, а-я]");
    QRegExp yOfB_rexp("[0-9]{4}");
    QRegExp adress_rexp("");
    QRegExp jOrSP_rexp("");

    int yOfB = yOfB_str.toInt(0,10);
    QDate date = QDate::currentDate();

    if (fio_rexp.indexIn(fio_str) < 0) {
        // Не павильная фамилия
        QMessageBox::critical(this, tr("Заполнение поля"), tr("Поле фамилия заполнено неверно."), QMessageBox::Ok);
    }
    else if (yOfB_rexp.indexIn(yOfB_str) < 0 || yOfB > date.year() || yOfB < date.year()-100) {
        // Не правильный год рождения
        QMessageBox::critical(this, tr("Заполнение поля"), tr("Поле год рождения заполнено неверно."), QMessageBox::Ok);
    }
    else if (adress_rexp.indexIn(adress_str) < 0) {
        // Не правильный адрес
        QMessageBox::critical(this, tr("Заполнение поля"), tr("Поле адрес заполнено неверно."), QMessageBox::Ok);
    }
    else if (jOrSP_rexp.indexIn(jOrSP_str) < 0) {
        // Не правильная работа
        QMessageBox::critical(this, tr("Заполнение поля"), tr("Поле место работы или учебы заполнено неверно."), QMessageBox::Ok);
    }
    else {
        Reader* r = library->AddReader(rOfA_str, fio_str, yOfB_str, adress_str, jOrSP_str);
        if (r != NULL) {
            UpdateReaderTableWidget();
            //QMessageBox::information(this, tr("Читатель добавлен"), tr("Новый читатель успешно добавлен в библиотеку."), QMessageBox::Ok);
            ui->stackedWidget->setCurrentWidget(ui->library_page);
            ui->library_tabWidget->setCurrentWidget(ui->reader_tab);
        }
        else {
            // Вывести ошибку о попытке добавления существующего читателя
            QMessageBox::critical(this, tr("Ошибка"), tr("Такой читатель уже зарегистрирован."), QMessageBox::Ok);
        }
    }
}

void MainWindow::on_cr_cancel_pushButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->library_page);
    ui->library_tabWidget->setCurrentWidget(ui->reader_tab);
}

void MainWindow::AddReaderInTableWidget(Reader* r, QTableWidget* tw, qint32 row) {
    tw->setItem(row, 0, new QTableWidgetItem(QString::number(r->getHashIndex())));
    tw->setItem(row, 1, new QTableWidgetItem(r->getCardNumber()));
    tw->setItem(row, 2, new QTableWidgetItem(r->getFio()));
    tw->setItem(row, 3, new QTableWidgetItem(r->getYearOfBirth()));
    tw->setItem(row, 4, new QTableWidgetItem(r->getAdress()));
    tw->setItem(row, 5, new QTableWidgetItem(r->getJobOrStudyPlace()));
}

// ------ Delete Reader
void MainWindow::on_delete_reader_action_triggered() { DeleteReader(); }

void MainWindow::on_delete_reader_pushButton_clicked() { DeleteReader(); }

void MainWindow::DeleteReader() {
    QList<QTableWidgetItem*> selectionRangeList = this->ui->reader_tableWidget->selectedItems();
    qint32 rowIndex;
    QListIterator<QTableWidgetItem*> selectionRangeListIter(selectionRangeList);

    if (selectionRangeList.size() > 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Удалить строки"));
        msgBox.setInformativeText(tr("Вы уверены, что хотите удалить выбранные строки?"));
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        qint32 ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Ok:
                while(selectionRangeListIter.hasNext()){
                    rowIndex = ((int)((QTableWidgetItem*)selectionRangeListIter.next())->row());
                    QTableWidgetItem *item = ui->reader_tableWidget->item(rowIndex, 0);
                    library->readersHash->Delete(item->text().toInt(0, 10));
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
        qint32 ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Ok:
                for (qint32 i = 0; i < library->readersHash->GetSize()-1; ++i) {
                    library->readersHash->Delete(i);
                }
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

    qint32 row;
    QVector<Reader*> results;
    if (ui->search_reader_lineEdit->text() != "") {
        if (ui->search_reader_by_FIO_radioButton->isChecked()) {
            results = library->readersHash->SearchByFIO(ui->search_reader_lineEdit->text());
        } else if (ui->search_reader_by_card_number_radioButton->isChecked()) {
            results = library->readersHash->SearchByCardNumber(ui->search_reader_lineEdit->text());
        }
        else {
            QMessageBox::critical(this, tr("Отсутствуют параметры поиска"), tr("Выберите один из вариантов поиска."), QMessageBox::Ok);
            return;
        }
    } else {
        QMessageBox::critical(this, tr("Строка поиска пуста"), tr("Заполните строку поиска."), QMessageBox::Ok);
        return;
    }

    if (results.size() != 0) {
        ClearTableWidget(ui->reader_tableWidget);
        foreach (Reader* r, results) {
            row = ui->reader_tableWidget->rowCount();
            ui->reader_tableWidget->insertRow(row);
            AddReaderInTableWidget(r, ui->reader_tableWidget, row);
        }
    }
    else {
        QMessageBox::information(this, tr("Совпадения отсутствуют"), tr("Читателей не найдено."), QMessageBox::Ok);
    }
}

// ------------
// --- BOOK ---
// ------------
void MainWindow::UpdateBookTableWidget() {
    ClearTableWidget(ui->book_tableWidget);
    QVector<Book*> vector = library->bookAVLTree->GetVectorOfBooks();
    qint32 row;
    foreach (Book* b, vector) {
        row = ui->book_tableWidget->rowCount();
        ui->book_tableWidget->insertRow(row);
        AddBookInTableWidget(b, ui->book_tableWidget, row);
    }
}

// ------ Create Book
void MainWindow::AddBookInTableWidget(Book* b, QTableWidget* tw, qint32 row) {
    tw->setItem(row, 0, new QTableWidgetItem(b->getCode()));
    tw->setItem(row, 1, new QTableWidgetItem(b->getAuthors()));
    tw->setItem(row, 2, new QTableWidgetItem(b->getTitle()));
    tw->setItem(row, 3, new QTableWidgetItem(b->getPublisher()));
    tw->setItem(row, 4, new QTableWidgetItem(b->getYearOfPublication()));
    tw->setItem(row, 5, new QTableWidgetItem(b->getAllCopies()));
    tw->setItem(row, 6, new QTableWidgetItem(b->getCopiesInStock()));
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
    QString sectionId_str = QString::number(ui->cb_section_comboBox->currentIndex());
    QString copies_in_section_str = QString::number(bookSections.value(ui->cb_section_comboBox->currentText()));
    QString authors_str = ui->cb_authors_lineEdit->text();
    QString title_str = ui->cb_title_lineEdit->text();
    QString publisher_str = ui->cb_publisher_lineEdit->text();
    QString yOfP_str = ui->cb_year_of_publication_lineEdit->text();
    QString all_copies_str = ui->cb_all_copies_lineEdit->text();
    QString copies_in_stock_str = ui->cb_copies_in_stock_lineEdit->text();

    QRegExp authors_rexp("[A-Z, a-z, А-Я, а-я]");
    QRegExp title_rexp("");
    QRegExp publisher_rexp("");
    QRegExp yOfP_rexp("[0-9]{4}");
    QRegExp all_copies_rexp("[0-9]");
    QRegExp copies_in_stock_rexp("[0-9]");

    int yOfP = yOfP_str.toInt(0,10);
    QDate date = QDate::currentDate();

    QString errorMsg = tr("Ошибка заполнения ");
    if (authors_rexp.indexIn(authors_str) < 0) {
        // Не павильный автор(ы)
        errorMsg += ui->cb_authors_label->text();
        QMessageBox::critical(this, errorMsg, tr("Поле \"Автор(ы)\" заполнено неверно."), QMessageBox::Ok);
    }
    else if (title_rexp.indexIn(title_str) < 0) {
        // Не правильное название
        errorMsg += ui->cb_title_label->text();
        QMessageBox::critical(this, errorMsg, tr("Поле \"Название\" заполнено неверно."), QMessageBox::Ok);
    }
    else if (publisher_rexp.indexIn(publisher_str) < 0) {
        // Не правильный издатель
        errorMsg += ui->cb_publisher_label->text();
        QMessageBox::critical(this, errorMsg, tr("Поле \"Издатель\" заполнено неверно."), QMessageBox::Ok);
    }
    else if (yOfP_rexp.indexIn(yOfP_str) < 0 || yOfP > date.year()) {
        // Не правильный год публикации
        errorMsg += ui->cb_year_of_publishing_label->text();
        QMessageBox::critical(this, errorMsg, tr("Поле \"Год публикации\" заполнено неверно."), QMessageBox::Ok);
    }
    else if (all_copies_rexp.indexIn(all_copies_str) < 0 || all_copies_str.toInt() <= 0) {
        // Не правильный тираж
        errorMsg += ui->cb_all_copies_label->text();
        QMessageBox::critical(this, errorMsg, tr("Поле \"Тираж\" заполнено неверно."), QMessageBox::Ok);
    }
    else if (copies_in_stock_rexp.indexIn(copies_in_stock_str) < 0 || copies_in_stock_str.toInt() > all_copies_str.toInt() || copies_in_stock_str.toInt() <=0 ) {
        // Не правильное в наличии
        errorMsg += ui->cb_copies_in_stock_label->text();
        QMessageBox::critical(this, errorMsg, tr("Поле \"В наличии\" заполнено неверно."), QMessageBox::Ok);
    }
    else {
        Book* r = new Book((library->GenerateCode(sectionId_str, copies_in_section_str)),authors_str, title_str, publisher_str, yOfP_str, all_copies_str, copies_in_stock_str);
        Book* temp = library->bookAVLTree->IsExists(r);
        if (temp == NULL) {
            library->bookAVLTree->root = library->bookAVLTree->Add(library->bookAVLTree->root, r);
            bookSections.insert(ui->cb_section_comboBox->currentText(), bookSections.value(ui->cb_section_comboBox->currentText()) + copies_in_stock_str.toInt());
        }
        else {
            QMessageBox msgBox;
            msgBox.setWindowTitle(tr("Внимание!"));
            msgBox.setText("Пополнить запас книг?"); // Заголовок сообщения
            msgBox.setInformativeText(tr("В таблице уже содержится данная книга, вы можете пополнить их кол-во. Для подтверждения нажмите \"ОК\"."));
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Ok);
            qint32 ret = msgBox.exec();
            switch (ret) {
                case QMessageBox::Ok:
                    temp->setCopiesInStock(QString::number(temp->getCopiesInStock().toInt() + copies_in_stock_str.toInt()));
                    bookSections.insert(ui->cb_section_comboBox->currentText(), bookSections.value(ui->cb_section_comboBox->currentText())+ copies_in_stock_str.toInt());
                    break;
                case QMessageBox::Cancel:
                    break;
            }
        }
        UpdateBookTableWidget();
        ui->stackedWidget->setCurrentWidget(ui->library_page);
        ui->library_tabWidget->setCurrentWidget(ui->book_tab);
    }
}

void MainWindow::on_cb_cancel_pushButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->library_page);
    ui->library_tabWidget->setCurrentWidget(ui->book_tab);
}

void MainWindow::on_cb_section_comboBox_currentIndexChanged(const QString &arg1) {
    ui->cb_section_count_label->setText(QString::number(bookSections.value(ui->cb_section_comboBox->currentText())));
}

// ------ Delete Book
void MainWindow::on_delete_book_pushButton_clicked() { DeleteBook(); }

void MainWindow::on_delete_book_action_triggered() { DeleteBook(); }

void MainWindow::DeleteBook() {
    QList<QTableWidgetItem*> selectionRangeList = ui->book_tableWidget->selectedItems();
    qint32 rowIndex;
    QListIterator<QTableWidgetItem*> selectionRangeListIter(selectionRangeList);

    if (selectionRangeList.size() > 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Внимание!"));
        msgBox.setText("Удалить выбранные строки?"); // Заголовок сообщения
        msgBox.setInformativeText(tr("Выбранные стоки будут безвозвратно стерты из таблицы. Для подтверждения нажмите \"ОК\"."));
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        qint32 ret = msgBox.exec();
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
        qint32 ret = msgBox.exec();
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

// ------ Show All Books
void MainWindow::on_show_all_books_pushButton_clicked() { UpdateBookTableWidget(); }

void MainWindow::on_show_all_books_action_triggered() { UpdateBookTableWidget(); }

// ------ Search Book
void MainWindow::on_search_book_pushButton_clicked() {
    qint32 row;
    if (ui->search_book_lineEdit->text() != "") {
        if (ui->search_book_by_author_or_title_radioButton->isChecked()) {
            QVector<Book*> results;
            results = library->bookAVLTree->SearchByAuthorsOrTitle(ui->search_book_lineEdit->text());
            if (results.size() != 0) {
                ClearTableWidget(ui->book_tableWidget);
                foreach (Book* b, results) {
                    row = ui->book_tableWidget->rowCount();
                    ui->book_tableWidget->insertRow(row);
                    AddBookInTableWidget(b, ui->book_tableWidget, row);
                }
            }
            else {
                QMessageBox::information(this, tr("Совпадения отсутствуют"), tr("Поиск не дал результатов."), QMessageBox::Ok);
            }
        } else if (ui->search_book_by_Code_radioButton->isChecked()) {
            Book *b = library->bookAVLTree->SearchByCode(ui->search_book_lineEdit->text());
            if (b != NULL) {
                ClearTableWidget(ui->book_tableWidget);
                row = ui->book_tableWidget->rowCount();
                ui->book_tableWidget->insertRow(row);
                AddBookInTableWidget(b, ui->book_tableWidget, row);
            }
            else {
                QMessageBox::information(this, tr("Совпадения отсутствуют"), tr("Поиск не дал результатов."), QMessageBox::Ok);
            }
        }
        else {
            QMessageBox::critical(this, tr("Отсутствуют параметры поиска"), tr("Выберите один из вариантов поиска."), QMessageBox::Ok);
        }
    } else {
        QMessageBox::critical(this, tr("Строка поиска пуста"), tr("Заполните строку поиска."), QMessageBox::Ok);
    }
}

// -------------- //
// --- IOINFO --- //
// -------------- //

void MainWindow::on_give_book_pushButton_clicked() { GiveBook(); }

void MainWindow::on_give_book_action_triggered() { GiveBook(); }

void MainWindow::GiveBook() {
    ui->gb_readers_comboBox->clear();
    for (qint32 i = 0; i < library->readersHash->GetSize(); ++i) {
        if (library->readersHash->At(i) != NULL) {
            QString str = library->readersHash->At(i)->getFio() + "/" + library->readersHash->At(i)->getCardNumber();
            ui->gb_readers_comboBox->addItem(str);
        }
    }

    ui->gb_books_comboBox->clear();
    QVector<Book*> vector = library->bookAVLTree->GetVectorOfBooks();
    foreach (Book* b, vector) {
        if (b->getCopiesInStock() > 0) {
            QString str = b->getTitle() + "/" + b->getCode();
            ui->gb_books_comboBox->addItem(str);
        }
    }
    if (ui->gb_readers_comboBox->count() == 0) {
        QMessageBox::information(this, tr("Нет читателей"), tr("Добавьте читателей для выдачи им книг."), QMessageBox::Ok);
    }
    else if (ui->gb_books_comboBox->count() == 0) {
        QMessageBox::information(this, tr("Нет книг"), tr("Добавьте книги для выдачи их читателям."), QMessageBox::Ok);
    }
    else {
        QDate date = QDate::currentDate();
        ui->gb_giving_dateEdit->setDate(date);
        date = date.addMonths(1);
        ui->gb_taking_dateEdit->setDate(date);
        ui->stackedWidget->setCurrentWidget(ui->give_book_page);
    }
}

void MainWindow::on_gb_give_book_pushButton_clicked() {
    if (ui->gb_giving_dateEdit->date() < ui->gb_taking_dateEdit->date()) {
        QString readerCardNumber = ui->gb_readers_comboBox->currentText();
        QString bookCode = ui->gb_books_comboBox->currentText();
        QString givingDate = ui->gb_giving_dateEdit->date().toString("dd.MM.yy");
        QString takingDate = ui->gb_taking_dateEdit->date().toString("dd.MM.yy");;
        for (qint32 i = 0; i < readerCardNumber.length(); ++i) {
            if (readerCardNumber.at(i) != '/') {
                readerCardNumber.remove(i, 1);
                --i;
            }
            else {
                readerCardNumber.remove(i, 1);
                break;
            }
        }
        for (qint32 i = 0; i < bookCode.length(); ++i) {
            if (bookCode.at(i) != '/') {
                bookCode.remove(i, 1);
                i--;
            }
            else {
                bookCode.remove(i, 1);
                break;
            }
        }
        IOBooksInfo* iobi = new IOBooksInfo(readerCardNumber, bookCode, givingDate, takingDate, NULL, NULL);
        library->ioBooksInfoList->Add(iobi);
        Book* temp = library->bookAVLTree->SearchByCode(bookCode);
        temp->setCopiesInStock(QString::number(temp->getCopiesInStock().toInt() - 1));
        UpdateIOBooksInfoTableWidget();
    }
    else {
        QMessageBox::information(this, tr("Неверная дата приема"), tr("Дата приема должна быть позже даты выдачи."), QMessageBox::Ok);
    }
    ui->stackedWidget->setCurrentWidget(ui->library_page);
    ui->library_tabWidget->setCurrentWidget(ui->iobooksinfo_tab);
}

void MainWindow::AddIOBooksInfoInTableWidget(IOBooksInfo* iobi, QTableWidget* tw, qint32 row) {
    tw->setItem(row, 0, new QTableWidgetItem(iobi->getCardNumber()));
    tw->setItem(row, 1, new QTableWidgetItem(iobi->getCode()));
    tw->setItem(row, 2, new QTableWidgetItem(iobi->getODate()));
    tw->setItem(row, 3, new QTableWidgetItem(iobi->getIDate()));
}

void MainWindow::UpdateIOBooksInfoTableWidget() {
    IOBooksInfo* temp = library->ioBooksInfoList->getFirst();
    qint32 row;
    ClearTableWidget(ui->iobooksinfo_tableWidget);
    while (temp != NULL) {
        row = ui->iobooksinfo_tableWidget->rowCount();
        ui->iobooksinfo_tableWidget->insertRow(row);
        AddIOBooksInfoInTableWidget(temp, ui->iobooksinfo_tableWidget, row);
        temp = temp->getNext();
    }
}

void MainWindow::on_take_iobooksinfo_action_triggered() { TakeBook(); }
void MainWindow::on_take_iobooksinfo_pushButton_clicked() { TakeBook(); }

void MainWindow::TakeBook() {
    QList<QTableWidgetItem*> selectionRangeList = ui->iobooksinfo_tableWidget->selectedItems();
    qint32 rowIndex;
    QListIterator<QTableWidgetItem*> selectionRangeListIter(selectionRangeList);

    if (selectionRangeList.size() > 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Удалить строки"));
        msgBox.setInformativeText(tr("Вы уверены, что хотите принять данные книги? Выбранные строки будут удалены."));
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        qint32 ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Ok:
                while(selectionRangeListIter.hasNext()){
                    rowIndex = ((int)((QTableWidgetItem*)selectionRangeListIter.next())->row());
                    IOBooksInfo* tempIOBI = library->ioBooksInfoList->AtIndex(rowIndex);
                    Book* tempB = library->bookAVLTree->SearchByCode(tempIOBI->getCode());
                    tempB->setCopiesInStock(QString::number(tempB->getCopiesInStock().toInt() + 1));
                    library->ioBooksInfoList->Delete(rowIndex);
                }
                break;
            case QMessageBox::Cancel:
                break;
        }
        UpdateIOBooksInfoTableWidget();
    } else {
        QMessageBox::critical(this, tr("Нет выбранных строк"), tr("Для удаления, выберите строки или ячейки строк."), QMessageBox::Ok);
    }
}

void MainWindow::on_quit_library_action_triggered() {
    this->close();
}

void MainWindow::on_about_help_action_triggered() {
    AboutDilog ad(this);
    ad.exec();
}

void MainWindow::on_gb_cancel_pushButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->library_page);
    ui->library_tabWidget->setCurrentWidget(ui->iobooksinfo_tab);
}
