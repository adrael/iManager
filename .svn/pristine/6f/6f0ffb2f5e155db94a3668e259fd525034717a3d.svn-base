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

#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

/** --------------------------------------------------------------------------------------------------------------- **/

#include <qobject.h>
#include <qstatusbar.h>
#include <qprogressbar.h>
#include <qlabel.h>

/** --------------------------------------------------------------------------------------------------------------- **/

class StatusBar : public QStatusBar
{
    Q_OBJECT

public:

    QProgressBar * progress;
    QStatusBar * statusBar;
    QLabel * infoLbl, * countLbl, * version;

    StatusBar(QStatusBar * sB = 0) {
        this -> statusBar = sB;

        this -> progress = new QProgressBar(this -> statusBar);
        this -> progress -> setRange(0, 100);
        this -> progress -> setValue(0);
        this -> progress -> setVisible(false);

        this -> infoLbl = new QLabel("<center>" + tr("No database loaded") + "</center>", this -> statusBar);
        this -> infoLbl -> setFrameStyle(QFrame::Panel | QFrame::Sunken);

        this -> countLbl = new QLabel(tr("Nothing to display"));
        this -> countLbl -> setFrameStyle(QFrame::Panel | QFrame::Sunken);

        this -> version = new QLabel("iPhoneManager 5.0", this -> statusBar);
        this -> version -> setFrameStyle(QFrame::Panel | QFrame::Sunken);

        this -> statusBar -> addPermanentWidget(this -> countLbl);
        this -> statusBar -> addPermanentWidget(this -> infoLbl, 100);
        this -> statusBar -> addPermanentWidget(this -> version);
        this -> statusBar -> addPermanentWidget(this -> progress, 100);
        this -> statusBar -> setSizeGripEnabled(false);
        this -> statusBar -> setFixedHeight(20);
    }

    ~StatusBar(){}

    /** --------------------------------------------------------------------------------------------------------------- **/

public slots:

    void update(const int & tab) {
        switch(tab) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            ;
        }
    }
};

/** --------------------------------------------------------------------------------------------------------------- **/

#endif // STATUSBAR_HPP

