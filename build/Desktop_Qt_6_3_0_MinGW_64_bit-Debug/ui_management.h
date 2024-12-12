/********************************************************************************
** Form generated from reading UI file 'management.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENT_H
#define UI_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_management
{
public:
    QStackedWidget *main;
    QWidget *Employe;
    QStackedWidget *employee;
    QWidget *default_employee;
    QGroupBox *search_2;
    QLabel *search_icon;
    QPushButton *add_employee_btn;
    QTableWidget *table;
    QPushButton *update_employee_btn;
    QPushButton *delete_employee_btn;
    QPushButton *searchReset;
    QComboBox *search;
    QLineEdit *search_field;
    QWidget *Add_employee;
    QGroupBox *email;
    QLineEdit *email_field;
    QLabel *Sub_title;
    QGroupBox *name;
    QLineEdit *name_field;
    QLabel *Title;
    QGroupBox *phone_number;
    QLineEdit *phone_field;
    QGroupBox *position;
    QComboBox *position_field;
    QPushButton *confirm_employee_btn;
    QPushButton *add_back;
    QWidget *update_employee;
    QLabel *Sub_title_6;
    QGroupBox *position_3;
    QComboBox *position_update;
    QGroupBox *name_3;
    QLineEdit *name_update;
    QGroupBox *email_6;
    QLineEdit *email_update;
    QGroupBox *phone_number_6;
    QLineEdit *phone_update;
    QPushButton *confirm_update_btn;
    QLabel *Title_6;
    QPushButton *update_back;
    QWidget *history;
    QLabel *txt_2;
    QPushButton *employee_export;
    QPushButton *history_back;
    QTableWidget *tableH;
    QFrame *stat1;
    QProgressBar *progressBar4;
    QLabel *label;
    QFrame *frame;
    QProgressBar *progressBar2;
    QProgressBar *progressBar3;
    QProgressBar *progressBar1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *Deliverie;
    QStackedWidget *Deliver;
    QWidget *maindelivery;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QPushButton *edit_table_button;
    QPushButton *button_delete;
    QPushButton *export_table;
    QPushButton *statsbutton;
    QGroupBox *search_3;
    QLabel *search_icon_3;
    QLineEdit *lineEdit_4;
    QWidget *add_delivery;
    QLabel *label_5;
    QFrame *frame_5;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_clientID;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_employeeID;
    QGroupBox *groupBox_4;
    QLineEdit *lineEdit_deliveryAddress;
    QPushButton *pushButton_10;
    QGroupBox *groupBox_6;
    QLineEdit *lineEdit_DeliveryID;
    QComboBox *comboBox_Status;
    QPushButton *return_main;
    QWidget *timeline;
    QPushButton *TL_ORDERED;
    QPushButton *TL_IN_PROGRESS;
    QPushButton *TL_DELIVERED;
    QProgressBar *progressBar_1;
    QProgressBar *progressBar_2;
    QLabel *Label_ordered;
    QLabel *Label_in_progress;
    QLabel *Label_delivered;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QLabel *label_delivered;
    QLabel *label_in_progress;
    QLabel *label_ordered;
    QWidget *page_6;
    QLabel *label_qrcode_ordered;
    QPushButton *back_qrcode_ordered;
    QWidget *page;
    QLabel *label_qrcode_in_progress;
    QPushButton *back_qrcode_in_progress;
    QWidget *page_2;
    QLabel *label_qrcode_delivered;
    QPushButton *back_qrcode_delivered;
    QWidget *stats;
    QFrame *Cannitech;
    QPushButton *dahsboard;
    QPushButton *employees;
    QPushButton *factories;
    QPushButton *deliveries;
    QPushButton *clients;
    QLabel *dash_icon;
    QLabel *emp_icon;
    QLabel *fac_icon;
    QLabel *del_icon;
    QLabel *cli_icon;
    QPushButton *machines;
    QLabel *del_icon_2;
    QLabel *label_21;
    QPushButton *logout;
    QLabel *bg;

    void setupUi(QWidget *management)
    {
        if (management->objectName().isEmpty())
            management->setObjectName(QString::fromUtf8("management"));
        management->resize(1543, 680);
        main = new QStackedWidget(management);
        main->setObjectName(QString::fromUtf8("main"));
        main->setGeometry(QRect(320, 0, 1011, 681));
        main->setStyleSheet(QString::fromUtf8("\n"
"QStackedWidget {\n"
"border-radius:10px;\n"
"background:transparent;\n"
"}\n"
""));
        main->setLineWidth(0);
        Employe = new QWidget();
        Employe->setObjectName(QString::fromUtf8("Employe"));
        employee = new QStackedWidget(Employe);
        employee->setObjectName(QString::fromUtf8("employee"));
        employee->setGeometry(QRect(10, 190, 1001, 491));
        employee->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white; /* Background color for the frame */\n"
"    border: none;            /* No border for the frame */\n"
"    border-bottom: 2px solid #d0d0d0; /* Bottom border */\n"
"    border-right: 2px solid #d0d0d0;  /* Right border */\n"
"    border-radius: 8px;     /* Rounded corners */\n"
"}\n"
""));
        employee->setFrameShape(QFrame::Shape::StyledPanel);
        employee->setFrameShadow(QFrame::Shadow::Raised);
        default_employee = new QWidget();
        default_employee->setObjectName(QString::fromUtf8("default_employee"));
        search_2 = new QGroupBox(default_employee);
        search_2->setObjectName(QString::fromUtf8("search_2"));
        search_2->setGeometry(QRect(40, 40, 341, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lexend Light")});
        search_2->setFont(font);
        search_2->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#white;"));
        search_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        search_2->setFlat(false);
        search_2->setCheckable(false);
        search_icon = new QLabel(search_2);
        search_icon->setObjectName(QString::fromUtf8("search_icon"));
        search_icon->setGeometry(QRect(10, 15, 21, 21));
        search_icon->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:none;\n"
""));
        search_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/Icon.png")));
        search_icon->setScaledContents(true);
        add_employee_btn = new QPushButton(default_employee);
        add_employee_btn->setObjectName(QString::fromUtf8("add_employee_btn"));
        add_employee_btn->setGeometry(QRect(460, 40, 211, 51));
        add_employee_btn->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:white;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#1ba019;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-left:3px solid white ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid white ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add-circle.png"), QSize(), QIcon::Normal, QIcon::On);
        add_employee_btn->setIcon(icon);
        add_employee_btn->setIconSize(QSize(200, 200));
        add_employee_btn->setAutoRepeatInterval(100);
        table = new QTableWidget(default_employee);
        if (table->columnCount() < 5)
            table->setColumnCount(5);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lexend")});
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font1);
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem1->setFont(font1);
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem2->setFont(font1);
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem3->setFont(font1);
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem4->setFont(font1);
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(40, 140, 911, 331));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Lexend")});
        font2.setPointSize(10);
        table->setFont(font2);
        table->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        table->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    border: none;\n"
