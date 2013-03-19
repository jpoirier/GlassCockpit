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

#ifndef Debug_H
#define Debug_H

#include <stdio.h>
#include <stdlib.h>

// Check host platform
#if defined(__GNUC__) && ( defined(__APPLE_CPP__) || defined(__APPLE_CC__) )

#include <TargetConditionals.h>

#if defined(TARGET_OS_MAC) && TARGET_OS_MAC
#define MACOSX
#endif

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#define IPHONE
#endif

#endif

// Global Debug flag
#define PROJ_DEBUG 1

// LogPrintf Macro
#ifdef PROJ_DEBUG
#define LogPrintf(...) { fprintf(stderr,__VA_ARGS__); }
#else
#define LogPrintf(...) ()
#endif

// Assert Macro
#ifdef __STRING
#define Assert(x, msg) { if (!(x)) { LogPrintf("\n%s:%d: Assertion \"%s\" failed, %s\n", __FILE__, __LINE__, __STRING(x), msg); abort(); } }
#else
#define Assert(x, msg) { if (!(x)) { LogPrintf("\n%s:%d: Assertion failed, %s\n", __FILE__, __LINE__, msg); abort(); } }
#endif

// Check Macro
#ifdef __STRING
#define Check(x) { if (!(x)) { LogPrintf("\n%s:%d: Check \"%s\" failed\n", __FILE__, __LINE__, __STRING(x)); abort(); } }
#else
#define Check(x) { if (!(x)) { LogPrintf("\n%s:%d: Check failed\n", __FILE__, __LINE__); abort(); } }
#endif

// OpenGL error checking
#define GLassert() Assert(glGetError() == GL_NO_ERROR, "OpenGL error occurred")

#endif // ifdnef Debug_H

