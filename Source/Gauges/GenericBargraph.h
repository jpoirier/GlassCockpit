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

#ifndef GenericBargraph_H
#define GenericBargraph_H

#include "GaugeComponent.h"

namespace OpenGC {

typedef float (AirframeDataContainer::*AirframeMemFn)();

class GenericBargraph : public GaugeComponent {
    public:
        GenericBargraph();
        virtual ~GenericBargraph();
        void Render();

        /** Set a function pointer to the Airframe->Get__() function */
        void SetDataSource(AirframeMemFn fn) {m_DataFn = fn; }

        /** Set the range of values displayed on this gauge */
        void SetMinMax(double min, double max) {m_Min = min; m_Max = max; }

        /** Set the thresholds which if the value drops below the colour will change */
        void SetColourRanges(double maxYellow, double maxRed) {m_MaxYellow = maxYellow; m_MaxRed = maxRed; }

    protected:
        int m_Font;
        AirframeMemFn m_DataFn;
        double m_Min, m_Max;
        double m_MaxYellow, m_MaxRed;
};

} // end namespace OpenGC

#endif
