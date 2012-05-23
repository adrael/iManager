/****************************************************************************
** Meta object code from reading C++ file 'menubar.hpp'
**
** Created: Sat 21. Apr 20:04:32 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/menubar.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menubar.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MenuBar[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      28,    8,    8,    8, 0x05,
      44,    8,    8,    8, 0x05,
      63,    8,    8,    8, 0x05,
      79,    8,    8,    8, 0x05,
      98,    8,    8,    8, 0x05,
     112,    8,    8,    8, 0x05,
     128,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     146,    8,    8,    8, 0x08,
     155,    8,    8,    8, 0x08,
     170,    8,    8,    8, 0x08,
     182,    8,    8,    8, 0x08,
     197,    8,    8,    8, 0x08,
     212,    8,    8,    8, 0x08,
     224,    8,    8,    8, 0x08,
     234,    8,    8,    8, 0x08,
     246,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MenuBar[] = {
    "MenuBar\0\0calendarDatabase()\0callsDatabase()\0"
    "contactsDatabase()\0notesDatabase()\0"
    "picturesDatabase()\0smsDatabase()\0"
    "vaultDatabase()\0importDatabases()\0"
    "import()\0openContacts()\0openCalls()\0"
    "openCalendar()\0openPictures()\0openNotes()\0"
    "openSMS()\0openVault()\0about()\0"
};

const QMetaObject MenuBar::staticMetaObject = {
    { &QMenuBar::staticMetaObject, qt_meta_stringdata_MenuBar,
      qt_meta_data_MenuBar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MenuBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MenuBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MenuBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuBar))
        return static_cast<void*>(const_cast< MenuBar*>(this));
    return QMenuBar::qt_metacast(_clname);
}

int MenuBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: calendarDatabase(); break;
        case 1: callsDatabase(); break;
        case 2: contactsDatabase(); break;
        case 3: notesDatabase(); break;
        case 4: picturesDatabase(); break;
        case 5: smsDatabase(); break;
        case 6: vaultDatabase(); break;
        case 7: importDatabases(); break;
        case 8: import(); break;
        case 9: openContacts(); break;
        case 10: openCalls(); break;
        case 11: openCalendar(); break;
        case 12: openPictures(); break;
        case 13: openNotes(); break;
        case 14: openSMS(); break;
        case 15: openVault(); break;
        case 16: about(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MenuBar::calendarDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MenuBar::callsDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MenuBar::contactsDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MenuBar::notesDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MenuBar::picturesDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MenuBar::smsDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MenuBar::vaultDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MenuBar::importDatabases()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
