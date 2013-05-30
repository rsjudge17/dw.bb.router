/****************************************************************************
** Meta object code from reading C++ file 'routerconfig.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/config/routerconfig.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'routerconfig.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dw__config__RouterConfig[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       8,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   26,   25,   25, 0x05,
      68,   59,   25,   25, 0x05,
     101,   59,   25,   25, 0x05,
     128,   59,   25,   25, 0x05,
     156,   25,   25,   25, 0x05,

 // properties: name, type, flags
     177,  172, 0x01495103,
     191,  183, 0x0a095103,
     199,  183, 0x0a095103,
     210,  183, 0x0a095103,
     221,  183, 0x0a095103,
     237,  183, 0x0a495103,
     243,  183, 0x0a495103,
     250,  172, 0x01495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       2,
       3,
       1,

       0        // eod
};

static const char qt_meta_stringdata_dw__config__RouterConfig[] = {
    "dw::config::RouterConfig\0\0newDebug\0"
    "debugValueChanged(bool)\0newValue\0"
    "trackerSupportValueChanged(bool)\0"
    "fmUrlValueChanged(QString)\0"
    "jmsUrlValueChanged(QString)\0loadCompleted()\0"
    "bool\0debug\0QString\0appName\0appVersion\0"
    "deviceName\0platformVersion\0fmUrl\0"
    "jmsUrl\0trackerSupport\0"
};

void dw::config::RouterConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RouterConfig *_t = static_cast<RouterConfig *>(_o);
        switch (_id) {
        case 0: _t->debugValueChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->trackerSupportValueChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->fmUrlValueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->jmsUrlValueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->loadCompleted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dw::config::RouterConfig::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dw::config::RouterConfig::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_dw__config__RouterConfig,
      qt_meta_data_dw__config__RouterConfig, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dw::config::RouterConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dw::config::RouterConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dw::config::RouterConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dw__config__RouterConfig))
        return static_cast<void*>(const_cast< RouterConfig*>(this));
    return Config::qt_metacast(_clname);
}

int dw::config::RouterConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< bool*>(_v) = isDebug(); break;
        case 1: *reinterpret_cast< QString*>(_v) = appName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = appVersion(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getDeviceName(); break;
        case 4: *reinterpret_cast< QString*>(_v) = getPlatformVersion(); break;
        case 5: *reinterpret_cast< QString*>(_v) = getFmUrl(); break;
        case 6: *reinterpret_cast< QString*>(_v) = getJmsUrl(); break;
        case 7: *reinterpret_cast< bool*>(_v) = isTrackerSupported(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDebug(*reinterpret_cast< bool*>(_v)); break;
        case 1: setAppName(*reinterpret_cast< QString*>(_v)); break;
        case 2: setAppVersion(*reinterpret_cast< QString*>(_v)); break;
        case 3: setDeviceName(*reinterpret_cast< QString*>(_v)); break;
        case 4: setPlatformVersion(*reinterpret_cast< QString*>(_v)); break;
        case 5: setFmUrl(*reinterpret_cast< QString*>(_v)); break;
        case 6: setJmsUrl(*reinterpret_cast< QString*>(_v)); break;
        case 7: setTrackerSupport(*reinterpret_cast< bool*>(_v)); break;
        }
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
void dw::config::RouterConfig::debugValueChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void dw::config::RouterConfig::trackerSupportValueChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void dw::config::RouterConfig::fmUrlValueChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void dw::config::RouterConfig::jmsUrlValueChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void dw::config::RouterConfig::loadCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
