/****************************************************************************
** Meta object code from reading C++ file 'QLinuxFtdiSerialAutoConnector.h'
**
** Created: Sun Dec 4 03:22:28 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qLinuxFtdiSerialAutoConnector/QLinuxFtdiSerialAutoConnector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QLinuxFtdiSerialAutoConnector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qFtdi__QLinuxFtdiSerialAutoConnector[] = {

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
      38,   37,   37,   37, 0x05,
      61,   37,   37,   37, 0x05,
      82,   37,   37,   37, 0x05,
     100,   37,   37,   37, 0x05,
     127,  120,   37,   37, 0x05,

 // slots: signature, parameters, type, tag, flags
     148,   37,   37,   37, 0x08,
     171,   37,  166,   37, 0x08,
     186,   37,   37,   37, 0x0a,
     202,   37,   37,   37, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qFtdi__QLinuxFtdiSerialAutoConnector[] = {
    "qFtdi::QLinuxFtdiSerialAutoConnector\0"
    "\0serialConnectionLost()\0serialDisconnected()\0"
    "serialConnected()\0serialReconnected()\0"
    "reason\0abort(AbortReason_t)\0"
    "ifaceManagement()\0bool\0searchSerial()\0"
    "serialConnect()\0serialDisconnect()\0"
};

const QMetaObject qFtdi::QLinuxFtdiSerialAutoConnector::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_qFtdi__QLinuxFtdiSerialAutoConnector,
      qt_meta_data_qFtdi__QLinuxFtdiSerialAutoConnector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qFtdi::QLinuxFtdiSerialAutoConnector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qFtdi::QLinuxFtdiSerialAutoConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qFtdi::QLinuxFtdiSerialAutoConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qFtdi__QLinuxFtdiSerialAutoConnector))
        return static_cast<void*>(const_cast< QLinuxFtdiSerialAutoConnector*>(this));
    return QThread::qt_metacast(_clname);
}

int qFtdi::QLinuxFtdiSerialAutoConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void qFtdi::QLinuxFtdiSerialAutoConnector::serialConnectionLost()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qFtdi::QLinuxFtdiSerialAutoConnector::serialDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void qFtdi::QLinuxFtdiSerialAutoConnector::serialConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void qFtdi::QLinuxFtdiSerialAutoConnector::serialReconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void qFtdi::QLinuxFtdiSerialAutoConnector::abort(AbortReason_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
