#include "management.h"
#include "commande.h"
#include "email.h"
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
#include "mainwindow.h"
#include "employee.h"
#include "ui_management.h"
#include "factory.h"
#include "client.h"
#include <QLabel>
#include <QTimer>
#include <QSystemTrayIcon>
management::management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::management)
{
    ui->setupUi(this);

    //on_dahsboard_clicked();
    ui->main->setCurrentIndex(4);
    ui->Dashboard__1->setCurrentIndex(0);
    //loadDeliveriesIntoTable();

    //---------------client---------------------------------------------------------
    ui->client->setCurrentWidget(ui->client);

    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_cl_3->setSortingEnabled(true);

    ui->tableView_cl_3->setModel(cl.afficher());

    //connect(ui->annuler, &QPushButton::clicked, this, &management::on_machines_clicked);
    //connect(ui->sup, &QPushButton::clicked, this, &management::on_sup_clicked);
    connect(ui->ajout_cl, &QPushButton::clicked, this, &management::on_ajout_cl_clicked);

    connect(ui->pdf_downloader, &QPushButton::clicked, this, &::management::on_pdf_clicked);
    connect(ui->trier, &QPushButton::clicked, this, &management::on_trier_clicked);
    connect(ui->selectid, &QPushButton::clicked, this, &management::on_selectid_clicked);

    connect(ui->update, &QPushButton::clicked, this, &management::on_update_clicked);

    connect(ui->cancel, &QPushButton::clicked, this, &management::on_pushButton_6_clicked);
    connect(ui->annuler, &QPushButton::clicked, this, &management::on_pushButton_6_clicked);

    connect(ui->confirm_client, &QPushButton::clicked, this, &management::on_add_clicked);

    connect(ui->confirm_update_client, &QPushButton::clicked, this, &management::on_update_2_clicked);
    connect(ui->clients, &QPushButton::clicked, this, &management::on_pushButton_6_clicked);

    connect(ui->dahsboard, &QPushButton::clicked, this, &management::on_dahsboard_clicked);



    statistique();
   // connect(ui->stats, &QPushButton::clicked, this, &management::on_stats_clicked);
    connect(ui->send, &QPushButton::clicked, this, &::management::on_send_clicked);





    // Main Page Initialization
    // Table and Delivery Management
    connect(ui->table, &QTableWidget::itemDoubleClicked, this, &management::onTableItemDoubleClicked);
    connect(ui->search_field, &QLineEdit::returnPressed, this, &management::on_searchConfirm);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // Disable edit on double click
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // Highlight entire row
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); // Single-row selection

    QSqlQuery query;
    query.exec("SELECT * FROM DELIVERY");

    // Load deliveries into the table after a delay
    QTimer::singleShot(1000, this, &management::loadDeliveriesIntoTable);

    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &management::onTableWidgetRowSelected);
    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, &management::filterTableByDeliveryId);
    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &management::on_tableWidget_cellDoubleClicked);

    // Maintenance Planning Initialization
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [this](int index) {
        if (index == 6) { // Maintenance planning tab
            updateCalendarHighlights();
            loadMaintenanceDates(); // Load maintenance dates when the tab is selected
        }
    });

    connect(ui->tableView_4, &QTableView::clicked, this, &management::showMaintenanceCalendar);



    // Set up the tab titles
    ui->tabWidget->setTabText(0, "Main Page");
    ui->tabWidget->setTabText(1, "Adding");
    ui->tabWidget->setTabText(2, "Modifying");
    ui->tabWidget->setTabText(3, "Diagnostic ");
    ui->tabWidget->setTabText(4, "Maintenance Planning");
    //liste
    ui->listWidget_3->addItem("Overheating");
    ui->listWidget_3->addItem("Power Loss");
    ui->listWidget_3->addItem("Unusual noise");
    ui->listWidget_3->addItem("Frequent shutdowns");
    ui->listWidget_3->addItem("Battery draining");
    ui->listWidget_3->addItem("Display not working");
    ui->listWidget_3->addItem("Electrical sparks");
    ui->listWidget_3->addItem("Slow operation");
    ui->listWidget_3->addItem("Vibrations");

    // Connect Buttons
    connect(ui->pushButton_13, &QPushButton::clicked, this, &management::on_pushButton_13_clicked);
    connect(ui->pushButton_24, &QPushButton::clicked, this, &management::on_pushButton_24_clicked);
    connect(ui->statsbutton, &QPushButton::clicked, this, &management::on_statsbutton_clicked);


    updateFactoryCountF();  // Call the function to set the factory count
    //--------------------------------factory------------------//

    // Connecting button clicks to their respective slots
    connect(ui->add, &QPushButton::clicked, this, &management::on_add_clickedF);
    connect(ui->annuler_4, &QPushButton::clicked, this, &management::on_annuler_clickedF);
    connect(ui->sup_3, &QPushButton::clicked, this, &management::on_sup_clickedF);
    connect(ui->ajout_cl_3, &QPushButton::clicked, this, &management::on_ajout_cl_2_clickedF);
    connect(ui->PDF, &QPushButton::clicked, this, &management::on_pdfButton_clickedF); // Connect PDF button
    connect(ui->filterButton, &QPushButton::clicked, this, &management::on_filterButton_clickedF);
    connect(ui->searchLocation, &QLineEdit::textChanged, this, &management::on_searchLocation_textChangedF);
    connect(ui->generateQRCodeButton, &QPushButton::clicked, this, &management::on_generateQRButton_clickedF);
    connect(ui->displayQRButton, &QPushButton::clicked, this, &management::on_displayQRButton_clickedF);
    //-------------------------------------------client-----------------------------------------------------------

    //count all clients
    ui->cb->setText(cl.count());
    //arduino client
    int ret = A.connect_arduino();
       switch (ret) {
       case 0:
           qDebug() << "Arduino is available and connected to:" << A.getarduino_port_name();
           break;
       case 1:
           qDebug() << "Arduino is available but not connected to:" << A.getarduino_port_name();
           break;
       case -1:
           qDebug() << "Arduino is not available";
       }

       QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));


       // Initialize alert label
       alertLabel = new QLabel(this);
          alertLabel->setStyleSheet(
              "background-color: white; "
              "color: black; "
              "border: 1px solid gray; "
              "border-radius: 10px; "
              "padding: 15px; "
              "font-size: 14px; "
              "box-shadow: 5px 5px 15px rgba(0, 0, 0, 0.3);"
          );
          alertLabel->setText(""); // No text initially
          alertLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
          alertLabel->setVisible(false); // Initially hidden

          alertLabel->setGeometry(width() - 350, height() - 100, 300, 60);


}

//code arduino client

