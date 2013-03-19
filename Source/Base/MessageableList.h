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

#ifndef MessageableList_h
#define MessageableList_h

#include <list>
#include "Messages.h"

namespace OpenGC {

// Forward declaration to avoid circular dependecy
class Messageable;

/** A list of messageable objects in OpenGC */
class MessageableList : std::list<Messageable*> {
public:
    MessageableList();
    ~MessageableList();

    /** Add an object to the MessageableList */
    void Add(Messageable *obj);

    /** Remove an object from the MessageableList */
    void Remove(Messageable *obj);

    /** Send a message to all Messageable objects */
    void DispatchMessage(Message message, void *data);
};

} // end namespace OpenGC

#endif

