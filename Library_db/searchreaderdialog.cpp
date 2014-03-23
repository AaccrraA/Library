#include "searchreaderdialog.h"
#include "ui_searchreaderdialog.h"

#include <QDebug>

SearchReaderDialog::SearchReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchReaderDialog)
{
    ui->setupUi(this);
    QButtonGroup *bg = new QButtonGroup(this);
    bg->addButton(ui->card_number_radioButton);
    bg->addButton(ui->fio_radioButton);
    bg->setId(ui->card_number_radioButton, 0);
    bg->setId(ui->fio_radioButton, 1);
    ui->card_number_radioButton->setChecked(true);
}

SearchReaderDialog::~SearchReaderDialog()
{
    delete ui;
}

// Search Button Clicked
void SearchReaderDialog::on_search_pushButton_clicked()
{
    bool isCorrectForm = true;

}

// Cancel Button Clicked
void SearchReaderDialog::on_cancel_pushButton_clicked()
{
    this->close();
}
