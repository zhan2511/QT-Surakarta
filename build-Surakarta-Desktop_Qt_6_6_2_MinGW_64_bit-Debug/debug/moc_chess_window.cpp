/****************************************************************************
** Meta object code from reading C++ file 'chess_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Surakarta/chess_window.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chess_window.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSchess_windowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSchess_windowENDCLASS = QtMocHelpers::stringData(
    "chess_window",
    "select",
    "",
    "pos",
    "moveend",
    "blackmove",
    "SurakartaMove",
    "Blackmove",
    "whitemove",
    "Whitemove",
    "select_",
    "moveend_",
    "winner_",
    "SurakartaGame",
    "game",
    "setboard",
    "decideblackmove",
    "decidewhitemove"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSchess_windowENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[13];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[8];
    char stringdata5[10];
    char stringdata6[14];
    char stringdata7[10];
    char stringdata8[10];
    char stringdata9[10];
    char stringdata10[8];
    char stringdata11[9];
    char stringdata12[8];
    char stringdata13[14];
    char stringdata14[5];
    char stringdata15[9];
    char stringdata16[16];
    char stringdata17[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSchess_windowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSchess_windowENDCLASS_t qt_meta_stringdata_CLASSchess_windowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "chess_window"
        QT_MOC_LITERAL(13, 6),  // "select"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 3),  // "pos"
        QT_MOC_LITERAL(25, 7),  // "moveend"
        QT_MOC_LITERAL(33, 9),  // "blackmove"
        QT_MOC_LITERAL(43, 13),  // "SurakartaMove"
        QT_MOC_LITERAL(57, 9),  // "Blackmove"
        QT_MOC_LITERAL(67, 9),  // "whitemove"
        QT_MOC_LITERAL(77, 9),  // "Whitemove"
        QT_MOC_LITERAL(87, 7),  // "select_"
        QT_MOC_LITERAL(95, 8),  // "moveend_"
        QT_MOC_LITERAL(104, 7),  // "winner_"
        QT_MOC_LITERAL(112, 13),  // "SurakartaGame"
        QT_MOC_LITERAL(126, 4),  // "game"
        QT_MOC_LITERAL(131, 8),  // "setboard"
        QT_MOC_LITERAL(140, 15),  // "decideblackmove"
        QT_MOC_LITERAL(156, 15)   // "decidewhitemove"
    },
    "chess_window",
    "select",
    "",
    "pos",
    "moveend",
    "blackmove",
    "SurakartaMove",
    "Blackmove",
    "whitemove",
    "Whitemove",
    "select_",
    "moveend_",
    "winner_",
    "SurakartaGame",
    "game",
    "setboard",
    "decideblackmove",
    "decidewhitemove"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSchess_windowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       5,    1,   80,    2, 0x06,    5 /* Public */,
       8,    1,   83,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   86,    2, 0x0a,    9 /* Public */,
      11,    1,   89,    2, 0x0a,   11 /* Public */,
      12,    1,   92,    2, 0x0a,   13 /* Public */,
      15,    1,   95,    2, 0x0a,   15 /* Public */,
      16,    1,   98,    2, 0x0a,   17 /* Public */,
      17,    1,  101,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject chess_window::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSchess_windowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSchess_windowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSchess_windowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<chess_window, std::true_type>,
        // method 'select'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'moveend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'blackmove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaMove, std::false_type>,
        // method 'whitemove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaMove, std::false_type>,
        // method 'select_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'moveend_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'winner_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'setboard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'decideblackmove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'decidewhitemove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>
    >,
    nullptr
} };

void chess_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<chess_window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->select((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->moveend((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->blackmove((*reinterpret_cast< std::add_pointer_t<SurakartaMove>>(_a[1]))); break;
        case 3: _t->whitemove((*reinterpret_cast< std::add_pointer_t<SurakartaMove>>(_a[1]))); break;
        case 4: _t->select_((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->moveend_((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->winner_((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 7: _t->setboard((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 8: _t->decideblackmove((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 9: _t->decidewhitemove((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (chess_window::*)(int );
            if (_t _q_method = &chess_window::select; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (chess_window::*)(int );
            if (_t _q_method = &chess_window::moveend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (chess_window::*)(SurakartaMove );
            if (_t _q_method = &chess_window::blackmove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (chess_window::*)(SurakartaMove );
            if (_t _q_method = &chess_window::whitemove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *chess_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chess_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSchess_windowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int chess_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void chess_window::select(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void chess_window::moveend(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void chess_window::blackmove(SurakartaMove _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void chess_window::whitemove(SurakartaMove _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
