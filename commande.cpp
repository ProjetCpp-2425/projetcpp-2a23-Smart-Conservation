#include "commande.h"
#include <QMessageBox>
#include "ui_commande.h"
#include <QDate>
#include <QDateTime>
#include <QSqlError>
#include <QDebug> // Include for debugging
#include <QSqlQueryModel>
#include <QTimer>
// partie excel
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
//stats
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QSqlQuery>
#include <QVBoxLayout>

commande::commande(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::commande)
{
    ui->setupUi(this);


    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);// tna7i edit 3al double click
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);// highliti row lkol
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//t5ali selection 3ala one row fi nafs wa9t

    ui->comboBox_Status->setCurrentIndex(0);
    // Fetch the updated data
    QSqlQuery query;
    query.exec("SELECT * FROM DELIVERY");

    QTimer::singleShot(1000, this, &commande::loadDeliveriesIntoTable); // ma 5edmet ken bl timer :')
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &commande::onTableWidgetRowSelected);

    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, &commande::filterTableByDeliveryId);

    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &commande::on_tableWidget_cellDoubleClicked);

    connect(ui->statsbutton, &QPushButton::clicked, this, &::commande::on_statsbutton_clicked);



}

commande::~commande()
{
    delete ui;
}

void commande::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void commande::on_pushButton_10_clicked()
{
    // Retrieve input values
    QString selectedStatus = ui->comboBox_Status->currentText();
    QString deliveryId = ui->lineEdit_DeliveryID->text();
    QString deliveryAddress = ui->lineEdit_deliveryAddress->text();
    QString clientId = ui->lineEdit_clientID->text();
    QString employeeId = ui->lineEdit_employeeID->text();
    QString deliveryDate = QDate::currentDate().toString("dd-MM-yy");

    // 1. Ensure DeliveryID starts with "D"
    if (!deliveryId.startsWith("D")) {
        QMessageBox::critical(this, "Error", "Delivery ID must start with the letter 'D'.");
        return;
    }

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

    ui->stackedWidget_2->setCurrentIndex(0);
}


Delivery::Delivery() {}

Delivery::Delivery(const QString &id, const QString &address, const QString &date, const QString &status, const QString &clientId, const QString &employeeId) :
    deliveryId(id), deliveryAddress(address), deliveryDate(date), status(status), clientId(clientId), employeeId(employeeId) {}

// Getters
QString Delivery::getId() const { return deliveryId; }
QString Delivery::getAddress() const { return deliveryAddress; }
QString Delivery::getDate() const { return deliveryDate; }
QString Delivery::getStatus() const { return status; }
QString Delivery::getClientId() const { return clientId; }
QString Delivery::getEmployeeId() const { return employeeId; }

// Setters
void Delivery::setId(const QString &id) { deliveryId = id; }
void Delivery::setAddress(const QString &address) { deliveryAddress = address; }
void Delivery::setDate(const QString &date) { deliveryDate = date; }
void Delivery::setStatus(const QString &status) { this->status = status; }
void Delivery::setClientId(const QString &clientId) { this->clientId = clientId; }
void Delivery::setEmployeeId(const QString &employeeId) { this->employeeId = employeeId; }

// Database functions
bool Delivery::add() {
    QSqlQuery query;
    query.prepare("INSERT INTO DELIVERY (DELIVERY_ID, DELIVERY_ADDRESS, DELIVERY_DATE, STATUS, CE_CLIENT_ID, CE_EMPLOYEE_ID) "
                  "VALUES (:id, :address, :date, :status, :clientId, :employeeId)");
    query.bindValue(":id", deliveryId);
    query.bindValue(":address", deliveryAddress);
    query.bindValue(":date", deliveryDate);
    query.bindValue(":status", status);
    query.bindValue(":clientId", clientId);
    query.bindValue(":employeeId", employeeId);

    if (!query.exec()) {
        qDebug() << "Preparing to execute query with values:";
        qDebug() << "Delivery Address:" << deliveryAddress;
        qDebug() << "Delivery Date:" << deliveryDate;
        qDebug() << "Client ID:" << clientId;
        // Other fields as needed

        qDebug() << "Failed to execute query:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Delivery::update(const QString &oldId) {
    QSqlQuery query;
    query.prepare("UPDATE DELIVERY SET DELIVERY_ID=:newId, DELIVERY_ADDRESS=:address, DELIVERY_DATE=:date, "
                  "STATUS=:status, CE_CLIENT_ID=:clientId, CE_EMPLOYEE_ID=:employeeId WHERE DELIVERY_ID=:oldId");
    query.bindValue(":newId", deliveryId); // Use the new Delivery ID
    query.bindValue(":oldId", oldId);      // Use the original Delivery ID to identify the record
    query.bindValue(":address", deliveryAddress);
    query.bindValue(":date", deliveryDate);
    query.bindValue(":status", status);
    query.bindValue(":clientId", clientId);
    query.bindValue(":employeeId", employeeId);

    return query.exec();
}


QSqlQueryModel* Delivery::display() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM DELIVERY");
    return model;
}

