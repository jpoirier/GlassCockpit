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

#ifndef MarkedDial_H
#define MarkedDial_H

#include "GaugeComponent.h"

namespace OpenGC {

typedef float (AirframeDataContainer::*AirframeMemFn)();

class MarkedDial : public GaugeComponent {
    public:
        MarkedDial();
        virtual ~MarkedDial();
        void Render();
        void SetDataSource(AirframeMemFn fn) {m_DataFn = fn;}
        void SetMinMax(double min, double max) {m_Min = min; m_Max = max;}
        void SetTickSpacing(double spacing) {m_TickSpacing = spacing;}
        void SetTickDivisor(double divisor) {m_TickDivisor = divisor;}

    protected:
        int m_Font;
        AirframeMemFn m_DataFn;
        double m_Min, m_Max, m_TickSpacing, m_TickDivisor;
};

}

#endif
