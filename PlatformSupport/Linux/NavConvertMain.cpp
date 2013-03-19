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

#include "BinaryNavData.h"
#include "Debug.h"
#include <string>

using namespace std;

int main(int argc, char **argv) {
    OpenGC::BinaryNavData ndtb;

    if (argc != 2) {
        printf("usage: navconvert Path/To/DataDir/Navigation\n");
        return 1;
    }

    LogPrintf("Converting airport data... ");
    ndtb.ConvertAirportData(string(argv[1]) + "apt.dat", string(argv[1]) + "apt_dat.bin");
    LogPrintf("Converting navaid data... ");
    ndtb.ConvertNavaidData(string(argv[1]) + "nav.dat", string(argv[1]) + "nav_dat.bin");
    LogPrintf("Done\n");
    return 0;
}

