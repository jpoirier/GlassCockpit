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
#include <string.h>
#include "DataSource.h"

namespace OpenGC
{

DataSource::DataSource() {
    m_Airframe = new AirframeDataContainer;
}

DataSource::~DataSource() {
    delete m_Airframe;
}

// Initialize the data
void DataSource::InitializeData() {
    m_Airframe->InitializeData();
}

bool DataSource::OnIdle() {
    // The default version does nothing
    return false;
}

bool DataSource::Open() {
    // The default version returns false, which doesn't necessarily mean anything
    return false;
}

} // end namespace OpenGC
