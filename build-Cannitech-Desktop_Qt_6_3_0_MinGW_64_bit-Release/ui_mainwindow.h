/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *Auth;
    QWidget *Login;
    QGroupBox *user;
    QLineEdit *name1;
    QPushButton *SignUp_btn;
    QPushButton *Login_btn;
    QGroupBox *Password;
    QLineEdit *password1;
    QLabel *Title;
    QLabel *Sub_title;
    QWidget *widget_2;
    QLabel *label_2;
    QWidget *face_create;
    QWidget *widget_3;
    QStackedWidget *stackedWidget;
    QWidget *viewfinderPage;
    QGridLayout *gridLayout_5;
    QVideoWidget *viewfinder;
    QWidget *previewPage;
    QGridLayout *gridLayout_4;
    QLabel *image_preview;
    QPushButton *retry;
    QPushButton *Image_next;
    QLabel *Sub_title_4;
    QLabel *label_4;
    QLabel *Title_4;
    QPushButton *back_cam;
    QPushButton *Capture;
    QWidget *Signup;
    QLabel *label_3;
    QWidget *widget_signup;
    QStackedWidget *creation;
    QWidget *create;
    QLabel *Sub_title_2;
    QGroupBox *user_2;
    QLineEdit *name2;
    QGroupBox *emaill_field;
    QLineEdit *email;
    QPushButton *proceed_btn;
    QPushButton *SignIn_btn;
    QGroupBox *Password_2;
    QLineEdit *password2;
    QLabel *Title_2;
    QGroupBox *img_field;
    QLineEdit *img_name;
    QPushButton *face;
    QWidget *verification;
    QGroupBox *user_3;
    QLineEdit *verificationCodeInput;
    QPushButton *verify;
    QLabel *Sub_title_3;
    QLabel *Title_3;
    QPushButton *cancel_verif;
    QWidget *face_recognition;
    QPushButton *back_cam_2;
    QWidget *widget_4;
    QStackedWidget *stackedWidget_2;
    QWidget *view_face_page;
    QGridLayout *gridLayout_6;
    QVideoWidget *face_view;
    QPushButton *face_rec_back;
    QLabel *Title_5;
    QLabel *Sub_title_5;
    QLabel *label_5;
    QLabel *bg;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 720);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:grey;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Auth = new QStackedWidget(centralWidget);
        Auth->setObjectName(QString::fromUtf8("Auth"));
        Auth->setGeometry(QRect(120, 20, 1541, 751));
        Auth->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        Login = new QWidget();
        Login->setObjectName(QString::fromUtf8("Login"));
        user = new QGroupBox(Login);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(620, 210, 309, 45));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lexend Light")});
        user->setFont(font);
        user->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        user->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        user->setFlat(false);
        user->setCheckable(false);
        name1 = new QLineEdit(user);
        name1->setObjectName(QString::fromUtf8("name1"));
        name1->setEnabled(true);
        name1->setGeometry(QRect(10, 16, 261, 22));
        name1->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        SignUp_btn = new QPushButton(Login);
        SignUp_btn->setObjectName(QString::fromUtf8("SignUp_btn"));
        SignUp_btn->setGeometry(QRect(620, 420, 311, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lexend Light")});
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setStrikeOut(false);
        SignUp_btn->setFont(font1);
        SignUp_btn->setCursor(QCursor(Qt::PointingHandCursor));
        SignUp_btn->setStyleSheet(QString::fromUtf8("border-color: rgb(27, 160, 25);\n"
"color: rgb(27, 160, 25);\n"
"border-radius:10px;\n"
"border-width : 1.2px;\n"
"border-style:solid;"));
        SignUp_btn->setCheckable(false);
        SignUp_btn->setAutoRepeat(false);
        SignUp_btn->setAutoDefault(false);
        SignUp_btn->setFlat(false);
        Login_btn = new QPushButton(Login);
        Login_btn->setObjectName(QString::fromUtf8("Login_btn"));
        Login_btn->setGeometry(QRect(620, 370, 311, 41));
        Login_btn->setFont(font1);
        Login_btn->setCursor(QCursor(Qt::PointingHandCursor));
        Login_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 160, 25);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        Login_btn->setCheckable(false);
        Login_btn->setAutoRepeat(false);
        Login_btn->setAutoDefault(false);
        Login_btn->setFlat(false);
        Password = new QGroupBox(Login);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(620, 280, 309, 44));
        Password->setFont(font);
        Password->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        Password->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        Password->setFlat(false);
        Password->setCheckable(false);
        password1 = new QLineEdit(Password);
        password1->setObjectName(QString::fromUtf8("password1"));
        password1->setGeometry(QRect(10, 16, 265, 22));
        password1->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        password1->setEchoMode(QLineEdit::EchoMode::Password);
        Title = new QLabel(Login);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setEnabled(false);
        Title->setGeometry(QRect(620, 90, 311, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Lexend")});
        font2.setPointSize(24);
        font2.setBold(true);
        Title->setFont(font2);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(104, 104, 104);"));
        Title->setScaledContents(false);
        Sub_title = new QLabel(Login);
        Sub_title->setObjectName(QString::fromUtf8("Sub_title"));
        Sub_title->setEnabled(false);
        Sub_title->setGeometry(QRect(620, 130, 291, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lexend Light")});
        font3.setPointSize(10);
        Sub_title->setFont(font3);
        Sub_title->setCursor(QCursor(Qt::PointingHandCursor));
        Sub_title->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Sub_title->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: #A2A1A8"));
        Sub_title->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        widget_2 = new QWidget(Login);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(530, 50, 481, 521));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:20px;\n"
""));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 50, 451, 521));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-top-left-radius: 20px;    /* Round top-left corner */\n"
"    border-bottom-left-radius: 20px; /* Round bottom-left corner */\n"
"    border-top-right-radius: 0px;    /* Ensure top-right remains square */\n"
"    border-bottom-right-radius: 0px; /* Ensure bottom-right remains square */\n"
"	border:none;         /* Optional: Add a visible border */\n"
"}\n"
""));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/Cover.png")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2->setWordWrap(false);
        Auth->addWidget(Login);
        widget_2->raise();
        label_2->raise();
        user->raise();
        SignUp_btn->raise();
        Login_btn->raise();
        Password->raise();
        Title->raise();
        Sub_title->raise();
        face_create = new QWidget();
        face_create->setObjectName(QString::fromUtf8("face_create"));
        widget_3 = new QWidget(face_create);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(530, 50, 481, 521));
        widget_3->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:20px;\n"
