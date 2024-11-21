#include "mainwindow.h"
#include "maintenancecalendar.h"
#include "ui_mainwindow.h"
#include <machine.h>
#include <QDebug>
#include <QMessageBox>
#include<QSqlDatabase>


#include <QFileDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [this](int index) {
            if (index == 6) { // Maintenance planning tab
                updateCalendarHighlights();
            }
        });

    connect(ui->tableView_2, &QTableView::clicked,
                this, &MainWindow::showMaintenanceCalendar);


    // Load maintenance dates when showing the maintenance planning tab
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [this](int index) {
        if (index == 6) { // Maintenance planning tab
            loadMaintenanceDates();
        }
    });  // Fixed: Added missing closing parenthesis

    ui->tabWidget->setTabText(0, "Main Page");
    ui->tabWidget->setTabText(1, "Adding");
    ui->tabWidget->setTabText(2, "searching");
    ui->tabWidget->setTabText(3, "statistics");
    ui->tabWidget->setTabText(4, "deleting");
    ui->tabWidget->setTabText(5, "modifying");
    ui->tabWidget->setTabText(6, "maintenance planifying");
    ui->tabWidget->setTabText(7, "Diagnostic");

    initializeUI();
    ui->tableView->setModel(ma.afficher());

    connect(ui->pushButton_13, &QPushButton::clicked,
            this, &MainWindow::on_pushButton_13_clicked);


    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [this](int index)
    {
        if (index == 6) { // Maintenance planning tab
            updateCalendarHighlights();
        }
    });
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::on_pushButton_15_clicked);





}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initializeUI()
{
    // Configuration initiale de la fenêtre
    this->setWindowTitle("Terra Nova");
    this->setMinimumSize(800, 600);
       ui->listWidget_2->addItem("Overheating");
       ui->listWidget_2->addItem("Power Loss");
       ui->listWidget_2->addItem("Unusual noise");
       ui->listWidget_2->addItem("Frequent shutdowns");
       ui->listWidget_2->addItem("Battery draining");
       ui->listWidget_2->addItem("Display not working");
       ui->listWidget_2->addItem("Electrical sparks");
       ui->listWidget_2->addItem("Slow operation");
       ui->listWidget_2->addItem("Vibrations");
}

