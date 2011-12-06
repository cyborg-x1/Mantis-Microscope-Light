/****************************************************************************
** Meta object code from reading C++ file 'QLinuxUSBSerialAutoConnector.h'
**
** Created: Tue Dec 6 14:11:02 2011
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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   41,   41,   41, 0x05,
      65,   41,   41,   41, 0x05,
      86,   41,   41,   41, 0x05,
     104,   41,   41,   41, 0x05,
     131,  124,   41,   41, 0x05,
     159,   41,   41,   41, 0x05,

 // slots: signature, parameters, type, tag, flags
     177,   41,   41,   41, 0x08,
     200,   41,  195,   41, 0x08,
     215,   41,   41,   41, 0x0a,
     231,   41,   41,   41, 0x0a,
     250,   41,   41,   41, 0x0a,
     265,   41,   41,   41, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qUSBSerial__QLinuxUSBSerialAutoConnector[] = {
    "qUSBSerial::QLinuxUSBSerialAutoConnector\0"
    "\0serialConnectionLost()\0serialDisconnected()\0"
    "serialConnected()\0serialReconnected()\0"
    "reason\0abortConnect(AbortReason_t)\0"
    "waitingForRetry()\0ifaceManagement()\0"
    "bool\0searchSerial()\0serialConnect()\0"
    "serialDisconnect()\0retryConnect()\0"
    "abortConnect()\0"
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
        case 0: serialConnectionLost(); break;
        case 1: serialDisconnected(); break;
        case 2: serialConnected(); break;
        case 3: serialReconnected(); break;
        case 4: abortConnect((*reinterpret_cast< AbortReason_t(*)>(_a[1]))); break;
        case 5: waitingForRetry(); break;
        case 6: ifaceManagement(); break;
        case 7: { bool _r = searchSerial();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: serialConnect(); break;
        case 9: serialDisconnect(); break;
        case 10: retryConnect(); break;
        case 11: abortConnect(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void qUSBSerial::QLinuxUSBSerialAutoConnector::serialConnectionLost()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qUSBSerial::QLinuxUSBSerialAutoConnector::serialDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void qUSBSerial::QLinuxUSBSerialAutoConnector::serialConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void qUSBSerial::QLinuxUSBSerialAutoConnector::serialReconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void qUSBSerial::QLinuxUSBSerialAutoConnector::abortConnect(AbortReason_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void qUSBSerial::QLinuxUSBSerialAutoConnector::waitingForRetry()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
