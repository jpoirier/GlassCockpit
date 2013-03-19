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
#include "NavaidList.h"
#include "NavaidGeoObj.h"
#include "Constants.h"
#include "BinaryNavData.h"
#include "Debug.h"

namespace OpenGC
{

using namespace std;

NavaidList::NavaidList()
{

}

NavaidList::~NavaidList()
{

}

bool NavaidList::LoadData(const string& fileName)
{
	ifstream file(fileName.c_str(), ios::binary);
	Assert(file.is_open(), "can't read navaid database");

	// The struct that is read in for each navaid
	BinaryNavData::NavaidData *nav = new BinaryNavData::NavaidData;

	// Now iterate over the structs in the file
	while (file.eof() != 1)
	{
		file.read((char*)nav, sizeof(BinaryNavData::NavaidData));

		// Ensure ID string is null terminated
		if (nav->id_length >= MAX_NAV_ID_LENGTH)
		{
			nav->id[MAX_NAV_ID_LENGTH] = 0;
		}
		else
		{
			nav->id[nav->id_length] = 0;
		}
		
		// Create the NavaidGeoObj and fill out it's fields
		NavaidGeoObj* pNavaid = new NavaidGeoObj();
		pNavaid->SetAltitudeMeters(nav->elev);
		pNavaid->SetIdentification(nav->id);
		pNavaid->SetDegreeLat(nav->lat);
		pNavaid->SetDegreeLon(nav->lon);
		// FIXME other info

		// Now add the navaid to the list
		this->push_back(pNavaid);
	}
	delete nav;
	return true;
}

} // end namespace OpenGC

