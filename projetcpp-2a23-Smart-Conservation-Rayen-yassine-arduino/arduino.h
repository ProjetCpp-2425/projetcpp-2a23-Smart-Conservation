#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QByteArray>

class arduino {
public:
    arduino();
    int connect_arduino();
    QSerialPort* getserial();  // Return pointer to QSerialPort for further interaction
    QByteArray read_from_arduino();  // Return data from Arduino as QByteArray

    QString getArduinoPortName() const;  // Getter for arduinoPortName

    int close_arduino();
    void write_to_arduino2( const QString &d  );
    QByteArray read_from_arduino2();
    QString getarduino_port_name();

private:
    QString arduinoPortName;  // Holds the port name of the connected Arduino
    QSerialPort serialPort;  // QSerialPort object for interacting with the Arduino
    int port;  // Not used, consider removing or keeping if needed for future use

    QSerialPort * serial;

    static const quint16 arduino_uno_vendor_id=0x2341;
    static const quint16 arduino_uno_producy_id=0x0043;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // ARDUINO_H
