#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "machine.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();void updateCalendarHighlights();

private slots:
    void on_ajouter_clicked();
    void on_delete_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();



    void on_pushButton_10_clicked();



    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_7_clicked();





    void on_pushButton_16_clicked();

    void on_pushButton_11_clicked();


    void on_pushButton_14_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);





    void on_pushButton_15_clicked();

private:
    Ui::MainWindow *ui;
    machine ma;

    void updateMachineTable();
    void initializeUI();
    void afficherPourcentages();
    void loadTableData();
    void showMaintenanceCalendar(const QModelIndex &index);
    void loadMaintenanceDates();
    void highlightMaintenanceDate(const QDate& date);


    QMap<QDate, QList<int>> maintenanceDateToMachineIds;




      void diagnose(int selectedMachineId);
  void displayDiagnosticMessage(int machineId, const QStringList& symptoms);
  QString performDiagnosis(const QStringList& symptoms, const QString& machineId);



};

#endif // MAINWINDOW_H
