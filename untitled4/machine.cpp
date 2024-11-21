#include "machine.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QRegularExpression>
#include <QSqlQueryModel>
#include "connection.h"
#include<QSqlDatabase>

#include <QFileDialog>




machine::machine(int MachineID, int SerialNumber, int FactoryID, QString Type, QString MachineStatus, QString LastMaintenanceDate)
{
    this->MachineID = MachineID;
    this->SerialNumber = SerialNumber;
    this->FactoryID =FactoryID;
    this->Type = Type;
    this->MachineStatus = MachineStatus;
    this->LastMaintenanceDate  = LastMaintenanceDate;
}


bool machine::ajouter()
{
    QSqlQuery query;

    QString machineIDStr = QString::number(MachineID);
    QString serialNumberStr = QString::number(SerialNumber);
    QString FactoryIDStr = QString::number(FactoryID);

    // Input validation checks
    if (machineIDStr.length() != 6)
    {
        QMessageBox::warning(nullptr, "ERROR ADD", "Id must contain exactly 6 digits.");
        return false;
    }
    if (serialNumberStr.length() != 6 )
    {
        QMessageBox::warning(nullptr, "ERROR ADD", "Phone must contain exactly 6 digits.");
        return false;
    }

    QStringList dateParts = LastMaintenanceDate.split("/");
    if (dateParts.size() != 3 ||
        (!dateParts[0].isEmpty() && (dateParts[0].toInt() < 1 || dateParts[0].toInt() > 31)) ||
        (!dateParts[1].isEmpty() && (dateParts[1].toInt() < 1 || dateParts[1].toInt() > 12)) ||
        (!dateParts[2].isEmpty() && (dateParts[2].toInt() < 1900 || dateParts[2].toInt() > 2100)))
    {
        QMessageBox::warning(nullptr, "ERROR ADD", "Last maintenance date must be in dd/mm/yyyy format.");
        return false;
    }

    if (MachineStatus != "working" && MachineStatus != "not working")
    {
        QMessageBox::warning(nullptr, "ERROR ADD", "Machine status must be 'working' or 'not working'.");
        return false;
    }

    // Modified INSERT statement to match the display order in afficher()
    query.prepare("INSERT INTO MACHINE (MACHINEID, SERIAL_NUMBER, TYPE, MACHINE_STATUS, LAST_MAINTENANCE_DATE, FACTORY_ID) "
                 "VALUES (:MachineID, :SerialNumber, :Type, :MachineStatus, :LastMaintenanceDate, :FactoryID)");

    query.bindValue(":MachineID", machineIDStr);
    query.bindValue(":SerialNumber", serialNumberStr);
    query.bindValue(":Type", Type);
    query.bindValue(":MachineStatus", MachineStatus);
    query.bindValue(":LastMaintenanceDate", LastMaintenanceDate);
    query.bindValue(":FactoryID", FactoryIDStr);

    return query.exec();
}

QSqlQueryModel * machine::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    // Explicit column selection to match header order
    model->setQuery("SELECT MACHINEID, SERIAL_NUMBER, TYPE, MACHINE_STATUS, LAST_MAINTENANCE_DATE, FACTORY_ID FROM MACHINE");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MACHINEID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIAL_NUMBER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MACHINE_STATUS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LAST_MAINTENANCE_DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("FACTORY_ID"));

    return model;
}


bool machine::supprimer(int MachineID)
{
    QSqlQuery query;
    QString machineIDStr = QString::number(MachineID);
    query.prepare("DELETE FROM MACHINE WHERE MACHINEID = :MachineID");
    query.bindValue(":MachineID", machineIDStr);
    return query.exec();
}

bool machine::update(int MachineID, int SerialNumber, int FactoryID, QString Type, QString MachineStatus,QString LastMaintenanceDate)
{
    QSqlQuery query;


    QString machineIDStr = QString::number(MachineID);
    QString serialNumberStr = QString::number(SerialNumber);
    QString factoryIDStr = QString::number(FactoryID);




    query.prepare("UPDATE MACHINE SET "
                  "SERIAL_NUMBER = :SerialNumber, "
                  "MACHINE_STATUS = :MachineStatus, "
                  "LAST_MAINTENANCE_DATE = :LastMaintenanceDate, "  // Add comma here
                  "TYPE = :Type, "
                  "FACTORY_ID = :FactoryID "
                  "WHERE MACHINEID = :MachineID");



    query.bindValue(":MachineID", machineIDStr);
    query.bindValue(":SerialNumber", serialNumberStr);
    query.bindValue(":Type", Type);
    query.bindValue(":MachineStatus", MachineStatus);
    query.bindValue(":LastMaintenanceDate", LastMaintenanceDate);
    query.bindValue(":FactoryID", factoryIDStr);

    return query.exec();
}
bool machine::search(int MachineID)
{
    QSqlQuery query;
    QString res=QString::number(MachineID);
    query.prepare("Select * from MACHINE where MACHINEID= :MachineID");
    query.bindValue(":MachineID",res);
    return query.exec();
}




