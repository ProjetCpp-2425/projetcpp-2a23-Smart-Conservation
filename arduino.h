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

private:
    QString arduinoPortName;  // Holds the port name of the connected Arduino
    QSerialPort serialPort;  // QSerialPort object for interacting with the Arduino
    int port;  // Not used, consider removing or keeping if needed for future use
};

#endif // ARDUINO_H
