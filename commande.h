// TO DO
//
// el timeline
// wl maps
#ifndef COMMANDE_H
#define COMMANDE_H

#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class commande;
}
QT_END_NAMESPACE

class commande : public QMainWindow
{
    Q_OBJECT

public:
    commande(QWidget *parent = nullptr);
    ~commande();





private slots:

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
    Ui::commande *ui;

    void loadDeliveriesIntoTable();

    bool isEditMode = false; // Indicates if the form is in edit mode

    QString currentDeliveryId; // Stores the ID of the delivery being edited

};

class Delivery {
public:
    // Constructors
    Delivery();
    Delivery(const QString &id, const QString &address, const QString &date, const QString &status, const QString &clientId, const QString &employeeId);

    // Getters
    QString getId() const;
    QString getAddress() const;
    QString getDate() const;
    QString getStatus() const;
    QString getClientId() const;
    QString getEmployeeId() const;

    // Setters
    void setId(const QString &id);
    void setAddress(const QString &address);
    void setDate(const QString &date);
    void setStatus(const QString &status);
    void setClientId(const QString &clientId);
    void setEmployeeId(const QString &employeeId);

    // Database functions
    bool add();
    bool update(const QString &id);
    bool remove(const QString &id);
    QSqlQueryModel* display();

private:
    QString deliveryId;
    QString deliveryAddress;
    QString deliveryDate;
    QString status;
    QString clientId;
    QString employeeId;


};

#endif // COMMANDE_H
