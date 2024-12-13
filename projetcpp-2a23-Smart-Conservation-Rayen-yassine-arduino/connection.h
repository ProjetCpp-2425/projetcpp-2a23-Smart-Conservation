#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool connect();
    void disconnect();
};

#endif // CONNECTION_H
