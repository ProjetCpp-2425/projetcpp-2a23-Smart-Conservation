#include "arduino.h"
#include <QSerialPortInfo>
#include <QDebug>

arduino::arduino() {
    // Constructor to initialize the serial port or other variables if needed
}

int arduino::connect_arduino() {
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    if (serialPorts.isEmpty()) {
        return -1;  // No serial ports found
    }

    foreach (const QSerialPortInfo &portInfo, serialPorts) {
        arduinoPortName = portInfo.portName();
        serialPort.setPort(portInfo);
        serialPort.setBaudRate(QSerialPort::Baud9600);
        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setParity(QSerialPort::NoParity);
        serialPort.setStopBits(QSerialPort::OneStop);
        serialPort.setFlowControl(QSerialPort::NoFlowControl);

        if (serialPort.open(QIODevice::ReadWrite)) {
            return 0;  // Successfully connected to the Arduino
        }
    }
    return 1;  // Arduino not connected
}

QSerialPort* arduino::getserial() {
    return &serialPort;  // Return the serial port object for further interaction
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
