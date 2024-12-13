#ifndef FACTORY_H
#define FACTORY_H
#include <QStandardItemModel>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QPdfWriter>    // For PDF generation
#include <QPainter>      // For drawing on PDF
#include <QPixmap>       // For working with images (logo in your case)
#include <QColor>        // For colors

class factory
{
    QString location;
    int idf, idc, tot_e, tot_m, capacity;

public:
    factory() {};  // Default constructor
    factory(int idf, int idc, int tot_e, int tot_m, int capacity, QString location);  // Parameterized constructor

    // Getters
    int getidf() const { return idf; }
    int getidc() const { return idc; }
    int getcapacity() const { return capacity; }
    int gettot_e() const { return tot_e; }
    QString getlocation() const { return location; }
    int gettot_m() const { return tot_m; }

    // Setters
    void setidf(int n) { this->idf = n; }
    void setidc(int e) { this->idc = e; }
    void setcapacity(int i) { this->capacity = i; }
    void settot_e(int a) { this->tot_e = a; }
    void setlocation(const QString& p) { location = p; }
    void settot_m(int t) { this->tot_m = t; }

    // Database Operations
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int idf);
    bool search(int idf);
    bool update(int idf, int idc, int tot_e, int tot_m, int capacity, QString location);
    bool getFactoryData(int idf);  // Method to retrieve data by factory ID

    // PDF generation
    void pdf_downloader();

    // New methods for statistics and progress bar
    int getTotalFactories(); // Get the total number of factories
    int getFactoriesByLocation(const QString& location); // Get the number of factories in a specific location
};

#endif // FACTORY_H
