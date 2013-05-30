/****************************************************************************
** Meta object code from reading C++ file 'trackersettings.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/config/trackersettings.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackersettings.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dw__config__TrackerSettings[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      16,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      33,   28, 0x01095103,
      56,   52, 0x02095103,
      72,   52, 0x02095103,
      88,   52, 0x02095103,
     102,   52, 0x02095103,
     119,   52, 0x02095103,
     134,   52, 0x02095103,
     153,   52, 0x02095103,
     170,   52, 0x02095103,
     188,   52, 0x02095103,
     204,   52, 0x02095103,
     220,   52, 0x02095103,
     234,   52, 0x02095103,
     252,   52, 0x02095103,
     268,   52, 0x02095103,
     284,   52, 0x02095103,

       0        // eod
};

static const char qt_meta_stringdata_dw__config__TrackerSettings[] = {
    "dw::config::TrackerSettings\0bool\0"
    "pollingStartSwitch\0int\0pollingInterval\0"
    "startTimeMonday\0endTimeMonday\0"
    "startTimeTuesday\0endTimeTuesday\0"
    "startTimeWednesday\0endTimeWednesday\0"
    "startTimeThursday\0endTimeThursday\0"
    "startTimeFriday\0endTimeFriday\0"
    "startTimeSaturday\0endTimeSaturday\0"
    "startTimeSunday\0endTimeSunday\0"
};

void dw::config::TrackerSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dw::config::TrackerSettings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dw::config::TrackerSettings::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_dw__config__TrackerSettings,
      qt_meta_data_dw__config__TrackerSettings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dw::config::TrackerSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dw::config::TrackerSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dw::config::TrackerSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dw__config__TrackerSettings))
        return static_cast<void*>(const_cast< TrackerSettings*>(this));
    return Config::qt_metacast(_clname);
}

int dw::config::TrackerSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isPollingStartSwitch(); break;
        case 1: *reinterpret_cast< int*>(_v) = pollingInterval(); break;
        case 2: *reinterpret_cast< int*>(_v) = startTimeMonday(); break;
        case 3: *reinterpret_cast< int*>(_v) = endTimeMonday(); break;
        case 4: *reinterpret_cast< int*>(_v) = startTimeTuesday(); break;
        case 5: *reinterpret_cast< int*>(_v) = endTimeTuesday(); break;
        case 6: *reinterpret_cast< int*>(_v) = startTimeWednesday(); break;
        case 7: *reinterpret_cast< int*>(_v) = endTimeWednesday(); break;
        case 8: *reinterpret_cast< int*>(_v) = startTimeThursday(); break;
        case 9: *reinterpret_cast< int*>(_v) = endTimeThursday(); break;
        case 10: *reinterpret_cast< int*>(_v) = startTimeFriday(); break;
        case 11: *reinterpret_cast< int*>(_v) = endTimeFriday(); break;
        case 12: *reinterpret_cast< int*>(_v) = startTimeSaturday(); break;
        case 13: *reinterpret_cast< int*>(_v) = endTimeSaturday(); break;
        case 14: *reinterpret_cast< int*>(_v) = startTimeSunday(); break;
        case 15: *reinterpret_cast< int*>(_v) = endTimeSunday(); break;
        }
        _id -= 16;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPollingStartSwitch(*reinterpret_cast< bool*>(_v)); break;
        case 1: setPollingInterval(*reinterpret_cast< int*>(_v)); break;
        case 2: setStartTimeMonday(*reinterpret_cast< int*>(_v)); break;
        case 3: setEndTimeMonday(*reinterpret_cast< int*>(_v)); break;
        case 4: setStartTimeTuesday(*reinterpret_cast< int*>(_v)); break;
        case 5: setEndTimeTuesday(*reinterpret_cast< int*>(_v)); break;
        case 6: setStartTimeWednesday(*reinterpret_cast< int*>(_v)); break;
        case 7: setEndTimeWednesday(*reinterpret_cast< int*>(_v)); break;
        case 8: setStartTimeThursday(*reinterpret_cast< int*>(_v)); break;
        case 9: setEndTimeThursday(*reinterpret_cast< int*>(_v)); break;
        case 10: setStartTimeFriday(*reinterpret_cast< int*>(_v)); break;
        case 11: setEndTimeFriday(*reinterpret_cast< int*>(_v)); break;
        case 12: setStartTimeSaturday(*reinterpret_cast< int*>(_v)); break;
        case 13: setEndTimeSaturday(*reinterpret_cast< int*>(_v)); break;
        case 14: setStartTimeSunday(*reinterpret_cast< int*>(_v)); break;
        case 15: setEndTimeSunday(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 16;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 16;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
