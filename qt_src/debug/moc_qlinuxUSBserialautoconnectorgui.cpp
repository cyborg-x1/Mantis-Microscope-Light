/****************************************************************************
** Meta object code from reading C++ file 'qlinuxUSBserialautoconnectorgui.h'
**
** Created: Thu Dec 8 05:38:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qLinuxUSBSerialAutoConnector/qlinuxUSBserialautoconnectorgui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlinuxUSBserialautoconnectorgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QLinuxUSBSerialAutoConnectorGUI[] = {

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
      33,   32,   32,   32, 0x05,
      41,   32,   32,   32, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   32,   32,   32, 0x08,
      61,   32,   32,   32, 0x08,
      91,   32,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QLinuxUSBSerialAutoConnectorGUI[] = {
    "QLinuxUSBSerialAutoConnectorGUI\0\0"
    "retry()\0abort()\0countdown()\0"
    "on_pushButton_retry_clicked()\0"
    "on_pushButton_abort_clicked()\0"
};

const QMetaObject QLinuxUSBSerialAutoConnectorGUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QLinuxUSBSerialAutoConnectorGUI,
      qt_meta_data_QLinuxUSBSerialAutoConnectorGUI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QLinuxUSBSerialAutoConnectorGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QLinuxUSBSerialAutoConnectorGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QLinuxUSBSerialAutoConnectorGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QLinuxUSBSerialAutoConnectorGUI))
        return static_cast<void*>(const_cast< QLinuxUSBSerialAutoConnectorGUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int QLinuxUSBSerialAutoConnectorGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: retry(); break;
        case 1: abort(); break;
        case 2: countdown(); break;
        case 3: on_pushButton_retry_clicked(); break;
        case 4: on_pushButton_abort_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QLinuxUSBSerialAutoConnectorGUI::retry()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QLinuxUSBSerialAutoConnectorGUI::abort()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
