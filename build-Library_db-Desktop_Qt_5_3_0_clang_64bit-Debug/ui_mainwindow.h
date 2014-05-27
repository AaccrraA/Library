/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *create_library_action;
    QAction *save_library_action;
    QAction *add_reader_action;
    QAction *delete_reader_action;
    QAction *delete_all_readers_action;
    QAction *show_all_readers_action;
    QAction *add_book_action;
    QAction *delete_book_action;
    QAction *delete_all_books_action;
    QAction *show_all_books_action;
    QAction *take_iobooksinfo_action;
    QAction *give_book_action;
    QAction *save_as_library_action;
    QAction *open_library_action;
    QAction *quit_library_action;
    QAction *about_help_action;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *stackedWidget;
    QWidget *library_page;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *library_tabWidget;
    QWidget *reader_tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *reader_tableWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *search_reader_label;
    QLineEdit *search_reader_lineEdit;
    QPushButton *search_reader_pushButton;
    QGroupBox *search_reader_parameters_groupBox;
    QGridLayout *gridLayout;
    QRadioButton *search_reader_by_FIO_radioButton;
    QRadioButton *search_reader_by_card_number_radioButton;
    QVBoxLayout *verticalLayout;
    QPushButton *add_reader_pushButton;
    QPushButton *delete_reader_pushButton;
    QPushButton *delete_all_readers_pushButton;
    QPushButton *show_all_readers_pushButton;
    QSpacerItem *verticalSpacer;
    QWidget *book_tab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *book_tableWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *search_book_label;
    QLineEdit *search_book_lineEdit;
    QPushButton *search_book_pushButton;
    QGroupBox *search_book_parameters_groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *search_book_by_Code_radioButton;
    QRadioButton *search_book_by_author_or_title_radioButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *add_book_pushButton;
    QPushButton *delete_book_pushButton;
    QPushButton *delete_all_books_pushButton;
    QPushButton *show_all_books_pushButton;
    QSpacerItem *verticalSpacer_4;
    QWidget *iobooksinfo_tab;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *iobooksinfo_tableWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *give_book_pushButton;
    QPushButton *take_iobooksinfo_pushButton;
    QSpacerItem *verticalSpacer_3;
    QWidget *create_reader_page;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *cr_fio_label;
    QLabel *cr_right_of_acces_label;
    QLabel *cr_year_of_birth_label;
    QLabel *cr_job_or_study_place_label;
    QLineEdit *cr_fio_lineEdit;
    QLineEdit *cr_job_or_study_place_lineEdit;
    QLabel *cr_adress_label;
    QComboBox *cr_right_of_acces_comboBox;
    QLineEdit *cr_adress_lineEdit;
    QLineEdit *cr_year_of_birth_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *cr_ok_pushButton;
    QPushButton *cr_cancel_pushButton;
    QWidget *create_book_page;
    QGridLayout *gridLayout_5;
    QLabel *cb_authors_label;
    QLineEdit *cb_authors_lineEdit;
    QLabel *cb_publisher_label;
    QLabel *cb_year_of_publishing_label;
    QLineEdit *cb_title_lineEdit;
    QLabel *cb_all_copies_label;
    QLineEdit *cb_copies_in_stock_lineEdit;
    QLabel *cb_section_count_label_2;
    QLabel *cb_section_count_label;
    QLineEdit *cb_publisher_lineEdit;
    QComboBox *cb_section_comboBox;
    QLabel *cb_title_label;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cb_ok_pushButton;
    QPushButton *cb_cancel_pushButton;
    QLineEdit *cb_all_copies_lineEdit;
    QLineEdit *cb_year_of_publication_lineEdit;
    QLabel *cb_section_label;
    QLabel *cb_copies_in_stock_label;
    QSpacerItem *verticalSpacer_5;
    QWidget *give_book_page;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_12;
    QDateEdit *gb_giving_dateEdit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_13;
    QDateEdit *gb_taking_dateEdit;
    QSpacerItem *horizontalSpacer_6;
    QLabel *gb_taking_label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *gb_give_book_pushButton;
    QPushButton *gb_cancel_pushButton;
    QLabel *gb_giving_label;
    QComboBox *gb_readers_comboBox;
    QComboBox *gb_books_comboBox;
    QMenuBar *menuBar;
    QMenu *library_menu;
    QMenu *reader_menu;
    QMenu *book_menu;
    QMenu *iobooksinfo_menu;
    QMenu *help_menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(616, 492);
        create_library_action = new QAction(MainWindow);
        create_library_action->setObjectName(QStringLiteral("create_library_action"));
        save_library_action = new QAction(MainWindow);
        save_library_action->setObjectName(QStringLiteral("save_library_action"));
        save_library_action->setEnabled(false);
        add_reader_action = new QAction(MainWindow);
        add_reader_action->setObjectName(QStringLiteral("add_reader_action"));
        add_reader_action->setCheckable(false);
        add_reader_action->setEnabled(true);
        delete_reader_action = new QAction(MainWindow);
        delete_reader_action->setObjectName(QStringLiteral("delete_reader_action"));
        delete_all_readers_action = new QAction(MainWindow);
        delete_all_readers_action->setObjectName(QStringLiteral("delete_all_readers_action"));
        show_all_readers_action = new QAction(MainWindow);
        show_all_readers_action->setObjectName(QStringLiteral("show_all_readers_action"));
        show_all_readers_action->setCheckable(false);
        add_book_action = new QAction(MainWindow);
        add_book_action->setObjectName(QStringLiteral("add_book_action"));
        delete_book_action = new QAction(MainWindow);
        delete_book_action->setObjectName(QStringLiteral("delete_book_action"));
        delete_all_books_action = new QAction(MainWindow);
        delete_all_books_action->setObjectName(QStringLiteral("delete_all_books_action"));
        show_all_books_action = new QAction(MainWindow);
        show_all_books_action->setObjectName(QStringLiteral("show_all_books_action"));
        take_iobooksinfo_action = new QAction(MainWindow);
        take_iobooksinfo_action->setObjectName(QStringLiteral("take_iobooksinfo_action"));
        give_book_action = new QAction(MainWindow);
        give_book_action->setObjectName(QStringLiteral("give_book_action"));
        save_as_library_action = new QAction(MainWindow);
        save_as_library_action->setObjectName(QStringLiteral("save_as_library_action"));
        save_as_library_action->setEnabled(false);
        open_library_action = new QAction(MainWindow);
        open_library_action->setObjectName(QStringLiteral("open_library_action"));
        quit_library_action = new QAction(MainWindow);
        quit_library_action->setObjectName(QStringLiteral("quit_library_action"));
        about_help_action = new QAction(MainWindow);
        about_help_action->setObjectName(QStringLiteral("about_help_action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setEnabled(true);
        library_page = new QWidget();
        library_page->setObjectName(QStringLiteral("library_page"));
        library_page->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(library_page);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        library_tabWidget = new QTabWidget(library_page);
        library_tabWidget->setObjectName(QStringLiteral("library_tabWidget"));
        library_tabWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(library_tabWidget->sizePolicy().hasHeightForWidth());
        library_tabWidget->setSizePolicy(sizePolicy);
        library_tabWidget->setMaximumSize(QSize(16777215, 16777215));
        reader_tab = new QWidget();
        reader_tab->setObjectName(QStringLiteral("reader_tab"));
        horizontalLayout = new QHBoxLayout(reader_tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        reader_tableWidget = new QTableWidget(reader_tab);
        reader_tableWidget->setObjectName(QStringLiteral("reader_tableWidget"));
        reader_tableWidget->setRowCount(0);
        reader_tableWidget->setColumnCount(0);
        reader_tableWidget->horizontalHeader()->setVisible(false);
        reader_tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        reader_tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        reader_tableWidget->horizontalHeader()->setHighlightSections(true);
        reader_tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        reader_tableWidget->horizontalHeader()->setStretchLastSection(true);
        reader_tableWidget->verticalHeader()->setVisible(false);
        reader_tableWidget->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_2->addWidget(reader_tableWidget);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        search_reader_label = new QLabel(reader_tab);
        search_reader_label->setObjectName(QStringLiteral("search_reader_label"));

        horizontalLayout_5->addWidget(search_reader_label);

        search_reader_lineEdit = new QLineEdit(reader_tab);
        search_reader_lineEdit->setObjectName(QStringLiteral("search_reader_lineEdit"));

        horizontalLayout_5->addWidget(search_reader_lineEdit);

        search_reader_pushButton = new QPushButton(reader_tab);
        search_reader_pushButton->setObjectName(QStringLiteral("search_reader_pushButton"));

        horizontalLayout_5->addWidget(search_reader_pushButton);


        verticalLayout_7->addLayout(horizontalLayout_5);

        search_reader_parameters_groupBox = new QGroupBox(reader_tab);
        search_reader_parameters_groupBox->setObjectName(QStringLiteral("search_reader_parameters_groupBox"));
        gridLayout = new QGridLayout(search_reader_parameters_groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        search_reader_by_FIO_radioButton = new QRadioButton(search_reader_parameters_groupBox);
        search_reader_by_FIO_radioButton->setObjectName(QStringLiteral("search_reader_by_FIO_radioButton"));

        gridLayout->addWidget(search_reader_by_FIO_radioButton, 0, 0, 1, 2);

        search_reader_by_card_number_radioButton = new QRadioButton(search_reader_parameters_groupBox);
        search_reader_by_card_number_radioButton->setObjectName(QStringLiteral("search_reader_by_card_number_radioButton"));

        gridLayout->addWidget(search_reader_by_card_number_radioButton, 1, 0, 1, 2);


        verticalLayout_7->addWidget(search_reader_parameters_groupBox);


        verticalLayout_2->addLayout(verticalLayout_7);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        add_reader_pushButton = new QPushButton(reader_tab);
        add_reader_pushButton->setObjectName(QStringLiteral("add_reader_pushButton"));

        verticalLayout->addWidget(add_reader_pushButton);

        delete_reader_pushButton = new QPushButton(reader_tab);
        delete_reader_pushButton->setObjectName(QStringLiteral("delete_reader_pushButton"));

        verticalLayout->addWidget(delete_reader_pushButton);

        delete_all_readers_pushButton = new QPushButton(reader_tab);
        delete_all_readers_pushButton->setObjectName(QStringLiteral("delete_all_readers_pushButton"));

        verticalLayout->addWidget(delete_all_readers_pushButton);

        show_all_readers_pushButton = new QPushButton(reader_tab);
        show_all_readers_pushButton->setObjectName(QStringLiteral("show_all_readers_pushButton"));

        verticalLayout->addWidget(show_all_readers_pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        library_tabWidget->addTab(reader_tab, QString());
        book_tab = new QWidget();
        book_tab->setObjectName(QStringLiteral("book_tab"));
        horizontalLayout_3 = new QHBoxLayout(book_tab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        book_tableWidget = new QTableWidget(book_tab);
        book_tableWidget->setObjectName(QStringLiteral("book_tableWidget"));
        book_tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        book_tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        book_tableWidget->horizontalHeader()->setStretchLastSection(true);
        book_tableWidget->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_5->addWidget(book_tableWidget);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        search_book_label = new QLabel(book_tab);
        search_book_label->setObjectName(QStringLiteral("search_book_label"));

        horizontalLayout_10->addWidget(search_book_label);

        search_book_lineEdit = new QLineEdit(book_tab);
        search_book_lineEdit->setObjectName(QStringLiteral("search_book_lineEdit"));

        horizontalLayout_10->addWidget(search_book_lineEdit);

        search_book_pushButton = new QPushButton(book_tab);
        search_book_pushButton->setObjectName(QStringLiteral("search_book_pushButton"));

        horizontalLayout_10->addWidget(search_book_pushButton);


        verticalLayout_8->addLayout(horizontalLayout_10);

        search_book_parameters_groupBox = new QGroupBox(book_tab);
        search_book_parameters_groupBox->setObjectName(QStringLiteral("search_book_parameters_groupBox"));
        gridLayout_2 = new QGridLayout(search_book_parameters_groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        search_book_by_Code_radioButton = new QRadioButton(search_book_parameters_groupBox);
        search_book_by_Code_radioButton->setObjectName(QStringLiteral("search_book_by_Code_radioButton"));

        gridLayout_2->addWidget(search_book_by_Code_radioButton, 0, 0, 1, 2);

        search_book_by_author_or_title_radioButton = new QRadioButton(search_book_parameters_groupBox);
        search_book_by_author_or_title_radioButton->setObjectName(QStringLiteral("search_book_by_author_or_title_radioButton"));

        gridLayout_2->addWidget(search_book_by_author_or_title_radioButton, 1, 0, 1, 2);


        verticalLayout_8->addWidget(search_book_parameters_groupBox);


        verticalLayout_5->addLayout(verticalLayout_8);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        add_book_pushButton = new QPushButton(book_tab);
        add_book_pushButton->setObjectName(QStringLiteral("add_book_pushButton"));

        verticalLayout_4->addWidget(add_book_pushButton);

        delete_book_pushButton = new QPushButton(book_tab);
        delete_book_pushButton->setObjectName(QStringLiteral("delete_book_pushButton"));

        verticalLayout_4->addWidget(delete_book_pushButton);

        delete_all_books_pushButton = new QPushButton(book_tab);
        delete_all_books_pushButton->setObjectName(QStringLiteral("delete_all_books_pushButton"));

        verticalLayout_4->addWidget(delete_all_books_pushButton);

        show_all_books_pushButton = new QPushButton(book_tab);
        show_all_books_pushButton->setObjectName(QStringLiteral("show_all_books_pushButton"));

        verticalLayout_4->addWidget(show_all_books_pushButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_4);

        library_tabWidget->addTab(book_tab, QString());
        iobooksinfo_tab = new QWidget();
        iobooksinfo_tab->setObjectName(QStringLiteral("iobooksinfo_tab"));
        horizontalLayout_4 = new QHBoxLayout(iobooksinfo_tab);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        iobooksinfo_tableWidget = new QTableWidget(iobooksinfo_tab);
        iobooksinfo_tableWidget->setObjectName(QStringLiteral("iobooksinfo_tableWidget"));
        iobooksinfo_tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        iobooksinfo_tableWidget->horizontalHeader()->setStretchLastSection(true);
        iobooksinfo_tableWidget->verticalHeader()->setDefaultSectionSize(25);

        horizontalLayout_4->addWidget(iobooksinfo_tableWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        give_book_pushButton = new QPushButton(iobooksinfo_tab);
        give_book_pushButton->setObjectName(QStringLiteral("give_book_pushButton"));

        verticalLayout_3->addWidget(give_book_pushButton);

        take_iobooksinfo_pushButton = new QPushButton(iobooksinfo_tab);
        take_iobooksinfo_pushButton->setObjectName(QStringLiteral("take_iobooksinfo_pushButton"));

        verticalLayout_3->addWidget(take_iobooksinfo_pushButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        library_tabWidget->addTab(iobooksinfo_tab, QString());

        horizontalLayout_2->addWidget(library_tabWidget);

        stackedWidget->addWidget(library_page);
        create_reader_page = new QWidget();
        create_reader_page->setObjectName(QStringLiteral("create_reader_page"));
        create_reader_page->setEnabled(true);
        gridLayout_4 = new QGridLayout(create_reader_page);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 6, 1, 1, 1);

        cr_fio_label = new QLabel(create_reader_page);
        cr_fio_label->setObjectName(QStringLiteral("cr_fio_label"));
        QFont font;
        font.setPointSize(10);
        cr_fio_label->setFont(font);

        gridLayout_4->addWidget(cr_fio_label, 1, 0, 1, 1);

        cr_right_of_acces_label = new QLabel(create_reader_page);
        cr_right_of_acces_label->setObjectName(QStringLiteral("cr_right_of_acces_label"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setKerning(true);
        cr_right_of_acces_label->setFont(font1);

        gridLayout_4->addWidget(cr_right_of_acces_label, 0, 0, 1, 1);

        cr_year_of_birth_label = new QLabel(create_reader_page);
        cr_year_of_birth_label->setObjectName(QStringLiteral("cr_year_of_birth_label"));
        cr_year_of_birth_label->setFont(font);

        gridLayout_4->addWidget(cr_year_of_birth_label, 2, 0, 1, 1);

        cr_job_or_study_place_label = new QLabel(create_reader_page);
        cr_job_or_study_place_label->setObjectName(QStringLiteral("cr_job_or_study_place_label"));
        cr_job_or_study_place_label->setFont(font);

        gridLayout_4->addWidget(cr_job_or_study_place_label, 4, 0, 1, 1);

        cr_fio_lineEdit = new QLineEdit(create_reader_page);
        cr_fio_lineEdit->setObjectName(QStringLiteral("cr_fio_lineEdit"));
        cr_fio_lineEdit->setInputMask(QStringLiteral(""));

        gridLayout_4->addWidget(cr_fio_lineEdit, 1, 1, 1, 1);

        cr_job_or_study_place_lineEdit = new QLineEdit(create_reader_page);
        cr_job_or_study_place_lineEdit->setObjectName(QStringLiteral("cr_job_or_study_place_lineEdit"));

        gridLayout_4->addWidget(cr_job_or_study_place_lineEdit, 4, 1, 1, 1);

        cr_adress_label = new QLabel(create_reader_page);
        cr_adress_label->setObjectName(QStringLiteral("cr_adress_label"));
        cr_adress_label->setFont(font);

        gridLayout_4->addWidget(cr_adress_label, 3, 0, 1, 1);

        cr_right_of_acces_comboBox = new QComboBox(create_reader_page);
        cr_right_of_acces_comboBox->setObjectName(QStringLiteral("cr_right_of_acces_comboBox"));
        cr_right_of_acces_comboBox->setMaxVisibleItems(3);

        gridLayout_4->addWidget(cr_right_of_acces_comboBox, 0, 1, 1, 1);

        cr_adress_lineEdit = new QLineEdit(create_reader_page);
        cr_adress_lineEdit->setObjectName(QStringLiteral("cr_adress_lineEdit"));

        gridLayout_4->addWidget(cr_adress_lineEdit, 3, 1, 1, 1);

        cr_year_of_birth_lineEdit = new QLineEdit(create_reader_page);
        cr_year_of_birth_lineEdit->setObjectName(QStringLiteral("cr_year_of_birth_lineEdit"));
        cr_year_of_birth_lineEdit->setMaxLength(32767);
        cr_year_of_birth_lineEdit->setCursorPosition(0);

        gridLayout_4->addWidget(cr_year_of_birth_lineEdit, 2, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        cr_ok_pushButton = new QPushButton(create_reader_page);
        cr_ok_pushButton->setObjectName(QStringLiteral("cr_ok_pushButton"));

        horizontalLayout_9->addWidget(cr_ok_pushButton);

        cr_cancel_pushButton = new QPushButton(create_reader_page);
        cr_cancel_pushButton->setObjectName(QStringLiteral("cr_cancel_pushButton"));

        horizontalLayout_9->addWidget(cr_cancel_pushButton);


        gridLayout_4->addLayout(horizontalLayout_9, 5, 1, 1, 1);

        stackedWidget->addWidget(create_reader_page);
        create_book_page = new QWidget();
        create_book_page->setObjectName(QStringLiteral("create_book_page"));
        gridLayout_5 = new QGridLayout(create_book_page);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        cb_authors_label = new QLabel(create_book_page);
        cb_authors_label->setObjectName(QStringLiteral("cb_authors_label"));

        gridLayout_5->addWidget(cb_authors_label, 2, 0, 1, 1);

        cb_authors_lineEdit = new QLineEdit(create_book_page);
        cb_authors_lineEdit->setObjectName(QStringLiteral("cb_authors_lineEdit"));

        gridLayout_5->addWidget(cb_authors_lineEdit, 2, 1, 1, 1);

        cb_publisher_label = new QLabel(create_book_page);
        cb_publisher_label->setObjectName(QStringLiteral("cb_publisher_label"));

        gridLayout_5->addWidget(cb_publisher_label, 4, 0, 1, 1);

        cb_year_of_publishing_label = new QLabel(create_book_page);
        cb_year_of_publishing_label->setObjectName(QStringLiteral("cb_year_of_publishing_label"));

        gridLayout_5->addWidget(cb_year_of_publishing_label, 5, 0, 1, 1);

        cb_title_lineEdit = new QLineEdit(create_book_page);
        cb_title_lineEdit->setObjectName(QStringLiteral("cb_title_lineEdit"));

        gridLayout_5->addWidget(cb_title_lineEdit, 3, 1, 1, 1);

        cb_all_copies_label = new QLabel(create_book_page);
        cb_all_copies_label->setObjectName(QStringLiteral("cb_all_copies_label"));

        gridLayout_5->addWidget(cb_all_copies_label, 6, 0, 1, 1);

        cb_copies_in_stock_lineEdit = new QLineEdit(create_book_page);
        cb_copies_in_stock_lineEdit->setObjectName(QStringLiteral("cb_copies_in_stock_lineEdit"));

        gridLayout_5->addWidget(cb_copies_in_stock_lineEdit, 7, 1, 1, 1);

        cb_section_count_label_2 = new QLabel(create_book_page);
        cb_section_count_label_2->setObjectName(QStringLiteral("cb_section_count_label_2"));

        gridLayout_5->addWidget(cb_section_count_label_2, 1, 0, 1, 1);

        cb_section_count_label = new QLabel(create_book_page);
        cb_section_count_label->setObjectName(QStringLiteral("cb_section_count_label"));

        gridLayout_5->addWidget(cb_section_count_label, 1, 1, 1, 1);

        cb_publisher_lineEdit = new QLineEdit(create_book_page);
        cb_publisher_lineEdit->setObjectName(QStringLiteral("cb_publisher_lineEdit"));

        gridLayout_5->addWidget(cb_publisher_lineEdit, 4, 1, 1, 1);

        cb_section_comboBox = new QComboBox(create_book_page);
        cb_section_comboBox->setObjectName(QStringLiteral("cb_section_comboBox"));

        gridLayout_5->addWidget(cb_section_comboBox, 0, 1, 1, 1);

        cb_title_label = new QLabel(create_book_page);
        cb_title_label->setObjectName(QStringLiteral("cb_title_label"));

        gridLayout_5->addWidget(cb_title_label, 3, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        cb_ok_pushButton = new QPushButton(create_book_page);
        cb_ok_pushButton->setObjectName(QStringLiteral("cb_ok_pushButton"));

        horizontalLayout_6->addWidget(cb_ok_pushButton);

        cb_cancel_pushButton = new QPushButton(create_book_page);
        cb_cancel_pushButton->setObjectName(QStringLiteral("cb_cancel_pushButton"));

        horizontalLayout_6->addWidget(cb_cancel_pushButton);


        gridLayout_5->addLayout(horizontalLayout_6, 8, 0, 1, 2);

        cb_all_copies_lineEdit = new QLineEdit(create_book_page);
        cb_all_copies_lineEdit->setObjectName(QStringLiteral("cb_all_copies_lineEdit"));

        gridLayout_5->addWidget(cb_all_copies_lineEdit, 6, 1, 1, 1);

        cb_year_of_publication_lineEdit = new QLineEdit(create_book_page);
        cb_year_of_publication_lineEdit->setObjectName(QStringLiteral("cb_year_of_publication_lineEdit"));

        gridLayout_5->addWidget(cb_year_of_publication_lineEdit, 5, 1, 1, 1);

        cb_section_label = new QLabel(create_book_page);
        cb_section_label->setObjectName(QStringLiteral("cb_section_label"));

        gridLayout_5->addWidget(cb_section_label, 0, 0, 1, 1);

        cb_copies_in_stock_label = new QLabel(create_book_page);
        cb_copies_in_stock_label->setObjectName(QStringLiteral("cb_copies_in_stock_label"));

        gridLayout_5->addWidget(cb_copies_in_stock_label, 7, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_5, 9, 0, 1, 2);

        stackedWidget->addWidget(create_book_page);
        give_book_page = new QWidget();
        give_book_page->setObjectName(QStringLiteral("give_book_page"));
        gridLayout_3 = new QGridLayout(give_book_page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(give_book_page);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 6, 0, 1, 2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        gb_giving_dateEdit = new QDateEdit(give_book_page);
        gb_giving_dateEdit->setObjectName(QStringLiteral("gb_giving_dateEdit"));
        gb_giving_dateEdit->setEnabled(true);

        horizontalLayout_12->addWidget(gb_giving_dateEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);


        gridLayout_3->addLayout(horizontalLayout_12, 4, 1, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        gb_taking_dateEdit = new QDateEdit(give_book_page);
        gb_taking_dateEdit->setObjectName(QStringLiteral("gb_taking_dateEdit"));
        gb_taking_dateEdit->setEnabled(false);

        horizontalLayout_13->addWidget(gb_taking_dateEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);


        gridLayout_3->addLayout(horizontalLayout_13, 3, 1, 1, 1);

        gb_taking_label = new QLabel(give_book_page);
        gb_taking_label->setObjectName(QStringLiteral("gb_taking_label"));

        gridLayout_3->addWidget(gb_taking_label, 4, 0, 1, 1);

        label_2 = new QLabel(give_book_page);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_7);

        gb_give_book_pushButton = new QPushButton(give_book_page);
        gb_give_book_pushButton->setObjectName(QStringLiteral("gb_give_book_pushButton"));

        horizontalLayout_15->addWidget(gb_give_book_pushButton);

        gb_cancel_pushButton = new QPushButton(give_book_page);
        gb_cancel_pushButton->setObjectName(QStringLiteral("gb_cancel_pushButton"));

        horizontalLayout_15->addWidget(gb_cancel_pushButton);


        gridLayout_3->addLayout(horizontalLayout_15, 5, 0, 1, 2);

        gb_giving_label = new QLabel(give_book_page);
        gb_giving_label->setObjectName(QStringLiteral("gb_giving_label"));

        gridLayout_3->addWidget(gb_giving_label, 3, 0, 1, 1);

        gb_readers_comboBox = new QComboBox(give_book_page);
        gb_readers_comboBox->setObjectName(QStringLiteral("gb_readers_comboBox"));

        gridLayout_3->addWidget(gb_readers_comboBox, 0, 1, 1, 1);

        gb_books_comboBox = new QComboBox(give_book_page);
        gb_books_comboBox->setObjectName(QStringLiteral("gb_books_comboBox"));

        gridLayout_3->addWidget(gb_books_comboBox, 1, 1, 1, 1);

        stackedWidget->addWidget(give_book_page);

        verticalLayout_6->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 616, 22));
        library_menu = new QMenu(menuBar);
        library_menu->setObjectName(QStringLiteral("library_menu"));
        reader_menu = new QMenu(menuBar);
        reader_menu->setObjectName(QStringLiteral("reader_menu"));
        reader_menu->setEnabled(true);
        book_menu = new QMenu(menuBar);
        book_menu->setObjectName(QStringLiteral("book_menu"));
        book_menu->setEnabled(true);
        iobooksinfo_menu = new QMenu(menuBar);
        iobooksinfo_menu->setObjectName(QStringLiteral("iobooksinfo_menu"));
        iobooksinfo_menu->setEnabled(true);
        help_menu = new QMenu(menuBar);
        help_menu->setObjectName(QStringLiteral("help_menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(reader_tableWidget, delete_reader_pushButton);
        QWidget::setTabOrder(delete_reader_pushButton, delete_all_readers_pushButton);
        QWidget::setTabOrder(delete_all_readers_pushButton, show_all_readers_pushButton);
        QWidget::setTabOrder(show_all_readers_pushButton, book_tableWidget);
        QWidget::setTabOrder(book_tableWidget, add_book_pushButton);
        QWidget::setTabOrder(add_book_pushButton, delete_book_pushButton);
        QWidget::setTabOrder(delete_book_pushButton, delete_all_books_pushButton);
        QWidget::setTabOrder(delete_all_books_pushButton, iobooksinfo_tableWidget);
        QWidget::setTabOrder(iobooksinfo_tableWidget, take_iobooksinfo_pushButton);
        QWidget::setTabOrder(take_iobooksinfo_pushButton, cr_right_of_acces_comboBox);
        QWidget::setTabOrder(cr_right_of_acces_comboBox, cr_fio_lineEdit);
        QWidget::setTabOrder(cr_fio_lineEdit, cr_year_of_birth_lineEdit);
        QWidget::setTabOrder(cr_year_of_birth_lineEdit, cr_adress_lineEdit);
        QWidget::setTabOrder(cr_adress_lineEdit, cr_job_or_study_place_lineEdit);
        QWidget::setTabOrder(cr_job_or_study_place_lineEdit, cr_ok_pushButton);
        QWidget::setTabOrder(cr_ok_pushButton, cr_cancel_pushButton);
        QWidget::setTabOrder(cr_cancel_pushButton, library_tabWidget);

        menuBar->addAction(library_menu->menuAction());
        menuBar->addAction(reader_menu->menuAction());
        menuBar->addAction(book_menu->menuAction());
        menuBar->addAction(iobooksinfo_menu->menuAction());
        menuBar->addAction(help_menu->menuAction());
        library_menu->addSeparator();
        library_menu->addAction(create_library_action);
        library_menu->addSeparator();
        library_menu->addAction(quit_library_action);
        reader_menu->addAction(add_reader_action);
        reader_menu->addAction(delete_reader_action);
        reader_menu->addSeparator();
        reader_menu->addAction(delete_all_readers_action);
        reader_menu->addSeparator();
        reader_menu->addAction(show_all_readers_action);
        book_menu->addAction(add_book_action);
        book_menu->addAction(delete_book_action);
        book_menu->addSeparator();
        book_menu->addAction(delete_all_books_action);
        book_menu->addSeparator();
        book_menu->addAction(show_all_books_action);
        iobooksinfo_menu->addAction(give_book_action);
        iobooksinfo_menu->addAction(take_iobooksinfo_action);
        iobooksinfo_menu->addSeparator();
        help_menu->addAction(about_help_action);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        library_tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260", 0));
        create_library_action->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", 0));
        save_library_action->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        add_reader_action->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214...", 0));
        delete_reader_action->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        delete_all_readers_action->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\265\321\200\320\265\321\202\321\214 \320\262\321\201\320\265\321\205", 0));
        show_all_readers_action->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265\321\205", 0));
        add_book_action->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214...", 0));
        delete_book_action->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214...", 0));
        delete_all_books_action->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\265\321\200\320\265\321\202\321\214 \320\262\321\201\320\265", 0));
        show_all_books_action->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265", 0));
        take_iobooksinfo_action->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", 0));
        give_book_action->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\264\320\260\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", 0));
        save_as_library_action->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0));
        open_library_action->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0));
        quit_library_action->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        about_help_action->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        search_reader_label->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260:", 0));
        search_reader_pushButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", 0));
        search_reader_parameters_groupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276:", 0));
        search_reader_by_FIO_radioButton->setText(QApplication::translate("MainWindow", "\320\244\320\230\320\236", 0));
        search_reader_by_card_number_radioButton->setText(QApplication::translate("MainWindow", "\342\204\226 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\276\320\263\320\276 \320\261\320\270\320\273\320\265\321\202\320\260", 0));
        add_reader_pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214...", 0));
        delete_reader_pushButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        delete_all_readers_pushButton->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\265\321\200\320\265\321\200\321\202\321\214 \320\262\321\201\320\265\321\205", 0));
        show_all_readers_pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265\321\205", 0));
        library_tabWidget->setTabText(library_tabWidget->indexOf(reader_tab), QApplication::translate("MainWindow", "\320\247\320\270\321\202\320\260\321\202\320\265\320\273\320\270", 0));
        search_book_label->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260:", 0));
        search_book_pushButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", 0));
        search_book_parameters_groupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276:", 0));
        search_book_by_Code_radioButton->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\321\203", 0));
        search_book_by_author_or_title_radioButton->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\321\203 \320\270\320\273\320\270 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", 0));
        add_book_pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214...", 0));
        delete_book_pushButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        delete_all_books_pushButton->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\265\321\200\320\265\321\200\321\202\321\214 \320\262\321\201\320\265", 0));
        show_all_books_pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265", 0));
        library_tabWidget->setTabText(library_tabWidget->indexOf(book_tab), QApplication::translate("MainWindow", "\320\232\320\275\320\270\320\263\320\270", 0));
        give_book_pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\264\320\260\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", 0));
        take_iobooksinfo_pushButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", 0));
        library_tabWidget->setTabText(library_tabWidget->indexOf(iobooksinfo_tab), QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\265\320\274/\320\222\321\213\320\264\320\260\321\207\320\260", 0));
        cr_fio_label->setText(QApplication::translate("MainWindow", "\320\244\320\230\320\236:", 0));
        cr_right_of_acces_label->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\260 \320\264\320\276\321\201\321\202\321\203\320\277\320\260:", 0));
        cr_year_of_birth_label->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", 0));
        cr_job_or_study_place_label->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \321\200\320\260\320\261\320\276\321\202\321\213 \320\270\320\273\320\270 \321\203\321\207\320\265\320\261\321\213:", 0));
        cr_adress_label->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201:", 0));
        cr_right_of_acces_comboBox->clear();
        cr_right_of_acces_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\321\202\320\276\320\273\321\214\320\272\320\276 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202 (\320\220)", 0)
         << QApplication::translate("MainWindow", "\321\202\320\276\320\273\321\214\320\272\320\276 \321\207\320\270\321\202\320\260\320\273\321\214\320\275\321\213\320\271 \320\267\320\260\320\273 (\320\247)", 0)
         << QApplication::translate("MainWindow", "\321\207\320\270\321\202\320\260\320\273\321\214\320\275\321\213\320\271 \320\267\320\260\320\273 \320\270 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202 (\320\222)", 0)
        );
        cr_year_of_birth_lineEdit->setInputMask(QString());
        cr_year_of_birth_lineEdit->setText(QString());
        cr_ok_pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        cr_cancel_pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        cb_authors_label->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200(\321\213):", 0));
        cb_publisher_label->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214:", 0));
        cb_year_of_publishing_label->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264 \320\277\321\203\320\261\320\273\320\270\320\272\320\260\321\206\320\270\320\270:", 0));
        cb_all_copies_label->setText(QApplication::translate("MainWindow", "\320\242\320\270\321\200\320\260\320\266(\321\210\321\202.):", 0));
        cb_section_count_label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\272\320\275\320\270\320\263 \320\262 \321\200\320\260\320\267\320\264\320\265\320\273\320\265:", 0));
        cb_section_count_label->setText(QString());
        cb_title_label->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", 0));
        cb_ok_pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        cb_cancel_pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        cb_section_label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\260\320\267\320\264\320\265\320\273:", 0));
        cb_copies_in_stock_label->setText(QApplication::translate("MainWindow", "\320\222 \320\275\320\260\320\273\320\270\321\207\320\270\320\270(\321\210\321\202.):", 0));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217:", 0));
        gb_taking_label->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\265\320\274\320\260:", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\275\320\270\320\263\321\203:", 0));
        gb_give_book_pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\264\320\260\321\202\321\214", 0));
        gb_cancel_pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        gb_giving_label->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\262\321\213\320\264\320\260\321\207\320\270:", 0));
        library_menu->setTitle(QApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260", 0));
        reader_menu->setTitle(QApplication::translate("MainWindow", "\320\247\320\270\321\202\320\260\321\202\320\265\320\273\321\214", 0));
        book_menu->setTitle(QApplication::translate("MainWindow", "\320\232\320\275\320\270\320\263\320\260", 0));
        iobooksinfo_menu->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\265\320\274\\\320\222\321\213\320\264\320\260\321\207\320\260", 0));
        help_menu->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
