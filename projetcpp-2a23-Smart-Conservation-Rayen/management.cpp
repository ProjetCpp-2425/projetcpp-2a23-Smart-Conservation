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
#include "email.h"
#include "management.h"
#include "mainwindow.h"
#include "employee.h"
#include "ui_management.h"

management::management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::management)
{
    ui->setupUi(this);
    ui->main->setCurrentIndex(0);
    connect(ui->table, &QTableWidget::itemDoubleClicked, this, &management::onTableItemDoubleClicked);
    connect(ui->search_field, &QLineEdit::returnPressed, this, &management::on_searchConfirm);
    //client
    ui->client->setCurrentWidget(ui->client);
    ui->tableView->setModel(cl.afficher());

    //connect(ui->annuler, &QPushButton::clicked, this, &management::on_machines_clicked);
    //connect(ui->sup, &QPushButton::clicked, this, &management::on_sup_clicked);
    connect(ui->ajout, &QPushButton::clicked, this, &management::on_add_client_2_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &::management::on_pdf_clicked);
    connect(ui->trier, &QPushButton::clicked, this, &management::on_trier_clicked);
    connect(ui->selectid, &QPushButton::clicked, this, &management::on_selectid_clicked);
    connect(ui->update, &QPushButton::clicked, this, &management::on_update_clicked);
    connect(ui->cancel, &QPushButton::clicked, this, &management::on_cancel_clicked);
    connect(ui->annuler, &QPushButton::clicked, this, &management::on_cancel_clicked);
    connect(ui->confirm_client, &QPushButton::clicked, this, &management::on_ajout_cl_clicked);
    connect(ui->confirm_update_client, &QPushButton::clicked, this, &management::on_update_clicked);


    statistique();
   // connect(ui->stats, &QPushButton::clicked, this, &management::on_stats_clicked);
    connect(ui->send, &QPushButton::clicked, this, &::management::on_send_clicked);
    //count all clients
    ui->cb->setText(cl.count());
}

management::~management()
{
    delete ui;
}

/*--------------SIDEBAR-ROUTING--------------*/

void management::on_dahsboard_clicked()
{
    ui->main->setCurrentIndex(0);
}
void management::on_employees_clicked()
{
    ui->main->setCurrentIndex(1);
    ui->employee->setCurrentIndex(0);
    Employee employee;
    employee.readEmployee(ui->table);
    updateProgressBars();
}
void management::on_factories_clicked()
{
    ui->main->setCurrentIndex(2);
    ui->factory->setCurrentIndex(0);
}
void management::on_machines_clicked()
{
    ui->main->setCurrentIndex(3);
    ui->machiness->setCurrentIndex(0);
}
void management::on_deliveries_clicked()
{
    ui->main->setCurrentIndex(4);
    ui->delivery->setCurrentIndex(0);
}
void management::on_clients_clicked()
{
    ui->main->setCurrentIndex(5);
    ui->client->setCurrentIndex(0);
}

/*--------------DEFAULT-TO-ADD-NEW-ROUTING--------------*/

void management::on_add_employee_btn_clicked()
{
    ui->employee->setCurrentIndex(1);
}
void management::on_add_client_btn_clicked()
{
    ui->client->setCurrentIndex(1);
}
void management::on_add_delivery_btn_clicked()
{
    ui->delivery->setCurrentIndex(1);
}
void management::on_add_factory_btn_clicked()
{
   ui->factory->setCurrentIndex(1);
}
void management::on_add_machine_btn_clicked()
{
    ui->machiness->setCurrentIndex(1);
}

/*--------------EMPLOYEE FUNCTIONS---------------*/

// Confirm and add a new employee
void management::on_confirm_employee_btn_clicked()
{
    QString name = ui->name_field->text();
    QString email = ui->email_field->text();
    int phone = ui->phone_field->text().toInt();
    QString position = ui->position_field->currentText();
    Employee emp;
    Employee newEmployee(name, email, position, phone);
    if (newEmployee.createEmployee()) {
        qDebug() << "Employee creation process completed successfully.";
        ui->name_field->clear();
        ui->email_field->clear();
        ui->phone_field->clear();
        ui->position_field->setCurrentIndex(0);
        Employee employee;
        employee.readEmployee(ui->table);
        ui->employee->setCurrentIndex(0);
    } else {
        qDebug() << "Employee creation process failed.";
    }
    updateProgressBars();
}

