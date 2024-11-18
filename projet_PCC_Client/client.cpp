#include "client.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QRegularExpression>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include<QPageSize>
#include <QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QNetworkAccessManager>
#include<QStandardItemModel>
#include "connection.h"

client::client(int id, QString name, int phone, QString email, QString adresse, int tot_ord)
{
    this->id=id;
    this->name=name;
    this->email=email;
    this->adresse=adresse;
    this->phone=phone;
    this->tot_ord=tot_ord;
}

bool client::ajouter(){
    QSqlQuery query;
    QString idstr = QString::number(id);
    QString phonestr = QString::number(phone);
    QString tot_ordstr = QString::number(tot_ord);
    if (idstr.length() != 8) {
            QMessageBox::warning(nullptr, "ERROR ADD", "Id must contain exactly 8 digits.");
            return false;
    }
    if (phonestr.length() != 8) {
            QMessageBox::warning(nullptr, "ERROR ADD", "Phone must contain exactly 8 digits.");
            return false;
    }
    /*if ((email.indexOf('@') < 0 && email.indexOf('.') < email.indexOf('@')  && email.indexOf('.') == email.length() - 1) && (email.length()>0)) {
        QMessageBox::warning(nullptr, "ERROR ADD", "Email must contain '@' in the middle and '.' after '@'.");
        return false;
    }*/
    if (email.indexOf('@') <= 0 ||                     // '@' must not be at the start or absent
        email.indexOf('.') <= email.indexOf('@') + 1 || // '.' must appear after '@' with at least one character between
        email.indexOf('.') == email.length() - 1) {    // '.' must not be the last character
        QMessageBox::warning(nullptr, "ERROR ADD", "Email must contain '@' in the middle and '.' after '@'.");
        return false;
    }



    query.prepare("INSERT INTO CLIENT (CLIENT_ID,NAME, PHONE_NUMBER, EMAIL, ADRESS, TOTAL_ORDERS) "
                      "VALUES (:id, :name, :phone, :email, :adresse, :tot_ord)");
    query.bindValue(":id", idstr);
    query.bindValue(":name", name);
    query.bindValue(":phone", phonestr);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tot_ord", tot_ordstr);

    return query.exec();

}
/*
QSqlQueryModel * client::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;

}
*/
//--------------------------------------------------affichage 2 whith number in client id and phone number------

QStandardItemModel* client::afficher()
{
    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    /*
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Phone Number"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Total Orders"));
    */
    // Execute SQL query to retrieve data
    QSqlQuery query("SELECT * FROM CLIENT");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}







