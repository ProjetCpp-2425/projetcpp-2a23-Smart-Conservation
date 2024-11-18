#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableView>
#include <QDesktopServices>
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QInputDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include "client.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->StackedWidget->setCurrentWidget(ui->principale);
    ui->tableView->setModel(cl.afficher());

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::on_add_clicked);
    connect(ui->annuler, &QPushButton::clicked, this, &MainWindow::on_annuler_clicked);
    connect(ui->sup, &QPushButton::clicked, this, &MainWindow::on_sup_clicked);
    connect(ui->ajout_cl_2, &QPushButton::clicked, this, &MainWindow::on_ajout_cl_2_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);
    connect(ui->trier, &QPushButton::clicked, this, &MainWindow::on_trier_clicked);
    //stat all clients
    ui->cb->setText(cl.count());

    //mail
    QPushButton *openEmailDialogButton = new QPushButton("Send Email", this);
    openEmailDialogButton->setGeometry(50, 50, 200, 50);  // Position the button
    connect(openEmailDialogButton, &QPushButton::clicked, this, &MainWindow::on_send_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->ajout);
}

void MainWindow::on_annuler_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->principale);
}

void MainWindow::on_sup_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->suppression);
}

void MainWindow::on_cancel_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->principale);
}

void MainWindow::on_update_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->modif);

}

//search for the update and cancel

