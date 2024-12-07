#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "arduino.h"
#include "employee.h"
#include <QWidget>
#include <QStackedWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include <QString>
#include <QScreen>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QTimer>
#include "client.h"
#include <QPropertyAnimation>
namespace Ui {
class management;
}

class management : public QWidget
{
    Q_OBJECT

public:
    explicit management(QWidget *parent = nullptr);
    ~management();

private slots:
    void on_dahsboard_clicked();
    void on_employees_clicked();
    void on_factories_clicked();
    void on_deliveries_clicked();
    void on_clients_clicked();
    void on_machines_clicked();

    void on_add_employee_btn_clicked();
    void on_add_client_btn_clicked();
    void on_add_delivery_btn_clicked();
    void on_add_factory_btn_clicked();
    void on_add_machine_btn_clicked();

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
    void on_logout_clicked();
    void updateProgressBars();
    //-------client--------------
    void on_add_clicked();

   // void on_annuler_clicked();

    void on_ajout_cl_clicked();


   // void on_sup_clicked();

    //void on_delete_2_clicked();


    void on_cancel_clicked();


    //void on_ajout_cl_2_clicked();

    void on_update_clicked();

    void on_update_2_clicked();
    void on_add_client_2_clicked();

   // void on_annuler_2_clicked();


    void on_pdf_clicked();

    void on_trier_clicked();

   // void on_send_clicked();

   // void on_stats_clicked();

   // void on_back_clicked();
    void statistique();

    void on_serarch_c_clicked();

    void on_pushButton_6_clicked();
    void on_selectid_clicked();

    void on_send_clicked();
    void update_label();
private:
    Ui::management *ui;
    client cl;

    QStackedWidget *mainStackedWidget;
    QStackedWidget *employeeStackedWidget;
    QStackedWidget *factoryStackedWidget;
    QStackedWidget *machineStackedWidget;
    QStackedWidget *clientStackedWidget;
    QStackedWidget *deliveryStackedWidget;
    Arduino A;

    QLabel *alertLabel; // Label for displaying alerts
    QTimer *alertTimer; // Timer to control the alert duration
    QPropertyAnimation *alertAnimation;

    void show_alert(const QString &message);
    void hide_alert();
};

#endif // MANAGEMENT_H
