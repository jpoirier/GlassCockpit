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
 * Responsible for creating a global AppObject (the application), processing
 * the command line arguments, setting some run-time configuration options
 * from the XML file, and starting the application.
 */

#include <FL/Fl.H>
#include <unistd.h>
#include <string.h>

#include "Debug.h"
#include "AppObject.h"
#include "Globals.h"
#include "Messageable.h"
#include "XMLParser.h"

#define DEFAULT_XML_FILE		(char*)"Data/Default.xml"
#define PREFERENCES_XML_FILE	(char*)"Data/Preferences.xml"

using namespace OpenGC;

/// Create the Globals object
Globals *OpenGC::globals;

/// Construct the one and only App Object
AppObject *theApp;

/** Print usage information */
void usage()
{
	LogPrintf("usage: OpenGC [config.xml]\nIf no XML configuration file"
		   "is provided Data/Default.xml is used.\n");
}

/** Global idle function to handle app updates */
void GlobalIdle(void *)
{
	theApp->IdleFunction();
	Fl::repeat_timeout(globals->m_PrefManager->GetPrefD(
				"AppUpdateRate"), GlobalIdle);
}

/** Main entry point for the application */
int main(int argc, char* argv[])
{	
	// Check the command line arguments
	char *xmlFileName = DEFAULT_XML_FILE;
	if (argc > 2)
	{
		usage();
		return 1;
	}
	else if (argc == 2)
	{
		// Check the file exists
		FILE *f = fopen(argv[1], "r");
		if (f == NULL) 
		{
			usage();
			return 1;
		}
		else
		{
			xmlFileName = argv[1];
		}
	}
	
	// Construct the application
	OpenGC::globals = new Globals();
	theApp= new AppObject();
	
	// Initialise preferences manager
	globals->m_PrefManager->InitPreferences(PREFERENCES_XML_FILE);
	
	// Read the XML file and do some basic checks about its contents
	XMLParser parser;
	Assert(parser.ReadFile(xmlFileName), "unable to read XML file");
	Check(parser.HasNode("/"));
	Assert(parser.HasNode("/Window"), "invalid XML, no Window node");
	Assert(parser.HasNode("/DataSource"), "invalid XML, no DataSource node");
	
	// Set the user-defined (in XML file) application preferences
	if (parser.HasNode("/Preferences"))
	{
		globals->m_PrefManager->SetPrefsFromXML(parser.GetNode("/Preferences"));
	}

	// Set RasterMaps path
	globals->m_RasterMapManager->SetCachePath(RasterMapManager::RMM_CACHE_MGMAPS, 
			globals->m_PrefManager->GetPrefS("PathToData") + "MGMapsCache", "GoogleTer");

	// FIXME debug:
	globals->m_PrefManager->PrintAll();

	// Set the update rate in nominal seconds per frame
	Fl::add_timeout(globals->m_PrefManager->GetPrefD(
				"AppUpdateRate"), GlobalIdle);

	// Run up the application
	int retval;
	XMLNode rootNode = parser.GetNode("/");
	if (theApp->Go(rootNode)) {
		LogPrintf("Done, exiting cleanly.\n");
		retval = 0;
	}
	else {
		LogPrintf("Error, exiting.\n");
		retval = 1;
	}

	// Clean up
	delete theApp;
	delete globals;

	return retval;
}

