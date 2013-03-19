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

#ifndef PieDial_H
#define PieDial_H

#include "MarkedDial.h"
#include "CircleEvaluator.h"

namespace OpenGC {

typedef float (AirframeDataContainer::*AirframeMemFn)();

class PieDial : public MarkedDial {
    public:
        PieDial();
        virtual ~PieDial();

        void Render();

        /** Set a function pointer to the Airframe->Get__() function */
        void SetDataSource(AirframeMemFn fn) {m_DataFn = fn; }

        /** Set the range of values displayed on this gauge */
        void SetMinMax(double min, double max) {m_Min = min; m_Max = max; }

        /** Set the thresholds which if the value exceeds, the colour will change */
        void SetColourRanges(double minYellow, double minRed) {m_MinYellow = minYellow; m_MinRed = minRed; }

    protected:
        /** Used from Render() to draw the dials arc.
         * Separate so it can be overloaded to draw the arc differently,
         * e.g. for the Tachometer. Drawing is done in a coordinate system
         * with the origin at the center of the dial. */
        virtual void RenderArc(CircleEvaluator *circ);

        /** Used from Render() to draw the dials ticks.
         * See RenderArc() for details. */
        virtual void RenderTicks(CircleEvaluator *circ);

        int m_Font;
        AirframeMemFn m_DataFn;
        double m_Min, m_Max;
        double m_MinYellow, m_MinRed;

        /** Drawing options */
        static const double R;
        static const double minDegrees;
        static const double maxDegrees;
};

} // end namespace OpenGC

#endif