bool client::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from CLIENT where CLIENT_ID= :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool client::search(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Select * from CLIENT where CLIENT_ID= :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool client::update(int id,QString name, int phone, QString email, QString adresse, int tot_ord)
{
    QSqlQuery query;
    QString idstr = QString::number(id);

    QString phonestr = QString::number(phone);
    QString tot_ordstr = QString::number(tot_ord);
    if (idstr.length() != 8) {
            QMessageBox::warning(nullptr, "ERROR ADD", "Id must contain exactly 8 digits.");
            return false;
    }
    if (phonestr.length() != 8) {
            QMessageBox::warning(nullptr, "ERROR ADD", "Phone must contain exactly 8 digits.");
            return false;
    }
    if ((email.indexOf('@') < 0 && email.indexOf('.') < email.indexOf('@')  && email.indexOf('.') == email.length() - 1) && (email.length()>0)) {
        QMessageBox::warning(nullptr, "ERROR ADD", "Email must contain '@' in the middle and '.' after '@'.");
        return false;
    }

    query.prepare("Update CLIENT set NAME= :name,PHONE_NUMBER= :phone,EMAIL= :mail,ADRESS= :adresse,TOTAL_ORDERS= :tot_ord where CLIENT_ID= :id");
    query.bindValue(":id", idstr);

    query.bindValue(":name", name);
    query.bindValue(":phone", phonestr);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tot_ord", tot_ordstr);

    return query.exec();

}

void client::pdf_downloader() {
    QPdfWriter pdf("C:/Users/amine/Downloads/client.pdf");
    QPainter painter(&pdf);

    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setPageOrientation(QPageLayout::Portrait);

    painter.fillRect(QRect(0, 0, pdf.width(), pdf.height()), QColor("light green"));

    QFont font("Client", 30, QFont::Bold);
    painter.setFont(font);
    painter.drawText(1000, 1000, "Profil du Client");

    // Content font
    QFont contentFont("Client", 14);
    painter.setFont(contentFont);

    // Database query
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT");
    query.exec();

    int x = 100;
    int y = 1900;
    int rowHeight = 600;
    int columnWidth = 1500;

    painter.setFont(QFont("Client", 12, QFont::Bold));
    painter.drawText(x, y, "𝐂𝐥𝐢𝐞𝐧𝐭 𝐈𝐃");
    painter.drawText(x + columnWidth, y, "𝐍𝐚𝐦𝐞");
    painter.drawText(x + 2 * columnWidth, y, "𝐏𝐡𝐨𝐧𝐞 𝐍𝐮𝐦𝐛𝐞𝐫");
    painter.drawText(x + 3 * columnWidth, y, "𝐄-𝐦𝐚𝐢𝐥");
    painter.drawText(x + 4 * columnWidth, y, "𝐀𝐝𝐫𝐞𝐬𝐬𝐞");
    painter.drawText(x + 5 * columnWidth, y, "𝐓𝐨𝐭𝐚𝐥 𝐎𝐫𝐝𝐞𝐫𝐬");

    // Draw line after header
    painter.drawLine(x, y + 20, x + 6 * columnWidth, y + 20);

    y += rowHeight;
    // Reset font for content
    painter.setFont(QFont("Client", 8));

    // Loop to handle multiple rows
    while (query.next()) {
        // Draw each column's data
        painter.drawText(x, y, query.value(0).toString());
        painter.drawText(x + columnWidth, y, query.value(1).toString());
        painter.drawText(x + 2 * columnWidth, y, query.value(2).toString());
        painter.drawText(x + 3 * columnWidth, y, query.value(3).toString());
        painter.drawText(x + 4 * columnWidth, y, query.value(4).toString());
        painter.drawText(x + 5 * columnWidth, y, query.value(5).toString());

        // Draw borders for the current row
        painter.drawLine(x, y - rowHeight + 20, x + 6 * columnWidth, y - rowHeight + 20); // Top border
        painter.drawLine(x, y + 20, x + 6 * columnWidth, y + 20); // Bottom border

        // Draw vertical lines between columns
        for (int i = 1; i <= 5; ++i) {
            painter.drawLine(x + i * columnWidth, y - rowHeight + 20, x + i * columnWidth, y + 20);
        }

        y += rowHeight;
    }

    // Load and scale up the logo
    QPixmap logo("C:/Users/amine/Downloads/logo2.png");
    double scaleFactor = 6.0;  // Double the logo size
    int newWidth = static_cast<int>(logo.width() * scaleFactor);
    int newHeight = static_cast<int>(logo.height() * scaleFactor);

    // Draw the scaled logo in the top-right corner
    painter.drawPixmap(pdf.width() - newWidth - 10, 10, newWidth, newHeight, logo);

    // End the painter
    painter.end();


}

QString client::count(){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM CLIENT");

    if (query.exec()) {
       if (query.next()) {
           int countValue = query.value(0).toInt();
           return QString::number(countValue);
       }
    } else {
       qDebug() << "Query failed: " << query.lastError();
    }
    return "0";

}
/*
//-----------------------------------------------------------------------------------------------

//desc
QSqlQueryModel * client::trier_tab_desc(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY TOTAL_ORDERS DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}

QSqlQueryModel * client::trier_id_desc(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY CLIENT_ID DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}

QSqlQueryModel * client::trier_name_desc(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY NAME DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}

QSqlQueryModel * client::trier_phone_desc(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY PHONE_NUMBER DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}

QSqlQueryModel * client::trier_adresse_desc(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY ADRESS DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}
QSqlQueryModel * client::trier_mail_desc(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY EMAIL DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}
//-----------------------------------------------------------------------------------------------
//Asc


QSqlQueryModel * client::trier_tab_ASC(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY TOTAL_ORDERS ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}

QSqlQueryModel * client::trier_id_ASC(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY CLIENT_ID ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}

QSqlQueryModel * client::trier_name_ASC(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY NAME ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}

QSqlQueryModel * client::trier_phone_ASC(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY PHONE_NUMBER ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}

QSqlQueryModel * client::trier_adresse_ASC(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY ADRESS ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}
QSqlQueryModel * client::trier_mail_ASC(){

    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY EMAIL ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Total Orders"));
    return model;
}
//-----------------------------------------------------------------------------------------------
*/
//-----------------------------------------------------------------------------------------------

//desc
QStandardItemModel * client::trier_tab_desc(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });

    QSqlQuery query("select * from CLIENT ORDER BY TOTAL_ORDERS DESC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;

}