"	background-color: #F5F7FA; /* Light gray */\n"
"border-radius:10px;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #1ba019; \n"
"    color: white;\n"
"    font: 500 12pt \"Lexend Medium\";\n"
"    padding: 6px;\n"
"	border-radius:2px;\n"
"    padding-left: 10px; \n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background:  #1ba019;;\n"
"    width: 12px;\n"
"}\n"
"QScrollBar::add-page:vertical {\n"
"    background:  #F5F7FA;}\n"
"QScrollBar::sub-page:vertical {\n"
"    background: #F5F7FA;}"));
        table->setFrameShape(QFrame::Shape::NoFrame);
        table->setFrameShadow(QFrame::Shadow::Plain);
        table->setLineWidth(0);
        table->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        table->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        table->setAutoScroll(true);
        table->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        table->setProperty("showDropIndicator", QVariant(false));
        table->setDragEnabled(false);
        table->setDragDropOverwriteMode(false);
        table->setDragDropMode(QAbstractItemView::DragDropMode::NoDragDrop);
        table->setAlternatingRowColors(false);
        table->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        table->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        table->setShowGrid(false);
        table->setGridStyle(Qt::PenStyle::NoPen);
        table->setSortingEnabled(false);
        table->setWordWrap(false);
        table->setCornerButtonEnabled(false);
        table->horizontalHeader()->setVisible(true);
        table->horizontalHeader()->setCascadingSectionResizes(false);
        table->horizontalHeader()->setMinimumSectionSize(35);
        table->horizontalHeader()->setDefaultSectionSize(178);
        table->horizontalHeader()->setHighlightSections(false);
        table->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table->horizontalHeader()->setStretchLastSection(true);
        table->verticalHeader()->setVisible(false);
        table->verticalHeader()->setCascadingSectionResizes(false);
        table->verticalHeader()->setMinimumSectionSize(24);
        table->verticalHeader()->setDefaultSectionSize(40);
        table->verticalHeader()->setHighlightSections(false);
        table->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        table->verticalHeader()->setStretchLastSection(false);
        update_employee_btn = new QPushButton(default_employee);
        update_employee_btn->setObjectName(QString::fromUtf8("update_employee_btn"));
        update_employee_btn->setGeometry(QRect(690, 40, 121, 51));
        update_employee_btn->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:#1ba019;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:white;\n"
"color:#00b521;\n"
"border-left:3px solid #00b521 ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:#1ba019;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid #1BA019 ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        update_employee_btn->setIconSize(QSize(200, 200));
        update_employee_btn->setAutoRepeatInterval(100);
        delete_employee_btn = new QPushButton(default_employee);
        delete_employee_btn->setObjectName(QString::fromUtf8("delete_employee_btn"));
        delete_employee_btn->setGeometry(QRect(830, 40, 121, 51));
        delete_employee_btn->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:#1ba019;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:white;\n"
"color:#00b521;\n"
"border-left:3px solid #00b521 ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:#1ba019;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid #1BA019 ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        delete_employee_btn->setIconSize(QSize(200, 200));
        delete_employee_btn->setAutoRepeatInterval(100);
        searchReset = new QPushButton(default_employee);
        searchReset->setObjectName(QString::fromUtf8("searchReset"));
        searchReset->setGeometry(QRect(340, 50, 31, 31));
        searchReset->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:12px;\n"
"color:#1ba019;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:white;\n"
"color:#00b521;\n"
"border-color:none;\n"
"border-radius:12px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:#1ba019;\n"
"border-radius:12px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        search = new QComboBox(default_employee);
        search->addItem(QString());
        search->addItem(QString());
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(74, 45, 81, 41));
        QFont font3;
        font3.setPointSize(10);
        search->setFont(font3);
        search->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"color:#1ba019;\n"
"background-color:transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"       border: none;\n"
"       background: transparent;\n"
"       width: 0px;\n"
"    }\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
""));
        search->setInsertPolicy(QComboBox::InsertPolicy::NoInsert);
        search->setDuplicatesEnabled(false);
        search_field = new QLineEdit(default_employee);
        search_field->setObjectName(QString::fromUtf8("search_field"));
        search_field->setGeometry(QRect(149, 45, 191, 41));
        search_field->setFont(font1);
        search_field->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;\n"
"font-family: Lexend;\n"
"font-size:16px;"));
        search_field->setEchoMode(QLineEdit::EchoMode::Normal);
        employee->addWidget(default_employee);
        search_2->raise();
        add_employee_btn->raise();
        table->raise();
        update_employee_btn->raise();
        delete_employee_btn->raise();
        search->raise();
        searchReset->raise();
        search_field->raise();
        Add_employee = new QWidget();
        Add_employee->setObjectName(QString::fromUtf8("Add_employee"));
        email = new QGroupBox(Add_employee);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(380, 160, 309, 44));
        email->setFont(font);
        email->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        email->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        email->setFlat(false);
        email->setCheckable(false);
        email_field = new QLineEdit(email);
        email_field->setObjectName(QString::fromUtf8("email_field"));
        email_field->setGeometry(QRect(10, 16, 265, 22));
        email_field->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        email_field->setEchoMode(QLineEdit::EchoMode::Normal);
        Sub_title = new QLabel(Add_employee);
        Sub_title->setObjectName(QString::fromUtf8("Sub_title"));
        Sub_title->setGeometry(QRect(40, 80, 291, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Lexend Light")});
        font4.setPointSize(10);
        Sub_title->setFont(font4);
        Sub_title->setCursor(QCursor(Qt::PointingHandCursor));
        Sub_title->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Sub_title->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: #A2A1A8;\n"
"border:none;"));
        Sub_title->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        name = new QGroupBox(Add_employee);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(40, 160, 309, 45));
        name->setFont(font);
        name->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        name->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        name->setFlat(false);
        name->setCheckable(false);
        name_field = new QLineEdit(name);
        name_field->setObjectName(QString::fromUtf8("name_field"));
        name_field->setEnabled(true);
        name_field->setGeometry(QRect(10, 16, 261, 22));
        name_field->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        Title = new QLabel(Add_employee);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(40, 50, 381, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Lexend")});
        font5.setPointSize(18);
        font5.setBold(true);
        Title->setFont(font5);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(104, 104, 104);\n"
"border:none;"));
        phone_number = new QGroupBox(Add_employee);
        phone_number->setObjectName(QString::fromUtf8("phone_number"));
        phone_number->setGeometry(QRect(40, 240, 309, 44));
        phone_number->setFont(font);
        phone_number->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        phone_number->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        phone_number->setFlat(false);
        phone_number->setCheckable(false);
        phone_field = new QLineEdit(phone_number);
        phone_field->setObjectName(QString::fromUtf8("phone_field"));
        phone_field->setGeometry(QRect(10, 16, 265, 22));
        phone_field->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        phone_field->setEchoMode(QLineEdit::EchoMode::Normal);
        position = new QGroupBox(Add_employee);
        position->setObjectName(QString::fromUtf8("position"));
        position->setGeometry(QRect(380, 240, 309, 44));
        position->setFont(font);
        position->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        position->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        position->setFlat(false);
        position->setCheckable(false);
        position_field = new QComboBox(position);
        position_field->addItem(QString());
        position_field->addItem(QString());
        position_field->addItem(QString());
        position_field->setObjectName(QString::fromUtf8("position_field"));
        position_field->setGeometry(QRect(10, 16, 291, 22));
        position_field->setStyleSheet(QString::fromUtf8("border:none;"));
        confirm_employee_btn = new QPushButton(Add_employee);
        confirm_employee_btn->setObjectName(QString::fromUtf8("confirm_employee_btn"));
        confirm_employee_btn->setGeometry(QRect(770, 40, 181, 51));
        confirm_employee_btn->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:white;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#1ba019;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-left:3px solid white ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid white ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        confirm_employee_btn->setIconSize(QSize(200, 200));
        add_back = new QPushButton(Add_employee);
        add_back->setObjectName(QString::fromUtf8("add_back"));
        add_back->setGeometry(QRect(640, 40, 121, 51));
        add_back->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:#1ba019;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:white;\n"
"color:#00b521;\n"
"border-left:3px solid #00b521 ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:#1ba019;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid #1BA019 ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_back->setIcon(icon1);
        add_back->setIconSize(QSize(200, 200));
        add_back->setAutoRepeatInterval(100);
        employee->addWidget(Add_employee);
        update_employee = new QWidget();
        update_employee->setObjectName(QString::fromUtf8("update_employee"));
        Sub_title_6 = new QLabel(update_employee);
        Sub_title_6->setObjectName(QString::fromUtf8("Sub_title_6"));
        Sub_title_6->setGeometry(QRect(40, 80, 291, 31));
        Sub_title_6->setFont(font4);
        Sub_title_6->setCursor(QCursor(Qt::PointingHandCursor));
        Sub_title_6->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Sub_title_6->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: #A2A1A8;\n"
