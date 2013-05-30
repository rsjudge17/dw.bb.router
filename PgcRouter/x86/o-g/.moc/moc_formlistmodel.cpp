/****************************************************************************
** Meta object code from reading C++ file 'formlistmodel.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/form/formlistmodel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formlistmodel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dw__form__FormListModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,

 // methods: signature, parameters, type, tag, flags
      51,   41,   24,   24, 0x02,
      86,   74,   65,   24, 0x02,
     121,  105,   24,   24, 0x02,
     159,  152,   24,   24, 0x02,

 // properties: name, type, flags
     152,  178, 0x0a495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_dw__form__FormListModel[] = {
    "dw::form::FormListModel\0\0filterChanged()\0"
    "file_name\0load(QString)\0QVariant\0"
    "ix,fld_name\0value(int,QString)\0"
    "ix,fld_name,val\0setValue(int,QString,QVariant)\0"
    "filter\0setFilter(QString)\0QString\0"
};

void dw::form::FormListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FormListModel *_t = static_cast<FormListModel *>(_o);
        switch (_id) {
        case 0: _t->filterChanged(); break;
        case 1: _t->load((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { QVariant _r = _t->value((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: _t->setValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 4: _t->setFilter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dw::form::FormListModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dw::form::FormListModel::staticMetaObject = {
    { &bb::cascades::QVariantListDataModel::staticMetaObject, qt_meta_stringdata_dw__form__FormListModel,
      qt_meta_data_dw__form__FormListModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dw::form::FormListModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dw::form::FormListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dw::form::FormListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dw__form__FormListModel))
        return static_cast<void*>(const_cast< FormListModel*>(this));
    typedef bb::cascades::QVariantListDataModel QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int dw::form::FormListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef bb::cascades::QVariantListDataModel QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = filter(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFilter(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void dw::form::FormListModel::filterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
