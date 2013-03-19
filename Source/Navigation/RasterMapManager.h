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

#ifndef RasterMapManager_h
#define RasterMapManager_h

#include <string>
//#include <map>
#include "RasterMapTile.h"

namespace OpenGC {

/** This class reads and parses cache sets. For now, only MGMap caches generated
 *  by the MapTileCacher.perl script (in Util/, version 1.35) tested.
 */	
class RasterMapManager
{
public:
	typedef enum {
		RMM_CACHE_MGMAPS = 0
	} CacheFormat;
	
	RasterMapManager();
	
	/** Set cache path. MapType should be e.g. "GoogleTer" to suit your cache */
	void SetCachePath(CacheFormat format, const std::string& path, const std::string& mapType);
	
	/** Get tile at specified tile coordinates and zoom level. Note this may be map-type/format specific */
	RasterMapTile *GetTile(const unsigned int zoom, const unsigned int x, const unsigned int y);

	/** Get tile coordinates for the tile containing specified lat/long in a certain zoom level.
	 *  (x, y) are the tile coordinate, (fx, fy) are the fractional coordinate within the tile. */
	void GetTileCoordsForLatLon(unsigned int& x, unsigned int& y, float& fx, float& fy,
								double lat, double lon, const unsigned int zoom);
	
	/** Set the cache of read-in tiles to be at most cacheSizeBytes (default is no cache) */
	void SetCacheMemorySize(const unsigned int cacheSizeBytes);
	
private:
	// Note: returned image pointer will be invalidated after a new image is read
	unsigned char *DecodeJPEG(unsigned char *readBuffer, unsigned int length, unsigned int& width, unsigned int& height);

	// Note: returned image pointer will be invalidated after a new image is read
	unsigned char *DecodePNG(unsigned char *readBuffer, unsigned int length, unsigned int& width, unsigned int& height);

	bool m_Ready;
	
	std::string m_CachePrefix;
	std::string m_MapType;
	
	static const unsigned int READ_BUFFER_SIZE = 64*1024;
	unsigned char m_ReadBuffer[READ_BUFFER_SIZE];
	
//	std::map
};
	
} // end namespace OpenGC

#endif // RasterMapManager_h