QStandardItemModel * client::trier_id_desc(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY CLIENT_ID DESC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}

QStandardItemModel * client::trier_name_desc(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY NAME DESC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}

QStandardItemModel * client::trier_phone_desc(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY PHONE_NUMBER DESC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}

QStandardItemModel * client::trier_adresse_desc(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
   QSqlQuery query("select * from CLIENT ORDER BY ADRESS DESC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}
QStandardItemModel * client::trier_mail_desc(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY EMAIL DESC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}
//-----------------------------------------------------------------------------------------------
//Asc


QStandardItemModel * client::trier_tab_ASC(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY TOTAL_ORDERS ASC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}

QStandardItemModel * client::trier_id_ASC(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY CLIENT_ID ASC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}

QStandardItemModel * client::trier_name_ASC(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY NAME ASC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}

QStandardItemModel * client::trier_phone_ASC(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY PHONE_NUMBER ASC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}

QStandardItemModel * client::trier_adresse_ASC(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY ADRESS ASC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}
QStandardItemModel * client::trier_mail_ASC(){

    QStandardItemModel* model = new QStandardItemModel();

    // Set headers for each column
    model->setHorizontalHeaderLabels({
        QObject::tr("Id Client"),
        QObject::tr("Name"),
        QObject::tr("Phone Number"),
        QObject::tr("E-mail"),
        QObject::tr("Adresse"),
        QObject::tr("Total Orders")
    });
    QSqlQuery query("select * from CLIENT ORDER BY EMAIL ASC");
    int row = 0;

    // Populate the QStandardItemModel with data from the database

    while (query.next()) {
        // Create a new row of items
        QList<QStandardItem*> rowItems;

        // Id_Client: Add as a string to prevent scientific notation
        QString idClient = query.value(0).toString();
        rowItems << new QStandardItem(idClient);

        // Other columns
        rowItems << new QStandardItem(query.value(1).toString()); // Name
        rowItems << new QStandardItem(query.value(2).toString()); // Phone
        rowItems << new QStandardItem(query.value(3).toString()); // Email
        rowItems << new QStandardItem(query.value(4).toString()); // Address
        rowItems << new QStandardItem(query.value(5).toString()); // Total Orders

        // Append the row to the model
        model->appendRow(rowItems);
        row++;
    }

    return model;
}
//-----------------------------------------------------------------------------------------------

/*bool client::isPhoneInDatabase(int phone)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE PHONE_NUMBER = :phone");
    query.bindValue(":phone", phone);

    if (query.exec() && query.next()) {
        return true; // Phone exists in the database
    }
    return false; // Phone does not exist
}*/
//sms send


QString client::generateVerificationCode()
{
    int randomCode = QRandomGenerator::global()->bounded(1000, 9999); // Generates a 6-digit code
    return QString::number(randomCode);
}

/*
void client::sendSms(QString to, QString message)
{
    QString accountSid = "AC2a8e6a44fdd669ba9c4ff531ebd8d388"; // Replace with your Twilio Account SID
    QString authToken = "a8a9c3d1942bc34cab24463075fd96e7";   // Replace with your Twilio Auth Token
    QString from = "+12319163131";     // Replace with your Twilio number

    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QString url = QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(accountSid);
    QNetworkRequest request((QUrl(url)));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QString auth = QString("%1:%2").arg(accountSid, authToken).toLocal8Bit().toBase64();
    request.setRawHeader("Authorization", "Basic " + auth.toLocal8Bit());

    QUrlQuery postData;
    postData.addQueryItem("From", from);
    postData.addQueryItem("To", to);
    postData.addQueryItem("Body", message);

    QNetworkReply *reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "SMS sent successfully to " << to;
        } else {
            qDebug() << "Error sending SMS:" << reply->errorString();
        }
        reply->deleteLater();
        manager->deleteLater();
    });
}
*/
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
/*void client::sendSms( QString toPhoneNumber,  QString message)
{

    const QString accountSid = "AC2a8e6a44fdd669ba9c4ff531ebd8d388";  // Replace with your Twilio Account SID
        const QString authToken = "a8a9c3d1942bc34cab24463075fd96e7";  // Replace with your Twilio Auth Token
        const QString fromPhoneNumber = "12319163131";  // Replace with your Twilio number

        if (accountSid.isEmpty() || authToken.isEmpty() || fromPhoneNumber.isEmpty()) {
            QMessageBox::warning(nullptr, "Configuration Error", "Please configure Twilio credentials.");
            return;
        }

        // API endpoint
        QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json");
        QNetworkAccessManager* manager = new QNetworkAccessManager();
        QNetworkRequest request(apiUrl);

        // Authorization header
        QString authValue = "Basic " + QString(QByteArray(QString("%1:%2").arg(accountSid).arg(authToken).toUtf8()).toBase64());
        request.setRawHeader("Authorization", authValue.toUtf8());

        // Multi-part form data
        QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

        QHttpPart toPart;
        toPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"To\""));
        toPart.setBody(toPhoneNumber.toUtf8());

        QHttpPart fromPart;
        fromPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"From\""));
        fromPart.setBody(fromPhoneNumber.toUtf8());

        QHttpPart bodyPart;
        bodyPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"Body\""));
        bodyPart.setBody(message.toUtf8());

        multiPart->append(toPart);
        multiPart->append(fromPart);
        multiPart->append(bodyPart);

        // Send POST request
        QNetworkReply* reply = manager->post(request, multiPart);
        multiPart->setParent(reply);  // Ensure multiPart is deleted with reply

        QAbstractSocket::connect(reply, &QNetworkReply::finished, [reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                QMessageBox::information(nullptr, "Success", "SMS sent successfully!");
            } else {
                QByteArray responseData = reply->readAll();
                QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
                QString errorMessage = jsonResponse["message"].toString();

                qDebug() << "Error sending SMS:" << reply->errorString();
                qDebug() << "Twilio response:" << jsonResponse;
                QMessageBox::warning(nullptr, "Error", "Failed to send SMS: " + errorMessage);
            }
            reply->deleteLater();
        });
}*/

/*
void client::sendSms(QString toPhoneNumber, QString message)
{
    const QString accountSid = "AC2a8e6a44fdd669ba9c4ff531ebd8d388";  // Replace with your Twilio Account SID
    const QString authToken = "a8a9c3d1942bc34cab24463075fd96e7";  // Replace with your Twilio Auth Token
    const QString fromPhoneNumber = "+12319163131";  // Replace with your Twilio number

    if (accountSid.isEmpty() || authToken.isEmpty() || fromPhoneNumber.isEmpty()) {
        QMessageBox::warning(nullptr, "Configuration Error", "Please configure Twilio credentials.");
        return;
    }

    // API endpoint
    QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json");
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    QNetworkRequest request(apiUrl);

    // Authorization header (Basic Auth)
    QString authValue = "Basic " + QString(QByteArray(QString("%1:%2").arg(accountSid).arg(authToken).toUtf8()).toBase64());
    request.setRawHeader("Authorization", authValue.toUtf8());

    // Multi-part form data for the SMS
    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    // "To" part
    QHttpPart toPart;
    toPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"To\""));
    toPart.setBody(toPhoneNumber.toUtf8());

    // "From" part (Twilio number)
    QHttpPart fromPart;
    fromPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"From\""));
    fromPart.setBody(fromPhoneNumber.toUtf8());

    // "Body" part (Message content)
    QHttpPart bodyPart;
    bodyPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"Body\""));
    bodyPart.setBody(message.toUtf8());

    // Append the parts to the multi-part form
    multiPart->append(toPart);
    multiPart->append(fromPart);
    multiPart->append(bodyPart);

    // Send the POST request
    QNetworkReply* reply = manager->post(request, multiPart);
    multiPart->setParent(reply);  // Ensure multiPart is deleted with the reply

    // Connect to the finished signal to handle the response
    QAbstractSocket::connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Success: Show success message
            QMessageBox::information(nullptr, "Success", "SMS sent successfully!");
        } else {
            // Failure: Read the response and handle the error
            QByteArray responseData = reply->readAll();
            qDebug() << "Error sending SMS:" << reply->errorString();
            qDebug() << "Response Data:" << responseData;

            // Parse JSON response (if the response is JSON formatted)
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            if (!jsonResponse.isNull()) {
                QString errorMessage = jsonResponse["message"].toString();
                QMessageBox::warning(nullptr, "Error", "Failed to send SMS: " + errorMessage);
            } else {
                QMessageBox::warning(nullptr, "Error", "Failed to send SMS. Unknown error.");
            }
        }

        // Clean up
        reply->deleteLater();
    });
}*/
void client::sendSms(QString toPhoneNumber, QString message)
{
    const QString accountSid = "AC2a8e6a44fdd669ba9c4ff531ebd8d388";  // Replace with your Twilio Account SID
    const QString authToken = "a8a9c3d1942bc34cab24463075fd96e7";     // Replace with your Twilio Auth Token
    const QString fromPhoneNumber = "+12319163131";                   // Replace with your Twilio number

    if (accountSid.isEmpty() || authToken.isEmpty() || fromPhoneNumber.isEmpty()) {
        QMessageBox::warning(nullptr, "Configuration Error", "Please configure Twilio credentials.");
        return;
    }

    // Automatically prepend +216 if not included
    if (!toPhoneNumber.startsWith("+216")) {
        if (toPhoneNumber.length() == 8) { // Tunisian phone numbers are 8 digits long
            toPhoneNumber = "+216" + toPhoneNumber;
        } else {
            QMessageBox::warning(nullptr, "Phone Number Error", "Invalid Tunisian phone number. It should be 8 digits or start with +216.");
            return;
        }
    }

    // Validate phone number length after formatting
    if (toPhoneNumber.length() != 12) {  // +216 followed by 8 digits
        QMessageBox::warning(nullptr, "Phone Number Error", "Invalid Tunisian phone number format.");
        return;
    }

    // Twilio API endpoint
    QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json");
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    QNetworkRequest request(apiUrl);

    // Authorization header (Basic Auth)
    QString authValue = "Basic " + QString(QByteArray(QString("%1:%2").arg(accountSid).arg(authToken).toUtf8()).toBase64());
    request.setRawHeader("Authorization", authValue.toUtf8());

    // Multi-part form data for the SMS
    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    // "To" part
    QHttpPart toPart;
    toPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"To\""));
    toPart.setBody(toPhoneNumber.toUtf8());

    // "From" part (Twilio number)
    QHttpPart fromPart;
    fromPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"From\""));
    fromPart.setBody(fromPhoneNumber.toUtf8());

    // "Body" part (Message content)
    QHttpPart bodyPart;
    bodyPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"Body\""));
    bodyPart.setBody(message.toUtf8());

    // Append the parts to the multi-part form
    multiPart->append(toPart);
    multiPart->append(fromPart);
    multiPart->append(bodyPart);

    // Send the POST request
    QNetworkReply* reply = manager->post(request, multiPart);
    multiPart->setParent(reply);  // Ensure multiPart is deleted with the reply

    // Handle the response
    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Success: Show success message
            QMessageBox::information(nullptr, "Success", "SMS sent successfully!");
        } else {
            // Failure: Read the response and handle the error
            QByteArray responseData = reply->readAll();
            qDebug() << "Error sending SMS:" << reply->errorString();
            qDebug() << "Response Data:" << responseData;

            // Parse JSON response (if the response is JSON formatted)
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            if (!jsonResponse.isNull()) {
                QString errorMessage = jsonResponse["message"].toString();
                QMessageBox::warning(nullptr, "Error", "Failed to send SMS: " + errorMessage);
            } else {
                QMessageBox::warning(nullptr, "Error", "Failed to send SMS. Unknown error.");
            }
        }

        // Clean up
        reply->deleteLater();
    });
}






