#include "factory.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QRegularExpression>
#include <QSqlQueryModel>
#include "connection.h"
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QPageLayout>
#include <QDir>
#include <QSqlQuery>
#include <QPixmap>
#include <QFont>
#include <QColor>
#include <QStandardItemModel>

factory::factory(int idf, int idc, int tot_e, int tot_m, int capacity, QString location) {
    this->idf = idf;
    this->idc = idc;
    this->tot_e = tot_e;
    this->tot_m = tot_m;
    this->capacity = capacity;
    this->location = location;
}

bool factory::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO FACTORY (FACTORY_ID, LOCATION, CAPACITY, TOTAL_EMPLOYEES, TOTAL_MACHINES, CHEF_ID) "
                  "VALUES (:idf, :location, :capacity, :tot_e, :tot_m, :idc)");
    query.bindValue(":idf", idf);
    query.bindValue(":location", location);
    query.bindValue(":capacity", capacity);
    query.bindValue(":tot_e", tot_e);
    query.bindValue(":tot_m", tot_m);
    query.bindValue(":idc", idc);

    return query.exec();
}

QSqlQueryModel* factory::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FACTORY");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("FACTORY_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITY"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOTAL_EMPLOYEES"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TOTAL_MACHINES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CHEF_ID"));
    return model;
}

bool factory::supprimer(int idf) {
    QSqlQuery query;
    query.prepare("DELETE FROM FACTORY WHERE FACTORY_ID = :idf");
    query.bindValue(":idf", idf);
    return query.exec();
}

bool factory::search(int idf) {
    QSqlQuery query;
    query.prepare("SELECT * FROM FACTORY WHERE FACTORY_ID = :idf");
    query.bindValue(":idf", idf);
    return query.exec();
}

bool factory::update(int idf, int idc, int tot_e, int tot_m, int capacity, QString location) {
    QSqlQuery query;
    query.prepare("UPDATE FACTORY SET LOCATION=:location, CAPACITY=:capacity, TOTAL_EMPLOYEES=:tot_e, TOTAL_MACHINES=:tot_m, CHEF_ID=:idc "
                  "WHERE FACTORY_ID = :idf");
    query.bindValue(":idf", idf);
    query.bindValue(":idc", idc);
    query.bindValue(":tot_e", tot_e);
    query.bindValue(":tot_m", tot_m);
    query.bindValue(":capacity", capacity);
    query.bindValue(":location", location);
    return query.exec();
}

bool factory::getFactoryData(int idf) {
    QSqlQuery query;
    query.prepare("SELECT * FROM FACTORY WHERE FACTORY_ID = :idf");
    query.bindValue(":idf", idf);

    if (query.exec() && query.next()) {
        this->idf = query.value("FACTORY_ID").toInt();
        this->idc = query.value("CHEF_ID").toInt();
        this->tot_e = query.value("TOTAL_EMPLOYEES").toInt();
        this->tot_m = query.value("TOTAL_MACHINES").toInt();
        this->capacity = query.value("CAPACITY").toInt();
        this->location = query.value("LOCATION").toString();
        return true;
    }
    return false;
}

void factory::pdf_downloader() {
    QPdfWriter pdf("C:/Users/saber/Documents/pdf_factory_test/Factory.pdf");
    QPainter painter(&pdf);

    // Set the page size and orientation
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setPageOrientation(QPageLayout::Portrait);

    // Set background color
    painter.fillRect(QRect(0, 0, pdf.width(), pdf.height()), QColor("light green"));

    // Title font and text
    QFont font("Arial", 30, QFont::Bold);
    painter.setFont(font);
    painter.drawText(1000, 1000, "Profil de la Factory");

    // Content font
    QFont contentFont("Arial", 14);
    painter.setFont(contentFont);

    // Database query
    QSqlQuery query;
    query.prepare("SELECT * FROM FACTORY");
    query.exec();

    // Define initial vertical position, line height, and table cell width
    int x = 100;
    int y = 1900;
    int rowHeight = 600;
    int columnWidth = 1500;

    // Draw table header
    painter.setFont(QFont("Arial", 8, QFont::Bold));
    painter.drawText(x, y, "FACTORY ID");
    painter.drawText(x + columnWidth, y, "CHEF ID");
    painter.drawText(x + 2 * columnWidth, y, "TOTAL EMPLOYEES");
    painter.drawText(x + 3 * columnWidth, y, "TOTAL MACHINES");
    painter.drawText(x + 4 * columnWidth, y, "CAPACITY");
    painter.drawText(x + 5 * columnWidth, y, "LOCATION");

    // Draw line after header
    painter.drawLine(x, y + 20, x + 6 * columnWidth, y + 20);

    y += rowHeight;

    // Reset font for content
    painter.setFont(QFont("Arial", 8));

    // Loop to handle multiple rows
    while (query.next()) {
        painter.drawText(x, y, query.value(0).toString());
        painter.drawText(x + columnWidth, y, query.value(1).toString());
        painter.drawText(x + 2 * columnWidth, y, query.value(2).toString());
        painter.drawText(x + 3 * columnWidth, y, query.value(3).toString());
        painter.drawText(x + 4 * columnWidth, y, query.value(4).toString());
        painter.drawText(x + 5 * columnWidth, y, query.value(5).toString());

        // Draw borders for the current row
        painter.drawLine(x, y - rowHeight + 20, x + 6 * columnWidth, y - rowHeight + 20);
        painter.drawLine(x, y + 20, x + 6 * columnWidth, y + 20);

        for (int i = 0; i <= 6; ++i) {
            painter.drawLine(x + i * columnWidth, y - rowHeight + 20, x + i * columnWidth, y + 20);
        }

        y += rowHeight;
    }

    QPixmap logo("Z:/Desktop/Projet_CPP/projet_PCC_Factory/logo.png");
    double scaleFactor = 20.0;
    int newWidth = static_cast<int>(logo.width() * scaleFactor);
    int newHeight = static_cast<int>(logo.height() * scaleFactor);
    logo = logo.scaled(newWidth, newHeight, Qt::KeepAspectRatio);
    painter.drawPixmap(5000, 100, logo);
    painter.end();
}

// New method to get the total number of factories
int factory::getTotalFactories() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FACTORY");
    query.exec();
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

// New method to get the number of factories by location
int factory::getFactoriesByLocation(const QString& location) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FACTORY WHERE LOCATION = :location");
    query.bindValue(":location", location);
    query.exec();
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}
