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

#include "manager.hpp"

/** --------------------------------------------------------------------------------------------------------------- **/

// REMPLACER

// QDir().homePath() + "/Documents/Dropbox/iPhoneManager5/iManager"

// PAR

// QCoreApplication::applicationDirPath()

int main(int argc, char ** argv)
{
    QString appName("iPhoneManager 5"), orgName("CrazyShrimp"), appPath(QDir().homePath() + "/Documents/Dropbox/iPhoneManager5/iManager");
    QApplication app(argc, argv);
    app.setApplicationName(appName);
    app.setApplicationVersion("5");
    app.setOrganizationName(orgName);
    app.setWindowIcon(QIcon(appPath + "/utils/icons/logo.png"));
    app.setQuitOnLastWindowClosed(true);

    Manager iM(appPath, appName, orgName);
    iM.setWindowTitle(appName);
    iM.setFixedSize(670, 552);
    iM.show();

    return app.exec();
}

/** --------------------------------------------------------------------------------------------------------------- **/
