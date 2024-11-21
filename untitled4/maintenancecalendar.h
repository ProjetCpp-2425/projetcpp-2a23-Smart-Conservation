#ifndef MAINTENANCECALENDAR_H
#define MAINTENANCECALENDAR_H

// Include necessary headers
#include <QDialog>
#include <QCalendarWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDate>
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>
#include <QTextCharFormat>

class MaintenanceCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit MaintenanceCalendar(int machineId, QWidget *parent = nullptr);
    QString getSelectedDate() const;

private:
    void highlightDate(const QDate& date);
    void onDateSelected();
    void updateMaintenanceDate();
    void loadExistingMaintenanceDates();

    int machineId;
    QString selectedDate;
    QCalendarWidget *calendar;
    QPushButton *confirmButton;
};

#endif // MAINTENANCECALENDAR_H
