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
    //SIDEBAR
    void on_employees_clicked();
    void on_deliveries_clicked();
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
};

#endif // MANAGEMENT_H