"border:none;"));
        Sub_title_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        position_3 = new QGroupBox(update_employee);
        position_3->setObjectName(QString::fromUtf8("position_3"));
        position_3->setGeometry(QRect(380, 240, 309, 44));
        position_3->setFont(font);
        position_3->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        position_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        position_3->setFlat(false);
        position_3->setCheckable(false);
        position_update = new QComboBox(position_3);
        position_update->addItem(QString());
        position_update->addItem(QString());
        position_update->addItem(QString());
        position_update->setObjectName(QString::fromUtf8("position_update"));
        position_update->setGeometry(QRect(10, 16, 291, 22));
        position_update->setStyleSheet(QString::fromUtf8("border:none;"));
        name_3 = new QGroupBox(update_employee);
        name_3->setObjectName(QString::fromUtf8("name_3"));
        name_3->setGeometry(QRect(40, 160, 309, 45));
        name_3->setFont(font);
        name_3->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        name_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        name_3->setFlat(false);
        name_3->setCheckable(false);
        name_update = new QLineEdit(name_3);
        name_update->setObjectName(QString::fromUtf8("name_update"));
        name_update->setEnabled(true);
        name_update->setGeometry(QRect(10, 16, 261, 22));
        name_update->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        email_6 = new QGroupBox(update_employee);
        email_6->setObjectName(QString::fromUtf8("email_6"));
        email_6->setGeometry(QRect(380, 160, 309, 44));
        email_6->setFont(font);
        email_6->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        email_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        email_6->setFlat(false);
        email_6->setCheckable(false);
        email_update = new QLineEdit(email_6);
        email_update->setObjectName(QString::fromUtf8("email_update"));
        email_update->setGeometry(QRect(10, 16, 265, 22));
        email_update->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        email_update->setEchoMode(QLineEdit::EchoMode::Normal);
        phone_number_6 = new QGroupBox(update_employee);
        phone_number_6->setObjectName(QString::fromUtf8("phone_number_6"));
        phone_number_6->setGeometry(QRect(40, 240, 309, 44));
        phone_number_6->setFont(font);
        phone_number_6->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        phone_number_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        phone_number_6->setFlat(false);
        phone_number_6->setCheckable(false);
        phone_update = new QLineEdit(phone_number_6);
        phone_update->setObjectName(QString::fromUtf8("phone_update"));
        phone_update->setGeometry(QRect(10, 16, 265, 22));
        phone_update->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        phone_update->setEchoMode(QLineEdit::EchoMode::Normal);
        confirm_update_btn = new QPushButton(update_employee);
        confirm_update_btn->setObjectName(QString::fromUtf8("confirm_update_btn"));
        confirm_update_btn->setGeometry(QRect(770, 40, 181, 51));
        confirm_update_btn->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:white;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#1ba019;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-left:3px solid white ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid white ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        confirm_update_btn->setIconSize(QSize(200, 200));
        Title_6 = new QLabel(update_employee);
        Title_6->setObjectName(QString::fromUtf8("Title_6"));
        Title_6->setGeometry(QRect(40, 50, 381, 31));
        Title_6->setFont(font5);
        Title_6->setStyleSheet(QString::fromUtf8("color: rgb(104, 104, 104);\n"
"border:none;"));
        update_back = new QPushButton(update_employee);
        update_back->setObjectName(QString::fromUtf8("update_back"));
        update_back->setGeometry(QRect(640, 40, 121, 51));
        update_back->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:#1ba019;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:white;\n"
"color:#00b521;\n"
"border-left:3px solid #00b521 ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:#1ba019;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid #1BA019 ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        update_back->setIcon(icon1);
        update_back->setIconSize(QSize(200, 200));
        update_back->setAutoRepeatInterval(100);
        employee->addWidget(update_employee);
        history = new QWidget();
        history->setObjectName(QString::fromUtf8("history"));
        txt_2 = new QLabel(history);
        txt_2->setObjectName(QString::fromUtf8("txt_2"));
        txt_2->setGeometry(QRect(40, 50, 361, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Lexend Medium")});
        font6.setPointSize(12);
        font6.setBold(false);
        txt_2->setFont(font6);
        txt_2->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:grey;\n"
"border:none;"));
        employee_export = new QPushButton(history);
        employee_export->setObjectName(QString::fromUtf8("employee_export"));
        employee_export->setGeometry(QRect(770, 40, 181, 51));
        employee_export->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:white;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#1ba019;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-left:3px solid white ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid white ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        employee_export->setIconSize(QSize(200, 200));
        history_back = new QPushButton(history);
        history_back->setObjectName(QString::fromUtf8("history_back"));
        history_back->setGeometry(QRect(640, 40, 121, 51));
        history_back->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:#1ba019;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:white;\n"
"color:#00b521;\n"
"border-left:3px solid #00b521 ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:#1ba019;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid #1BA019 ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        history_back->setIcon(icon1);
        history_back->setIconSize(QSize(200, 200));
        history_back->setAutoRepeatInterval(100);
        tableH = new QTableWidget(history);
        if (tableH->columnCount() < 6)
            tableH->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem5->setFont(font1);
        tableH->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem6->setFont(font1);
        tableH->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem7->setFont(font1);
        tableH->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem8->setFont(font1);
        tableH->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem9->setFont(font1);
        tableH->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem10->setFont(font1);
        tableH->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        tableH->setObjectName(QString::fromUtf8("tableH"));
        tableH->setGeometry(QRect(40, 140, 911, 331));
        tableH->setFont(font2);
        tableH->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tableH->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    border: none;\n"
"	background-color: #F5F7FA; /* Light gray */\n"
"border-radius:10px;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #1ba019; \n"
"    color: white;\n"
"    font: 500 12pt \"Lexend Medium\";\n"
"    padding: 6px;\n"
"	border-radius:2px;\n"
"    padding-left: 10px; \n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background:  #1ba019;;\n"
"    width: 12px;\n"
"}\n"
"QScrollBar::add-page:vertical {\n"
"    background:  #1ba019;;}\n"
"QScrollBar::sub-page:vertical {\n"
"    background:  #1ba019;;}"));
        tableH->setFrameShape(QFrame::Shape::NoFrame);
        tableH->setFrameShadow(QFrame::Shadow::Plain);
        tableH->setLineWidth(0);
        tableH->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        tableH->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        tableH->setAutoScroll(true);
        tableH->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableH->setProperty("showDropIndicator", QVariant(false));
        tableH->setDragEnabled(false);
        tableH->setDragDropOverwriteMode(false);
        tableH->setDragDropMode(QAbstractItemView::DragDropMode::NoDragDrop);
        tableH->setAlternatingRowColors(false);
        tableH->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableH->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableH->setShowGrid(false);
        tableH->setGridStyle(Qt::PenStyle::NoPen);
        tableH->setSortingEnabled(false);
        tableH->setWordWrap(false);
        tableH->setCornerButtonEnabled(false);
        tableH->horizontalHeader()->setVisible(true);
        tableH->horizontalHeader()->setCascadingSectionResizes(false);
        tableH->horizontalHeader()->setMinimumSectionSize(37);
        tableH->horizontalHeader()->setDefaultSectionSize(163);
        tableH->horizontalHeader()->setHighlightSections(false);
        tableH->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableH->horizontalHeader()->setStretchLastSection(true);
        tableH->verticalHeader()->setVisible(false);
        tableH->verticalHeader()->setCascadingSectionResizes(false);
        tableH->verticalHeader()->setMinimumSectionSize(24);
        tableH->verticalHeader()->setDefaultSectionSize(40);
        tableH->verticalHeader()->setHighlightSections(false);
        tableH->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableH->verticalHeader()->setStretchLastSection(false);
        employee->addWidget(history);
        stat1 = new QFrame(Employe);
        stat1->setObjectName(QString::fromUtf8("stat1"));
        stat1->setGeometry(QRect(10, 20, 371, 151));
        stat1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white; /* Background color for the frame */\n"
