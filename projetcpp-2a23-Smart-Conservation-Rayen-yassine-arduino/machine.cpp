#include "machine.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QRegularExpression>
#include <QSqlQueryModel>
#include "connection.h"
#include "management.h"
#include<QSqlDatabase>
#include<mainwindow.h>

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


void machine::updateStatisticsDisplay(QWidget* parent)
{
    // Create a scroll area
    QScrollArea* scrollArea = new QScrollArea(parent);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // Create container widget for scroll area
    QWidget* containerWidget = new QWidget();

    // Get percentages
    QPair<int, int> percentages = calculerPourcentages();
    int workingPerc = percentages.first;
    int notWorkingPerc = percentages.second;

    // Create main layout
    QVBoxLayout* mainLayout = new QVBoxLayout(containerWidget);

    // Create horizontal layout for charts
    QHBoxLayout* chartsLayout = new QHBoxLayout();

    // Create bars container widget
    QWidget* barsWidget = new QWidget();
    QVBoxLayout* barsLayout = new QVBoxLayout(barsWidget);

    // Working machines bar
    QProgressBar* workingBar = new QProgressBar();
    workingBar->setValue(workingPerc);
    workingBar->setStyleSheet(
        "QProgressBar {"
        "   border: 2px solid grey;"
        "   border-radius: 5px;"
        "   text-align: center;"
        "   height: 30px;"
        "   margin: 10px;"
        "}"
        "QProgressBar::chunk {"
        "   background-color: #00FF00;"
        "   border-radius: 3px;"
        "}"
    );

    QLabel* workingLabel = new QLabel("Working machines:");
    workingLabel->setStyleSheet("font-size: 14px; font-weight: bold; margin: 5px;");
    barsLayout->addWidget(workingLabel);
    barsLayout->addWidget(workingBar);

    // Not working machines bar
    QProgressBar* notWorkingBar = new QProgressBar();
    notWorkingBar->setValue(notWorkingPerc);
    notWorkingBar->setStyleSheet(
        "QProgressBar {"
        "   border: 2px solid grey;"
        "   border-radius: 5px;"
        "   text-align: center;"
        "   height: 30px;"
        "   margin: 10px;"
        "}"
        "QProgressBar::chunk {"
        "   background-color: #FF4444;"
        "   border-radius: 3px;"
        "}"
    );

    QLabel* notWorkingLabel = new QLabel("Not working machines:");
    notWorkingLabel->setStyleSheet("font-size: 14px; font-weight: bold; margin: 5px;");
    barsLayout->addWidget(notWorkingLabel);
    barsLayout->addWidget(notWorkingBar);

    // Add some spacing
    barsLayout->addSpacing(20);

    // Create pie chart
    QChartView* pieChartView = createPieChart(workingPerc, notWorkingPerc);
    pieChartView->setMinimumSize(500, 400);  // Increased size for better visibility

    // Add widgets to charts layout
    chartsLayout->addWidget(barsWidget);
    chartsLayout->addWidget(pieChartView);

    // Add charts layout to main layout
    mainLayout->addLayout(chartsLayout);

    // Add some padding to the container
    containerWidget->setContentsMargins(20, 20, 20, 20);

    // Set the container widget to the scroll area
    scrollArea->setWidget(containerWidget);

    // Set up the layout for the parent widget
    QVBoxLayout* parentLayout = new QVBoxLayout(parent);
    parentLayout->addWidget(scrollArea);
    parentLayout->setContentsMargins(0, 0, 0, 0);

    // Set the scroll area to take up all available space
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

QChartView* machine::createPieChart(int workingPerc, int notWorkingPerc)
{
    // Create series
    QPieSeries* series = new QPieSeries();

    // Add slices
    QPieSlice* workingSlice = series->append("Working " + QString::number(workingPerc) + "%", workingPerc);
    QPieSlice* notWorkingSlice = series->append("Not Working " + QString::number(notWorkingPerc) + "%", notWorkingPerc);

    // Customize slices
    workingSlice->setBrush(QColor("#00FF00"));
    notWorkingSlice->setBrush(QColor("#FF4444"));

    // Add effects
    workingSlice->setExploded(true);
    workingSlice->setLabelVisible(true);
    notWorkingSlice->setLabelVisible(true);

    // Add hover effects
    workingSlice->setLabelPosition(QPieSlice::LabelOutside);
    notWorkingSlice->setLabelPosition(QPieSlice::LabelOutside);

    QObject::connect(workingSlice, &QPieSlice::hovered, [workingSlice](bool hover) {
        if (hover) {
            workingSlice->setExplodeDistanceFactor(0.15);
        } else {
            workingSlice->setExplodeDistanceFactor(0.1);
        }
    });

    QObject::connect(notWorkingSlice, &QPieSlice::hovered, [notWorkingSlice](bool hover) {
        if (hover) {
            notWorkingSlice->setExploded(true);
            notWorkingSlice->setExplodeDistanceFactor(0.15);
        } else {
            notWorkingSlice->setExploded(false);
        }
    });

    // Create chart and customize it
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Machines Status Distribution");
    chart->setTitleFont(QFont("Arial", 14, QFont::Bold));
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setTheme(QChart::ChartThemeLight);

    // Create chart view
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
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
    // Map symptoms to known issues with scores
    struct Issue {
        QString message;
        int score; // Weight of the issue based on symptoms
    };

    QMap<QString, QList<QString>> issueSymptomMap = {
        {"Cooling system failure", {"Overheating", "Frequent shutdowns"}},
        {"Power supply failure", {"Power Loss", "Electrical sparks"}},
        {"Mechanical misalignment", {"Unusual noise", "Vibrations"}},
        {"Battery failure", {"Battery draining"}},
        {"Software fault", {"Slow operation", "Frequent shutdowns"}},
        {"Display failure", {"Display not working"}},
        {"Wiring issue", {"Electrical sparks", "Frequent shutdowns"}}
    };

    QMap<QString, Issue> issues = {
        {"Cooling system failure", {"Cooling system might be clogged or fans are non-functional.", 0}},
        {"Power supply failure", {"Inspect power supply unit for faulty components.", 0}},
        {"Mechanical misalignment", {"Check for wear in moving parts or improper assembly.", 0}},
        {"Battery failure", {"Replace battery or check the charging mechanism.", 0}},
        {"Software fault", {"Ensure the latest software updates are applied.", 0}},
        {"Display failure", {"Inspect or replace display connectors or unit.", 0}},
        {"Wiring issue", {"Examine wiring for potential short circuits.", 0}}
    };

    // Diagnostic logic
    QString diagnosticMessage;
    diagnosticMessage += QString("Machine Diagnostics Report for Machine ID: %1\n").arg(selectedMachineId);
    diagnosticMessage += "-------------------------------------------------------------\n";

    if (selectedSymptoms.isEmpty()) {
        diagnosticMessage += "No symptoms provided. Please select one or more symptoms for diagnosis.\n";
        return diagnosticMessage;
    }

    // Analyze symptoms and score potential issues
    for (const QString& symptom : selectedSymptoms) {
        for (auto& key : issueSymptomMap.keys()) {
            if (issueSymptomMap[key].contains(symptom)) {
                issues[key].score += 1; // Increment score for each matching symptom
            }
        }
    }

    // Sort issues by score
    QList<QString> sortedIssues = issues.keys();
    std::sort(sortedIssues.begin(), sortedIssues.end(), [&issues](const QString& a, const QString& b) {
        return issues[a].score > issues[b].score;
    });

    // Generate detailed diagnosis report
    diagnosticMessage += "Identified Issues (sorted by likelihood):\n";
    for (const QString& issue : sortedIssues) {
        if (issues[issue].score > 0) {
            diagnosticMessage += QString("- %1\n  Cause: %2\n  Score: %3\n\n")
                .arg(issue)
                .arg(issues[issue].message)
                .arg(issues[issue].score);
        }
    }

    diagnosticMessage += "Recommended Actions:\n";
    diagnosticMessage += "- Perform a detailed inspection based on identified issues.\n";
    diagnosticMessage += "- Use diagnostic tools or consult a specialist if issues persist.\n";

    return diagnosticMessage;
}


MaintenanceCalendar::MaintenanceCalendar(int machineId, QWidget *parent)
    : QDialog(parent), machineId(machineId)
{
    setWindowTitle("Schedule Maintenance");

    QVBoxLayout *layout = new QVBoxLayout(this);

    calendar = new QCalendarWidget(this);
    calendar->setGridVisible(true);
    calendar->setMinimumDate(QDate::currentDate());

    QLabel *legend = new QLabel("Green: Scheduled Maintenance", this);
    confirmButton = new QPushButton("Confirm Maintenance Date", this);

    layout->addWidget(calendar);
    layout->addWidget(legend);
    layout->addWidget(confirmButton);

    connect(calendar, &QCalendarWidget::clicked, this, &MaintenanceCalendar::onDateSelected);
    connect(confirmButton, &QPushButton::clicked, this, &MaintenanceCalendar::updateMaintenanceDate);

    // Load existing maintenance dates
    loadExistingMaintenanceDates();

    QDate defaultDate = QDate::currentDate().addDays(7);
    calendar->setSelectedDate(defaultDate);
    highlightDate(defaultDate);
}

void MaintenanceCalendar::loadExistingMaintenanceDates()
{
    QSqlQuery query;
    query.prepare("SELECT NEXT_MAINTENANCE_DATE FROM MACHINE WHERE NEXT_MAINTENANCE_DATE IS NOT NULL");

    if (query.exec()) {
        while (query.next()) {
            QString dateStr = query.value(0).toString();
            QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");
            if (date.isValid()) {
                highlightDate(date);
            }
        }
    }
}

void MaintenanceCalendar::highlightDate(const QDate& date)
{
    QTextCharFormat format;
    format.setBackground(QColor(144, 238, 144));  // Light green
    format.setForeground(Qt::black);
    calendar->setDateTextFormat(date, format);
}

void MaintenanceCalendar::onDateSelected()
{
    QDate date = calendar->selectedDate();
    selectedDate = date.toString("dd/MM/yyyy");
}

void MaintenanceCalendar::updateMaintenanceDate()
{
    qDebug() << "Updating maintenance date for Machine ID:" << machineId;
    qDebug() << "Selected Date:" << selectedDate;

    if (selectedDate.isEmpty()) {
        selectedDate = calendar->selectedDate().toString("dd/MM/yyyy");
    }

    QSqlQuery query;
    query.prepare("UPDATE MACHINE SET NEXT_MAINTENANCE_DATE = :date WHERE MACHINEID = :id");
    query.bindValue(":date", selectedDate);
    query.bindValue(":id", machineId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Maintenance date scheduled successfully!");

        // Find the parent management class
        management* parentManagement = qobject_cast<management*>(parentWidget());
        if (parentManagement) {
            parentManagement->updateCalendarHighlights(); // Call the method from the management class
        }

        accept();
    } else {
        QMessageBox::warning(this, "Error", "Failed to schedule maintenance date!");
    }
}

QString MaintenanceCalendar::getSelectedDate() const
{
    return selectedDate;
}

