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

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

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

