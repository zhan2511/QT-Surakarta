/****************************************************************************
** Meta object code from reading C++ file 'chess_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Surakarta/chess_window.h"
#include <QtGui/qtextcursor.h>
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
    "blackgamermove",
    "SurakartaGame",
    "gamecopy",
    "whitegamermove",
    "blackgamerturn",
    "whitegamerturn",
    "timeover",
    "SurakartaPlayer",
    "time_out",
    "mainshow",
    "select_",
    "moveend_",
    "winner_",
    "game",
    "setboard",
    "decideblackmove",
    "decidewhitemove"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSchess_windowENDCLASS_t {
    uint offsetsAndSizes[54];
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
    char stringdata10[15];
    char stringdata11[14];
    char stringdata12[9];
    char stringdata13[15];
    char stringdata14[15];
    char stringdata15[15];
    char stringdata16[9];
    char stringdata17[16];
    char stringdata18[9];
    char stringdata19[9];
    char stringdata20[8];
    char stringdata21[9];
    char stringdata22[8];
    char stringdata23[5];
    char stringdata24[9];
    char stringdata25[16];
    char stringdata26[16];
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
        QT_MOC_LITERAL(87, 14),  // "blackgamermove"
        QT_MOC_LITERAL(102, 13),  // "SurakartaGame"
        QT_MOC_LITERAL(116, 8),  // "gamecopy"
        QT_MOC_LITERAL(125, 14),  // "whitegamermove"
        QT_MOC_LITERAL(140, 14),  // "blackgamerturn"
        QT_MOC_LITERAL(155, 14),  // "whitegamerturn"
        QT_MOC_LITERAL(170, 8),  // "timeover"
        QT_MOC_LITERAL(179, 15),  // "SurakartaPlayer"
        QT_MOC_LITERAL(195, 8),  // "time_out"
        QT_MOC_LITERAL(204, 8),  // "mainshow"
        QT_MOC_LITERAL(213, 7),  // "select_"
        QT_MOC_LITERAL(221, 8),  // "moveend_"
        QT_MOC_LITERAL(230, 7),  // "winner_"
        QT_MOC_LITERAL(238, 4),  // "game"
        QT_MOC_LITERAL(243, 8),  // "setboard"
        QT_MOC_LITERAL(252, 15),  // "decideblackmove"
        QT_MOC_LITERAL(268, 15)   // "decidewhitemove"
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
    "blackgamermove",
    "SurakartaGame",
    "gamecopy",
    "whitegamermove",
    "blackgamerturn",
    "whitegamerturn",
    "timeover",
    "SurakartaPlayer",
    "time_out",
    "mainshow",
    "select_",
    "moveend_",
    "winner_",
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
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x06,    1 /* Public */,
       4,    1,  119,    2, 0x06,    3 /* Public */,
       5,    1,  122,    2, 0x06,    5 /* Public */,
       8,    1,  125,    2, 0x06,    7 /* Public */,
      10,    1,  128,    2, 0x06,    9 /* Public */,
      13,    1,  131,    2, 0x06,   11 /* Public */,
      14,    0,  134,    2, 0x06,   13 /* Public */,
      15,    0,  135,    2, 0x06,   14 /* Public */,
      16,    1,  136,    2, 0x06,   15 /* Public */,
      19,    0,  139,    2, 0x06,   17 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    1,  140,    2, 0x0a,   18 /* Public */,
      21,    1,  143,    2, 0x0a,   20 /* Public */,
      22,    1,  146,    2, 0x0a,   22 /* Public */,
      22,    1,  149,    2, 0x0a,   24 /* Public */,
      24,    1,  152,    2, 0x0a,   26 /* Public */,
      25,    1,  155,    2, 0x0a,   28 /* Public */,
      26,    1,  158,    2, 0x0a,   30 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 11,   23,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 11,   23,
    QMetaType::Void, 0x80000000 | 11,   23,
    QMetaType::Void, 0x80000000 | 11,   23,

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
        // method 'blackgamermove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'whitegamermove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'blackgamerturn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'whitegamerturn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timeover'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaPlayer, std::false_type>,
        // method 'mainshow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'select_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'moveend_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'winner_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaGame, std::false_type>,
        // method 'winner_'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SurakartaPlayer, std::false_type>,
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
        case 4: _t->blackgamermove((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 5: _t->whitegamermove((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 6: _t->blackgamerturn(); break;
        case 7: _t->whitegamerturn(); break;
        case 8: _t->timeover((*reinterpret_cast< std::add_pointer_t<SurakartaPlayer>>(_a[1]))); break;
        case 9: _t->mainshow(); break;
        case 10: _t->select_((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->moveend_((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->winner_((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 13: _t->winner_((*reinterpret_cast< std::add_pointer_t<SurakartaPlayer>>(_a[1]))); break;
        case 14: _t->setboard((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 15: _t->decideblackmove((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
        case 16: _t->decidewhitemove((*reinterpret_cast< std::add_pointer_t<SurakartaGame>>(_a[1]))); break;
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
        {
            using _t = void (chess_window::*)(SurakartaGame );
            if (_t _q_method = &chess_window::blackgamermove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (chess_window::*)(SurakartaGame );
            if (_t _q_method = &chess_window::whitegamermove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (chess_window::*)();
            if (_t _q_method = &chess_window::blackgamerturn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (chess_window::*)();
            if (_t _q_method = &chess_window::whitegamerturn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (chess_window::*)(SurakartaPlayer );
            if (_t _q_method = &chess_window::timeover; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (chess_window::*)();
            if (_t _q_method = &chess_window::mainshow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
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

// SIGNAL 4
void chess_window::blackgamermove(SurakartaGame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void chess_window::whitegamermove(SurakartaGame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void chess_window::blackgamerturn()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void chess_window::whitegamerturn()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void chess_window::timeover(SurakartaPlayer _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void chess_window::mainshow()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
