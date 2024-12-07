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
#include <QFileDialog>

#include <QSslSocket>
#include <QDebug>
#include <QByteArray>
#include <QTextStream>

#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QJsonObject>
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

    if (email.indexOf('@') <= 0 || email.indexOf('.') <= email.indexOf('@') + 1 ||  email.indexOf('.') == email.length() - 1) {
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
/*
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


}*/
void client::pdf_downloader() {
    QString filePath = QFileDialog::getSaveFileName(
        nullptr,
        "Enregistrer le profil du client",
        "",
        "PDF Files (*.pdf);;Text Files (*.txt);;All Files (*)"
    );

    if (filePath.isEmpty())
        return;

    QFileInfo fileInfo(filePath);
    QString extension = fileInfo.suffix();

    if (extension.isEmpty()) {
        // Par défaut, utiliser PDF si aucune extension n'est fournie
        filePath += ".pdf";
        extension = "pdf";
    }

    if (extension.toLower() == "pdf") {
        // Gérer la création du PDF
        QPdfWriter pdfWriter(filePath);
        QPainter painter(&pdfWriter);

        pdfWriter.setPageSize(QPageSize(QPageSize::A4));
        pdfWriter.setPageOrientation(QPageLayout::Portrait);

        painter.fillRect(QRect(0, 0, pdfWriter.width(), pdfWriter.height()), QColor("light green"));

        QFont font("Client", 30, QFont::Bold);
        painter.setFont(font);
        painter.drawText(1000, 1000, "Profil du Client");

        // Police pour le contenu
        QFont contentFont("Client", 14);
        painter.setFont(contentFont);

        // Requête base de données
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

        painter.drawLine(x, y + 20, x + 6 * columnWidth, y + 20);

        y += rowHeight;
        painter.setFont(QFont("Client", 8));

        while (query.next()) {
            painter.drawText(x, y, query.value(0).toString());
            painter.drawText(x + columnWidth, y, query.value(1).toString());
            painter.drawText(x + 2 * columnWidth, y, query.value(2).toString());
            painter.drawText(x + 3 * columnWidth, y, query.value(3).toString());
            painter.drawText(x + 4 * columnWidth, y, query.value(4).toString());
            painter.drawText(x + 5 * columnWidth, y, query.value(5).toString());

            painter.drawLine(x, y - rowHeight + 20, x + 6 * columnWidth, y - rowHeight + 20);
            painter.drawLine(x, y + 20, x + 6 * columnWidth, y + 20);

            for (int i = 1; i <= 5; ++i) {
                painter.drawLine(x + i * columnWidth, y - rowHeight + 20, x + i * columnWidth, y + 20);
            }

            y += rowHeight;
        }

        QPixmap logo("C:/Users/amine/Downloads/logo2.png");
        double scaleFactor = 6.0;
        int newWidth = static_cast<int>(logo.width() * scaleFactor);
        int newHeight = static_cast<int>(logo.height() * scaleFactor);

        painter.drawPixmap(pdfWriter.width() - newWidth - 10, 10, newWidth, newHeight, logo);
        painter.end();

    } else if (extension.toLower() == "txt") {
        // Gérer la création d'un fichier texte
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // Requête base de données
            QSqlQuery query;
            query.prepare("SELECT * FROM CLIENT");
            query.exec();

            out << "Client ID\tName\tPhone Number\tEmail\tAdresse\tTotal Orders\n";

            while (query.next()) {
                out << query.value(0).toString() << "\t"
                    << query.value(1).toString() << "\t"
                    << query.value(2).toString() << "\t"
                    << query.value(3).toString() << "\t"
                    << query.value(4).toString() << "\t"
                    << query.value(5).toString() << "\n";
            }

            file.close();
        } else {
            qDebug() << "Unable to open file for writing.";
        }
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Type de fichier non pris en charge !");
    }
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

bool client::isPhoneInDatabase(int phone)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE PHONE_NUMBER = :phone");
    query.bindValue(":phone", phone);

    if (query.exec() && query.next()) {
        return true; // Phone exists in the database
    }
    return false; // Phone does not exist
}
//sms send


QString client::generateVerificationCode()
{
    int randomCode = QRandomGenerator::global()->bounded(1000, 9999);
    return QString::number(randomCode);
}