"    border: none;            /* No border for the frame */\n"
"    border-bottom: 2px solid #d0d0d0; /* Bottom border */\n"
"    border-right: 2px solid #d0d0d0;  /* Right border */\n"
"    border-radius: 8px;     /* Rounded corners */\n"
"}\n"
""));
        stat1->setFrameShape(QFrame::Shape::StyledPanel);
        stat1->setFrameShadow(QFrame::Shadow::Raised);
        progressBar4 = new QProgressBar(stat1);
        progressBar4->setObjectName(QString::fromUtf8("progressBar4"));
        progressBar4->setGeometry(QRect(30, 40, 311, 91));
        progressBar4->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 1px solid #8f8f91;\n"
"    border-radius: 10px;          /* Outer border radius */\n"
"    background-color: #F5F7FA;    /* Background color */\n"
"    text-align: center;           /* Centered text */\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #1ba019;    /* Fill color */\n"
"    border-radius: 8px;           /* Inner fill border radius */\n"
"    margin: 1px;                  /* Adds space for rounded edges */\n"
"}\n"
""));
        progressBar4->setMinimum(-1);
        progressBar4->setMaximum(100);
        progressBar4->setValue(80);
        progressBar4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progressBar4->setTextVisible(true);
        progressBar4->setOrientation(Qt::Orientation::Horizontal);
        progressBar4->setInvertedAppearance(false);
        progressBar4->setTextDirection(QProgressBar::Direction::BottomToTop);
        label = new QLabel(stat1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 9, 171, 31));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("border:none;\n"
""));
        frame = new QFrame(Employe);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(400, 20, 611, 151));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white; /* Background color for the frame */\n"
"    border: none;            /* No border for the frame */\n"
"    border-bottom: 2px solid #d0d0d0; /* Bottom border */\n"
"    border-right: 2px solid #d0d0d0;  /* Right border */\n"
"    border-radius: 8px;     /* Rounded corners */\n"
"}\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        progressBar2 = new QProgressBar(frame);
        progressBar2->setObjectName(QString::fromUtf8("progressBar2"));
        progressBar2->setGeometry(QRect(240, 40, 111, 91));
        progressBar2->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 1px solid #8f8f91;\n"
"    border-radius: 10px;          /* Outer border radius */\n"
"    background-color:#F5F7FA;    /* Background color */\n"
"    text-align: center;           /* Centered text */\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #1ba019;    /* Fill color */\n"
"    border-radius: 8px;           /* Inner fill border radius */\n"
"    margin: 1px;                  /* Adds space for rounded edges */\n"
"}\n"
""));
        progressBar2->setValue(60);
        progressBar2->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        progressBar2->setTextVisible(true);
        progressBar2->setOrientation(Qt::Orientation::Vertical);
        progressBar2->setInvertedAppearance(false);
        progressBar2->setTextDirection(QProgressBar::Direction::BottomToTop);
        progressBar3 = new QProgressBar(frame);
        progressBar3->setObjectName(QString::fromUtf8("progressBar3"));
        progressBar3->setGeometry(QRect(440, 40, 111, 91));
        progressBar3->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 1px solid #8f8f91;\n"
"    border-radius: 10px;          /* Outer border radius */\n"
"    background-color: #F5F7FA;    /* Background color */\n"
"    text-align: center;           /* Centered text */\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #1ba019;    /* Fill color */\n"
"    border-radius: 8px;           /* Inner fill border radius */\n"
"    margin: 1px;                  /* Adds space for rounded edges */\n"
"}\n"
""));
        progressBar3->setValue(60);
        progressBar3->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        progressBar3->setTextVisible(true);
        progressBar3->setOrientation(Qt::Orientation::Vertical);
        progressBar3->setInvertedAppearance(false);
        progressBar3->setTextDirection(QProgressBar::Direction::BottomToTop);
        progressBar1 = new QProgressBar(frame);
        progressBar1->setObjectName(QString::fromUtf8("progressBar1"));
        progressBar1->setGeometry(QRect(50, 40, 111, 91));
        progressBar1->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 1px solid #8f8f91;\n"
"    border-radius: 10px;          /* Outer border radius */\n"
"    background-color: #F5F7FA;    /* Background color */\n"
"    text-align: center;           /* Centered text */\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #1ba019;    /* Fill color */\n"
"    border-radius: 8px;           /* Inner fill border radius */\n"
"    margin: 1px;                  /* Adds space for rounded edges */\n"
"}\n"
""));
        progressBar1->setValue(60);
        progressBar1->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        progressBar1->setTextVisible(true);
        progressBar1->setOrientation(Qt::Orientation::Vertical);
        progressBar1->setInvertedAppearance(false);
        progressBar1->setTextDirection(QProgressBar::Direction::BottomToTop);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 10, 111, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
""));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 10, 111, 31));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
""));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 10, 111, 31));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
""));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        main->addWidget(Employe);
        Deliverie = new QWidget();
        Deliverie->setObjectName(QString::fromUtf8("Deliverie"));
        Deliver = new QStackedWidget(Deliverie);
        Deliver->setObjectName(QString::fromUtf8("Deliver"));
        Deliver->setGeometry(QRect(10, 20, 1001, 761));
        Deliver->setCursor(QCursor(Qt::CrossCursor));
        Deliver->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white; /* Background color for the frame */\n"
"    border: none;            /* No border for the frame */\n"
"    border-bottom: 2px solid #d0d0d0; /* Bottom border */\n"
"    border-right: 2px solid #d0d0d0;  /* Right border */\n"
"    border-radius: 8px;     /* Rounded corners */\n"
"}\n"
""));
        maindelivery = new QWidget();
        maindelivery->setObjectName(QString::fromUtf8("maindelivery"));
        pushButton_3 = new QPushButton(maindelivery);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(570, 50, 211, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("*{\n"
"border-radius:25px;\n"
"color:white;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#1ba019;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-left:3px solid white ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:white;\n"
"border-radius:25px;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-left:3.2px solid white ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(20, 20));
        tableWidget = new QTableWidget(maindelivery);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(true);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font7);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font7);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font7);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font7);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font7);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font7);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font7);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem17);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 150, 941, 491));
        QFont font8;
        font8.setPointSize(12);
        font8.setKerning(false);
        tableWidget->setFont(font8);
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        tableWidget->setMouseTracking(true);
#if QT_CONFIG(statustip)
        tableWidget->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        tableWidget->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        tableWidget->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        tableWidget->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        tableWidget->setAutoFillBackground(false);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    border: none;\n"