""));
        stackedWidget = new QStackedWidget(widget_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(60, 100, 381, 231));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        stackedWidget->setPalette(palette);
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        viewfinderPage = new QWidget();
        viewfinderPage->setObjectName(QString::fromUtf8("viewfinderPage"));
        gridLayout_5 = new QGridLayout(viewfinderPage);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        viewfinder = new QVideoWidget(viewfinderPage);
        viewfinder->setObjectName(QString::fromUtf8("viewfinder"));
        viewfinder->setStyleSheet(QString::fromUtf8("border-radius:5px;"));

        gridLayout_5->addWidget(viewfinder, 0, 0, 1, 1);

        stackedWidget->addWidget(viewfinderPage);
        previewPage = new QWidget();
        previewPage->setObjectName(QString::fromUtf8("previewPage"));
        gridLayout_4 = new QGridLayout(previewPage);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        image_preview = new QLabel(previewPage);
        image_preview->setObjectName(QString::fromUtf8("image_preview"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(image_preview->sizePolicy().hasHeightForWidth());
        image_preview->setSizePolicy(sizePolicy1);
        image_preview->setStyleSheet(QString::fromUtf8(""));
        image_preview->setFrameShape(QFrame::Shape::Box);

        gridLayout_4->addWidget(image_preview, 0, 0, 1, 1);

        stackedWidget->addWidget(previewPage);
        retry = new QPushButton(widget_3);
        retry->setObjectName(QString::fromUtf8("retry"));
        retry->setGeometry(QRect(250, 350, 151, 41));
        retry->setFont(font1);
        retry->setCursor(QCursor(Qt::PointingHandCursor));
        retry->setStyleSheet(QString::fromUtf8("border-color: rgb(27, 160, 25);\n"
"color: rgb(27, 160, 25);\n"
"border-radius:10px;\n"
"border-width : 1.2px;\n"
"border-style:solid;"));
        retry->setCheckable(false);
        retry->setAutoRepeat(false);
        retry->setAutoDefault(false);
        retry->setFlat(false);
        Image_next = new QPushButton(widget_3);
        Image_next->setObjectName(QString::fromUtf8("Image_next"));
        Image_next->setGeometry(QRect(90, 400, 311, 41));
        Image_next->setFont(font1);
        Image_next->setCursor(QCursor(Qt::PointingHandCursor));
        Image_next->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 160, 25);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        Image_next->setCheckable(false);
        Image_next->setAutoRepeat(false);
        Image_next->setAutoDefault(false);
        Image_next->setFlat(false);
        Sub_title_4 = new QLabel(face_create);
        Sub_title_4->setObjectName(QString::fromUtf8("Sub_title_4"));
        Sub_title_4->setEnabled(false);
        Sub_title_4->setGeometry(QRect(620, 110, 291, 31));
        Sub_title_4->setFont(font3);
        Sub_title_4->setCursor(QCursor(Qt::PointingHandCursor));
        Sub_title_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Sub_title_4->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: #A2A1A8"));
        Sub_title_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_4 = new QLabel(face_create);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 50, 451, 521));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-top-left-radius: 20px;    /* Round top-left corner */\n"
