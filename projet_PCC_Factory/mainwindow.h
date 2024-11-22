#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "factory.h"
#include <QProgressBar> // Include for progress bar

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Existing slots
    void on_filterButton_clicked(); // Slot for filter button
    void on_add_clicked();
    void on_annuler_clicked();
    void on_ajout_cl_clicked();
    void on_sup_clicked();
    void on_delete_2_clicked();
    void on_cancel_clicked();
    void on_cancl_clicked();
    void on_ajout_cl_2_clicked();
    void on_update_clicked();
    void on_update_2_clicked();
    void on_annuler_2_clicked();

    // New slot for statistics button
    void on_statisticButton_clicked(); // Slot for statistics button

    // New slot to update the progress bar
    void updateProgressBar(int value); // Slot for updating the progress bar

    // New method for PDF export
    void on_pdfButton_clicked(); // Slot for PDF button click

    // Method to update the factory count
    void updateFactoryCount(); // Declaration of the method to update factory count

private:
    Ui::MainWindow *ui;
    factory cl; // Instance of the factory class
    void on_searchLocation_textChanged(const QString &searchText);
};

#endif // MAINWINDOW_H
