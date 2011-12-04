TEMPLATE = app
TARGET = RL_Microscope_Light_Control
QT += core \
    gui \
    xml
HEADERS += qLinuxUSBSerialAutoConnector/qlinuxUSBserialautoconnectorgui.h \
    qLinuxUSBSerialAutoConnector/QLinuxUSBSerialAutoConnector.h \
    MicroScopeConnector.h \
    qext/qextserialenumerator.h \
    qext/qextserialport.h \
    qext/qextserialport_global.h \
    msl.h
SOURCES += qLinuxUSBSerialAutoConnector/QLinuxUSBSerialAutoConnector.cpp \
    qLinuxUSBSerialAutoConnector/qlinuxUSBserialautoconnectorgui.cpp \
    MicroScopeConnector.cpp \
    qext/posix_qextserialport.cpp \
    qext/qextserialenumerator_unix.cpp \
    qext/qextserialport.cpp \
    main.cpp \
    msl.cpp
FORMS += qLinuxUSBSerialAutoConnector/qlinuxUSBserialautoconnectorgui.ui \
    msl.ui
RESOURCES += 
LIBS += /usr/lib/x86_64-linux-gnu/libudev.so
