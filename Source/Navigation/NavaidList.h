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

#ifndef NavaidList_h
#define NavaidList_h

#include <list>
#include <string>
#include "GeographicObjectList.h"

namespace OpenGC {

class NavaidList : public GeographicObjectList {
    public:
        NavaidList();
        virtual ~NavaidList();

        /** Read a file contain navaids, returns true if successful, else false */
        bool LoadData(const string& fileName);
};

} // end namespace OpenGC

#endif
