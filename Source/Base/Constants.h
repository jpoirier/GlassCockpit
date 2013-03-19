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
 * Global configuration definitions for OpenGC for Albatross as well as 
 * a configuration manager class.
 */

#ifndef Constants_h
#define Constants_h

#include <math.h>

namespace OpenGC {

// Numerical Constants and global Configuration Constants
const double DEG_TO_RAD = (M_PI / 180.0);	// degrees to radians multiplier
const double RAD_TO_DEG = (180.0 / M_PI);	// radians to degrees multiplier
const double METER_PER_NM = 1852.0;			// meters per nautical mile
const double MS_TO_KNOTS  = 1.94384449;		// meters per second to knots
const double METERS_TO_FEET = 3.2808399;	// meters to feet
const double EARTH_RADIUS  = 6371000.0;		// approx. radius of the earth in meters

// OpenGL Colours
#define COLOUR_YELLOW() glColor3ub(0,0,0) // FIXME

} // end namespace OpenGC

#endif
