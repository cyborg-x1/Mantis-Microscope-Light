/****************************************************************************
** Meta object code from reading C++ file 'msl.h'
**
** Created: Thu Dec 8 05:38:48 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../msl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'msl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_msl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,
      19,   13,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   41,    4,    4, 0x08,
      68,    4,    4,    4, 0x08,
      97,    4,    4,    4, 0x08,
     127,    4,    4,    4, 0x08,
     161,  155,    4,    4, 0x08,
     200,  155,    4,    4, 0x08,
     242,    4,    4,    4, 0x08,
     273,    4,    4,    4, 0x08,
     305,    4,    4,    4, 0x08,
     343,    4,    4,    4, 0x08,
     378,    4,    4,    4, 0x08,
     410,    4,    4,    4, 0x08,
     442,    4,    4,    4, 0x08,
     484,    4,    4,    4, 0x08,
     502,    4,    4,    4, 0x08,
     533,  526,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_msl[] = {
    "msl\0\0retry()\0array\0sendArray(QByteArray)\0"
    "color\0colorChanged(QColor)\0"
    "on_pushButton_Wmax_clicked()\0"
    "on_pushButton_UVmax_clicked()\0"
    "on_pushButton_off_clicked()\0value\0"
    "on_verticalSlider_uv_valueChanged(int)\0"
    "on_verticalSlider_white_valueChanged(int)\0"
    "on_pushButton_EEPROM_clicked()\0"
    "on_pushButton_RGB_off_clicked()\0"
    "on_pushButton_UV_White_Tggl_clicked()\0"
    "on_pushButton_UvWhiteOff_clicked()\0"
    "on_pushButton_EE_Save_clicked()\0"
    "on_pushButton_EE_Read_clicked()\0"
    "on_pushButton_EE_currentSetting_clicked()\0"
    "serialConnected()\0serialWaitingForRetry()\0"
    "reason\0serialConnectionAbort(int)\0"
};

const QMetaObject msl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_msl,
      qt_meta_data_msl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &msl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *msl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *msl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_msl))
        return static_cast<void*>(const_cast< msl*>(this));
    return QWidget::qt_metacast(_clname);
}

int msl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: retry(); break;
        case 1: sendArray((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: colorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: on_pushButton_Wmax_clicked(); break;
        case 4: on_pushButton_UVmax_clicked(); break;
        case 5: on_pushButton_off_clicked(); break;
        case 6: on_verticalSlider_uv_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_verticalSlider_white_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_pushButton_EEPROM_clicked(); break;
        case 9: on_pushButton_RGB_off_clicked(); break;
        case 10: on_pushButton_UV_White_Tggl_clicked(); break;
        case 11: on_pushButton_UvWhiteOff_clicked(); break;
        case 12: on_pushButton_EE_Save_clicked(); break;
        case 13: on_pushButton_EE_Read_clicked(); break;
        case 14: on_pushButton_EE_currentSetting_clicked(); break;
        case 15: serialConnected(); break;
        case 16: serialWaitingForRetry(); break;
        case 17: serialConnectionAbort((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void msl::retry()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void msl::sendArray(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
