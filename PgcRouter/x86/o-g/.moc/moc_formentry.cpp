/****************************************************************************
** Meta object code from reading C++ file 'formentry.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/form/formentry.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formentry.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dw__form__FormEntry[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      28,   20, 0x0a095103,
      34,   20, 0x0a095103,
      39,   20, 0x0a095103,
      46,   20, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_dw__form__FormEntry[] = {
    "dw::form::FormEntry\0QString\0title\0"
    "desc\0status\0time\0"
};

void dw::form::FormEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dw::form::FormEntry::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dw::form::FormEntry::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_dw__form__FormEntry,
      qt_meta_data_dw__form__FormEntry, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dw::form::FormEntry::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dw::form::FormEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dw::form::FormEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dw__form__FormEntry))
        return static_cast<void*>(const_cast< FormEntry*>(this));
    return QObject::qt_metacast(_clname);
}

int dw::form::FormEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = title(); break;
        case 1: *reinterpret_cast< QString*>(_v) = desc(); break;
        case 2: *reinterpret_cast< QString*>(_v) = status(); break;
        case 3: *reinterpret_cast< QString*>(_v) = time(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: setDesc(*reinterpret_cast< QString*>(_v)); break;
        case 2: setStatus(*reinterpret_cast< QString*>(_v)); break;
        case 3: setTime(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
