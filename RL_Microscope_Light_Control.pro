TEMPLATE = app
TARGET = RL_Microscope_Light_Control
QT += core \
    gui \
    xml
HEADERS += qLinuxFtdiSerialAutoConnector/qlinuxftdiserialautoconnectorgui.h \
    qLinuxFtdiSerialAutoConnector/QLinuxFtdiSerialAutoConnector.h \
    MicroScopeConnector.h \
    qext/qextserialenumerator.h \
    qext/qextserialport.h \
    qext/qextserialport_global.h \
    msl.h
SOURCES += qLinuxFtdiSerialAutoConnector/qlinuxftdiserialautoconnectorgui.cpp \
    qLinuxFtdiSerialAutoConnector/QLinuxFtdiSerialAutoConnector.cpp \
    MicroScopeConnector.cpp \
    qext/posix_qextserialport.cpp \
    qext/qextserialenumerator_unix.cpp \
    qext/qextserialport.cpp \
    main.cpp \
    msl.cpp
FORMS += qLinuxFtdiSerialAutoConnector/qlinuxftdiserialautoconnectorgui.ui \
    msl.ui
RESOURCES += 
LIBS += /usr/lib/x86_64-linux-gnu/libudev.so
