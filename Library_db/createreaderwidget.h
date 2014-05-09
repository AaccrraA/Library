#ifndef CREATEREADERWIDGET_H
#define CREATEREADERWIDGET_H

#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QWidget>
#include <library.h>

namespace Ui {
class CreateReaderWidget;
}

class CreateReaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateReaderWidget(QWidget *parent = 0);
    ~CreateReaderWidget();

private slots:
    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    Ui::CreateReaderWidget *ui;
    Reader* newReader_;

    void CleanField(QString &field);
};

#endif // CREATEREADERWIDGET_H
