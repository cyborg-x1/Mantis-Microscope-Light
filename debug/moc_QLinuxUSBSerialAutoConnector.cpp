/****************************************************************************
** Meta object code from reading C++ file 'QLinuxUSBSerialAutoConnector.h'
**
** Created: Tue Dec 6 23:21:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qLinuxUSBSerialAutoConnector/QLinuxUSBSerialAutoConnector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QLinuxUSBSerialAutoConnector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qUSBSerial__QLinuxUSBSerialAutoConnector[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   41,   41,   41, 0x05,
      63,   41,   41,   41, 0x05,
      81,   41,   41,   41, 0x05,
     107,   41,   41,   41, 0x05,
     125,   41,   41,   41, 0x05,

 // slots: signature, parameters, type, tag, flags
     148,   41,   41,   41, 0x08,
     171,   41,  166,   41, 0x08,
     186,   41,  166,   41, 0x08,
     209,   41,  166,   41, 0x08,
     225,   41,   41,   41, 0x08,
     242,   41,   41,   41, 0x0a,
     258,   41,   41,   41, 0x0a,
     277,   41,   41,   41, 0x0a,
     292,   41,   41,   41, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qUSBSerial__QLinuxUSBSerialAutoConnector[] = {
    "qUSBSerial::QLinuxUSBSerialAutoConnector\0"
    "\0serialDisconnected()\0serialConnected()\0"
    "serialAbortedConnect(int)\0waitingForRetry()\0"
    "serialConnectionLost()\0ifaceManagement()\0"
    "bool\0searchSerial()\0updateSerialSettings()\0"
    "openInterface()\0closeInterface()\0"
    "serialConnect()\0serialDisconnect()\0"
    "retryConnect()\0abortConnect()\0"
};

const QMetaObject qUSBSerial::QLinuxUSBSerialAutoConnector::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_qUSBSerial__QLinuxUSBSerialAutoConnector,
      qt_meta_data_qUSBSerial__QLinuxUSBSerialAutoConnector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qUSBSerial::QLinuxUSBSerialAutoConnector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qUSBSerial::QLinuxUSBSerialAutoConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qUSBSerial::QLinuxUSBSerialAutoConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qUSBSerial__QLinuxUSBSerialAutoConnector))
        return static_cast<void*>(const_cast< QLinuxUSBSerialAutoConnector*>(this));
    return QThread::qt_metacast(_clname);
}

int qUSBSerial::QLinuxUSBSerialAutoConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: serialDisconnected(); break;
        case 1: serialConnected(); break;
        case 2: serialAbortedConnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: waitingForRetry(); break;
        case 4: serialConnectionLost(); break;
        case 5: ifaceManagement(); break;
        case 6: { bool _r = searchSerial();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = updateSerialSettings();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = openInterface();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: closeInterface(); break;
        case 10: serialConnect(); break;
        case 11: serialDisconnect(); break;
        case 12: retryConnect(); break;
        case 13: abortConnect(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void qUSBSerial::QLinuxUSBSerialAutoConnector::serialDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qUSBSerial::QLinuxUSBSerialAutoConnector::serialConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void qUSBSerial::QLinuxUSBSerialAutoConnector::serialAbortedConnect(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void qUSBSerial::QLinuxUSBSerialAutoConnector::waitingForRetry()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void qUSBSerial::QLinuxUSBSerialAutoConnector::serialConnectionLost()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
