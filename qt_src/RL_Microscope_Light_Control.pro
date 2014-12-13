QT += core \
    gui \
    xml \
    widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RL_Microscope_Light_Control
TEMPLATE = app


SOURCES += qLinuxUSBSerialAutoConnector/QLinuxUSBSerialAutoConnector.cpp \
    qLinuxUSBSerialAutoConnector/qlinuxUSBserialautoconnectorgui.cpp \
    qext/posix_qextserialport.cpp \
    qext/qextserialenumerator_unix.cpp \
    qext/qextserialport.cpp \
    main.cpp \
    msl.cpp

HEADERS += qLinuxUSBSerialAutoConnector/qlinuxUSBserialautoconnectorgui.h \
    qLinuxUSBSerialAutoConnector/QLinuxUSBSerialAutoConnector.h \
    qext/qextserialenumerator.h \
    qext/qextserialport.h \
    qext/qextserialport_global.h \
    msl.h

FORMS += qLinuxUSBSerialAutoConnector/qlinuxUSBserialautoconnectorgui.ui \
    msl.ui

RESOURCES +=


LIBS += /usr/lib/x86_64-linux-gnu/libudev.so