void commande::on_edit_table_button_clicked()
{

    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Edit Error", "Please select a delivery to edit.");
        return;
    }

    // Fill the form with the selected delivery's data
    ui->lineEdit_DeliveryID->setText(ui->tableWidget->item(row, 0)->text());
    ui->lineEdit_deliveryAddress->setText(ui->tableWidget->item(row, 1)->text());
    ui->comboBox_Status->setCurrentText(ui->tableWidget->item(row, 3)->text());
    ui->lineEdit_clientID->setText(ui->tableWidget->item(row, 4)->text());
    ui->lineEdit_employeeID->setText(ui->tableWidget->item(row, 5)->text());

    // Set edit mode to true and store the ID of the delivery being edited
    isEditMode = true;
    currentDeliveryId = ui->lineEdit_DeliveryID->text();
    loadDeliveriesIntoTable();

    // Switch to the edit view
    ui->stackedWidget_2->setCurrentIndex(1);}


void commande::on_button_delete_clicked()
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
// debut
void commande::loadDeliveriesIntoTable() {
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



//fin


void commande::on_return_main_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void commande::on_export_table_clicked()
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


void commande::filterTableByDeliveryId(const QString &searchText)
{
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        bool matches = ui->tableWidget->item(row, 0)->text().startsWith(searchText, Qt::CaseInsensitive);
        ui->tableWidget->setRowHidden(row, !matches);
    }
}

void commande::on_tableWidget_cellDoubleClicked(int row, int column) {
    qDebug() << "Cell double-clicked: row=" << row << ", column=" << column;

    // Check if the column matches the status column index (e.g., replace 3 with the actual index of the status column)
    if (column == 2) {
        qDebug() << "Status column double-clicked, changing stackedWidget index to 2";

        // Change the stacked widget to index 2
        ui->stackedWidget_2->setCurrentIndex(2);

        // Get the status from the clicked row (not from the comboBox)
        QString status = ui->tableWidget->item(row, 2)->text();
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
        QString status = ui->tableWidget->item(row, 2)->text(); // Statut dans la colonne 3 (ajustez si nécessaire)

        // Changer l'index de stackedWidget_2 en fonction du statut
        if (status == "Delivered") {
            ui->stackedWidget_2->setCurrentIndex(5);
        } else if (status == "In Progress") {
            ui->stackedWidget_2->setCurrentIndex(4);
        } else if (status == "Ordered") {
            ui->stackedWidget_2->setCurrentIndex(3);
        } else {
            QMessageBox::warning(this, "Error", "Unknown status: " + status);
        }
    }
}


void commande::on_pushButton_2_clicked()// button el retour ta3 page timeline
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


// Slot to update the date and time when the status changes
void commande::onTableWidgetRowSelected(int row, int column) {
    Q_UNUSED(column);

    QTableWidgetItem *statusItem = ui->tableWidget->item(row, 2); // Adjust index based on actual column number
    if (statusItem) {
        QString status = statusItem->text();
        QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

        if (status == "Ordered") {
            ui->label_ordered->setText(currentDateTime);
        } else if (status == "In Progress") {
            ui->label_in_progress->setText(currentDateTime);
        } else if (status == "Delivered") {
            ui->label_delivered->setText(currentDateTime);
        }
    }
}

void commande::on_back_qrcode_ordered_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void commande::on_back_qrcode_in_progress_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void commande::on_back_qrcode_delivered_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}




void commande::on_statsbutton_clicked()
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
