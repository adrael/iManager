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

#ifndef MENUBAR_HPP
#define MENUBAR_HPP

/** --------------------------------------------------------------------------------------------------------------- **/

#include <qdebug.h>

#include <qmenu.h>
#include <qobject.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qmessagebox.h>
#include <qcoreapplication.h>

/** --------------------------------------------------------------------------------------------------------------- **/

#include "configdialog.hpp"

/** --------------------------------------------------------------------------------------------------------------- **/

class MenuBar : public QMenuBar
{

    Q_OBJECT

public:

    QMenuBar * mB;

    /** --------------------------------------------------------------------------------------------------------------- **/

    MenuBar(QMenuBar * bar = 0, ConfigDialog * configDialog = 0, const QString & iconPath = "") {
        this -> mB = bar;
        this -> path = iconPath;

        QMenu   * fileMenu    (this -> mB -> addMenu(tr("&Files"))),
                * SMSMenu     (this -> mB -> addMenu(tr("&SMS"))),
                * ContactMenu (this -> mB -> addMenu(tr("&Contacts"))),
                * CallMenu    (this -> mB -> addMenu(tr("C&alls"))),
                * NotesMenu   (this -> mB -> addMenu(tr("&Notes"))),
                * CalendarMenu(this -> mB -> addMenu(tr("Calen&dar"))),
                * PicMenu     (this -> mB -> addMenu(tr("&Pictures"))),
                * VaultMenu   (this -> mB -> addMenu(tr("&Vault"))),
                * aboutMenu   (this -> mB -> addMenu(tr("&?")));

        QAction * importAction       = fileMenu     -> addAction(tr("Import Apple iTunes iPhone Backup"), this, SLOT(import()), QKeySequence("Ctrl+Shift+I")),
                * ParamAction        = fileMenu     -> addAction(tr("Parameters"),     (QObject *)configDialog, SLOT(show()));
        fileMenu -> addSeparator();
        QAction * quitAction         = fileMenu     -> addAction(tr("Quit"),                   QCoreApplication::instance(), SLOT(quit()), QKeySequence("Alt+F4"));

        QAction * ContactOpenAction  = ContactMenu  -> addAction(tr("Open Contacts database"), this, SLOT(openContacts()));

        QAction * CallOpenAction     = CallMenu     -> addAction(tr("Open Calls database"),    this, SLOT(openCalls()));

        QAction * CalendarOpenAction = CalendarMenu -> addAction(tr("Open Calendar database"), this, SLOT(openCalendar()));

        QAction * SMSOpenAction      = SMSMenu      -> addAction(tr("Open SMS database"),      this, SLOT(openSMS()));

        QAction * PicOpenAction      = PicMenu      -> addAction(tr("Open Pictures database"), this, SLOT(openPictures()));

        QAction * NoteOpenAction     = NotesMenu    -> addAction(tr("Open Notes database"),    this, SLOT(openNotes()));

        QAction * aboutAction        = aboutMenu    -> addAction(tr("About iPhoneManager"),    this, SLOT(about())),
                * helpAction         = aboutMenu    -> addAction(tr("Help"),                   QCoreApplication::instance(), SLOT(quit()));
        aboutMenu -> addSeparator();
        QAction * payAction          = aboutMenu    -> addAction(tr("Donate"),                 QCoreApplication::instance(), SLOT(quit()));

        QAction * VaultOpenAction    = VaultMenu    -> addAction(tr("Open Vault database"),    this, SLOT(openVault()));

        importAction       -> setIcon(QIcon(this -> path + "/utils/icons/import.png"));
        ParamAction        -> setIcon(QIcon(this -> path + "/utils/icons/tools.png"));
        CalendarOpenAction -> setIcon(QIcon(this -> path + "/utils/icons/open.png"));
        CallOpenAction     -> setIcon(QIcon(this -> path + "/utils/icons/open.png"));
        quitAction         -> setIcon(QIcon(this -> path + "/utils/icons/quit.png"));
        ContactOpenAction  -> setIcon(QIcon(this -> path + "/utils/icons/open.png"));
        SMSOpenAction      -> setIcon(QIcon(this -> path + "/utils/icons/open.png"));
        PicOpenAction      -> setIcon(QIcon(this -> path + "/utils/icons/open.png"));
        NoteOpenAction     -> setIcon(QIcon(this -> path + "/utils/icons/open.png"));
        VaultOpenAction    -> setIcon(QIcon(this -> path + "/utils/icons/open.png"));
        aboutAction        -> setIcon(QIcon(this -> path + "/utils/icons/about.png"));
        helpAction         -> setIcon(QIcon(this -> path + "/utils/icons/help.png"));
        payAction          -> setIcon(QIcon(this -> path + "/utils/icons/paypal.png"));
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

private slots:

    void import() {
        emit this -> importDatabases();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void openContacts() {
        emit this -> contactsDatabase();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void openCalls() {
        emit this -> callsDatabase();
    }


    /** --------------------------------------------------------------------------------------------------------------- **/

    void openCalendar() {
        emit this -> calendarDatabase();
    }


    /** --------------------------------------------------------------------------------------------------------------- **/

    void openPictures() {
        emit this -> picturesDatabase();
    }


    /** --------------------------------------------------------------------------------------------------------------- **/

    void openNotes() {
        emit this -> notesDatabase();
    }


    /** --------------------------------------------------------------------------------------------------------------- **/

    void openSMS() {
        emit this -> smsDatabase();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void openVault() {
        emit this -> vaultDatabase();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void about() {
        QMessageBox about_box(this);
        about_box.setWindowTitle(tr("About iPhoneManager"));
        about_box.setText(tr("<b>iPhoneManager</b> is a free software, designed to easily<br/>access all iPhone data.<br/>"
                             "You can modify, redistribute or use it as you want.<br/>See \"<u>LICENSE</u>\" file for details.<br/>"
                             "It has been made possible by Rapha&euml;l Marques <b>&lt;work.rmarques@gmail.com&gt;</b>.<br/><br/>"
                             "Enjoy =) !!"));
        about_box.setIconPixmap(QPixmap(this -> path + "/utils/icons/logo.png"));
        about_box.exec();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

private:

    QString path;

Q_SIGNALS:

    void calendarDatabase();
    void callsDatabase();
    void contactsDatabase();
    void notesDatabase();
    void picturesDatabase();
    void smsDatabase();
    void vaultDatabase();
    void importDatabases();

};

/** --------------------------------------------------------------------------------------------------------------- **/

#endif // MENUBAR_HPP
