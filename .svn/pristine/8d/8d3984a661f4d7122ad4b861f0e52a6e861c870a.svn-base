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

#ifndef SMS_HPP
#define SMS_HPP

/** --------------------------------------------------------------------------------------------------------------- **/

#include <qdebug.h>

#include <qobject.h>
#include <qwidget.h>
#include <qlayout.h>
#include <qtreewidget.h>

#include <qstatemachine.h>
#include <qgraphicsview.h>
#include <qgraphicsscene.h>
#include <qgraphicswidget.h>
#include <qpropertyanimation.h>
#include <qgraphicsproxywidget.h>
#include <qgraphicslinearlayout.h>
#include <qparallelanimationgroup.h>
#include <qsequentialanimationgroup.h>

/** --------------------------------------------------------------------------------------------------------------- **/

#include "webview.hpp"
#include "options.hpp"
#include "database.hpp"

/** --------------------------------------------------------------------------------------------------------------- **/

class SMS : public QWidget {

    Q_OBJECT

public:

    SMS(QWidget * parent = 0, database * db = 0, const QString & path = "", Options * opt = 0) : QWidget(parent) {
        this -> initAttributes(db, path, opt);
        QHBoxLayout * SMSLayout = new QHBoxLayout;
        SMSLayout -> setContentsMargins(0, 0, 0, 0);
        SMSLayout -> setSpacing(0);

        this -> SMSTreeList = new QTreeWidget(this);
        this -> SMSTreeList -> setAlternatingRowColors(true);
        this -> SMSTreeList -> setIconSize(QSize(50, 50));
        this -> SMSTreeList -> setMinimumWidth(300);
        this -> connect(this -> SMSTreeList, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(showConversation(QTreeWidgetItem *, int)));

        this -> SMSWebView = new WebView();
        this -> SMSWebView -> setFixedSize(364, 483);
        this -> connect(this -> SMSWebView, SIGNAL(linkClicked(const QUrl &)), this, SLOT(emitSignal(const QUrl &)));

        /////////// ANIMATION ///////////

        QGraphicsProxyWidget * webProxy = new QGraphicsProxyWidget;
        webProxy -> setWidget(this -> SMSWebView);

        QGraphicsWidget * widget = new QGraphicsWidget;
        QGraphicsLinearLayout * layout = new QGraphicsLinearLayout(Qt::Vertical, widget);
        layout -> addItem(webProxy);
        widget -> setLayout(layout);

        QGraphicsScene * scene = new QGraphicsScene(0, 0, 364, 483, this);
        scene -> setBackgroundBrush(this -> palette().window());
        scene -> addItem(widget);

        QStateMachine * machine = new QStateMachine;
        QState * state1 = new QState(machine);
        QState * state2 = new QState(machine);
        machine -> setInitialState(state1);

        int time(350);
        state1 -> assignProperty(this -> SMSWebView, "geometry", QRect(0, 0, this -> SMSWebView -> width(), this -> SMSWebView -> height()));
        state2 -> assignProperty(this -> SMSWebView, "geometry", QRect(0, 0, this -> SMSWebView -> width(), this -> SMSWebView -> height()));

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        QPropertyAnimation * animation = new QPropertyAnimation(webProxy, "opacity");
        animation -> setDuration(time);
        animation -> setKeyValueAt(  0, qreal(1));
        animation -> setKeyValueAt(0.5, qreal(0.5));
        animation -> setKeyValueAt(  1, qreal(0));

        QPropertyAnimation * move = new QPropertyAnimation(webProxy, "pos");
        move -> setDuration(2 * time);
        move -> setKeyValueAt(  0, QPointF(0,         0));
        move -> setKeyValueAt(0.5, QPointF(50,        0));
        move -> setKeyValueAt(1.0, QPointF(120,       0));
        move -> setEasingCurve(QEasingCurve::OutExpo);

        QParallelAnimationGroup * para = new QParallelAnimationGroup;
        para -> addAnimation(animation);
        para -> addAnimation(move);

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        QPropertyAnimation * animation2 = new QPropertyAnimation(webProxy, "opacity");
        animation2 -> setDuration(time);
        animation2 -> setKeyValueAt(  0, qreal(0));
        animation2 -> setKeyValueAt(0.5, qreal(0.5));
        animation2 -> setKeyValueAt(  1, qreal(1));

        QPropertyAnimation * move2 = new QPropertyAnimation(webProxy, "pos");
        move2 -> setDuration(2 * time);
        move2 -> setKeyValueAt(  0, QPointF(120,         0));
        move2 -> setKeyValueAt(0.5, QPointF(-70,         0));
        move2 -> setKeyValueAt(1.0, QPointF(0,           0));
        move2 -> setEasingCurve(QEasingCurve::OutExpo);

        QParallelAnimationGroup * para2 = new QParallelAnimationGroup;
        para2 -> addAnimation(animation2);
        para2 -> addAnimation(move2);

        this -> group = new QSequentialAnimationGroup;
        this -> group -> addAnimation(para);
        this -> group -> addAnimation(para2);

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        this -> connect(para, SIGNAL(finished()), this, SLOT(change()));

        QAbstractTransition * t1 = state1 -> addTransition(this -> SMSTreeList, SIGNAL(itemClicked(QTreeWidgetItem *, int)), state2);
        t1 -> addAnimation(this -> group);

        QAbstractTransition * t2 = state2 -> addTransition(this -> SMSTreeList, SIGNAL(itemClicked(QTreeWidgetItem *, int)), state1);
        t2 -> addAnimation(this -> group);

        machine -> start();

        this -> view = new QGraphicsView(scene);
        this -> view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this -> view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this -> view -> setFocusPolicy(Qt::NoFocus);

        ////////////// FIN //////////////

        SMSLayout -> addWidget(this -> SMSTreeList);
        SMSLayout -> addWidget(this -> view);

        this -> displayDefaultView();
        this -> setLayout(SMSLayout);
    }

