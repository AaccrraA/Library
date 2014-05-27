/********************************************************************************
** Form generated from reading UI file 'aboutdilog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDILOG_H
#define UI_ABOUTDILOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDilog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *AboutDilog)
    {
        if (AboutDilog->objectName().isEmpty())
            AboutDilog->setObjectName(QStringLiteral("AboutDilog"));
        AboutDilog->setEnabled(true);
        AboutDilog->resize(383, 135);
        AboutDilog->setMinimumSize(QSize(383, 135));
        AboutDilog->setMaximumSize(QSize(383, 135));
        verticalLayout = new QVBoxLayout(AboutDilog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(AboutDilog);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(AboutDilog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(AboutDilog);

        QMetaObject::connectSlotsByName(AboutDilog);
    } // setupUi

    void retranslateUi(QDialog *AboutDilog)
    {
        AboutDilog->setWindowTitle(QApplication::translate("AboutDilog", "Dialog", 0));
        label->setText(QApplication::translate("AboutDilog", "\320\232\321\203\321\200\321\201\320\276\320\262\320\276\320\271 \320\277\321\200\320\276\320\265\320\272\321\202 \"\320\237\321\200\320\270\320\265\320\274 \320\270 \320\262\321\213\320\264\320\260\321\207\320\260 \320\272\320\275\320\270\320\263 \320\262 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\265\" \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\276\320\274 \320\263\321\200. 4236 \320\222\320\276\321\200\320\276\320\275\320\276\320\262\321\213\320\274 \320\225\320\262\320\263\320\265\320\275\320\270\320\265\320\274. All rights reserved (c) 2014", 0));
        pushButton->setText(QApplication::translate("AboutDilog", "\320\222\320\276\321\201\321\205\320\270\321\202\320\270\321\202\320\265\320\273\321\214\320\275\320\276", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutDilog: public Ui_AboutDilog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDILOG_H