"    border-bottom-left-radius: 20px; /* Round bottom-left corner */\n"
"    border-top-right-radius: 0px;    /* Ensure top-right remains square */\n"
"    border-bottom-right-radius: 0px; /* Ensure bottom-right remains square */\n"
"	border:none;         /* Optional: Add a visible border */\n"
"}\n"
""));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/Cover.png")));
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4->setWordWrap(false);
        Title_4 = new QLabel(face_create);
        Title_4->setObjectName(QString::fromUtf8("Title_4"));
        Title_4->setEnabled(false);
        Title_4->setGeometry(QRect(620, 80, 311, 31));
        Title_4->setFont(font2);
        Title_4->setStyleSheet(QString::fromUtf8("color: rgb(104, 104, 104);"));
        Title_4->setScaledContents(false);
        back_cam = new QPushButton(face_create);
        back_cam->setObjectName(QString::fromUtf8("back_cam"));
        back_cam->setGeometry(QRect(620, 500, 311, 41));
        back_cam->setFont(font1);
        back_cam->setCursor(QCursor(Qt::PointingHandCursor));
        back_cam->setStyleSheet(QString::fromUtf8("border-color: rgb(27, 160, 25);\n"
"color: rgb(27, 160, 25);\n"
"border-radius:10px;\n"
"border-width : 1.2px;\n"
"border-style:solid;"));
        back_cam->setCheckable(false);
        back_cam->setAutoRepeat(false);
        back_cam->setAutoDefault(false);
        back_cam->setFlat(false);
        Capture = new QPushButton(face_create);
        Capture->setObjectName(QString::fromUtf8("Capture"));
        Capture->setGeometry(QRect(620, 400, 151, 41));
        Capture->setFont(font1);
        Capture->setCursor(QCursor(Qt::PointingHandCursor));
        Capture->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 160, 25);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        Capture->setCheckable(false);
        Capture->setAutoRepeat(false);
        Capture->setAutoDefault(false);
        Capture->setFlat(false);
        Auth->addWidget(face_create);
        Signup = new QWidget();
        Signup->setObjectName(QString::fromUtf8("Signup"));
        label_3 = new QLabel(Signup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 50, 451, 521));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-top-left-radius: 20px;    /* Round top-left corner */\n"
"    border-bottom-left-radius: 20px; /* Round bottom-left corner */\n"
"    border-top-right-radius: 0px;    /* Ensure top-right remains square */\n"
"    border-bottom-right-radius: 0px; /* Ensure bottom-right remains square */\n"
"	border:none;         /* Optional: Add a visible border */\n"
"}\n"
""));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/Cover.png")));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3->setWordWrap(false);
        widget_signup = new QWidget(Signup);
        widget_signup->setObjectName(QString::fromUtf8("widget_signup"));
        widget_signup->setGeometry(QRect(520, 50, 491, 521));
        widget_signup->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:20px;\n"
