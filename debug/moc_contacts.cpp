/****************************************************************************
** Meta object code from reading C++ file 'contacts.hpp'
**
** Created: Sat 21. Apr 20:04:13 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/contacts.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contacts.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CONTACTS[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      31,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,    9,    9,    9, 0x0a,
      75,    9,    9,    9, 0x2a,
      98,   94,    9,    9, 0x08,
     115,    9,    9,    9, 0x08,
     136,  131,    9,    9, 0x08,
     164,  158,    9,    9, 0x08,
     203,  198,    9,    9, 0x28,
     233,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CONTACTS[] = {
    "CONTACTS\0\0linkClicked(QString)\0"
    "conversation(QString)\0loadContactsData(int)\0"
    "loadContactsData()\0url\0emitSignal(QUrl)\0"
    "updateOptions()\0name\0findContacts(QString)\0"
    "item,\0showContact(QTreeWidgetItem*,int)\0"
    "item\0showContact(QTreeWidgetItem*)\0"
    "change()\0"
};

const QMetaObject CONTACTS::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CONTACTS,
      qt_meta_data_CONTACTS, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CONTACTS::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CONTACTS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CONTACTS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CONTACTS))
        return static_cast<void*>(const_cast< CONTACTS*>(this));
    return QWidget::qt_metacast(_clname);
}

int CONTACTS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: linkClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: conversation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: loadContactsData((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: loadContactsData(); break;
        case 4: emitSignal((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 5: updateOptions(); break;
        case 6: findContacts((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: showContact((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 8: showContact((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 9: change(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CONTACTS::linkClicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CONTACTS::conversation(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
