#include "management.h"
#include "commande.h"
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

    //commande
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);// tna7i edit 3al double click
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);// highliti row lkol
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//t5ali selection 3ala one row fi nafs wa9t
    ui->comboBox_Status->setCurrentIndex(0);
    QSqlQuery query;
    query.exec("SELECT * FROM DELIVERY");
    QTimer::singleShot(1000, this, &management::loadDeliveriesIntoTable); // ma 5edmet ken bl timer :')
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &management::onTableWidgetRowSelected);
    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, &management::filterTableByDeliveryId);
    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &management::on_tableWidget_cellDoubleClicked);
    connect(ui->statsbutton, &QPushButton::clicked, this, &::management::on_statsbutton_clicked);
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