"	background-color: #F5F7FA; /* Light gray */\n"
"border-radius:10px;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #1ba019; \n"
"    color: white;\n"
"    font: 500 12pt \"Lexend Medium\";\n"
"    padding: 6px;\n"
"	border-radius:2px;\n"
"    padding-left: 10px; \n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background:  #1ba019;;\n"
"    width: 12px;\n"
"}\n"
"QScrollBar::add-page:vertical {\n"
"    background:  #F5F7FA;}\n"
"QScrollBar::sub-page:vertical {\n"
"    background: #F5F7FA;}"));
        tableWidget->setFrameShape(QFrame::Shape::NoFrame);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragEnabled(false);
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setDefaultDropAction(Qt::DropAction::IgnoreAction);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        tableWidget->setIconSize(QSize(100, 100));
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(true);
        tableWidget->setWordWrap(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(135);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(40);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(false);
        edit_table_button = new QPushButton(maindelivery);
        edit_table_button->setObjectName(QString::fromUtf8("edit_table_button"));
        edit_table_button->setGeometry(QRect(860, 50, 51, 51));
        edit_table_button->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"border-color: white;\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background:#f8981d;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/figma/pnghut_user-profile-editing-logo-symbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        edit_table_button->setIcon(icon2);
        edit_table_button->setIconSize(QSize(40, 40));
        button_delete = new QPushButton(maindelivery);
        button_delete->setObjectName(QString::fromUtf8("button_delete"));
        button_delete->setGeometry(QRect(920, 50, 51, 51));
        button_delete->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"border-color: white;\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background:#F04438;\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/figma/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_delete->setIcon(icon3);
        button_delete->setIconSize(QSize(30, 30));
        export_table = new QPushButton(maindelivery);
        export_table->setObjectName(QString::fromUtf8("export_table"));
        export_table->setGeometry(QRect(800, 50, 50, 51));
        export_table->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"border-color: white;\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#478ECC;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        export_table->setIcon(icon4);
        export_table->setIconSize(QSize(30, 30));
        statsbutton = new QPushButton(maindelivery);
        statsbutton->setObjectName(QString::fromUtf8("statsbutton"));
        statsbutton->setGeometry(QRect(390, 50, 51, 51));
        statsbutton->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#white;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/stats.png"), QSize(), QIcon::Normal, QIcon::Off);
        statsbutton->setIcon(icon5);
        statsbutton->setIconSize(QSize(30, 30));
        search_3 = new QGroupBox(maindelivery);
        search_3->setObjectName(QString::fromUtf8("search_3"));
        search_3->setGeometry(QRect(30, 50, 341, 51));
        search_3->setFont(font);
        search_3->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:#white;"));
        search_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        search_3->setFlat(false);
        search_3->setCheckable(false);
        search_icon_3 = new QLabel(search_3);
        search_icon_3->setObjectName(QString::fromUtf8("search_icon_3"));
        search_icon_3->setGeometry(QRect(10, 15, 21, 21));
        search_icon_3->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:none;\n"
""));
        search_icon_3->setPixmap(QPixmap(QString::fromUtf8(":/images/Icon.png")));
        search_icon_3->setScaledContents(true);
        lineEdit_4 = new QLineEdit(search_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(40, 10, 221, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;\n"
"font-family: Lexend;\n"
"font-size:16px;"));
        Deliver->addWidget(maindelivery);
        add_delivery = new QWidget();
        add_delivery->setObjectName(QString::fromUtf8("add_delivery"));
        label_5 = new QLabel(add_delivery);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(64, 110, 561, 491));
        label_5->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border-color: none;\n"
