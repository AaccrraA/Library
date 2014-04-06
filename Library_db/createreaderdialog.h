#ifndef CREATEREADERDIALOG_H
#define CREATEREADERDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
    class CreateReaderDialog;
}

class CreateReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateReaderDialog(QWidget *parent = 0);
    ~CreateReaderDialog();

    QString getROfA();
    QString getFio();
    int getYOfB();
    QString getAdress();
    QString getJOrSP();

private slots:
    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    Ui::CreateReaderDialog *ui;

    QString rOfA;
    QString fio;
    int yOfB;
    QString adress;
    QString jOrSP;

    bool IsCorrectForm();
    void CleanField(QString &field);
};

#endif // CREATEREADERDIALOG_H
