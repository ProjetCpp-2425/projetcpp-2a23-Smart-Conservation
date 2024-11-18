#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include<QStandardItemModel>
#include <QNetworkAccessManager>
#include <QSqlQueryModel>
#include <QTcpSocket>
#include <QObject>
#include <QString>
class client
{
    QString name,email,adresse;
    int phone,tot_ord,id;

public:
    client(){};
    client(int, QString , int , QString , QString , int);
    //geters
    QString getName()  { return name; }
    QString getAdresse()  { return adresse; }
    int getId()  { return id; }
    int gettot_ord()  { return tot_ord; }
    QString getEmail()  { return email; }
    int getPhone()  { return phone; }
    //setters
    void setNom( QString n) { name = n; }
    void setPrenom( QString &e) { email = e; }
    void setId(int i) { this->id = i; }
    void setAdresse( QString a) { adresse = a; }
    void setPhone(int p) { this-> phone = p; }
    void settot_ord(int&t) { this-> tot_ord = t; }

    bool ajouter();
    //QSqlQueryModel * afficher();
    QStandardItemModel * afficher();
    bool supprimer(int );
    bool search(int);

    bool update(int,QString , int , QString , QString , int);

    void pdf_downloader();

    QString count();
    /*
    QSqlQueryModel * trier_tab_desc();
    QSqlQueryModel * trier_id_desc();
    QSqlQueryModel * trier_name_desc();
    QSqlQueryModel * trier_phone_desc();
    QSqlQueryModel * trier_adresse_desc();
    QSqlQueryModel * trier_mail_desc();

    QSqlQueryModel * trier_tab_ASC();
    QSqlQueryModel * trier_id_ASC();
    QSqlQueryModel * trier_name_ASC();
    QSqlQueryModel * trier_phone_ASC();
    QSqlQueryModel * trier_adresse_ASC();
    QSqlQueryModel * trier_mail_ASC();
    */
    QStandardItemModel * trier_tab_desc();
    QStandardItemModel * trier_id_desc();
    QStandardItemModel * trier_name_desc();
    QStandardItemModel * trier_phone_desc();
    QStandardItemModel * trier_adresse_desc();
    QStandardItemModel * trier_mail_desc();

    QStandardItemModel * trier_tab_ASC();
    QStandardItemModel * trier_id_ASC();
    QStandardItemModel * trier_name_ASC();
    QStandardItemModel * trier_phone_ASC();
    QStandardItemModel * trier_adresse_ASC();
    QStandardItemModel * trier_mail_ASC();

    QString generateVerificationCode();
    void sendSms(QString ,QString);

    bool isPhoneInDatabase(int);
    bool emailExists(QString);
    void sendEmail( QString ,  QString ,  QString );


private:
    QNetworkAccessManager *manager;

};

class SmtpClient : public QObject
{
    Q_OBJECT

public:
    explicit SmtpClient(QObject *parent = nullptr);
    ~SmtpClient();

    //void sendEmail( QString from,  QString to, const QString subject,  QString message);
    bool sendEmail( QString &from,  QString &to,  QString &subject,  QString &message);
private:
    bool sendCommand(QSslSocket &socket, const QString &command, const QString &expectedResponse);
};

#endif // CLIENT_H
