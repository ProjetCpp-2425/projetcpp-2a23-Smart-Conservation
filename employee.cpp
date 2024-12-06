#include "employee.h"

// Constructor
Employee::Employee(QString name, QString email, QString position, int phoneNumber) {
    setName(name);
    setEmail(email);
    setPosition(position);
    setPhoneNumber(phoneNumber);
}

bool Employee::createEmployee() {
    // Validate name
    if (getName().isEmpty()) {
        QMessageBox::warning(nullptr, "Input Error", "Name cannot be empty.");
        return false;
    }
    // Validate email with a simple regex
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(getEmail()).hasMatch()) {
        QMessageBox::warning(nullptr, "Input Error", "Please enter a valid email address.");
        return false;
    }
    // Validate phone number: check for 8 digits only
    QString phoneStr = QString::number(getPhoneNumber());
    if (phoneStr.length() != 8 || !phoneStr.contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(nullptr, "Input Error", "Phone number must be exactly 8 digits.");
        return false;
    }

    // Validate position
    if (getPosition().isEmpty()) {
        QMessageBox::warning(nullptr, "Input Error", "Position cannot be empty.");
        return false;
    }

    // Check if the employee already exists in the database
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employee WHERE email = :email AND phone_number = :phone");
    checkQuery.bindValue(":email", getEmail());
    checkQuery.bindValue(":phone", getPhoneNumber());

    if (checkQuery.exec()) {
        if (checkQuery.next() && checkQuery.value(0).toInt() > 0) {
            qDebug() << "Employee already exists!";
            QMessageBox::warning(nullptr, "Confirmation Error", "Employee already exists!");
            return false;
        }
    } else {
        qDebug() << "Failed to check for existing employee:" << checkQuery.lastError().text();
        QMessageBox::critical(nullptr, "Query Failed", "Failed to check for existing employee.");
        return false;
    }

    // Insert the new employee into the database
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO employee (name, email, phone_number, position) "
                        "VALUES (:name, :email, :phone, :position)");
    insertQuery.bindValue(":name", getName());
    insertQuery.bindValue(":email", getEmail());
    insertQuery.bindValue(":phone", getPhoneNumber());
    insertQuery.bindValue(":position", getPosition());

    if (insertQuery.exec()) {
        QMessageBox::information(nullptr, "Success", "Employee added successfully.");
        return true;
    } else {
        qDebug() << "Employee insertion failed:" << insertQuery.lastError().text();
        QMessageBox::critical(nullptr, "Insertion Failed", "Employee insertion failed.");
        return false;
    }
}

void Employee::readEmployee(QTableWidget *table) {
    // Clear the table before adding new data
    table->setRowCount(0);
    table->setColumnCount(5);

    QSqlQuery query;
    query.prepare("SELECT employee_id, name, email, phone_number, position FROM employee");

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);

            for (int column = 0; column < 5; ++column) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(column).toString());
                item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                table->setItem(row, column, item);
            }
            row++;
        }
    } else {
        qDebug() << "Failed to execute readEmployee query:" << query.lastError().text();
    }
    int fixedHeight = 40;
    for (int i = 0; i < table->rowCount(); ++i) {
        table->setRowHeight(i, fixedHeight);
    }
}

