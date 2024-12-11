/********************************************************************************
** Form generated from reading UI file 'email.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAIL_H
#define UI_EMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_email
{
public:
    QFrame *stat1_2;
    QPushButton *send;
    QPushButton *cancel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *toLineEdit;
    QLabel *label_3;
    QLineEdit *subjectLineEdit;
    QLabel *label;
    QLineEdit *fromLineEdit;
    QTextEdit *messageTextEdit;

    void setupUi(QDialog *email)
    {
        if (email->objectName().isEmpty())
            email->setObjectName(QString::fromUtf8("email"));
        email->resize(568, 492);
        stat1_2 = new QFrame(email);
        stat1_2->setObjectName(QString::fromUtf8("stat1_2"));
        stat1_2->setGeometry(QRect(10, 10, 551, 471));
        stat1_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white; /* Background color for the frame */\n"
"    border: none;            /* No border for the frame */\n"
"    border-bottom: 2px solid #d0d0d0; /* Bottom border */\n"
"    border-right: 2px solid #d0d0d0;  /* Right border */\n"
"    border-radius: 8px;     /* Rounded corners */\n"
"}\n"
""));
        stat1_2->setFrameShape(QFrame::StyledPanel);
        stat1_2->setFrameShadow(QFrame::Raised);
        send = new QPushButton(stat1_2);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(440, 10, 101, 51));
        send->setStyleSheet(QString::fromUtf8("*{\n"
"background:#1ba019;\n"
"border-radius:25px;\n"
"color:white;\n"
"font-family: Lexend;\n"
"font-size:16px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#00b521;\n"
"color:white;\n"
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
"color:black;\n"
"border-radius:25px;\n"
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
        cancel = new QPushButton(stat1_2);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(440, 70, 101, 51));
        cancel->setStyleSheet(QString::fromUtf8("*{\n"
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
        gridLayoutWidget = new QWidget(stat1_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 431, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        toLineEdit = new QLineEdit(gridLayoutWidget);
        toLineEdit->setObjectName(QString::fromUtf8("toLineEdit"));

        gridLayout->addWidget(toLineEdit, 4, 0, 1, 2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        subjectLineEdit = new QLineEdit(gridLayoutWidget);
        subjectLineEdit->setObjectName(QString::fromUtf8("subjectLineEdit"));

        gridLayout->addWidget(subjectLineEdit, 6, 0, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(label, 1, 0, 1, 2);

        fromLineEdit = new QLineEdit(gridLayoutWidget);
        fromLineEdit->setObjectName(QString::fromUtf8("fromLineEdit"));

        gridLayout->addWidget(fromLineEdit, 2, 0, 1, 2);

        messageTextEdit = new QTextEdit(gridLayoutWidget);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));

        gridLayout->addWidget(messageTextEdit, 8, 0, 1, 1);


        retranslateUi(email);

        QMetaObject::connectSlotsByName(email);
    } // setupUi

    void retranslateUi(QDialog *email)
    {
        email->setWindowTitle(QCoreApplication::translate("email", "Dialog", nullptr));
        send->setText(QCoreApplication::translate("email", "Send", nullptr));
        cancel->setText(QCoreApplication::translate("email", "Cancel", nullptr));
        label_4->setText(QCoreApplication::translate("email", "Message :", nullptr));
        label_2->setText(QCoreApplication::translate("email", "To :", nullptr));
        label_3->setText(QCoreApplication::translate("email", "Subject :", nullptr));
        label->setText(QCoreApplication::translate("email", "From :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class email: public Ui_email {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAIL_H
