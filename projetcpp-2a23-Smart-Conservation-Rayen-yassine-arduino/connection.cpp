#include "connection.h"

Connection::Connection(){}

bool Connection::connect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Oracle in XE};DSN=integration;");
    db.setUserName("terranova");
    db.setPassword("terranova");

    if (db.open()) {
        test = true;
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();
    }

    return test;

}

void Connection::disconnect()
{ db.close(); }