void management::update_label() {
    QByteArray data = A.read_from_arduino(); // Read data from Arduino
    QString message(data.trimmed()); // Trim whitespace and newline characters

    // Convert the data to an integer
    bool isNumeric = false;
    int value = message.toInt(&isNumeric);

    if (isNumeric) { // Ensure the data is a valid number
        qDebug() << "Received value from Arduino:" << value;

        if (value > 0) { // Check if value exceeds 0
            show_alert("⚠️ There is client in reception!");
        }
    } else {
        qDebug() << "Non-numeric data received:" << message;
    }
}
void management::show_alert(const QString &message) {
    // Update alert text
    alertLabel->setText(message);

    // Adjust alert size to fit text
    alertLabel->adjustSize();
    int width = 430;  // Set width to be width of content + 60
    int height = alertLabel->height();

    // Set the alert label to the fixed width and calculated height
    alertLabel->setFixedSize(width, height);

    // Apply the CSS styles
    alertLabel->setStyleSheet(
        "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
        "stop: 0 #ffffff, stop: 1 #dcdcdc); "
        "color: #1BA019; "
        "border-left: 3px solid #1BA019; "
        "border-right: 3px solid #1BA019; "
        "border-color: none; "
        "border-radius: 5px; "
        "padding: 10px; "
        "font-size: 14px;"
    );

    // Position the alert in the top-right corner (fixed)
    int posX = this->width() - alertLabel->width() - 20; // Right side with padding
    int posY = 20; // Offset from top
    alertLabel->move(posX, posY);


    // Show the alert
    alertLabel->setVisible(true);

    // Hide the alert after 5 seconds
    QTimer::singleShot(5000, this, &management::hide_alert);
}


void management::hide_alert() {
    alertLabel->setVisible(false);
}



management::~management()
{   delete ui;  }

/*--------------SIDEBAR--------------*/
void management::on_employees_clicked()
{
    ui->main->setCurrentIndex(0);
    ui->employee->setCurrentIndex(0);
    Employee employee;
    employee.readEmployee(ui->table);
    updateProgressBars();
}
void management::on_machines_clicked()
{
    ui->main->setCurrentIndex(2);

}


void management::on_deliveries_clicked()
{
    ui->main->setCurrentIndex(1);
    ui->Deliver->setCurrentIndex(0);
    loadDeliveriesIntoTable();

}


/*--------------DEFAULT-TO-ADD-NEW-ROUTING--------------*/

void management::on_add_employee_btn_clicked()
{
    ui->employee->setCurrentIndex(1);
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
        }
    } else {
        qDebug() << "Tech count query failed:" << query.lastError().text();
    }

    // Get count of employees with position 'Chef'
    if (query.exec("SELECT COUNT(*) FROM employee WHERE position = 'Chef Cuisine'")) {
        if (query.next()) {
            chefCount = query.value(0).toInt();
        }
    } else {
        qDebug() << "Chef count query failed:" << query.lastError().text();
    }

    // Get count of employees with position 'Manager'
    if (query.exec("SELECT COUNT(*) FROM employee WHERE position = 'Manager'")) {
        if (query.next()) {
            managerCount = query.value(0).toInt();
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
    ui->progressBar4->setValue(totalCount);
}

/*----------------------COMMANDE----------------------*/


void management::on_pushButton_3_clicked()
{
    ui->Deliver->setCurrentIndex(1);
}

void management::on_pushButton_10_clicked()
{
    // Retrieve input values
    QString selectedStatus = ui->comboBox_Status->currentText();
    QString deliveryId = ui->lineEdit_DeliveryID->text();
    QString deliveryAddress = ui->lineEdit_deliveryAddress->text();
    QString clientId = ui->lineEdit_clientID->text();
    QString employeeId = ui->lineEdit_employeeID->text();
    QString deliveryDate = QDate::currentDate().toString("dd-MM-yy");
    // 1. Ensure DeliveryID starts with "D"

    // 2. Ensure a valid status is selected (not "Status")
    if (selectedStatus == "Status") {
        QMessageBox::critical(this, "Error", "Please select a valid status.");
        return;
    }

    // 3. Check if the clientID exists in the database
    QSqlQuery clientQuery;
    clientQuery.prepare("SELECT COUNT(*) FROM CLIENT WHERE CLIENT_ID = :clientId");
    clientQuery.bindValue(":clientId", clientId);
    clientQuery.exec();
    clientQuery.next();
    if (clientQuery.value(0).toInt() == 0) {
        QMessageBox::critical(this, "Error", "Client ID does not exist in the database.");
        return;
    }

    // 4. Check if the employeeID exists in the database
    QSqlQuery employeeQuery;
    employeeQuery.prepare("SELECT COUNT(*) FROM EMPLOYEE WHERE EMPLOYEE_ID = :employeeId");
    employeeQuery.bindValue(":employeeId", employeeId);
    employeeQuery.exec();
    employeeQuery.next();

    if (employeeQuery.value(0).toInt() == 0) {
        QMessageBox::critical(this, "Error", "Employee ID does not exist in the database.");
        return;
    }
    // Proceed with either Add or Edit mode
    if (isEditMode) {
        // Update mode
        Delivery updatedDelivery(deliveryId, deliveryAddress, deliveryDate, selectedStatus, clientId, employeeId);
        if (updatedDelivery.update(currentDeliveryId)) {
            QMessageBox::information(this, "Success", "Delivery updated successfully!");
            isEditMode = false;
            currentDeliveryId.clear();

        } else {
            QMessageBox::critical(this, "Error", "Failed to update delivery.");
        }
    } else {
        // Add mode
        Delivery newDelivery(deliveryId, deliveryAddress, deliveryDate, selectedStatus, clientId, employeeId);
        if (newDelivery.add()) {
            QMessageBox::information(this, "Success", "Delivery added successfully!");

        } else {
            QMessageBox::critical(this, "Error", "Failed to add delivery.");
        }
    }

    // Reload the table and add the "View QRcode" item
    ui->tableWidget->setRowCount(0);
    QSqlQuery query;
    query.exec("SELECT * FROM DELIVERY");
    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        // Add "View QRcode" in the 7th column
        QTableWidgetItem *viewQRCodeItem = new QTableWidgetItem("View QRcode");
        ui->tableWidget->setItem(row, 6, viewQRCodeItem);
    }

    ui->Deliver->setCurrentIndex(0);
}
void management::on_edit_table_button_clicked()
{

    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Edit Error", "Please select a delivery to edit.");
        return;
    }

    // Fill the form with the selected delivery's data
    ui->lineEdit_DeliveryID->setText(ui->tableWidget->item(row, 0)->text());
    ui->lineEdit_clientID->setText(ui->tableWidget->item(row, 1)->text());
    ui->lineEdit_employeeID->setText(ui->tableWidget->item(row, 2)->text());
    ui->lineEdit_deliveryAddress->setText(ui->tableWidget->item(row, 3)->text());
    ui->comboBox_Status->setCurrentText(ui->tableWidget->item(row, 4)->text());

    // Set edit mode to true and store the ID of the delivery being edited
    isEditMode = true;
    currentDeliveryId = ui->lineEdit_DeliveryID->text();
    loadDeliveriesIntoTable();

    // Switch to the edit view
    ui->Deliver->setCurrentIndex(1);}


