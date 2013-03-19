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

#include "Globals.h"

namespace OpenGC {

Globals::Globals() {
    m_PrefManager = new PrefManager();
    m_NavDatabase = new NavDatabase();
    m_FontManager = new FontManager();
    m_CircleEvaluator = new CircleEvaluator();
    m_RasterMapManager = new RasterMapManager();
    m_MessageableList = new MessageableList();
    m_DataSource = 0;
}

Globals::~Globals() {
    if (m_FontManager != 0) {
        delete m_FontManager;
        m_FontManager = 0;
    }

    if (m_DataSource != 0) {
        delete m_DataSource;
        m_DataSource = 0;
    }

    if (m_PrefManager != 0) {
        delete m_PrefManager;
        m_PrefManager = 0;
    }

    if (m_NavDatabase != 0) {
        delete m_NavDatabase;
        m_NavDatabase = 0;
    }

    if (m_RasterMapManager != 0) {
        delete m_RasterMapManager;
        m_RasterMapManager = 0;
    }

    if (m_CircleEvaluator != 0) {
        delete m_CircleEvaluator;
        m_CircleEvaluator = 0;
    }

    if (m_MessageableList != 0) {
        delete m_MessageableList;
        m_MessageableList = 0;
    }
}

} // end namespace OpenGC
