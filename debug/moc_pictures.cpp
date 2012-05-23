/****************************************************************************
** Meta object code from reading C++ file 'pictures.hpp'
**
** Created: Sat 21. Apr 20:04:20 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/pictures.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pictures.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PICTURES[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,    9,    9,    9, 0x0a,
      56,    9,    9,    9, 0x2a,
      81,   75,    9,    9, 0x08,
     120,  115,    9,    9, 0x28,
     150,    9,    9,    9, 0x08,
     166,    9,    9,    9, 0x08,
     175,    9,    9,    9, 0x08,
     186,    9,    9,    9, 0x08,
     201,  196,    9,    9, 0x08,
     223,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PICTURES[] = {
    "PICTURES\0\0contactClicked(QString)\0"
    "loadPicturesData(int)\0loadPicturesData()\0"
    "item,\0showPicture(QTreeWidgetItem*,int)\0"
    "item\0showPicture(QTreeWidgetItem*)\0"
    "updateOptions()\0change()\0fullSize()\0"
    "savePic()\0name\0findPictures(QString)\0"
    "viewContactFnc()\0"
};

const QMetaObject PICTURES::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PICTURES,
      qt_meta_data_PICTURES, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PICTURES::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PICTURES::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PICTURES::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PICTURES))
        return static_cast<void*>(const_cast< PICTURES*>(this));
    return QWidget::qt_metacast(_clname);
}

int PICTURES::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: contactClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: loadPicturesData((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: loadPicturesData(); break;
        case 3: showPicture((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: showPicture((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 5: updateOptions(); break;
        case 6: change(); break;
        case 7: fullSize(); break;
        case 8: savePic(); break;
        case 9: findPictures((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: viewContactFnc(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PICTURES::contactClicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