""));
        creation = new QStackedWidget(widget_signup);
        creation->setObjectName(QString::fromUtf8("creation"));
        creation->setGeometry(QRect(20, -1, 461, 521));
        create = new QWidget();
        create->setObjectName(QString::fromUtf8("create"));
        Sub_title_2 = new QLabel(create);
        Sub_title_2->setObjectName(QString::fromUtf8("Sub_title_2"));
        Sub_title_2->setGeometry(QRect(80, 80, 291, 31));
        Sub_title_2->setFont(font3);
        Sub_title_2->setCursor(QCursor(Qt::PointingHandCursor));
        Sub_title_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Sub_title_2->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: #A2A1A8"));
        Sub_title_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        user_2 = new QGroupBox(create);
        user_2->setObjectName(QString::fromUtf8("user_2"));
        user_2->setGeometry(QRect(80, 130, 309, 45));
        user_2->setFont(font);
        user_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        user_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        user_2->setFlat(false);
        user_2->setCheckable(false);
        name2 = new QLineEdit(user_2);
        name2->setObjectName(QString::fromUtf8("name2"));
        name2->setEnabled(true);
        name2->setGeometry(QRect(10, 16, 261, 22));
        name2->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        emaill_field = new QGroupBox(create);
        emaill_field->setObjectName(QString::fromUtf8("emaill_field"));
        emaill_field->setGeometry(QRect(80, 252, 309, 44));
        emaill_field->setFont(font);
        emaill_field->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        emaill_field->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        emaill_field->setFlat(false);
        emaill_field->setCheckable(false);
        email = new QLineEdit(emaill_field);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(10, 16, 265, 22));
        email->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        email->setEchoMode(QLineEdit::EchoMode::Normal);
        proceed_btn = new QPushButton(create);
        proceed_btn->setObjectName(QString::fromUtf8("proceed_btn"));
        proceed_btn->setGeometry(QRect(80, 370, 311, 41));
        proceed_btn->setFont(font1);
        proceed_btn->setCursor(QCursor(Qt::PointingHandCursor));
        proceed_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 160, 25);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        proceed_btn->setCheckable(false);
        proceed_btn->setAutoRepeat(false);
        proceed_btn->setAutoDefault(false);
        proceed_btn->setFlat(false);
        SignIn_btn = new QPushButton(create);
        SignIn_btn->setObjectName(QString::fromUtf8("SignIn_btn"));
        SignIn_btn->setGeometry(QRect(80, 420, 311, 41));
        SignIn_btn->setFont(font1);
        SignIn_btn->setCursor(QCursor(Qt::PointingHandCursor));
        SignIn_btn->setStyleSheet(QString::fromUtf8("border-color: rgb(27, 160, 25);\n"
"color: rgb(27, 160, 25);\n"
"border-radius:10px;\n"
"border-width : 1.2px;\n"
"border-style:solid;"));
        SignIn_btn->setCheckable(false);
        SignIn_btn->setAutoRepeat(false);
        SignIn_btn->setAutoDefault(false);
        SignIn_btn->setFlat(false);
        Password_2 = new QGroupBox(create);
        Password_2->setObjectName(QString::fromUtf8("Password_2"));
        Password_2->setGeometry(QRect(80, 190, 309, 44));
        Password_2->setFont(font);
        Password_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        Password_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        Password_2->setFlat(false);
        Password_2->setCheckable(false);
        password2 = new QLineEdit(Password_2);
        password2->setObjectName(QString::fromUtf8("password2"));
        password2->setGeometry(QRect(10, 16, 265, 22));
        password2->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        password2->setEchoMode(QLineEdit::EchoMode::Password);
        Title_2 = new QLabel(create);
        Title_2->setObjectName(QString::fromUtf8("Title_2"));
        Title_2->setGeometry(QRect(80, 40, 311, 31));
        Title_2->setFont(font2);
        Title_2->setStyleSheet(QString::fromUtf8("color: rgb(104, 104, 104);"));
        img_field = new QGroupBox(create);
        img_field->setObjectName(QString::fromUtf8("img_field"));
        img_field->setGeometry(QRect(80, 310, 311, 44));
        img_field->setFont(font);
        img_field->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        img_field->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        img_field->setFlat(false);
        img_field->setCheckable(false);
        img_name = new QLineEdit(img_field);
        img_name->setObjectName(QString::fromUtf8("img_name"));
        img_name->setGeometry(QRect(10, 16, 181, 22));
        img_name->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        img_name->setEchoMode(QLineEdit::EchoMode::Normal);
        face = new QPushButton(create);
        face->setObjectName(QString::fromUtf8("face"));
        face->setGeometry(QRect(80, 310, 311, 41));
        face->setFont(font1);
        face->setCursor(QCursor(Qt::PointingHandCursor));
        face->setStyleSheet(QString::fromUtf8("border-color:transparent;\n"
"border-radius:10px;\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"background-color:transparent;"));
        face->setCheckable(false);
        face->setAutoRepeat(false);
        face->setAutoDefault(false);
        face->setFlat(false);
        creation->addWidget(create);
        verification = new QWidget();
        verification->setObjectName(QString::fromUtf8("verification"));
        user_3 = new QGroupBox(verification);
        user_3->setObjectName(QString::fromUtf8("user_3"));
        user_3->setGeometry(QRect(80, 150, 309, 45));
        user_3->setFont(font);
        user_3->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 1.2px;\n"
"border-style:solid;\n"
"color: rgb(27, 160, 25);\n"
""));
        user_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        user_3->setFlat(false);
        user_3->setCheckable(false);
        verificationCodeInput = new QLineEdit(user_3);
        verificationCodeInput->setObjectName(QString::fromUtf8("verificationCodeInput"));
        verificationCodeInput->setEnabled(true);
        verificationCodeInput->setGeometry(QRect(10, 16, 261, 22));
        verificationCodeInput->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-color: rgb(27, 160, 25);\n"
