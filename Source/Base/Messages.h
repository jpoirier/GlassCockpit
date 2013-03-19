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
 * Defines messages which can be triggered by mouse clicks, key presses, etc.
 */

#ifndef Messages_h
#define Messages_h

namespace OpenGC
{

enum Message
{
	/** Nav zoom in and out */
	MSG_NAV_ZOOM_DECREASE,
	MSG_NAV_ZOOM_INCREASE,

	/** Application control messages */
	MSG_APP_QUIT
};

} // end namespace OpenGC

#endif
