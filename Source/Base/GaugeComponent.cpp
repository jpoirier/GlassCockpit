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

#include <stdio.h>
#include "GLHeaders.h"

#include "GaugeComponent.h"

namespace OpenGC {

GaugeComponent::GaugeComponent():m_Opaque(true) {

}

GaugeComponent::~GaugeComponent() {
}

void GaugeComponent::Render() {
    // Overload this function in derived classes to render
    // the guage component
    OrderedPair<double> parentPhysicalPosition = m_pParentRenderObject->GetPhysicalPosition();

    // The location in pixels is calculated based on the size of the
    // gauge component and the offset of the parent guage
    m_PixelPosition.x = (int) ( (m_PhysicalPosition.x * m_Scale.x + parentPhysicalPosition.x ) / m_UnitsPerPixel);
    m_PixelPosition.y = (int) ( (m_PhysicalPosition.y * m_Scale.y + parentPhysicalPosition.y ) / m_UnitsPerPixel);

    // The size in pixels of the gauge is the physical size / mm per pixel
    m_PixelSize.x = (int) ( m_PhysicalSize.x / m_UnitsPerPixel * m_Scale.x);
    m_PixelSize.y = (int) ( m_PhysicalSize.y / m_UnitsPerPixel * m_Scale.y);

    // The viewport is established in order to clip things
    // outside the bounds of the GaugeComponent
    glViewport(m_PixelPosition.x, m_PixelPosition.y, m_PixelSize.x, m_PixelSize.y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Define the projection so that we're drawing in "real" space
    glOrtho(0, m_Scale.x * m_PhysicalSize.x, 0, m_Scale.y * m_PhysicalSize.y, -1, 1);

    // Prepare the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(m_Scale.x, m_Scale.y, 1.0f);
}

bool GaugeComponent::ClickTest(int button, int state, int x, int y) {
    if ((x >= (int)m_PixelPosition.x)&&(x <= (int)(m_PixelPosition.x + m_PixelSize.x))
            &&(y >= (int)m_PixelPosition.y)&&(y <= (int)(m_PixelPosition.y + m_PixelSize.y))) {
        // Click is inside the GaugeComponent
        return true;
    } else {
        // Click is NOT inside the GaugeComponent
        return false;
    }
}

} // end namespace OpenGC
