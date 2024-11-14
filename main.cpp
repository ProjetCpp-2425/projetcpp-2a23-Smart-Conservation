#include "connection.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QIcon>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test = c.connect();
    MainWindow w;
    a.setWindowIcon(QIcon("C:/Users/21699/Desktop/final/logo.ico")); // Adjust the path as needed


    if (test) {
        qDebug() << "Database Connected";
        w.show();
    } else {
        qDebug() << "Database Issue";
    }

    return a.exec();
}
