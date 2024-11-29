#include "commande.h"
#include <QMessageBox>
#include <QDate>
#include <QDateTime>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QSqlQuery>
#include <QVBoxLayout>

Delivery::Delivery() {}

Delivery::Delivery(const QString &id, const QString &address, const QString &date, const QString &status, const QString &clientId, const QString &employeeId) :
    deliveryId(id), deliveryAddress(address), deliveryDate(date), status(status), clientId(clientId), employeeId(employeeId) {}

// Getters
QString Delivery::getId() const { return deliveryId; }
QString Delivery::getAddress() const { return deliveryAddress; }
QString Delivery::getDate() const { return deliveryDate; }
QString Delivery::getStatus() const { return status; }
QString Delivery::getClientId() const { return clientId; }
QString Delivery::getEmployeeId() const { return employeeId; }

// Setters
void Delivery::setId(const QString &id) { deliveryId = id; }
void Delivery::setAddress(const QString &address) { deliveryAddress = address; }
void Delivery::setDate(const QString &date) { deliveryDate = date; }
void Delivery::setStatus(const QString &status) { this->status = status; }
void Delivery::setClientId(const QString &clientId) { this->clientId = clientId; }
void Delivery::setEmployeeId(const QString &employeeId) { this->employeeId = employeeId; }

bool Delivery::add() {
    QSqlQuery query;
    query.prepare("INSERT INTO DELIVERY (DELIVERY_ID, DELIVERY_ADDRESS, DELIVERY_DATE, STATUS, CE_CLIENT_ID, CE_EMPLOYEE_ID) "
                  "VALUES (:id, :address, :date, :status, :clientId, :employeeId)");
    query.bindValue(":id", deliveryId);
    query.bindValue(":address", deliveryAddress);
    query.bindValue(":date", deliveryDate);
    query.bindValue(":status", status);
    query.bindValue(":clientId", clientId);
    query.bindValue(":employeeId", employeeId);
    if (!query.exec()) {
        qDebug() << "Preparing to execute query with values:";
        qDebug() << "Delivery Address:" << deliveryAddress;
        qDebug() << "Delivery Date:" << deliveryDate;
        qDebug() << "Client ID:" << clientId;
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Delivery::update(const QString &oldId) {
    QSqlQuery query;
    query.prepare("UPDATE DELIVERY SET DELIVERY_ID=:newId, DELIVERY_ADDRESS=:address, DELIVERY_DATE=:date, "
                  "STATUS=:status, CE_CLIENT_ID=:clientId, CE_EMPLOYEE_ID=:employeeId WHERE DELIVERY_ID=:oldId");
    query.bindValue(":newId", deliveryId); // Bind the new Delivery ID
    query.bindValue(":address", deliveryAddress); // Bind the new delivery address
    query.bindValue(":date", deliveryDate);       // Bind the new delivery date
    query.bindValue(":status", status);           // Bind the new status
    query.bindValue(":clientId", clientId);       // Bind the new client ID
    query.bindValue(":employeeId", employeeId);   // Bind the new employee ID
    query.bindValue(":oldId", oldId);             // Bind the old Delivery ID to identify the record
    return query.exec();
}

QSqlQueryModel* Delivery::display() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM DELIVERY");
    return model;
}