//send e-mail
/*
bool client::emailExists(QString email)
{
    QSqlQuery query;
    query.prepare("SELECT EMAIL FROM CLIENT WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        return true;  // Email found
    }
    return false;  // Email not found
}

*/






SmtpClient::SmtpClient(QObject *parent)
    : QObject(parent)
{
}

SmtpClient::~SmtpClient()
{
}
/*
void SmtpClient::sendEmail( QString from, QString to,  QString subject,QString message)
{
    // Sample SMTP details (use your own SMTP server)
    QString smtpHost = "smtp.gmail.com";  // Example: Gmail
    int smtpPort = 587;  // Port for TLS/STARTTLS

    // Create socket and connect to the SMTP server
    QTcpSocket socket;
    socket.connectToHost(smtpHost, smtpPort);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Failed to connect to the SMTP server.";
        return;
    }

    // Send EHLO to the server (SMTP greeting)
    if (!sendCommand(socket, "EHLO localhost\r\n", "250")) {
        qDebug() << "Failed to send EHLO command.";
        return;
    }

    // Send MAIL FROM
    if (!sendCommand(socket, QString("MAIL FROM:<%1>\r\n").arg(from), "250")) {
        qDebug() << "Failed to send MAIL FROM command.";
        return;
    }

    // Send RCPT TO
    if (!sendCommand(socket, QString("RCPT TO:<%1>\r\n").arg(to), "250")) {
        qDebug() << "Failed to send RCPT TO command.";
        return;
    }

    // Send DATA command to start email body
    if (!sendCommand(socket, "DATA\r\n", "354")) {
        qDebug() << "Failed to start email data.";
        return;
    }

    // Prepare the email content and send
    QString emailContent = QString("From: %1\r\nTo: %2\r\nSubject: %3\r\n\r\n%4\r\n.\r\n")
        .arg(from, to, subject, message);
    socket.write(emailContent.toUtf8());
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    QString response = socket.readAll();
    if (!response.startsWith("250")) {
        qDebug() << "Failed to send the email content.";
        return;
    }

    // Send QUIT command to close the connection
    if (!sendCommand(socket, "QUIT\r\n", "221")) {
        qDebug() << "Failed to close the connection.";
        return;
    }

    // Email sent successfully
    qDebug() << "Your email has been sent successfully!";
}
*/
#include <QSslSocket>
#include <QDebug>
#include <QByteArray>
#include <QTextStream>

