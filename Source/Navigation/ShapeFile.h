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

#ifndef ShapeFile_h
#define ShapeFile_h

#include <vector>
#include <string>

namespace OpenGC {

class ShapeFile {
public:
    ShapeFile(const std::string& fileName);
    void Draw();

private:
    typedef struct { double dX; double dY; } Point2D;
    typedef std::vector<Point2D> LineString2D;
    typedef std::vector<Point2D> Polygon2D;

    float *m_Points; unsigned int m_PointsCount; // holds coordinates of Point Shapefile
    std::vector<LineString2D> m_Lines; // holds coordinates of Line Shapefile
    std::vector<Polygon2D> m_Polygons; // holds coordinates of Polygon Shapefile

    struct { float minX; float minY; float maxX; float maxY; } m_BoundingBox; // bounding box of shapefile
};

} // end namespace OpenGC

#endif // ShapeFile_h
