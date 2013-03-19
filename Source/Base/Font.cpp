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

#include "GLHeaders.h"
#include <stdio.h>

#include "Font.h"

#define FONT_TEXTURE_SIZE       24.0
#define FONT_TEXTURE_CROSSOVER  4.0

namespace OpenGC {

Font::Font() {
    // Default is a unit sized font
    m_Size.x = 1.0;
    m_Size.y = 1.0;
    m_TextureFont = NULL;
    m_RightAligned = false;
}

Font::~Font() {
    if(m_TextureFont != 0) {
        delete m_TextureFont;
    }
    m_TextureFont = 0;
}

void Font::SetSize(double x, double y) {
    m_Size.x = x;
    m_Size.y = y;
}

void Font::Print(double x, double y, const char *string) {
    Check(m_TextureFont != NULL);

    // Save the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    // Set position and size
    glTranslated(x, y, 0);
    glScaled(1.35 / FONT_TEXTURE_SIZE * m_Size.x, 1.35 / FONT_TEXTURE_SIZE * m_Size.y, 1);
    if (m_RightAligned) {
        // We offset by the width of the text, so the right hand edge of the string is at the provided coordinates.
        glTranslated(-1.0 * m_TextureFont->Advance(string), 0, 0);
    }
#ifdef USE_MIPMAPPING_QUESTION_MARK_FIXME
    // Hint the font to use a texture of appropriate quality for the size we're rendering at
    if (max(m_Size.x, m_Size.y) < FONT_TEXTURE_CROSSOVER) {
        m_TextureFont->Hint_LowerResolution(true);
    } else {
        m_TextureFont->Hint_LowerResolution(false);
    }
#endif

    m_TextureFont->Render(string);

    // Restore modelview matrix
    glPopMatrix();
}

bool Font::LoadFont(const string& name) {
    m_Name = name;

    // Open the the font in texture mode
    m_TextureFont = new FTTextureFont(name.c_str());
    Assert(m_TextureFont && !(m_TextureFont->Error()), "could not create font object");

    // The initial face size is large so that font sizing will work correctly later on
    m_TextureFont->FaceSize(FONT_TEXTURE_SIZE);

    return true;
}

} // end namespace OpenGC
