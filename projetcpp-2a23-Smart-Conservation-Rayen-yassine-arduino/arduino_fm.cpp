#include "arduino_fm.h"

ArduinoFM::ArduinoFM()
{
    dataFM = "";
    arduino_port_name = "";
    arduino_is_available = false;
    serial = new QSerialPort;
}

QString ArduinoFM::getarduino_port_nameFM()
{
    return arduino_port_name;
}

QSerialPort* ArduinoFM::getserialFM()
{
    return serial;
}

int ArduinoFM::connect_arduinoFM()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }
    qDebug() << "arduino_port_name is :" << arduino_port_name;
    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int ArduinoFM::close_arduinoFM()
{
    if (serial->isOpen()) {
        serial->close();
        return 0;
    }
    return 1;
}

int ArduinoFM::read_number_from_arduinoFM()
{
    if (serial->isReadable()) {
        QByteArray rawData = serial->readAll();
        QString dataString = QString::fromUtf8(rawData).trimmed();

        bool ok;
        int number = dataString.toInt(&ok);
        if (ok) {
            return number;
        } else {
            qDebug() << "Received data is not a valid number:" << dataString;
            return -1;
        }
    }
    qDebug() << "No data available to read.";
    return -1;
}

QByteArray ArduinoFM::read_from_arduinoFM()
{
    if (serial->isReadable()) {
        dataFM = serial->readAll();
        return dataFM;
    }
    return QByteArray();
}

void ArduinoFM::write_to_arduinoFM(const QString &d)
{
    if (serial->isWritable()) {
        QByteArray data = d.toUtf8();
        serial->write(data);
    } else {
        qDebug() << "Failed to write to Arduino.";
    }
}
