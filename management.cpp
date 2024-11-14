#include "management.h"
#include "mainwindow.h"
#include "employee.h"
#include "ui_management.h"

management::management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::management)
{
    ui->setupUi(this);
    ui->main->setCurrentIndex(0);
    connect(ui->table, &QTableWidget::itemDoubleClicked, this, &management::onTableItemDoubleClicked);
    connect(ui->search_field, &QLineEdit::returnPressed, this, &management::on_searchConfirm);
}

management::~management()
{
    delete ui;
}

/*--------------SIDEBAR-ROUTING--------------*/

void management::on_dahsboard_clicked()
{
    ui->main->setCurrentIndex(0);
}
void management::on_employees_clicked()
{
    ui->main->setCurrentIndex(1);
    ui->employee->setCurrentIndex(0);
    Employee employee;
    employee.readEmployee(ui->table);
    updateProgressBars();
}
void management::on_factories_clicked()
{
    ui->main->setCurrentIndex(2);
    ui->factory->setCurrentIndex(0);
}
void management::on_machines_clicked()
{
    ui->main->setCurrentIndex(3);
    ui->machiness->setCurrentIndex(0);
}
void management::on_deliveries_clicked()
{
    ui->main->setCurrentIndex(4);
    ui->delivery->setCurrentIndex(0);
}
void management::on_clients_clicked()
{
    ui->main->setCurrentIndex(5);
    ui->client->setCurrentIndex(0);
}

/*--------------DEFAULT-TO-ADD-NEW-ROUTING--------------*/

void management::on_add_employee_btn_clicked()
{
    ui->employee->setCurrentIndex(1);
}
void management::on_add_client_btn_clicked()
{
    ui->client->setCurrentIndex(1);
}
void management::on_add_delivery_btn_clicked()
{
    ui->delivery->setCurrentIndex(1);
}
void management::on_add_factory_btn_clicked()
{
   ui->factory->setCurrentIndex(1);
}
void management::on_add_machine_btn_clicked()
{
    ui->machiness->setCurrentIndex(1);
}

/*--------------EMPLOYEE FUNCTIONS---------------*/

// Confirm and add a new employee
void management::on_confirm_employee_btn_clicked()
{
    QString name = ui->name_field->text();
    QString email = ui->email_field->text();
    int phone = ui->phone_field->text().toInt();
    QString position = ui->position_field->currentText();
    Employee emp;
    Employee newEmployee(name, email, position, phone);
    if (newEmployee.createEmployee()) {
        qDebug() << "Employee creation process completed successfully.";
        ui->name_field->clear();
        ui->email_field->clear();
        ui->phone_field->clear();
        ui->position_field->setCurrentIndex(0);
        Employee employee;
        employee.readEmployee(ui->table);
        ui->employee->setCurrentIndex(0);
    } else {
        qDebug() << "Employee creation process failed.";
    }
    updateProgressBars();
}

// Navigate back in history
void management::on_history_back_clicked()
{
    ui->employee->setCurrentIndex(0);
}
void management::on_update_back_clicked()
{
    ui->employee->setCurrentIndex(0);
}
void management::on_add_back_clicked()
{
    ui->employee->setCurrentIndex(0);
}

// Export employee data (function to be implemented)
void management::on_employee_export_clicked()
{
    Employee employee;
    employee.readEmployee(ui->table);
    QTableWidget *tableH = ui->tableH;  // Replace with your actual table object
    employee.exportPresence(tableH); }

void management::on_update_employee_btn_clicked()
{

    int selectedRow = ui->table->currentRow();
    if (selectedRow != -1) { // Check if a row is selected
        QString name = ui->table->item(selectedRow, 1)->text();
        QString email = ui->table->item(selectedRow, 2)->text();
        int phone = ui->table->item(selectedRow, 3)->text().toInt();
        QString position = ui->table->item(selectedRow, 4)->text();
        QString employeeId = ui->table->item(selectedRow, 0)->text();

        ui->name_update->setText(name);
        ui->email_update->setText(email);
        ui->phone_update->setText(QString::number(phone));
        ui->position_update->setCurrentText(position);
        ui->employee->setCurrentIndex(2);

    }
}

// Confirm update to employee data
void management::on_confirm_update_btn_clicked()
{
    QString name = ui->name_update->text();
    QString email = ui->email_update->text();
    int phone = ui->phone_update->text().toInt();
    QString position = ui->position_update->currentText();
    int selectedRow = ui->table->currentRow();
    QString employeeId = ui->table->item(selectedRow, 0)->text();

    Employee employee;
    employee.setName(name);
    employee.setEmail(email);
    employee.setPhoneNumber(phone);
    employee.setPosition(position);

    if (employee.updateEmployee(employeeId)) {
        qDebug() << "Employee update process completed successfully.";
        ui->name_update->clear();
        ui->email_update->clear();
        ui->phone_update->clear();
        ui->position_update->setCurrentIndex(0);
        ui->employee->setCurrentIndex(0);
        ui->table->setRowCount(0);
        Employee employee;
        employee.readEmployee(ui->table);
    } else {
        qDebug() << "Employee update process failed.";
    }
    updateProgressBars();
}

