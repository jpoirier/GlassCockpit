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

#include "MessageableList.h"
#include "Messageable.h"

namespace OpenGC {

MessageableList::MessageableList() {}
MessageableList::~MessageableList() {}

void MessageableList::Add(Messageable *obj) {
    this->push_back(obj);
}

void MessageableList::Remove(Messageable *obj) {
    MessageableList::iterator iter;
    for (iter = this->begin(); iter != this->end(); ++iter) {
        if ((*iter) == obj) {
            this->remove(*iter);
            break;
        }
    }
}

void MessageableList::DispatchMessage(Message message, void *data) {
    MessageableList::iterator it;
    for (it = this->begin(); it != this->end(); ++it) {
        (*it)->OnMessage(message, data);
    }
}

}; // end namespace OpenGC

