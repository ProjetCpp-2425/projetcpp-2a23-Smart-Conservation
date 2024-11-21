/********************************************************************************
** Form generated from reading UI file 'commande.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDE_H
#define UI_COMMANDE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_commande
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QPushButton *Dashboard_Button;
    QPushButton *Employee_Button;
    QPushButton *Factories_Button;
    QPushButton *Deliveries_Button;
    QPushButton *pushButton_8;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_2;
    QFrame *frame_2;
    QLineEdit *lineEdit;
    QLabel *label_12;
    QPushButton *pushButton;
    QLabel *label_7;
    QFrame *frame_4;
    QPushButton *pushButton_9;
    QLabel *label_19;
    QLabel *label_20;
    QStackedWidget *main_rose;
    QWidget *delivery;
    QStackedWidget *stackedWidget_2;
    QWidget *maindelivery;
    QFrame *frame_3;
    QLineEdit *lineEdit_4;
    QLabel *label_11;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QPushButton *edit_table_button;
    QPushButton *button_delete;
    QPushButton *export_table;
    QPushButton *statsbutton;
    QWidget *add_delivery;
    QLabel *label_4;
    QFrame *frame_5;
    QLabel *label_3;
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
    QLabel *label_6;
    QPushButton *pushButton_2;
    QLabel *label_ordered;
    QLabel *label_in_progress;
    QLabel *label_delivered;
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
    QWidget *page_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *commande)
    {
        if (commande->objectName().isEmpty())
            commande->setObjectName(QString::fromUtf8("commande"));
        commande->resize(1440, 1080);
        commande->setStyleSheet(QString::fromUtf8("background:white;"));
        centralwidget = new QWidget(commande);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 20, 171, 21));
        label->setStyleSheet(QString::fromUtf8("*{\n"
"color: var(--Dark-500, #16151C);\n"
"\n"
"/* Header-6 Bold */\n"
"font-family: Lexend;\n"
"font-size: 20px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: 30px; /* 150% */\n"
"background:none;\n"
"}"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 280, 831));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgba(236,236,236,108);\n"
"\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        Dashboard_Button = new QPushButton(frame);
        Dashboard_Button->setObjectName(QString::fromUtf8("Dashboard_Button"));
        Dashboard_Button->setGeometry(QRect(40, 110, 220, 50));
        Dashboard_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(236,236,236,108);\n"
"\n"
"\n"
"border: 1px solid;\n"
"border-color:#ececec;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3.5px solid #1BA019 ; \n"
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
"border-left:5px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        Employee_Button = new QPushButton(frame);
        Employee_Button->setObjectName(QString::fromUtf8("Employee_Button"));
        Employee_Button->setGeometry(QRect(40, 160, 220, 50));
        Employee_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(236,236,236,108);\n"
"\n"
"border: 1px solid;\n"
"border-color:#ececec;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3.5px solid #1BA019 ; \n"
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
"border-left:5px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        Factories_Button = new QPushButton(frame);
        Factories_Button->setObjectName(QString::fromUtf8("Factories_Button"));
        Factories_Button->setGeometry(QRect(40, 210, 220, 50));
        Factories_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(236,236,236,108);\n"
"border: 1px solid;\n"
"border-color:#ececec;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3.5px solid #1BA019 ; \n"
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
"border-left:5px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        Deliveries_Button = new QPushButton(frame);
        Deliveries_Button->setObjectName(QString::fromUtf8("Deliveries_Button"));
        Deliveries_Button->setGeometry(QRect(40, 260, 220, 50));
        Deliveries_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(236,236,236,108);\n"
"\n"
"\n"
"border: 1px solid;\n"
"border-color:#ececec;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3.5px solid #1BA019 ; \n"
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
"border-left:5px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(40, 310, 220, 50));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(236,236,236,108);\n"
"\n"
"\n"
"border: 1px solid;\n"
"border-color:#ececec;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#aaaaaa;\n"
"color:#1BA019;\n"
"border-left:3.5px solid #1BA019 ; \n"
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
"border-left:5px solid #1BA019 ; \n"
"border-color:none;\n"
"border-radius:10px;\n"
"/*background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ffffff, stop: 1 #dcdcdc);*/\n"
"}"));
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(50, 120, 31, 31));
        label_14->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: px solid;\n"
"border-color:none;\n"
""));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/figma/apps.png")));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(50, 220, 31, 31));
        label_15->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: px solid;\n"
