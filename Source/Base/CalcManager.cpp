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

#include <math.h>

#include "Globals.h"
#include "CalcManager.h"

namespace OpenGC {

CalcManager::CalcManager()
{
}

CalcManager::~CalcManager()
{
}

void CalcManager::InitFromXMLNode(XMLNode calcNode)
{
}
	
bool CalcManager::Calculate()
{
	AirframeDataContainer* data = globals->m_DataSource->GetAirframe();
	
	// FIXME this isn't really the right place for this...
	double lat = data->GetLatitude();
	double lon = data->GetLongitude();
	CoursePoint p = CoursePoint(lat, lon);
	globals->m_NavDatabase->GetFlightCourse()->push_back(p);
	
	return false;
}
	
} // end namespace OpenGC
