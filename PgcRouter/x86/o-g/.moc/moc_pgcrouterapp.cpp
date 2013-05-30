/****************************************************************************
** Meta object code from reading C++ file 'pgcrouterapp.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/pgcrouterapp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pgcrouterapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PgcRouterApp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       8,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      31,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   47,   13,   13, 0x0a,
      69,   13,   13,   13, 0x08,
     109,   13,   13,   13, 0x08,
     148,   13,   13,   13, 0x08,
     184,   13,   13,   13, 0x0a,
     197,   13,   13,   13, 0x0a,
     209,   13,   13,   13, 0x0a,
     235,   13,   13,   13, 0x0a,
     270,  261,   13,   13, 0x0a,
     300,  261,   13,   13, 0x0a,

 // properties: name, type, flags
     338,  330, 0x0a495001,
     350,  330, 0x0a495001,
     357,  330, 0x0a495001,
     364,  330, 0x0a495001,
     371,  330, 0x0a495001,
     380,  330, 0x0a495001,
     384,  330, 0x0a495001,
     389,  330, 0x0a495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_PgcRouterApp[] = {
    "PgcRouterApp\0\0requestChanged()\0"
    "statusChanged()\0msg\0cardDone(QString)\0"
    "handleInvoke(bb::system::InvokeRequest)\0"
    "resized(bb::system::CardResizeMessage)\0"
    "pooled(bb::system::CardDoneMessage)\0"
    "loadConfig()\0loadForms()\0"
    "onSettingsLoadCompleted()\0"
    "onSettingsSaveCompleted()\0errorStr\0"
    "onSettingsLoadFailed(QString)\0"
    "onSettingsSaveFailed(QString)\0QString\0"
    "startupMode\0source\0target\0action\0"
    "mimeType\0uri\0data\0status\0"
};

void PgcRouterApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PgcRouterApp *_t = static_cast<PgcRouterApp *>(_o);
        switch (_id) {
        case 0: _t->requestChanged(); break;
        case 1: _t->statusChanged(); break;
        case 2: _t->cardDone((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->handleInvoke((*reinterpret_cast< const bb::system::InvokeRequest(*)>(_a[1]))); break;
        case 4: _t->resized((*reinterpret_cast< const bb::system::CardResizeMessage(*)>(_a[1]))); break;
        case 5: _t->pooled((*reinterpret_cast< const bb::system::CardDoneMessage(*)>(_a[1]))); break;
        case 6: _t->loadConfig(); break;
        case 7: _t->loadForms(); break;
        case 8: _t->onSettingsLoadCompleted(); break;
        case 9: _t->onSettingsSaveCompleted(); break;
        case 10: _t->onSettingsLoadFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->onSettingsSaveFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PgcRouterApp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PgcRouterApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PgcRouterApp,
      qt_meta_data_PgcRouterApp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PgcRouterApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PgcRouterApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PgcRouterApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PgcRouterApp))
        return static_cast<void*>(const_cast< PgcRouterApp*>(this));
    return QObject::qt_metacast(_clname);
}

int PgcRouterApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = startupMode(); break;
        case 1: *reinterpret_cast< QString*>(_v) = source(); break;
        case 2: *reinterpret_cast< QString*>(_v) = target(); break;
        case 3: *reinterpret_cast< QString*>(_v) = action(); break;
        case 4: *reinterpret_cast< QString*>(_v) = mimeType(); break;
        case 5: *reinterpret_cast< QString*>(_v) = uri(); break;
        case 6: *reinterpret_cast< QString*>(_v) = data(); break;
        case 7: *reinterpret_cast< QString*>(_v) = status(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PgcRouterApp::requestChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PgcRouterApp::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
