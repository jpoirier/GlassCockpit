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

#include "GeographicHash.h"
#include <math.h>

namespace OpenGC {
/* Longitude:  -180------------0------------180
 * Bin:           0           90            180
 *
 * Lattitude: Bin:
 *    90       90
 *    |
 *    |
 *    0        45
 *    |
 *    |
 *   -90       0
 */
GeographicHash::GeoListType& GeographicHash::GetListAtLatLon(double lat, double lon) {
    int latBin = (int)floor(45 + lat/2);
    int lonBin = (int)floor(90 + lon/2);
    return m_GeoHash[latBin][lonBin];
}

void GeographicHash::InsertGeographicObject(GeographicObject* pObj) {
    GetListAtLatLon(pObj->GetDegreeLat(), pObj->GetDegreeLon()).push_back(pObj);
}

void GeographicHash::InsertGeographicList(GeographicObjectList* pList) {
    for (GeoListType::iterator it = pList->begin(); it != pList->end(); ++it) {
        this->InsertGeographicObject(*it);
    }
}

} // end namespace OpenGC

