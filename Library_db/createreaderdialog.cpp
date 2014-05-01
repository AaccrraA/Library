#include "createreaderdialog.h"
#include "ui_createreaderdialog.h"

CreateReaderDialog::CreateReaderDialog(QWidget *parent) : QDialog(parent), ui(new Ui::CreateReaderDialog)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle("Добавление нового читателя");
}

CreateReaderDialog::~CreateReaderDialog()
{
    delete ui;
}

// Ok Button Clicked
void CreateReaderDialog::on_ok_pushButton_clicked()
{
    bool isCorrectForm = true;

    QString fio_txt = this->ui->fio_lineEdit->text();
    QString yOfB_txt = ui->year_of_birth_lineEdit->text();
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
    }
}

// Cancel Button Clicked
void CreateReaderDialog::on_cancel_pushButton_clicked()
{
    this->close();
}

void CreateReaderDialog::CleanField(QString &field)
{
    bool isWordStarted = false;
    for (int i = 0; i < field.length(); i++)
    {
        if (field[i] == ' ' && !isWordStarted)
        {
            field.remove(i, 1);
            i--;
        }
        else if (field[i] != ' ' && !isWordStarted)
            isWordStarted = true;
        else if (field[i] == ' ' && isWordStarted)
            isWordStarted = false;
    }
}

QString CreateReaderDialog::getROfA()
{
    return rOfA;
}

QString CreateReaderDialog::getFio()
{
    return fio;
}

int CreateReaderDialog::getYOfB()
{
    return yOfB;
}

QString CreateReaderDialog::getAdress()
{
    return adress;
}

QString CreateReaderDialog::getJOrSP()
{
    return jOrSP;
}






