#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"client.h"

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

    void on_selectid_clicked();

    void on_pdf_clicked();

    void on_trier_clicked();

    void on_send_clicked();

private:
    Ui::MainWindow *ui;
    client cl;
};
#endif // MAINWINDOW_H

