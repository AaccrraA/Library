#include "aboutdilog.h"
#include "ui_aboutdilog.h"

AboutDilog::AboutDilog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDilog)
{
    ui->setupUi(this);
}

AboutDilog::~AboutDilog()
{
    delete ui;
}

void AboutDilog::on_pushButton_clicked() {
    this->close();
}
