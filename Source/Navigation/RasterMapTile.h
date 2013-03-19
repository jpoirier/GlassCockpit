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

#ifndef RasterMapTile_h
#define RasterMapTile_h

/** Represents one tile in a raster map.
 */

namespace OpenGC {

class RasterMapTile
{
public:
	RasterMapTile(unsigned char *image, unsigned int width, unsigned int height);
	
	unsigned char *Image() { return m_Image; }
	unsigned int Width() { return m_Width; }
	unsigned int Height() { return m_Height; }

private:
	unsigned char *m_Image;
	unsigned int m_Width, m_Height;
};
	
} // end namespace OpenGC

#endif // RasterMapTile_h
