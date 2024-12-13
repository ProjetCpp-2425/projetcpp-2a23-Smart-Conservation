/****************************************************************************
** Meta object code from reading C++ file 'management.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../projetcpp-2a23-Smart-Conservation-Rayen-yassine-arduino/management.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'management.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_management_t {
    const uint offsetsAndSize[178];
    char stringdata0[1881];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_management_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_management_t qt_meta_stringdata_management = {
    {
QT_MOC_LITERAL(0, 10), // "management"
QT_MOC_LITERAL(11, 20), // "on_employees_clicked"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 21), // "on_deliveries_clicked"
QT_MOC_LITERAL(55, 19), // "on_machines_clicked"
QT_MOC_LITERAL(75, 17), // "on_logout_clicked"
QT_MOC_LITERAL(93, 27), // "on_add_employee_btn_clicked"
QT_MOC_LITERAL(121, 19), // "on_add_back_clicked"
QT_MOC_LITERAL(141, 22), // "on_update_back_clicked"
QT_MOC_LITERAL(164, 23), // "on_history_back_clicked"
QT_MOC_LITERAL(188, 31), // "on_confirm_employee_btn_clicked"
QT_MOC_LITERAL(220, 30), // "on_update_employee_btn_clicked"
QT_MOC_LITERAL(251, 29), // "on_confirm_update_btn_clicked"
QT_MOC_LITERAL(281, 30), // "on_delete_employee_btn_clicked"
QT_MOC_LITERAL(312, 16), // "on_searchConfirm"
QT_MOC_LITERAL(329, 22), // "on_searchReset_clicked"
QT_MOC_LITERAL(352, 24), // "onTableItemDoubleClicked"
QT_MOC_LITERAL(377, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(395, 4), // "item"
QT_MOC_LITERAL(400, 26), // "on_employee_export_clicked"
QT_MOC_LITERAL(427, 18), // "updateProgressBars"
QT_MOC_LITERAL(446, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(470, 24), // "on_pushButton_10_clicked"
QT_MOC_LITERAL(495, 28), // "on_edit_table_button_clicked"
QT_MOC_LITERAL(524, 24), // "on_button_delete_clicked"
QT_MOC_LITERAL(549, 22), // "on_return_main_clicked"
QT_MOC_LITERAL(572, 23), // "on_export_table_clicked"
QT_MOC_LITERAL(596, 23), // "filterTableByDeliveryId"
QT_MOC_LITERAL(620, 10), // "searchText"
QT_MOC_LITERAL(631, 32), // "on_tableWidget_cellDoubleClicked"
QT_MOC_LITERAL(664, 3), // "row"
QT_MOC_LITERAL(668, 6), // "column"
QT_MOC_LITERAL(675, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(699, 24), // "onTableWidgetRowSelected"
QT_MOC_LITERAL(724, 30), // "on_back_qrcode_ordered_clicked"
QT_MOC_LITERAL(755, 34), // "on_back_qrcode_in_progress_cl..."
QT_MOC_LITERAL(790, 32), // "on_back_qrcode_delivered_clicked"
QT_MOC_LITERAL(823, 22), // "on_statsbutton_clicked"
QT_MOC_LITERAL(846, 18), // "on_ajouter_clicked"
QT_MOC_LITERAL(865, 19), // "on_delete_2_clicked"
QT_MOC_LITERAL(885, 24), // "on_pushButton_22_clicked"
QT_MOC_LITERAL(910, 24), // "on_pushButton_23_clicked"
QT_MOC_LITERAL(935, 24), // "on_pushButton_11_clicked"
QT_MOC_LITERAL(960, 24), // "on_pushButton_12_clicked"
QT_MOC_LITERAL(985, 24), // "on_pushButton_13_clicked"
QT_MOC_LITERAL(1010, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(1034, 24), // "on_pushButton_16_clicked"
QT_MOC_LITERAL(1059, 24), // "on_pushButton_25_clicked"
QT_MOC_LITERAL(1084, 22), // "on_tableView_4_clicked"
QT_MOC_LITERAL(1107, 11), // "QModelIndex"
QT_MOC_LITERAL(1119, 5), // "index"
QT_MOC_LITERAL(1125, 24), // "on_pushButton_24_clicked"
QT_MOC_LITERAL(1150, 24), // "on_filterButton_clickedF"
QT_MOC_LITERAL(1175, 15), // "on_add_clickedF"
QT_MOC_LITERAL(1191, 19), // "on_annuler_clickedF"
QT_MOC_LITERAL(1211, 20), // "on_ajout_cl_clickedF"
QT_MOC_LITERAL(1232, 15), // "on_sup_clickedF"
QT_MOC_LITERAL(1248, 20), // "on_delete_2_clickedF"
QT_MOC_LITERAL(1269, 18), // "on_cancel_clickedF"
QT_MOC_LITERAL(1288, 17), // "on_cancl_clickedF"
QT_MOC_LITERAL(1306, 22), // "on_ajout_cl_2_clickedF"
QT_MOC_LITERAL(1329, 18), // "on_update_clickedF"
QT_MOC_LITERAL(1348, 20), // "on_update_2_clickedF"
QT_MOC_LITERAL(1369, 21), // "on_annuler_2_clickedF"
QT_MOC_LITERAL(1391, 27), // "on_statisticButton_clickedF"
QT_MOC_LITERAL(1419, 18), // "updateProgressBarF"
QT_MOC_LITERAL(1438, 5), // "value"
QT_MOC_LITERAL(1444, 21), // "on_pdfButton_clickedF"
QT_MOC_LITERAL(1466, 19), // "updateFactoryCountF"
QT_MOC_LITERAL(1486, 28), // "on_generateQRButton_clickedF"
QT_MOC_LITERAL(1515, 27), // "on_displayQRButton_clickedF"
QT_MOC_LITERAL(1543, 20), // "on_factories_clicked"
QT_MOC_LITERAL(1564, 14), // "on_add_clicked"
QT_MOC_LITERAL(1579, 19), // "on_ajout_cl_clicked"
QT_MOC_LITERAL(1599, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(1617, 17), // "on_update_clicked"
QT_MOC_LITERAL(1635, 19), // "on_update_2_clicked"
QT_MOC_LITERAL(1655, 14), // "on_pdf_clicked"
QT_MOC_LITERAL(1670, 16), // "on_trier_clicked"
QT_MOC_LITERAL(1687, 11), // "statistique"
QT_MOC_LITERAL(1699, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(1723, 19), // "on_selectid_clicked"
QT_MOC_LITERAL(1743, 15), // "on_send_clicked"
QT_MOC_LITERAL(1759, 12), // "update_label"
QT_MOC_LITERAL(1772, 20), // "on_dahsboard_clicked"
QT_MOC_LITERAL(1793, 24), // "on_searchReset_2_clicked"
QT_MOC_LITERAL(1818, 17), // "on_searchConfirm2"
QT_MOC_LITERAL(1836, 29), // "on_search_field_2_textChanged"
QT_MOC_LITERAL(1866, 14) // "search_field_2"

    },
    "management\0on_employees_clicked\0\0"
    "on_deliveries_clicked\0on_machines_clicked\0"
    "on_logout_clicked\0on_add_employee_btn_clicked\0"
    "on_add_back_clicked\0on_update_back_clicked\0"
    "on_history_back_clicked\0"
    "on_confirm_employee_btn_clicked\0"
    "on_update_employee_btn_clicked\0"
    "on_confirm_update_btn_clicked\0"
    "on_delete_employee_btn_clicked\0"
    "on_searchConfirm\0on_searchReset_clicked\0"
    "onTableItemDoubleClicked\0QTableWidgetItem*\0"
    "item\0on_employee_export_clicked\0"
    "updateProgressBars\0on_pushButton_3_clicked\0"
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
    "on_statsbutton_clicked\0on_ajouter_clicked\0"
    "on_delete_2_clicked\0on_pushButton_22_clicked\0"
    "on_pushButton_23_clicked\0"
    "on_pushButton_11_clicked\0"
    "on_pushButton_12_clicked\0"
    "on_pushButton_13_clicked\0"
    "on_pushButton_7_clicked\0"
    "on_pushButton_16_clicked\0"
    "on_pushButton_25_clicked\0"
    "on_tableView_4_clicked\0QModelIndex\0"
    "index\0on_pushButton_24_clicked\0"
    "on_filterButton_clickedF\0on_add_clickedF\0"
    "on_annuler_clickedF\0on_ajout_cl_clickedF\0"
    "on_sup_clickedF\0on_delete_2_clickedF\0"
    "on_cancel_clickedF\0on_cancl_clickedF\0"
    "on_ajout_cl_2_clickedF\0on_update_clickedF\0"
    "on_update_2_clickedF\0on_annuler_2_clickedF\0"
    "on_statisticButton_clickedF\0"
    "updateProgressBarF\0value\0on_pdfButton_clickedF\0"
    "updateFactoryCountF\0on_generateQRButton_clickedF\0"
    "on_displayQRButton_clickedF\0"
    "on_factories_clicked\0on_add_clicked\0"
    "on_ajout_cl_clicked\0on_cancel_clicked\0"
    "on_update_clicked\0on_update_2_clicked\0"
    "on_pdf_clicked\0on_trier_clicked\0"
    "statistique\0on_pushButton_6_clicked\0"
    "on_selectid_clicked\0on_send_clicked\0"
    "update_label\0on_dahsboard_clicked\0"
    "on_searchReset_2_clicked\0on_searchConfirm2\0"
    "on_search_field_2_textChanged\0"
    "search_field_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_management[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      78,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  482,    2, 0x08,    1 /* Private */,
       3,    0,  483,    2, 0x08,    2 /* Private */,
       4,    0,  484,    2, 0x08,    3 /* Private */,
       5,    0,  485,    2, 0x08,    4 /* Private */,
       6,    0,  486,    2, 0x08,    5 /* Private */,
       7,    0,  487,    2, 0x08,    6 /* Private */,
       8,    0,  488,    2, 0x08,    7 /* Private */,
       9,    0,  489,    2, 0x08,    8 /* Private */,
      10,    0,  490,    2, 0x08,    9 /* Private */,
      11,    0,  491,    2, 0x08,   10 /* Private */,
      12,    0,  492,    2, 0x08,   11 /* Private */,
      13,    0,  493,    2, 0x08,   12 /* Private */,
      14,    0,  494,    2, 0x08,   13 /* Private */,
      15,    0,  495,    2, 0x08,   14 /* Private */,
      16,    1,  496,    2, 0x08,   15 /* Private */,
      19,    0,  499,    2, 0x08,   17 /* Private */,
      20,    0,  500,    2, 0x08,   18 /* Private */,
      21,    0,  501,    2, 0x08,   19 /* Private */,
      22,    0,  502,    2, 0x08,   20 /* Private */,
      23,    0,  503,    2, 0x08,   21 /* Private */,
      24,    0,  504,    2, 0x08,   22 /* Private */,
      25,    0,  505,    2, 0x08,   23 /* Private */,
      26,    0,  506,    2, 0x08,   24 /* Private */,
      27,    1,  507,    2, 0x08,   25 /* Private */,
      29,    2,  510,    2, 0x08,   27 /* Private */,
      32,    0,  515,    2, 0x08,   30 /* Private */,
      33,    2,  516,    2, 0x08,   31 /* Private */,
      34,    0,  521,    2, 0x08,   34 /* Private */,
      35,    0,  522,    2, 0x08,   35 /* Private */,
      36,    0,  523,    2, 0x08,   36 /* Private */,
      37,    0,  524,    2, 0x08,   37 /* Private */,
      38,    0,  525,    2, 0x08,   38 /* Private */,
      39,    0,  526,    2, 0x08,   39 /* Private */,
      40,    0,  527,    2, 0x08,   40 /* Private */,
      41,    0,  528,    2, 0x08,   41 /* Private */,
      42,    0,  529,    2, 0x08,   42 /* Private */,
      43,    0,  530,    2, 0x08,   43 /* Private */,
      44,    0,  531,    2, 0x08,   44 /* Private */,
      45,    0,  532,    2, 0x08,   45 /* Private */,
      46,    0,  533,    2, 0x08,   46 /* Private */,
      47,    0,  534,    2, 0x08,   47 /* Private */,
      48,    1,  535,    2, 0x08,   48 /* Private */,
      51,    0,  538,    2, 0x08,   50 /* Private */,
      52,    0,  539,    2, 0x08,   51 /* Private */,
      53,    0,  540,    2, 0x08,   52 /* Private */,
      54,    0,  541,    2, 0x08,   53 /* Private */,
      55,    0,  542,    2, 0x08,   54 /* Private */,
      56,    0,  543,    2, 0x08,   55 /* Private */,
      57,    0,  544,    2, 0x08,   56 /* Private */,
      58,    0,  545,    2, 0x08,   57 /* Private */,
      59,    0,  546,    2, 0x08,   58 /* Private */,
      60,    0,  547,    2, 0x08,   59 /* Private */,
      61,    0,  548,    2, 0x08,   60 /* Private */,
      62,    0,  549,    2, 0x08,   61 /* Private */,
      63,    0,  550,    2, 0x08,   62 /* Private */,
      64,    0,  551,    2, 0x08,   63 /* Private */,
      65,    1,  552,    2, 0x08,   64 /* Private */,
      67,    0,  555,    2, 0x08,   66 /* Private */,
      68,    0,  556,    2, 0x08,   67 /* Private */,
      69,    0,  557,    2, 0x08,   68 /* Private */,
      70,    0,  558,    2, 0x08,   69 /* Private */,
      71,    0,  559,    2, 0x08,   70 /* Private */,
      72,    0,  560,    2, 0x08,   71 /* Private */,
      73,    0,  561,    2, 0x08,   72 /* Private */,
      74,    0,  562,    2, 0x08,   73 /* Private */,
      75,    0,  563,    2, 0x08,   74 /* Private */,
      76,    0,  564,    2, 0x08,   75 /* Private */,
      77,    0,  565,    2, 0x08,   76 /* Private */,
      78,    0,  566,    2, 0x08,   77 /* Private */,
      79,    0,  567,    2, 0x08,   78 /* Private */,
      80,    0,  568,    2, 0x08,   79 /* Private */,
      81,    0,  569,    2, 0x08,   80 /* Private */,
      82,    0,  570,    2, 0x08,   81 /* Private */,
      83,    0,  571,    2, 0x08,   82 /* Private */,
      84,    0,  572,    2, 0x08,   83 /* Private */,
      85,    0,  573,    2, 0x08,   84 /* Private */,
      86,    0,  574,    2, 0x08,   85 /* Private */,
      87,    1,  575,    2, 0x08,   86 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   30,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   30,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 49,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   66,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   88,

       0        // eod
};

