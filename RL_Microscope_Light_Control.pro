TEMPLATE = app
TARGET = RL_Microscope_Light_Control
QT += core \
    gui \
    xml
HEADERS += MicroScopeConnector.h \
    qext/qextserialenumerator.h \
    qext/qextserialport.h \
    qext/qextserialport_global.h \
    msl.h
SOURCES += MicroScopeConnector.cpp \
    qext/posix_qextserialport.cpp \
    qext/qextserialenumerator_unix.cpp \
    qext/qextserialport.cpp \
    main.cpp \
    msl.cpp
FORMS += msl.ui
RESOURCES += 
