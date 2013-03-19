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
 * This header addresses the various ways that OpenGL headers
 * are handled on different systems
 */

#ifndef _WIN32
    // Non windows, doesn't require Windows header to work correctly
    #ifndef __gl_h_
        #ifdef __APPLE_CC__
            #include <OpenGL/gl.h>
            #include <OpenGL/glu.h>
        #else
            #include <GL/gl.h>
            #include <GL/glu.h>
        #endif
    #endif

    // Required for compatibility with glext.h style function definitions
    #ifndef APIENTRY
        #define APIENTRY
    #endif

#else   // Win32 Platform

    #ifdef _WIN32
        #define WIN32_LEAN_AND_MEAN
        #include <windows.h>
    #endif

    #include <GL/gl.h>
    #include <GL/glu.h>

#endif  //   WIN32
