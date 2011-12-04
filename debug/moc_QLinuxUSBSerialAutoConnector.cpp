/****************************************************************************
** Meta object code from reading C++ file 'QLinuxUSBSerialAutoConnector.h'
**
** Created: Sun Dec 4 15:02:57 2011
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
static const uint qt_meta_data_qUSB__QLinuxUSBSerialAutoConnector[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   35,   35,   35, 0x05,
      59,   35,   35,   35, 0x05,
      80,   35,   35,   35, 0x05,
      98,   35,   35,   35, 0x05,
     125,  118,   35,   35, 0x05,

 // slots: signature, parameters, type, tag, flags
     146,   35,   35,   35, 0x08,
     169,   35,  164,   35, 0x08,
     184,   35,   35,   35, 0x0a,
     200,   35,   35,   35, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qUSB__QLinuxUSBSerialAutoConnector[] = {
    "qUSB::QLinuxUSBSerialAutoConnector\0\0"
    "serialConnectionLost()\0serialDisconnected()\0"
    "serialConnected()\0serialReconnected()\0"
    "reason\0abort(AbortReason_t)\0"
    "ifaceManagement()\0bool\0searchSerial()\0"
    "serialConnect()\0serialDisconnect()\0"
};

const QMetaObject qUSB::QLinuxUSBSerialAutoConnector::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_qUSB__QLinuxUSBSerialAutoConnector,
      qt_meta_data_qUSB__QLinuxUSBSerialAutoConnector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qUSB::QLinuxUSBSerialAutoConnector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qUSB::QLinuxUSBSerialAutoConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qUSB::QLinuxUSBSerialAutoConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qUSB__QLinuxUSBSerialAutoConnector))
        return static_cast<void*>(const_cast< QLinuxUSBSerialAutoConnector*>(this));
    return QThread::qt_metacast(_clname);
}

int qUSB::QLinuxUSBSerialAutoConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: abort((*reinterpret_cast< AbortReason_t(*)>(_a[1]))); break;
        case 5: ifaceManagement(); break;
        case 6: { bool _r = searchSerial();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: serialConnect(); break;
        case 8: serialDisconnect(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void qUSB::QLinuxUSBSerialAutoConnector::serialConnectionLost()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qUSB::QLinuxUSBSerialAutoConnector::serialDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void qUSB::QLinuxUSBSerialAutoConnector::serialConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void qUSB::QLinuxUSBSerialAutoConnector::serialReconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void qUSB::QLinuxUSBSerialAutoConnector::abort(AbortReason_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