void Employee::readHistorique(QTableWidget *tableH, QString employeeId) {
    tableH->setRowCount(0);
    tableH->setColumnCount(3);

    QStringList headers = {"Presence ID", "Employee ID", "Check-In", /*"Check-Out", "Working Hours"*/};
    tableH->setHorizontalHeaderLabels(headers);
    tableH->horizontalHeader()->setDefaultSectionSize(163);

    QSqlQuery query;
    query.prepare("SELECT PRESENCEID, EMPLOYEEID, CHECK_IN, CHECK_OUT, WORKING_HOURS FROM TableH WHERE EMPLOYEEID = :employeeId");
    query.bindValue(":employeeId", employeeId);

    if (query.exec()) {
        int row = 0;
        if (!query.next()) {
            qDebug() << "No data found for employee ID:" << employeeId;
            QTableWidgetItem *item = new QTableWidgetItem("No data found");
            tableH->setItem(0, 0, item);
            return;
        }
        do {
            tableH->insertRow(row);

            for (int column = 0; column < 3; ++column) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(column).toString());
                //item->setTextAlignment(/*Qt::AlignLeft |*/ Qt::AlignVCenter);
                if (column == 2 || column == 3) {  // Check-In and Check-Out columns
                    QDateTime datetime = query.value(column).toDateTime();
                    item->setText(datetime.toString("yyyy-MM-dd HH:mm:ss"));
                }

                tableH->setItem(row, column, item);
            }
            row++;
        } while (query.next());

        tableH->setSortingEnabled(true);

        int fixedHeight = 40;
        for (int i = 0; i < tableH->rowCount(); ++i) {
            tableH->setRowHeight(i, fixedHeight);
        }
    } else {
        qDebug() << "Failed to execute readHistorique query:" << query.lastError().text();
    }
}






bool Employee::updateEmployee(QString employeeId)
{
    if (getName().isEmpty()) {
        QMessageBox::warning(nullptr, "Input Error", "Name cannot be empty.");
        return false;
    }

    // Validate email with a simple regex
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(getEmail()).hasMatch()) {
        QMessageBox::warning(nullptr, "Input Error", "Please enter a valid email address.");
        return false;
    }

    // Validate phone number: check for 8 digits only
    QString phoneStr = QString::number(getPhoneNumber());
    if (phoneStr.length() != 8 || !phoneStr.contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(nullptr, "Input Error", "Phone number must be exactly 8 digits.");
        return false;
    }

    // Validate position
    if (getPosition().isEmpty()) {
        QMessageBox::warning(nullptr, "Input Error", "Position cannot be empty.");
        return false;
    }

    QSqlQuery updateQuery;

    // Prepare the SQL query to update employee data based on employee ID
    updateQuery.prepare("UPDATE employee SET name = :name, email = :email, phone_number = :phone, position = :position WHERE employee_id = :id");

    // Bind values from the Employee object
    updateQuery.bindValue(":name", getName());
    updateQuery.bindValue(":email", getEmail());
    updateQuery.bindValue(":phone", getPhoneNumber());
    updateQuery.bindValue(":position", getPosition());

    // Bind the employee ID (the first column in your table)
    updateQuery.bindValue(":id", employeeId);
    // Execute the query and provide feedback
    if (updateQuery.exec()) {
        QMessageBox::information(nullptr, "Success", "Employee updated successfully.");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Update Failed", "Failed to update employee.");
        return false;
    }
}

bool Employee::deleteEmployee(const QString &employeeId) {
    QSqlQuery deletePresenceQuery;
    QSqlQuery deleteEmployeeQuery;

    // Delete all occurrences of the employee ID in the presence table
    deletePresenceQuery.prepare("DELETE FROM presence WHERE employee_id = :id");
    deletePresenceQuery.bindValue(":id", employeeId);

    if (!deletePresenceQuery.exec()) {
        QMessageBox::critical(nullptr, "Delete Failed", "Failed to delete entries from presence.");
        return false;
    }

    // After successfully deleting from presence, delete the employee row in the employee table
    deleteEmployeeQuery.prepare("DELETE FROM employee WHERE employee_id = :id");
    deleteEmployeeQuery.bindValue(":id", employeeId);

    if (deleteEmployeeQuery.exec()) {
        QMessageBox::information(nullptr, "Success", "Employee deleted successfully.");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Delete Failed", "Failed to delete employee.");
        return false;
    }
}



