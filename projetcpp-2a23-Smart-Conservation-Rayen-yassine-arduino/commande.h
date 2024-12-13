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
    QSqlQueryModel* display();
private slots :
    void filterTableByDeliveryId(const QString &searchText);

private:
    QString deliveryId;
    QString deliveryAddress;
    QString deliveryDate;
    QString status;
    QString clientId;
    QString employeeId;  

};

#endif // COMMANDE_H
