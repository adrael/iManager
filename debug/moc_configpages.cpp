/****************************************************************************
** Meta object code from reading C++ file 'configpages.hpp'
**
** Created: Sat 21. Apr 20:04:34 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/configpages.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configpages.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigBar[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfigBar[] = {
    "ConfigBar\0\0text\0updateCloseButton(QString)\0"
};

const QMetaObject ConfigBar::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_ConfigBar,
      qt_meta_data_ConfigBar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfigBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfigBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfigBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigBar))
        return static_cast<void*>(const_cast< ConfigBar*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int ConfigBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateCloseButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_GlobalPage[] = {

 // content:
       5,       // revision
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

static const char qt_meta_stringdata_GlobalPage[] = {
    "GlobalPage\0"
};

const QMetaObject GlobalPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GlobalPage,
      qt_meta_data_GlobalPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlobalPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlobalPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlobalPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlobalPage))
        return static_cast<void*>(const_cast< GlobalPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int GlobalPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SMSPage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      19,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SMSPage[] = {
    "SMSPage\0\0getPath()\0getColor()\0"
};

const QMetaObject SMSPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SMSPage,
      qt_meta_data_SMSPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SMSPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SMSPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SMSPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SMSPage))
        return static_cast<void*>(const_cast< SMSPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int SMSPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getPath(); break;
        case 1: getColor(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_ContactsPage[] = {

 // content:
       5,       // revision
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

static const char qt_meta_stringdata_ContactsPage[] = {
    "ContactsPage\0"
};

const QMetaObject ContactsPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ContactsPage,
      qt_meta_data_ContactsPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContactsPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContactsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContactsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContactsPage))
        return static_cast<void*>(const_cast< ContactsPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int ContactsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_PicturesPage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PicturesPage[] = {
    "PicturesPage\0\0getColor()\0"
};

const QMetaObject PicturesPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PicturesPage,
      qt_meta_data_PicturesPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PicturesPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PicturesPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PicturesPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PicturesPage))
        return static_cast<void*>(const_cast< PicturesPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int PicturesPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getColor(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_ThemePage[] = {

 // content:
       5,       // revision
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

static const char qt_meta_stringdata_ThemePage[] = {
    "ThemePage\0"
};

const QMetaObject ThemePage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ThemePage,
      qt_meta_data_ThemePage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThemePage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThemePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThemePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThemePage))
        return static_cast<void*>(const_cast< ThemePage*>(this));
    return QWidget::qt_metacast(_clname);
}

int ThemePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