bool SmtpClient::sendEmail(QString &from, QString &to, QString &subject, QString &message)
{
    QString smtpHost = "smtp.gmail.com";  // Gmail SMTP server
    int smtpPort = 465;  // SSL port for Gmail

    QSslSocket socket;
    socket.connectToHostEncrypted(smtpHost, smtpPort);  // Use SSL for the connection

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Failed to connect to the SMTP server.";
        return false;
    }

    // Read the server's initial greeting (220 response)
    QString serverGreeting = socket.readAll();
    qDebug() << "Server greeting:" << serverGreeting;
    if (!serverGreeting.startsWith("220")) {
        qDebug() << "Unexpected greeting response:" << serverGreeting;
        return false;
    }

    // Send EHLO to the server (SMTP greeting)
    if (!sendCommand(socket, "EHLO localhost\r\n", "250")) {
        return false;
    }

    // Start Authentication (AUTH LOGIN for Gmail)
    if (!sendCommand(socket, "AUTH LOGIN\r\n", "334")) {
        return false;
    }

    // Send base64 encoded username (email address)
    QString base64Username = QString(from).toUtf8().toBase64();
    if (!sendCommand(socket, base64Username + "\r\n", "334")) {
        return false;
    }

    // Send base64 encoded app-specific password (replace this with OAuth token if possible)
    QString base64Password = "cgblexibxglxmdyt";  // Replace with actual app-specific password (or OAuth token)
    if (!sendCommand(socket, base64Password + "\r\n", "235")) {
        return false;
    }

    // Send MAIL FROM command
    if (!sendCommand(socket, QString("MAIL FROM:<%1>\r\n").arg(from), "250")) {
        return false;
    }

    // Send RCPT TO command
    if (!sendCommand(socket, QString("RCPT TO:<%1>\r\n").arg(to), "250")) {
        return false;
    }

    // Send DATA command to start email body
    if (!sendCommand(socket, "DATA\r\n", "354")) {
        return false;
    }

    // Prepare the email content and send
    QString emailContent = QString("From: %1\r\nTo: %2\r\nSubject: %3\r\n\r\n%4\r\n.\r\n")
        .arg(from, to, subject, message);
    if (!sendCommand(socket, emailContent.toUtf8(), "250")) {
        return false;
    }

    // Send QUIT command to close the connection
    if (!sendCommand(socket, "QUIT\r\n", "221")) {
        return false;
    }

    return true;  // Return true if email was sent successfully
}

/*
bool SmtpClient::sendCommand(QSslSocket &socket, const QString &command, const QString &expectedResponse)
{
    socket.write(command.toUtf8());
    if (!socket.waitForBytesWritten(5000)) {
        qDebug() << "Failed to write command:" << command;
        return false;
    }
    if (!socket.waitForReadyRead(5000)) {
        qDebug() << "No response for command:" << command;
        return false;
    }
    QString response = socket.readAll();
    if (!response.startsWith(expectedResponse)) {
        qDebug() << "Unexpected response:" << response;
        return false;
    }
    return true;
}
*/
bool SmtpClient::sendCommand(QSslSocket &socket, const QString &command, const QString &expectedResponse)
{
    // Write the command to the socket
    socket.write(command.toUtf8());

    // Wait for the command to be written
    if (!socket.waitForBytesWritten(5000)) {
        qDebug() << "Failed to write command:" << command;
        return false;
    }

    // Wait for the server's response
    if (!socket.waitForReadyRead(5000)) {
        qDebug() << "No response for command:" << command;
        return false;
    }

    // Read the response from the server
    QString response = socket.readAll();

    // Log the response for debugging purposes
    qDebug() << "Server response:" << response;

    // Check if the response starts with the expected response code
    if (!response.startsWith(expectedResponse)) {
        qDebug() << "Unexpected response:" << response;
        return false;
    }

    return true;
}