void management::on_button_delete_clicked()
{
    // Get the currently selected row in the table
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Delete Error", "Please select a delivery to delete.");
        return;
    }

    // Get the Delivery ID from the selected row (assuming it's in the first column)
    QString deliveryId = ui->tableWidget->item(row, 0)->text();

    // Ask for confirmation before deleting
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Are you sure you want to delete this delivery?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    // Attempt to delete the delivery from the database
    QSqlQuery query;
    query.prepare("DELETE FROM DELIVERY WHERE DELIVERY_ID = :id");
    query.bindValue(":id", deliveryId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Delete Error", "Failed to delete delivery: " + query.lastError().text());
        return;
    }

    // Remove the row from the QTableWidget
    ui->tableWidget->removeRow(row);
    QMessageBox::information(this, "Success", "Delivery deleted successfully!");

}


void management::filterTableByDeliveryId(const QString &searchText)
{
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        bool matches = ui->tableWidget->item(row, 0)->text().startsWith(searchText, Qt::CaseInsensitive);
        ui->tableWidget->setRowHidden(row, !matches);
    }
}

void management::on_tableWidget_cellDoubleClicked(int row, int column) {
    qDebug() << "QRCode Pressed";

    // Check if the column matches the status column index (e.g., replace 3 with the actual index of the status column)
    if (column == 4) {
        qDebug() << "Status column double-clicked, changing stackedWidget index to 2";

        // Change the stacked widget to index 2
        ui->Deliver->setCurrentIndex(2);

        // Get the status from the clicked row (not from the comboBox)
        QString status = ui->tableWidget->item(row, 4)->text();
        qDebug() << "Status from the clicked row: " << status;

        // Set progress bar values based on the status
        if (status == "Ordered") {
            ui->progressBar_1->setValue(0);
            ui->progressBar_2->setValue(0);
        } else if (status == "In Progress") {
            ui->progressBar_1->setValue(99);
            ui->progressBar_2->setValue(50);
        } else if (status == "Delivered") {
            ui->progressBar_1->setValue(99);
            ui->progressBar_2->setValue(99);
        }
    }
    if (column == 6) {
        QString status = ui->tableWidget->item(row, 4)->text(); // Statut dans la colonne 3 (ajustez si nécessaire)

        // Changer l'index de stackedWidget_2 en fonction du statut
        if (status == "Delivered") {
            ui->Deliver->setCurrentIndex(5);
        } else if (status == "In Progress") {
            ui->Deliver->setCurrentIndex(4);
        } else if (status == "Ordered") {
            ui->Deliver->setCurrentIndex(3);
        } else {
            QMessageBox::warning(this, "Error", "Unknown status: " + status);
        }
    }
}


void management::on_pushButton_2_clicked()// button el retour ta3 page timeline
{
    ui->Deliver->setCurrentIndex(0);
}


// Slot to update the date and time when the status changes
void management::onTableWidgetRowSelected(int row, int column) {
    Q_UNUSED(column);

    QTableWidgetItem *statusItem = ui->tableWidget->item(row, 4); // Adjust column index if needed
    if (statusItem) {
        QString status = statusItem->text().trimmed(); // Trim extra spaces
        QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

        // Debug: Log the current status and time
        qDebug() << "Status:" << status << "Current time:" << currentDateTime;

        if (status == "Ordered") {
            ui->label_ordered->setText(currentDateTime);
            ui->label_ordered->update(); // Force label update
            qDebug() << "Ordered label updated:" << ui->label_ordered->text();
        } else if (status == "In Progress") {
            ui->label_in_progress->setText(currentDateTime);
            ui->label_in_progress->update();
            qDebug() << "In Progress label updated:" << ui->label_in_progress->text();
        } else if (status == "Delivered") {
            ui->label_delivered->setText(currentDateTime);
            ui->label_delivered->update();
            qDebug() << "Delivered label updated:" << ui->label_delivered->text();
        } else {
            qDebug() << "Unexpected status:" << status;
        }
    } else {
        qWarning() << "No item found in the specified column.";
    }
}



void management::on_back_qrcode_ordered_clicked()
{
    ui->Deliver->setCurrentIndex(0);
}


void management::on_back_qrcode_in_progress_clicked()
{
    ui->Deliver->setCurrentIndex(0);
}


void management::on_back_qrcode_delivered_clicked()
{
    ui->Deliver->setCurrentIndex(0);
}




void management::on_statsbutton_clicked()
{
    // Query the database to get the count of each status
    int orderedCount = 0;
    int inProgressCount = 0;
    int deliveredCount = 0;
    int totalCount = 0;

    QSqlQuery query("SELECT STATUS, COUNT(*) FROM DELIVERY GROUP BY STATUS");
    while (query.next()) {
        QString status = query.value(0).toString();
        int count = query.value(1).toInt();

        if (status == "Ordered") {
            orderedCount = count;
        } else if (status == "In Progress") {
            inProgressCount = count;
        } else if (status == "Delivered") {
            deliveredCount = count;
        }
        totalCount += count;
    }

    if (totalCount == 0) {
        QMessageBox::information(this, "Statistics", "No data available for statistics.");
        return;
    }

    // Calculate the percentage for each status
    double orderedPercentage = (static_cast<double>(orderedCount) / totalCount) * 100;
    double inProgressPercentage = (static_cast<double>(inProgressCount) / totalCount) * 100;
    double deliveredPercentage = (static_cast<double>(deliveredCount) / totalCount) * 100;

    // Create pie series and add data
    auto *pieSeries = new QPieSeries();
    auto *orderedSlice = pieSeries->append("Ordered", orderedPercentage);
    auto *inProgressSlice = pieSeries->append("In Progress", inProgressPercentage);
    auto *deliveredSlice = pieSeries->append("Delivered", deliveredPercentage);

    // Customize slice labels and colors
    orderedSlice->setLabelVisible(true);
    orderedSlice->setLabel(QString("%1 (%2%)").arg(orderedSlice->label()).arg(orderedSlice->percentage() * 100, 0, 'f', 1));
    orderedSlice->setColor(QColor(0, 128, 0)); // Dark green

    inProgressSlice->setLabelVisible(true);
    inProgressSlice->setLabel(QString("%1 (%2%)").arg(inProgressSlice->label()).arg(inProgressSlice->percentage() * 100, 0, 'f', 1));
    inProgressSlice->setColor(QColor(0, 170, 0)); // Medium green

    deliveredSlice->setLabelVisible(true);
    deliveredSlice->setLabel(QString("%1 (%2%)").arg(deliveredSlice->label()).arg(deliveredSlice->percentage() * 100, 0, 'f', 1));
    deliveredSlice->setColor(QColor(144, 238, 144)); // Light green

    // Create chart and add the series
    auto *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Delivery Status Distribution");

    // Set up a label to display the total number of orders
    QLabel *totalLabel = new QLabel(QString("Total Orders: %1").arg(totalCount));
    totalLabel->setAlignment(Qt::AlignCenter);
    totalLabel->setStyleSheet("font-size: 16px; font-weight: bold;");

    // Set up chart view
    auto *chartView = new QChartView(pieChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a layout to position the label and chart together
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(totalLabel);
    layout->addWidget(chartView);

    // Create a container widget to show the chart and label
    QWidget *container = new QWidget();
    container->setLayout(layout);
    container->resize(600, 450);
    container->show();
}



//fin


void management::on_return_main_clicked()
{
    ui->Deliver->setCurrentIndex(0);
}


void management::on_export_table_clicked()
{
    // el creation ta3 el fichier
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "CSV Files (*.csv);;All Files (*)");

    if (fileName.isEmpty())
        return; // User canceled the dialog

    // Open file
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Unable to open the file for writing.");
        return;
    }

    QTextStream out(&file);

    // headers ta3 table
    int columnCount = ui->tableWidget->columnCount();
    for (int col = 0; col < columnCount; ++col) {
        out << ui->tableWidget->horizontalHeaderItem(col)->text();
        if (col < columnCount - 1)
            out << ";";
    }
    out << "\n";  // next line

    // Write the table content row by row
    int rowCount = ui->tableWidget->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            out << (item ? item->text() : "");
            if (col < columnCount - 1)
                out << ";";  // separation
        }
        out << "\n";  // Move to next line
    }

    file.close();
    QMessageBox::information(this, "Success", "Table exported successfully to " + fileName);
}

