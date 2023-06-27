/****************************************************************************
** Meta object code from reading C++ file 'recommendwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../lab3/recommendwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recommendwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RecommendWindow_t {
    const uint offsetsAndSize[22];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RecommendWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RecommendWindow_t qt_meta_stringdata_RecommendWindow = {
    {
QT_MOC_LITERAL(0, 15), // "RecommendWindow"
QT_MOC_LITERAL(16, 8), // "respond1"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 8), // "respond2"
QT_MOC_LITERAL(35, 8), // "respond3"
QT_MOC_LITERAL(44, 8), // "respond4"
QT_MOC_LITERAL(53, 8), // "respond5"
QT_MOC_LITERAL(62, 8), // "respond6"
QT_MOC_LITERAL(71, 8), // "respond7"
QT_MOC_LITERAL(80, 8), // "respond8"
QT_MOC_LITERAL(89, 8) // "respond9"

    },
    "RecommendWindow\0respond1\0\0respond2\0"
    "respond3\0respond4\0respond5\0respond6\0"
    "respond7\0respond8\0respond9"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecommendWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    0,   69,    2, 0x0a,    2 /* Public */,
       4,    0,   70,    2, 0x0a,    3 /* Public */,
       5,    0,   71,    2, 0x0a,    4 /* Public */,
       6,    0,   72,    2, 0x0a,    5 /* Public */,
       7,    0,   73,    2, 0x0a,    6 /* Public */,
       8,    0,   74,    2, 0x0a,    7 /* Public */,
       9,    0,   75,    2, 0x0a,    8 /* Public */,
      10,    0,   76,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RecommendWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RecommendWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->respond1(); break;
        case 1: _t->respond2(); break;
        case 2: _t->respond3(); break;
        case 3: _t->respond4(); break;
        case 4: _t->respond5(); break;
        case 5: _t->respond6(); break;
        case 6: _t->respond7(); break;
        case 7: _t->respond8(); break;
        case 8: _t->respond9(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject RecommendWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_RecommendWindow.offsetsAndSize,
    qt_meta_data_RecommendWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RecommendWindow_t
, QtPrivate::TypeAndForceComplete<RecommendWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RecommendWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecommendWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecommendWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RecommendWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
