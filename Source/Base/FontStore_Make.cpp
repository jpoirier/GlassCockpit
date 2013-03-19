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

#include "Debug.h"

// Note: compile with USE_FREETYPE2 defined (gcc -DUSE_FREETYPE2 ...)

#include "Font_FileStore.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        LogPrintf("Usage: FontStore_Make fontname.ttf (generates fontstore.glfont)");
        return 1;
    }

    string basename = argv[1];
    Font_FileStore *fileStore = Font_FileStore::CreateFromTTF(basename + ".ttf");
    Assert(fileStore != NULL, "error create font filestore");
    fileStore->SerializeToFile(basename + ".glfont");

    delete fileStore;
    return 0;
}
