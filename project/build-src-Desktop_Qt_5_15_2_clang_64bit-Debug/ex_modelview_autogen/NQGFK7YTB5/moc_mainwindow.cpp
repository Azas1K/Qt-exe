/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/ex_modelview/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "loadFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "saveFile"
QT_MOC_LITERAL(4, 30, 10), // "addRowSlot"
QT_MOC_LITERAL(5, 41, 9), // "showAbout"
QT_MOC_LITERAL(6, 51, 20), // "changeCurrentRowSlot"
QT_MOC_LITERAL(7, 72, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 84, 13), // "deleteRowSlot"
QT_MOC_LITERAL(9, 98, 12), // "updateFilter"
QT_MOC_LITERAL(10, 111, 4), // "text"
QT_MOC_LITERAL(11, 116, 13), // "updateFilter2"
QT_MOC_LITERAL(12, 130, 19), // "updateFilterMinPers"
QT_MOC_LITERAL(13, 150, 5), // "value"
QT_MOC_LITERAL(14, 156, 19), // "updateFilterMaxPers"
QT_MOC_LITERAL(15, 176, 18), // "updateFromLineEdit"
QT_MOC_LITERAL(16, 195, 4), // "pers"
QT_MOC_LITERAL(17, 200, 16), // "updateToLineEdit"
QT_MOC_LITERAL(18, 217, 20), // "updateFilterMinPersS"
QT_MOC_LITERAL(19, 238, 4), // "line"
QT_MOC_LITERAL(20, 243, 20), // "updateFilterMaxPersS"
QT_MOC_LITERAL(21, 264, 15), // "updateLinerFrom"
QT_MOC_LITERAL(22, 280, 13), // "updateLinerTo"
QT_MOC_LITERAL(23, 294, 10) // "colorCells"

    },
    "MainWindow\0loadFile\0\0saveFile\0addRowSlot\0"
    "showAbout\0changeCurrentRowSlot\0"
    "QModelIndex\0deleteRowSlot\0updateFilter\0"
    "text\0updateFilter2\0updateFilterMinPers\0"
    "value\0updateFilterMaxPers\0updateFromLineEdit\0"
    "pers\0updateToLineEdit\0updateFilterMinPersS\0"
    "line\0updateFilterMaxPersS\0updateLinerFrom\0"
    "updateLinerTo\0colorCells"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    1,  103,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    1,  107,    2, 0x08 /* Private */,
      11,    1,  110,    2, 0x08 /* Private */,
      12,    1,  113,    2, 0x08 /* Private */,
      14,    1,  116,    2, 0x08 /* Private */,
      15,    1,  119,    2, 0x08 /* Private */,
      17,    1,  122,    2, 0x08 /* Private */,
      18,    1,  125,    2, 0x08 /* Private */,
      20,    1,  128,    2, 0x08 /* Private */,
      21,    1,  131,    2, 0x08 /* Private */,
      22,    1,  134,    2, 0x08 /* Private */,
      23,    1,  137,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadFile(); break;
        case 1: _t->saveFile(); break;
        case 2: _t->addRowSlot(); break;
        case 3: _t->showAbout(); break;
        case 4: _t->changeCurrentRowSlot((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->deleteRowSlot(); break;
        case 6: _t->updateFilter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->updateFilter2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->updateFilterMinPers((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateFilterMaxPers((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateFromLineEdit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateToLineEdit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateFilterMinPersS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->updateFilterMaxPersS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->updateLinerFrom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->updateLinerTo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->colorCells((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