"border-width : 0x;\n"
"color:grey;"));
        verify = new QPushButton(verification);
        verify->setObjectName(QString::fromUtf8("verify"));
        verify->setGeometry(QRect(80, 250, 311, 41));
        verify->setFont(font1);
        verify->setCursor(QCursor(Qt::PointingHandCursor));
        verify->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 160, 25);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        verify->setCheckable(false);
        verify->setAutoRepeat(false);
        verify->setAutoDefault(false);
        verify->setFlat(false);
        Sub_title_3 = new QLabel(verification);
        Sub_title_3->setObjectName(QString::fromUtf8("Sub_title_3"));
        Sub_title_3->setGeometry(QRect(80, 90, 291, 31));
        Sub_title_3->setFont(font3);
        Sub_title_3->setCursor(QCursor(Qt::PointingHandCursor));
        Sub_title_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Sub_title_3->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: #A2A1A8"));
        Sub_title_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        Title_3 = new QLabel(verification);
        Title_3->setObjectName(QString::fromUtf8("Title_3"));
        Title_3->setGeometry(QRect(80, 50, 361, 31));
        Title_3->setFont(font2);
        Title_3->setStyleSheet(QString::fromUtf8("color: rgb(104, 104, 104);"));
        cancel_verif = new QPushButton(verification);
        cancel_verif->setObjectName(QString::fromUtf8("cancel_verif"));
        cancel_verif->setGeometry(QRect(80, 300, 311, 41));
        cancel_verif->setFont(font1);
        cancel_verif->setCursor(QCursor(Qt::PointingHandCursor));
        cancel_verif->setStyleSheet(QString::fromUtf8("border-color: rgb(27, 160, 25);\n"
"color: rgb(27, 160, 25);\n"
"border-radius:10px;\n"
"border-width : 1.2px;\n"
"border-style:solid;"));
        cancel_verif->setCheckable(false);
        cancel_verif->setAutoRepeat(false);
        cancel_verif->setAutoDefault(false);
        cancel_verif->setFlat(false);
        creation->addWidget(verification);
        Auth->addWidget(Signup);
        widget_signup->raise();
        label_3->raise();
        face_recognition = new QWidget();
        face_recognition->setObjectName(QString::fromUtf8("face_recognition"));
        back_cam_2 = new QPushButton(face_recognition);
        back_cam_2->setObjectName(QString::fromUtf8("back_cam_2"));
        back_cam_2->setGeometry(QRect(620, 500, 311, 41));
        back_cam_2->setFont(font1);
        back_cam_2->setCursor(QCursor(Qt::PointingHandCursor));
        back_cam_2->setStyleSheet(QString::fromUtf8("border-color: rgb(27, 160, 25);\n"
"color: rgb(27, 160, 25);\n"
"border-radius:10px;\n"
"border-width : 1.2px;\n"
"border-style:solid;"));
        back_cam_2->setCheckable(false);
        back_cam_2->setAutoRepeat(false);
        back_cam_2->setAutoDefault(false);
        back_cam_2->setFlat(false);
        widget_4 = new QWidget(face_recognition);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(530, 50, 481, 521));
        widget_4->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:20px;\n"
