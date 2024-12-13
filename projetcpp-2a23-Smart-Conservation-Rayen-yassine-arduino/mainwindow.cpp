#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "management.h"
#include <QCameraDevice>
#include <QDir>
#include <QDebug>
#include <QBuffer>
#include <QTimer>
#include <QImage>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QDateTime>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QRegularExpression>  // Include this for QRegularExpression

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("CanniTech");
    // arduino
    int ret = A.connect_arduino();
    // Connect to the Arduino
    switch(ret) {
    case(0):
        qDebug() << "Arduino is available and connected to : " << A.getArduinoPortName();
        break;
    case(1):
        qDebug() << "Arduino is available but not connected to : " << A.getArduinoPortName();
        break;
    case(-1):
        qDebug() << "Arduino is not available";
    }

    QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));

    QRegularExpression re("[A-Za-z]+");
    QRegularExpressionValidator *nameValidator = new QRegularExpressionValidator(re, this);

    ui->name1->setValidator(nameValidator);
    ui->name2->setValidator(nameValidator);
    ui->Auth->setCurrentIndex(0); // Sign-in page
}


MainWindow::~MainWindow() {
    delete ui;
}

/*-------------LOGIN-------------*/
void MainWindow::on_Login_btn_clicked() {
    QString username = ui->name1->text();
    QString password = ui->password1->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM admin WHERE name = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        if (query.next()) {
            qDebug() << "Login successful!";
            management *managementWindow = new management();
            managementWindow->show();
            this->hide();
        } else {
            qDebug() << "Login failed: Invalid username or password.";
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }
}

void MainWindow::on_SignUp_btn_clicked() {
    ui->Auth->setCurrentIndex(2);
    ui->creation->setCurrentIndex(0);
    ui->img_name->setText("Image not added");

}

/*-------------SIGNUP-------------*/
void MainWindow::on_SignIn_btn_clicked() {
    ui->name2->clear();
    ui->password2->clear();
    ui->email->clear();
    ui->Auth->setCurrentIndex(0);
    m_capturedImage = QImage();
}

void MainWindow::on_proceed_btn_clicked() {
    QString name = ui->name2->text();
    QString password = ui->password2->text();
    QString email = ui->email->text();

    if (name.isEmpty() || password.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM admin WHERE email = :email");
    checkQuery.bindValue(":email", email);

    if (checkQuery.exec()) {
        checkQuery.next();

        if (checkQuery.value(0).toInt() > 0) {
            qDebug() << "User already exists!";
            QMessageBox::warning(this, "Registration Error", "User already exists!");
            return;
        } else {
            tempVerificationCode = generateVerificationCode();
            sendEmail(email, tempVerificationCode);
            ui->creation->setCurrentIndex(1);
        }
    } else {
        qDebug() << "Failed to check if user exists:" << checkQuery.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to check for existing user.");
    }
}

QString MainWindow::generateVerificationCode() {
    int verificationCode = QRandomGenerator::global()->bounded(100000, 1000000);
    qDebug()<<verificationCode;
    return QString::number(verificationCode);
}

void MainWindow::sendEmail(const QString &email, const QString &code) {
    QUrl url("https://api.postmarkapp.com/email");
    QNetworkRequest request(url);
    request.setRawHeader("X-Postmark-Server-Token", "53de2487-404b-47c2-bc47-768c044a5ed0");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
       json["From"] = "mohamedrayen.rebai@esprit.tn";
       json["To"] = email;
       json["Subject"] = "Verification Code";
       json["TextBody"] = "Your verification code is: " + code;
       json["HtmlBody"] = "<strong>Your verification code is:</strong> " + code;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onSendEmailSuccess);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onSendEmailFailed);

    manager->post(request, QJsonDocument(json).toJson());
}

void MainWindow::onSendEmailSuccess(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Email sent successfully!";
        QMessageBox::information(this, "Email Sent", "A verification code has been sent to your email.");
    } else {
        qDebug() << "Email sending failed:" << reply->errorString();
    }
    reply->deleteLater();
}