// Delete employee logic
void management::on_delete_employee_btn_clicked()
{
    int selectedRow = ui->table->currentRow();
    Employee employee;
    QString employeeId = ui->table->item(selectedRow, 0)->text();

    if (employee.deleteEmployee(employeeId)) {
        qDebug() << "Employee deletion process completed successfully.";
        employee.readEmployee(ui->table);
    } else {
        qDebug() << "Employee deletion process failed.";
    }
    employee.readEmployee(ui->table);
    updateProgressBars();
}


void management::on_searchConfirm()
{
    Employee employee;
    QString type = ui->search->currentText();
    QString searchText = ui->search_field->text();
    QTableWidget *table = ui->table;
    QSqlQueryModel *model = employee.rechercher(type, searchText);

    if (model) {
        table->setRowCount(0);
        table->setColumnCount(model->columnCount());

        // Populate the QTableWidget with data from the model
        int rowCount = model->rowCount();
        int columnCount = model->columnCount();

        for (int row = 0; row < rowCount; ++row) {
            table->insertRow(row);  // Insert new row in the table

            for (int col = 0; col < columnCount; ++col) {
                // Create a new item for each cell and set its text from the model's data
                QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
                item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                table->setItem(row, col, item);
            }
        }

        int fixedHeight = 40;
        for (int i = 0; i < table->rowCount(); ++i) {
            table->setRowHeight(i, fixedHeight);
        }
        table->setSortingEnabled(true);
    } else {
        qDebug() << "No results found.";
    }
}

void management::on_searchReset_clicked()
{
    ui->search_field->clear();
    ui->table->setRowCount(0);
    Employee employee;
    employee.readEmployee(ui->table);
    ui->employee->setCurrentIndex(0);
}

void management::onTableItemDoubleClicked(QTableWidgetItem *item) {
    QString employeeIdStr = ui->table->item(item->row(), 0)->text();
    Employee employee;
    ui->employee->setCurrentIndex(3);
    QTableWidget *historiqueTable = ui->tableH;
    employee.readHistorique(historiqueTable, employeeIdStr);
}


void management::on_logout_clicked()
{
    this->hide();
    MainWindow *mainWindow = new MainWindow();
     mainWindow->show();
}

void management::updateProgressBars() {
    int techCount = 0;
    int chefCount = 0;
    int managerCount = 0;
    int totalCount = 1;  // Initialize to 1 to avoid division by zero

    QSqlQuery query;

    // Get total count of employees
    if (query.exec("SELECT COUNT(*) FROM employee")) {
        if (query.next()) {
            totalCount = query.value(0).toInt();
            qDebug() << "Total count:" << totalCount;
        }
    } else {
        qDebug() << "Total count query failed:" << query.lastError().text();
    }

    // Set progress bars to 0 if no employees are found
    if (totalCount == 0) {
        ui->progressBar1->setValue(0);
        ui->progressBar2->setValue(0);
        ui->progressBar3->setValue(0);
        return;
    }
    // Get count of employees with position 'Tech'
    if (query.exec("SELECT COUNT(*) FROM employee WHERE position = 'Tech'")) {
        if (query.next()) {
            techCount = query.value(0).toInt();
            qDebug() << "Tech count:" << techCount;
        }
    } else {
        qDebug() << "Tech count query failed:" << query.lastError().text();
    }

    // Get count of employees with position 'Chef'
    if (query.exec("SELECT COUNT(*) FROM employee WHERE position = 'Chef'")) {
        if (query.next()) {
            chefCount = query.value(0).toInt();
            qDebug() << "Chef count:" << chefCount;
        }
    } else {
        qDebug() << "Chef count query failed:" << query.lastError().text();
    }

    // Get count of employees with position 'Manager'
    if (query.exec("SELECT COUNT(*) FROM employee WHERE position = 'Manager'")) {
        if (query.next()) {
            managerCount = query.value(0).toInt();
            qDebug() << "Manager count:" << managerCount;
        }
    } else {
        qDebug() << "Manager count query failed:" << query.lastError().text();
    }

    // Calculate percentages for each position and update progress bars
    int technicianPercentage = (techCount * 100) / totalCount;
    int chefCuisinePercentage = (chefCount * 100) / totalCount;
    int managerPercentage = (managerCount * 100) / totalCount;

    ui->progressBar1->setValue(technicianPercentage);
    ui->progressBar2->setValue(chefCuisinePercentage);
    ui->progressBar3->setValue(managerPercentage);
}