""));
        stackedWidget_2 = new QStackedWidget(widget_4);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(60, 100, 381, 231));
        sizePolicy.setHeightForWidth(stackedWidget_2->sizePolicy().hasHeightForWidth());
        stackedWidget_2->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        stackedWidget_2->setPalette(palette1);
        stackedWidget_2->setStyleSheet(QString::fromUtf8(""));
        view_face_page = new QWidget();
        view_face_page->setObjectName(QString::fromUtf8("view_face_page"));
        gridLayout_6 = new QGridLayout(view_face_page);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        face_view = new QVideoWidget(view_face_page);
        face_view->setObjectName(QString::fromUtf8("face_view"));
        face_view->setStyleSheet(QString::fromUtf8("border-radius:5px;"));

        gridLayout_6->addWidget(face_view, 0, 0, 1, 1);

        stackedWidget_2->addWidget(view_face_page);
        face_rec_back = new QPushButton(widget_4);
        face_rec_back->setObjectName(QString::fromUtf8("face_rec_back"));
        face_rec_back->setGeometry(QRect(90, 370, 311, 41));
        face_rec_back->setFont(font1);
        face_rec_back->setCursor(QCursor(Qt::PointingHandCursor));
        face_rec_back->setStyleSheet(QString::fromUtf8("border-color: rgb(27, 160, 25);\n"
"color: rgb(27, 160, 25);\n"
"border-radius:10px;\n"
"border-width : 1.2px;\n"
"border-style:solid;"));
        face_rec_back->setCheckable(false);
        face_rec_back->setAutoRepeat(false);
        face_rec_back->setAutoDefault(false);
        face_rec_back->setFlat(false);
        Title_5 = new QLabel(face_recognition);
        Title_5->setObjectName(QString::fromUtf8("Title_5"));
        Title_5->setEnabled(false);
        Title_5->setGeometry(QRect(620, 80, 311, 31));
        Title_5->setFont(font2);
        Title_5->setStyleSheet(QString::fromUtf8("color: rgb(104, 104, 104);"));
        Title_5->setScaledContents(false);
        Sub_title_5 = new QLabel(face_recognition);
        Sub_title_5->setObjectName(QString::fromUtf8("Sub_title_5"));
        Sub_title_5->setEnabled(false);
        Sub_title_5->setGeometry(QRect(620, 110, 291, 31));
        Sub_title_5->setFont(font3);
        Sub_title_5->setCursor(QCursor(Qt::PointingHandCursor));
        Sub_title_5->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Sub_title_5->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: #A2A1A8"));
        Sub_title_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_5 = new QLabel(face_recognition);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 50, 451, 521));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-top-left-radius: 20px;    /* Round top-left corner */\n"
