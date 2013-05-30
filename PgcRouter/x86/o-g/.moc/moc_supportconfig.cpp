/****************************************************************************
** Meta object code from reading C++ file 'supportconfig.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/config/supportconfig.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supportconfig.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dw__config__SupportConfig[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      34,   26, 0x0a095103,
      48,   26, 0x0a095103,
      61,   26, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_dw__config__SupportConfig[] = {
    "dw::config::SupportConfig\0QString\0"
    "supportNumber\0supportEmail\0webSite\0"
};

void dw::config::SupportConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dw::config::SupportConfig::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dw::config::SupportConfig::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_dw__config__SupportConfig,
      qt_meta_data_dw__config__SupportConfig, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dw::config::SupportConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dw::config::SupportConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dw::config::SupportConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dw__config__SupportConfig))
        return static_cast<void*>(const_cast< SupportConfig*>(this));
    return Config::qt_metacast(_clname);
}

int dw::config::SupportConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = supportNumber(); break;
        case 1: *reinterpret_cast< QString*>(_v) = supportEmail(); break;
        case 2: *reinterpret_cast< QString*>(_v) = webSite(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setSupportNumber(*reinterpret_cast< QString*>(_v)); break;
        case 1: setSupportEmail(*reinterpret_cast< QString*>(_v)); break;
        case 2: setWebSite(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
