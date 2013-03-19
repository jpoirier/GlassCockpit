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

#ifndef Globals_h
#define Globals_h

#include "DataSource.h"
#include "NavDatabase.h"
#include "PrefManager.h"
#include "FontManager.h"
#include "RasterMapManager.h"
#include "CircleEvaluator.h"
#include "MessageableList.h"

namespace OpenGC {

class Globals {
public:
    Globals();
    ~Globals();

    DataSource          *m_DataSource;
    NavDatabase         *m_NavDatabase;
    PrefManager         *m_PrefManager;
    FontManager         *m_FontManager;
    RasterMapManager    *m_RasterMapManager;
    CircleEvaluator     *m_CircleEvaluator;
    MessageableList     *m_MessageableList;
};

extern Globals *globals;

} // end namespace OpenGC

#endif