void management::loadDeliveriesIntoTable() {
    ui->tableWidget->setRowCount(0); // Clear existing rows

    QSqlQuery query("SELECT * FROM DELIVERY");
    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Remplir les colonnes existantes
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Delivery ID
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Delivery Address
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Delivery Date
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Status
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Client ID
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Employee ID

        // Ajouter "View QRcode" dans la dernière colonne
        QTableWidgetItem *viewQRCodeItem = new QTableWidgetItem("View QRcode");
        ui->tableWidget->setItem(row, 6, viewQRCodeItem); // Colonne 6 : "View QRcode"
    }
}

/*--------------MACHINE FUNCTIONS---------------*/

void management::on_ajouter_clicked()
{
    int machineID = ui->lineEdit_ID_2->text().toInt();
    int serialNumber = ui->lineEdit_SerialNumber_2->text().toInt();
    int FactoryID = ui->lineEdit_Factory_2->text().toInt();
    QString type = ui->comboBox_type_2->currentText(); // Get selected type
      QString machineStatus = ui->comboBox_status_2->currentText(); // Get selected status
    QString lastMaintenanceDate = ui->lineEdit_Maintenance_2->text();
    machine m(machineID, serialNumber, FactoryID, type, machineStatus, lastMaintenanceDate);
    bool test = m.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(ma.afficher());

    }
    else
    {
         QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void management::on_delete_2_clicked()
{
    // Get the selected row
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("No row selected.\nPlease select a machine to delete."));
        return;
    }

    // Assuming the MachineID is in the first column
    QModelIndex selectedIndex = selectedRows.first(); // Get the first selected row
    int MachineID = ui->tableView->model()->data(selectedIndex).toInt(); // Retrieve MachineID

    // Confirm deletion
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirm Delete"),
                                  tr("Are you sure you want to delete the selected machine?"),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Attempt to delete the machine
        bool success = ma.supprimer(MachineID);

        if (success) {
            QMessageBox::information(this, tr("Success"), tr("Machine deleted successfully."));

            // Refresh the table view
            ui->tableView->setModel(ma.afficher());
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to delete the machine."));
        }
    }
}

