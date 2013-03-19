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

#ifndef Messageable_h
#define Messageable_h

#include "Globals.h"
#include "Messages.h"

namespace OpenGC {

/** Abstract base class for objects that can receive messages (i.e. are
 * messageable). Inherit from it and implement OnMessage() to receive
 * messages. */
class Messageable {
public:
    /** When a Messageable is constructed, add it to the global list
     * of messageable objects */
    Messageable() { globals->m_MessageableList->Add(this); }

    /** When a Messageable is destructed, remove it from the global list
     * of messageable objects */
    virtual ~Messageable() { globals->m_MessageableList->Remove(this); }

    /** Called when a message is triggered somewhere */
    virtual void OnMessage(Message message, void *data) = 0;
};

} // end namespace OpenGC

#endif