"border-color:none;\n"
""));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/figma/community.png")));
        label_16 = new QLabel(frame);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(50, 270, 31, 31));
        label_16->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: px solid;\n"
"border-color:none;\n"
""));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/figma/notepad.png")));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(50, 170, 31, 31));
        label_17->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: px solid;\n"
"border-color:none;\n"
""));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/figma/users 02.png")));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(50, 320, 31, 31));
        label_18->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: px solid;\n"
"border-color:none;\n"
""));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/figma/users 01.png")));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 181, 41));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/figma/cannitech_logo.svg")));
        Dashboard_Button->raise();
        Employee_Button->raise();
        Factories_Button->raise();
        Deliveries_Button->raise();
        pushButton_8->raise();
        label_14->raise();
        label_17->raise();
        label_15->raise();
        label_16->raise();
        label_18->raise();
        label_2->raise();
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(790, 20, 311, 50));
        frame_2->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border: 1px solid;\n"
"border-color:gray;\n"
"background:white;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 10, 171, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("color:gray;\n"
"background:white;\n"
"border: 0px solid;\n"
"border-color:none;\n"
"\n"
"/* Body-1 Regular */\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"font-style: normal;\n"
"font-weight: 300;\n"
"line-height: 24px; /* 150% */"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 10, 31, 31));
        label_12->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:none;\n"
""));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/Icon.png")));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1120, 20, 50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("background:#D3D3D3;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/figma/notification.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(340, 40, 131, 21));
        label_7->setStyleSheet(QString::fromUtf8("*{\n"
"\n"
"color:gray;\n"
"/* Body-2 Regular */\n"
"font-family:Lexend;\n"
"font-size:14px;\n"
"font-style: normal;\n"
"font-weight: 300;\n"
"line-height: 22px; /* 157.143% */\n"
"background:none;\n"
"}"));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(1200, 20, 191, 50));
        frame_4->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border: 1px solid;\n"
"border-color:gray;\n"
"background:white;"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_9 = new QPushButton(frame_4);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(0, 0, 50, 50));
        pushButton_9->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:none;\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/figma/pngwing.com.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon1);
        pushButton_9->setIconSize(QSize(30, 30));
        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 3, 141, 21));
        label_19->setStyleSheet(QString::fromUtf8("*{\n"
"background:none;\n"
"border:none;\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"}"));
        label_20 = new QLabel(frame_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(50, 20, 141, 21));
        label_20->setStyleSheet(QString::fromUtf8("*{\n"
"\n"
"color:gray;\n"
"font-family:Lexend;\n"
"font-size:14px;\n"
"font-style: normal;\n"
"font-weight: 300;\n"
"line-height: 22px; \n"
"background:none;\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        main_rose = new QStackedWidget(centralwidget);
        main_rose->setObjectName(QString::fromUtf8("main_rose"));
        main_rose->setGeometry(QRect(310, 80, 1211, 781));
        main_rose->setStyleSheet(QString::fromUtf8("/*background:pink;*/\n"
"background:none;"));
        delivery = new QWidget();
        delivery->setObjectName(QString::fromUtf8("delivery"));
        stackedWidget_2 = new QStackedWidget(delivery);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 0, 1291, 761));
        stackedWidget_2->setCursor(QCursor(Qt::CrossCursor));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,128);"));
        maindelivery = new QWidget();
        maindelivery->setObjectName(QString::fromUtf8("maindelivery"));
        frame_3 = new QFrame(maindelivery);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(50, 60, 371, 50));
        frame_3->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border: 1px solid;\n"
"border-color:gray;\n"
"background:white;"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_4 = new QLineEdit(frame_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(40, 10, 321, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("color:gray;\n"
"background:white;\n"
"border: 0px solid;\n"
"border-color:none;\n"
"\n"
"/* Body-1 Regular */\n"
"font-family: Lexend;\n"
"font-size: 16px;\n"
"font-style: normal;\n"
"font-weight: 300;\n"
"line-height: 24px; /* 150% */"));
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 10, 31, 31));
        label_11->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:none;\n"
