/****************************************************************************
** Meta object code from reading C++ file 'pgcmessages.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/pgc/pgcmessages.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pgcmessages.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PgcMessages[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   29,   12,   12, 0x0a,
      86,   71,   12,   12, 0x0a,
     128,   12,   12,   12, 0x0a,
     144,   12,   12,   12, 0x08,

 // methods: signature, parameters, type, tag, flags
     176,  161,   12,   12, 0x02,

 // properties: name, type, flags
     228,  198, 0x00095409,
     242,  234, 0x0a495103,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_PgcMessages[] = {
    "PgcMessages\0\0filterChanged()\0indexPath\0"
    "setCurrentMessage(QVariantList)\0"
    "selectedOption\0setSelectedAccount(bb::cascades::Option*)\0"
    "deleteMessage()\0filterMessages()\0"
    "dropDownObject\0addAccounts(QObject*)\0"
    "bb::cascades::GroupDataModel*\0model\0"
    "QString\0filter\0"
};

void PgcMessages::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PgcMessages *_t = static_cast<PgcMessages *>(_o);
        switch (_id) {
        case 0: _t->filterChanged(); break;
        case 1: _t->setCurrentMessage((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 2: _t->setSelectedAccount((*reinterpret_cast< bb::cascades::Option*(*)>(_a[1]))); break;
        case 3: _t->deleteMessage(); break;
        case 4: _t->filterMessages(); break;
        case 5: _t->addAccounts((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PgcMessages::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PgcMessages::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PgcMessages,
      qt_meta_data_PgcMessages, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PgcMessages::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PgcMessages::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PgcMessages::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PgcMessages))
        return static_cast<void*>(const_cast< PgcMessages*>(this));
    return QObject::qt_metacast(_clname);
}

int PgcMessages::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bb::cascades::GroupDataModel**>(_v) = model(); break;
        case 1: *reinterpret_cast< QString*>(_v) = filter(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setFilter(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PgcMessages::filterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
