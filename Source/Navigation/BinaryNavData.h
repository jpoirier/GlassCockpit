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

#ifndef BinaryNavData_h
#define BinaryNavData_h

#include <string>

#define MAX_APT_ID_LENGTH 8
#define MAX_NAV_ID_LENGTH 8

namespace OpenGC {

/** Utility class for converting ASCII navigation files into binary format.
 * The binary format is around 12 times smaller on disk, and loads into
 * OpenGC much, much faster.
 *
 * See http://www.x-plane.org/home/robinp/FileDef.htm for more info
 */
class BinaryNavData {
public:
    /** Parses an ASCII airport database (apt.dat) and writes to the
     * binary output file */
    static void ConvertAirportData(const std::string& inFileName,
            const std::string& outFileName);

    /** Parses an ASCII navaid database (nav.dat) and writes to the
     * binary output file */
    static void ConvertNavaidData(const std::string& inFileName,
            const std::string& outFileName);

    /** Struct representing each navaid in the binary file format */
    typedef struct {
        float lat, lon, elev, frequency;
        unsigned char navaidType;
        unsigned char id_length;
        char id[MAX_NAV_ID_LENGTH];
    } NavaidData;

    /** Struct representing each airport in the binary file format */
    typedef struct {
        float lat, lon, elev;
        unsigned char id_length;
        char id[MAX_APT_ID_LENGTH];
    } AirportData;
};

} // end namespace OpenGC

#endif