// Navigate back in history
void management::on_history_back_clicked()
{
    ui->employee->setCurrentIndex(0);
}
void management::on_update_back_clicked()
{
    ui->employee->setCurrentIndex(0);
}
void management::on_add_back_clicked()
{
    ui->employee->setCurrentIndex(0);
}

// Export employee data (function to be implemented)
void management::on_employee_export_clicked()
{
    Employee employee;
    employee.readEmployee(ui->table);
    QTableWidget *tableH = ui->tableH;  // Replace with your actual table object
    employee.exportPresence(tableH); }

void management::on_update_employee_btn_clicked()
{

    int selectedRow = ui->table->currentRow();
    if (selectedRow != -1) { // Check if a row is selected
        QString name = ui->table->item(selectedRow, 1)->text();
        QString email = ui->table->item(selectedRow, 2)->text();
        int phone = ui->table->item(selectedRow, 3)->text().toInt();
        QString position = ui->table->item(selectedRow, 4)->text();
        QString employeeId = ui->table->item(selectedRow, 0)->text();

        ui->name_update->setText(name);
        ui->email_update->setText(email);
        ui->phone_update->setText(QString::number(phone));
        ui->position_update->setCurrentText(position);
        ui->employee->setCurrentIndex(2);

    }
}

// Confirm update to employee data
void management::on_confirm_update_btn_clicked()
{
    QString name = ui->name_update->text();
    QString email = ui->email_update->text();
    int phone = ui->phone_update->text().toInt();
    QString position = ui->position_update->currentText();
    int selectedRow = ui->table->currentRow();
    QString employeeId = ui->table->item(selectedRow, 0)->text();

    Employee employee;
    employee.setName(name);
    employee.setEmail(email);
    employee.setPhoneNumber(phone);
    employee.setPosition(position);

    if (employee.updateEmployee(employeeId)) {
        qDebug() << "Employee update process completed successfully.";
        ui->name_update->clear();
        ui->email_update->clear();
        ui->phone_update->clear();
        ui->position_update->setCurrentIndex(0);
        ui->employee->setCurrentIndex(0);
        ui->table->setRowCount(0);
        Employee employee;
        employee.readEmployee(ui->table);
    } else {
        qDebug() << "Employee update process failed.";
    }
    updateProgressBars();
}

// Delete employee logic
void management::on_delete_employee_btn_clicked()
{
    int selectedRow = ui->table->currentRow();
    Employee employee;
    QString employeeId = ui->table->item(selectedRow, 0)->text();

    if (employee.deleteEmployee(employeeId)) {
        qDebug() << "Employee deletion process completed successfully.";
        employee.readEmployee(ui->table);
    } else {
        qDebug() << "Employee deletion process failed.";
    }
    employee.readEmployee(ui->table);
    updateProgressBars();
}


void management::on_searchConfirm()
{
    Employee employee;
    QString type = ui->search->currentText();
    QString searchText = ui->search_field->text();
    QTableWidget *table = ui->table;
    QSqlQueryModel *model = employee.rechercher(type, searchText);

    if (model) {
        table->setRowCount(0);
        table->setColumnCount(model->columnCount());

        // Populate the QTableWidget with data from the model
        int rowCount = model->rowCount();
        int columnCount = model->columnCount();

        for (int row = 0; row < rowCount; ++row) {
            table->insertRow(row);  // Insert new row in the table

            for (int col = 0; col < columnCount; ++col) {
                // Create a new item for each cell and set its text from the model's data
                QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
                item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                table->setItem(row, col, item);
            }
        }

        int fixedHeight = 40;
        for (int i = 0; i < table->rowCount(); ++i) {
            table->setRowHeight(i, fixedHeight);
        }
        table->setSortingEnabled(true);
    } else {
        qDebug() << "No results found.";
    }
}

void management::on_searchReset_clicked()
{
    ui->search_field->clear();
    ui->table->setRowCount(0);
    Employee employee;
    employee.readEmployee(ui->table);
    ui->employee->setCurrentIndex(0);
}

