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

#ifndef FGDataSource_h
#define FGDataSource_h

#include "DataSource.h"

#include <string>
//#include <plib/netSocket.h>
#include "FlightGear_Protocol.h"

using namespace std;

namespace OpenGC
{

/** This is the actual DataSource */
class FGDataSource : public DataSource
{
	public:

		FGDataSource();  
		virtual ~FGDataSource();

		// Open the network connection
		bool Open();

		// The "money" function
		bool OnIdle(); 

	protected:

		// Get data from FlightGear
		bool GetData();

		// Flight model data received from FlightGear
		FGData *m_FDM;

		// The socket
//		netSocket m_Socket;

		// The host and port we're receiving on
		string m_Host;
		int m_ReceivePort;

		// Are we connected to Flightgear?
		bool m_ValidConnection;

		// The message received from Flightgear
		char *m_Buffer;

		// A temporary buffer used in the receive process
		char *m_TempMsg;

		// Maximum length of the buffer
		int m_BufferLength;
};

} // end namespace OpenGC


#endif