void MainWindow::onSendEmailFailed(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Failed to send email:" << reply->errorString();
        QMessageBox::warning(this, "Email Failed", "Failed to send email. Please try again.");
    }
    reply->deleteLater();
}

void MainWindow::on_verify_clicked() {
    QString name = ui->name2->text();
    QString password = ui->password2->text();
    QString email = ui->email->text();
    QString enteredCode = ui->verificationCodeInput->text();

    if (enteredCode != tempVerificationCode) {
        QMessageBox::warning(this, "Verification Error", "Incorrect verification code. Please try again.");
        return;
    }

    QByteArray imageData;
    QBuffer buffer(&imageData);
    buffer.open(QIODevice::WriteOnly);
    bool saved = m_capturedImage.save(&buffer, "PNG");
    if (!saved) {
        qDebug() << "Failed to save image to buffer.";
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO admin (name, password, email, image) VALUES (:name, :password, :email, :image)");
    insertQuery.bindValue(":name", name);
    insertQuery.bindValue(":password", password);
    insertQuery.bindValue(":email", email);
    insertQuery.bindValue(":image", imageData);

    if (insertQuery.exec()) {
        qDebug() << "User registered successfully!";
        QMessageBox::information(this, "Success", "User registered successfully.");
        ui->name2->clear();
        ui->password2->clear();
        ui->email->clear();
        ui->verificationCodeInput->clear();
        ui->img_name->setText("Image not added");
        ui->Auth->setCurrentIndex(0);
    } else {
        qDebug() << "Registration failed:" << insertQuery.lastError().text();
        QMessageBox::critical(this, "Registration Failed", "User registration failed.");
    }
}


void MainWindow::on_cancel_verif_clicked()
{
    ui->creation->setCurrentIndex(0);
}

/*-----------------CAMERA-----------------*/

void MainWindow::setCamera1(const QCameraDevice &cameraDevice) {
    if (cameraDevice.isNull()) {
            qDebug() << "Camera device is null!";
            return; // Prevent further processing
        }

        if (m_camera) {
            m_camera->stop();
        }

        m_camera.reset(new QCamera(cameraDevice));
        if (!m_camera) {
            qDebug() << "Failed to create camera!";
            return;
        }
        m_captureSession.setCamera(m_camera.data());
        m_captureSession.setImageCapture(m_imageCapture);
        m_captureSession.setVideoOutput(ui->viewfinder);
        m_camera->start();

        if (!m_camera->isActive()) {
                qDebug() << "Camera failed to start!";
            }
    }



void MainWindow::on_back_clicked()
{
    ui->Auth->setCurrentIndex(0);
    m_camera->stop();
}


void MainWindow::on_Capture_clicked() {
    m_capturedImage = QImage();
    if (m_imageCapture) {
        connect(m_imageCapture, &QImageCapture::imageCaptured, this, [&](int /*id*/, const QImage &image) {
            // Capture and display the image
            m_capturedImage = image;
            ui->image_preview->setPixmap(QPixmap::fromImage(m_capturedImage));
            m_camera->stop();
            ui->img_name->setText("Image Added");

            // Convert image to QByteArray
            QByteArray byteArray;
            QBuffer buffer(&byteArray);
            buffer.open(QIODevice::WriteOnly);
            m_capturedImage.save(&buffer, "JPG");

            // Encode the byte array to base64
            QString encodedImage = byteArray.toBase64();

            // Open face.txt for writing and save the encoded image data
            QFile file("face.txt");
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                // Write the base64-encoded image string to the file
                out << encodedImage;
                file.close();
                qDebug() << "Image data saved to face.txt.";
            } else {
                qDebug() << "Failed to open face.txt for writing.";
            }
        });
        m_imageCapture->capture();
    } else {
        ui->img_name->setText("Image not added");
    }
}





void MainWindow::on_face_clicked()
{
    setCamera1(QMediaDevices::defaultVideoInput());
    if (m_camera) {
        m_camera->stop();
    }
    m_capturedImage = QImage();
    ui->Auth->setCurrentIndex(1);
    m_camera->start();
}