void management::onTableItemDoubleClicked(QTableWidgetItem *item) {
    QString employeeIdStr = ui->table->item(item->row(), 0)->text();
    Employee employee;
    ui->employee->setCurrentIndex(3);
    QTableWidget *historiqueTable = ui->tableH;
    employee.readHistorique(historiqueTable, employeeIdStr);
}


void management::on_logout_clicked()
{
    this->hide();
    MainWindow *mainWindow = new MainWindow();
     mainWindow->show();
}

void management::updateProgressBars() {
    int techCount = 0;
    int chefCount = 0;
    int managerCount = 0;
    int totalCount = 1;  // Initialize to 1 to avoid division by zero

    QSqlQuery query;

    // Get total count of employees
    if (query.exec("SELECT COUNT(*) FROM employee")) {
        if (query.next()) {
            totalCount = query.value(0).toInt();
            qDebug() << "Total count:" << totalCount;
        }
    } else {
        qDebug() << "Total count query failed:" << query.lastError().text();
    }

    // Set progress bars to 0 if no employees are found
    if (totalCount == 0) {
        ui->progressBar1->setValue(0);
        ui->progressBar2->setValue(0);
        ui->progressBar3->setValue(0);
        return;
    }
    // Get count of employees with position 'Tech'
    if (query.exec("SELECT COUNT(*) FROM employee WHERE position = 'Tech'")) {
        if (query.next()) {
            techCount = query.value(0).toInt();
            qDebug() << "Tech count:" << techCount;
        }
    } else {
        qDebug() << "Tech count query failed:" << query.lastError().text();
    }

    // Get count of employees with position 'Chef'
    if (query.exec("SELECT COUNT(*) FROM employee WHERE position = 'Chef'")) {
        if (query.next()) {
            chefCount = query.value(0).toInt();
            qDebug() << "Chef count:" << chefCount;
        }
    } else {
        qDebug() << "Chef count query failed:" << query.lastError().text();
    }

    // Get count of employees with position 'Manager'
    if (query.exec("SELECT COUNT(*) FROM employee WHERE position = 'Manager'")) {
        if (query.next()) {
            managerCount = query.value(0).toInt();
            qDebug() << "Manager count:" << managerCount;
        }
    } else {
        qDebug() << "Manager count query failed:" << query.lastError().text();
    }

    // Calculate percentages for each position and update progress bars
    int technicianPercentage = (techCount * 100) / totalCount;
    int chefCuisinePercentage = (chefCount * 100) / totalCount;
    int managerPercentage = (managerCount * 100) / totalCount;

    ui->progressBar1->setValue(technicianPercentage);
    ui->progressBar2->setValue(chefCuisinePercentage);
    ui->progressBar3->setValue(managerPercentage);
}
//------------------------------------------------------------------------------------------------------------------Clients----------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
void management::on_add_client_2_clicked(){
    ui->client->setCurrentWidget(ui->add_client_2);

}

void management::on_pushButton_6_clicked()
{
    ui->client->setCurrentWidget(ui->principale);
}
void management::on_add_clicked()
{
    ui->client->setCurrentWidget(ui->ajout);
}


void management::on_cancel_clicked()
{
    ui->client->setCurrentWidget(ui->principale);
}


void management::on_update_clicked()
{
    ui->client->setCurrentWidget(ui->update_cl);

}

/*void management::on_stats_clicked()
{
    ui->client->setCurrentWidget(ui->status);

    QPieSeries *series =cl.generateClientStatistics();

        // Create the chart
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Client Order Statistics");
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Create the chart view
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Embed the chart view inside frame_2
        chartView->setParent(ui->frame_2); // Attach to frame_2
        chartView->resize(ui->frame_2->size()); // Adjust size to match frame_2
        chartView->show();


}*/
/*
void management::on_back_clicked()
{
    ui->client->setCurrentWidget(ui->principale);
}*/

//search for the update and cancel
/*
void management::on_ajout_cl_2_clicked()
{
    int id = ui->search_2->text().toInt();

    bool test = cl.search(id);
    if(test)
    {
        //yhezna el stacked whidget ou5ra
        ui->cb->setText(cl.count());

        ui->client->setCurrentWidget(ui->update_if);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Try an other Id"),
                    QObject::tr("ERROR 404.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

}*/
//modification des information

