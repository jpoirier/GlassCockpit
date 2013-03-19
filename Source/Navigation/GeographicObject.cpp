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

#include <cmath>
#include "GeographicObject.h"
#include "Constants.h"

namespace OpenGC
{

GeographicObject::GeographicObject()
{
	m_AltitudeMeters=0.0;
	m_DegreeLat=0.0;
	m_DegreeLon=0.0;
}

GeographicObject::~GeographicObject()
{

}

void GeographicObject::LatLonToMercator(double lat, double lon, double &northing, double &easting)
{
	easting = EARTH_RADIUS * (lon * DEG_TO_RAD);
	northing = EARTH_RADIUS * log(tan(M_PI / 4.0 + (lat * DEG_TO_RAD) / 2.0));
}

} // end namespace OpenGC

