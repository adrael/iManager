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

#ifndef SEARCHBAR_HPP
#define SEARCHBAR_HPP

/** --------------------------------------------------------------------------------------------------------------- **/

#include <qcoreapplication.h>
#include <qtoolbutton.h>
#include <qevent.h>
#include <qlineedit.h>
#include <qstyle.h>

/** --------------------------------------------------------------------------------------------------------------- **/

class SearchBar : public QLineEdit {

    Q_OBJECT

public:

    SearchBar(const QString & lineText = "", const QString & iconPath = "", QWidget * lineParent = 0) :
        QLineEdit(lineText, lineParent),
        clearButton(new QToolButton(this)),
        iconButton(new QToolButton(this)),
        myText(lineText) {


        QPalette palette = this -> palette();
        palette.setColor(QPalette::Text, QColor(128, 128, 128));
        this -> setPalette(palette);

        this -> clearButton -> setIcon(QIcon(iconPath + "/clear.png"));
        this -> clearButton -> setIconSize(QSize(16, 16));
        this -> clearButton -> setCursor(Qt::PointingHandCursor);
        this -> clearButton -> setStyleSheet("QToolButton {border: none; padding: 0px;}");
        this -> clearButton -> hide();
        this -> clearButton -> setToolTip(tr("Clear searchbar"));

        this -> iconButton -> setIcon(QIcon(iconPath + "/search.png"));
        this -> iconButton -> setIconSize(QSize(16, 16));
        this -> iconButton -> setStyleSheet("QToolButton {border: none; padding: 0px;}");
        this -> iconButton -> setToolTip(tr("Type keywords you are searching for"));

        this -> connect(this -> clearButton, SIGNAL(clicked()), this, SLOT(clear()));
        this -> connect(this, SIGNAL(textChanged(const QString &)), this, SLOT(updateCloseButton(const QString &)));

        int frameWidth = style() -> pixelMetric(QStyle::PM_DefaultFrameWidth);
        this -> setStyleSheet(QString("QLineEdit {padding-right: %1px; padding-left: %1px;} ").arg(this -> clearButton -> sizeHint().width() + frameWidth + 5));

        QSize miniSize = minimumSizeHint();

        this -> setMinimumSize(qMax(miniSize.width(), this -> clearButton -> sizeHint().height() + frameWidth * 2 + 2),
                               qMax(miniSize.height(), this -> clearButton -> sizeHint().height() + frameWidth * 2 + 2));

        this -> setAcceptDrops(false);
    }

    ~SearchBar() {}

    void mousePressEvent(QMouseEvent * event) {
        if (event -> button() == Qt::RightButton) event -> accept();
        else  QLineEdit::mousePressEvent(event);
    }

    void contextMenuEvent(QContextMenuEvent * event) {
        event -> ignore();
        return;
    }

    void noResult(bool result = false) {
        QPalette palette = this -> palette();
        if(result) palette.setColor(QPalette::Text, QColor(255, 0, 0));
        else palette.setColor(QPalette::Text, QColor(0, 0, 0));
        this -> setPalette(palette);
    }

protected:

    void resizeEvent(QResizeEvent * event) {
        QSize size = this -> clearButton -> sizeHint();
        int frameWidth = style() -> pixelMetric(QStyle::PM_DefaultFrameWidth);
        this -> clearButton -> move(rect().right() - frameWidth - size.width(), (rect().bottom() + 1 - size.height()) / 2);
        this -> iconButton -> move(5, (rect().bottom() + 1 - size.height()) / 2);
    }


private slots:

    void updateCloseButton(const QString & text) {
        bool empty(text.isEmpty());
        this -> clearButton -> setVisible(!empty);
        if(!empty && text != this -> myText) this -> emit searchText(text);
        if(empty) {
            this -> emit cleaned();
            QCoreApplication::processEvents();
            QCoreApplication::flush();
        }
    }

private:

    QToolButton * clearButton, * iconButton;
    QString myText;

    void focusInEvent(QFocusEvent * event) {
        if(this -> text() == this -> myText) {
            QPalette palette = this -> palette();
            palette.setColor(QPalette::Text, QColor(0, 0, 0));
            this -> setPalette(palette);
            this -> emit hasFocus();
        } else this -> emit searchText(this -> text());
        event -> accept();
    }

    void focusOutEvent(QFocusEvent * e) {
        if(this -> text().isEmpty()) {
            QPalette palette = this -> palette();
            palette.setColor(QPalette::Text, QColor(128, 128, 128));
            this -> setPalette(palette);
            this -> setText(this -> myText);
            this -> clearButton -> setVisible(false);
            this -> emit cleaned();
            QCoreApplication::processEvents();
            QCoreApplication::flush();
        }
        e -> accept();
    }

Q_SIGNALS:

    void hasFocus();
    void searchText(const QString &);
    void cleaned();
};

/** --------------------------------------------------------------------------------------------------------------- **/

#endif // SEARCHBAR_HPP
