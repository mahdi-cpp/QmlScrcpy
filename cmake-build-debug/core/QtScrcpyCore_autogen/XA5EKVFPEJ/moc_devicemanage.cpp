/****************************************************************************
** Meta object code from reading C++ file 'devicemanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../core/src/devicemanage/devicemanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicemanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qsc__DeviceManage_t {
    QByteArrayData data[8];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qsc__DeviceManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qsc__DeviceManage_t qt_meta_stringdata_qsc__DeviceManage = {
    {
QT_MOC_LITERAL(0, 0, 17), // "qsc::DeviceManage"
QT_MOC_LITERAL(1, 18, 17), // "onDeviceConnected"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "success"
QT_MOC_LITERAL(4, 45, 6), // "serial"
QT_MOC_LITERAL(5, 52, 10), // "deviceName"
QT_MOC_LITERAL(6, 63, 4), // "size"
QT_MOC_LITERAL(7, 68, 20) // "onDeviceDisconnected"

    },
    "qsc::DeviceManage\0onDeviceConnected\0"
    "\0success\0serial\0deviceName\0size\0"
    "onDeviceDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qsc__DeviceManage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x09 /* Protected */,
       7,    1,   33,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QSize,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void qsc::DeviceManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeviceManage *_t = static_cast<DeviceManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDeviceConnected((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QSize(*)>(_a[4]))); break;
        case 1: _t->onDeviceDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qsc::DeviceManage::staticMetaObject = {
    { &IDeviceManage::staticMetaObject, qt_meta_stringdata_qsc__DeviceManage.data,
      qt_meta_data_qsc__DeviceManage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *qsc::DeviceManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qsc::DeviceManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qsc__DeviceManage.stringdata0))
        return static_cast<void*>(this);
    return IDeviceManage::qt_metacast(_clname);
}

int qsc::DeviceManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IDeviceManage::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
