/****************************************************************************
** Meta object code from reading C++ file 'FormViewer.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/form/FormViewer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FormViewer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FormViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       4,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      27,   11,   11,   11, 0x05,
      48,   11,   11,   11, 0x05,
      69,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      90,   85,   11,   11, 0x08,

 // properties: name, type, flags
     153,  145, 0x0a495001,
     159,  145, 0x0a495001,
     171,  145, 0x0a495001,
     183,  145, 0x0a495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

static const char qt_meta_stringdata_FormViewer[] = {
    "FormViewer\0\0titleChanged()\0"
    "descriptionChanged()\0dueDateTimeChanged()\0"
    "statusChanged()\0note\0"
    "noteChanged(QList<bb::pim::notebook::NotebookEntryId>)\0"
    "QString\0title\0description\0dueDateTime\0"
    "status\0"
};

void FormViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FormViewer *_t = static_cast<FormViewer *>(_o);
        switch (_id) {
        case 0: _t->titleChanged(); break;
        case 1: _t->descriptionChanged(); break;
        case 2: _t->dueDateTimeChanged(); break;
        case 3: _t->statusChanged(); break;
        case 4: _t->noteChanged((*reinterpret_cast< const QList<bb::pim::notebook::NotebookEntryId>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FormViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FormViewer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FormViewer,
      qt_meta_data_FormViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FormViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FormViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FormViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormViewer))
        return static_cast<void*>(const_cast< FormViewer*>(this));
    return QObject::qt_metacast(_clname);
}

int FormViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< QString*>(_v) = title(); break;
        case 1: *reinterpret_cast< QString*>(_v) = description(); break;
        case 2: *reinterpret_cast< QString*>(_v) = dueDateTime(); break;
        case 3: *reinterpret_cast< QString*>(_v) = status(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
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

// SIGNAL 0
void FormViewer::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FormViewer::descriptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FormViewer::dueDateTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void FormViewer::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
