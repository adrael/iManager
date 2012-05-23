/****************************************************************************
*  Copyright (C) 2011 Raphaël MARQUES <work.rmarques@gmail.com>
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

/** --------------------------------------------------------------------------------------------------------------- **/

#ifndef IPHONE_MANAGER5
#define IPHONE_MANAGER5

/** --------------------------------------------------------------------------------------------------------------- **/

#include <qprogressdialog.h>
#include <qdesktopwidget.h>
#include <qsplashscreen.h>
#include <qapplication.h>
#include <qmainwindow.h>
#include <qtimer.h>
#include <qdir.h>

#include <qwindowsvistastyle.h>
#include <qcleanlooksstyle.h>
#include <qplastiquestyle.h>
#include <qwindowsxpstyle.h>
#include <qstylefactory.h>
#include <qwindowsstyle.h>
#include <qmotifstyle.h>
#include <qcdestyle.h>

/** --------------------------------------------------------------------------------------------------------------- **/

#include "sms.hpp"
#include "calls.hpp"
#include "notes.hpp"
#include "vault.hpp"
#include "options.hpp"
#include "menubar.hpp"
#include "calendar.hpp"
#include "pictures.hpp"
#include "contacts.hpp"
#include "statusbar.hpp"
#include "configdialog.hpp"

/** --------------------------------------------------------------------------------------------------------------- **/

class Manager : public QMainWindow {

    Q_OBJECT

public:

    // REMPLACER PARTOUT appPath par QCoreApplication::applicationPath()
    Manager(const QString & path = "", const QString & appName = "", const QString & orgName = "", QWidget * parent = 0)  :