"    border-bottom-left-radius: 20px; /* Round bottom-left corner */\n"
"    border-top-right-radius: 0px;    /* Ensure top-right remains square */\n"
"    border-bottom-right-radius: 0px; /* Ensure bottom-right remains square */\n"
"	border:none;         /* Optional: Add a visible border */\n"
"}\n"
""));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/Cover.png")));
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5->setWordWrap(false);
        Auth->addWidget(face_recognition);
        bg = new QLabel(centralWidget);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(-30, -180, 1451, 1081));
        bg->setPixmap(QPixmap(QString::fromUtf8(":/images/bg.jpg")));
        bg->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        bg->raise();
        Auth->raise();

        retranslateUi(MainWindow);

        Auth->setCurrentIndex(0);
        SignUp_btn->setDefault(false);
        Login_btn->setDefault(false);
        stackedWidget->setCurrentIndex(0);
        retry->setDefault(false);
        Image_next->setDefault(false);
        back_cam->setDefault(false);
        Capture->setDefault(false);
        creation->setCurrentIndex(0);
        proceed_btn->setDefault(false);
        SignIn_btn->setDefault(false);
        face->setDefault(false);
        verify->setDefault(false);
        cancel_verif->setDefault(false);
        back_cam_2->setDefault(false);
        stackedWidget_2->setCurrentIndex(0);
        face_rec_back->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        user->setTitle(QCoreApplication::translate("MainWindow", "Name", nullptr));
        name1->setText(QString());
        SignUp_btn->setText(QCoreApplication::translate("MainWindow", "No account ? signup", nullptr));
        Login_btn->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Password->setTitle(QCoreApplication::translate("MainWindow", "Password", nullptr));
        password1->setText(QString());
        Title->setText(QCoreApplication::translate("MainWindow", "Welcome Back!", nullptr));
        Sub_title->setText(QCoreApplication::translate("MainWindow", "Please login here", nullptr));
        label_2->setText(QString());
        image_preview->setText(QString());
        retry->setText(QCoreApplication::translate("MainWindow", "Retry", nullptr));
        Image_next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        Sub_title_4->setText(QCoreApplication::translate("MainWindow", "Please capture your image", nullptr));
        label_4->setText(QString());
        Title_4->setText(QCoreApplication::translate("MainWindow", "Dont move !", nullptr));
        back_cam->setText(QCoreApplication::translate("MainWindow", "Go Back", nullptr));
        Capture->setText(QCoreApplication::translate("MainWindow", "Capture", nullptr));
        label_3->setText(QString());
        Sub_title_2->setText(QCoreApplication::translate("MainWindow", "Create your account below", nullptr));
        user_2->setTitle(QCoreApplication::translate("MainWindow", "Name", nullptr));
        name2->setText(QString());
        emaill_field->setTitle(QCoreApplication::translate("MainWindow", "Email", nullptr));
        email->setText(QString());
        proceed_btn->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        SignIn_btn->setText(QCoreApplication::translate("MainWindow", "You have an account ? Signin", nullptr));
        Password_2->setTitle(QCoreApplication::translate("MainWindow", "Password", nullptr));
        password2->setText(QString());
        Title_2->setText(QCoreApplication::translate("MainWindow", "Join Us!", nullptr));
        img_field->setTitle(QCoreApplication::translate("MainWindow", "Image ( Optional )", nullptr));
        img_name->setText(QString());
        face->setText(QString());
        user_3->setTitle(QCoreApplication::translate("MainWindow", "Name", nullptr));
        verificationCodeInput->setText(QString());
        verificationCodeInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter SMS Code", nullptr));
        verify->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        Sub_title_3->setText(QCoreApplication::translate("MainWindow", "We\342\200\231ve sent a 6-digit code to your phone number. Enter it below to continue", nullptr));
        Title_3->setText(QCoreApplication::translate("MainWindow", "Account Verification", nullptr));
        cancel_verif->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        back_cam_2->setText(QCoreApplication::translate("MainWindow", "Go Back", nullptr));
        face_rec_back->setText(QCoreApplication::translate("MainWindow", "Go Back", nullptr));
        Title_5->setText(QCoreApplication::translate("MainWindow", "Please wait !", nullptr));
        Sub_title_5->setText(QCoreApplication::translate("MainWindow", "Stay still", nullptr));
        label_5->setText(QString());
        bg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
