/*=========================================================================
    OpenGC - The Open Source Glass Cockpit Project

    Copyright (c) 2001-2004 Damion Shelton
    Copyright (c) 2005-2010 Hugo Vincent <hugo.vincent@gmail.com>
    Copyright (c) 2008-2010 Yuriy Kinakh <ykinakh@gmail.com>
    Copyright (c) 2008-2010 Bohdan Mushkevych <mushkevych@gmail.com>
    All rights reserved.

    This branch of OpenGC is developed within "Albatross UAV Project"
    http://gitorious.org/albatross/

    This software is distributed WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See Copyright.txt or http://opengc.sourceforge.net/licensing.html for more information.
=========================================================================*/

#include "NavDatabase.h"
#include "BinaryNavData.h"
#include "Debug.h"
#include "Globals.h"
#include <stdio.h>
#include <sys/stat.h>

namespace OpenGC {

NavDatabase::NavDatabase() {
    m_NavaidList = 0;
    m_NavaidHash = 0;
    m_AirportList = 0;
    m_AirportHash = 0;
    m_WaypointList = 0;
    m_FlightCourse = new FlightCourse();
}

NavDatabase::~NavDatabase() {
    if (m_NavaidList != 0) {
        delete m_NavaidList;
    }
    if (m_NavaidHash != 0) {
        delete m_NavaidHash;
    }
    if (m_AirportList != 0) {
        delete m_AirportList;
    }
    if (m_AirportHash != 0) {
        delete m_AirportHash;
    }
    if (m_WaypointList != 0) {
        delete m_WaypointList;
    }
    if (m_FlightCourse != 0) {
        delete m_FlightCourse;
    }
}

bool fileExists(const string& filename) {
    struct stat stFileInfo;
    if (stat(filename.c_str(), &stFileInfo) == 0) {
        return true;
    } else {
        return false;
    }
}

void NavDatabase::InitDatabase() {
    const string& pathToNav = globals->m_PrefManager->GetPrefS("PathToData") + "Navigation/";
    const string& pathToWritableNav = globals->m_PrefManager->GetPrefS("PathToCaches") + "Navigation/";

    // Check for cached binary copies of nav data otherwise convert and cache
    if (!fileExists(pathToWritableNav + "nav_dat.bin")) {
        LogPrintf("Generating binary cache of navaid data...\n");
        BinaryNavData::ConvertNavaidData(pathToNav + "nav.dat", pathToWritableNav + "nav_dat.bin");
    }
    if (!fileExists(pathToWritableNav + "apt_dat.bin")) {
        LogPrintf("Generating binary cache of airport data...\n");
        BinaryNavData::ConvertAirportData(pathToNav + "apt.dat", pathToWritableNav + "apt_dat.bin");
    }

    printf("NavDatabase: Loading navigation database... ");
    fflush(stdout);

    // Load and hash NavAid (binary) database
    m_NavaidList = new NavaidList;
    m_NavaidList->InitializeList(pathToWritableNav + "nav_dat.bin");
    m_NavaidHash = new GeographicHash;
    m_NavaidHash->InsertGeographicList(m_NavaidList);

    // Load and hash Airport (binary) database
    m_AirportList = new AirportList;
    m_AirportList->InitializeList(pathToWritableNav + "apt_dat.bin");
    m_AirportHash = new GeographicHash;
    m_AirportHash->InsertGeographicList(m_AirportList);

    // Load Waypoint database
    m_WaypointList = new WaypointList;
    m_WaypointList->InitializeList(pathToNav + "waypoint.dat");

    // Load and hash Map database
    // FIXME actually load the map shapes database

    printf("Done\nNavDatabase: Navigation database contains:\n");
    printf("\t%i NavAids\n\t%i Airports\n\t%i Waypoints\n\t%i Map shapes\n",
            (int)m_NavaidList->size(), (int)m_AirportList->size(),
            (int)m_WaypointList->size(), 0 /* m_MapShapeList->size() */);
}

} // end namespace OpenGC