void MainWindow::on_Image_next_clicked()
{
    ui->Auth->setCurrentIndex(2);
    m_camera->stop();
}

void MainWindow::on_retry_clicked()
{
    ui->img_name->setText("Image not added");
    m_capturedImage = QImage();
    ui->image_preview->clear();

    if (m_camera) {
        m_camera->stop();
    }
    if (m_imageCapture) {
        m_camera->start();
}
}

void MainWindow::on_back_cam_clicked()
{
    ui->Auth->setCurrentIndex(2);
    m_capturedImage = QImage();
    ui->image_preview->clear();
    m_camera->stop();
    ui->img_name->setText("Image not added");
}

/************FACIAL RECOGNITION************/
void MainWindow::setCamera2(const QCameraDevice &cameraDevice)
{
    m_cameraFaceRecognition.reset(new QCamera(cameraDevice));

    if (m_cameraFaceRecognition) {
        m_captureSession.setVideoOutput(ui->face_view  );
        m_imageCapture = new QImageCapture;
        m_captureSession.setCamera(m_cameraFaceRecognition.data());
        m_captureSession.setImageCapture(m_imageCapture);
    } else {
        qDebug() << "Failed to initialize camera.";
    }
}



void MainWindow::on_go_to_face_recog_clicked()
{
            if (m_cameraFaceRecognition) {
                m_cameraFaceRecognition->stop();
            }
            // Set up the second camera for face recognition
            setCamera2(QMediaDevices::defaultVideoInput());
            m_cameraFaceRecognition->start();
            ui->Auth->setCurrentIndex(3);
}

void MainWindow::on_face_rec_back_clicked()
{
          ui->Auth->setCurrentIndex(0);
           m_cameraFaceRecognition->stop();
}
/*--------------ARDUINO------------*/

void MainWindow::update_label()
{
    // Ensure the arduino object is initialized and connected
    if (!A.getserial()->isOpen()) {
        qDebug() << "Arduino is not connected!";
        return;  // Exit if Arduino is not connected
    }

    // Read data from the Arduino (this is a QByteArray now)
    QByteArray data = A.read_from_arduino();  // Keeps QByteArray type
    if (data.isEmpty()) {
        qDebug() << "No data received from Arduino.";
        return;  // Exit if no data is received
    }

    // Convert QByteArray to QString
    QString rfidTag = QString::fromUtf8(data).trimmed(); // Convert QByteArray to QString
    rfidTag = rfidTag.replace("\r\n", "");  // Remove newlines or carriage returns
    rfidTag = rfidTag.toUpper();  // Convert to uppercase if needed
    qDebug() << "RFID Tag Received: " << rfidTag;

    // Check if the RFID UID exists in the EMPLOYEE table
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEE WHERE RFID_UID = :rfid");
    query.bindValue(":rfid", rfidTag);

    if (query.exec() && query.next()) {
        QString employeeId = query.value("EMPLOYEE_ID").toString();
        qDebug() << "Employee found with ID: " << employeeId;

        // Insert check-in entry into TABLEH
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO PRESENCE (EMPLOYEEID, CHECK_IN, CHECK_OUT, WORKING_HOURS) "
                            "VALUES (:id, :checkin, NULL, 0)");
        insertQuery.bindValue(":id", employeeId);
        insertQuery.bindValue(":checkin", QDateTime::currentDateTime());

        if (insertQuery.exec()) {
            qDebug() << "Check-in successful!";
        } else {
            qDebug() << "Failed to insert CHECK-IN:" << insertQuery.lastError().text();
        }
    } else {
        qDebug() << "RFID UID not found in the EMPLOYEE table.";
    }
}


