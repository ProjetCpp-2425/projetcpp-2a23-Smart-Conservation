#include "connection.h"

Connection::Connection(){}

bool Connection::connect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_CPP");
    db.setUserName("terranova");
    db.setPassword("terranova");

    if (db.open()) {
        test =true;
       }
    return test;

}

void Connection::disconnect()
{ db.close(); }
