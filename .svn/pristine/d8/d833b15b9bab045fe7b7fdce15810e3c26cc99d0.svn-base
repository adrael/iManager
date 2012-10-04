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

#ifndef PEOPLE
#define PEOPLE

/** --------------------------------------------------------------------------------------------------------------- **/

#include <qstring.h>
#include <qwidget.h>
#include <qicon.h>

/** --------------------------------------------------------------------------------------------------------------- **/

#include <vector>
#include <map>

/** --------------------------------------------------------------------------------------------------------------- **/

class people : public QWidget {

    Q_OBJECT

public:

    people(QWidget * parent = 0) : QWidget(parent) {}

    ~people() {}

    QString address, homePage, work, first, last, nick, recordID, UID;
    QIcon thumbnail;
    QPixmap picture;

    std::vector<QString> cell, home;
    std::multimap<QString, QString> infos;

    double birth, anniversary;
    int peopleID;
    bool correctPicture;
};

/** --------------------------------------------------------------------------------------------------------------- **/

#endif // PEOPLE

/** --------------------------------------------------------------------------------------------------------------- **/