""));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/Icon.png")));
        pushButton_3 = new QPushButton(maindelivery);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(690, 50, 211, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("*{\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/figma/add-circle.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(20, 20));
        tableWidget = new QTableWidget(maindelivery);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(45, 201, 1051, 561));
        QFont font1;
        font1.setPointSize(12);
        font1.setKerning(false);
        tableWidget->setFont(font1);
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
"background-color:transparent;\n"
"border:none;\n"
"}\n"
"QHeaderView::section {\n"
"    border: none;\n"
"background-color:white;\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical {\n"
"    border:none;\n"
"    background:#85DD84;\n"
"    width: 12px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #1BA019;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical {\n"
"	background: #9CD79B;\n"
"}\n"
"QScrollBar::sub-page:vertical {\n"
"	background: #9CD79B;\n"
"}\n"
""));
        tableWidget->setFrameShape(QFrame::Shape::StyledPanel);
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
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
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
        edit_table_button->setGeometry(QRect(980, 50, 51, 51));
        edit_table_button->setStyleSheet(QString::fromUtf8("/*background:#D3D3D3;*/\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
"/*background:#478ecc;\n"
"azra9*/\n"
"background:#f8981d;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/figma/pnghut_user-profile-editing-logo-symbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        edit_table_button->setIcon(icon3);
        edit_table_button->setIconSize(QSize(40, 40));
        button_delete = new QPushButton(maindelivery);
        button_delete->setObjectName(QString::fromUtf8("button_delete"));
        button_delete->setGeometry(QRect(1040, 50, 51, 51));
        button_delete->setStyleSheet(QString::fromUtf8("/*background:#D3D3D3;*/\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
"background:#F04438;\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/figma/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_delete->setIcon(icon4);
        button_delete->setIconSize(QSize(30, 30));
        export_table = new QPushButton(maindelivery);
        export_table->setObjectName(QString::fromUtf8("export_table"));
        export_table->setGeometry(QRect(920, 50, 50, 51));
        export_table->setStyleSheet(QString::fromUtf8("background:#478ECC;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/figma/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        export_table->setIcon(icon5);
        export_table->setIconSize(QSize(30, 30));
        statsbutton = new QPushButton(maindelivery);
        statsbutton->setObjectName(QString::fromUtf8("statsbutton"));
        statsbutton->setGeometry(QRect(590, 50, 83, 51));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/figma/stats.png"), QSize(), QIcon::Normal, QIcon::Off);
        statsbutton->setIcon(icon6);
        stackedWidget_2->addWidget(maindelivery);
        add_delivery = new QWidget();
        add_delivery->setObjectName(QString::fromUtf8("add_delivery"));
        label_4 = new QLabel(add_delivery);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(64, 150, 561, 611));
        label_4->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border-color: none;\n"
"border-width : 1px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/figma/final2.jpg")));
        label_4->setWordWrap(false);
        frame_5 = new QFrame(add_delivery);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(640, 150, 491, 611));
        frame_5->setStyleSheet(QString::fromUtf8("background:white;"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 50, 211, 41));
        label_3->setStyleSheet(QString::fromUtf8("*{\n"
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
        groupBox_2->setGeometry(QRect(90, 240, 281, 51));
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
        groupBox_3->setGeometry(QRect(90, 330, 281, 51));
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
        groupBox_4->setGeometry(QRect(90, 150, 281, 51));
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
        pushButton_10->setGeometry(QRect(70, 510, 281, 50));
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
        groupBox_6->setGeometry(QRect(90, 420, 101, 51));
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
        comboBox_Status->setGeometry(QRect(250, 420, 121, 51));
        comboBox_Status->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        return_main = new QPushButton(add_delivery);
        return_main->setObjectName(QString::fromUtf8("return_main"));
        return_main->setGeometry(QRect(70, 70, 51, 51));
        return_main->setStyleSheet(QString::fromUtf8("background:#D3D3D3;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/figma/arrow1.png"), QSize(), QIcon::Normal, QIcon::Off);
        return_main->setIcon(icon7);
        return_main->setIconSize(QSize(30, 30));
        stackedWidget_2->addWidget(add_delivery);
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/figma/ordered.png"), QSize(), QIcon::Normal, QIcon::Off);
        TL_ORDERED->setIcon(icon8);
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/figma/in_progress.png"), QSize(), QIcon::Normal, QIcon::Off);
        TL_IN_PROGRESS->setIcon(icon9);
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
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/figma/delivered.png"), QSize(), QIcon::Normal, QIcon::Off);
        TL_DELIVERED->setIcon(icon10);
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
        Label_in_progress->setGeometry(QRect(480, 410, 111, 41));
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
        label_6 = new QLabel(timeline);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 420, 551, 20));
        label_6->setStyleSheet(QString::fromUtf8("background: #1BA019;"));
        pushButton_2 = new QPushButton(timeline);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 20, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:#D3D3D3;\n"
"border-radius: 20px;\n"
"border: 1px solid;\n"
"border-color:#D3D3D3;\n"
""));
        pushButton_2->setIcon(icon7);
        pushButton_2->setIconSize(QSize(40, 40));
        label_ordered = new QLabel(timeline);
        label_ordered->setObjectName(QString::fromUtf8("label_ordered"));
        label_ordered->setGeometry(QRect(130, 190, 201, 31));
        label_ordered->setStyleSheet(QString::fromUtf8("*{\n"
"background: gray;\n"
"border-radius: 12px;\n"
"color:white;\n"
"/* Header-6 Bold */\n"
"font-family: Lexend;\n"
"font-size: 20px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: 30px; /* 150% */\n"
"\n"
"}"));
        label_in_progress = new QLabel(timeline);
        label_in_progress->setObjectName(QString::fromUtf8("label_in_progress"));
        label_in_progress->setGeometry(QRect(440, 190, 201, 31));
        label_in_progress->setStyleSheet(QString::fromUtf8("*{\n"
"background: gray;\n"
"border-radius: 12px;\n"
"color:white;\n"
"/* Header-6 Bold */\n"
"font-family: Lexend;\n"
"font-size: 20px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: 30px; /* 150% */\n"
"\n"
"}"));
        label_delivered = new QLabel(timeline);
        label_delivered->setObjectName(QString::fromUtf8("label_delivered"));
        label_delivered->setGeometry(QRect(740, 190, 201, 31));
        label_delivered->setStyleSheet(QString::fromUtf8("*{\n"
"background: gray;\n"
"border-radius: 12px;\n"
"color:white;\n"
"\n"
"/* Header-6 Bold */\n"
"font-family: Lexend;\n"
"font-size: 20px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: 30px; /* 150% */\n"
"\n"
"}"));
        stackedWidget_2->addWidget(timeline);
        label_6->raise();
        progressBar_1->raise();
        TL_ORDERED->raise();
        TL_IN_PROGRESS->raise();
        TL_DELIVERED->raise();
        progressBar_2->raise();
        Label_ordered->raise();
        Label_in_progress->raise();
        Label_delivered->raise();
        pushButton_2->raise();
        label_ordered->raise();
        label_in_progress->raise();
        label_delivered->raise();
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_qrcode_ordered = new QLabel(page_6);
        label_qrcode_ordered->setObjectName(QString::fromUtf8("label_qrcode_ordered"));
        label_qrcode_ordered->setGeometry(QRect(330, 60, 481, 481));
        label_qrcode_ordered->setPixmap(QPixmap(QString::fromUtf8(":/figma/qrcode_ordered.png")));
        back_qrcode_ordered = new QPushButton(page_6);
        back_qrcode_ordered->setObjectName(QString::fromUtf8("back_qrcode_ordered"));
        back_qrcode_ordered->setGeometry(QRect(530, 590, 121, 41));
        stackedWidget_2->addWidget(page_6);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_qrcode_in_progress = new QLabel(page);
        label_qrcode_in_progress->setObjectName(QString::fromUtf8("label_qrcode_in_progress"));
        label_qrcode_in_progress->setGeometry(QRect(340, 60, 481, 481));
        label_qrcode_in_progress->setPixmap(QPixmap(QString::fromUtf8(":/figma/qrcode_in_progress.png")));
        label_qrcode_in_progress->setScaledContents(true);
        back_qrcode_in_progress = new QPushButton(page);
        back_qrcode_in_progress->setObjectName(QString::fromUtf8("back_qrcode_in_progress"));
        back_qrcode_in_progress->setGeometry(QRect(510, 600, 121, 41));
        stackedWidget_2->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_qrcode_delivered = new QLabel(page_2);
        label_qrcode_delivered->setObjectName(QString::fromUtf8("label_qrcode_delivered"));
        label_qrcode_delivered->setGeometry(QRect(330, 70, 481, 481));
        label_qrcode_delivered->setPixmap(QPixmap(QString::fromUtf8(":/figma/qrcode_delivered.png")));
        label_qrcode_delivered->setScaledContents(true);
        back_qrcode_delivered = new QPushButton(page_2);
        back_qrcode_delivered->setObjectName(QString::fromUtf8("back_qrcode_delivered"));
        back_qrcode_delivered->setGeometry(QRect(502, 600, 101, 41));
        stackedWidget_2->addWidget(page_2);
        stats = new QWidget();
        stats->setObjectName(QString::fromUtf8("stats"));
        stackedWidget_2->addWidget(stats);
        main_rose->addWidget(delivery);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        main_rose->addWidget(page_4);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 1461, 861));
        label_5->setAutoFillBackground(false);
        label_5->setFrameShape(QFrame::Shape::NoFrame);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/figma/bg.jpg")));
        label_5->setScaledContents(true);
        commande->setCentralWidget(centralwidget);
        label_5->raise();
        pushButton->raise();
        label->raise();
        frame->raise();
        frame_2->raise();
        label_7->raise();
        frame_4->raise();
        main_rose->raise();
        menubar = new QMenuBar(commande);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1440, 25));
        commande->setMenuBar(menubar);
        statusbar = new QStatusBar(commande);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        commande->setStatusBar(statusbar);
        toolBar = new QToolBar(commande);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        commande->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(commande);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        commande->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(commande);

        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(commande);
    } // setupUi

    void retranslateUi(QMainWindow *commande)
    {
        commande->setWindowTitle(QCoreApplication::translate("commande", "commande", nullptr));
        label->setText(QCoreApplication::translate("commande", "All deliveries", nullptr));
        Dashboard_Button->setText(QCoreApplication::translate("commande", "Dashboard", nullptr));
        Employee_Button->setText(QCoreApplication::translate("commande", "Employees", nullptr));
        Factories_Button->setText(QCoreApplication::translate("commande", "Factories", nullptr));
        Deliveries_Button->setText(QCoreApplication::translate("commande", "Delivries", nullptr));
        pushButton_8->setText(QCoreApplication::translate("commande", "Clients", nullptr));
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_2->setText(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("commande", "Search", nullptr));
        label_12->setText(QString());
        pushButton->setText(QString());
        label_7->setText(QCoreApplication::translate("commande", "Show All candidates", nullptr));
        pushButton_9->setText(QString());
        label_19->setText(QCoreApplication::translate("commande", "Username", nullptr));
        label_20->setText(QCoreApplication::translate("commande", "Position", nullptr));
        lineEdit_4->setText(QString());
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("commande", "search", nullptr));
        label_11->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("commande", "Add New Delivery", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("commande", "DeliveryID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("commande", "DeliveryAdress", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("commande", "STATUS", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("commande", "LastEditDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("commande", "ClientID", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("commande", "EmployeeID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("commande", "Qrcode", nullptr));
        edit_table_button->setText(QString());
        button_delete->setText(QString());
        export_table->setText(QString());
        statsbutton->setText(QString());
        label_4->setText(QString());
        label_3->setText(QCoreApplication::translate("commande", "Add new delivery", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("commande", "ClientID", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("commande", "EmployeeID", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("commande", "DeliveryAdress", nullptr));
        pushButton_10->setText(QCoreApplication::translate("commande", "Add", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("commande", "DeliveryID", nullptr));
        comboBox_Status->setItemText(0, QCoreApplication::translate("commande", "Status", nullptr));
        comboBox_Status->setItemText(1, QCoreApplication::translate("commande", "Ordered", nullptr));
        comboBox_Status->setItemText(2, QCoreApplication::translate("commande", "In Progress", nullptr));
        comboBox_Status->setItemText(3, QCoreApplication::translate("commande", "Delivered", nullptr));

        return_main->setText(QString());
        TL_ORDERED->setText(QString());
        TL_IN_PROGRESS->setText(QString());
        TL_DELIVERED->setText(QString());
        Label_ordered->setText(QCoreApplication::translate("commande", "Ordered", nullptr));
        Label_in_progress->setText(QCoreApplication::translate("commande", "In Progress", nullptr));
        Label_delivered->setText(QCoreApplication::translate("commande", "Delivered", nullptr));
        label_6->setText(QString());
        pushButton_2->setText(QString());
        label_ordered->setText(QString());
        label_in_progress->setText(QString());
        label_delivered->setText(QString());
        label_qrcode_ordered->setText(QString());
        back_qrcode_ordered->setText(QCoreApplication::translate("commande", "Back", nullptr));
        label_qrcode_in_progress->setText(QString());
        back_qrcode_in_progress->setText(QCoreApplication::translate("commande", "back", nullptr));
        label_qrcode_delivered->setText(QString());
        back_qrcode_delivered->setText(QCoreApplication::translate("commande", "back", nullptr));
        label_5->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("commande", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("commande", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class commande: public Ui_commande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDE_H
