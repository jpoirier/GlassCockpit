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

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "WaypointList.h"
#include "WaypointGeoObj.h"
#include "Constants.h"

namespace OpenGC
{

using namespace std;

WaypointList::WaypointList()
{

}

WaypointList::~WaypointList()
{

}

bool WaypointList::LoadData(const string& fileName)
{

	// Buffer used to read from file
	string lineData;

	// Open the input file for reading
	ifstream inputFile( fileName.c_str() );

	// Test to see if the file is open
	if( inputFile.is_open() == 0 )
	{
		printf("Error: unable to load the waypoint database file.\n");
		return false;
	}

	// Ok, file is open, process it
	while (inputFile.eof() != 1)
	{
		// Extract a line
		getline(inputFile, lineData);
		
		// Ignore blank lines
		if (lineData == "" || (lineData.size() == 1 && isspace(lineData[0]))) // FIXME need python string.strip() operation...
			continue;
		
		// Ignore comments (lines starting with "#")
		if (lineData[0] == '#')
			continue;

		// Variables to parse into
		double lat, lon, elev;
		int waypointStyle;
		string id;

		// Temp waypoint storage
		WaypointGeoObj* pWaypoint;

		// Input stream for parsing
		std::istringstream inputStream(lineData);

		// Parse and store the input line
		inputStream >> lat >> lon >> elev >> waypointStyle >> id;
		pWaypoint = new WaypointGeoObj();
		pWaypoint->SetDegreeLat(lat);
		pWaypoint->SetDegreeLon(lon);
		pWaypoint->SetAltitudeMeters(elev / METERS_TO_FEET);
		pWaypoint->SetStyle(waypointStyle);
		pWaypoint->SetIdentification(id);
		this->push_back(pWaypoint);
	}

	// Everything worked ok
	return true;
}

} // end namespace OpenGC