void management::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<management *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_employees_clicked(); break;
        case 1: _t->on_deliveries_clicked(); break;
        case 2: _t->on_machines_clicked(); break;
        case 3: _t->on_logout_clicked(); break;
        case 4: _t->on_add_employee_btn_clicked(); break;
        case 5: _t->on_add_back_clicked(); break;
        case 6: _t->on_update_back_clicked(); break;
        case 7: _t->on_history_back_clicked(); break;
        case 8: _t->on_confirm_employee_btn_clicked(); break;
        case 9: _t->on_update_employee_btn_clicked(); break;
        case 10: _t->on_confirm_update_btn_clicked(); break;
        case 11: _t->on_delete_employee_btn_clicked(); break;
        case 12: _t->on_searchConfirm(); break;
        case 13: _t->on_searchReset_clicked(); break;
        case 14: _t->onTableItemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 15: _t->on_employee_export_clicked(); break;
        case 16: _t->updateProgressBars(); break;
        case 17: _t->on_pushButton_3_clicked(); break;
        case 18: _t->on_pushButton_10_clicked(); break;
        case 19: _t->on_edit_table_button_clicked(); break;
        case 20: _t->on_button_delete_clicked(); break;
        case 21: _t->on_return_main_clicked(); break;
        case 22: _t->on_export_table_clicked(); break;
        case 23: _t->filterTableByDeliveryId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->on_tableWidget_cellDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 25: _t->on_pushButton_2_clicked(); break;
        case 26: _t->onTableWidgetRowSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 27: _t->on_back_qrcode_ordered_clicked(); break;
        case 28: _t->on_back_qrcode_in_progress_clicked(); break;
        case 29: _t->on_back_qrcode_delivered_clicked(); break;
        case 30: _t->on_statsbutton_clicked(); break;
        case 31: _t->on_ajouter_clicked(); break;
        case 32: _t->on_delete_2_clicked(); break;
        case 33: _t->on_pushButton_22_clicked(); break;
        case 34: _t->on_pushButton_23_clicked(); break;
        case 35: _t->on_pushButton_11_clicked(); break;
        case 36: _t->on_pushButton_12_clicked(); break;
        case 37: _t->on_pushButton_13_clicked(); break;
        case 38: _t->on_pushButton_7_clicked(); break;
        case 39: _t->on_pushButton_16_clicked(); break;
        case 40: _t->on_pushButton_25_clicked(); break;
        case 41: _t->on_tableView_4_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 42: _t->on_pushButton_24_clicked(); break;
        case 43: _t->on_filterButton_clickedF(); break;
        case 44: _t->on_add_clickedF(); break;
        case 45: _t->on_annuler_clickedF(); break;
        case 46: _t->on_ajout_cl_clickedF(); break;
        case 47: _t->on_sup_clickedF(); break;
        case 48: _t->on_delete_2_clickedF(); break;
        case 49: _t->on_cancel_clickedF(); break;
        case 50: _t->on_cancl_clickedF(); break;
        case 51: _t->on_ajout_cl_2_clickedF(); break;
        case 52: _t->on_update_clickedF(); break;
        case 53: _t->on_update_2_clickedF(); break;
        case 54: _t->on_annuler_2_clickedF(); break;
        case 55: _t->on_statisticButton_clickedF(); break;
        case 56: _t->updateProgressBarF((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 57: _t->on_pdfButton_clickedF(); break;
        case 58: _t->updateFactoryCountF(); break;
        case 59: _t->on_generateQRButton_clickedF(); break;
        case 60: _t->on_displayQRButton_clickedF(); break;
        case 61: _t->on_factories_clicked(); break;
        case 62: _t->on_add_clicked(); break;
        case 63: _t->on_ajout_cl_clicked(); break;
        case 64: _t->on_cancel_clicked(); break;
        case 65: _t->on_update_clicked(); break;
        case 66: _t->on_update_2_clicked(); break;
        case 67: _t->on_pdf_clicked(); break;
        case 68: _t->on_trier_clicked(); break;
        case 69: _t->statistique(); break;
        case 70: _t->on_pushButton_6_clicked(); break;
        case 71: _t->on_selectid_clicked(); break;
        case 72: _t->on_send_clicked(); break;
        case 73: _t->update_label(); break;
        case 74: _t->on_dahsboard_clicked(); break;
        case 75: _t->on_searchReset_2_clicked(); break;
        case 76: _t->on_searchConfirm2(); break;
        case 77: _t->on_search_field_2_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject management::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_management.offsetsAndSize,
    qt_meta_data_management,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_management_t
, QtPrivate::TypeAndForceComplete<management, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *management::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *management::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_management.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int management::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 78)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 78;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 78)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 78;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
