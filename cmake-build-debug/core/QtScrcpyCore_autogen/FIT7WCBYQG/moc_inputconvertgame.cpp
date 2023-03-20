/****************************************************************************
** Meta object code from reading C++ file 'inputconvertgame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../core/src/device/controller/inputconvert/inputconvertgame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputconvertgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InputConvertGame_t {
    QByteArrayData data[4];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InputConvertGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InputConvertGame_t qt_meta_stringdata_InputConvertGame = {
    {
QT_MOC_LITERAL(0, 0, 16), // "InputConvertGame"
QT_MOC_LITERAL(1, 17, 17), // "onSteerWheelTimer"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11) // "onDragTimer"

    },
    "InputConvertGame\0onSteerWheelTimer\0\0"
    "onDragTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InputConvertGame[] = {

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
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InputConvertGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputConvertGame *_t = static_cast<InputConvertGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSteerWheelTimer(); break;
        case 1: _t->onDragTimer(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject InputConvertGame::staticMetaObject = {
    { &InputConvertNormal::staticMetaObject, qt_meta_stringdata_InputConvertGame.data,
      qt_meta_data_InputConvertGame,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *InputConvertGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputConvertGame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InputConvertGame.stringdata0))
        return static_cast<void*>(this);
    return InputConvertNormal::qt_metacast(_clname);
}

int InputConvertGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = InputConvertNormal::qt_metacall(_c, _id, _a);
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