void management::on_pushButton_22_clicked()
{
    int MachineID=ui->lineEdit_7->text().toInt();
    bool success=ma.search(MachineID);
    if (success)
            {
                QMessageBox::information(this, tr("Success"), tr("Machine founded.\nClick Cancel to exit."), QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(this, tr("Error"), tr("Failed to find the machine.\nClick Cancel to exit."), QMessageBox::Cancel);
            }
}


void management::on_pushButton_23_clicked()
{
    int MachineID=ui->lineEdit_7->text().toInt();
    int FactoryID = ui->lineEdit_Factory_2->text().toInt();
    int SerialNumber = ui->lineEdit_SerialNumber_2->text().toInt();
    QString type = ui->lineEdit_type_3->text();
    QString machineStatus = ui->lineEdit_status_3->text();
    QString lastMaintenanceDate = ui->lineEdit_Maintenance_2->text();
    machine m( MachineID,  SerialNumber,  FactoryID,  type,  machineStatus,  lastMaintenanceDate);
    bool success=m.update(MachineID, SerialNumber, FactoryID, type, machineStatus, lastMaintenanceDate);
    if (success)
            {
                QMessageBox::information(this, tr("Success"), tr("Machine updated.\nClick Cancel to exit."), QMessageBox::Cancel);

            }
     else
     {
                QMessageBox::critical(this, tr("Error"), tr("Failed to update the machine.\nClick Cancel to exit."), QMessageBox::Cancel);
            }

}






void management::on_pushButton_11_clicked()
{
    bool success = ma.exporterPDF();
    if(success)
    {
        QMessageBox::information(this, "Succès",
            "Le fichier PDF a été généré avec succès");
    }
    else
    {
        QMessageBox::critical(this, "Erreur",
            "Échec de la génération du fichier PDF");
    }
}




void management::on_pushButton_12_clicked()

{
    machine m;

    // Get the selected sorting criteria from the combo box
    QString criteria = ui->comboBox_2->currentText();
    QSqlQueryModel* sortedModel = m.trierPar(criteria);

    if (sortedModel->rowCount() > 0) {
        ui->tableView->setModel(sortedModel);
        QMessageBox::information(this, "Success", QString("Machines sorted by %1.").arg(criteria));
    } else {
        QMessageBox::warning(this, "Error", "No data available to sort.");
    }
}

void management::on_pushButton_13_clicked()
{
    machine m;  // Create the machine object

    // Load data into the table
    QSqlQueryModel* model = m.loadDataIntoTable();

    if (model) {
        ui->tableView->setModel(model);  // Set the model to the table view
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to load Machine data."));  // Error message if loading failed
    }
}




void management::afficherPourcentages()
{
    machine m;

    // Create a persistent dialog instead of using QMessageBox
    QDialog* statsDialog = new QDialog(this);
    statsDialog->setWindowTitle("Machine Statistics");
    statsDialog->setMinimumSize(800, 600);

    // Create layout for dialog
    QVBoxLayout* mainLayout = new QVBoxLayout(statsDialog);

    // Create widget for statistics
    QWidget* statsWidget = new QWidget(statsDialog);

    // Update statistics display
    m.updateStatisticsDisplay(statsWidget);

    // Add widgets to layout
    mainLayout->addWidget(statsWidget);

    // Add OK button at bottom
    QPushButton* okButton = new QPushButton("OK", statsDialog);
    mainLayout->addWidget(okButton);

    // Connect OK button to close dialog
    connect(okButton, &QPushButton::clicked, statsDialog, &QDialog::accept);

    // Show dialog as modal
    statsDialog->exec();

    // Clean up
    delete statsDialog;
}
void management::on_pushButton_7_clicked()
{
    afficherPourcentages();
}







void management::on_pushButton_16_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel(this);
    QString searchValue = ui->lineEdit_3->text();
    QSqlQuery query;

    // Determine the search criteria based on the selected combo box option
    QString searchColumn;
    if (ui->comboBox->currentText() == "Serial Number")
    {
        searchColumn = "SERIAL_NUMBER";
    }
    else if (ui->comboBox->currentText() == "Last Maintenance Date")
    {
        searchColumn = "LAST_MAINTENANCE_DATE";
    }
    else // Default to "ID" (Machine ID)
    {
        searchColumn = "MACHINEID";
    }

    // Prepare the search query
    QString queryString = QString("SELECT MACHINEID, SERIAL_NUMBER, TYPE, MACHINE_STATUS, LAST_MAINTENANCE_DATE, FACTORY_ID FROM MACHINE WHERE %1 = :searchValue").arg(searchColumn);
    query.prepare(queryString);

    // Bind the value as an integer for MachineID or Serial Number, and as a string for Date
    if (searchColumn == "LAST_MAINTENANCE_DATE")
    {
        query.bindValue(":searchValue", searchValue); // Assuming date format is correct in input
    }
    else
    {
        query.bindValue(":searchValue", searchValue.toInt());
    }

    // Execute the query and display the results
    if (query.exec() && query.next())
    {
        model->setQuery(std::move(query));

        // Set headers
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("MACHINEID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIAL_NUMBER"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("MACHINE_STATUS"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("LAST_MAINTENANCE_DATE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("FACTORY_ID"));

        // Display the model in the table view
        ui->tableView->setModel(model);

        QMessageBox::information(this, tr("Success"), tr("Machine found.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        delete model;

        QMessageBox::critical(this, tr("Error"), tr("Failed to find the machine.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}
void management::on_pushButton_25_clicked()
{
    machine m;  // Create an instance of the machine class
    QSqlQueryModel* maintenanceModel = m.machinesToPlanMaintenance();
    ui->tableView_4->setModel(maintenanceModel);

    if (maintenanceModel->rowCount() == 0) {
        QMessageBox::information(this, "Planifier la maintenance", "Aucune machine ne nécessite de maintenance pour le moment.");
    }
}



void management::on_tableView_4_clicked(const QModelIndex &index)
{
    int column = index.column();
    int row = index.row();

    // Check if the column corresponds to "Status"
    if (column == 3) { // "MACHINE_STATUS" is in the 4th column (index 3)
        // Get the Machine ID from the first column of the same row
        int machineId = ui->tableView_4->model()->data(ui->tableView_4->model()->index(row, 0)).toInt();

        // Create and show the maintenance calendar directly
        MaintenanceCalendar *calendar = new MaintenanceCalendar(machineId, this);
        if (calendar->exec() == QDialog::Accepted) {
            // Refresh the table view to show the updated maintenance date
            machine m;
            ui->tableView_4->setModel(m.getScheduledMaintenance());
            updateCalendarHighlights(); // Update calendar highlights
        }
        delete calendar;
    }
}

void management::loadTableData()
{
    machine machineInstance;
    QSqlQueryModel *model = machineInstance.loadDataIntoTable();
    if (model) {
        ui->tableView_4->setModel(model);
        updateCalendarHighlights(); // <-- Add this line
    } else {
        QMessageBox::warning(this, "Error", "Impossible de recharger les données du tableau !");
    }
}
void management::showMaintenanceCalendar(const QModelIndex &index)
{
    // Check if clicked column is MACHINE_STATUS
    if (index.column() == 3) { // 3 is the MACHINE_STATUS column
        // Get the machine ID from the first column of the same row
        int machineId = ui->tableView_4->model()->index(index.row(), 0).data().toInt();

        // Create and show the maintenance calendar
        MaintenanceCalendar *calendar = new MaintenanceCalendar(machineId, this);
        if (calendar->exec() == QDialog::Accepted) {
            // Refresh the table view to show the updated maintenance date
            machine m;
            ui->tableView_4->setModel(m.getScheduledMaintenance());
        }
        delete calendar;
    }
}
void management::loadMaintenanceDates()
{
    updateCalendarHighlights();
}

void management::highlightMaintenanceDate(const QDate& date)
{
    QTextCharFormat format;
    format.setBackground(QColor(144, 238, 144));  // Light green
    format.setForeground(Qt::black);
    ui->calendarWidget_3->setDateTextFormat(date, format);
}

void management::updateCalendarHighlights()
{
    qDebug() << "Starting updateCalendarHighlights()";

    // Ensure database connection is open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database connection is not open!";
        return;
    }

    // Clear existing highlights
    ui->calendarWidget_3->setDateTextFormat(QDate(), QTextCharFormat());
    maintenanceDateToMachineIds.clear();

    QSqlQuery query;
    query.prepare("SELECT MACHINEID, NEXT_MAINTENANCE_DATE FROM MACHINE WHERE NEXT_MAINTENANCE_DATE IS NOT NULL");

    if (query.exec()) {
        qDebug() << "Query executed successfully";
        while (query.next()) {
            int machineId = query.value(0).toInt();
            QString dateStr = query.value(1).toString();

            qDebug() << "Machine ID:" << machineId << "Date:" << dateStr;

            QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");

            if (date.isValid()) {
                QTextCharFormat format;
                format.setBackground(QColor(144, 238, 144));
                format.setForeground(Qt::black);

                ui->calendarWidget_3->setDateTextFormat(date, format);
                maintenanceDateToMachineIds[date].append(machineId);
            } else {
                qDebug() << "Invalid date format:" << dateStr;
            }
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }
}

void management::diagnose(int selectedMachineId)
{
    // Get the selected symptoms from the listWidget_2
    QStringList selectedSymptoms;
    for (int i = 0; i < ui->listWidget_3->count(); ++i)
    {
        if (ui->listWidget_3->item(i)->checkState() == Qt::Checked) {
            selectedSymptoms.append(ui->listWidget_3->item(i)->text());
        }
    }

    // Generate the diagnostic message
    QString diagnosticMessage = machineDiagnostic(selectedSymptoms, selectedMachineId);

    // Display the diagnostic message in the textEdit
    ui->textEdit_2->setPlainText(diagnosticMessage);
}





void management::on_pushButton_24_clicked()
{
    QString machineId = ui->lineEdit_8->text();
    QList<QListWidgetItem*> selectedItems = ui->listWidget_3->selectedItems();

    if (machineId.isEmpty()) {
        ui->textEdit_2->setText("Please enter or select a valid Machine ID.");
        return;
    }

    if (selectedItems.isEmpty()) {
        ui->textEdit_2->setText("No symptoms selected for diagnosis. Please select one or more symptoms.");
        return;
    }

    QStringList selectedSymptoms;
    for (QListWidgetItem* item : selectedItems) {
        selectedSymptoms.append(item->text());
    }

    QString diagnosis = performDiagnosis(selectedSymptoms, machineId);
    ui->textEdit_2->setText(diagnosis);
}

QString management::performDiagnosis(const QStringList& symptoms, const QString& machineId)
{
    if (symptoms.isEmpty()) {
        return QString("Machine with the ID %1:\n"
                       "No symptoms selected for diagnosis. Please select one or more symptoms.")
            .arg(machineId);
    }

    // Call the detailed diagnosis function
    QString detailedDiagnosis = machineDiagnostic(symptoms, machineId.toInt());
    return detailedDiagnosis;
}
//----------------FACTORY--------------------------------------------------------------------------------------------------------------//

void management::on_factories_clicked()
{
    ui->main->setCurrentWidget(ui->factory);
}
void management::on_add_clickedF()
{
    ui->main->setCurrentWidget(ui->ajout_2);
}

void management::on_annuler_clickedF()
{
    ui->main->setCurrentWidget(ui->principale_2);
}

void management::on_sup_clickedF()
{
    ui->main->setCurrentWidget(ui->suppression_2);
}

void management::on_cancel_clickedF()
{
    ui->main->setCurrentWidget(ui->principale_2);
}

void management::on_update_clickedF()
{
    ui->main->setCurrentWidget(ui->modif_2);
}

// Search for the update and show old data
void management::on_ajout_cl_2_clickedF()
{
    int idf = ui->search_6->text().toInt();

    // Check if the factory exists
    if (fa.search(idf) && fa.getFactoryData(idf)) {
        // Populate UI fields with the old data
        ui->chi_2->setText(QString::number(fa.getidc()));
        ui->totm_2->setText(QString::number(fa.gettot_m()));
        ui->tote_2->setText(QString::number(fa.gettot_e()));
        ui->cap_2->setText(QString::number(fa.getcapacity()));
        ui->loc_2->setText(fa.getlocation());

        // Switch to update page
        ui->StackedWidget->setCurrentWidget(ui->update_if_2);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Try another ID"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

// Modification of information
void management::on_update_2_clickedF()
{
    int idf = ui->search_6->text().toInt();
    int idc = ui->chi_2->text().toInt();
    int tot_m = ui->totm_2->text().toInt();
    int tot_e = ui->tote_2->text().toInt();
    int capacity = ui->cap_2->text().toInt();
    QString location = ui->loc_2->text();

    bool test = fa.update(idf, idc, tot_e, tot_m, capacity, location);
    if (test) {
        ui->tableView_2->setModel(fa.afficher());
        updateFactoryCountF();  // Update the factory count after update
        QMessageBox::information(nullptr, QObject::tr("Update"),
                                 QObject::tr("Updated successfully.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Won't be Updated"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void management::on_cancl_clickedF()
{
    ui->main->setCurrentWidget(ui->principale_2);
}

void management::on_annuler_2_clickedF()
{
    ui->main->setCurrentWidget(ui->principale_2);
}

// Deleting an item from the database
void management::on_delete_2_clickedF()
{
    int id = ui->id_sup_2->text().toInt();

    bool test = fa.supprimer(id);
    if (test) {
        ui->tableView_2->setModel(fa.afficher());
        updateFactoryCountF();  // Update the factory count after deletion
        QMessageBox::information(nullptr, QObject::tr("Delete"),
                                 QObject::tr("The item was deleted successfully.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Won't be Deleted"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void management::on_ajout_cl_clickedF()
{
    int idf = ui->idf_2->text().toInt();
    int idc = ui->idc_2->text().toInt();
    int tot_m = ui->tot_m_2->text().toInt();
    int tot_e = ui->tot_e_2->text().toInt();
    int capacity = ui->capacity_2->text().toInt();
    QString location = ui->location_2->text();

    factory c(idf, idc, tot_e, tot_m, capacity, location);
    bool test = c.ajouter();
    if (test) {
        ui->tableView_2->setModel(fa.afficher());
        updateFactoryCountF();  // Update the factory count after adding
        QMessageBox::information(nullptr, QObject::tr("Add Successful"),
                                 QObject::tr("Client added successfully.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Won't be added"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

// New method to handle PDF export when the button is clicked
void management::on_pdfButton_clickedF()
{
    // Call the PDF export function from the factory class
    fa.pdf_downloader();

    // Show a success message
    QMessageBox::information(this, "PDF Export", "Factory data has been successfully exported to a PDF.");
}

void management::on_filterButton_clickedF()
{
    QString selectedCriteria = ui->filterComboBox->currentText(); // Critère sélectionné

    QString query;
    if (selectedCriteria == "factory_id") {
        query = "SELECT * FROM FACTORY ORDER BY FACTORY_ID ASC";
    } else if (selectedCriteria == "total_employees") {
        query = "SELECT * FROM FACTORY ORDER BY TOTAL_EMPLOYEES ASC";
    } else if (selectedCriteria == "total_machines") {
        query = "SELECT * FROM FACTORY ORDER BY TOTAL_MACHINES ASC";
    }

    if (!query.isEmpty()) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("FACTORY_ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCATION"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITY"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOTAL_EMPLOYEES"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("TOTAL_MACHINES"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("CHEF_ID"));

        ui->tableView_2->setModel(model); // Mettez à jour l'affichage
    }
}

void management::on_searchLocation_textChangedF(const QString &searchText)
{
    QString query = "SELECT * FROM FACTORY WHERE LOCATION LIKE '%" + searchText + "%'";

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("FACTORY_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITY"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOTAL_EMPLOYEES"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TOTAL_MACHINES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CHEF_ID"));

    ui->tableView_2->setModel(model); // Update the table view to show filtered results
}

// Function to update the factory count
void management::updateFactoryCountF()
{
    QSqlQuery query("SELECT COUNT(*) FROM FACTORY");
    if (query.next()) {
        int count = query.value(0).toInt();
        ui->totalFactoriesLabel->setText(QString("Total Factories: %1").arg(count));  // Update the label
    }
}
// Slot to update progress bar value
void management::updateProgressBarF(int value)
{
    ui->progressBarStatistics->setValue(value); // Update the progress bar value
}

// Slot to handle the "Statistics" button click
void management::on_statisticButton_clickedF()
{
    // Get the selected location from the UI
    QString selectedLocation = ui->locationComboBox->currentText();  // Assuming there's a ComboBox for location

    // Query to count total number of factories
    QSqlQuery totalFactoriesQuery;
    totalFactoriesQuery.exec("SELECT COUNT(*) FROM FACTORY");
    totalFactoriesQuery.next();
    int totalFactories = totalFactoriesQuery.value(0).toInt();

    // Query to count the number of factories in the selected location
    QSqlQuery locationFactoriesQuery;
    locationFactoriesQuery.prepare("SELECT COUNT(*) FROM FACTORY WHERE LOCATION = :location");
    locationFactoriesQuery.bindValue(":location", selectedLocation);
    locationFactoriesQuery.exec();
    locationFactoriesQuery.next();
    int locationFactories = locationFactoriesQuery.value(0).toInt();

    if (totalFactories == 0) {
        QMessageBox::critical(this, "Error", "No factories found in the database.");
        return;
    }

    // Calculate the progress (percentage)
    int progressValue = static_cast<int>((static_cast<double>(locationFactories) / totalFactories) * 100);

    // Set the progress bar range and value
    ui->progressBarStatistics->setRange(0, 100);
    ui->progressBarStatistics->setValue(progressValue);

    // Display the location name and progress
    ui->locationLabel->setText("Location: " + selectedLocation); // Assuming you have a QLabel to show the location name
    ui->progressLabel->setText(QString::number(progressValue) + "%"); // Assuming you have a QLabel to show the progress percentage
}
void management::on_generateQRButton_clickedF()
{
    // Ask for the factory ID before proceeding
    bool ok;
    int factoryID = QInputDialog::getInt(this, tr("Enter Factory ID"),
                                         tr("Factory ID:"), 0, 0, 100000, 1, &ok);

    if (ok) {
        // Define the path to the Python executable and the script
        QString pythonExecutable = "python";  // Use "python3" as you manually did
        QString scriptPath = "C:/Users/saber/Desktop/karmouss/kol_chay_yemchi/Projet_CPP/projet_PCC_Factory/generate_qr.py";  // Ensure this path is correct
        QString outputImagePath = "C:/Users/saber/Documents/pdf_factory_test/factory_" + QString::number(factoryID) + "_qr.png";  // Set output path

        // Prepare the arguments to match the manual command format
        QStringList arguments;
        arguments << scriptPath << QString::number(factoryID) << outputImagePath;

        // Debugging outputs
        qDebug() << "Python Executable:" << pythonExecutable;
        qDebug() << "Script Path:" << scriptPath;
        qDebug() << "Output Image Path:" << outputImagePath;
        qDebug() << "Arguments:" << arguments;

        // Create a QProcess object to run the Python script
        QProcess process;

        // Set the working directory (optional, in case the script needs files from this directory)
        process.setWorkingDirectory("C:/Users/saber/Desktop/karmouss/kol_chay_yemchi/Projet_CPP/projet_PCC_Factory/");

        // Start the Python process with the provided arguments
        process.start(pythonExecutable, arguments);

        // Wait for the process to start
        if (!process.waitForStarted()) {
            qDebug() << "Failed to start the Python process.";
            return;
        }

        // Wait for the process to finish (up to 5 seconds)
        if (!process.waitForFinished(5000)) {
            qDebug() << "Python script execution timed out or failed.";
            return;
        }

        // Check Python process output and errors
        QByteArray output = process.readAllStandardOutput();
        QByteArray errorOutput = process.readAllStandardError();
        qDebug() << "Python Output:" << output;
        qDebug() << "Python Error Output:" << errorOutput;

        // Check if the output file was created successfully
        if (QFile::exists(outputImagePath)) {
            QImage image(outputImagePath);
            if (!image.isNull()) {
                // Set fixed width and height
                int targetWidth = 100;  // Desired width
                int targetHeight = 100; // Desired height

                // Resize the image to the fixed dimensions
                QPixmap pixmap = QPixmap::fromImage(image).scaled(targetWidth, targetHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                ui->qrImageLabel->setPixmap(pixmap);
                qDebug() << "QR code successfully displayed with fixed dimensions.";
            } else {
                qDebug() << "Failed to load QR code image.";
            }
        } else {
            qDebug() << "QR code image file does not exist.";
        }
    } else {
        qDebug() << "No valid Factory ID entered.";
    }
}

void management::on_displayQRButton_clickedF()
{
    // This function reuses the logic from on_generateQRButton_clicked.
    on_generateQRButton_clickedF();
}



























































//----------------------------------------------------------client--------------------------------------------------

void management::on_dahsboard_clicked()
{
    ui->main->setCurrentIndex(4);
    ui->Dashboard__1->setCurrentIndex(0);

}
void management::on_pushButton_6_clicked()
{
    ui->main->setCurrentIndex(3);
    ui->client->setCurrentIndex(0);

}


void management::on_ajout_cl_clicked()
{
    ui->main->setCurrentIndex(3);
    ui->client->setCurrentWidget(ui->add_client_22);
}
//add/
void management::on_add_clicked()
{
    int tot_ord = ui->total_ord_cl_6->text().toInt();
    QString adresse = ui->adress_cl_6->text();
    int id = ui->id_cl_6->text().toInt();
    QString name = ui->name_cl_6->text();
    QString email = ui->email_cl_6->text();
    int phone = ui->phone_cl_6->text().toInt();
    client c(id, name, phone, email, adresse, tot_ord);
    bool test=c.ajouter();
    qDebug()<< test;
    if(test)
    {
        ui->cb->setText(cl.count());
        ui->main->setCurrentIndex(3);
        ui->client->setCurrentIndex(0);

        // Refresh the table view
        ui->tableView_cl_3->setModel(cl.afficher());
        ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView_cl_3->setSortingEnabled(true);
        //ui->StackedWidget->setCurrentWidget(ui->principale);
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



void management::on_cancel_clicked()
{
    ui->main->setCurrentIndex(3);
    ui->client->setCurrentIndex(0);
    //loadDeliveriesIntoTable();
}



void management::on_update_clicked()
{
    ui->main->setCurrentIndex(3);
    ui->client->setCurrentWidget(ui->update_cl);

    QAbstractItemModel *model = ui->tableView_cl_3->model();

    QModelIndex currentIndex = ui->tableView_cl_3->selectionModel()->currentIndex();
    if (currentIndex.isValid()) {
        selectedClientId = model->data(currentIndex.siblingAtColumn(0)).toInt(); // Assign to member variable
        qDebug() << "Selected client ID:" << selectedClientId;

        QString adresse = model->data(currentIndex.siblingAtColumn(4)).toString();
        QString name = model->data(currentIndex.siblingAtColumn(1)).toString();
        QString email = model->data(currentIndex.siblingAtColumn(3)).toString();
        int phone = model->data(currentIndex.siblingAtColumn(2)).toInt();
        int total_orders = model->data(currentIndex.siblingAtColumn(5)).toInt();

        ui->adress_cl_25->setText(adresse);
        ui->email_cl_25->setText(email);
        ui->name_cl_25->setText(name);
        ui->phone_cl_25->setText(QString::number(phone));
        ui->total_ord_35->setText(QString::number(total_orders));
    } else {
        ui->main->setCurrentIndex(3);
        ui->client->setCurrentIndex(0);
        QMessageBox::critical(nullptr, QObject::tr("You must select"),
                              QObject::tr("No row selected.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

//modification des information

void management::on_update_2_clicked()
{
    if (selectedClientId == -1) {
        QMessageBox::critical(nullptr, QObject::tr("No client selected"),
                              QObject::tr("No valid client selected for update.\nClick Cancel to exit."), QMessageBox::Cancel);
        return;
    }

    QString adresse = ui->adress_cl_25->text();
    QString name = ui->name_cl_25->text();
    QString email = ui->email_cl_25->text();
    int phone = ui->phone_cl_25->text().toInt();
    int total_orders = ui->total_ord_35->text().toInt();

    qDebug() << "Selected Client ID:" << selectedClientId;

    // Call the update function in the client class
    bool test = cl.update(selectedClientId, name, phone, email, adresse, total_orders);

    if (test) {
        ui->main->setCurrentIndex(3);
        ui->client->setCurrentIndex(0);
        ui->cb->setText(cl.count());
        ui->tableView_cl_3->setModel(cl.afficher());
        ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView_cl_3->setSortingEnabled(true);

        QMessageBox::information(nullptr, QObject::tr("Update"),
                                  QObject::tr("Update successful.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Update Failed"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}




//ki ta5tar haja fel table view yfasa5ha

void management::on_selectid_clicked()
{
    int id=ui->tableView_cl_3->model()->data(ui->tableView_cl_3->selectionModel()->currentIndex().siblingAtColumn(0)).toInt();
    qDebug() << "Selected ID:" << id;
    if (id>0){
    bool test = cl.supprimer(id);
    if(test){
            ui->cb->setText(cl.count());

            ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            ui->tableView_cl_3->setSortingEnabled(true);

            ui->tableView_cl_3->setModel(cl.afficher());
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
    else{
        QMessageBox::critical(nullptr, QObject::tr("not founded"),
                    QObject::tr("You must select the Item that you want to Delete.\n"
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

    QModelIndex index = ui->tableView_cl_3->selectionModel()->currentIndex();
    if(index.isValid()){
            if(ui->cbb->currentText()=="Descend"){

                if(index.sibling(index.row(), 0).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_id_desc());
                }
                else if(index.sibling(index.row(), 1).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_name_desc());
                }
                else if(index.sibling(index.row(), 2).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_phone_desc());
                }

                else if(index.sibling(index.row(), 3).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_mail_desc());
                }

                else if(index.sibling(index.row(), 4).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_adresse_desc());
                }
                else if (index.sibling(index.row(), 5).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_tab_desc());

                }

        }
        else if(ui->cbb->currentText()=="Ascend"){
                if(index.sibling(index.row(), 0).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_id_ASC());
                }
                else if(index.sibling(index.row(), 1).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_name_ASC());
                }
                else if(index.sibling(index.row(), 2).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_phone_ASC());
                }

                else if(index.sibling(index.row(), 3).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_mail_ASC());
                }

                else if(index.sibling(index.row(), 4).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_adresse_ASC());
                }
                else if (index.sibling(index.row(), 5).data().toInt()){
                    ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    ui->tableView_cl_3->setSortingEnabled(true);

                    ui->tableView_cl_3->setModel(cl.trier_tab_ASC());

                }
        }
    }
    else {
        if(ui->cbb->currentText()=="Descend"){

               if(ui->choose->currentText()=="Client id"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_id_desc());
               }
               else if(ui->choose->currentText()=="Name"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_name_desc());
               }
               else if(ui->choose->currentText()=="Phone Number"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_phone_desc());
               }

               else if(ui->choose->currentText()=="E-mail"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_mail_desc());
               }

               else if(ui->choose->currentText()=="Adresse"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_adresse_desc());
               }
               else if (ui->choose->currentText()=="Total Orders"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_tab_desc());

               }

       }
       else if(ui->cbb->currentText()=="Ascend"){
            if(ui->choose->currentText()=="Client id"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_id_ASC());
               }
               else if(ui->choose->currentText()=="Name"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_name_ASC());
               }
               else if(ui->choose->currentText()=="Phone Number"){
                   ui->tableView_cl_3->setModel(cl.trier_phone_ASC());
               }

               else if(ui->choose->currentText()=="E-mail"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_mail_ASC());
               }

               else if(ui->choose->currentText()=="Adresse"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_adresse_ASC());
               }
               else if (ui->choose->currentText()=="Total Orders"){
                   ui->tableView_cl_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   ui->tableView_cl_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                   ui->tableView_cl_3->setSortingEnabled(true);

                   ui->tableView_cl_3->setModel(cl.trier_tab_ASC());

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



void management::on_searchConfirm2() {
    QString type = ui->cb_recherche_cl->currentText();  // Get selected search criteria
    QString searchText = ui->search_field_2->text();    // Get the text from the search field

    // Perform the search using the Client class
    client client;
    QStandardItemModel *model = client.rechercher(type, searchText);

    if (model) {
        if (model->rowCount() > 0) {
            // Set the model to the QTableView
            QTableView *tableView = ui->tableView_cl_3;
            tableView->setModel(model);

            // Adjust table view settings for better display
            tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            tableView->setSortingEnabled(true);  // Enable sorting

            qDebug() << "Real-time search results loaded.";
        } else {
            qDebug() << "No results found for search:" << searchText;
            // Optionally show a message to the user about no results
        }
    } else {
        qDebug() << "Error in search query or no data found.";
    }
}

void management::on_searchReset_2_clicked() {

    ui->search_field_2->clear();

    ui->tableView_cl_3->setModel(cl.afficher());

    ui->cb_recherche_cl->setCurrentIndex(0);
}
void management::on_search_field_2_textChanged(const QString &search_field_2) {

    on_searchConfirm2();
}

