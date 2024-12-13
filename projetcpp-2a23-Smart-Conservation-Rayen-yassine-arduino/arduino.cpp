#include "arduino.h"
#include <QSerialPortInfo>
#include <QDebug>
arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *arduino::getserial()
{
   return serial;
}
int arduino::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray arduino::read_from_arduino2()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
}


 void arduino::write_to_arduino2(const QString &d)
 {
     if (serial->isWritable()) {

         QByteArray data = d.toUtf8();


         serial->write(data);
     } else {
         qDebug() << "Couldn't write to serial!";
     }
 }



QByteArray arduino::read_from_arduino() {
    QByteArray data = serialPort.readAll();  // Read the available data
    static QByteArray buffer;  // Static buffer to store accumulated data

    // Accumulate data until we have a complete tag (or use a delimiter)
    if (!data.isEmpty()) {
        buffer.append(data);
        // Check for a possible end of tag (e.g., newline, specific character, etc.)
        if (buffer.contains("\n")) {
            // We have a complete tag, return it and reset the buffer
            QByteArray completeTag = buffer;
            buffer.clear();  // Clear buffer for next reading
            return completeTag;
        }
    }

    // Return empty if no complete tag is received yet
    return QByteArray();
}


QString arduino::getArduinoPortName() const {
    return arduinoPortName;  // Return the port name
}
