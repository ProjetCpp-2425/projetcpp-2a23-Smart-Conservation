/****************************************************************************
** Meta object code from reading C++ file 'commande.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../commande.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commande.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_commande_t {
    const uint offsetsAndSize[38];
    char stringdata0[410];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_commande_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_commande_t qt_meta_stringdata_commande = {
    {
QT_MOC_LITERAL(0, 8), // "commande"
QT_MOC_LITERAL(9, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 24), // "on_pushButton_10_clicked"
QT_MOC_LITERAL(59, 28), // "on_edit_table_button_clicked"
QT_MOC_LITERAL(88, 24), // "on_button_delete_clicked"
QT_MOC_LITERAL(113, 22), // "on_return_main_clicked"
QT_MOC_LITERAL(136, 23), // "on_export_table_clicked"
QT_MOC_LITERAL(160, 23), // "filterTableByDeliveryId"
QT_MOC_LITERAL(184, 10), // "searchText"
QT_MOC_LITERAL(195, 32), // "on_tableWidget_cellDoubleClicked"
QT_MOC_LITERAL(228, 3), // "row"
QT_MOC_LITERAL(232, 6), // "column"
QT_MOC_LITERAL(239, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(263, 24), // "onTableWidgetRowSelected"
QT_MOC_LITERAL(288, 30), // "on_back_qrcode_ordered_clicked"
QT_MOC_LITERAL(319, 34), // "on_back_qrcode_in_progress_cl..."
QT_MOC_LITERAL(354, 32), // "on_back_qrcode_delivered_clicked"
QT_MOC_LITERAL(387, 22) // "on_statsbutton_clicked"

    },
    "commande\0on_pushButton_3_clicked\0\0"
    "on_pushButton_10_clicked\0"
    "on_edit_table_button_clicked\0"
    "on_button_delete_clicked\0"
    "on_return_main_clicked\0on_export_table_clicked\0"
    "filterTableByDeliveryId\0searchText\0"
    "on_tableWidget_cellDoubleClicked\0row\0"
    "column\0on_pushButton_2_clicked\0"
    "onTableWidgetRowSelected\0"
    "on_back_qrcode_ordered_clicked\0"
    "on_back_qrcode_in_progress_clicked\0"
    "on_back_qrcode_delivered_clicked\0"
    "on_statsbutton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_commande[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    1,  104,    2, 0x08,    7 /* Private */,
      10,    2,  107,    2, 0x08,    9 /* Private */,
      13,    0,  112,    2, 0x08,   12 /* Private */,
      14,    2,  113,    2, 0x08,   13 /* Private */,
      15,    0,  118,    2, 0x08,   16 /* Private */,
      16,    0,  119,    2, 0x08,   17 /* Private */,
      17,    0,  120,    2, 0x08,   18 /* Private */,
      18,    0,  121,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void commande::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<commande *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_3_clicked(); break;
        case 1: _t->on_pushButton_10_clicked(); break;
        case 2: _t->on_edit_table_button_clicked(); break;
        case 3: _t->on_button_delete_clicked(); break;
        case 4: _t->on_return_main_clicked(); break;
        case 5: _t->on_export_table_clicked(); break;
        case 6: _t->filterTableByDeliveryId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_tableWidget_cellDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->onTableWidgetRowSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->on_back_qrcode_ordered_clicked(); break;
        case 11: _t->on_back_qrcode_in_progress_clicked(); break;
        case 12: _t->on_back_qrcode_delivered_clicked(); break;
        case 13: _t->on_statsbutton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject commande::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_commande.offsetsAndSize,
    qt_meta_data_commande,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_commande_t
, QtPrivate::TypeAndForceComplete<commande, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *commande::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *commande::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_commande.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int commande::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
