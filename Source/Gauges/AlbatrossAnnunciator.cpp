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
#include "Globals.h"
#include "GaugeComponent.h"
#include "AlbatrossAnnunciator.h"

namespace OpenGC {

AlbatrossAnnunciator::AlbatrossAnnunciator() {
    m_Font = globals->m_FontManager->LoadDefaultFont();
    m_PhysicalSize.x = 98;
    m_PhysicalSize.y = 21;
    m_Scale.x = 1.0;
    m_Scale.y = 1.0;
}

AlbatrossAnnunciator::~AlbatrossAnnunciator() {
}

void AlbatrossAnnunciator::Render() {
    GaugeComponent::Render();
    AirframeDataContainer *data = globals->m_DataSource->GetAirframe();

    // Draw grey-blue background rectangle
    glColor3ub(51,51,76);
    static const float vertices[] = {0.0, 0.0, 0.0, 21.0, 97.5, 21.0, 97.5, 0.0, 0.0, 0.0};
    glVertexPointer(2, GL_FLOAT, 0, &vertices);
    glDrawArrays(GL_POLYGON, 0, 5);

    if (data->GetGot_Data()) {
        // Draw white separator lines
        glLineWidth(2.0);
        glColor3ub(255, 255, 255);
        static const float vertices[] = {28.0, 2.0, 28.0, 18.0, 70.0, 2.0, 70.0, 18.0};
        glVertexPointer(2, GL_FLOAT, 0, &vertices);
        glDrawArrays(GL_LINES, 0, 4);

        if (data->GetStatus_Active()) {
            globals->m_FontManager->SetSize(m_Font, 5, 6);
            glColor3ub(44, 214, 47); // Green

            globals->m_FontManager->Print(2, 12, "GPS", m_Font);
            globals->m_FontManager->Print(75, 12, "TEMP", m_Font);

            char buffer[8];

            // GPS 2D/3D mode and Satellites In View
            glColor3ub(240, 240, 0); // Yellow
            sprintf(buffer, "%iD : %i", data->GetGPS_Mode(), data->GetGPS_Sats());
            globals->m_FontManager->Print(2, 3, &buffer[0], m_Font);

            // Battery Voltage
            sprintf(buffer, "%2.2f", data->GetInternal_Temp());
            globals->m_FontManager->Print(75, 3, &buffer[0], m_Font);

            // Macro for printing status text strings.
            #define STATUS_TEXT(num, x, y) \
                col = data->GetStatus_Colour##num(); \
                if (col == 1) { \
                    glColor3ub(255, 20, 20); /* Red */ \
                    globals->m_FontManager->Print(x, y, data->GetStatus_Text##num(), m_Font);   \
                } else if (col == 2) { \
                    glColor3ub(44, 214, 47); /* Green */ \
                    globals->m_FontManager->Print(x, y, data->GetStatus_Text##num(), m_Font); \
                }

            // Display On/Off status text and colour
            int col;
            STATUS_TEXT(1, 31, 12);
            STATUS_TEXT(2, 31, 3);
            STATUS_TEXT(3, 52, 12);
            STATUS_TEXT(4, 52, 3);
        }
    } else {
        globals->m_FontManager->SetSize(m_Font, 5, 6);
        glColor3ub(255, 20, 20); // Red
        globals->m_FontManager->Print(2, 12, "NO DATA", m_Font);
        glColor3ub(240, 200, 10); // Yellow
        if (data->GetStatus_Text_NoData()) { // if its not null
            globals->m_FontManager->Print(2, 3, data->GetStatus_Text_NoData(), m_Font);
        }
    }
}

} // end namespace OpenGC