QSqlQueryModel* Employee::rechercher(const QString &type, const QString &text)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    if (type == "name") {
        query.prepare("SELECT * FROM employee WHERE name LIKE :text");
        query.bindValue(":text", "%" + text + "%");
    } else if (type == "id") {
        query.prepare("SELECT * FROM employee WHERE employee_id LIKE :text");
        query.bindValue(":text", "%" + text + "%");
    } else {
        // Return an empty model or handle the case if type is neither "name" nor "id"
        return model;
    }

    if (!query.exec()) {
        // Handle error (optional)
        qDebug() << "Query Error:" << query.lastError().text();
    }
    model->setQuery(std::move(query));

    return model;
}
void Employee::exportPresence(QTableWidget *tableH)
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save as PDF", "", "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return;  // Exit if the user cancels
    }

    // Check and append .pdf if not present
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath.append(".pdf");
    }

    // Create the printer object
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);  // Set the file path from the dialog
    printer.setPageSize(QPageSize(QPageSize::A4));

    QPainter painter;

    if (!painter.begin(&printer)) { // Failed to open file
        qWarning("Failed to open file, is it writable?");
        return;
    }

    // Set rendering hints for smoother text and shapes
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

//    QImage backgroundImage(":/images/background.png");
//       if (backgroundImage.isNull()) {
//           qWarning("Background image not found!");
//       }
//       QRect pageRect = printer.pageRect(QPrinter::DevicePixel).toRect();
//       painter.drawImage(pageRect.topLeft(), backgroundImage);

           QImage logoImage(":/images/iconh.png");
           if (logoImage.isNull()) {
               qWarning("Logo image not found!");
           }

           // Manually set coordinates and size for logo
           int logoX = 250;
           int logoY = 20;
           painter.drawImage(logoX, logoY, logoImage);



    // Title manually positioned below the logo
    QFont titleFont("Lexend", 18, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(Qt::darkGreen);

    // Title X, Y, width, height
    int titleX = 250;
    int titleY = 120;
    int titleWidth = 300;
    int titleHeight = 50;
    painter.drawText(QRect(titleX, titleY, titleWidth, titleHeight), Qt::AlignCenter, "Employee History");

    // Draw table headers manually
    QFont headerFont("Lexend", 10, QFont::Bold);
    painter.setFont(headerFont);
    painter.setPen(Qt::black);
    int headerY = 220;  // Y-coordinate for header

    // Header X-coordinates manually set
    int column1X = 40;
    int column2X = 150;
    int column3X = 270;
    int column4X = 410;
    int column5X = 550;
    int column6X = 680;

    // Manually set column headers with specific X and Y coordinates
    painter.drawText(column1X, headerY, "Presence ID");
    painter.drawText(column2X, headerY, "Employee ID");
    painter.drawText(column3X, headerY, "Check In");
    painter.drawText(column4X, headerY, "Check Out");
    painter.drawText(column5X, headerY, "Working Hours");
    painter.drawText(column6X, headerY, "Status");

    // Set the font for the table content
    QFont contentFont("Lexend", 9);
    painter.setFont(contentFont);
    painter.setPen(Qt::black);

    // Read the data from QTableWidget (tableH) and export it
    int rowY = headerY + 40;  // Starting vertical position for the first row
    int rowCount = tableH->rowCount();

    // Loop through the rows of the table and export the data to PDF
    for (int row = 0; row < rowCount; ++row) {
        // Manually set x-coordinates for each column cell
        QString presenceID = tableH->item(row, 0) ? tableH->item(row, 0)->text() : "";
        QString employeeID = tableH->item(row, 1) ? tableH->item(row, 1)->text() : "";
        QString checkIn = tableH->item(row, 2) ? tableH->item(row, 2)->text() : "";
        QString checkOut = tableH->item(row, 3) ? tableH->item(row, 3)->text() : "";
        QString workingHours = tableH->item(row, 4) ? tableH->item(row, 4)->text() : "";
        QString status = tableH->item(row, 5) ? tableH->item(row, 5)->text() : "";

        // Draw table cells for each row
        painter.drawText(column1X, rowY, presenceID);
        painter.drawText(column2X, rowY, employeeID);
        painter.drawText(column3X, rowY, checkIn);
        painter.drawText(column4X, rowY, checkOut);
        painter.drawText(column5X, rowY, workingHours);
        painter.drawText(column6X, rowY, status);

        // Increment the Y-coordinate for the next row
        rowY += 20;  // Adjust vertical space between rows as needed
    }
    painter.end();
}