void management::on_update_2_clicked()
{
    int tot_ord = ui->total_ord_3->text().toInt();
    int id = ui->tableView->model()->data(ui->tableView->selectionModel()->currentIndex().siblingAtColumn(0)).toInt();
    QString adresse = ui->adress_cl_2->text();
    QString name = ui->name_cl_2->text();
    QString email = ui->email_cl_2->text();
    int phone = ui->phone_cl_2->text().toInt();


    bool test = cl.update(id,name,tot_ord,adresse,email,phone);
    if(test)
    {
        ui->cb->setText(cl.count());

        ui->client->setCurrentWidget(ui->principale);
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

//supprission un element du la base du donne


void management::on_ajout_cl_clicked()
{
    int tot_ord = ui->total_ord->text().toInt();
    QString adresse = ui->adress_cl->text();
    int id = ui->id->text().toInt();
    QString name = ui->name_cl->text();
    QString email = ui->email_cl->text();
    int phone = ui->phone_cl->text().toInt();
    client c(id, name, phone, email, adresse, tot_ord);
    bool test=c.ajouter();

    if(test)
    {
        ui->cb->setText(cl.count());

        ui->client->setCurrentWidget(ui->principale);
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
void management::on_serarch_c_clicked()
{
     QString namesearch = ui->recherche->text();
     if (namesearch.isEmpty()) {
            QMessageBox::warning(this, tr("Input Error"), tr("Please enter a name to search."));
            return;
        }

     bool test = cl.searchcl(namesearch);
     if(test)
     {
         ui->cb->setText(cl.countname(namesearch));
         ui->tableView->setModel(cl.affichercl(namesearch));
         QMessageBox::information(nullptr, QObject::tr("founded done"),
                     QObject::tr("Client Founded.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

    }
     else{
         QMessageBox::critical(nullptr, QObject::tr("not founded"),
                     QObject::tr("can't find the client that you are searching for.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
}


//ki ta5tar haja fel table view yfasa5ha

void management::on_selectid_clicked()
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

void management::on_pdf_clicked()
{
    int phone = QInputDialog::getInt(this, "Enter Phone Number", "Phone:");

    if (!cl.isPhoneInDatabase(phone)) {
        QMessageBox::warning(this, "Phone Not Found", "The entered phone number is not in the database.");
        return;
    }

    QString verificationCode = cl.generateVerificationCode();

    cl.sendSms(QString::number(phone), "Your verification code is: " + verificationCode);

    bool ok;
    QString enteredCode = QInputDialog::getText(this, "Verification",
                                                "Enter the verification code sent to your phone:",
                                                QLineEdit::Normal, "", &ok);

    if (!ok || enteredCode.isEmpty() || enteredCode != verificationCode) {
        QMessageBox::warning(this, "Verification Failed", "The entered verification code is incorrect.");
        return;
    }

    cl.pdf_downloader();
    QMessageBox::information(this, "PDF Downloaded", "PDF downloaded successfully.");
}




void management::on_trier_clicked()
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




void management::statistique() {
    int total_order = 0;
    int totalCount = 1;

    QSqlQuery query;

    if (query.exec("SELECT COUNT(*) FROM Client")) {
        if (query.next()) {
            totalCount = query.value(0).toInt();
            //qDebug() << "Total count:" << totalCount;
        }
    } else {
        qDebug() << "Total count query failed:" << query.lastError().text();
    }

    if (totalCount == 0) {
        ui->progressBar1->setValue(0);
        ui->progressBar2_4->setValue(0);
        return;
    }
    if (query.exec("SELECT COUNT(*) FROM Client WHERE TOTAL_ORDERS >0")) {
        if (query.next()) {
            total_order = query.value(0).toInt();
            //qDebug() << "Total Orders:" << total_order;
        }
    } else {
        qDebug() << "Tech count query failed:" << query.lastError().text();
    }




    // Calculate percentages for each position and update progress bars
    int totalorderPercentage = (total_order * 100) / totalCount;
    //int totalclientpercentage = (totalCount);

    ui->presenceBar1__9->setValue(totalCount);
    ui->progressBar2_4->setValue(totalorderPercentage);

}


void management::on_send_clicked()
{
    email * SecondWindow = new email(this);
    SecondWindow->setModal(true);
    SecondWindow->show();
}









