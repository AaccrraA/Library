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
    ui->reader_tableWidget->setRowCount(5);
    ui->reader_tableWidget->setColumnCount(5);

    // --- Setting up main widget
    ui->stackedWidget->setCurrentWidget(ui->library_page);
    ui->library_tabWidget->setCurrentWidget(ui->reader_tab);
    // --- Setting up tables
    QStringList readerLabels, bookLabels, iobooksinfoLabels;
    readerLabels << tr("#") << tr("№ ЧБ") << tr("ФИО") << tr("Год рождения") << tr("Адрес") << tr("Место работы/учебы");
    bookLabels << tr("#") << tr("Шифр") << tr("Автор(ы)") << tr("Название") << tr("Издатель") << tr("Год издания") << tr("Тираж(шт.)") << tr("На складе(шт.)");
    iobooksinfoLabels << tr("#") << tr("№ ЧБ") << tr("Шифр") << tr("Дата выдачи") << tr("Дата приема");
    ui->reader_tableWidget->setColumnCount(readerLabels.length());
    ui->book_tableWidget->setColumnCount(bookLabels.length());
    ui->iobooksinfo_tableWidget->setColumnCount(iobooksinfoLabels.length());
    ui->reader_tableWidget->setRowCount(0);
    ui->book_tableWidget->setRowCount(0);
    ui->iobooksinfo_tableWidget->setRowCount(0);
    ui->reader_tableWidget->setHorizontalHeaderLabels(readerLabels);
    ui->book_tableWidget->setHorizontalHeaderLabels(bookLabels);
    ui->iobooksinfo_tableWidget->setHorizontalHeaderLabels(iobooksinfoLabels);

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

void MainWindow::on_add_reader_action_triggered() { SetupCreateReaderWidget(); }
void MainWindow::on_add_reader_pushButton_clicked() { SetupCreateReaderWidget(); }

void MainWindow::SetupCreateReaderWidget() {
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
        if (library->AddReader(rOfA_str, fio_str, yOfB_str, adress_str, jOrSP_str)) {
            // Вывести поздравление
            QMessageBox::information(this, "Алилуя!", "Новый читатель успешно добавленв библиотеку.", QMessageBox::Ok);
            ui->stackedWidget->setCurrentWidget(ui->library_page);
        }
        else {
            // Вывести ошибку о попытке добавления существующего читателя
        }
    }
    else {
        // Вывести ошибку о заполнении полей
    }
}

void MainWindow::on_search_reader_action_triggered() {
}
