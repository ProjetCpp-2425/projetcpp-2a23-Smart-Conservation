#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "client.h"
#include "employee.h"
#include "machine.h"
#include "factory.h"
#include <QWidget>
#include <QStackedWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QTimer>
#include <QDate>
#include <QDateTime>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QVBoxLayout>
#include "arduino.h"
namespace Ui {
class management;
}

class management : public QWidget
{
    Q_OBJECT



public:
    explicit management(QWidget *parent = nullptr);
    ~management();
    //machine
    void updateCalendarHighlights();
    //factory
    void updateFactoryCount();
private slots:
    //SIDEBAR
    void on_employees_clicked();
    void on_deliveries_clicked();
    void on_machines_clicked();
    void on_logout_clicked();
    //EMPLOYEE
    void on_add_employee_btn_clicked();
    void on_add_back_clicked();
    void on_update_back_clicked();
    void on_history_back_clicked();
    void on_confirm_employee_btn_clicked();
    void on_update_employee_btn_clicked();
    void on_confirm_update_btn_clicked();
    void on_delete_employee_btn_clicked();
    void on_searchConfirm();
    void on_searchReset_clicked();
    void onTableItemDoubleClicked(QTableWidgetItem *item);
    void on_employee_export_clicked();
    void updateProgressBars();
    //COMMANDE
    void on_pushButton_3_clicked();
    void on_pushButton_10_clicked();
    void on_edit_table_button_clicked();
    void on_button_delete_clicked();
    void on_return_main_clicked();
    void on_export_table_clicked();
    void filterTableByDeliveryId(const QString &searchText);
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_pushButton_2_clicked();
    void onTableWidgetRowSelected(int row, int column) ;
    void on_back_qrcode_ordered_clicked();
    void on_back_qrcode_in_progress_clicked();
    void on_back_qrcode_delivered_clicked();
    void on_statsbutton_clicked();
    //MACHINE
    void on_ajouter_clicked();
    void on_delete_2_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_25_clicked();
    void on_tableView_4_clicked(const QModelIndex &index);
    void on_pushButton_24_clicked();
    //---------------------------------------------------------------------------FACTORY
    void on_filterButton_clickedF(); // Slot for filter button
    void on_add_clickedF();
    void on_annuler_clickedF();
    void on_ajout_cl_clickedF();
    void on_sup_clickedF();
    void on_delete_2_clickedF();
    void on_cancel_clickedF();
    void on_cancl_clickedF();
    void on_ajout_cl_2_clickedF();
    void on_update_clickedF();
    void on_update_2_clickedF();
    void on_annuler_2_clickedF();

    // New slot for statistics button
    void on_statisticButton_clickedF(); // Slot for statistics button

    // New slot to update the progress bar
    void updateProgressBarF(int value); // Slot for updating the progress bar

    // New method for PDF export
    void on_pdfButton_clickedF(); // Slot for PDF button click

    // Method to update the factory count
    void updateFactoryCountF(); // Declaration of the method to update factory count

    // New slots for QR code generation and display
    void on_generateQRButton_clickedF(); // Slot to generate QR code
    void on_displayQRButton_clickedF(); // Slot to display the QR code for a specific factory
    //void on_factoriesF_clicked();
    void on_factories_clicked();
    //----------------------------------------------client--------------------------

    void on_add_clicked();

   // void on_annuler_clicked();

    void on_ajout_cl_clicked();

   // void on_sup_clicked();
    //void on_delete_2_clicked();

    void on_cancel_clicked();

    //void on_ajout_cl_2_clicked();

    void on_update_clicked();
    void on_update_2_clicked();
    //void on_add_client_2_clicked();

   // void on_annuler_2_clicked();

    void on_pdf_clicked();
    void on_trier_clicked();

   // void on_send_clicked();
   // void on_stats_clicked();
   // void on_back_clicked();

    void statistique();
    //void on_serarch_c_clicked();
    void on_pushButton_6_clicked();
    void on_selectid_clicked();
    void on_send_clicked();
    void update_label();

    //void on_clients_clicked();

    void on_dahsboard_clicked();

    void on_searchReset_2_clicked();
    void on_searchConfirm2();
    void on_search_field_2_textChanged(const QString &search_field_2);

private:
    Ui::management *ui;
    QStackedWidget *mainStackedWidget;
    QStackedWidget *employeeStackedWidget;
    QStackedWidget *factoryStackedWidget;
    QStackedWidget *machineStackedWidget;
    QStackedWidget *clientStackedWidget;
    QStackedWidget *deliveryStackedWidget;
    QString currentDeliveryId; // Stores the ID of the delivery being edited
    bool isEditMode; // Indicates if the form is in edit mode
    void loadDeliveriesIntoTable();
    //MACHINE
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

    //FACTORY
    factory fa; // Instance of the factory class

    // New method to handle text search for location filtering
    void on_searchLocation_textChangedF(const QString &searchText);
    /////--------------------------------------client
    client cl;
    arduino A;

    QLabel *alertLabel; // Label for displaying alerts
    QTimer *alertTimer; // Timer to control the alert duration
    QPropertyAnimation *alertAnimation;

    void show_alert(const QString &message);
    void hide_alert();


    int selectedClientId=-1;
};

#endif // MANAGEMENT_H
