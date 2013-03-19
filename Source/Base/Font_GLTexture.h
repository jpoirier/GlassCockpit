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

#ifndef Font_GLTexture_H
#define Font_GLTexture_H

#include "GLHeaders.h"

class Font_FileStore;

/** This is a minimal, lightweight reimplementation of FTTextureFont from
 *  the FTGL library, for use on OpenGL ES, e.g. on the iPhone. It only
 *  provides the functionality required by OpenGC. 
 *
 *  We acheive this reduction in CPU and memory required by prerendering
 *  the font to a bitmap image on the development host, where we have access
 *  to the full stack, in particular libfreetype2.
 *
 *  Only 7-bit ASCII is supported, no unicode.
 */
class Font_GLTexture
{
public:
	Font_GLTexture(const char* filename);
	~Font_GLTexture();
	void FaceSize(float size);
	void Render(const char* str);
	float Advance(const char* str);
	int Error();

private:
	Font_FileStore *m_Store;
	GLuint texName;
	
	void CheckOrCreateTexture();
};

#endif