void client::sendSms(QString toPhoneNumber, QString message)
{
    const QString accountSid = "AC2a8e6a44fdd669ba9c4ff531ebd8d388";
    const QString authToken = "a8a9c3d1942bc34cab24463075fd96e7";
    const QString fromPhoneNumber = "+12319163131";

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
bool client::searchcl(QString name){

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM CLIENT WHERE NAME=:name");
    query.bindValue(":name",name);
    return query.exec();
}

QStandardItemModel * client::affichercl(QString name){
    QSqlQuery query;
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
    query.prepare("SELECT * FROM CLIENT WHERE NAME=:name");
    query.bindValue(":name", name);
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
QString client::countname(QString name){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM CLIENT WHERE NAME=:name");
    query.bindValue(":name", name);
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



QPieSeries* client::generateClientStatistics() {
    // Create a QPieSeries
    QPieSeries *series = new QPieSeries();

    // Fetch data from the database
    QSqlQuery query;
    int clientsWithOrders = 0;
    int clientsWithoutOrders = 0;

    query.exec("SELECT COUNT(*) FROM CLIENT WHERE total_orders > 0");
    if (query.next()) {
        clientsWithOrders = query.value(0).toInt();
    }

    query.exec("SELECT COUNT(*) FROM CLIENT WHERE total_orders = 0");
    if (query.next()) {
        clientsWithoutOrders = query.value(0).toInt();
    }

    int totalClients = clientsWithOrders + clientsWithoutOrders;
    if (totalClients == 0) {
        qDebug() << "No clients found.";
        return series;
    }

    // Add data to the pie chart
    series->append("With Orders", clientsWithOrders);
    series->append("Without Orders", clientsWithoutOrders);

    // Style the slices with distinct colors
    QPieSlice *sliceWithOrders = series->slices().at(0);
    sliceWithOrders->setBrush(QColor("#4CAF50")); // Green
    sliceWithOrders->setLabel(QString("With Orders (%1%)")
                                  .arg((clientsWithOrders * 100.0) / totalClients, 0, 'f', 1));

    QPieSlice *sliceWithoutOrders = series->slices().at(1);
    sliceWithoutOrders->setBrush(QColor("#FF5722")); // Orange-Red
    sliceWithoutOrders->setLabel(QString("Without Orders (%1%)")
                                     .arg((clientsWithoutOrders * 100.0) / totalClients, 0, 'f', 1));

    // Enable labels
    series->setLabelsVisible(true);

    return series;
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

bool SmtpClient::sendEmail(QString &from, QString &to, QString &subject, QString &message)
{
    QString smtpHost = "smtp.gmail.com";
    int smtpPort = 465;

    QSslSocket socket;
    socket.connectToHostEncrypted(smtpHost, smtpPort);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Failed to connect to the SMTP server.";
        return false;
    }

    // Read the initial server greeting (220)
    if (!socket.waitForReadyRead(5000)) {
        qDebug() << "No server greeting.";
        return false;
    }
    QString serverGreeting = socket.readAll();
    qDebug() << "Server greeting:" << serverGreeting;
    if (!serverGreeting.startsWith("220")) {
        qDebug() << "Unexpected greeting response:" << serverGreeting;
        return false;
    }

    // Send EHLO command
    if (!sendCommand(socket, "EHLO localhost\r\n", "250")) {
        return false;
    }

    // Start AUTH LOGIN
    if (!sendCommand(socket, "AUTH LOGIN\r\n", "334")) {
        return false;
    }

    // Send Base64-encoded username (email address)
    QString base64Username = QString(from).toUtf8().toBase64();
    if (!sendCommand(socket, base64Username + "\r\n", "334")) {
        return false;
    }

    // Send Base64-encoded app password
    QString base64Password = QString("muvp pbqs bwmr jbzw").toUtf8().toBase64();
    if (!sendCommand(socket, base64Password + "\r\n", "235")) {
        return false;
    }

    // Send MAIL FROM
    if (!sendCommand(socket, QString("MAIL FROM:<%1>\r\n").arg(from), "250")) {
        return false;
    }

    // Send RCPT TO to confirm the reception of message
    if (!sendCommand(socket, QString("RCPT TO:<%1>\r\n").arg(to), "250")) {
        return false;
    }

    // Send DATA command it s accepted to recive the date that u will send
    if (!sendCommand(socket, "DATA\r\n", "354")) {
        return false;
    }

    // Send email content
    QString emailContent = QString("From: %1\r\nTo: %2\r\nSubject: %3\r\n\r\n%4\r\n.\r\n")
        .arg(from, to, subject, message);
    if (!sendCommand(socket, emailContent, "250")) {
        return false;
    }

    // Send QUIT command
    if (!sendCommand(socket, "QUIT\r\n", "221")) {
        return false;
    }

    return true;
}

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
    qDebug() << "Server response:" << response;

    if (!response.startsWith(expectedResponse)) {
        qDebug() << "Unexpected response:" << response;
        return false;
    }

    return true;
}


