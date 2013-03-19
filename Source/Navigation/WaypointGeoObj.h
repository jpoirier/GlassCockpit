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

#ifndef WaypointGeoObj_h
#define WaypointGeoObj_h

#include "GeographicObject.h"

namespace OpenGC
{

class WaypointGeoObj : public GeographicObject
{
public:
	WaypointGeoObj();
	virtual ~WaypointGeoObj();

	void SetStyle(int style) { m_Style = style; }

	enum {STYLE_FUNDAMENTAL, STYLE_INTERP};

protected:
	int m_Style;
};

} // end namespace OpenGC

#endif