    ~SMS() {}

    /** --------------------------------------------------------------------------------------------------------------- **/

    void displayDefaultView() {
        this -> SMSTreeList -> setHeaderLabel(tr("There is no SMS in the database"));
        this -> contactPicture.load(this -> appPath + "/utils/icons/nobody.png");
        this -> makeDefaultWebPage();
        this -> SMSWebView -> load(QUrl(this -> tmpDirectory + "/sms.html"));
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void loadSMSData() {
        this -> SMSTreeList -> clear();
        QSqlQuery smsQuery(this -> DBManager -> getDatabase("sms"));
        smsQuery.exec("SELECT * FROM message");
        while(smsQuery.next()) ++this -> totalSMS;

        int count(0);
        people * tmp;
        QVector<QTreeWidgetItem *> sort;
        QVector<qint64> time;

        smsQuery.exec("SELECT * FROM group_member");
        while(smsQuery.next()) {
            ++count;
            tmp = this -> DBManager -> getContactFromNum(this -> getCastNum(smsQuery.value(2).toString()));

            QTreeWidgetItem * item = new QTreeWidgetItem(this -> SMSTreeList);
            item -> setIcon(0, (tmp ? tmp -> thumbnail : QIcon(this -> appPath + "/utils/icons/nobody.png")));
            item -> setText(0, (tmp ? tmp -> first + " " + tmp -> last : smsQuery.value(2).toString()) + "\n" + this -> getLastSMSDate(smsQuery.value(1).toString()));
            item -> setFont(0, QFont("", 8, QFont::Bold));
            item -> setText(1, smsQuery.value(1).toString());
            item -> setText(2, QString::number(tmp ? tmp -> peopleID : -1));
            this -> SMSTreeList -> addTopLevelItem(item);
        }

        this -> SMSTreeList -> setHeaderLabel(QString::number(count) + " " + (count > 1 ? tr("conversations") : tr("conversation")));
        this -> showConversation(this -> SMSTreeList -> topLevelItem(0));
        this -> change();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void setMaxScrollWebView() {
        this -> SMSWebView -> page() -> mainFrame() -> setScrollBarValue(Qt::Vertical, this -> SMSWebView -> page() -> mainFrame() -> scrollBarMaximum(Qt::Vertical));
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void setMinScrollWebView() {
        this -> SMSWebView -> page() -> mainFrame() -> setScrollBarValue(Qt::Vertical, this -> SMSWebView -> page() -> mainFrame() -> scrollBarMinimum(Qt::Vertical));
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    bool isSMS(const QString & ID) {
        for(int i(0); i < this -> SMSTreeList -> topLevelItemCount(); ++i)
            if(this -> SMSTreeList -> topLevelItem(i) -> text(2) == ID)
                return true;
        return false;
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void findContact(const QString & ID) {
        for(int i(0); i < this -> SMSTreeList -> topLevelItemCount(); ++i)
            if(this -> SMSTreeList -> topLevelItem(i) -> text(2) == ID) {
                this -> showConversation(this -> SMSTreeList -> topLevelItem(i));
                this -> group -> start();
                break;
            }
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

private slots:

    void updateOptions() {
        if(this -> currentContactDisplayedSet)
            this -> showConversation(this -> currentContactDisplayed);
        else this -> makeDefaultWebPage();

        this -> group -> start();
        this -> change();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void showConversation(QTreeWidgetItem * item, const int & = 0) {
        int received(0), sent(0);
        QSqlQuery sms_query(this -> DBManager -> getDatabase("sms"));
        QString html("");

        this -> currentContactDisplayedSet = true;
        this -> currentContactDisplayed = item;

        item -> icon(0).pixmap(44, 43).save(this -> tmpDirectory + "/pic_sms.png");

        sms_query.exec("SELECT * FROM message WHERE flags = " + QString::number(2) + " AND group_id = " + item -> text(1));
        while(sms_query.next()) ++received;
        sms_query.exec("SELECT * FROM message WHERE flags = " + QString::number(3) + " AND group_id = " + item -> text(1));
        while(sms_query.next()) ++sent;
        sms_query.exec("SELECT * FROM message WHERE group_id = " + item -> text(1));

        html = "<!DOCTYPE HTML><html><head><style type=\"text/css\"><!--" + this -> getCSS() +
                "--></style></head><body><html><div id=\"header\"><a href=\"pic/" + item -> text(2) + "\"><img class=\"pic\" src=\"pic_sms.png\" width=\"44\" height=\"43\"/></a><b><font size=\"4\">" +
                item -> text(0).split('\n', QString::KeepEmptyParts, Qt::CaseInsensitive).at(0) + "</font></b><br/>" +
                "<font size=\"2\">" + QString::number(received) + " " + tr("received") + " / " + QString::number(sent) + " " + tr("sent") + "</font><a href=\"contacts/" + item -> text(2) + "\" id=\"info\">" +
                "<img src=\"../icons/contacts.png\" title=\"" + tr("View contact address information") + "\"/></a></div><br/><br/><br/><div id=\"top\"></div>" +
                (sent + received >= 5 ? "<center><a href=\"#foot\" id=\"head\"><img src=\"../icons/arrow-down.png\"/></a></center>" : "") + "<br/>";

        qint64 previous(0), current(0);
        QString when("");
        while(sms_query.next()) {
            when.clear();
            current = sms_query.value(2).toInt();
            if(current - previous >= 700)
                when = "<div id=\"date\">" + QDateTime::fromTime_t(current).toString("dd MMMM yyyy hh:mm") + "</div><br/>";
            previous = current;
            if(sms_query.value(4).toString() == "2")
                html += when + "<div id=\"receiveh\">&nbsp;</div><div id=\"receive\">" + this -> manageText(sms_query.value(3).toString()) + "</div><div id=\"receiveb\">&nbsp;</div><br/>";
            else html += when + "<div id=\"senth\">&nbsp;</div><div id=\"sent\">" + this -> manageText(sms_query.value(3).toString()) + "</div><div id=\"sentb\">&nbsp;</div><br/>";
        }

        html += (sent + received >= 5 ? "<center><a href=\"#top\" id=\"bottom\"><img src=\"../icons/arrow-up.png\"/></a></center>" : "") + QString("<br/><div id=\"foot\"/></body></html>");

        QFile file(this -> tmpDirectory + "/sms.html");
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            file.write(html.toAscii());
            file.close();
        }
        this -> SMSTreeList -> clearSelection();
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void emitSignal(const QUrl & url) {
        this -> emit linkClicked(url.toString());
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void change() {
        this -> SMSWebView -> load(QUrl(this -> tmpDirectory + "/sms.html"));
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

private:

    void makeDefaultWebPage() {
        QString html = "<!DOCTYPE HTML><html><head><style type=\"text/css\"><!--" + this -> getCSS() +
                "--></style></head><body><html><div id=\"header\"><b><font size=\"6\">"+ tr("No SMS to display") + "</font></b><br/></body></html>";

        QFile index(this -> tmpDirectory + "/sms.html", this);
        if(index.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&index);
            stream.setCodec("UTF-8");
            index.write(html.toAscii());
            index.close();
        } else qDebug() << tr("Cannot open sms.html !");
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    QString manageText(QString ref) {
        QStringList list(ref.split('\n', QString::KeepEmptyParts, Qt::CaseInsensitive)), final;
        int currPos(0), relativePos(0), lastSpace(-1), lastCut(0);
        while(!list.isEmpty()) {
            ref.clear();
            ref = list.takeFirst();
            if(ref.contains(" ", Qt::CaseInsensitive)) {
                currPos = 0;
                relativePos = 0;
                lastSpace = -1;
                lastCut = 0;
                while(currPos  < ref.size()) {
                    lastCut = lastSpace + 1;
                    currPos = lastCut;
                    relativePos = 0;
                    lastSpace = -1;
                    while(relativePos < 30 && currPos  < ref.size()) {
                        if(ref.at(currPos) == ' ') lastSpace = currPos;
                        ++relativePos;
                        ++currPos;
                    }
                    if(lastSpace != -1 && currPos < ref.size())
                        final << ref.mid(lastCut, lastSpace - lastCut);
                    else {
                        final << ref.mid(lastCut, currPos - lastCut);
                        lastSpace = currPos - 1;
                    }
                }
            } else {
                for(int i(26); i < ref.size(); i += 27) ref.insert(i, '\n');
                ref.replace("\n", "<br/>");
                final.append(ref);
            }
        }

        ref.clear();
        while(!final.isEmpty()) ref.append(final.takeFirst() + "<br/>");

        ref.replace("é", "&eacute;").replace("É", "&Eacute;").replace("è", "&egrave;").replace("È", "&Egrave;").replace("� ", "&agrave;").replace("À", "&Agrave;").replace(" ", "&nbsp;");

        return ref;
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    QString getCSS() {
        QString content(""), background(""), header("../icons/header.png");
        QFile css(this -> appPath + "/utils/sms_design.css", this);
        if(css.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&css);
            while(!stream.atEnd())
                content += stream.readLine();
            css.close();

            if(this -> appOptions -> BGColor.isEmpty() && this -> appOptions -> BGPath.isEmpty())
                background = "background: #dbe2ed;";
            else if(!this -> appOptions -> BGPath.isEmpty())
                background = "background: #dbe2ed url('" + this -> appOptions -> BGPath + "')  no-repeat; background-size: 370px 480px; background-attachment: fixed; background-position: top center;";
            else
                background = "background: " + this -> appOptions -> BGColor + ";";

            if(this -> appOptions -> title == "Darkness")
                header = "../icons/header_black.png";

            content.replace("--background--", background).replace("--header--", header);
        } else qDebug() << tr("Cannot open sms_design.css !");
        return content;
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    QString getCastNum(QString req) {
        QSqlQuery contact_query(this -> DBManager -> getDatabase("contacts"));
        QString format("");
        int method(0);

        contact_query.exec("SELECT * FROM ABMultiValue WHERE value = " + req );
        contact_query.next();

        while(!contact_query.isValid() && method < 3) {
            switch(method) {
            case 0:
                req.replace(" ", "");
                break;

            case 1:
                for(int i(0); i < 100; ++i) req.replace("+" + (i < 10 ? "0" + QString::number(i) : QString::number(i)), "0");
                break;

            case 2:
                for(int i(0); i < 5; ++i) {
                    format += req.left(2) + " ";
                    req.remove(0, 2);
                }
                req.clear();
                format.chop(1);
                req = format;
                format.clear();
                break;

            default:
                method = 3;
            }

            contact_query.exec("SELECT * FROM ABMultiValue WHERE value = " + req);
            contact_query.next();
            ++method;
        }

        req.replace(" ", "");
        req.replace("+33", "0");
        for(int i(0); i < 5; ++i) {
            format += req.left(2) + " ";
            req.remove(0, 2);
        }
        format.chop(1);
        return format;
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    QString getLastSMSDate(const QString & ID) {
        QDateTime date;
        QSqlQuery smsQuery(this -> DBManager -> getDatabase("sms"));
        smsQuery.exec("SELECT * FROM message WHERE group_id = " + ID);
        if(smsQuery.last()) {
            date.setTime_t(smsQuery.value(2).toInt());
            return date.toString("dd MMM yyyy");
        }
        return tr("Unable to determine the date");
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    int getSMSCount() {
        return this -> totalSMS;
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    void initAttributes(database * db, const QString & path, Options * opt) {
        this -> appPath                    = path;
        this -> tmpDirectory               = this -> appPath + "/utils/tmp";
        this -> DBManager                  = db;
        this -> appOptions                 = opt;
        this -> totalSMS                   = 0;
        this -> currentContactDisplayedSet = false;
    }

    /** --------------------------------------------------------------------------------------------------------------- **/

    QTreeWidget                * SMSTreeList;
    QTreeWidgetItem            * currentContactDisplayed;
    QPixmap                      contactPicture;
    QString                      appPath, tmpDirectory;
    QGraphicsView              * view;
    QSequentialAnimationGroup  * group;

    int  totalSMS;
    bool currentContactDisplayedSet;

    WebView  * SMSWebView;
    database * DBManager;
    Options  * appOptions;

Q_SIGNALS:

    void linkClicked(const QString &);
};

/** --------------------------------------------------------------------------------------------------------------- **/

#endif // SMS_HPP