"border-width : 1px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/final2.jpg")));
        label_5->setWordWrap(false);
        frame_5 = new QFrame(add_delivery);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(640, 110, 351, 491));
        frame_5->setStyleSheet(QString::fromUtf8("background:white;"));
        frame_5->setFrameShape(QFrame::Shape::NoFrame);
        label_6 = new QLabel(frame_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 20, 261, 41));
        label_6->setStyleSheet(QString::fromUtf8("*{\n"
"color: var(--Dark-500, #16151C);\n"
"\n"
"font-family: Lexend;\n"
"font-size: 25px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: 30px; \n"
"background:none;\n"
"}"));
        groupBox_2 = new QGroupBox(frame_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 170, 281, 51));
        groupBox_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        lineEdit_clientID = new QLineEdit(groupBox_2);
        lineEdit_clientID->setObjectName(QString::fromUtf8("lineEdit_clientID"));
        lineEdit_clientID->setGeometry(QRect(12, 20, 261, 21));
        lineEdit_clientID->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        groupBox_3 = new QGroupBox(frame_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 260, 281, 51));
        groupBox_3->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        lineEdit_employeeID = new QLineEdit(groupBox_3);
        lineEdit_employeeID->setObjectName(QString::fromUtf8("lineEdit_employeeID"));
        lineEdit_employeeID->setGeometry(QRect(12, 20, 261, 21));
        lineEdit_employeeID->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        groupBox_4 = new QGroupBox(frame_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(40, 80, 281, 51));
        groupBox_4->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        lineEdit_deliveryAddress = new QLineEdit(groupBox_4);
        lineEdit_deliveryAddress->setObjectName(QString::fromUtf8("lineEdit_deliveryAddress"));
        lineEdit_deliveryAddress->setGeometry(QRect(12, 20, 261, 21));
        lineEdit_deliveryAddress->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        pushButton_10 = new QPushButton(frame_5);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(40, 440, 281, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("*{\n"
"background:#1ba019;\n"
"border-radius:10px;\n"
"color:white;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#00b521;\n"
"color:white;\n"
"border-left:3.5px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"\n"
"\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:black;\n"
"border-radius:10px;\n"
"color:white;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-radius:10px;\n"
"border-left:3.5px solid #1BA019 ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        pushButton_10->setIconSize(QSize(20, 20));
        groupBox_6 = new QGroupBox(frame_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(40, 350, 101, 51));
        groupBox_6->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        lineEdit_DeliveryID = new QLineEdit(groupBox_6);
        lineEdit_DeliveryID->setObjectName(QString::fromUtf8("lineEdit_DeliveryID"));
        lineEdit_DeliveryID->setGeometry(QRect(12, 20, 81, 21));
        lineEdit_DeliveryID->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        comboBox_Status = new QComboBox(frame_5);
        comboBox_Status->addItem(QString());
        comboBox_Status->addItem(QString());
        comboBox_Status->addItem(QString());
        comboBox_Status->addItem(QString());
        comboBox_Status->setObjectName(QString::fromUtf8("comboBox_Status"));
        comboBox_Status->setGeometry(QRect(200, 350, 121, 51));
        comboBox_Status->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        return_main = new QPushButton(add_delivery);
        return_main->setObjectName(QString::fromUtf8("return_main"));
        return_main->setGeometry(QRect(70, 40, 51, 51));
        return_main->setStyleSheet(QString::fromUtf8("background:#D3D3D3;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/arrow1.png"), QSize(), QIcon::Normal, QIcon::Off);
        return_main->setIcon(icon6);
        return_main->setIconSize(QSize(30, 30));
        Deliver->addWidget(add_delivery);
        timeline = new QWidget();
        timeline->setObjectName(QString::fromUtf8("timeline"));
        TL_ORDERED = new QPushButton(timeline);
        TL_ORDERED->setObjectName(QString::fromUtf8("TL_ORDERED"));
        TL_ORDERED->setGeometry(QRect(150, 230, 151, 150));
        TL_ORDERED->setStyleSheet(QString::fromUtf8("background:#1BA019;\n"
"/*background:#EFFADC;*/\n"
"border-radius: 70px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/ordered.png"), QSize(), QIcon::Normal, QIcon::Off);
        TL_ORDERED->setIcon(icon7);
        TL_ORDERED->setIconSize(QSize(80, 80));
        TL_IN_PROGRESS = new QPushButton(timeline);
        TL_IN_PROGRESS->setObjectName(QString::fromUtf8("TL_IN_PROGRESS"));
        TL_IN_PROGRESS->setGeometry(QRect(460, 230, 151, 150));
        TL_IN_PROGRESS->setStyleSheet(QString::fromUtf8("background:#1BA019;\n"
"/*background:#CBF84C;*/\n"
"border-radius: 70px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/in_progress.png"), QSize(), QIcon::Normal, QIcon::Off);
        TL_IN_PROGRESS->setIcon(icon8);
        TL_IN_PROGRESS->setIconSize(QSize(80, 80));
        TL_DELIVERED = new QPushButton(timeline);
        TL_DELIVERED->setObjectName(QString::fromUtf8("TL_DELIVERED"));
        TL_DELIVERED->setGeometry(QRect(760, 230, 151, 150));
        TL_DELIVERED->setStyleSheet(QString::fromUtf8("background:#1BA019;\n"
"/*background:#93D52D;*/\n"
"border-radius: 70px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/delivered.png"), QSize(), QIcon::Normal, QIcon::Off);
        TL_DELIVERED->setIcon(icon9);
        TL_DELIVERED->setIconSize(QSize(80, 80));
        progressBar_1 = new QProgressBar(timeline);
        progressBar_1->setObjectName(QString::fromUtf8("progressBar_1"));
        progressBar_1->setGeometry(QRect(310, 300, 131, 23));
        progressBar_1->setStyleSheet(QString::fromUtf8("\n"
"border-radius: 5px;\n"
"border: 1px solid;\n"
"\n"
""));
        progressBar_1->setMinimum(0);
        progressBar_1->setMaximum(100);
        progressBar_1->setValue(99);
        progressBar_1->setTextVisible(false);
        progressBar_2 = new QProgressBar(timeline);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(620, 300, 131, 23));
        progressBar_2->setAutoFillBackground(false);
        progressBar_2->setStyleSheet(QString::fromUtf8("\n"
"border-radius: 5px;\n"
"border: 1px solid;\n"
"\n"
""));
        progressBar_2->setValue(50);
        progressBar_2->setTextVisible(false);
        progressBar_2->setInvertedAppearance(false);
        Label_ordered = new QLabel(timeline);
        Label_ordered->setObjectName(QString::fromUtf8("Label_ordered"));
        Label_ordered->setGeometry(QRect(170, 410, 111, 41));
        Label_ordered->setStyleSheet(QString::fromUtf8("*{\n"
"background: #1BA019;\n"
"border-radius: 12px;\n"
"/* Header-6 Bold */\n"
"font-family: Lexend;\n"
"font-size: 20px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: 30px; /* 150% */\n"
"\n"
"}"));
        Label_ordered->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Label_in_progress = new QLabel(timeline);
        Label_in_progress->setObjectName(QString::fromUtf8("Label_in_progress"));
        Label_in_progress->setGeometry(QRect(460, 410, 151, 41));
        Label_in_progress->setStyleSheet(QString::fromUtf8("*{\n"
"background: #1BA019;\n"
"border-radius: 12px;\n"
"/* Header-6 Bold */\n"
"font-family: Lexend;\n"
"font-size: 18px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: 30px; /* 150% */\n"
"\n"
"}"));
        Label_in_progress->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Label_delivered = new QLabel(timeline);
        Label_delivered->setObjectName(QString::fromUtf8("Label_delivered"));
        Label_delivered->setGeometry(QRect(780, 410, 111, 41));
        Label_delivered->setStyleSheet(QString::fromUtf8("*{\n"
"background: #1BA019;\n"
"border-radius: 12px;\n"
"/* Header-6 Bold */\n"
"font-family: Lexend;\n"
"font-size: 20px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: 30px; /* 150% */\n"
"\n"
"}"));
        Label_delivered->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_7 = new QLabel(timeline);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 420, 551, 20));
        label_7->setStyleSheet(QString::fromUtf8("background: #1BA019;"));
        pushButton_2 = new QPushButton(timeline);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 20, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:#D3D3D3;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        pushButton_2->setIcon(icon6);
        pushButton_2->setIconSize(QSize(40, 40));
        label_delivered = new QLabel(timeline);
        label_delivered->setObjectName(QString::fromUtf8("label_delivered"));
        label_delivered->setGeometry(QRect(730, 160, 201, 41));
        label_in_progress = new QLabel(timeline);
        label_in_progress->setObjectName(QString::fromUtf8("label_in_progress"));
        label_in_progress->setGeometry(QRect(430, 160, 201, 41));
        label_ordered = new QLabel(timeline);
        label_ordered->setObjectName(QString::fromUtf8("label_ordered"));
        label_ordered->setGeometry(QRect(120, 160, 201, 41));
        Deliver->addWidget(timeline);
        label_7->raise();
        progressBar_1->raise();
        TL_ORDERED->raise();
        TL_IN_PROGRESS->raise();
        TL_DELIVERED->raise();
        progressBar_2->raise();
        Label_ordered->raise();
        Label_in_progress->raise();
        Label_delivered->raise();
        pushButton_2->raise();
        label_delivered->raise();
        label_in_progress->raise();
        label_ordered->raise();
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_qrcode_ordered = new QLabel(page_6);
        label_qrcode_ordered->setObjectName(QString::fromUtf8("label_qrcode_ordered"));
        label_qrcode_ordered->setGeometry(QRect(330, 60, 481, 481));
        label_qrcode_ordered->setPixmap(QPixmap(QString::fromUtf8(":/images/qrcode_ordered.png")));
        back_qrcode_ordered = new QPushButton(page_6);
        back_qrcode_ordered->setObjectName(QString::fromUtf8("back_qrcode_ordered"));
        back_qrcode_ordered->setGeometry(QRect(530, 590, 121, 41));
        Deliver->addWidget(page_6);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_qrcode_in_progress = new QLabel(page);
        label_qrcode_in_progress->setObjectName(QString::fromUtf8("label_qrcode_in_progress"));
        label_qrcode_in_progress->setGeometry(QRect(330, 60, 481, 481));
        label_qrcode_in_progress->setPixmap(QPixmap(QString::fromUtf8(":/images/qrcode_in_progress.png")));
        label_qrcode_in_progress->setScaledContents(true);
        back_qrcode_in_progress = new QPushButton(page);
        back_qrcode_in_progress->setObjectName(QString::fromUtf8("back_qrcode_in_progress"));
        back_qrcode_in_progress->setGeometry(QRect(510, 600, 121, 41));
        Deliver->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_qrcode_delivered = new QLabel(page_2);
        label_qrcode_delivered->setObjectName(QString::fromUtf8("label_qrcode_delivered"));
        label_qrcode_delivered->setGeometry(QRect(330, 60, 481, 481));
        label_qrcode_delivered->setPixmap(QPixmap(QString::fromUtf8(":/images/qrcode_delivered.png")));
        label_qrcode_delivered->setScaledContents(true);
        back_qrcode_delivered = new QPushButton(page_2);
        back_qrcode_delivered->setObjectName(QString::fromUtf8("back_qrcode_delivered"));
        back_qrcode_delivered->setGeometry(QRect(502, 600, 101, 41));
        Deliver->addWidget(page_2);
        stats = new QWidget();
        stats->setObjectName(QString::fromUtf8("stats"));
        Deliver->addWidget(stats);
        main->addWidget(Deliverie);
        Cannitech = new QFrame(management);
        Cannitech->setObjectName(QString::fromUtf8("Cannitech"));
        Cannitech->setGeometry(QRect(20, 20, 281, 661));
        Cannitech->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white; /* Background color for the frame */\n"
