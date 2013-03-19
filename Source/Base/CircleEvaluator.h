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
 * CircleEvaluator generates a series of points which lie on the
 * perimeter of the circle. The circle is evaluated as an arc,
 * given a start and end point in degrees. Degrees are defined as 0=360 being
 * up, 90 degrees right, etc.
 */

#ifndef CircleEvaluator_h
#define CircleEvaluator_h

#include "GLHeaders.h"

namespace OpenGC
{

class CircleEvaluator  
{

	public:

		CircleEvaluator();
		virtual ~CircleEvaluator();

		/** Sets the radius of the circle in physical units */
		void SetRadius(double radius);

		/** Defines the "coarseness" of the circle (degree spacing of GL_POINTS) */
		void SetDegreesPerPoint(double degreesPerPoint);

		/** Defines the start and end of the arc in degrees */
		void SetArcStartEnd(double startArc, double endArc);

		/** Defines the center of the circle in physical units */
		void SetOrigin(double x, double y);

		/** Add specified vertex to vertex array at the current position */
		void AddVertex(float x, float y);

		/** Evaluate the circle, generating points into vertex cache */
		void Evaluate();

		/** Renders vertex cache in specified mode */
		void Render(GLenum mode);

		/** Clears vertex cache */
		void ResetVertices();

	protected:

		/** The origin (center) of the circle */
		double m_XOrigin, m_YOrigin;

		/** The radius of the arc/circle */
		double m_Radius;

		/** The start and end of the arc in degrees */
		double m_StartArcDegrees, m_EndArcDegrees;

		/** How many degrees to move before generating a new point */
		double m_DegreesPerPoint;

		/** Used to hold GL generated vertices */
		float *m_Vertices;

		/** Current index into vertex array */
		unsigned int m_VertexIdx;
};

} // end namespace OpenGC

#endif
