
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

#ifndef CONFIGDIALOG_HPP
#define CONFIGDIALOG_HPP

/** --------------------------------------------------------------------------------------------------------------- **/

#include <qdebug.h>

#include <qlistwidget.h>
#include <qstackedwidget.h>
#include <qdialog.h>
#include <qsettings.h>

/** --------------------------------------------------------------------------------------------------------------- **/

#include "configpages.hpp"
#include "options.hpp"

/** --------------------------------------------------------------------------------------------------------------- **/

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:

    ConfigDialog(QWidget * parent = 0, const QString & path = "", const QString & appName = "", const QString & orgName = "", Options * opt = 0) : QDialog(parent, Qt::Dialog) {
        this -> appPath = path;
        this -> appOptions = opt;
        this -> globalOptions = new QSettings(orgName, appName, this);
        this -> contentsWidget = new QListWidget();
        this -> contentsWidget -> setViewMode(QListView::IconMode);
        this -> contentsWidget -> setIconSize(QSize(62, 62));
        this -> contentsWidget -> setMovement(QListView::Static);
        this -> contentsWidget -> setFixedSize(113, 380);
        this -> contentsWidget -> setSpacing(12);

        this -> global   = new GlobalPage  (this);
        this -> sms      = new SMSPage     (this, this -> appPath);
        this -> contacts = new ContactsPage(this);
        this -> pictures = new PicturesPage(this, this -> appPath);
        this -> skin     = new ThemePage   (this, this -> appPath);

        this -> pagesWidget = new QStackedWidget();
        this -> pagesWidget -> addWidget(this -> global);
        this -> pagesWidget -> addWidget(this -> sms);
        this -> pagesWidget -> addWidget(this -> contacts);
        this -> pagesWidget -> addWidget(this -> pictures);
        this -> pagesWidget -> addWidget(this -> skin);

        QPushButton * cancelButton = new QPushButton(QIcon(this -> appPath + "/utils/icons/cancel.png"), tr("Cancel"), this);
        this -> connect(cancelButton, SIGNAL(clicked()), this, SLOT(loadOptions()));
        this -> connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

        QPushButton * applyButton = new QPushButton(QIcon(this -> appPath + "/utils/icons/apply.png"), tr("Apply"), this);
        this -> connect(applyButton, SIGNAL(clicked()), this, SLOT(saveOptions()));

        QPushButton * closeButton = new QPushButton(QIcon(this -> appPath + "/utils/icons/quit.png"), tr("Close"), this);
        this -> connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

        QPushButton * restoreButton = new QPushButton(QIcon(this -> appPath + "/utils/icons/restore.png"), tr("Reset"), this);
        this -> connect(restoreButton, SIGNAL(clicked()), this, SLOT(restoreOptions()));

        this -> createIcons();
        this -> contentsWidget -> setCurrentRow(0);

        QHBoxLayout * horizontalLayout = new QHBoxLayout();
        horizontalLayout -> addWidget(this -> contentsWidget);
        horizontalLayout -> addWidget(this -> pagesWidget, 1);

        QHBoxLayout * buttonsLayout = new QHBoxLayout();
        buttonsLayout -> addStretch(1);
        buttonsLayout -> addWidget(applyButton);
        buttonsLayout -> addWidget(cancelButton);
        buttonsLayout -> addWidget(closeButton);
        buttonsLayout -> addWidget(restoreButton);

        QVBoxLayout * mainLayout = new QVBoxLayout();
        mainLayout -> addLayout(horizontalLayout);
        mainLayout -> addStretch(1);
        mainLayout -> addSpacing(12);
        mainLayout -> addLayout(buttonsLayout);

        this -> setLayout(mainLayout);
        this -> setWindowTitle(tr("Parameters"));
        this -> setWindowModality(Qt::WindowModal);
        this -> setWindowIcon(QIcon(this -> appPath + "/utils/icons/tools.png"));
        this -> resize(400, 400);

        this -> loadOptions();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

public slots:

    void saveOptions() {
        this -> setupOptions(this -> skin -> select -> currentText());

        this -> globalOptions -> beginGroup("Manager");
        this -> globalOptions -> setValue("loadiTunes",    this -> global -> apple    -> isChecked());
        this -> globalOptions -> setValue("loadVault",     this -> global -> vault    -> isChecked());
        this -> globalOptions -> setValue("loadNothing",   this -> global -> nada     -> isChecked());
        this -> globalOptions -> setValue("language",      this -> global -> language -> currentIndex());
        this -> globalOptions -> setValue("iPhoneVersion", this -> global -> iphones  -> currentIndex());
        this -> globalOptions -> endGroup();

        this -> globalOptions -> beginGroup("SMS");
        this -> globalOptions -> setValue("BGPath",  this -> sms -> BGWay -> text());
        this -> globalOptions -> setValue("BGColor", this -> sms -> BGC   -> text());
        this -> globalOptions -> endGroup();

        this -> globalOptions -> beginGroup("Contacts");
        this -> globalOptions -> setValue("SearchBar", this -> contacts -> box         -> isChecked());
        this -> globalOptions -> setValue("FirstLast", this -> contacts -> _first_last -> isChecked());
        this -> globalOptions -> endGroup();

        this -> globalOptions -> beginGroup("Pictures");
        this -> globalOptions -> setValue("SearchBar", this -> pictures -> box         -> isChecked());
        this -> globalOptions -> setValue("FirstLast", this -> pictures -> _first_last -> isChecked());
        this -> globalOptions -> setValue("BGColor",   this -> pictures -> BGC         -> text());
        this -> globalOptions -> endGroup();

        this -> globalOptions -> beginGroup("Theme");
        this -> globalOptions -> setValue("Title",  this -> skin -> select -> currentText());
        this -> globalOptions -> setValue("QSS",  this -> skin             -> getStyleSheet());
        this -> globalOptions -> endGroup();

        this -> loadOptions();
        emit this -> optionsChanged();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void loadOptions() {

        ///////////////////////////////////////////////////////////////
        // RETRIEVING DATA
        ///////////////////////////////////////////////////////////////

        this -> globalOptions -> beginGroup("Manager");

        bool    loadiTunes (this -> globalOptions -> value("loadiTunes", false).toBool()),
                loadVault  (this -> globalOptions -> value("loadVault",  false).toBool()),
                loadNothing(this -> globalOptions -> value("loadNothing", true).toBool());

        QString language     (this -> global -> language -> itemText(this -> globalOptions -> value("language",      0).toInt())),
                iPhoneVersion(this -> global -> language -> itemText(this -> globalOptions -> value("iPhoneVersion", 0).toInt()));

        this -> global -> apple    -> setChecked(loadiTunes);
        this -> global -> vault    -> setChecked(loadVault);
        this -> global -> nada     -> setChecked(loadNothing);
        this -> global -> language -> setCurrentIndex(this -> global -> language -> findText(language));
        this -> global -> iphones  -> setCurrentIndex(this -> global -> language -> findText(iPhoneVersion));

        this -> appOptions -> loadiTunes    = loadiTunes;
        this -> appOptions -> loadVault     = loadVault;
        this -> appOptions -> loadNothing   = loadNothing;
        this -> appOptions -> language      = language;
        this -> appOptions -> iPhoneVersion = iPhoneVersion;

        this -> globalOptions -> endGroup();

        ///////////////////////////////////////////////////////////////

        this -> globalOptions -> beginGroup("SMS");

        QString BGPath (this -> globalOptions -> value("BGPath",  "").toString()),
                BGColor(this -> globalOptions -> value("BGColor", "").toString());

        this -> sms -> BGWay -> setText(BGPath);
        this -> sms -> BGC   -> setText(BGColor);

        this -> appOptions -> BGPath  = BGPath;
        this -> appOptions -> BGColor = BGColor;

        this -> globalOptions -> endGroup();

        ///////////////////////////////////////////////////////////////

        this -> globalOptions -> beginGroup("Contacts");

        bool    SearchBarContatcs(this -> globalOptions -> value("SearchBar", true).toBool()),
                FirstLastContacts(this -> globalOptions -> value("FirstLast", true).toBool());

        this -> contacts -> box         -> setChecked(SearchBarContatcs);
        this -> contacts -> _first_last -> setChecked(FirstLastContacts);
        this -> contacts -> _last_first -> setChecked(!FirstLastContacts);

        this -> appOptions -> SearchBarContatcs = SearchBarContatcs;
        this -> appOptions -> FirstLastContacts = FirstLastContacts;

        this -> globalOptions -> endGroup();

        ///////////////////////////////////////////////////////////////

        this -> globalOptions -> beginGroup("Pictures");

        bool    SearchBarPictures(this -> globalOptions -> value("SearchBar", true).toBool()),
                FirstLastPictures(this -> globalOptions -> value("FirstLast", true).toBool());

        QString BGColorPictures(this -> globalOptions -> value("BGColor", "").toString());

        this -> pictures -> box         -> setChecked(SearchBarPictures);
        this -> pictures -> _first_last -> setChecked(FirstLastPictures);
        this -> pictures -> _last_first -> setChecked(!FirstLastPictures);
        this -> pictures -> BGC         -> setText(BGColorPictures);

        this -> appOptions -> SearchBarPictures = SearchBarPictures;
        this -> appOptions -> FirstLastPictures = FirstLastPictures;
        this -> appOptions -> BGColorPictures = BGColorPictures;

        this -> globalOptions -> endGroup();

        ///////////////////////////////////////////////////////////////

        this -> globalOptions -> beginGroup("Theme");

        QString title (this -> globalOptions -> value("Title",  "").toString()),
                QSS (this -> globalOptions -> value("QSS",  "").toString());

        this -> skin -> select -> setCurrentIndex(this -> skin -> select -> findText(title));

        this -> appOptions -> title = title;
        this -> appOptions -> QSS = QSS;

        this -> globalOptions -> endGroup();

        ///////////////////////////////////////////////////////////////
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void restoreOptions() {
        this -> global -> apple -> setChecked(false);
        this -> global -> vault -> setChecked(false);
        this -> global -> nada  -> setChecked(true);
        this -> global -> language -> setCurrentIndex(0);
        this -> global -> iphones  -> setCurrentIndex(0);

        this -> sms -> BGWay -> setText("");
        this -> sms -> BGC   -> setText("");

        this -> skin -> select -> setCurrentIndex(0);
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void changePage(QListWidgetItem * current, QListWidgetItem * previous) {
        if (!current) current = previous;
        this -> pagesWidget -> setCurrentIndex(this -> contentsWidget -> row(current));
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

private:

    void createIcons() {
        QListWidgetItem * globalButton = new QListWidgetItem(this -> contentsWidget);
        globalButton -> setIcon(QIcon(this -> appPath + "/utils/icons/manage.png"));
        globalButton -> setText(tr("iManager"));
        globalButton -> setTextAlignment(Qt::AlignHCenter);
        globalButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QListWidgetItem * smsButton = new QListWidgetItem(this -> contentsWidget);
        smsButton -> setIcon(QIcon(this -> appPath + "/utils/icons/sms_icon.png"));
        smsButton -> setText(tr("SMS"));
        smsButton -> setTextAlignment(Qt::AlignHCenter);
        smsButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QListWidgetItem * contactButton = new QListWidgetItem(this -> contentsWidget);
        contactButton -> setIcon(QIcon(this -> appPath + "/utils/icons/contact_icon.png"));
        contactButton -> setText(tr("Contacts"));
        contactButton -> setTextAlignment(Qt::AlignHCenter);
        contactButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QListWidgetItem * pictureButton = new QListWidgetItem(this -> contentsWidget);
        pictureButton -> setIcon(QIcon(this -> appPath + "/utils/icons/picture_icon.png"));
        pictureButton -> setText(tr("Pictures"));
        pictureButton -> setTextAlignment(Qt::AlignHCenter);
        pictureButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QListWidgetItem * callButton = new QListWidgetItem(this -> contentsWidget);
        callButton -> setIcon(QIcon(this -> appPath + "/utils/icons/call_icon.png"));
        callButton -> setText(tr("Calls"));
        callButton -> setTextAlignment(Qt::AlignHCenter);
        callButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QListWidgetItem * noteButton = new QListWidgetItem(this -> contentsWidget);
        noteButton -> setIcon(QIcon(this -> appPath + "/utils/icons/note_icon.png"));
        noteButton -> setText(tr("Notes"));
        noteButton -> setTextAlignment(Qt::AlignHCenter);
        noteButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QListWidgetItem * calendarButton = new QListWidgetItem(this -> contentsWidget);
        calendarButton -> setIcon(QIcon(this -> appPath + "/utils/icons/calendar_icon.png"));
        calendarButton -> setText(tr("Calendar"));
        calendarButton -> setTextAlignment(Qt::AlignHCenter);
        calendarButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QListWidgetItem * vaultButton = new QListWidgetItem(this -> contentsWidget);
        vaultButton -> setIcon(QIcon(this -> appPath + "/utils/icons/vault_icon.png"));
        vaultButton -> setText(tr("Vault"));
        vaultButton -> setTextAlignment(Qt::AlignHCenter);
        vaultButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QListWidgetItem * themeButton = new QListWidgetItem(this -> contentsWidget);
        themeButton -> setIcon(QIcon(this -> appPath + "/utils/icons/theme.png"));
        themeButton -> setText(tr("Skin"));
        themeButton -> setTextAlignment(Qt::AlignHCenter);
        themeButton -> setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        connect(this -> contentsWidget, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(changePage(QListWidgetItem *, QListWidgetItem *)));
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void setupOptions(const QString & title) {
        if(title == "Darkness") {
            if(this -> sms -> BGC -> text().isEmpty())
                this -> sms -> BGC -> setText("#555555");
            if(this -> pictures -> BGC -> text().isEmpty())
                this -> pictures -> BGC -> setText("#555555");
        }
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    QListWidget * contentsWidget;
    QStackedWidget * pagesWidget;
    QString appPath;
    QSettings * globalOptions;

    GlobalPage * global;
    SMSPage * sms;
    ContactsPage * contacts;
    PicturesPage * pictures;
    ThemePage * skin;
    Options * appOptions;

Q_SIGNALS:

    void optionsChanged();
};

/** --------------------------------------------------------------------------------------------------------------- **/

#endif // CONFIGDIALOG_HPP

/** --------------------------------------------------------------------------------------------------------------- **/
