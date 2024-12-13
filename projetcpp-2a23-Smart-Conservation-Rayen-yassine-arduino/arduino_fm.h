#ifndef ARDUINO_FM_H
#define ARDUINO_FM_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class ArduinoFM
{
public:     //méthodes de la classe Arduino
    ArduinoFM();
    int connect_arduinoFM(); // permet de connecter le PC à Arduino
    int close_arduinoFM(); // permet de femer la connexion
    int read_number_from_arduinoFM();
    void write_to_arduinoFM(const QString &d); // envoyer des données vers arduino
    QByteArray read_from_arduinoFM();  //recevoir des données de la carte Arduino
    QSerialPort* getserialFM();   // accesseur
    QString getarduino_port_nameFM();
private:
    QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
    //et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
    static const quint16 arduino_uno_vendor_id=0X1A86;
    static const quint16 arduino_uno_producy_id=0X7523;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray dataFM;
    // contenant les données lues à partir d'Arduino
};



#endif // ARDUINO_FM_H

