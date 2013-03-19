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

#ifndef GeographicObjectList_h
#define GeographicObjectList_h

#include <list>
#include <string>
#include "GeographicObject.h"

namespace OpenGC
{

class GeographicObjectList : public std::list<GeographicObject*>
{
	public:

		GeographicObjectList();
		virtual ~GeographicObjectList();

		/** Initialize the object list - this consists of loading the data and 
		 * computing positions in coordinates other than lat / lon. The data
		 * loading stage should be overridden when implementing a derived 
		 * class. Will automatically call either LoadDataBin or LoadDataAscii
		 * depending on extension of filename (.bin->binary, .dat->ASCII */
		bool InitializeList(const string& filename);

		/** Read binary or ASCII file that contains data, returns true if
		 * successful,  else false. */
		virtual bool LoadData(const string& fileName) { return false; };

		/** Computes additional coordinate positions for the objects in the 
		 * list. This is called by InitializeList(). */
		void ComputeAdditionalCoordinates();
};

} // end namespace OpenGC

#endif