void MainWindow::on_ajouter_clicked()
{
    int machineID = ui->lineEdit_ID->text().toInt();
    int serialNumber = ui->lineEdit_serialNumber->text().toInt();
    int FactoryID = ui->lineEdit_factory->text().toInt();
    QString type = ui->lineEdit_type->text();
    QString machineStatus = ui->lineEdit_status->text();
    QString lastMaintenanceDate = ui->lineEdit_Maintenance->text();
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

void MainWindow::on_delete_2_clicked()
{
    int MachineID = ui->lineEdit_ID->text().toInt();
    bool success = ma.supprimer(MachineID);
    if (success)
    {
        QMessageBox::information(this, tr("Success"), tr("Machine deleted successfully.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(ma.afficher());

    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Failed to delete the machine.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    int MachineID=ui->lineEdit_2->text().toInt();
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


void MainWindow::on_pushButton_9_clicked()
{
    int MachineID=ui->lineEdit_2->text().toInt();
    int FactoryID = ui->lineEdit_factory_2->text().toInt();
    int SerialNumber = ui->lineEdit_serialNumber_2->text().toInt();
    QString type = ui->lineEdit_type_2->text();
    QString machineStatus = ui->lineEdit_status_2->text();
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






void MainWindow::on_pushButton_10_clicked()
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




void MainWindow::on_pushButton_12_clicked()

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

void MainWindow::on_pushButton_13_clicked()
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




void MainWindow::afficherPourcentages()
{
    machine m;  // Créer un objet machine pour appeler la fonction
    QPair<int, int> pourcentages = m.calculerPourcentages();

    // Mettre à jour les barres de progression
    ui->progressBar_3->setValue(pourcentages.first);
    ui->progressBar->setValue(pourcentages.second);

    // Optionnel: afficher un message d'information
    QString message = QString("Working: %1%, Not Working: %2%")
                          .arg(pourcentages.first)
                          .arg(pourcentages.second);
    QMessageBox::information(this, "Pourcentages des machines", message);
}
void MainWindow::on_pushButton_7_clicked()
{
    afficherPourcentages();
}







void MainWindow::on_pushButton_16_clicked()
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
        ui->tableView_3->setModel(model);

        QMessageBox::information(this, tr("Success"), tr("Machine found.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        delete model;

        QMessageBox::critical(this, tr("Error"), tr("Failed to find the machine.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_11_clicked()
{
    machine m;  // Create an instance of the machine class
    QSqlQueryModel* maintenanceModel = m.machinesToPlanMaintenance();
    ui->tableView_2->setModel(maintenanceModel);

    if (maintenanceModel->rowCount() == 0) {
        QMessageBox::information(this, "Planifier la maintenance", "Aucune machine ne nécessite de maintenance pour le moment.");
    }
}



void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    int column = index.column();
    int row = index.row();

    // Vérifiez si la colonne correspond à "État"
    if (column == 3) { // "MACHINE_STATUS" est dans la 4e colonne (index 3)
        QString machineId = ui->tableView_2->model()->data(ui->tableView->model()->index(row, 0)).toString();
        QString lastMaintenanceDate = ui->tableView_2->model()->data(ui->tableView->model()->index(row, 4)).toString();

        // Générer une date de maintenance par défaut : aujourd'hui + 1 an
        QDate nextMaintenanceDate = QDate::currentDate().addYears(1);

        if (!lastMaintenanceDate.isEmpty()) {
            QDate lastDate = QDate::fromString(lastMaintenanceDate, "dd/MM/yyyy");
            if (lastDate.isValid()) {
                nextMaintenanceDate = lastDate.addYears(1);
            }
        }

        // Ouvrir une boîte de dialogue pour saisir ou confirmer la date de maintenance
        QString selectedDateStr = QInputDialog::getText(this, "Planifier la maintenance",
                                                        "Entrez la date de maintenance (dd/MM/yyyy) :",
                                                        QLineEdit::Normal, nextMaintenanceDate.toString("dd/MM/yyyy"));

        // Vérifier la validité de la date saisie
        QDate selectedDate = QDate::fromString(selectedDateStr, "dd/MM/yyyy");
        if (!selectedDateStr.isEmpty() && selectedDate.isValid()) {
            // Mettre à jour la date de maintenance dans la base de données
            QSqlQuery query;
            query.prepare("UPDATE MACHINE SET NEXT_MAINTENANCE_DATE = :date WHERE MACHINEID = :id");
            query.bindValue(":date", selectedDate.toString("dd/MM/yyyy"));
            query.bindValue(":id", machineId);

            if (query.exec()) {
                QMessageBox::information(this, "Succès", "Date de maintenance mise à jour avec succès !");
                // Rechargez les données du tableau
                loadTableData(); // Vérifiez que cette méthode existe
            } else {
                QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour de la date de maintenance !");
            }
        } else {
            QMessageBox::warning(this, "Erreur", "Date invalide ou action annulée !");
        }
    }
}

void MainWindow::loadTableData()
{
    machine machineInstance;
    QSqlQueryModel *model = machineInstance.loadDataIntoTable();
    if (model) {
        ui->tableView_2->setModel(model);
        updateCalendarHighlights(); // <-- Add this line
    } else {
        QMessageBox::warning(this, "Error", "Impossible de recharger les données du tableau !");
    }
}
void MainWindow::showMaintenanceCalendar(const QModelIndex &index)
{
    // Check if clicked column is MACHINE_STATUS
    if (index.column() == 3) { // 3 is the MACHINE_STATUS column
        // Get the machine ID from the first column of the same row
        int machineId = ui->tableView_2->model()->index(index.row(), 0).data().toInt();

        // Create and show the maintenance calendar
        MaintenanceCalendar *calendar = new MaintenanceCalendar(machineId, this);
        if (calendar->exec() == QDialog::Accepted) {
            // Refresh the table view to show the updated maintenance date
            machine m;
            ui->tableView_2->setModel(m.getScheduledMaintenance());
        }
        delete calendar;
    }
}
void MainWindow::loadMaintenanceDates()
{
    updateCalendarHighlights();
}

void MainWindow::highlightMaintenanceDate(const QDate& date)
{
    QTextCharFormat format;
    format.setBackground(QColor(144, 238, 144));  // Light green
    format.setForeground(Qt::black);
    ui->calendarWidget_2->setDateTextFormat(date, format);
}

void MainWindow::updateCalendarHighlights()
{
    qDebug() << "Starting updateCalendarHighlights()";

    // Ensure database connection is open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database connection is not open!";
        return;
    }

    // Clear existing highlights
    ui->calendarWidget_2->setDateTextFormat(QDate(), QTextCharFormat());
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

                ui->calendarWidget_2->setDateTextFormat(date, format);
                maintenanceDateToMachineIds[date].append(machineId);
            } else {
                qDebug() << "Invalid date format:" << dateStr;
            }
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }
}

void MainWindow::diagnose(int selectedMachineId)
{
    // Get the selected symptoms from the listWidget_2
    QStringList selectedSymptoms;
    for (int i = 0; i < ui->listWidget_2->count(); ++i)
    {
        if (ui->listWidget_2->item(i)->checkState() == Qt::Checked) {
            selectedSymptoms.append(ui->listWidget_2->item(i)->text());
        }
    }

    // Generate the diagnostic message
    QString diagnosticMessage = machineDiagnostic(selectedSymptoms, selectedMachineId);

    // Display the diagnostic message in the textEdit
    ui->textEdit->setPlainText(diagnosticMessage);
}





void MainWindow::on_pushButton_15_clicked()//diagnose button
{
    qDebug() << "Diagnose button clicked";
        QString machineId = ui->lineEdit_4->text();
        qDebug() << "Machine ID:" << machineId;

        QList<QListWidgetItem*> selectedItems = ui->listWidget_2->selectedItems();
        qDebug() << "Number of symptoms selected:" << selectedItems.size();

    qDebug() << "Diagnose button clicked"; // Log entry
    // Get the list of selected items from the QListWidget


    // Check if no items are selected
    if (selectedItems.isEmpty()) {
        ui->textEdit->setText("No symptoms selected for diagnosis. Please select one or more symptoms.");
        return;
    }

    // Collect selected symptoms into a QStringList
    QStringList selectedSymptoms;
    for (QListWidgetItem* item : selectedItems) {
        selectedSymptoms.append(item->text());
    }

    // Retrieve the machine ID from QLineEdit (e.g., lineEditMachineId)
    QString selectedMachineId = ui->lineEdit_4->text();

    // Check if the machine ID is empty
    if (selectedMachineId.isEmpty()) {
        ui->textEdit->setText("Please enter or select a valid Machine ID.");
        return;
    }

    // Display the selected symptoms for debugging
    qDebug() << "Selected Symptoms:" << selectedSymptoms;

    // Perform diagnosis based on selected symptoms
    QString diagnosis = performDiagnosis(selectedSymptoms, selectedMachineId);

    // Display the diagnosis in the textEdit
    ui->textEdit->setText(diagnosis);
}
QString MainWindow::performDiagnosis(const QStringList& symptoms, const QString& machineId)
{
    // Map symptoms to their possible problems
    QMap<QString, QString> symptomDiagnosis = {
        {"Overheating", "The machine may have a cooling system issue or needs maintenance."},
        {"Power Loss", "The machine's power supply or electrical components may be malfunctioning."},
        {"Unusual noise", "There could be a mechanical issue causing wear or misalignment."},
        {"Frequent shutdowns", "The machine might have a software or hardware fault."},
        {"Battery draining", "Inspect the battery or charging system for potential failures."},
        {"Display not working", "There could be an issue with the display unit or its connection."},
        {"Electrical sparks", "Possible short circuits or damaged electrical wiring."},
        {"Slow operation", "The machine might be overloaded or require software updates."},
        {"Vibrations", "Check for loose components or imbalanced moving parts."}
    };

    // Initialize a QString to collect diagnosis results
    QString diagnosis;

    // Loop through the selected symptoms and find their corresponding diagnoses
    for (const QString& symptom : symptoms) {
        if (symptomDiagnosis.contains(symptom)) {
            diagnosis += " - " + symptom + ": " + symptomDiagnosis[symptom] + "\n";
        } else {
            diagnosis += " - " + symptom + ": Diagnosis not found for this symptom.\n";
        }
    }

    // If no valid diagnoses were added, return a default message
    if (diagnosis.isEmpty()) {
        return QString("Machine with the ID %1:\n"
                       "Diagnostic Result:\n"
                       " - No symptoms selected for diagnosis. Please select one or more symptoms.")
            .arg(machineId);
    }

    // Construct the final formatted output
    return QString("Machine with the ID %1:\n"
                   "Diagnostic Result:\n%2")
        .arg(machineId)
        .arg(diagnosis);
}
