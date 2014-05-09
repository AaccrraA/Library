#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createreaderwidget.h"
#include "ui_createreaderwidget.h"

#include "library.h"

MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent),
                                            ui(new Ui::MainWindow) {
    library = NULL;
    ui->setupUi(this);

    ui->reader_menu->setEnabled(false);
    ui->book_menu->setEnabled(false);
    ui->iobooksinfo_menu->setEnabled(false);
    ui->stackedWidget->setEnabled(false);
    ui->save_library_action->setEnabled(false);
    ui->save_as_library_action->setEnabled(false);
    ui->reader_tableWidget->setRowCount(5);
    ui->reader_tableWidget->setColumnCount(5);

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

void MainWindow::on_add_reader_action_triggered() {
    AddReaderToLibrary();
}

void MainWindow::on_add_reader_pushButton_clicked() {
    AddReaderToLibrary();
}

void MainWindow::AddReaderToLibrary() {
    ui->stackedWidget->setCurrentIndex(ui->create_reader_page);
    Reader* newReader = CreateReader();
    if (newReader != NULL) {
        library->AddReader(newReader);
    }
    else {
        ui->stackedWidget->setCurrentWidget(ui->library_page);
    }
}

Reader* MainWindow::CreateReader() {
    Reader *newReader = new Reader;
    return NULL;
}

void MainWindow::on_search_reader_action_triggered() {
}

void MainWindow::on_ok_pushButton_clicked() {
    /*
    bool isCorrectForm = true;

    QString fio_txt = this->ui->fio_lineEdit->text();
    //QString yOfB_txt = this->ui->year_of_birth_lineEdit->text();
    QString adress_txt = this->ui->adress_lineEdit->text();
    QString jOrSP_txt = this->ui->job_or_study_place_lineEdit->text();

    CleanField(fio_txt);
    CleanField(adress_txt);
    CleanField(jOrSP_txt);

    if (fio_txt.isEmpty() || adress_txt.isEmpty() || jOrSP_txt.isEmpty())
        isCorrectForm = false;

    if (!isCorrectForm)
    {
        QMessageBox::StandardButton msgBox = QMessageBox::warning(this, "Ошибка заполнения",
                                                                  "Заполните все поля.",
                                                                  QMessageBox::Ok);
    }
    else
    {
        switch (this->ui->right_of_acces_comboBox->currentIndex()) {
        case 0:
            rOfA = "А";
            break;
        case 1:
            rOfA = "Ч";
            break;
        case 2:
            rOfA = "В";
            break;
        default:
            qDebug() << "Error: Incorrect value of right_of_acces_comboBox->currentIndex() in CreateReaderDialog.";
            break;
        }
        fio = this->ui->fio_lineEdit->text();
        //yOfB = this->ui->year_of_birth_lineEdit->text().toInt();
        adress = this->ui->adress_lineEdit->text();
        jOrSP = this->ui->job_or_study_place_lineEdit->text();
        this->close();
    }*/
}
