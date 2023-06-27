/****************************************************************************
** Meta object code from reading C++ file 'searchwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../lab3/searchwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchWindow_t {
    const uint offsetsAndSize[18];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SearchWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SearchWindow_t qt_meta_stringdata_SearchWindow = {
    {
QT_MOC_LITERAL(0, 12), // "SearchWindow"
QT_MOC_LITERAL(13, 8), // "respond1"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 8), // "respond2"
QT_MOC_LITERAL(32, 8), // "respond3"
QT_MOC_LITERAL(41, 8), // "respond4"
QT_MOC_LITERAL(50, 8), // "respond5"
QT_MOC_LITERAL(59, 8), // "respond6"
QT_MOC_LITERAL(68, 8) // "respond7"

    },
    "SearchWindow\0respond1\0\0respond2\0"
    "respond3\0respond4\0respond5\0respond6\0"
    "respond7"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    0,   58,    2, 0x0a,    3 /* Public */,
       5,    0,   59,    2, 0x0a,    4 /* Public */,
       6,    0,   60,    2, 0x0a,    5 /* Public */,
       7,    0,   61,    2, 0x0a,    6 /* Public */,
       8,    0,   62,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SearchWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->respond1(); break;
        case 1: _t->respond2(); break;
        case 2: _t->respond3(); break;
        case 3: _t->respond4(); break;
        case 4: _t->respond5(); break;
        case 5: _t->respond6(); break;
        case 6: _t->respond7(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject SearchWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SearchWindow.offsetsAndSize,
    qt_meta_data_SearchWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SearchWindow_t
, QtPrivate::TypeAndForceComplete<SearchWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SearchWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SearchWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