        QMainWindow(parent),
        globalWidget(new QTabWidget(this)),
        appPath(path),
        tmpDirectory(this -> appPath + "/utils/tmp"),
        defaultStyle(qApp -> style() -> objectName()),
        DBManager(new database(this, this -> appPath)),
        appOptions(new Options(this)),
        configDialog(new ConfigDialog(this, this -> appPath, appName, orgName, this -> appOptions)),
        mB(new MenuBar(this -> menuBar(), configDialog, this -> appPath)),
        sB(new StatusBar(this -> statusBar()))
    {
        QSplashScreen * splash = new QSplashScreen(QPixmap(this -> appPath + "/utils/icons/splash.png"));
        splash -> show();
        splash -> showMessage(tr("Initialization") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);

        if(!QDir().exists(this -> tmpDirectory))
            QDir().mkdir(this -> tmpDirectory);

        splash -> showMessage(tr("Creating SMS") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> SMSPAGE      = new SMS(this -> globalWidget, this -> DBManager, this -> appPath, this -> appOptions);
        this -> connect(this -> SMSPAGE, SIGNAL(linkClicked(const QString &)), this, SLOT(sortURL(const QString &)));

        splash -> showMessage(tr("Creating Contacts") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> CONTACTSPAGE = new CONTACTS(this -> globalWidget, this -> DBManager, this -> appPath, this -> appOptions);
        this -> connect(this -> CONTACTSPAGE, SIGNAL(linkClicked(const QString &)), this, SLOT(sortURL(const QString &)));
        this -> connect(this -> CONTACTSPAGE, SIGNAL(conversation(const QString &)), this, SLOT(checkConversation(const QString &)));

        splash -> showMessage(tr("Creating Contacts Pictures") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> PICTURESPAGE = new PICTURES(this -> globalWidget, this -> DBManager, this -> appPath, this -> appOptions);
        this -> connect(this -> PICTURESPAGE, SIGNAL(contactClicked(const QString &)), this, SLOT(sortURL(const QString &)));

        splash -> showMessage(tr("Creating Calls") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> CALLSPAGE    = new CALLS(this -> globalWidget);

        splash -> showMessage(tr("Creating Notes") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> NOTESPAGE    = new NOTES(this -> globalWidget);

        splash -> showMessage(tr("Creating Calendar") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> CALENDARPAGE = new CALENDAR(this -> globalWidget);

        splash -> showMessage(tr("Creating Vault") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> VAULTPAGE    = new VAULT(this -> globalWidget);

        // --------------------------------------------------------------------------------------------------------

        splash -> showMessage(tr("Setting SMS") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> globalWidget -> addTab(this -> SMSPAGE,      QIcon(this -> appPath + "/utils/icons/sms.png"),      tr("SMS"));

        splash -> showMessage(tr("Setting Contacts") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> globalWidget -> addTab(this -> CONTACTSPAGE, QIcon(this -> appPath + "/utils/icons/contacts.png"), tr("Contacts"));

        splash -> showMessage(tr("Setting Contacts Pictures") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> globalWidget -> addTab(this -> PICTURESPAGE, QIcon(this -> appPath + "/utils/icons/pictures.png"), tr("Pictures"));

        splash -> showMessage(tr("Setting Calls") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> globalWidget -> addTab(this -> CALLSPAGE,    QIcon(this -> appPath + "/utils/icons/calls.png"),    tr("Calls"));

        splash -> showMessage(tr("Setting Notes") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> globalWidget -> addTab(this -> NOTESPAGE,    QIcon(this -> appPath + "/utils/icons/notes.png"),    tr("Notes"));

        splash -> showMessage(tr("Setting Calendar") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> globalWidget -> addTab(this -> CALENDARPAGE, QIcon(this -> appPath + "/utils/icons/calendar.png"), tr("Calendar"));

        splash -> showMessage(tr("Setting Vault") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
        this -> globalWidget -> addTab(this -> VAULTPAGE,    QIcon(this -> appPath + "/utils/icons/vault.png"),    tr("Vault"));

        splash -> showMessage(tr("Finalizing") + " ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);

        this -> connect(this -> globalWidget, SIGNAL(currentChanged(int)), this -> sB, SLOT(update(int)));

        this -> connect(this -> mB, SIGNAL(contactsDatabase()), this -> DBManager, SLOT(openContactsDatabase()));
        this -> connect(this -> mB, SIGNAL(calendarDatabase()), this -> DBManager, SLOT(openCalendarDatabase()));
        this -> connect(this -> mB, SIGNAL(callsDatabase()),    this -> DBManager, SLOT(openCallsDatabase()));
        this -> connect(this -> mB, SIGNAL(notesDatabase()),    this -> DBManager, SLOT(openNotesDatabase()));
        this -> connect(this -> mB, SIGNAL(picturesDatabase()), this -> DBManager, SLOT(openPicturesDatabase()));
        this -> connect(this -> mB, SIGNAL(smsDatabase()),      this -> DBManager, SLOT(openSmsDatabase()));
        this -> connect(this -> mB, SIGNAL(vaultDatabase()),    this -> DBManager, SLOT(openVaultDatabase()));
        this -> connect(this -> mB, SIGNAL(importDatabases()),  this,              SLOT(loadGlobalData()));

        this -> connect(this -> configDialog, SIGNAL(optionsChanged()), this,                 SLOT(updateOptions()));
        this -> connect(this -> configDialog, SIGNAL(optionsChanged()), this -> SMSPAGE,      SLOT(updateOptions()));
        this -> connect(this -> configDialog, SIGNAL(optionsChanged()), this -> CONTACTSPAGE, SLOT(updateOptions()));
        this -> connect(this -> configDialog, SIGNAL(optionsChanged()), this -> PICTURESPAGE, SLOT(updateOptions()));

        this -> setCentralWidget(this -> globalWidget);
        this -> setContentsMargins(0, 0, 0, 0);
        this -> setContextMenuPolicy(Qt::ActionsContextMenu);
        this -> centerApp();
        this -> updateOptions();

        if(this -> appOptions -> loadiTunes)
            QTimer::singleShot(1000, this, SLOT(loadGlobalData()));

        splash -> close();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    ~Manager() {
        delete this -> DBManager;
        this -> removeDir(this -> tmpDirectory);
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

private slots:

    void updateOptions() {
        qApp -> setStyleSheet("");
        qApp -> setStyle(QStyleFactory::create(defaultStyle));
        if(this -> appOptions -> title      == "CDE")
            qApp -> setStyle(new QCDEStyle());
        else if(this -> appOptions -> title == "Cleanlooks")
            qApp -> setStyle(new QCleanlooksStyle());
        else if(this -> appOptions -> title == "Motif")
            qApp -> setStyle(new QMotifStyle());
        else if(this -> appOptions -> title == "Plastic")
            qApp -> setStyle(new QPlastiqueStyle());
        else if(this -> appOptions -> title == "Windows")
            qApp -> setStyle(new QWindowsStyle());
        else if(this -> appOptions -> title == "Windows Vista/7")
            qApp -> setStyle(new QWindowsVistaStyle());
        else if(this -> appOptions -> title == "WindowsXP")
            qApp -> setStyle(new QWindowsXPStyle());
        else if(this -> appOptions -> title == "Darkness")
            qApp -> setStyleSheet(this -> appOptions -> QSS);
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void loadGlobalData() {
        int dbCount(this -> DBManager -> countDatabases() + 1);
        QProgressDialog progress(tr("Searching..."), tr("Cancel"), 0, dbCount, this);
        progress.setWindowModality(Qt::WindowModal);
        progress.setWindowTitle(tr("Loading data..."));
        progress.setCancelButton(NULL);

        for (int i(0); i < dbCount; ++i) {
            progress.setValue(i);
            if (progress.wasCanceled())
                break;

            switch(i) {
            case 0:
                progress.setLabelText(tr("Loading databases..."));
                this -> DBManager -> importDatabases("3G"); // this -> appOptions -> iPhoneVersion;
                this -> DBManager -> openDatabases();
                this -> DBManager -> loadBook();
                break;
            case 1:
                progress.setLabelText(tr("Loading SMS data..."));
                this -> SMSPAGE   -> loadSMSData();
                break;
            case 2:
                progress.setLabelText(tr("Loading Contacts data..."));
                this -> CONTACTSPAGE -> loadContactsData();
                break;
            case 3:
                progress.setLabelText(tr("Loading Contacts Pictures data..."));
                this -> PICTURESPAGE -> loadPicturesData();
                break;
            case 4:
                progress.setLabelText(tr("Loading Notes data..."));
                break;
            case 5:
                progress.setLabelText(tr("Loading Calls data..."));
                break;
            case 6:
                progress.setLabelText(tr("Loading Calendar data..."));
                break;
            }
        }

        progress.setLabelText(tr("Done !"));
        progress.setValue(dbCount);
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void sortURL(const QString & url) {
        if(url.right(5) == "#foot")
            this -> SMSPAGE -> setMaxScrollWebView();
        else if(url.right(4) == "#top")
            this -> SMSPAGE -> setMinScrollWebView();
        else {
            QStringList splitURL(url.split('/', QString::KeepEmptyParts, Qt::CaseInsensitive));
            if(splitURL.last() != "-1") {
                if(splitURL.at(splitURL.size() - 2) == "pic") {
                    this -> PICTURESPAGE -> whoIs(splitURL.last());
                    this -> globalWidget -> setCurrentIndex(2);
                } else if(splitURL.at(splitURL.size() - 2) == "contacts") {
                    this -> CONTACTSPAGE -> whoIs(splitURL.last());
                    this -> globalWidget -> setCurrentIndex(1);
                } else if(splitURL.at(splitURL.size() - 2) == "sms") {
                    this -> SMSPAGE -> findContact(splitURL.last());
                    this -> globalWidget -> setCurrentIndex(0);
                }
            }
        }
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void checkConversation(const QString & ID) {
        this -> CONTACTSPAGE -> displayIcon(this -> SMSPAGE -> isSMS(ID));
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

private:

    bool removeDir(const QString & dirName) {
        this -> cleanDir(dirName);
        return QDir().rmdir(dirName);
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    bool cleanDir(const QString & dirName) {
        QDir folder(dirName);
        folder.setFilter(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files);
        foreach(QFileInfo fileInfo, folder.entryInfoList()) {
            if(fileInfo.isDir()) {
                if(!removeDir(fileInfo.filePath()))
                    return false;
            } else if(fileInfo.isFile()) {
                if(!QFile::remove(fileInfo.filePath())) {
                    qDebug() << tr("Unable to remove file") + " : " << fileInfo.filePath();
                    return false;
                }
            }
        }
        return true;
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void centerApp() {
        int w(QApplication::desktop() -> screenGeometry().width()), h(QApplication::desktop() -> screenGeometry().height());
        this -> move((w / 2) - 670 / 2, (h / 2) - 540 / 2);
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

protected:

    void closeEvent(QCloseEvent * event)
    {
        //        this -> configDialog -> saveOptions();
        event -> accept();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    QTabWidget * globalWidget;
    QString appPath, tmpDirectory, defaultStyle;

    database * DBManager;
    Options * appOptions;
    ConfigDialog * configDialog;
    MenuBar * mB;
    StatusBar * sB;

    SMS      * SMSPAGE;
    CONTACTS * CONTACTSPAGE;
    CALLS    * CALLSPAGE;
    NOTES    * NOTESPAGE;
    CALENDAR * CALENDARPAGE;
    PICTURES * PICTURESPAGE;
    VAULT    * VAULTPAGE;
};

/** --------------------------------------------------------------------------------------------------------------- **/

#endif // IPHONE_MANAGER5

/** --------------------------------------------------------------------------------------------------------------- **/

