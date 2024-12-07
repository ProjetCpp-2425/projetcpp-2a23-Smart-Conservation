#include "email.h"
#include "ui_email.h"
#include "client.h"
#include "mainwindow.h"
#include "management.h"

email::email(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::email)
{
    ui->setupUi(this);
    connect(ui->send, &QPushButton::clicked, this, &email::on_send_clicked);
    connect(ui->cancel, &QPushButton::clicked, this, &email::on_cancel_clicked);
}

email::~email()
{
    delete ui;
}

void email::on_send_clicked()
{
    QString from = ui->fromLineEdit->text();
    QString to = ui->toLineEdit->text();
    QString subject = ui->subjectLineEdit->text();
    QString message = ui->messageTextEdit->toPlainText();

    // Send the email
    SmtpClient smtpClient;
    if (smtpClient.sendEmail(from, to, subject, message)) {
        QMessageBox::information(this, "Email Sent", "Your email has been sent successfully!");
    } else {
        QMessageBox::warning(this, "Email Failed", "Failed to send the email. Please try again.");
    }
}


void email::on_cancel_clicked()
{
    this->close();
}