"    border: none;            /* No border for the frame */\n"
"    border-bottom: 2px solid #d0d0d0; /* Bottom border */\n"
"    border-right: 2px solid #d0d0d0;  /* Right border */\n"
"    border-radius: 8px;     /* Rounded corners */\n"
"}\n"
""));
        Cannitech->setFrameShape(QFrame::Shape::NoFrame);
        Cannitech->setFrameShadow(QFrame::Shadow::Plain);
        Cannitech->setLineWidth(0);
        Cannitech->setMidLineWidth(0);
        dahsboard = new QPushButton(Cannitech);
        dahsboard->setObjectName(QString::fromUtf8("dahsboard"));
        dahsboard->setGeometry(QRect(0, 175, 281, 50));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dahsboard->sizePolicy().hasHeightForWidth());
        dahsboard->setSizePolicy(sizePolicy);
        dahsboard->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        dahsboard->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        dahsboard->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        dahsboard->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:transparent;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:5px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-right:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/figma/apps.png"), QSize(), QIcon::Normal, QIcon::Off);
        dahsboard->setIcon(icon10);
        dahsboard->setIconSize(QSize(30, 30));
        dahsboard->setCheckable(false);
        dahsboard->setAutoRepeat(false);
        dahsboard->setAutoExclusive(false);
        dahsboard->setAutoRepeatDelay(300);
        dahsboard->setFlat(false);
        employees = new QPushButton(Cannitech);
        employees->setObjectName(QString::fromUtf8("employees"));
        employees->setGeometry(QRect(0, 235, 281, 50));
        sizePolicy.setHeightForWidth(employees->sizePolicy().hasHeightForWidth());
        employees->setSizePolicy(sizePolicy);
        employees->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        employees->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        employees->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        employees->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:transparent;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:5px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-right:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/figma/users 02.png"), QSize(), QIcon::Normal, QIcon::Off);
        employees->setIcon(icon11);
        employees->setIconSize(QSize(30, 30));
        employees->setCheckable(false);
        employees->setAutoRepeat(false);
        employees->setAutoExclusive(false);
        factories = new QPushButton(Cannitech);
        factories->setObjectName(QString::fromUtf8("factories"));
        factories->setGeometry(QRect(0, 295, 281, 50));
        sizePolicy.setHeightForWidth(factories->sizePolicy().hasHeightForWidth());
        factories->setSizePolicy(sizePolicy);
        factories->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        factories->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        factories->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        factories->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:transparent;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:5px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-right:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/figma/community.png"), QSize(), QIcon::Normal, QIcon::Off);
        factories->setIcon(icon12);
        factories->setIconSize(QSize(30, 30));
        factories->setCheckable(false);
        factories->setAutoRepeat(false);
        factories->setAutoExclusive(false);
        deliveries = new QPushButton(Cannitech);
        deliveries->setObjectName(QString::fromUtf8("deliveries"));
        deliveries->setGeometry(QRect(0, 416, 281, 50));
        sizePolicy.setHeightForWidth(deliveries->sizePolicy().hasHeightForWidth());
        deliveries->setSizePolicy(sizePolicy);
        deliveries->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        deliveries->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        deliveries->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        deliveries->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:transparent;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:5px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-right:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/figma/notepad.png"), QSize(), QIcon::Normal, QIcon::Off);
        deliveries->setIcon(icon13);
        deliveries->setIconSize(QSize(30, 30));
        deliveries->setCheckable(false);
        deliveries->setAutoRepeat(false);
        deliveries->setAutoExclusive(false);
        clients = new QPushButton(Cannitech);
        clients->setObjectName(QString::fromUtf8("clients"));
        clients->setGeometry(QRect(0, 475, 281, 50));
        sizePolicy.setHeightForWidth(clients->sizePolicy().hasHeightForWidth());
        clients->setSizePolicy(sizePolicy);
        clients->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        clients->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        clients->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        clients->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:transparent;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:5px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-right:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/figma/users 01.png"), QSize(), QIcon::Normal, QIcon::Off);
        clients->setIcon(icon14);
        clients->setIconSize(QSize(30, 30));
        clients->setCheckable(false);
        clients->setAutoRepeat(false);
        clients->setAutoExclusive(false);
        dash_icon = new QLabel(Cannitech);
        dash_icon->setObjectName(QString::fromUtf8("dash_icon"));
        dash_icon->setGeometry(QRect(50, 190, 20, 20));
        dash_icon->setStyleSheet(QString::fromUtf8("border:none;"));
        dash_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/apps.png")));
        dash_icon->setScaledContents(true);
        emp_icon = new QLabel(Cannitech);
        emp_icon->setObjectName(QString::fromUtf8("emp_icon"));
        emp_icon->setGeometry(QRect(50, 250, 20, 20));
        emp_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/users 02.png")));
        emp_icon->setScaledContents(true);
        fac_icon = new QLabel(Cannitech);
        fac_icon->setObjectName(QString::fromUtf8("fac_icon"));
        fac_icon->setGeometry(QRect(50, 310, 20, 20));
        fac_icon->setStyleSheet(QString::fromUtf8("border:none;"));
        fac_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/community.png")));
        fac_icon->setScaledContents(true);
        del_icon = new QLabel(Cannitech);
        del_icon->setObjectName(QString::fromUtf8("del_icon"));
        del_icon->setGeometry(QRect(50, 430, 20, 20));
        del_icon->setStyleSheet(QString::fromUtf8("border:none;"));
        del_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/notepad.png")));
        del_icon->setScaledContents(true);
        cli_icon = new QLabel(Cannitech);
        cli_icon->setObjectName(QString::fromUtf8("cli_icon"));
        cli_icon->setGeometry(QRect(50, 490, 20, 20));
        cli_icon->setStyleSheet(QString::fromUtf8("border:none;"));
        cli_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/users 01.png")));
        cli_icon->setScaledContents(true);
        machines = new QPushButton(Cannitech);
        machines->setObjectName(QString::fromUtf8("machines"));
        machines->setGeometry(QRect(0, 356, 281, 50));
        sizePolicy.setHeightForWidth(machines->sizePolicy().hasHeightForWidth());
        machines->setSizePolicy(sizePolicy);
        machines->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        machines->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        machines->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        machines->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:transparent;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:5px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-right:3px solid #1BA019 ; \n"
