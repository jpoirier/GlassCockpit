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

#ifndef Font_FileStore_H
#define Font_FileStore_H

#include <string>
#include "GLHeaders.h"

class Font_FileStore
{
public:
#ifdef USE_FREETYPE2
	static Font_FileStore *CreateFromTTF(const std::string& ttfFilename);
#endif
	
	Font_FileStore(const std::string& glfontFilename); // Convenience constructor for deserialize from file
	~Font_FileStore();

	void DeserializeFromFile(const std::string& glfontFilename);
	void SerializeToFile(const std::string& glfontFilename) const;
	
	// Methods for accessing the data
	
	GLfloat Advance(char i, char j); // for character i (followed by j, needed for kerning); in texture UV coordinates
	GLfloat *TextureCoordsForChar(char glyph);
	GLfloat *VertexCoordsForChar(char glyph);
	GLubyte *TextureBitmap(unsigned int *texWidth, unsigned int *texHeight, bool *safeToFree); // if safeToFree is set, you must free the bitmap
	
	float FaceSize() { return store->faceSize; }
	
private:
	
	Font_FileStore() : store(NULL) {} // used to create from TrueType file, for serialization
	
	class Glyph
	{
	public:
		char character;
		short xOffset, yOffset, width, height;
		float advance;
	};
	
	class DiskFormat
	{
	public:
		float faceSize;
		
		// Glyph info
		char firstGlyph;
		short numGlyphs;
		
		// Texture format info
		short rows, columns;
		short glyphWidth, glyphHeight; // maximum size of a glyph, actual size may be smaller
		short texWidth, texHeight;
		
		// Array of glyphs (length = numGlyphs)
		Glyph *glyphs;

		// Array of kerning pairs (advance for character pair i,j indexed is by [j * numGlyphs + i])
		float *kerningTable;

		// Texture bitmap (length = texWidth * texHeight). Pixel format is 8-bit alpha-only.
		GLubyte *bitmap;

		DiskFormat() : glyphs(NULL), kerningTable(NULL), bitmap(NULL) {}
		~DiskFormat();
	};
	
	inline void TextureCellForCharacter(int character, int *x, int *y)
	{
		*x = character % store->rows;
		*y = character / store->rows;
	}

	static void CheckBinaryFormatAssumptions();
	
	DiskFormat *store;
	GLfloat texCoords[8], vertexCoords[8]; // four (x,y) coordinates
};

#endif
