#ifndef MANAGEMENT_H
#define MANAGEMENT_H
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
private:
    Ui::management *ui;
    QStackedWidget *mainStackedWidget;
    QStackedWidget *employeeStackedWidget;
    QStackedWidget *factoryStackedWidget;
    QStackedWidget *machineStackedWidget;
    QStackedWidget *clientStackedWidget;
    QStackedWidget *deliveryStackedWidget;
};

#endif // MANAGEMENT_H
