QT       += core gui sql network multimedia multimediawidgets printsupport charts axcontainer serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += core gui charts
TARGET = Cannitech
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++17

# Source and Header Files
SOURCES += \
        arduino.cpp \
        arduino_fm.cpp \
        client.cpp \
        commande.cpp \
        connection.cpp \
        employee.cpp \
        factory.cpp \
        machine.cpp \
        main.cpp \
        mainwindow.cpp \
        management.cpp \
        email.cpp

HEADERS += \
        arduino.h \
        arduino_fm.h \
        client.h \
        commande.h \
        connection.h \
        employee.h \
        factory.h \
        machine.h \
        mainwindow.h \
        management.h \
        email.h

FORMS += \
        mainwindow.ui \
        management.ui \
        email.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Resources
RESOURCES += resources.qrc

