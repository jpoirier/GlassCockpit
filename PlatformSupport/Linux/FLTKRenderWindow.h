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
 * FLTK implementation of the OpenGC render window
 */

#ifndef FLTKRenderWindow_h
#define FLTKRenderWindow_h

#include <FL/Fl_Gl_Window.H>
#include "RenderWindow.h"

namespace OpenGC
{

class FLTKRenderWindow : public Fl_Gl_Window, public RenderWindow
{
	public:

		/** Constructor follows FLTK syntax */
		FLTKRenderWindow(int X, int Y, int W, int H, const char *L = 0);

		/** Yawn, a destructor */
		~FLTKRenderWindow();

		/** FL rendering callback */
		void draw();

		/**  FL event handling callback */
		int handle(int);

		/**  Render the entire window */
		void Render();
};

} // end namespace OpenGC

#endif