"border-right:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        machines->setIcon(icon13);
        machines->setIconSize(QSize(30, 30));
        machines->setCheckable(false);
        machines->setAutoRepeat(false);
        machines->setAutoExclusive(false);
        del_icon_2 = new QLabel(Cannitech);
        del_icon_2->setObjectName(QString::fromUtf8("del_icon_2"));
        del_icon_2->setGeometry(QRect(50, 370, 20, 20));
        del_icon_2->setStyleSheet(QString::fromUtf8("border:none;"));
        del_icon_2->setPixmap(QPixmap(QString::fromUtf8(":/images/notepad.png")));
        del_icon_2->setScaledContents(true);
        label_21 = new QLabel(Cannitech);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, -6, 271, 161));
        label_21->setStyleSheet(QString::fromUtf8("QFrame{border-radius:10px;\n"
"background-color:transparent;\n"
"border:none;\n"
"}\n"
""));
        label_21->setFrameShape(QFrame::Shape::NoFrame);
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/images/logoh.png")));
        label_21->setScaledContents(true);
        label_21->setWordWrap(false);
        logout = new QPushButton(Cannitech);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(60, 570, 161, 51));
        logout->setStyleSheet(QString::fromUtf8("*{\n"
"background:transparent;\n"
"border-radius:25px;\n"
"color:#1ba019;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#00b521;\n"
"color:#1ba019;\n"
"border-left:3px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:25px;\n"
"\n"
"\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background:#013220;\n"
"color:#1ba019;\n"
"border-radius:25px;\n"
"color:#1ba019;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"border-radius:10px;\n"
"border-left:3.5px solid #1BA019 ; \n"
"\n"
"\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        logout->setIconSize(QSize(200, 200));
        logout->setAutoRepeatInterval(100);
        clients->raise();
        deliveries->raise();
        factories->raise();
        dahsboard->raise();
        employees->raise();
        dash_icon->raise();
        emp_icon->raise();
        fac_icon->raise();
        del_icon->raise();
        cli_icon->raise();
        machines->raise();
        del_icon_2->raise();
        label_21->raise();
        logout->raise();
        bg = new QLabel(management);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(0, 0, 1371, 791));
        bg->setPixmap(QPixmap(QString::fromUtf8(":/images/bg.jpg")));
        bg->setScaledContents(true);
        bg->raise();
        main->raise();
        Cannitech->raise();

        retranslateUi(management);

        main->setCurrentIndex(0);
        employee->setCurrentIndex(3);
        Deliver->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(management);
    } // setupUi

    void retranslateUi(QWidget *management)
    {
        management->setWindowTitle(QCoreApplication::translate("management", "Form", nullptr));
        search_2->setTitle(QString());
        search_icon->setText(QString());
        add_employee_btn->setText(QCoreApplication::translate("management", "  Add New Employee", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("management", "Employee ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("management", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("management", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("management", "PhoneNumber", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("management", "Position", nullptr));
        update_employee_btn->setText(QCoreApplication::translate("management", "Update", nullptr));
        delete_employee_btn->setText(QCoreApplication::translate("management", "Delete", nullptr));
        searchReset->setText(QCoreApplication::translate("management", "X", nullptr));
        search->setItemText(0, QCoreApplication::translate("management", "name", nullptr));
        search->setItemText(1, QCoreApplication::translate("management", "id", nullptr));

        search_field->setInputMask(QString());
        search_field->setText(QString());
        search_field->setPlaceholderText(QCoreApplication::translate("management", "Search for an Employee", nullptr));
        email->setTitle(QCoreApplication::translate("management", "Email", nullptr));
        email_field->setText(QString());
        Sub_title->setText(QCoreApplication::translate("management", "Please fill in the fields", nullptr));
        name->setTitle(QCoreApplication::translate("management", "Name", nullptr));
        name_field->setText(QString());
        Title->setText(QCoreApplication::translate("management", "Add a new employee", nullptr));
        phone_number->setTitle(QCoreApplication::translate("management", "Phone Number", nullptr));
        phone_field->setText(QString());
        position->setTitle(QCoreApplication::translate("management", "Position", nullptr));
        position_field->setItemText(0, QCoreApplication::translate("management", "Chef Cuisine", nullptr));
        position_field->setItemText(1, QCoreApplication::translate("management", "Manager", nullptr));
        position_field->setItemText(2, QCoreApplication::translate("management", "technicien", nullptr));

        confirm_employee_btn->setText(QCoreApplication::translate("management", "  Confirm", nullptr));
        add_back->setText(QCoreApplication::translate("management", "Back", nullptr));
        Sub_title_6->setText(QCoreApplication::translate("management", "Please change the fields", nullptr));
        position_3->setTitle(QCoreApplication::translate("management", "Position", nullptr));
        position_update->setItemText(0, QCoreApplication::translate("management", "Chef ", nullptr));
        position_update->setItemText(1, QCoreApplication::translate("management", "Manager", nullptr));
        position_update->setItemText(2, QCoreApplication::translate("management", "Tech", nullptr));

        name_3->setTitle(QCoreApplication::translate("management", "Name", nullptr));
        name_update->setText(QString());
        email_6->setTitle(QCoreApplication::translate("management", "Email", nullptr));
        email_update->setText(QString());
        phone_number_6->setTitle(QCoreApplication::translate("management", "Phone Number", nullptr));
        phone_update->setText(QString());
        confirm_update_btn->setText(QCoreApplication::translate("management", "Confirm", nullptr));
        Title_6->setText(QCoreApplication::translate("management", "Update This employee", nullptr));
        update_back->setText(QCoreApplication::translate("management", "Back", nullptr));
        txt_2->setText(QCoreApplication::translate("management", "View Employee History", nullptr));
        employee_export->setText(QCoreApplication::translate("management", "Export", nullptr));
        history_back->setText(QCoreApplication::translate("management", "Back", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableH->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("management", "Presence ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableH->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("management", "Employee ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableH->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("management", "Check In", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableH->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("management", "Check Out", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableH->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("management", "Working Hours", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableH->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("management", "Status", nullptr));
        progressBar4->setFormat(QCoreApplication::translate("management", "%p Employee", nullptr));
        label->setText(QCoreApplication::translate("management", "Total Employees :", nullptr));
        progressBar2->setFormat(QCoreApplication::translate("management", "%p %", nullptr));
        progressBar3->setFormat(QCoreApplication::translate("management", "%p %", nullptr));
        progressBar1->setFormat(QCoreApplication::translate("management", "%p %", nullptr));
        label_2->setText(QCoreApplication::translate("management", "Technicians", nullptr));
        label_3->setText(QCoreApplication::translate("management", "Chef", nullptr));
        label_4->setText(QCoreApplication::translate("management", "Manager", nullptr));
        pushButton_3->setText(QCoreApplication::translate("management", "Add New Delivery", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("management", "DeliveryID", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("management", "ClientID", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("management", "EmployeeID", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("management", "DeliveryAdress", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("management", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("management", "DeliveryDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("management", "Qrcode", nullptr));
        edit_table_button->setText(QString());
        button_delete->setText(QString());
        export_table->setText(QString());
        statsbutton->setText(QString());
        search_3->setTitle(QString());
        search_icon_3->setText(QString());
        lineEdit_4->setText(QString());
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("management", "search", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("management", "Add new delivery", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("management", "ClientID", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("management", "EmployeeID", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("management", "DeliveryAdress", nullptr));
        pushButton_10->setText(QCoreApplication::translate("management", "Add", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("management", "DeliveryID", nullptr));
        comboBox_Status->setItemText(0, QCoreApplication::translate("management", "Status", nullptr));
        comboBox_Status->setItemText(1, QCoreApplication::translate("management", "Ordered", nullptr));
        comboBox_Status->setItemText(2, QCoreApplication::translate("management", "In Progress", nullptr));
        comboBox_Status->setItemText(3, QCoreApplication::translate("management", "Delivered", nullptr));

        return_main->setText(QString());
        TL_ORDERED->setText(QString());
        TL_IN_PROGRESS->setText(QString());
        TL_DELIVERED->setText(QString());
        Label_ordered->setText(QCoreApplication::translate("management", "Ordered", nullptr));
        Label_in_progress->setText(QCoreApplication::translate("management", "In Progress", nullptr));
        Label_delivered->setText(QCoreApplication::translate("management", "Delivered", nullptr));
        label_7->setText(QString());
        pushButton_2->setText(QString());
        label_delivered->setText(QString());
        label_in_progress->setText(QString());
        label_ordered->setText(QString());
        label_qrcode_ordered->setText(QString());
        back_qrcode_ordered->setText(QCoreApplication::translate("management", "Back", nullptr));
        label_qrcode_in_progress->setText(QString());
        back_qrcode_in_progress->setText(QCoreApplication::translate("management", "back", nullptr));
        label_qrcode_delivered->setText(QString());
        back_qrcode_delivered->setText(QCoreApplication::translate("management", "back", nullptr));
        dahsboard->setText(QCoreApplication::translate("management", "Dashboard", nullptr));
        employees->setText(QCoreApplication::translate("management", "Employees", nullptr));
        factories->setText(QCoreApplication::translate("management", "Factories", nullptr));
        deliveries->setText(QCoreApplication::translate("management", "Delivries", nullptr));
        clients->setText(QCoreApplication::translate("management", "Clients", nullptr));
        dash_icon->setText(QString());
        emp_icon->setText(QString());
        fac_icon->setText(QString());
        del_icon->setText(QString());
        cli_icon->setText(QString());
        machines->setText(QCoreApplication::translate("management", "Machines", nullptr));
        del_icon_2->setText(QString());
        label_21->setText(QString());
        logout->setText(QCoreApplication::translate("management", "Logout", nullptr));
        bg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class management: public Ui_management {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENT_H
