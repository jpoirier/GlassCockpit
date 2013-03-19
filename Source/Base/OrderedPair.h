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
 * Defines an ordered pair structure templated over data type (int, double, etc.)
 * and associated mathematical operations. All members are public to allow easy
 * access
 */

#ifndef OrderedPair_h
#define OrderedPair_h

namespace OpenGC
{

template<typename TDataType>
class OrderedPair
{

	public:

		OrderedPair() {x=0; y=0;}
		OrderedPair(char *init);
		~OrderedPair() {};

		/** X coordinate */
		TDataType x;

		/** Y coordinate */
		TDataType y;
};

} // end namespace OpenGC

#endif