/*void MainWindow::update_label()
{
    // Ensure the arduino object is initialized and connected
    if (!A.getserial()->isOpen()) {
        qDebug() << "Arduino is not connected!";
        return;  // Exit if Arduino is not connected
    }

    // Read data from the Arduino (this is a QByteArray now)
    QByteArray data = A.read_from_arduino();  // Keeps QByteArray type
    if (data.isEmpty()) {
        qDebug() << "No data received from Arduino.";
        return;  // Exit if no data is received
    }

    // Convert QByteArray to QString
    QString rfidTag = QString::fromUtf8(data).trimmed(); // Convert QByteArray to QString
    rfidTag = rfidTag.replace("\r\n", "");  // Remove newlines or carriage returns
    rfidTag = rfidTag.toUpper();  // Convert to uppercase if needed
    qDebug() << "RFID Tag Received: " << rfidTag;

    // Check if the RFID UID exists in the EMPLOYEE table
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEE WHERE RFID_UID = :rfid");
    query.bindValue(":rfid", rfidTag);

    if (query.exec() && query.next()) {
        QString employeeId = query.value("EMPLOYEE_ID").toString();
        qDebug() << "Employee found with ID: " << employeeId;

        // Check if the employee has any existing check-in/out records
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM TableH WHERE EMPLOYEEID = :id AND CHECK_OUT IS NULL");
        checkQuery.bindValue(":id", employeeId);

        bool isCheckIn = false; // Initially true for first scan, false for second, etc.

        if (checkQuery.exec() && checkQuery.next()) {
            // Employee has already checked in, so this must be a check-out
            isCheckIn = false;
        } else {
            // No previous check-in, so this must be a check-in
            isCheckIn = true;
        }

        // Insert check-in or check-out entry
        QSqlQuery insertQuery;
        if (isCheckIn) {
            insertQuery.prepare("INSERT INTO TableH (EMPLOYEEID, CHECK_IN, CHECK_OUT, WORKING_HOURS) "
                                "VALUES (:id, :checkin, NULL, 0)");
            insertQuery.bindValue(":id", employeeId);
            insertQuery.bindValue(":checkin", QDateTime::currentDateTime());

            qDebug() << "Executing check-in query: " << insertQuery.lastQuery();  // Debugging query

            if (insertQuery.exec()) {
                qDebug() << "Check-in successful!";
            } else {
                qDebug() << "Failed to insert CHECK-IN:" << insertQuery.lastError().text();
            }
        } else {
            // Check-out logic: calculate working hours
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE TableH SET CHECK_OUT = :checkout, "
                                "WORKING_HOURS = :workingHours WHERE EMPLOYEEID = :id AND CHECK_OUT IS NULL");
            updateQuery.bindValue(":id", employeeId);
            updateQuery.bindValue(":checkout", QDateTime::currentDateTime());

            // Calculate working hours
            QDateTime checkInTime = QDateTime::fromString(checkQuery.value("CHECK_IN").toString(), Qt::ISODate);
            qint64 workingHours = checkInTime.msecsTo(QDateTime::currentDateTime()) / 1000 / 3600;  // Convert ms to hours
            updateQuery.bindValue(":workingHours", workingHours);

            qDebug() << "Executing check-out query: " << updateQuery.lastQuery();  // Debugging query

            if (updateQuery.exec()) {
                qDebug() << "Check-out successful!";
            } else {
                qDebug() << "Failed to insert CHECK-OUT:" << updateQuery.lastError().text();
            }
        }
    } else {
        qDebug() << "RFID UID not found in the EMPLOYEE table.";
    }
}

void MainWindow::update_check_out(QString employeeId, QDateTime checkoutTime, double workingHours)
{
    // Log the values for debugging purposes
    qDebug() << "Employee ID:" << employeeId;
    qDebug() << "Checkout Time:" << checkoutTime;
    qDebug() << "Working Hours:" << workingHours;

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("UPDATE TableH SET CHECK_OUT = :checkout, WORKING_HOURS = :workingHours WHERE EMPLOYEEID = :id AND CHECK_OUT IS NULL");

    // Bind values to the query
    query.bindValue(":checkout", checkoutTime);
    query.bindValue(":workingHours", workingHours);
    query.bindValue(":id", employeeId);

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError();
        qDebug() << "SQL query:" << query.lastQuery();
    } else {
        qDebug() << "Check-out recorded successfully.";
    }
}
*/