bool machine::exporterPDF()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr,
        "Export to PDF",
        QString(),
        "PDF Files (*.pdf)");

    if (fileName.isEmpty())
        return false;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);
    writer.setPageMargins(QMargins(50, 50, 50, 50)); // Set margins for centered layout

    QPainter painter(&writer);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    // Increase row width
    int tableColumnWidth = 450;  // Increased width for each column

    // Calculate left margin to center the table
    int totalTableWidth = tableColumnWidth * 5;  // Total width for all columns (5 columns)
    int leftMargin = (writer.width() - totalTableWidth) / 2;

    int topMargin = 30;   // Title position at the top of the page
    int currentY = topMargin;
    int tableRowHeight = 80;

    // Title at the top of the page
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(QRect(leftMargin, currentY, writer.width() - 2 * leftMargin, 40),
                     Qt::AlignCenter, "Liste des Machines");
    currentY += 60; // Adjust the currentY after the title

    // Export date
    painter.setFont(QFont("Arial", 10));
    QString currentDate = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm");
    painter.drawText(leftMargin, currentY, "Date d'exportation: " + currentDate);
    currentY += 60;

    // Table headers with lines
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    int currentX = leftMargin;
    QStringList headers = {"ID Machine", "Numéro de Série", "Type", "Statut", "Dernière Maintenance"};
    for (const QString &header : headers) {
        painter.drawRect(QRect(currentX, currentY, tableColumnWidth, tableRowHeight)); // Draw header cell border
        painter.drawText(QRect(currentX, currentY, tableColumnWidth, tableRowHeight),
                         Qt::AlignCenter, header);
        currentX += tableColumnWidth;
    }
    currentY += tableRowHeight;

    // Table content with lines
    QSqlQuery query("SELECT MACHINEID, SERIAL_NUMBER, TYPE, MACHINE_STATUS, LAST_MAINTENANCE_DATE FROM MACHINE ORDER BY MACHINEID");
    painter.setFont(QFont("Arial", 10));

    while (query.next()) {
        // Check for page overflow
        if (currentY >= writer.height() - 100) {
            writer.newPage();
            currentY = topMargin + 80;

            // Redraw headers on new page
            painter.setFont(QFont("Arial", 10, QFont::Bold));
            currentX = leftMargin;
            for (const QString &header : headers) {
                painter.drawRect(QRect(currentX, currentY, tableColumnWidth, tableRowHeight));
                painter.drawText(QRect(currentX, currentY, tableColumnWidth, tableRowHeight),
                                 Qt::AlignCenter, header);
                currentX += tableColumnWidth;
            }
            currentY += tableRowHeight;
            painter.setFont(QFont("Arial", 10));
        }

        // Table row data with lines
        currentX = leftMargin;
        for (int i = 0; i < headers.size(); i++) {
            QString cellText = query.value(i).toString();
            painter.drawRect(QRect(currentX, currentY, tableColumnWidth, tableRowHeight)); // Draw cell border
            painter.drawText(QRect(currentX, currentY, tableColumnWidth, tableRowHeight),
                             Qt::AlignCenter, cellText);
            currentX += tableColumnWidth;
        }
        currentY += tableRowHeight;
    }

    return painter.end();
}


QSqlQueryModel* machine::trierPar(const QString& criteria)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Build the SQL query dynamically based on the criteria
    QString queryStr = "SELECT MACHINEID, SERIAL_NUMBER, TYPE, MACHINE_STATUS, LAST_MAINTENANCE_DATE, FACTORY_ID FROM MACHINE ";

    if (criteria == "Last Maintenance Date") {
        queryStr += "ORDER BY CAST(SUBSTR(LAST_MAINTENANCE_DATE, 7, 4) AS INTEGER) ASC, "
                    "CAST(SUBSTR(LAST_MAINTENANCE_DATE, 4, 2) AS INTEGER) ASC, "
                    "CAST(SUBSTR(LAST_MAINTENANCE_DATE, 1, 2) AS INTEGER) ASC";
    } else if (criteria == "Serial Number") {
        queryStr += "ORDER BY SERIAL_NUMBER ASC";
    } else if (criteria == "ID") {
        queryStr += "ORDER BY MACHINEID ASC";
    }

    // Set the query to the model
    model->setQuery(queryStr);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MACHINEID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIAL_NUMBER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MACHINE_STATUS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LAST_MAINTENANCE_DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("FACTORY_ID"));

    return model;
}


