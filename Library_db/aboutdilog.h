#ifndef ABOUTDILOG_H
#define ABOUTDILOG_H

#include <QDialog>

namespace Ui {
class AboutDilog;
}

class AboutDilog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDilog(QWidget *parent = 0);
    ~AboutDilog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AboutDilog *ui;
};

#endif // ABOUTDILOG_H
