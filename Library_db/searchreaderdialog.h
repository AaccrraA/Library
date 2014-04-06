#ifndef SEARCHREADERDIALOG_H
#define SEARCHREADERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QString>

namespace Ui {
class SearchReaderDialog;
}

class SearchReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchReaderDialog(QWidget *parent = 0);
    ~SearchReaderDialog();

private slots:
    void on_cancel_pushButton_clicked();

    void on_search_pushButton_clicked();

private:
    Ui::SearchReaderDialog *ui;
};

#endif // SEARCHREADERDIALOG_H
