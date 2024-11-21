#ifndef MACHINE_H
#define MACHINE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDate>

#include <QPdfWriter>
#include <QPainter>





QString machineDiagnostic(const QStringList& selectedSymptoms, int selectedMachineId);


class machine
{
private:
    int MachineID;
    int SerialNumber;
    int FactoryID;
    QString Type;
    QString MachineStatus;
    QString LastMaintenanceDate;


public:

    machine() {};
    machine(int MachineID, int SerialNumber, int FactoryID, QString Type, QString MachineStatus, QString LastMaintenanceDate);


    int getMachineID() { return MachineID; }
    int getSerialNumber() { return SerialNumber; }
    int getFactoryID(){return FactoryID; }
    QString getType() { return Type; }
    QString getMachineStatus() { return MachineStatus; }
    QString getLastMaintenanceDate() { return LastMaintenanceDate; }


    void setMachineID(int id) { MachineID = id; }
    void setSerialNumber(int sn) { SerialNumber = sn; }
    void setFactoryID(int Fid){FactoryID =Fid; }
    void setType(QString t) { Type = t; }
    void setMachineStatus(QString ms) { MachineStatus = ms; }
    void setLastMaintenanceDate(QString date) { LastMaintenanceDate = date; }


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool search(int);
    bool update(int, int, int, QString, QString, QString);

    bool exporterPDF();
    QSqlQueryModel* loadDataIntoTable();
    QPair<int, int> calculerPourcentages();

    QSqlQueryModel* trierPar(const QString& criteria);
    QSqlQueryModel* machinesToPlanMaintenance();
    bool updateMaintenanceDate(int MachineId, const QString& maintenanceDate);
    QSqlQueryModel* getScheduledMaintenance();
    void navigateToCalendar(int machineId);


    QList<int> getMachinesForMaintenance();
    QString machineDiagnostic(const QStringList& selectedSymptoms);




};

#endif