QSqlQueryModel* machine::loadDataIntoTable()
{
     QSqlQueryModel* model = new QSqlQueryModel();

    // Exécution de la requête SQL pour récupérer toutes les données de la table DELIVERY
   model-> setQuery("SELECT MACHINEID, SERIAL_NUMBER, TYPE, MACHINE_STATUS, LAST_MAINTENANCE_DATE, FACTORY_ID FROM MACHINE ");

    // Vérification des erreurs dans le modèle
    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans le modèle:" << model->lastError();
        delete model;
        return nullptr;
    }

    // Définir les en-têtes de colonnes avec des noms personnalisés
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MACHINEID"));  // Colonne 0
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIAL_NUMBER"));  // Colonne 1
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));  // Colonne 2
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MACHINE_STATUS"));  // Colonne 3
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LAST_MAINTENANCE_DATE"));  // Colonne 4
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("FACTORY_ID"));  // Colonne 5

    // Retourner le modèle avec les données et les en-têtes
    return model;
}







QPair<int, int> machine::calculerPourcentages()
{
    QSqlQuery query;

    // Nombre total de machines
    query.prepare("SELECT COUNT(*) FROM MACHINE");
    if (!query.exec() || !query.next()) {
        qDebug() << "Erreur lors du calcul du total des machines.";
        return QPair<int, int>(0, 0); // Si une erreur se produit, retourner 0%
    }
    int totalMachines = query.value(0).toInt();

    if (totalMachines == 0) {
        return QPair<int, int>(0, 0); // Si aucune machine, retourner 0% pour les deux
    }

    // Nombre de machines 'working'
    query.prepare("SELECT COUNT(*) FROM MACHINE WHERE MACHINE_STATUS = 'working'");
    if (!query.exec() || !query.next()) {
        qDebug() << "Erreur lors du calcul des machines 'working'.";
        return QPair<int, int>(0, 0);
    }
    int workingMachines = query.value(0).toInt();

    // Calcul des pourcentages
    int workingPercentage = (totalMachines > 0) ? (workingMachines * 100) / totalMachines : 0;
    int notWorkingPercentage = 100 - workingPercentage;

    return QPair<int, int>(workingPercentage, notWorkingPercentage);
}






QSqlQueryModel* machine::machinesToPlanMaintenance()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT MACHINEID, SERIAL_NUMBER, TYPE, MACHINE_STATUS, LAST_MAINTENANCE_DATE, FACTORY_ID "
                  "FROM MACHINE WHERE MACHINE_STATUS = :status");
    query.bindValue(":status", "not working");  // Bind the 'not working' status

    if (query.exec()) {
        model->setQuery(std::move(query));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("MACHINEID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIAL_NUMBER"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("MACHINE_STATUS"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("LAST_MAINTENANCE_DATE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("FACTORY_ID"));
    } else {
        qDebug() << "Error fetching machines for maintenance:" << query.lastError().text();
    }
    return model;
}





QSqlQueryModel* machine::getScheduledMaintenance()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT MACHINEID, SERIAL_NUMBER, TYPE, MACHINE_STATUS, "
                    "LAST_MAINTENANCE_DATE, NEXT_MAINTENANCE_DATE, FACTORY_ID "
                    "FROM MACHINE "
                    "WHERE MACHINE_STATUS = 'not working'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MACHINEID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIAL_NUMBER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MACHINE_STATUS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LAST_MAINTENANCE_DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NEXT_MAINTENANCE_DATE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("FACTORY_ID"));

    return model;
}



QString machineDiagnostic(const QStringList& selectedSymptoms, int selectedMachineId)
{
    // Map of possible issues and their corresponding messages
    QMap<QString, QString> issueMessages = {
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

    // Check if symptoms are selected
    if (selectedSymptoms.isEmpty()) {
        return QString("No symptoms selected for diagnosis. Please select one or more symptoms.");
    }

    // Generate diagnostic message based on symptoms
    QString diagnosticMessage;
    diagnosticMessage += QString("Diagnostics for Machine ID: %1\n\n").arg(selectedMachineId);
    diagnosticMessage += "Identified Issues:\n";

    for (const QString& symptom : selectedSymptoms) {
        if (issueMessages.contains(symptom)) {
            diagnosticMessage += QString("- %1: %2\n").arg(symptom, issueMessages[symptom]);
        } else {
            diagnosticMessage += QString("- %1: No specific issue identified.\n").arg(symptom);
        }
    }

    // Additional note
    diagnosticMessage += "\nRecommended Actions:\n";
    diagnosticMessage += "- Perform a detailed inspection of the machine.\n";
    diagnosticMessage += "- Consult the user manual or a technician for further troubleshooting.\n";

    return diagnosticMessage;
}

