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
 * GaugeComponents are the most "primitive" building block in the
 * OpenGC design scheme. Gauges are composed of a number of
 * GaugeComponents, each of which is capable of positioning and
 * drawing itself.
 *
 * By breaking a gauge into multiple GaugeComponents, recycling
 * of code is encouraged between different gauge designs.
 */

#ifndef GaugeComponent_h
#define GaugeComponent_h

#include "FontManager.h"
#include "DataSource.h"
#include "OrderedPair.h"
#include "RenderObject.h"

namespace OpenGC
{

class GaugeComponent: public RenderObject
{
	public:
		GaugeComponent();
		virtual ~GaugeComponent();

		/** Render the gauge component */
		virtual void Render();

		/** Return true if the click is inside the gauge component */
		bool ClickTest(int button, int state, int x, int y);

		/** Set to true to have an opaque background */
		void SetOpaque(bool opaque) { m_Opaque = opaque; }

	private:
		bool m_Opaque;
};

} // end namespace OpenGC

#endif

