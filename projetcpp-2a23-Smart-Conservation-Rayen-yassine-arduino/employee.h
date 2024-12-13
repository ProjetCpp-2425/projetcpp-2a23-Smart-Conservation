#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QProgressBar>
#include <QSqlQuery>
#include <QWidget>
#include <QStackedWidget>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidget>
#include <QSqlError>
#include <QHeaderView>
#include <QSqlQueryModel>
#include <QDateTime>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPageSize>
#include <QPrinter>
#include <QPainter>
#include <QPageSize>
#include <QTextOption>
#include <QRegularExpression>


class Employee {
private:
    QString name, email, position;
    int phoneNumber;

public:
    // Default constructor
    Employee() {}
    // Constructor with parameters
    Employee(QString name, QString email, QString position, int phoneNumber);  
    // Getters
    QString getName() const { return name; }
    QString getEmail() const { return email; }
    QString getPosition() const { return position; }
    int getPhoneNumber() const { return phoneNumber; }
    // Setters
    void setName(const QString &n) { name = n; }
    void setEmail(const QString &e) { email = e; }
    void setPhoneNumber(int p) { phoneNumber = p; }
    void setPosition(const QString &po) { position = po; }
    // Function for employee
    bool createEmployee();
    void readEmployee(QTableWidget *table);   
    void readHistorique(QTableWidget *tableH,QString employeeId);
    bool updateEmployee(QString id);
    bool deleteEmployee(const QString &employeeId);
    QSqlQueryModel *rechercher(const QString &type,const QString &text);
    void exportPresence(QTableWidget *tableH);
};

#endif // EMPLOYEE_H
