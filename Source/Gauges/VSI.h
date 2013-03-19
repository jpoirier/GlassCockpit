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
 * Boeing 777 vertical speed indicator
 */

#ifndef VSI_h
#define VSI_h

#include "GaugeComponent.h"

namespace OpenGC
{

class VSI : public GaugeComponent  
{
	public:

		VSI();
		virtual ~VSI();

		/** Overloaded render function */
		void Render();

	protected:

		/** Routine to convert an altitude to needle position */
		double VSpeedToNeedle(double vspd);

		/** The font number provided to us by the font manager */
		int m_Font;

		/** Centered position of needle in physical coordinates */
		double m_NeedleCenter;

		/** Max positive or negative deflection of needle in physical coordinates */
		double m_MaxNeedleDeflection;

};

} // end namespace OpenGC

#endif
