#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;

    bool test = c.createconnect();
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr,
            QObject::tr("Base de données"),
            QObject::tr("Connexion réussie à la base de données.\n"
                       "Cliquez sur OK pour continuer."),
            QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr,
            QObject::tr("Base de données"),
            QObject::tr("Erreur de connexion à la base de données.\n"
                       "Cliquez sur OK pour quitter."),
            QMessageBox::Ok);
    }

    return a.exec();
}

