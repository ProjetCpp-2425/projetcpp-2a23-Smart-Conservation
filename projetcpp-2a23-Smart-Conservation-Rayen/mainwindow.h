#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QIntValidator>
#include <QSqlQuery>
#include <QSqlError>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QWidget>
#include <QVideoWidget>
#include <QCamera>
#include <QImageCapture>
#include <QMediaCaptureSession>
#include <QScopedPointer>
#include <QMediaDevices>
#include <QBuffer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Login_btn_clicked();
    //void on_SignUp_btn_clicked();
   // void on_SignIn_btn_clicked();
    //void on_proceed_btn_clicked();
    //void on_verify_clicked();
    //void on_cancel_verif_clicked();
    //CAMERA


private:
    Ui::MainWindow *ui;
    /*QString tempVerificationCode;
    void sendEmail(const QString &email, const QString &code);
    QString generateVerificationCode();
    void onSendEmailSuccess(QNetworkReply *reply);
    void onSendEmailFailed(QNetworkReply *reply);
    //CAMERA
    QMediaCaptureSession m_captureSession; // Media capture session
    QScopedPointer<QCamera> m_camera; // Scoped pointer for camera
    QScopedPointer<QCamera> m_cameraFaceRecognition; // Camera for facial recognition
    QImageCapture *m_imageCapture; // Pointer to image capture
    QVideoWidget *videoWidget; // Pointer to the video widget
    QImage m_capturedImage; // Add this line
*/
private slots:
    /*void setCamera1(const QCameraDevice &cameraDevice);
    void setCamera2(const QCameraDevice &cameraDevice);
    void on_Capture_clicked();
    void on_face_clicked();
    void on_back_clicked();
    void on_Image_next_clicked();
    void on_retry_clicked();
    void on_back_cam_clicked();
    void on_go_to_face_recog_clicked();
    void on_face_rec_back_clicked();*/
};

#endif // MAINWINDOW_H
