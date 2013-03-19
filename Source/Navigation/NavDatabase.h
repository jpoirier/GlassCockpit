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

/**
 * NavDatabase is the container that stores all other nav information
 * used by OpenGC.
 */

#ifndef NavDatabase_h
#define NavDatabase_h

#include <string>
#include "NavaidList.h"
#include "AirportList.h"
#include "WaypointList.h"
#include "FlightCourse.h"
#include "GeographicHash.h"

namespace OpenGC {

class NavDatabase {
    public:
        NavDatabase();
        virtual ~NavDatabase();

        /** Load the nav data */
        void InitDatabase();

        /** Get the hashed navaid list */
        GeographicHash* GetNavaidHash() {return m_NavaidHash;}

        /** Get the hashed airport list */
        GeographicHash* GetAirportHash() {return m_AirportHash;}

        /** Get the waypoint list */
        WaypointList* GetWaypointList() {return m_WaypointList;}

        /** Get the flight path */
        FlightCourse* GetFlightCourse() {return m_FlightCourse;}

    private:
        /** The flight path/course */
        FlightCourse *m_FlightCourse;

        /** A list of all waypoints */
        WaypointList *m_WaypointList;

        /** Airport list */
        AirportList *m_AirportList;

        /** Airport list hashed by lat/lon */
        GeographicHash *m_AirportHash;

        /** Navaid list */
        NavaidList *m_NavaidList;

        /** Navaid list hashed by lat/lon */
        GeographicHash *m_NavaidHash;
};

} // end namespace OpenGC

#endif

