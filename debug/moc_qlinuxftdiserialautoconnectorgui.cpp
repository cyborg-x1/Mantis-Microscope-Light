/****************************************************************************
** Meta object code from reading C++ file 'qlinuxftdiserialautoconnectorgui.h'
**
** Created: Sat Dec 3 21:35:49 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qLinuxFtdiSerialAutoConnector/qlinuxftdiserialautoconnectorgui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlinuxftdiserialautoconnectorgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QLinuxFtdiSerialAutoConnectorGUI[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   33,   33,   33, 0x05,
      48,   33,   33,   33, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   33,   33,   33, 0x0a,
      92,   33,   33,   33, 0x0a,
     139,  122,   33,   33, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QLinuxFtdiSerialAutoConnectorGUI[] = {
    "QLinuxFtdiSerialAutoConnectorGUI\0\0"
    "retry_click()\0abort_click()\0"
    "on_pushbutton_retry_clicked()\0"
    "on_pushbutton_abort_clicked()\0"
    "secondsTillRetry\0secondsvalue(int)\0"
};

const QMetaObject QLinuxFtdiSerialAutoConnectorGUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QLinuxFtdiSerialAutoConnectorGUI,
      qt_meta_data_QLinuxFtdiSerialAutoConnectorGUI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QLinuxFtdiSerialAutoConnectorGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QLinuxFtdiSerialAutoConnectorGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QLinuxFtdiSerialAutoConnectorGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QLinuxFtdiSerialAutoConnectorGUI))
        return static_cast<void*>(const_cast< QLinuxFtdiSerialAutoConnectorGUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int QLinuxFtdiSerialAutoConnectorGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: retry_click(); break;
        case 1: abort_click(); break;
        case 2: on_pushbutton_retry_clicked(); break;
        case 3: on_pushbutton_abort_clicked(); break;
        case 4: secondsvalue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QLinuxFtdiSerialAutoConnectorGUI::retry_click()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QLinuxFtdiSerialAutoConnectorGUI::abort_click()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
