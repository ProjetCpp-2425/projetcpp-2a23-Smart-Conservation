#include "maintenancecalendar.h"
#include "mainwindow.h"

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

        // Try to find the parent MainWindow and call updateCalendarHighlights
        MainWindow* mainWindow = qobject_cast<MainWindow*>(parentWidget());
        if (mainWindow) {
            mainWindow->updateCalendarHighlights();
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
