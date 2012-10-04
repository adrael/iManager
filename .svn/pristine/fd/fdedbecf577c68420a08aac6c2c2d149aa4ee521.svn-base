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

#ifndef WEBVIEW_HPP
#define WEBVIEW_HPP

/** --------------------------------------------------------------------------------------------------------------- **/

#include <qapplication.h>
#include <qevent.h>
#include <qclipboard.h>
#include <qwebframe.h>
#include <qwebview.h>

/** --------------------------------------------------------------------------------------------------------------- **/

class WebView : public QWebView
{
    Q_OBJECT

public:

    WebView(QWidget * parent = 0) : QWebView(parent), clipApp(QApplication::clipboard()) {
        this -> setAcceptDrops(false);
        this -> page() -> mainFrame() -> setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
        this -> page() -> setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    }

    void mousePressEvent(QMouseEvent * event) {
        if (event -> button() == Qt::RightButton) event -> accept();
        else  QWebView::mousePressEvent(event);
    }

    void keyPressEvent(QKeyEvent * event) {
        if((event -> modifiers() &  Qt::ControlModifier) && (event -> key() == Qt::Key_C) && !this -> selectedText().isEmpty()) clipApp -> setText(this -> selectedText());
        else if(event -> key() == Qt::Key_PageUp || event -> key() == Qt::Key_PageDown || event -> key() == Qt::Key_Up || event -> key() == Qt::Key_Down ||
                event -> key() == Qt::Key_End || event -> key() == Qt::Key_Space || event -> key() == Qt::Key_Home) QWebView::keyPressEvent(event);
        else event -> ignore();
    }

    void contextMenuEvent(QContextMenuEvent * event) {
        event -> ignore();
        return;
    }

private:

    QClipboard * clipApp;
};

/** --------------------------------------------------------------------------------------------------------------- **/

#endif // WEBVIEW_HPP
