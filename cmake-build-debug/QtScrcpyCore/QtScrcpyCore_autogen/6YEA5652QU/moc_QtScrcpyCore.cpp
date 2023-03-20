/****************************************************************************
** Meta object code from reading C++ file 'QtScrcpyCore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QtScrcpyCore/include/QtScrcpyCore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtScrcpyCore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qsc__IDevice_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qsc__IDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qsc__IDevice_t qt_meta_stringdata_qsc__IDevice = {
    {
QT_MOC_LITERAL(0, 0, 12), // "qsc::IDevice"
QT_MOC_LITERAL(1, 13, 15), // "deviceConnected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "success"
QT_MOC_LITERAL(4, 38, 6), // "serial"
QT_MOC_LITERAL(5, 45, 10), // "deviceName"
QT_MOC_LITERAL(6, 56, 4), // "size"
QT_MOC_LITERAL(7, 61, 18) // "deviceDisconnected"

    },
    "qsc::IDevice\0deviceConnected\0\0success\0"
    "serial\0deviceName\0size\0deviceDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qsc__IDevice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,
       7,    1,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QSize,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void qsc::IDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IDevice *_t = static_cast<IDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceConnected((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QSize(*)>(_a[4]))); break;
        case 1: _t->deviceDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (IDevice::*_t)(bool , const QString & , const QString & , const QSize & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDevice::deviceConnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IDevice::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDevice::deviceDisconnected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qsc::IDevice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qsc__IDevice.data,
      qt_meta_data_qsc__IDevice,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *qsc::IDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qsc::IDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qsc__IDevice.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qsc::IDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qsc::IDevice::deviceConnected(bool _t1, const QString & _t2, const QString & _t3, const QSize & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qsc::IDevice::deviceDisconnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_qsc__IDeviceManage_t {
    QByteArrayData data[8];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qsc__IDeviceManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qsc__IDeviceManage_t qt_meta_stringdata_qsc__IDeviceManage = {
    {
QT_MOC_LITERAL(0, 0, 18), // "qsc::IDeviceManage"
QT_MOC_LITERAL(1, 19, 15), // "deviceConnected"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "success"
QT_MOC_LITERAL(4, 44, 6), // "serial"
QT_MOC_LITERAL(5, 51, 10), // "deviceName"
QT_MOC_LITERAL(6, 62, 4), // "size"
QT_MOC_LITERAL(7, 67, 18) // "deviceDisconnected"

    },
    "qsc::IDeviceManage\0deviceConnected\0\0"
    "success\0serial\0deviceName\0size\0"
    "deviceDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qsc__IDeviceManage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,
       7,    1,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QSize,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void qsc::IDeviceManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IDeviceManage *_t = static_cast<IDeviceManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceConnected((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QSize(*)>(_a[4]))); break;
        case 1: _t->deviceDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (IDeviceManage::*_t)(bool , const QString & , const QString & , const QSize & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDeviceManage::deviceConnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IDeviceManage::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDeviceManage::deviceDisconnected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qsc::IDeviceManage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qsc__IDeviceManage.data,
      qt_meta_data_qsc__IDeviceManage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *qsc::IDeviceManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qsc::IDeviceManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qsc__IDeviceManage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qsc::IDeviceManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qsc::IDeviceManage::deviceConnected(bool _t1, const QString & _t2, const QString & _t3, const QSize & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qsc::IDeviceManage::deviceDisconnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
