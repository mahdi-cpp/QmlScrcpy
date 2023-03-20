/****************************************************************************
** Meta object code from reading C++ file 'filehandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QtScrcpyCore/src/device/filehandler/filehandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileHandler_t {
    QByteArrayData data[12];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileHandler_t qt_meta_stringdata_FileHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileHandler"
QT_MOC_LITERAL(1, 12, 17), // "fileHandlerResult"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "FILE_HANDLER_RESULT"
QT_MOC_LITERAL(4, 51, 13), // "processResult"
QT_MOC_LITERAL(5, 65, 5), // "isApk"
QT_MOC_LITERAL(6, 71, 17), // "onPushFileRequest"
QT_MOC_LITERAL(7, 89, 6), // "serial"
QT_MOC_LITERAL(8, 96, 4), // "file"
QT_MOC_LITERAL(9, 101, 10), // "devicePath"
QT_MOC_LITERAL(10, 112, 19), // "onInstallApkRequest"
QT_MOC_LITERAL(11, 132, 7) // "apkFile"

    },
    "FileHandler\0fileHandlerResult\0\0"
    "FILE_HANDLER_RESULT\0processResult\0"
    "isApk\0onPushFileRequest\0serial\0file\0"
    "devicePath\0onInstallApkRequest\0apkFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       1,    1,   44,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   47,    2, 0x0a /* Public */,
       6,    2,   54,    2, 0x2a /* Public | MethodCloned */,
      10,    2,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,   11,

       0        // eod
};

void FileHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileHandler *_t = static_cast<FileHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileHandlerResult((*reinterpret_cast< FILE_HANDLER_RESULT(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->fileHandlerResult((*reinterpret_cast< FILE_HANDLER_RESULT(*)>(_a[1]))); break;
        case 2: _t->onPushFileRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->onPushFileRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->onInstallApkRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FileHandler::*_t)(FILE_HANDLER_RESULT , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileHandler::fileHandlerResult)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileHandler.data,
      qt_meta_data_FileHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FileHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FileHandler::fileHandlerResult(FILE_HANDLER_RESULT _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
