QT       += core gui sql network multimedia multimediawidgets printsupport charts axcontainer serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cannitech
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++17

# Source and Header Files
SOURCES += \
        arduino.cpp \
        commande.cpp \
        connection.cpp \
        employee.cpp \
        main.cpp \
        mainwindow.cpp \
        management.cpp

HEADERS += \
        arduino.h \
        commande.h \
        connection.h \
        employee.h \
        mainwindow.h \
        management.h

FORMS += \
        mainwindow.ui \
        management.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Resources
RESOURCES += resources.qrc