void MainWindow::on_ajout_cl_2_clicked()
{
    int id = ui->search_2->text().toInt();

    bool test = cl.search(id);
    if(test)
    {
        //yhezna el stacked whidget ou5ra
        ui->cb->setText(cl.count());

        ui->StackedWidget->setCurrentWidget(ui->update_if);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Try an other Id"),
                    QObject::tr("ERROR 404.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

}
//modification des information
void MainWindow::on_update_2_clicked()
{
    int tot_ord = ui->tot_2->text().toInt();
    int id = ui->search_2->text().toInt();
    QString adresse = ui->adresse_2->text();
    QString name = ui->name_2->text();
    QString email = ui->mail_2->text();
    int phone = ui->phone_2->text().toInt();


    bool test = cl.update(id,name,tot_ord,adresse,email,phone);
    if(test)
    {
        ui->cb->setText(cl.count());

        ui->StackedWidget->setCurrentWidget(ui->principale);
        ui->tableView->setModel(cl.afficher());
        QMessageBox::information(nullptr, QObject::tr("Update"),
                    QObject::tr("Updated successfullly.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Won't be Updated"),
                    QObject::tr("ERROR 404.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void MainWindow::on_cancl_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->principale);
}

void MainWindow::on_annuler_2_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->principale);
}

//supprission un element du la base du donne

void MainWindow::on_delete_2_clicked()
{

    int id = ui->id_sup->text().toInt();

    bool test = cl.supprimer(id);
    if(test)
    {
        ui->cb->setText(cl.count());

        ui->StackedWidget->setCurrentWidget(ui->principale);
        ui->tableView->setModel(cl.afficher());
        QMessageBox::information(nullptr, QObject::tr("Delete"),
                    QObject::tr("The item is Deleted successfullly.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Won't be Deleted"),
                    QObject::tr("ERROR 404.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_ajout_cl_clicked()
{
    int tot_ord = ui->tot->text().toInt();
    QString adresse = ui->adresse->text();
    int id = ui->id->text().toInt();
    QString name = ui->name->text();
    QString email = ui->mail->text();
    int phone = ui->phone->text().toInt();
    client c(id, name, phone, email, adresse, tot_ord);
    bool test=c.ajouter();

    if(test)
    {
        ui->cb->setText(cl.count());

        ui->StackedWidget->setCurrentWidget(ui->principale);
        ui->tableView->setModel(cl.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout done"),
                    QObject::tr("Client Added successfull.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Won't be added"),
                    QObject::tr("ERROR 404.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}
//ki ta5tar haja fel table view yfasa5ha

void MainWindow::on_selectid_clicked()
{
    int id=ui->tableView->model()->data(ui->tableView->selectionModel()->currentIndex().siblingAtColumn(0)).toInt();
    bool test = cl.supprimer(id);
    if(test)
    {
        ui->cb->setText(cl.count());

        ui->tableView->setModel(cl.afficher());
        QMessageBox::information(nullptr, QObject::tr("Delete"),
                    QObject::tr("The item is Deleted successfullly.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Won't be Deleted"),
                    QObject::tr("ERROR 404.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}


//download pdf
/*void MainWindow::on_pdf_clicked()
{
    //QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    //if (!index.isValid()) {
     //      QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un Client.");
     //      return;
     //}
    // int selectedId = index.sibling(index.row(), 0).data().toInt(); // Supposons que la colonne 0 contient l'ID

     // Demander confirmation à l'utilisateur
     QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Confirmation", "Voulez-vous télécharger le PDF de cet Client ?", QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {

               cl.pdf_downloader();
               QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/amine/Downloads/client.pdf"));

      }

}*/
void MainWindow::on_pdf_clicked()
{
    int phone = QInputDialog::getInt(this, "Enter Phone Number", "Phone:");

   /* if (!cl.isPhoneInDatabase(phone)) {
        QMessageBox::warning(this, "Phone Not Found", "The entered phone number is not in the database.");
        return;
    }*/

    // Generate a random 6-digit verification code
    QString verificationCode = cl.generateVerificationCode();

    // Send the verification code via SMS
    cl.sendSms(QString::number(phone), "Your verification code is: " + verificationCode);

    // Prompt the user to enter the verification code
    bool ok;
    QString enteredCode = QInputDialog::getText(this, "Verification",
                                                "Enter the verification code sent to your phone:",
                                                QLineEdit::Normal, "", &ok);

    // Check if the entered code matches the generated code
    if (!ok || enteredCode.isEmpty() || enteredCode != verificationCode) {
        QMessageBox::warning(this, "Verification Failed", "The entered verification code is incorrect.");
        return;
    }

    // Verification succeeded, proceed to download the PDF
    cl.pdf_downloader();
    QMessageBox::information(this, "PDF Downloaded", "PDF downloaded successfully.");
}




void MainWindow::on_trier_clicked()
{
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    if(index.isValid()){
            if(ui->cbb->currentText()=="Descend"){

                if(index.sibling(index.row(), 0).data().toInt()){
                    ui->tableView->setModel(cl.trier_id_desc());
                }
                else if(index.sibling(index.row(), 1).data().toInt()){
                    ui->tableView->setModel(cl.trier_name_desc());
                }
                else if(index.sibling(index.row(), 2).data().toInt()){
                    ui->tableView->setModel(cl.trier_phone_desc());
                }

                else if(index.sibling(index.row(), 3).data().toInt()){
                    ui->tableView->setModel(cl.trier_mail_desc());
                }

                else if(index.sibling(index.row(), 4).data().toInt()){
                    ui->tableView->setModel(cl.trier_adresse_desc());
                }
                else if (index.sibling(index.row(), 5).data().toInt()){
                    ui->tableView->setModel(cl.trier_tab_desc());

                }

        }
        else if(ui->cbb->currentText()=="Ascend"){
                if(index.sibling(index.row(), 0).data().toInt()){
                    ui->tableView->setModel(cl.trier_id_ASC());
                }
                else if(index.sibling(index.row(), 1).data().toInt()){
                    ui->tableView->setModel(cl.trier_name_ASC());
                }
                else if(index.sibling(index.row(), 2).data().toInt()){
                    ui->tableView->setModel(cl.trier_phone_ASC());
                }

                else if(index.sibling(index.row(), 3).data().toInt()){
                    ui->tableView->setModel(cl.trier_mail_ASC());
                }

                else if(index.sibling(index.row(), 4).data().toInt()){
                    ui->tableView->setModel(cl.trier_adresse_ASC());
                }
                else if (index.sibling(index.row(), 5).data().toInt()){
                    ui->tableView->setModel(cl.trier_tab_ASC());

                }
        }
    }
    else {
        if(ui->cbb->currentText()=="Descend"){

               if(ui->choose->currentText()=="Client id"){
                   ui->tableView->setModel(cl.trier_id_desc());
               }
               else if(ui->choose->currentText()=="Name"){
                   ui->tableView->setModel(cl.trier_name_desc());
               }
               else if(ui->choose->currentText()=="Phone Number"){
                   ui->tableView->setModel(cl.trier_phone_desc());
               }

               else if(ui->choose->currentText()=="E-mail"){
                   ui->tableView->setModel(cl.trier_mail_desc());
               }

               else if(ui->choose->currentText()=="Adresse"){
                   ui->tableView->setModel(cl.trier_adresse_desc());
               }
               else if (ui->choose->currentText()=="Total Orders"){
                   ui->tableView->setModel(cl.trier_tab_desc());

               }

       }
       else if(ui->cbb->currentText()=="Ascend"){
            if(ui->choose->currentText()=="Client id"){
                   ui->tableView->setModel(cl.trier_id_ASC());
               }
               else if(ui->choose->currentText()=="Name"){
                   ui->tableView->setModel(cl.trier_name_ASC());
               }
               else if(ui->choose->currentText()=="Phone Number"){
                   ui->tableView->setModel(cl.trier_phone_ASC());
               }

               else if(ui->choose->currentText()=="E-mail"){
                   ui->tableView->setModel(cl.trier_mail_ASC());
               }

               else if(ui->choose->currentText()=="Adresse"){
                   ui->tableView->setModel(cl.trier_adresse_ASC());
               }
               else if (ui->choose->currentText()=="Total Orders"){
                   ui->tableView->setModel(cl.trier_tab_ASC());

               }
        }
    }

}


















void MainWindow::on_send_clicked()
{
    // Create a new QWidget for the email input dialog
    QWidget *emailDialog = new QWidget(this);
    emailDialog->setWindowTitle("Send Email");

    // Create input fields for the email details
    QVBoxLayout *layout = new QVBoxLayout(emailDialog);

    QLabel *fromLabel = new QLabel("From:", emailDialog);
    QLineEdit *fromLineEdit = new QLineEdit(emailDialog);

    QLabel *toLabel = new QLabel("To:", emailDialog);
    QLineEdit *toLineEdit = new QLineEdit(emailDialog);

    QLabel *subjectLabel = new QLabel("Subject:", emailDialog);
    QLineEdit *subjectLineEdit = new QLineEdit(emailDialog);

    QLabel *messageLabel = new QLabel("Message:", emailDialog);
    QTextEdit *messageTextEdit = new QTextEdit(emailDialog);

    QPushButton *sendButton = new QPushButton("Send Email", emailDialog);

    layout->addWidget(fromLabel);
    layout->addWidget(fromLineEdit);
    layout->addWidget(toLabel);
    layout->addWidget(toLineEdit);
    layout->addWidget(subjectLabel);
    layout->addWidget(subjectLineEdit);
    layout->addWidget(messageLabel);
    layout->addWidget(messageTextEdit);
    layout->addWidget(sendButton);

    emailDialog->setLayout(layout);
    emailDialog->resize(400, 300);
    emailDialog->show();

    // Connect the Send button to the function that sends the email
    connect(sendButton, &QPushButton::clicked, [this, fromLineEdit, toLineEdit, subjectLineEdit, messageTextEdit, emailDialog](){
        // Get the input values
        QString from = fromLineEdit->text();
        QString to = toLineEdit->text();
        QString subject = subjectLineEdit->text();
        QString message = messageTextEdit->toPlainText();

        // Send the email using SmtpClient
        SmtpClient smtpClient;
        smtpClient.sendEmail(from, to, subject, message);

        // Show success message
        QMessageBox::information(this, "Email Sent", "Your email has been sent successfully!");

        // Close the email dialog
        emailDialog->close();
    });

}

//aminegaming275@gmail.com
