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

#include <math.h>

#include "GLHeaders.h"
#include "Tachometer.h"
#include "CircleEvaluator.h"
#include "Constants.h"

#define CALL_MEMBER_FN(object,ptrToMember)  ((object)->*(ptrToMember))

namespace OpenGC {

Tachometer::Tachometer() {
    m_DataFn = &AirframeDataContainer::GetEngine_RPM;
    m_Min = 0.0;
    m_Max = 9000.0;
    m_MinYellow = 6000.0;
    m_MinRed = 8000.0;
}

Tachometer::~Tachometer() {
}

void Tachometer::Render() {
    PieDial::Render();
}

// These Render___() Functions are overloaded to change the way the dial appears

void Tachometer::RenderTicks(CircleEvaluator *circ) {
    // yellow stripe
    double percentagey = m_MinYellow / (m_Max - m_Min) ;
    double degreeyellow = minDegrees + ((maxDegrees - minDegrees) * percentagey);
    glColor3ub(247, 231, 8);
    double radians = degreeyellow * DEG_TO_RAD;
    const float vertices[] = {
        R * sin(radians), R * cos(radians),
        (R + 4) * sin(radians), (R + 4) * cos(radians)
    };
    glVertexPointer(2, GL_FLOAT, 0, &vertices);
    glDrawArrays(GL_LINE_STRIP, 0, 2);

    // red stripe
    double percentager = m_MinRed / (m_Max - m_Min) ;
    double degreered =  minDegrees + ((maxDegrees - minDegrees) * percentager);
    radians = degreered * DEG_TO_RAD;
    glColor3ub(255, 0, 0);
    const float vertices2[] = {
        R * sin(radians), R * cos(radians),
        (R + 4) * sin(radians), (R + 5) * cos(radians)
    };
    glVertexPointer(2, GL_FLOAT, 0, &vertices2);
    glDrawArrays(GL_LINE_STRIP, 0, 2);
}

void Tachometer::RenderArc(CircleEvaluator *circ) {
    // white partial circle
    glColor3ub(255, 255, 255);
    circ->SetArcStartEnd(minDegrees, maxDegrees);
    // FIXME enable mitering
    glLineWidth(3.0);
    circ->ResetVertices();
    circ->Evaluate();
    circ->Render(GL_LINE_STRIP);
}
} // end namespace OpenGC
