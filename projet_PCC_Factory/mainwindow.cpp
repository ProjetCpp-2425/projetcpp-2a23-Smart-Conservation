#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "factory.h"
#include <QFileDialog>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StackedWidget->setCurrentWidget(ui->principale);
    ui->tableView->setModel(cl.afficher());

    // Update the factory count on startup
    updateFactoryCount();  // Call the function to set the factory count

    // Connecting button clicks to their respective slots
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::on_add_clicked);
    connect(ui->annuler, &QPushButton::clicked, this, &MainWindow::on_annuler_clicked);
    connect(ui->sup, &QPushButton::clicked, this, &MainWindow::on_sup_clicked);
    connect(ui->ajout_cl_2, &QPushButton::clicked, this, &MainWindow::on_ajout_cl_2_clicked);
    connect(ui->PDF, &QPushButton::clicked, this, &MainWindow::on_pdfButton_clicked); // Connect PDF button
    connect(ui->filterButton, &QPushButton::clicked, this, &MainWindow::on_filterButton_clicked);
    connect(ui->searchLocation, &QLineEdit::textChanged, this, &MainWindow::on_searchLocation_textChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->ajout);
}

void MainWindow::on_annuler_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->principale);
}

void MainWindow::on_sup_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->suppression);
}

void MainWindow::on_cancel_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->principale);
}

void MainWindow::on_update_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->modif);
}

// Search for the update and show old data
void MainWindow::on_ajout_cl_2_clicked()
{
    int idf = ui->search_2->text().toInt();

    // Check if the factory exists
    if (cl.search(idf) && cl.getFactoryData(idf)) {
        // Populate UI fields with the old data
        ui->chi->setText(QString::number(cl.getidc()));
        ui->totm->setText(QString::number(cl.gettot_m()));
        ui->tote->setText(QString::number(cl.gettot_e()));
        ui->cap->setText(QString::number(cl.getcapacity()));
        ui->loc->setText(cl.getlocation());

        // Switch to update page
        ui->StackedWidget->setCurrentWidget(ui->update_if);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Try another ID"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

// Modification of information
void MainWindow::on_update_2_clicked()
{
    int idf = ui->search_2->text().toInt();
    int idc = ui->chi->text().toInt();
    int tot_m = ui->totm->text().toInt();
    int tot_e = ui->tote->text().toInt();
    int capacity = ui->cap->text().toInt();
    QString location = ui->loc->text();

    bool test = cl.update(idf, idc, tot_e, tot_m, capacity, location);
    if (test) {
        ui->tableView->setModel(cl.afficher());
        updateFactoryCount();  // Update the factory count after update
        QMessageBox::information(nullptr, QObject::tr("Update"),
                                 QObject::tr("Updated successfully.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Won't be Updated"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_cancl_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->principale);
}

void MainWindow::on_annuler_2_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->principale);
}

// Deleting an item from the database
void MainWindow::on_delete_2_clicked()
{
    int id = ui->id_sup->text().toInt();

    bool test = cl.supprimer(id);
    if (test) {
        ui->tableView->setModel(cl.afficher());
        updateFactoryCount();  // Update the factory count after deletion
        QMessageBox::information(nullptr, QObject::tr("Delete"),
                                 QObject::tr("The item was deleted successfully.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Won't be Deleted"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_ajout_cl_clicked()
{
    int idf = ui->idf->text().toInt();
    int idc = ui->idc->text().toInt();
    int tot_m = ui->tot_m->text().toInt();
    int tot_e = ui->tot_e->text().toInt();
    int capacity = ui->capacity->text().toInt();
    QString location = ui->location->text();

    factory c(idf, idc, tot_e, tot_m, capacity, location);
    bool test = c.ajouter();
    if (test) {
        ui->tableView->setModel(cl.afficher());
        updateFactoryCount();  // Update the factory count after adding
        QMessageBox::information(nullptr, QObject::tr("Add Successful"),
                                 QObject::tr("Client added successfully.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Won't be added"),
                              QObject::tr("ERROR 404.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

// New method to handle PDF export when the button is clicked
void MainWindow::on_pdfButton_clicked()
{
    // Call the PDF export function from the factory class
    cl.pdf_downloader();

    // Show a success message
    QMessageBox::information(this, "PDF Export", "Factory data has been successfully exported to a PDF.");
}

void MainWindow::on_filterButton_clicked()
{
    QString selectedCriteria = ui->filterComboBox->currentText(); // Critère sélectionné

    QString query;
    if (selectedCriteria == "factory_id") {
        query = "SELECT * FROM FACTORY ORDER BY FACTORY_ID ASC";
    } else if (selectedCriteria == "total_employees") {
        query = "SELECT * FROM FACTORY ORDER BY TOTAL_EMPLOYEES ASC";
    } else if (selectedCriteria == "total_machines") {
        query = "SELECT * FROM FACTORY ORDER BY TOTAL_MACHINES ASC";
    }

    if (!query.isEmpty()) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("FACTORY_ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCATION"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITY"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOTAL_EMPLOYEES"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("TOTAL_MACHINES"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("CHEF_ID"));

        ui->tableView->setModel(model); // Mettez à jour l'affichage
    }
}

void MainWindow::on_searchLocation_textChanged(const QString &searchText)
{
    QString query = "SELECT * FROM FACTORY WHERE LOCATION LIKE '%" + searchText + "%'";

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("FACTORY_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITY"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOTAL_EMPLOYEES"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TOTAL_MACHINES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CHEF_ID"));

    ui->tableView->setModel(model); // Update the table view to show filtered results
}

// Function to update the factory count
void MainWindow::updateFactoryCount()
{
    QSqlQuery query("SELECT COUNT(*) FROM FACTORY");
    if (query.next()) {
        int count = query.value(0).toInt();
        ui->totalFactoriesLabel->setText(QString("Total Factories: %1").arg(count));  // Update the label
    }
}
// Slot to update progress bar value
void MainWindow::updateProgressBar(int value)
{
    ui->progressBarStatistics->setValue(value); // Update the progress bar value
}

// Slot to handle the "Statistics" button click
void MainWindow::on_statisticButton_clicked()
{
    // Get the selected location from the UI
    QString selectedLocation = ui->locationComboBox->currentText();  // Assuming there's a ComboBox for location

    // Query to count total number of factories
    QSqlQuery totalFactoriesQuery;
    totalFactoriesQuery.exec("SELECT COUNT(*) FROM FACTORY");
    totalFactoriesQuery.next();
    int totalFactories = totalFactoriesQuery.value(0).toInt();

    // Query to count the number of factories in the selected location
    QSqlQuery locationFactoriesQuery;
    locationFactoriesQuery.prepare("SELECT COUNT(*) FROM FACTORY WHERE LOCATION = :location");
    locationFactoriesQuery.bindValue(":location", selectedLocation);
    locationFactoriesQuery.exec();
    locationFactoriesQuery.next();
    int locationFactories = locationFactoriesQuery.value(0).toInt();

    if (totalFactories == 0) {
        QMessageBox::critical(this, "Error", "No factories found in the database.");
        return;
    }

    // Calculate the progress (percentage)
    int progressValue = static_cast<int>((static_cast<double>(locationFactories) / totalFactories) * 100);

    // Set the progress bar range and value
    ui->progressBarStatistics->setRange(0, 100);
    ui->progressBarStatistics->setValue(progressValue);

    // Display the location name and progress
    ui->locationLabel->setText("Location: " + selectedLocation); // Assuming you have a QLabel to show the location name
    ui->progressLabel->setText(QString::number(progressValue) + "%"); // Assuming you have a QLabel to show the progress percentage
}
