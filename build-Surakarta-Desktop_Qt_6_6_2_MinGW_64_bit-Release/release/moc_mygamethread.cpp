/****************************************************************************
** Meta object code from reading C++ file 'mygamethread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Surakarta/mygamethread.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygamethread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMyGameThreadENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMyGameThreadENDCLASS = QtMocHelpers::stringData(
    "MyGameThread",
    "GameReady",
    "",
    "SurakartaGame",
    "game",
    "BlackTurn",
    "WhiteTurn",
    "OneMove",
    "Finished",
    "blackmove_",
    "SurakartaMove",
    "Blackmove",
    "whitemove_",
    "Whitemove"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMyGameThreadENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[13];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[5];
    char stringdata5[10];
    char stringdata6[10];
    char stringdata7[8];
    char stringdata8[9];
    char stringdata9[11];
    char stringdata10[14];
    char stringdata11[10];
    char stringdata12[11];
    char stringdata13[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMyGameThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMyGameThreadENDCLASS_t qt_meta_stringdata_CLASSMyGameThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "MyGameThread"
        QT_MOC_LITERAL(13, 9),  // "GameReady"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 13),  // "SurakartaGame"
        QT_MOC_LITERAL(38, 4),  // "game"
        QT_MOC_LITERAL(43, 9),  // "BlackTurn"
        QT_MOC_LITERAL(53, 9),  // "WhiteTurn"
        QT_MOC_LITERAL(63, 7),  // "OneMove"
        QT_MOC_LITERAL(71, 8),  // "Finished"
        QT_MOC_LITERAL(80, 10),  // "blackmove_"
        QT_MOC_LITERAL(91, 13),  // "SurakartaMove"
        QT_MOC_LITERAL(105, 9),  // "Blackmove"
        QT_MOC_LITERAL(115, 10),  // "whitemove_"
        QT_MOC_LITERAL(126, 9)   // "Whitemove"
    },
    "MyGameThread",
    "GameReady",
    "",
    "SurakartaGame",
    "game",
    "BlackTurn",
    "WhiteTurn",
    "OneMove",
    "Finished",
    "blackmove_",
    "SurakartaMove",
    "Blackmove",
    "whitemove_",
    "Whitemove"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMyGameThreadENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       5,    1,   59,    2, 0x06,    3 /* Public */,
       6,    1,   62,    2, 0x06,    5 /* Public */,
       7,    1,   65,    2, 0x06,    7 /* Public */,
       8,    1,   68,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   71,    2, 0x0a,   11 /* Public */,
      12,    1,   74,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyGameThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSMyGameThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMyGameThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMyGameThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyGameThread, std::true_type>,
        // method 'GameReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'BlackTurn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'WhiteTurn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'OneMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'Finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'blackmove_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaMove, std::false_type>,
        // method 'whitemove_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaMove, std::false_type>
    >,
    nullptr
} };

void MyGameThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGameThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->GameReady((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 1: _t->BlackTurn((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 2: _t->WhiteTurn((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 3: _t->OneMove((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 4: _t->Finished((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 5: _t->blackmove_((*reinterpret_cast< std::add_pointer_t<SurakartaMove>>(_a[1]))); break;
        case 6: _t->whitemove_((*reinterpret_cast< std::add_pointer_t<SurakartaMove>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGameThread::*)(SurakartaGame );
            if (_t _q_method = &MyGameThread::GameReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGameThread::*)(SurakartaGame );
            if (_t _q_method = &MyGameThread::BlackTurn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyGameThread::*)(SurakartaGame );
            if (_t _q_method = &MyGameThread::WhiteTurn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyGameThread::*)(SurakartaGame );
            if (_t _q_method = &MyGameThread::OneMove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyGameThread::*)(SurakartaGame );
            if (_t _q_method = &MyGameThread::Finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *MyGameThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGameThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMyGameThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MyGameThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MyGameThread::GameReady(SurakartaGame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGameThread::BlackTurn(SurakartaGame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGameThread::WhiteTurn(SurakartaGame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGameThread::OneMove(SurakartaGame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGameThread::Finished(SurakartaGame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP