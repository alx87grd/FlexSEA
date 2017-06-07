/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../plan-gui/inc/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[81];
    char stringdata0[1702];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_openComButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16), // "timerStreamEvent"
QT_MOC_LITERAL(4, 54, 14), // "timerPlotEvent"
QT_MOC_LITERAL(5, 69, 14), // "timerCtrlEvent"
QT_MOC_LITERAL(6, 84, 30), // "on_updateRefreshButton_clicked"
QT_MOC_LITERAL(7, 115, 31), // "on_UpdatePlotpushButton_clicked"
QT_MOC_LITERAL(8, 147, 25), // "on_closeComButton_clicked"
QT_MOC_LITERAL(9, 173, 35), // "on_pushButton_SetController_c..."
QT_MOC_LITERAL(10, 209, 31), // "on_pushButton_setp_a_go_clicked"
QT_MOC_LITERAL(11, 241, 31), // "on_pushButton_setp_b_go_clicked"
QT_MOC_LITERAL(12, 273, 30), // "on_pushButton_SetGains_clicked"
QT_MOC_LITERAL(13, 304, 32), // "on_pushButton_CtrlMinMax_clicked"
QT_MOC_LITERAL(14, 337, 28), // "on_hSlider_Ctrl_valueChanged"
QT_MOC_LITERAL(15, 366, 5), // "value"
QT_MOC_LITERAL(16, 372, 28), // "on_pushButton_toggle_clicked"
QT_MOC_LITERAL(17, 401, 30), // "on_pushButton_ext_pwro_clicked"
QT_MOC_LITERAL(18, 432, 42), // "on_SlaveSelectComboBox_curren..."
QT_MOC_LITERAL(19, 475, 5), // "index"
QT_MOC_LITERAL(20, 481, 34), // "on_stream_SA_RefreshOffset_cl..."
QT_MOC_LITERAL(21, 516, 40), // "on_comboBox_minm_rgb_currentI..."
QT_MOC_LITERAL(22, 557, 41), // "on_comboBox_ctrl_list_current..."
QT_MOC_LITERAL(23, 599, 27), // "on_quadrature_write_clicked"
QT_MOC_LITERAL(24, 627, 14), // "stream_execute"
QT_MOC_LITERAL(25, 642, 17), // "stream_strain_amp"
QT_MOC_LITERAL(26, 660, 17), // "stream_ricnu_knee"
QT_MOC_LITERAL(27, 678, 11), // "stream_ctrl"
QT_MOC_LITERAL(28, 690, 14), // "stream_in_ctrl"
QT_MOC_LITERAL(29, 705, 17), // "stream_ankle_2dof"
QT_MOC_LITERAL(30, 723, 43), // "on_StreamSelectComboBox_curre..."
QT_MOC_LITERAL(31, 767, 33), // "on_streamON_master_button_cli..."
QT_MOC_LITERAL(32, 801, 34), // "on_streamOFF_master_button_cl..."
QT_MOC_LITERAL(33, 836, 30), // "on_logON_master_button_clicked"
QT_MOC_LITERAL(34, 867, 31), // "on_logOFF_master_button_clicked"
QT_MOC_LITERAL(35, 899, 15), // "init_tab_config"
QT_MOC_LITERAL(36, 915, 14), // "init_tab_about"
QT_MOC_LITERAL(37, 930, 15), // "init_tab_plot_1"
QT_MOC_LITERAL(38, 946, 13), // "init_tab_ctrl"
QT_MOC_LITERAL(39, 960, 12), // "init_tab_exp"
QT_MOC_LITERAL(40, 973, 12), // "init_tab_ext"
QT_MOC_LITERAL(41, 986, 23), // "init_tab_stream_in_ctrl"
QT_MOC_LITERAL(42, 1010, 23), // "init_tab_stream_execute"
QT_MOC_LITERAL(43, 1034, 22), // "init_tab_stream_strain"
QT_MOC_LITERAL(44, 1057, 26), // "init_tab_stream_ricnu_knee"
QT_MOC_LITERAL(45, 1084, 26), // "init_tab_stream_ankle_2dof"
QT_MOC_LITERAL(46, 1111, 15), // "control_trapeze"
QT_MOC_LITERAL(47, 1127, 18), // "stream_status_disp"
QT_MOC_LITERAL(48, 1146, 6), // "status"
QT_MOC_LITERAL(49, 1153, 16), // "status_byte_disp"
QT_MOC_LITERAL(50, 1170, 7), // "uint8_t"
QT_MOC_LITERAL(51, 1178, 5), // "stat1"
QT_MOC_LITERAL(52, 1184, 5), // "stat2"
QT_MOC_LITERAL(53, 1190, 8), // "slave_ab"
QT_MOC_LITERAL(54, 1199, 31), // "on_pushButton_inctrl_w0_clicked"
QT_MOC_LITERAL(55, 1231, 31), // "on_pushButton_inctrl_w1_clicked"
QT_MOC_LITERAL(56, 1263, 31), // "on_pushButton_inctrl_w2_clicked"
QT_MOC_LITERAL(57, 1295, 31), // "on_pushButton_inctrl_w3_clicked"
QT_MOC_LITERAL(58, 1327, 18), // "write_in_control_w"
QT_MOC_LITERAL(59, 1346, 3), // "var"
QT_MOC_LITERAL(60, 1350, 12), // "disp_slave_a"
QT_MOC_LITERAL(61, 1363, 6), // "enable"
QT_MOC_LITERAL(62, 1370, 12), // "disp_slave_b"
QT_MOC_LITERAL(63, 1383, 12), // "disp_execute"
QT_MOC_LITERAL(64, 1396, 10), // "execute_s*"
QT_MOC_LITERAL(65, 1407, 2), // "ex"
QT_MOC_LITERAL(66, 1410, 18), // "assign_execute_ptr"
QT_MOC_LITERAL(67, 1429, 11), // "execute_s**"
QT_MOC_LITERAL(68, 1441, 6), // "ex_ptr"
QT_MOC_LITERAL(69, 1448, 5), // "slave"
QT_MOC_LITERAL(70, 1454, 15), // "init_datalogger"
QT_MOC_LITERAL(71, 1470, 13), // "timerLogEvent"
QT_MOC_LITERAL(72, 1484, 11), // "log_execute"
QT_MOC_LITERAL(73, 1496, 17), // "select_plot_slave"
QT_MOC_LITERAL(74, 1514, 30), // "on_pushButton_a2dof_w0_clicked"
QT_MOC_LITERAL(75, 1545, 30), // "on_pushButton_a2dof_w1_clicked"
QT_MOC_LITERAL(76, 1576, 30), // "on_pushButton_a2dof_w2_clicked"
QT_MOC_LITERAL(77, 1607, 30), // "on_pushButton_a2dof_w3_clicked"
QT_MOC_LITERAL(78, 1638, 35), // "on_pushButton_a2dof_refresh_c..."
QT_MOC_LITERAL(79, 1674, 21), // "a2dof_write_user_data"
QT_MOC_LITERAL(80, 1696, 5) // "sel_w"

    },
    "MainWindow\0on_openComButton_clicked\0"
    "\0timerStreamEvent\0timerPlotEvent\0"
    "timerCtrlEvent\0on_updateRefreshButton_clicked\0"
    "on_UpdatePlotpushButton_clicked\0"
    "on_closeComButton_clicked\0"
    "on_pushButton_SetController_clicked\0"
    "on_pushButton_setp_a_go_clicked\0"
    "on_pushButton_setp_b_go_clicked\0"
    "on_pushButton_SetGains_clicked\0"
    "on_pushButton_CtrlMinMax_clicked\0"
    "on_hSlider_Ctrl_valueChanged\0value\0"
    "on_pushButton_toggle_clicked\0"
    "on_pushButton_ext_pwro_clicked\0"
    "on_SlaveSelectComboBox_currentIndexChanged\0"
    "index\0on_stream_SA_RefreshOffset_clicked\0"
    "on_comboBox_minm_rgb_currentIndexChanged\0"
    "on_comboBox_ctrl_list_currentIndexChanged\0"
    "on_quadrature_write_clicked\0stream_execute\0"
    "stream_strain_amp\0stream_ricnu_knee\0"
    "stream_ctrl\0stream_in_ctrl\0stream_ankle_2dof\0"
    "on_StreamSelectComboBox_currentIndexChanged\0"
    "on_streamON_master_button_clicked\0"
    "on_streamOFF_master_button_clicked\0"
    "on_logON_master_button_clicked\0"
    "on_logOFF_master_button_clicked\0"
    "init_tab_config\0init_tab_about\0"
    "init_tab_plot_1\0init_tab_ctrl\0"
    "init_tab_exp\0init_tab_ext\0"
    "init_tab_stream_in_ctrl\0init_tab_stream_execute\0"
    "init_tab_stream_strain\0"
    "init_tab_stream_ricnu_knee\0"
    "init_tab_stream_ankle_2dof\0control_trapeze\0"
    "stream_status_disp\0status\0status_byte_disp\0"
    "uint8_t\0stat1\0stat2\0slave_ab\0"
    "on_pushButton_inctrl_w0_clicked\0"
    "on_pushButton_inctrl_w1_clicked\0"
    "on_pushButton_inctrl_w2_clicked\0"
    "on_pushButton_inctrl_w3_clicked\0"
    "write_in_control_w\0var\0disp_slave_a\0"
    "enable\0disp_slave_b\0disp_execute\0"
    "execute_s*\0ex\0assign_execute_ptr\0"
    "execute_s**\0ex_ptr\0slave\0init_datalogger\0"
    "timerLogEvent\0log_execute\0select_plot_slave\0"
    "on_pushButton_a2dof_w0_clicked\0"
    "on_pushButton_a2dof_w1_clicked\0"
    "on_pushButton_a2dof_w2_clicked\0"
    "on_pushButton_a2dof_w3_clicked\0"
    "on_pushButton_a2dof_refresh_clicked\0"
    "a2dof_write_user_data\0sel_w"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      64,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  334,    2, 0x08 /* Private */,
       3,    0,  335,    2, 0x08 /* Private */,
       4,    0,  336,    2, 0x08 /* Private */,
       5,    0,  337,    2, 0x08 /* Private */,
       6,    0,  338,    2, 0x08 /* Private */,
       7,    0,  339,    2, 0x08 /* Private */,
       8,    0,  340,    2, 0x08 /* Private */,
       9,    0,  341,    2, 0x08 /* Private */,
      10,    0,  342,    2, 0x08 /* Private */,
      11,    0,  343,    2, 0x08 /* Private */,
      12,    0,  344,    2, 0x08 /* Private */,
      13,    0,  345,    2, 0x08 /* Private */,
      14,    1,  346,    2, 0x08 /* Private */,
      16,    0,  349,    2, 0x08 /* Private */,
      17,    0,  350,    2, 0x08 /* Private */,
      18,    1,  351,    2, 0x08 /* Private */,
      20,    0,  354,    2, 0x08 /* Private */,
      21,    1,  355,    2, 0x08 /* Private */,
      22,    1,  358,    2, 0x08 /* Private */,
      23,    0,  361,    2, 0x08 /* Private */,
      24,    0,  362,    2, 0x08 /* Private */,
      25,    0,  363,    2, 0x08 /* Private */,
      26,    0,  364,    2, 0x08 /* Private */,
      27,    0,  365,    2, 0x08 /* Private */,
      28,    0,  366,    2, 0x08 /* Private */,
      29,    0,  367,    2, 0x08 /* Private */,
      30,    1,  368,    2, 0x08 /* Private */,
      31,    0,  371,    2, 0x08 /* Private */,
      32,    0,  372,    2, 0x08 /* Private */,
      33,    0,  373,    2, 0x08 /* Private */,
      34,    0,  374,    2, 0x08 /* Private */,
      35,    0,  375,    2, 0x08 /* Private */,
      36,    0,  376,    2, 0x08 /* Private */,
      37,    0,  377,    2, 0x08 /* Private */,
      38,    0,  378,    2, 0x08 /* Private */,
      39,    0,  379,    2, 0x08 /* Private */,
      40,    0,  380,    2, 0x08 /* Private */,
      41,    0,  381,    2, 0x08 /* Private */,
      42,    0,  382,    2, 0x08 /* Private */,
      43,    0,  383,    2, 0x08 /* Private */,
      44,    0,  384,    2, 0x08 /* Private */,
      45,    0,  385,    2, 0x08 /* Private */,
      46,    0,  386,    2, 0x08 /* Private */,
      47,    1,  387,    2, 0x08 /* Private */,
      49,    3,  390,    2, 0x08 /* Private */,
      54,    0,  397,    2, 0x08 /* Private */,
      55,    0,  398,    2, 0x08 /* Private */,
      56,    0,  399,    2, 0x08 /* Private */,
      57,    0,  400,    2, 0x08 /* Private */,
      58,    1,  401,    2, 0x08 /* Private */,
      60,    1,  404,    2, 0x08 /* Private */,
      62,    1,  407,    2, 0x08 /* Private */,
      63,    2,  410,    2, 0x08 /* Private */,
      66,    2,  415,    2, 0x08 /* Private */,
      70,    0,  420,    2, 0x08 /* Private */,
      71,    0,  421,    2, 0x08 /* Private */,
      72,    0,  422,    2, 0x08 /* Private */,
      73,    1,  423,    2, 0x08 /* Private */,
      74,    0,  426,    2, 0x08 /* Private */,
      75,    0,  427,    2, 0x08 /* Private */,
      76,    0,  428,    2, 0x08 /* Private */,
      77,    0,  429,    2, 0x08 /* Private */,
      78,    0,  430,    2, 0x08 /* Private */,
      79,    1,  431,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
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
    QMetaType::Void, QMetaType::Int,   48,
    QMetaType::Void, 0x80000000 | 50, 0x80000000 | 50, 0x80000000 | 50,   51,   52,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 50,   59,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void, 0x80000000 | 64, 0x80000000 | 50,   65,   53,
    QMetaType::Void, 0x80000000 | 67, 0x80000000 | 50,   68,   69,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 50, 0x80000000 | 50,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 50,   80,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_openComButton_clicked(); break;
        case 1: _t->timerStreamEvent(); break;
        case 2: _t->timerPlotEvent(); break;
        case 3: _t->timerCtrlEvent(); break;
        case 4: _t->on_updateRefreshButton_clicked(); break;
        case 5: _t->on_UpdatePlotpushButton_clicked(); break;
        case 6: _t->on_closeComButton_clicked(); break;
        case 7: _t->on_pushButton_SetController_clicked(); break;
        case 8: _t->on_pushButton_setp_a_go_clicked(); break;
        case 9: _t->on_pushButton_setp_b_go_clicked(); break;
        case 10: _t->on_pushButton_SetGains_clicked(); break;
        case 11: _t->on_pushButton_CtrlMinMax_clicked(); break;
        case 12: _t->on_hSlider_Ctrl_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_pushButton_toggle_clicked(); break;
        case 14: _t->on_pushButton_ext_pwro_clicked(); break;
        case 15: _t->on_SlaveSelectComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_stream_SA_RefreshOffset_clicked(); break;
        case 17: _t->on_comboBox_minm_rgb_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_comboBox_ctrl_list_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_quadrature_write_clicked(); break;
        case 20: _t->stream_execute(); break;
        case 21: _t->stream_strain_amp(); break;
        case 22: _t->stream_ricnu_knee(); break;
        case 23: _t->stream_ctrl(); break;
        case 24: _t->stream_in_ctrl(); break;
        case 25: _t->stream_ankle_2dof(); break;
        case 26: _t->on_StreamSelectComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_streamON_master_button_clicked(); break;
        case 28: _t->on_streamOFF_master_button_clicked(); break;
        case 29: _t->on_logON_master_button_clicked(); break;
        case 30: _t->on_logOFF_master_button_clicked(); break;
        case 31: _t->init_tab_config(); break;
        case 32: _t->init_tab_about(); break;
        case 33: _t->init_tab_plot_1(); break;
        case 34: _t->init_tab_ctrl(); break;
        case 35: _t->init_tab_exp(); break;
        case 36: _t->init_tab_ext(); break;
        case 37: _t->init_tab_stream_in_ctrl(); break;
        case 38: _t->init_tab_stream_execute(); break;
        case 39: _t->init_tab_stream_strain(); break;
        case 40: _t->init_tab_stream_ricnu_knee(); break;
        case 41: _t->init_tab_stream_ankle_2dof(); break;
        case 42: _t->control_trapeze(); break;
        case 43: _t->stream_status_disp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->status_byte_disp((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2])),(*reinterpret_cast< uint8_t(*)>(_a[3]))); break;
        case 45: _t->on_pushButton_inctrl_w0_clicked(); break;
        case 46: _t->on_pushButton_inctrl_w1_clicked(); break;
        case 47: _t->on_pushButton_inctrl_w2_clicked(); break;
        case 48: _t->on_pushButton_inctrl_w3_clicked(); break;
        case 49: _t->write_in_control_w((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 50: _t->disp_slave_a((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->disp_slave_b((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 52: _t->disp_execute((*reinterpret_cast< execute_s*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 53: _t->assign_execute_ptr((*reinterpret_cast< execute_s**(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 54: _t->init_datalogger(); break;
        case 55: _t->timerLogEvent(); break;
        case 56: _t->log_execute(); break;
        case 57: { uint8_t _r = _t->select_plot_slave((*reinterpret_cast< uint8_t(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint8_t*>(_a[0]) = _r; }  break;
        case 58: _t->on_pushButton_a2dof_w0_clicked(); break;
        case 59: _t->on_pushButton_a2dof_w1_clicked(); break;
        case 60: _t->on_pushButton_a2dof_w2_clicked(); break;
        case 61: _t->on_pushButton_a2dof_w3_clicked(); break;
        case 62: _t->on_pushButton_a2dof_refresh_clicked(); break;
        case 63: _t->a2dof_write_user_data((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 64)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 64;
    }
    return _id;
}
struct qt_meta_stringdata_MainWindowTabWidget_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindowTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindowTabWidget_t qt_meta_stringdata_MainWindowTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 19) // "MainWindowTabWidget"

    },
    "MainWindowTabWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowTabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MainWindowTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MainWindowTabWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_MainWindowTabWidget.data,
      qt_meta_data_MainWindowTabWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindowTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowTabWidget.stringdata0))
        return static_cast<void*>(const_cast< MainWindowTabWidget*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int MainWindowTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
