/****************************************************************************
** Meta object code from reading C++ file 'msl.h'
**
** Created: Tue Dec 6 21:32:59 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../msl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'msl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_msl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      19,   13,    4,    4, 0x08,
      40,    4,    4,    4, 0x08,
      69,    4,    4,    4, 0x08,
      99,    4,    4,    4, 0x08,
     133,  127,    4,    4, 0x08,
     172,  127,    4,    4, 0x08,
     214,    4,    4,    4, 0x08,
     245,    4,    4,    4, 0x08,
     277,    4,    4,    4, 0x08,
     315,    4,    4,    4, 0x08,
     350,    4,    4,    4, 0x08,
     382,    4,    4,    4, 0x08,
     414,    4,    4,    4, 0x08,
     456,    4,    4,    4, 0x08,
     474,    4,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_msl[] = {
    "msl\0\0retry()\0color\0colorChanged(QColor)\0"
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
        case 1: colorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: on_pushButton_Wmax_clicked(); break;
        case 3: on_pushButton_UVmax_clicked(); break;
        case 4: on_pushButton_off_clicked(); break;
        case 5: on_verticalSlider_uv_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_verticalSlider_white_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_pushButton_EEPROM_clicked(); break;
        case 8: on_pushButton_RGB_off_clicked(); break;
        case 9: on_pushButton_UV_White_Tggl_clicked(); break;
        case 10: on_pushButton_UvWhiteOff_clicked(); break;
        case 11: on_pushButton_EE_Save_clicked(); break;
        case 12: on_pushButton_EE_Read_clicked(); break;
        case 13: on_pushButton_EE_currentSetting_clicked(); break;
        case 14: serialConnected(); break;
        case 15: serialWaitingForRetry(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void msl::retry()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
