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

#ifndef DataSource_h
#define DataSource_h

#include "AirframeDataContainer.h"

namespace OpenGC
{

class DataSource
{
	public:
		
		DataSource();
		virtual ~DataSource();

		/** Initialize the data to a default value*/
		void InitializeData();

		/** Called by the base AppObject after all the init parameters
		 * have been complete. This should open the connection to the sim
		 */
		virtual bool Open();

		/** Called by the render window during idle processing
		 * This function is the one and only place where OpenGC
		 * should acquire data from the sim
		 */
		virtual bool OnIdle();

		/** Get access to airframe data */
		AirframeDataContainer* GetAirframe() { return m_Airframe; }

	protected:

		/** Data that describes the airframe (alt, heading, control surfaces, etc.) */
		AirframeDataContainer* m_Airframe;
};

} // end namespace OpenGC

#endif

